#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string first;
    getline(cin, first);
    int samples=stoi(first);
    vector<string> timestamp(samples);
    vector<string> data(samples);
    vector<double> prices(samples);

    for (int i=0; i<samples; i++) {
    	string line;
    	getline(cin, line);
    	istringstream iss(line);
        getline(iss, timestamp[i], '\t');
        getline(iss, data[i], '\t');
        if (data[i].size()>=7 && data[i].substr(0,7)=="Missing") {
            prices[i]=-1;
        } else {
            prices[i]=stod(data[i]);
        }
    }

    for (int i=0; i<samples; i++) {
        if (prices[i]==-1) {
            double prev=(i>0?prices[i-1]:0);
            double next=(i<samples-1?prices[i+1]:0);
            cout << (prev+next)/2 << endl;
        }
    }
return 0;
}

