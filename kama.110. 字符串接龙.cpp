#include <iostream>
#include <string>
#include <vector>

using namespace std;

int m = 501;

void dfs(int pos, vector<vector<int> > &selected, int goal, int step) {
    if (pos == goal) {
        m = min(m, step);
        return;
    }
    for (int i = 0;)
}


int main() {
    int N;
    cin >> N;
    vector<string> str(N + 2);
    vector<vector<int> > selected(N + 2, vector<int>(N + 2));
    cin >> str[0] >> str[N + 1];
    for (int i = 1; i < N; i++) {
        cin >> str[i];
    }
    for (int i = 0; i < N + 2; i++) {
        for (int j = i + 1; j < N + 2; j++) {
            for (int k = 0; k < str[0].length(); k++) {
                if (str[i][k] != str[j][k]) {
                    selected[i][j]++;
                    selected[j][i]++;
                }
                
            }
        }
    }
    dfs[0];
 


    return 0;
}