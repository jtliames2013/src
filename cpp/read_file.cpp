int main() {
	ifstream is("sample.txt");
	vector<vector<int> > lines;
	string line;
	while (getline(is, line)) {
		istringstream iss(line);
		vector<int> nums;
		string a, b, c;
		getline(iss, a, ' ');
		nums.push_back(stoi(a));
		getline(iss, b, ' ');
		nums.push_back(stoi(b));
		getline(iss, c, ' ');
		nums.push_back(stoi(c));
		lines.push_back(nums);
		cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;
	}
	return 0;
}

