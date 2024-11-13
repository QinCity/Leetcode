#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> num(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
        num[i] += num[i - 1];
    }  
    int a, b;
    while (~scanf("%d %d", &a, &b)) {
        cout << num[b + 1] - num[a] << endl;
    }
    return 0;
}