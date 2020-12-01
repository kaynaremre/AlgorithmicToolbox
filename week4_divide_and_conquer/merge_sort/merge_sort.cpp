#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

vector<int> merge(vector<int> &lo, vector<int> &hi){
    vector<int> res;
    sort(lo.begin(), lo.end());
    sort(hi.begin(), hi.end());

    int b;
    int c;

    while (lo.size() != 0 && hi.size() != 0){
        b = lo.at(0);
        c = hi.at(0);

        if(b <= c){
            res.push_back(b);
            lo.erase(lo.begin());
        }
        else{
            res.push_back(c);
            hi.erase(hi.begin());

        }
    }
    while(lo.size() != 0){
        res.push_back(lo[0]);
        lo.erase(lo.begin());
    }
    while(hi.size() != 0){
        res.push_back(hi[0]);
        hi.erase(hi.begin());
    }

    return res;
}

vector<int> mergeSort(const vector<int> &a){
    if( a.size() == 1){
        return a;
    }

    int m = a.size() / 2;

    vector<int> lo(a.begin(), a.begin() + m);

    vector<int> hi(a.begin() + m, a.end());

    mergeSort(lo);
    mergeSort(hi);

    return merge(lo, hi);

}

int main(){
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
   }

    a = mergeSort(a);

   for(int i = 0; i < a.size(); i++){
       cout << a[i] << " ";
   }

}