253. Meeting Rooms II 
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.

Hide Company Tags Google Facebook
Hide Tags Heap Greedy Sort
Hide Similar Problems (H) Merge Intervals (E) Meeting Rooms

NOTE: sort an array of both start and end points. if start of point 1 equals end of point 2, then point 2 comes first.

  class Solution {
  public:
	  struct point {
		  int pos;
		  bool isStart;
		  point(int p, bool s): pos(p), isStart(s) {}
	  };
      int minMeetingRooms(vector<Interval>& intervals) {
    	  vector<point> points;
    	  for (auto i:intervals) {
    		  points.push_back(point(i.start, true));
    		  points.push_back(point(i.end, false));
    	  }

    	  sort(points.begin(), points.end(), [](point a, point b) { return (a.pos<b.pos || (a.pos==b.pos && a.isStart==false)); } );

    	  int rooms=0, count=0;
    	  for (int i=0; i<points.size(); i++) {
    		  if (points[i].isStart) {
    			  count++;
    		  } else {
    			  count--;
    		  }
    		  rooms=max(rooms, count);
    	  }
    	  return rooms;
      }
  };

2. return all the empty intervals
  class Solution {
  public:
      vector<Interval> minMeetingRooms(vector<Interval>& intervals) {
          vector<Interval> res;
    	  vector<pair<int, bool>> time;
          for (auto i:intervals) {
              time.push_back({i.start, true});
              time.push_back({i.end, false});
          }

          sort(time.begin(), time.end(), [](pair<int,bool> a, pair<int,bool> b) { return (a.first<b.first||(a.first==b.first&&a.second==false));});

          int count=0;
          int start, end, hasStarted=false;
          for (auto t:time) {
              if (t.second==true) count++;
              else count--;
              if (count==0) {
            	  start=t.first;
            	  hasStarted=true;
              }
              if (count==1 && hasStarted) {
            	  end=t.first;
            	  hasStarted=false;
            	  if (end>start) {
            		  res.push_back(Interval(start, end));
            	  }
              }
          }

          return res;
      }
  };


