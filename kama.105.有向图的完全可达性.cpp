#include <iostream>
#include <vector>
#include <deque>

using namespace std;



int main() {
    int N,K;
    cin >> N >> K;
    deque<int> deq;
    vector<bool> used(N + 1);
    vector<vector<int> > road(N + 1, vector<int>(N + 1));
    for (int i = 0; i < K; i++) {
        int l, r;
        cin >> l >> r;
        road[l][r] = 1;
    }
    deq.push_back(1);
    used[1] = 1;
    while (!deq.empty()) {
        int cur_num = deq.front();
        deq.pop_front();
        for (int j = 1; j < N + 1; j++) {
            if (!used[j] && road[cur_num][j]) {
                deq.push_back(j);
                used[j] = 1;
            }
        }
    }
    for (int i = 1; i < N + 1; i++){
        if (used[i] == 0) {
            cout << "-1"; 
            return 0;
        }
    }
    cout << "1";
    return 0;
    
}