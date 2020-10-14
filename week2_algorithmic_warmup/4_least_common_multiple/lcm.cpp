#include <iostream>

long long lcm_naive(long a, long b) {
  if (a < b){
    for (long l = b; l <= (long long) a * b; ++l)
      if (l % a == 0 && l % b == 0)
        return l;
  }
  else{
    for (long l = a; l <= (long long) a * b; ++l)
      if (l % a == 0 && l % b == 0)
        return l;
  }
  return (long long) a * b;
}

unsigned long long gcd_fast(unsigned long long a, unsigned long long b){
  unsigned long long a1 = a;
  unsigned long long result;
  if(a < b){
    a1 = a;
    unsigned long long a2 = b % a;
    unsigned long long a3;
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
    unsigned long long b1 = b;
    unsigned long long b2 = a % b;
    unsigned long long b3;
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
  return (unsigned long long) result;
  }
unsigned long long lcm_fast(unsigned long long a, unsigned long long b){
  
  return a*b/gcd_fast(a ,b);
}


int main() {
  unsigned long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
