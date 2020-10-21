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
  vector<long long> endpoints;

  for (int j = 0; j < segments.size(); ++j){
    segments.at(j) = tmp;
    endpoints.at(j) = tmp.end;
  }

  sort(endpoints.begin(), endpoints.end());

  


  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
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
