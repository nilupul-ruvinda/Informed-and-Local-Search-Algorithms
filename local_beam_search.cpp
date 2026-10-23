#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int f(int x) {
    return max(10 - (x - 5) * (x - 5), 20 - (x - 15) * (x - 15));
}

bool compareStates(int a, int b) {
    if (f(a) != f(b))
        return f(a) > f(b);
    return a < b;
}

int main() {
    int k;
    if (!(cin >> k)) return 0;
    
    vector<int> states(k);
    for (int i = 0; i < k; ++i) {
        cin >> states[i];
    }
    
    int best_val = -1000000;
    int best_x = -1;
    for (int s : states) {
        if (f(s) > best_val || (f(s) == best_val && s < best_x)) {
            best_val = f(s);
            best_x = s;
        }
    }
    
    for (int iter = 0; iter < 1000; ++iter) {
        set<int> pool;
        for (int s : states) {
            pool.insert(s);
            if (s - 1 >= 0) pool.insert(s - 1);
            if (s + 1 <= 20) pool.insert(s + 1);
        }
        
        vector<int> candidates(pool.begin(), pool.end());
        sort(candidates.begin(), candidates.end(), compareStates);
        
        vector<int> next_states;
        for (int i = 0; i < min(k, (int)candidates.size()); ++i) {
            next_states.push_back(candidates[i]);
        }
        
        int current_best_x = next_states[0];
        int current_best_val = f(current_best_x);
        
        if (current_best_val <= best_val) {
            break; 
        }
        
        best_val = current_best_val;
        best_x = current_best_x;
        states = next_states;
    }
    
    cout << best_x << " " << best_val << endl;
    
    return 0;
}
