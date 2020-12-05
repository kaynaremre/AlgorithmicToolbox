#include <iostream>
#include <vector>


using std::vector;


int get_change(int m) {

  if(m == 0) return 0;

  int coins [3] = {1, 3, 4};

  int minNumCoins[m + 1];

  minNumCoins[0] = 0;

  for(int f = 1; f <= m; f++){
    minNumCoins[f] = INT16_MAX;
      for(int i = 0; i < 3; i++){
        if(coins[i] <= f){
          int amk = minNumCoins[f - coins[i]] + 1;
          if(minNumCoins[f] > amk){
            minNumCoins[f] = amk;
          }
        }
      }
  }
  return minNumCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
