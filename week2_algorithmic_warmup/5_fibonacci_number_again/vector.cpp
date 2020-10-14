#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using std::vector;
using std::cin;
using std::cout;

int main(){
    vector <long long> vec(2000,1);
    int count = 0;
    vec.push_back(31);
    for (int i = 0; i < vec.size(); ++i){
        count ++;
    }
    cout << count << " " << vec.max_size() << " " << vec.at(1543) << " " << vec.at(2000);
    
    return 0;
}