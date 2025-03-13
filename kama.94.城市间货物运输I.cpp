#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > roads(n + 1);
    for (int i = 0; i < m; i++) {
        int s, t, v;
        cin >> s >> t >> v;
        roads[s].push_back(pair<int, int>(t, v));
    }
    
    queue<int> q;
    vector<int> min_dist(n + 1, INT_MAX);
    vector<bool> is_in_queue(n + 1, false);

    min_dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        is_in_queue[t] = 0;
        for (auto r : roads[t]) {
            if (min_dist[r.first] > min_dist[t] + r.second) {
                min_dist[r.first] = min_dist[t] + r.second;
                if (!is_in_queue[r.first]) {
                    q.push(r.first);
                    is_in_queue[r.first] = 1;
                }
            }
        }

    }
    if (min_dist[n] == INT_MAX)
        cout << "unconnected";
    else {
        cout << min_dist[n];
    }
    return 0;
}