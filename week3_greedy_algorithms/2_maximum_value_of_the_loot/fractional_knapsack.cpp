#include <iostream>
#include <vector>

using namespace std; 

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  int n = values.size();

  double per_unit_value[n];

  int sum_weights = 0, sum_values = 0;

  for(int i = 0; i < n; ++i){
    per_unit_value[i] = (double)values[i] / weights[i];
    sum_weights += weights[i];
    sum_values += values[i];  
  }

  if(sum_weights < capacity)
    return (double)sum_values;

  while(capacity){
    int index_max;
    double max;
    max = 0.0, index_max = 0;
    for(int i = 0; i < n; ++i){
      if(max < per_unit_value[i])
        max = per_unit_value[i],  index_max = i;
    }
    if(weights[index_max] >= capacity){
      value += max * capacity;
      
      capacity -= capacity;
    }
    else{
      value += max *  weights[index_max];
      capacity -= weights[index_max];
      weights[index_max] = 0;
      per_unit_value[index_max] = 0;
    } 
  }

  return value;
}

int main() {
  int n;
  double capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
