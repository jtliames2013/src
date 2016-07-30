写echo TCP client， 向面试官的server发请求， 读回数据。地里比较少人说这种， 我来详细说一下， 情境是这样的： 想象你开车， 踩下油门，车会加速，放开油门，车会减速。 client向server发的请求有以下2种： （a）STATUS –表示查询现在车的速度和踩下踏板的压力； （b）THROTTLE 50.1 — 这条指令是“THROTTLE” 加上一个数字， 表示我现在将踩油门的压力调为50.1

EXAMPLE: 比如在telnet中
STATUS
0.0 0.0 (这行是server返回的， 第一个数字表示压力，第二个数字表示速度)
THROTTLE 50.1 (这个指令发出 server没有返回)
STATUS
50.1 3.75 (可以看到速度在缓慢上升)
STATUS (过几秒后，你又发STATUS指令过去)
50.1 15.98 (速度依旧上升。。。)

对就是这样，像是简单物理实验。

写完TCP client后，要求是写一个方法将速度控制到达一个target speed

最后一个问题是求这个 delta力 和 delta速度 之间的函数关系。。。。。。。。醉了。我物理还给老师了。。。。。。时间不够了

希望可以帮助到大家！！！

Round 3 coding 1: 碰到了一道非面经题。我发誓从来没有在网上见过任何类似的题。题目是这样的，在一个server上有一个汽车的simulator，要求楼主用一个socket连过去，然后可以call两个API：getStatus()可以得到当前的速度和加速度，setStatus(加速度)可以修改汽车加速度。对于每一个加速度，这辆汽车会不断加速最终达到一个稳定速度。问题是要写一个wrapper function让汽车的速度稳定在29mph。楼主花了十几分钟才理解清楚题目，又花了五分钟学习怎么连socket。最后code是写完了，但是输出不正确。时间不够了就没有继续。跟面试官过了程序，他觉得算法没问题，也没找到不输出的原因。最后把程序copy走了了事。希望不要给太负面的评价 

class Client {
public:
	Client() {
		init();
	}

	void init() {
		CONTROL=1;
		GET=1;
		SET=2;
		SHUTDOWN=3;
		DATA=2;
		portno=50000;
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd<0) cerr << "error open socket" << endl;
		server = gethostbyname("jiangtian-ThinkPad-T410");
		if (server==NULL) cerr << "no such host" << endl;
		bzero((char *) &serv_addr, sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		bcopy((char *)server->h_addr,
			 (char *)&serv_addr.sin_addr.s_addr,
			 server->h_length);
		serv_addr.sin_port = htons(portno);
		if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
			cerr << "error connecting" << endl;
		}
	}

	~Client() {
		close(sockfd);
	}

	pair<float, float> getStatus() {
		 bzero(buffer,256);
		 memcpy(&buffer[0], &CONTROL, sizeof(int));
		 memcpy(&buffer[sizeof(int)], &GET, sizeof(int));
		 int n = write(sockfd,buffer,2*sizeof(int));
		 if (n<0) cerr << "error writing socket" << endl;

 		 bzero(buffer,256);
		 n = read(sockfd,buffer,2*sizeof(float));
		 if (n<0) cerr << "error reading socket" << endl;
		 float force=*((float*)&buffer[0]);
		 float speed=*((float*)&buffer[sizeof(float)]);
		 cout << "client: received force=" << force << " speed=" << speed << endl;
		 return {force, speed};
	}

	void setStatus(float force) {
		 bzero(buffer,256);
		 memcpy(&buffer[0], &CONTROL, sizeof(int));
		 memcpy(&buffer[sizeof(int)], &SET, sizeof(int));
		 int n = write(sockfd,buffer,2*sizeof(int));
		 if (n<0) cerr << "error writing socket" << endl;

 		 bzero(buffer,256);
 		 memcpy(&buffer[0], &DATA, sizeof(int));
 		 memcpy(&buffer[sizeof(int)], &force, sizeof(float));
		 n = write(sockfd,buffer,sizeof(int)+sizeof(float));
		 if (n<0) cerr << "error writing socket" << endl;
		 cout << "client: sent force=" << force << endl;
	}

	void controlSpeed(float speed) {
		float left=0, right=100;
		int interval=1; // 1 second
		float force;
		float maxAccel=0;
		float accel=0;
		float deaccel=0;
		float lastVelocity;
		float upperForce;

		while (1) {
			setStatus(right);
			pair<float,float> begin=getStatus();
			usleep(interval*1000000);
			pair<float,float> end=getStatus();
			lastVelocity=end.second;
			accel=(end.second-begin.second)/interval;
			maxAccel=max(maxAccel, accel);
			if (accel>0) break;
			else right*=2;
		}
		upperForce=right;
		cout <<"upperForce=" << upperForce << endl;

		while (left<=right) {
			force=(right+left)/2;
			if (lastVelocity==0) {
				setStatus(upperForce);
				usleep(interval*1000000);
			}
			setStatus(force);
			pair<float,float> begin=getStatus();
			usleep(interval*1000000);
			pair<float,float> end=getStatus();
			lastVelocity=end.second;
			accel=(end.second-begin.second)/interval;
			cout << "end=" << end.second << " begin=" << begin.second << " accel=" << accel << endl;
			if (accel==0) break;
			else if (accel>0) {
				right=force-1;
			} else {
				left=force+1;
			}
		}
		cout << "force=" << force << endl;

		pair<int,int> curr=getStatus();
		if (curr.second>speed) {
			cout << "curr=" << curr.second << " speed=" << speed << endl;
			// make sure we have enough speed
			setStatus(upperForce);
			usleep(interval*1000000);
			setStatus(0);
			pair<float,float> begin=getStatus();
			usleep(interval*1000000);
			pair<float,float> end=getStatus();
			deaccel=(end.second-begin.second)/interval;
			cout << "end=" << end.second << " begin=" << begin.second << " deaccel=" << deaccel << endl;
			float time=(speed-curr.second)/deaccel;
			cout << "time=" << time << endl;
			setStatus(0);
			usleep(time*1000000);
		} else if (curr.second<speed) {
			cout << "curr=" << curr.second << " speed=" << speed << endl;
			float time=(curr.second-speed)/maxAccel;
			cout << "maxAccel=" << maxAccel <<  " time=" << time << endl;
			setStatus(upperForce);
			usleep(time*1000000);
		}

		setStatus(force);
	}

	void shutdown() {
		 bzero(buffer,256);
		 memcpy(&buffer[0], &CONTROL, sizeof(int));
		 memcpy(&buffer[sizeof(int)], &SHUTDOWN, sizeof(int));
		 int n = write(sockfd,buffer,2*sizeof(int));
		 if (n<0) cerr << "error writing socket" << endl;
	}

private:
	int CONTROL;
	int GET;
	int SET;
	int DATA;
	int SHUTDOWN;
	int sockfd, portno;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];
};

int main() {
	Client client;
	client.controlSpeed(30);
	client.shutdown();
	//pair<float, float> status=client.getStatus();
	//cout << status.first << " " << status.second << endl;
	return 0;
}


server
int main() {
	const int CONTROL=1;
	const int GET=1;
	const int SET=2;
	const int DATA=2;
	const int SHUTDOWN=3;

    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    float force=0, speed=0;
    const float antiforce=60;
    time_t lasttime=0;
    int lastspeed=0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
       cerr << "ERROR opening socket" << endl;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 50000;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    	cerr << "ERROR on binding" << endl;
    }
    listen(sockfd,5);

    while (1) {
		clilen = sizeof(cli_addr);
		newsockfd = accept(sockfd,
					(struct sockaddr *) &cli_addr,
					&clilen);
		if (newsockfd < 0)
			 cerr << "ERROR on accept" << endl;

		while (1) {
			bzero(buffer,256);
			while (1) {
				n = read(newsockfd,buffer,2*sizeof(int));
				if (n < 0) {
					cerr << "ERROR reading from socket" << endl;
					break;
				} else if (n>0) {
					break;
				} else {
					usleep(10000);
				}
			}

			int control=*((int *)&buffer[0]);
			if (control!=CONTROL) cerr << "error should be control message" << endl;
			int action=*((int *)&buffer[sizeof(int)]);
			cout << "server: received control=" << control << " action=" << action << endl;
			if (action==GET) {
				time_t currtime=time(NULL);
				speed=lastspeed+(currtime-lasttime)*(force-antiforce);
				if (speed<0) speed=0;
				lastspeed=speed;
				lasttime=currtime;
				cout << "lastspeed=" << lastspeed << " lasttime=" << lasttime << endl;

				 memcpy(&buffer[0], &force, sizeof(float));
				 memcpy(&buffer[sizeof(int)], &speed, sizeof(float));
				 n = write(newsockfd,buffer,2*sizeof(float));
				 if (n < 0) cerr << "ERROR writing to socket" << endl;
				 cout << "server: sent force=" << force << " speed=" << speed << endl;
			} else if (action==SET) {
				bzero(buffer,256);
				n = read(newsockfd,buffer,255);
				if (n < 0) cerr << "ERROR reading from socket" << endl;
				int data=*((int *)buffer);
				if (data!=DATA) cerr << "error should be data message" << endl;
				force=*(float *)(buffer+sizeof(int));
				cout << "server: received force=" << force << endl;
				time_t currtime=time(NULL);
				if (lasttime!=0) {
					speed=lastspeed+(currtime-lasttime)*(force-antiforce);
					if (speed<0) speed=0;
					lastspeed=speed;
					lasttime=currtime;
				} else {
					lasttime=currtime;
				}
				cout << "lastspeed=" << lastspeed << " lasttime=" << lasttime << endl;
			} else if (action==SHUTDOWN) {
				cout << "server: received shutdown" << endl;
				break;
			} else {
				cerr << "error action not recognized" << endl;
				break;
			}
		}

		close(newsockfd);
    }
    close(sockfd);

	return 0;
}


