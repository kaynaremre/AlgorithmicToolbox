#include <cstdlib> // to generate random numbers
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long result = 0;
    long long n = numbers.size();
    for (int i = 0; i < n; ++i){
        for (int j = i+1; j < n; ++j){
            if (((long long)numbers[i]) * numbers[j] > result){
                result = ((long long)numbers[i]) * numbers[j];
            }
        }
    }
    return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
    int n = numbers.size();

    int max_index1 = -1;
    for (int i = 0; i < n; ++i){
        if((max_index1 == -1) || (numbers[i] > numbers[max_index1])){
            max_index1 = i;
        }
    }
    int max_index2 = -1;
    for (int j = 0; j < n; ++j){
        if((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2]))){
            max_index2 = j;
        }
    }
    cout << max_index1 << ' ' << max_index2 << "\n";
    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {
    while (true) {
        int n = rand() % 1000 + 2; // rand() gives us randon 0-9 and we add 2 in case n = 0 or 1 so we get 2-11 random
        cout << n << "\n";       // rand() %10 0-9  rand() %100 0-99 //rand() % 30 + 1985 1985-2014
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(rand() % 100000); // push_back() adds new element to the end of the vector 
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << "\n";
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);
        if (res1 != res2) {
            cout << "Wrong Answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else{
            cout << "OK\n";
        }
    }
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProductFast(vector<int>(numbers));
    cout << result << "\n";
    return 0;
}
