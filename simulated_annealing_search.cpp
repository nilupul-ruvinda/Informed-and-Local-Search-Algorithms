#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int f(int x) {
    return max(10 - (x - 5) * (x - 5), 20 - (x - 15) * (x - 15));
}

int main() {
    int current;
    double T_temp, alpha;
    if (!(cin >> current >> T_temp >> alpha)) return 0;
    
    int best_x = current;
    int best_f = f(current);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        int d;
        double u;
        cin >> d >> u;
        
        int next_x = current + d;
        if (next_x >= 0 && next_x <= 20) {
            int delta = f(next_x) - f(current);
            
            if (delta > 0) {
                current = next_x;
            } else {
                if (u < exp(delta / T_temp)) {
                    current = next_x;
                }
            }
            
            if (f(current) > best_f) {
                best_f = f(current);
                best_x = current;
            }
        }
        T_temp *= alpha;
    }
    
    cout << best_x << " " << best_f << endl;
    return 0;
}
