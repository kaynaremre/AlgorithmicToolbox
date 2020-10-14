#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;

long long pisanos(long long n)
{
    int m = 10;
    int sum = 0;
    vector<long long> pisano;
    pisano.push_back(0);
    pisano.push_back(1);
    pisano.push_back(1);
    int index = 0;
    for (int i = 3;; ++i)
    {
        pisano.push_back((pisano.at(i - 1) + pisano.at(i - 2)) % m);
        if (pisano.at(i) == 1 && pisano.at(i - 1) == 0)
        {
            for (int k = 0; k < 2; ++k)
            {
                pisano.pop_back();
            }
            //index = n % pisano.size();
            //return pisano.at(index);
            break;
        }
    }
    pisano.erase(pisano.begin());
    int net = n % 60;
    long long os = n / 60;
    for (int o = 0; o < pisano.size(); ++o){
        sum = sum + pisano.at(o);
        sum = sum % 10;
    }
    sum = sum * os;
    pisano.insert(pisano.begin(), 0);
    int sumpis = 0;
    for (int a = 0; a < net + 1; ++a){
        sumpis = sumpis + pisano.at(a);
        sumpis = sumpis % 10;
    }
    return (sum + sumpis) % 10;
}

int main()
{
    unsigned long long n;
    std::cin >> n;
    std::cout << pisanos(n) << '\n';
    return 0;
}