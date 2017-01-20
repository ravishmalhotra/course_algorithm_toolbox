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
  int new_seg=0;

  //Using the safe move as follows
  //Check the first point of every segement is within bounds
  //If it is update the current point
  //If it is not, make a new point and update the total number of points by resizing the array.
  for (size_t i = 0; i < segments.size(); ++i) {

   if (segments[i].start<=segments[new_seg].end && segments[i].start>=segments[new_seg].start){
   if (segments[i].end<segments[new_seg].end) {
   new_seg=i;
   } //Redefining the new boundary of comparison if the current line segment has a smaller end point than previous. Covers corner case like (10,12), (10,10) and (12,14)
   //where the above inputs appear in sequence. (10, 12) is selected as the initial boundary, then (10,10). Therefore, a coordinate of 10 will be a unique point, followed by 12. If this
   //line is not used, an incorrect answer of 1 point with a coordinate 12 will be given.
   points[n]=segments[i].start;

   }

   else {
   n=n+1; //Increasing the number of points by 1
   new_seg=i;
   points.push_back(segments[i].start);

   }

  }
  return points;
}

int main() {
  int n;
  std::cin >> n;

  vector<Segment>segments(n);

 for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}


/*
= {

{41, 42},
{52, 52},
{63, 63},
{80, 82},
{78, 79},
{35, 35},
{22, 23},
{31, 32},
{44, 45},
{81, 82},
{36, 38},
{10, 12},
{1 ,1},
{23, 23},
{32, 33},
{87, 88},
{55, 56},
{69, 71},
{89, 91},
{93, 93},
{38, 40},
{33, 34},
{14, 16},
{57, 59},
{70, 72},
{36, 36},
{29, 29},
{73, 74},
{66, 68},
{36, 38},
{1, 3},
{49, 50},
{68, 70},
{26, 28},
{30, 30},
{1, 2},
{64, 65},
{57, 58},
{58, 58},
{51, 53},
{41, 41},
{17, 18},
{45, 46},
{4, 4},
{0, 1},
{65, 67},
{92, 93},
{84, 85},
{75, 77},
{39, 41},
{5, 15},
{29, 31},
{83, 84},
{12, 14},
{91, 93},
{83, 84},
{81, 81},
{3, 4},
{66, 67},
{8, 8},
{17, 19},
{86, 87},
{44, 44},
{34, 34},
{74, 74},
{94, 95},
{79, 81},
{29, 29},
{60, 61},
{58, 59},
{62, 62},
{54, 56},
{58, 58},
{79, 79},
{89, 91},
{40, 42},
{2, 4},
{12, 14},
{5,5},
{28, 28},
{35, 36},
{7, 8},
{82, 84},
{49, 51},
{2,4},
{57, 59},
{25, 27},
{52, 53},
{48, 49},
{9, 9},
{10, 10},
{78, 78},
{26, 26},
{83, 84},
{22, 24},
{86, 87},
{52, 54},
{49, 51},
{63, 64},
{54, 54}
 };




*/
