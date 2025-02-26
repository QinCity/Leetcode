#include <iostream>
#include <vector>

using namespace std;

int M,N;


void dfs(vector<vector<int> > &high, vector<vector<int> > &selected) {
        
}


int main() {
    cin >> N >> M;
    vector<vector<int> > high(N, vector<int>(M));
    vector<vector<int> > selected(N, vector<int>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> high[i][j];
        }
    }

    return 0;
}