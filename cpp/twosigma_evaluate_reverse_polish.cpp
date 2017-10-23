一轮，两题，1设计逆波兰表达式，要求much scalable，可以提供任何自定义operator和operand.

class IOperator {
public:
	virtual ~IOperator() {}
	virtual int Operate(vector<int>& operands) = 0;
};

class Add: public IOperator {
public:
	virtual ~Add() {}
	int Operate(vector<int>& operands) {
		if (operands.size()<2) return 0;
		return operands[0]+operands[1];
	}
};

class Substract: public IOperator {
public:
	virtual ~Substract() {}
	int Operate(vector<int>& operands) {
		if (operands.size()<2) return 0;
		return operands[0]-operands[1];
	}
};

class Multiply: public IOperator {
public:
	virtual ~Multiply() {}
	int Operate(vector<int>& operands) {
		if (operands.size()<2) return 0;
		return operands[0]*operands[1];
	}
};

class Divide: public IOperator {
public:
	virtual ~Divide() {}
	int Operate(vector<int>& operands) {
		if (operands.size()<2 || operands[1]==0) return 0;
		return operands[0]/operands[1];
	}
};

class OperatorFactory {
public:
	static IOperator *CreateOperator(string opstr) {
		if (opstr=="+") {
			return new Add();
		} else if (opstr=="-") {
			return new Substract();
		} else if (opstr=="*") {
			return new Multiply();
		} else if (opstr=="/") {
			return new Divide();
		} else {
			return NULL;
		}
	}
};

class Expression {
public:
	Expression() {
		ops={"+", "-", "*", "/"};
	}

	void addOperator(string op) {
		ops.insert(op);
	}

	int calc(string opstr, int oprand1, int oprand2) {
		IOperator *op=OperatorFactory::CreateOperator(opstr);
		if (op==NULL) return 0;
		vector<int> v={oprand1, oprand2};
		return op->Operate(v);
	}

	int eval(vector<string> tokens) {
		stack<int> stk;
		for (auto& t:tokens) {
			if (ops.find(t)==ops.end()) stk.push(stoi(t));
			else {
				int num1=stk.top();
				stk.pop();
				int num2=stk.top();
				stk.pop();
				stk.push(calc(t, num1, num2));
			}
		}
		return stk.top();
	}

private:
	unordered_set<string> ops;
};

int main()
{
	Expression s;
	vector<string> tokens={"2", "3", "+" };
	cout << s.eval(tokens) << endl;
	return 0;
}

