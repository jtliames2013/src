Airbnb: Page Display
实现分页显示。给了以下一些输入数据，要求将以下行分页显示，每页12行，其中每行已经按score排好序，分页显示的时候如果有相同host id的行，则将后面同host id的行移到下一页。
[
"host_id,listing_id,score,city",
"1,28,300.1,SanFrancisco",
"4,5,209.1,SanFrancisco",
"20,7,208.1,SanFrancisco",
"23,8,207.1,SanFrancisco",
"16,10,206.1,Oakland",
"1,16,205.1,SanFrancisco",
"6,29,204.1,SanFrancisco",
"7,20,203.1,SanFrancisco",
"8,21,202.1,SanFrancisco",
"2,18,201.1,SanFrancisco",
"2,30,200.1,SanFrancisco",
"15,27,109.1,Oakland",
"10,13,108.1,Oakland",
"11,26,107.1,Oakland",
"12,9,106.1,Oakland",
"13,1,105.1,Oakland",
"22,17,104.1,Oakland",
"1,2,103.1,Oakland",
"28,24,102.1,Oakland",
"18,14,11.1,SanJose",
"6,25,10.1,Oakland",
"19,15,9.1,SanJose",
"3,19,8.1,SanJose",
"3,11,7.1,Oakland",
"27,12,6.1,Oakland",
"1,3,5.1,Oakland",
"25,4,4.1,SanJose",
"5,6,3.1,SanJose",
"29,22,2.1,SanJose",
"30,23,1.1,SanJose"
]

Output:
Page 1
1,28,300.1,SanFrancisco
4,5,209.1,SanFrancisco
20,7,208.1,SanFrancisco
23,8,207.1,SanFrancisco
16,10,206.1,Oakland
6,29,204.1,SanFrancisco
7,20,203.1,SanFrancisco
8,21,202.1,SanFrancisco
2,18,201.1,SanFrancisco
15,27,109.1,Oakland
10,13,108.1,Oakland
11,26,107.1,Oakland
Page 2
1,16,205.1,SanFrancisco
2,30,200.1,SanFrancisco
12,9,106.1,Oakland
13,1,105.1,Oakland
22,17,104.1,Oakland
28,24,102.1,Oakland
18,14,11.1,SanJose
6,25,10.1,Oakland
19,15,9.1,SanJose
3,19,8.1,SanJose
27,12,6.1,Oakland
25,4,4.1,SanJose
Page 3
1,2,103.1,Oakland
3,11,7.1,Oakland
5,6,3.1,SanJose
29,22,2.1,SanJose
30,23,1.1,SanJose
Page 4
1,3,5.1,Oakland

Summary:
There is a trick in this question. When do we need to get to a new page? There are two cases need to consider:
1. When the current page has 12 entries. 
2. When the current page has less than 12 but the iterator has reached to the end. IN this case, we need wrap back and iterator the list again. 

class Solution {
public:
	  void displayPages(vector<string> input) {
		  set<string> visited;
		  int page=1;
		  int i=0;
		  cout << "Page " << page << ":" << endl;
		  while (i<input.size()) {
			  istringstream iss(input[i]);
			  string hostId;
			  getline(iss, hostId, ',');

			  if (visited.find(hostId)==visited.end()) {
				  cout << input[i] << endl;
				  visited.insert(hostId);
				  input.erase(input.begin()+i);
			  } else {
				  i++;
			  }

			  if (visited.size()==12 || i==input.size()) {
				  visited.clear();
				  i=0;
				  if (input.size()>0) {
					  page++;
					  cout << "Page " << page << ":" << endl;
				  }
			  }
		  }
	  }
  };

int main()
{
	vector<string> input={
		      "1,28,300.1,SanFrancisco",
		      "4,5,209.1,SanFrancisco",
		      "20,7,208.1,SanFrancisco",
		      "23,8,207.1,SanFrancisco",
		      "16,10,206.1,Oakland",
		      "1,16,205.1,SanFrancisco",
		      "6,29,204.1,SanFrancisco",
		      "7,20,203.1,SanFrancisco",
		      "8,21,202.1,SanFrancisco",
		      "2,18,201.1,SanFrancisco",
		      "2,30,200.1,SanFrancisco",
		      "15,27,109.1,Oakland",
		      "10,13,108.1,Oakland",
		      "11,26,107.1,Oakland",
		      "12,9,106.1,Oakland",
		      "13,1,105.1,Oakland",
		      "22,17,104.1,Oakland",
		      "1,2,103.1,Oakland",
		      "28,24,102.1,Oakland",
		      "18,14,11.1,SanJose",
		      "6,25,10.1,Oakland",
		      "19,15,9.1,SanJose",
		      "3,19,8.1,SanJose",
		      "3,11,7.1,Oakland",
		      "27,12,6.1,Oakland",
		      "1,3,5.1,Oakland",
		      "25,4,4.1,SanJose",
		      "5,6,3.1,SanJose",
		      "29,22,2.1,SanJose",
		      "30,23,1.1,SanJose"
		    };
	Solution s;
	s.displayPages(input);
  	return 0;
}

