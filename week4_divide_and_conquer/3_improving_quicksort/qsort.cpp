#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;


int partition2(vector<int> &a, int l, int r) { 
    int piv = a[l];
    int j = l; //keeps index for left region (smaller)

    for(int i = l + 1; i <= r; i++){
        if(a[i] <=  piv){
            j++;
            swap(a[j], a[i]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

void q_sort(vector<int> &a, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    //int k = l + rand() % (r - l + 1);
    //swap(a[l], a[k]);
    int m = partition2(a, l, r); // returns an element between index of l and r and rearranges the array 
                                // now all the elements greater then m is right side and vice-versa

    q_sort(a, l, m - 1);
    q_sort(a, m + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  q_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}

