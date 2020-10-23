#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

using namespace std; 

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  Segment tmp;
  int k_tmp = -1;
  int i = 0;
  int k = 1;

  auto sortRuleLambda = [] (Segment const& s1, Segment const& s2) -> bool{
    return s1.end < s2.end;
  };


  sort(segments.begin(), segments.end(), sortRuleLambda);


  while(segments.size() > 1){
    while(k < segments.size() - 1){
      if (segments.at(0).end >= segments.at(k).start){
        segments.erase(segments.begin() + k);
        k++;
      }
    }
    k = 1;
    points.push_back(segments.at(i).end);
    segments.erase(segments.begin());
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
