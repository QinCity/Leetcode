#include <iostream>
#include <vector>

using namespace std;

int find(int num, vector<int> &father) {
    return (father[num] == num)? num : father[num] = find(father[num], father);
}

int isSame(int a, int b, vector<int> &father) {
    a = find(a, father);
    b = find(b, father);
    return a == b;
}

int main() {
    int N, M;
    int source, terminal;
    cin >> N >> M;
    vector<int> father(N + 1);
    for (int i = 0; i <= N; i++) {
        father[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a = find(a, father);
        father[a] = find(b, father);
    }
    
    cin >> source >> terminal;
    if (find(source, father) == find(terminal, father))
        cout << 1;
    else {
        cout << 0;
    }

    return 0;
}