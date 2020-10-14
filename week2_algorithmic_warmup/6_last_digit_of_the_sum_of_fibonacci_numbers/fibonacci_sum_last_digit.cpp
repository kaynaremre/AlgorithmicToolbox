#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n){
    int array [n+1];
    int sum = 0;
    array[0] = 0;
    array[1] = 1;
    
    for (long long i = 2; i < n+1; ++i){
        array[i] = array[i-1] + array[i-2];
        array[i] = array[i] % 10;
    }
    for (long long j = 0; j < n+1; ++j){
        sum = array[j] + sum;
        sum = sum % 10;
    }
    return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
