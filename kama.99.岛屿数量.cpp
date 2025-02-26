#include <iostream>
#include <vector>

using namespace std;

int direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N, M;
int result = 0;

void dps(vector<vector<int> > &visited, int x, int y) {
    if (!(0 <= x && x < N && 0 <= y && y < M) || visited[x][y] == 0) {
        return;
    }
    visited[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        // cout << x + direct[i][0] << " " << y + direct[i][0] << endl;
        dps(visited, x + direct[i][0], y + direct[i][1]);
    }
}


int main() {
    cin >> N >> M;
    vector<vector<int> > visited(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> visited[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 1) {
                dps(visited, i, j);
                result++;
            }
        }
    }
    cout << result;
    return 0;
}