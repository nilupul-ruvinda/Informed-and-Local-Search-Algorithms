#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int x) {
    return max(10 - (x - 5) * (x - 5), 20 - (x - 15) * (x - 15));
}

int main() {
    int T;
    if (!(cin >> T)) return 0;
    
    while (T--) {
        int x;
        cin >> x;
        
        while (true) {
            int best_nx = x;
            int max_val = f(x);
            
            // Check valid neighbors
            vector<int> neighbors;
            if (x - 1 >= 0) neighbors.push_back(x - 1);
            if (x + 1 <= 20) neighbors.push_back(x + 1);
            
            for (int nx : neighbors) {
                int val = f(nx);
                if (val > max_val) {
                    max_val = val;
                    best_nx = nx;
                } else if (val == max_val && nx < best_nx) {
                    best_nx = nx;
                }
            }
            
            if (max_val > f(x)) {
                x = best_nx;
            } else {
                break;
            }
        }
        cout << x << " " << f(x) << endl;
    }
    return 0;
}
