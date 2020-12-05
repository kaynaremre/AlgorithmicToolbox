#include <iostream>

using namespace std;

int get_change(int m) {
  int count = 0;
  while (m >= 10){
    count++;
    m = m - 10;
  }
  while (m >= 5){
    count++;
    m = m-5;
  }
  while (m != 0){
    count++;
    m = m-1;
  }
  return count;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
