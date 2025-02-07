#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<pair<int, int> > mater(M, make_pair(0, 0));
    vector<vector<int> > dp(M, vector<int>(N + 1));
    for (int i = 0; i < M; i++) {
        cin >> mater[i].first;
    }
    for (int i = 0; i < M; i++) {
        cin >> mater[i].second;
    }
    for (int i = 0; i < M; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < N + 1; i++) {
        if (i >= mater[0].first)
            dp[0][i] = mater[0].second;
    }
    cout << endl;
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (j - mater[i].first >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - mater[i].first] + mater[i].second);
            else
                dp[i][j] = dp[i - 1][j];
            cout << dp[i][j];
        } 
        cout << endl;
    }
    cout << dp[M - 1][N];
    return 0;
}