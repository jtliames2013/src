Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2. 

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

