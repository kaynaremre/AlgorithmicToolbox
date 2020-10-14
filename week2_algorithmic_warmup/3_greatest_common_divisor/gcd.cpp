#include <iostream>

using std::cin;
using std::cout;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}


int gcd_fast(int a, int b){
  int a1 = a;
  int result = 31;
  if(a < b){
    a1 = a;
    int a2 = b % a;
    int a3;
    result = a;
    while (true){
        if(a2 == 0){
          result = a;
          break;
        }
        else{
          a3 = a1 % a2;
          a1 = a2;
          if (a3 == 0){
            result = a1;
            break;
          }
          else{
            a2 = a3;
          }
      }
    }
  }
  else{
    int b1 = b;
    int b2 = a % b;
    int b3;
    result = b;
    while (true){
        if(b2 == 0){
          return b;
          break;
        }
        else{
          b3 = b1 % b2;
          b1 = b2;
          if (b3 == 0){
            result = b1;
            break;
          }
          else{
            b2 = b3;
          }
      }
    }
  }
  return result;
  }

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
