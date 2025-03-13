#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>

using namespace std;

class Compair{
public:
    bool operator() (const pair<int, int>& l, const pair<int, int>& r) {
        return l.second > r.second;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<list<pair<int, int> > > road(N + 1);
    for (int i = 1; i <= M; i++) {
        int S, E, V;
        cin >> S >> E >> V;
        road[S].push_back(pair<int, int>(E, V));
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, Compair> pile;
    vector<bool> visited(N + 1);
    vector<int> min_dis(N + 1, INT_MAX);
    
    pile.push(pair<int, int>(1, 0));

    while (!pile.empty()) {
        pair<int, int> h = pile.top();
        pile.pop();
        if (visited[h.first]) {
            continue;
        }
        visited[h.first] = true;
        for (auto r: road[h.first]) {
            if (visited[r.first] == false && min_dis[r.first] > h.second + r.second) {
                min_dis[r.first] = h.second + r.second;
                pile.push(pair<int, int>(r.first, min_dis[r.first]));
            }
        }
    } 
    if (min_dis[N] == INT_MAX)
        cout << "-1";
    else
        cout << min_dis[N];
    return 0;
}