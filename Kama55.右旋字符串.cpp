#include <iostream>
#include <string>
#include <algorithm>

using namespace std;




int main() {
    int k;
    string result;
    cin >> k;
    cin >> result;
    reverse(result.begin(), result.end());
    reverse(result.begin(), result.begin() + k);
    reverse(result.begin() + k, result.end());
    cout << result;
    return 0;
}