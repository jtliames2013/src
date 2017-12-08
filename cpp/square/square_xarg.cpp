2. 面试官上来也特别的友好,介绍了自己是前10%员工.在square工作6年了.然后就是帮我配置了一下环境 pycharm 设置各种路径,创建工程啥的,耽误了快10分钟.
    然后就讲问题, 这个题目是我遇到过的最长的题目.

    模拟 linux 下的 xargs, 比如说 seq 5 | xargs -n 3 echo  这个命令就会把前面生成的1,2,3,4,5 list 传到xargs中,然后按照-n的参数进行分行.
    结果就是  1 2 3
                   4 5
    因为第二行就2个元素.

    其实题目讲明白了以后不难写, 但是牵涉到大量的标准输入输出和参数处理,所以问题也没那么容易.
    用python写,调用了一个 python里面的 subprocess_check() 啥的命令. 先从标准输入中读取输入 (类似前面的seq 5 这种), 然后从参数中读取命令,添加到subprocess_check后面.
    结果用pycharm不知道怎么读入标准输入, 哎!总之环境各种坑爹. 最后的解决方法是在 pycharm里写代码然后去命令行里手动run.

我最开始采取的措施是先把前面所有的输入都读进来, 然后再处理.    然后代码写完了, 验证了一下,和结果一样.
    follow up 是如果输入是无限的咋办? 比如说  yes | xargs -n 3 echo  前面那个 yes 会无线的输如 y 这个字符.
    做法就是不能读完,每次等到读的字符串够处理的时候就处理, 然后处理完了就删了. 写了个while 循环.  跑了一下测试,发现没有问题.
    给面试官解释了一下代码逻辑, 最后也算是完成了,但是感觉磕磕盼盼的. 而且一旦出了问题以后, 会出各种问题. 反正觉得有点坑.

    我觉得我大部分时间都花在环境和输入输出的处理上, 就跟面试官解释了一下这个环境和系统命令我不熟,不然我会做的更好. 
    我觉得还有其他的follow up,就问了一下面试官, 他说还有一个特别复杂的bonus follow up. 反正就这样了.

总之就觉得 square 面试确实很少面重复的题,也不用紧张,大部分题都是从简单的开始,一般都有俩个follow up. 也祝大家求职顺利.

void printOutput(vector<string>& output) {
	for (int i=0; i<output.size(); i++) {
		cout << output[i] << " ";
	}
	cout << endl;
}

int main(int argc, char** argv) {
	if (argc!=3) {
		cout << "Usage:" + string(argv[0]) + " -n number" << endl;
		return 0;
	}
	if (string(argv[1])!="-n") return 0;
	int num=atoi(argv[2]);

	string line;
	vector<string> output;

	while (getline(cin, line)) {
		if (output.size()==num) {
			printOutput(output);
			output.clear();
		}

		output.push_back(line);
	}

	if (!output.empty()) printOutput(output);

	return 0;
}

