#include <bits/stdc++.h>

using namespace std;

const int MAX_K = 1e5 + 10;

priority_queue <int> trucks;

int w[MAX_K];

int main() {

    int n, k;
    int max_truck_weight = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        trucks.push(0);
    }

    for (int i = 0; i < k; i++) {
        cin >> w[i];
    }
    sort(w, w + k);

    for (int i = k-1; i >= 0; i--) {
        int min_truck_weight = trucks.top();
        trucks.pop();
        int new_truck_weight = min_truck_weight - w[i];
        max_truck_weight = max(max_truck_weight, -new_truck_weight);
        trucks.push(new_truck_weight);
    }

    cout << max_truck_weight;
}