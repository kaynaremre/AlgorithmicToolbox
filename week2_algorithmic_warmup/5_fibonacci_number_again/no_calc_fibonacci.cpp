#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;

long long pisanos(long long n, long long m)
{
    vector<long long> pisano;
    pisano.push_back(0);
    pisano.push_back(1);
    pisano.push_back(1);
    bool flag = 1;
    long long index = 0;
    for (int i = 3;; ++i)
    {
        pisano.push_back((pisano.at(i - 1) + pisano.at(i - 2)) % m);
        if (pisano.at(i) == 1 && pisano.at(i - 1) == 0)
        {
            for (int k = 0; k < 2; ++k)
            {
                pisano.pop_back();
            }
            index = n % pisano.size();
            return pisano.at(index);
        }
    }
    return 0;
}

int main()
{
    unsigned long long n;
    unsigned long long m;
    std::cin >> n >> m;
    std::cout << pisanos(n, m) << '\n';

    return 0;
}