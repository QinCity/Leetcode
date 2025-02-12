#include<iostream>
#include <vector>

using namespace std;

int main() {
    int C, N;
    cin >> C >> N;
    vector<int> w(N), v(N), k(N);   
    vector<int> dp(C + 1); // dp[j]表示当前j大小的背包最大的价值
    for (int i = 0; i < N; i++)
        cin >> w[i];
    for (int i = 0; i < N; i++) 
        cin >> v[i];
    for (int i = 0; i < N; i++)
        cin >> k[i];
    for (int i = 0; i < N; ++i) {
        for (int j = C; j >= 1; --j) {
            int max_sum = dp[i];
            for (int t = 1; t <= k[i] && t * w[i] <= j; ++t) {
                dp[j] = max(dp[j], dp[j - t * w[i]] + v[i] * t);
            }
        }
    }
    cout << dp[C];
    return 0;
}