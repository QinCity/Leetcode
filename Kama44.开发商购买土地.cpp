#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    int min = 1000000;
    cin >> n >> m;
    vector<vector<int> > land(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> land[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            land[i][j] = land[i - 1][j] + land[i][j - 1] - land[i - 1][j - 1] + land[i][j];
        }
    }

    for (int i = 0; i <= n; i++) {
        if (abs(land[n][m] - 2 * land[i][m]) < min)
            min = abs(land[n][m ] - 2 * land[i][m]);
    }
    for (int i = 0; i <= m; i++) {
        if (abs(land[n][m] - 2 * land[n][i]) < min)
        min = abs(land[n][m] - 2 * land[n][i]); 
    }
    cout << min;
    return 0;
}