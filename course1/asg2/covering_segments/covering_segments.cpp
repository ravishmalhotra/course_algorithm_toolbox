#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points(1);
  //write your code here
  //Sorting the line segments in ascending order of the first point, a(i)
  std::sort(segments.begin(),segments.end(),[]( Segment s1 , Segment s2) {return s1.start<s2.start;});

  points[0]=segments[0].start;
  int n=0;

  //Using the safe move as follows
  //Check the first point of every segement is within bounds
  //If it is update the current point
  //If it is not, make a new point and update the total number of points by resizing the array.
  for (size_t i = 0; i < segments.size(); ++i) {

   if (segments[i].start<=segments[n].end && segments[i].start>=segments[n].start){
   points[n]=segments[i].start;

   }

   else {
   n=n+1;
   //points.resize(n);
   //points[n]=segments[i+1].start;
   points.push_back(segments[i].start);

   }

    //points.push_back(segments[i].start);
    //points.push_back(segments[i].end);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
