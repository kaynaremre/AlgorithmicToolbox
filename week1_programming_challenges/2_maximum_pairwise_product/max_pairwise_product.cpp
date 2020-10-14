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
    return ((long long)(numbers[max_index1])) * numbers[max_index2];
}

int main() {

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
