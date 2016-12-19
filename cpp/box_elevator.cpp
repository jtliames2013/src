mutex singleton_mutex;

enum Direction {
	up=0,
	down
};

class Request {
	Request(int f, Direction d, int t):arrivalFloor(f), direction(d), arrivalTime(t) {}
private:
	int arrivalFloor;
	Direction direction;
	int arrivalTime;
};

class Elevator {
	Elevator():capacity(20), speed(2) {}
	void addRequest(Request req) {
		lock_guard<mutex> guard(reqMutex);
		requests.insert(req);
		if (requests.size()==1) {
			reqCv.notify_all();
		}
	}

	void processRequest() {
		while (1) {
			Request req;
			{
				unique_lock<mutex> lk(reqMutex);
				if (request.empty()) {
					reqCv.wait(lk);
				}

				// get next request
				req = getNextRequest();
			}

			// move to next request
			move(req.arrivalFloor);
		}
	}

	Request getNextRequest() {
		Request res;
		int destFloor=floor;
		switch (direction) {
		case up:
			for (auto r:requests) {
				if (r.arrivalFloor>floor) {
					destFloor=r.arrivalFloor;
					res=r;
					break;
				}
			}
			if (destFloor==floor) {
				for (auto iter=requests.rbegin(); iter!=requests.rend(); iter++) {
					if (iter->arrivalFloor<floor) {
						res=*iter;
						direction=down;
						break;
					}
				}
			}
		case down:
			for (auto iter=requests.rbegin(); iter!=requests.rend(); iter++) {
				if (iter->arrivalFloor<floor) {
					destFloor=iter->arrivalFloor;
					res=*iter;
					break;
				}
			}
			if (destFloor==floor) {
				for (auto r:requests) {
					if (r.arrivalFloor>floor) {
						direction=up;
						res=r;
						break;
					}
				}
			}
		}
		requests.erase(res);
		return res;
	}

	void move(int destFloor) {
		int time=abs(destFloor-floor)/speed+1;
		sleep(time);
		floor=destFloor;
	}

	void run() {
		worker=thread(&Elevator::processRequest, this);
	}
private:
	int capacity;
	float speed;
	Direction direction;
	int floor;
	set<Request> requests;
	mutex reqMutex;
	condition_variable reqCv;
	thread worker;
};

class ElevatorManager {
	static ElevatorManager* GetInstance() {
		if (m_instance==NULL) {
			lock_guard<mutex> guard(singleton_mutex);
			if (m_instance==NULL) {
				m_instance = new ElevatorManager();
			}
		}

		return m_instance;
	}

	void addRequest(Request req) {

	}
private:
	ElevatorManager():numElevators(4) {
		elevators.resize(numElevators);
		for (int i=0; i<numElevators; i++) {
			elevators[i].run();
		}
	}
	vector<Elevator> elevators;
	const int numElevators;
	static ElevatorManager* m_instance;
};

ElevatorManager* ElevatorManager::m_instance=NULL;

int main()
{
	srand (time(NULL));
	int time=0;
	for (int i=0; i<1000; i++) {
		int floor=rand()%50+1;
		Direction direction=rand()%2==0?up:down;
		time+=rand()%100;
		Request req = new Request(floor, direction, time);
		ElevatorManager::GetInstance()->addRequest(req);
	}

	return 0;
}

