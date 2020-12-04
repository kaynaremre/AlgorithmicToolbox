#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;



struct m1m2{
  int m1;
  int m2;
};

m1m2 partition3(vector<int> &a, int l, int r){
    m1m2 s;
    
    int piv = a[l];
    int j = l;
    int k = l + 1;

    for (int i = l + 1; i <=r; i++){

      if(a[i] <= piv){
        j++;
        swap(a[i], a[j]);

        if (a[j] < piv){
          swap(a[k], a[j]);
          k++;
        }        
      }
    }
    swap(a[l], a[k-1]);
    s.m1 = k;
    s.m2 = j;
    return s;
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  m1m2 osas = partition3(a, l, r);

  int m_1 = osas.m1;
  int m_2 = osas.m2;

  randomized_quick_sort(a, l, m_1 - 1);
  randomized_quick_sort(a, m_2 + 1, r);
}

vector<int> stress_test(){
  vector<int> arr;

  for(int i = 0; i < 10; i++){
    arr.push_back(rand() % 5);
  }
  return arr;

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  } 
}
