#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int numRefills = 0;
    int currentRefill = 0;
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);
    int n = stops.size();
    int lastRefill = 0;
    while(currentRefill < (n - 1)){
        lastRefill = currentRefill;
        while(currentRefill < (n - 1) && (stops.at(currentRefill + 1) - stops.at(lastRefill)) <= tank ){
            currentRefill = currentRefill + 1;
        }
        if (currentRefill == lastRefill){
            return -1;
        }
        if(currentRefill < (n - 1)){
            numRefills = numRefills + 1;
        }
    }
    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
