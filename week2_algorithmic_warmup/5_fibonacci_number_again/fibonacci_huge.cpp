#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using std::vector;
using std::cin;
using std::cout;
  
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

unsigned long long fibonacci_fast(unsigned long long n) {
    unsigned long long array [n+1];
    array[0] = 0;
    array[1] = 1;
    
    for (unsigned long long i = 2; i < n+1; ++i){
        array[i] = array[i-1] + array[i-2];
    }
    unsigned long long a = array[n];
    return a;
}

unsigned long long get_fibonacci_huge_fast(unsigned long long n, unsigned long long m){
    unsigned long long a = 31;
    unsigned long long i = 2;
    int flag = 1;
    if (n <= 1){
        return n;
    }
    else{
        vector<unsigned long long> modulos;
        unsigned long long index;
        modulos.push_back(5);
        modulos.push_back(5);
        while(flag){
            modulos.push_back(fibonacci_fast(i - 1) % m);
            if (modulos.at(i - 1) == 0 && modulos.at(i) == 1){
                modulos.erase(modulos.begin());
                modulos.erase(modulos.begin());
                modulos.insert(modulos.begin(), 0);
                for(int k = 0; k < 2; ++k){
                     modulos.pop_back();
                }
                index = n % modulos.size();
                //cout << modulos.size() << " ";
                flag = 0;
                return modulos.at(index);
            }
           i ++;
        }
    }
    return a;
}

int main() {
    unsigned long long n;
    unsigned long long m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
