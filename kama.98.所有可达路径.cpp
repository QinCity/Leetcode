#include <iostream>
#include <vector>

using namespace std;

struct Node {
  Node* next;
  int val;
  Node (Node* n, int v): next(n), val(v) {}
};

vector<vector<int> > result;
vector<int> cur_result;

void dfs(int num, int N, vector<Node*> &p) {
    if (num == N) {
        result.push_back(cur_result);
        return;
    }
    if (p[num - 1]->next == NULL)
        return;
    Node* cur = p[num - 1]->next;
    while (cur) {
        cur_result.push_back(cur->val);
        dfs(cur->val, N, p);
        cur_result.pop_back();
        cur = cur->next;
    }
}


int main() {
    int N, M;
    cin >> N >> M;
    vector<Node*> p(N);
    for (int i = 0; i < N; ++i) {
        p[i] = new Node(NULL, 0);
    }

    for (int i = 0; i < M; i++) {
        int begin, end;
        cin >> begin >> end;
        Node* cur = new Node(p[begin - 1]->next, end);
        p[begin - 1]->next = cur;
    }

    // Node* tmp = p[1]->next;
    // while (tmp != NULL) {
    //     cout << tmp->val;
    //     tmp = tmp->next;
    // }

    cur_result.push_back(1);
    dfs(1, N, p); 
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            if (j == 0)
                cout << result[i][j];
            else
                cout << " " << result[i][j];
        }
        if (i != result.size() - 1)
            cout << endl;
    }
    if (result.size() == 0)
        cout << "-1";
    
}