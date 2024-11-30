#include <iostream>
#include <string>

using namespace std;



int main() {
    string result;
    char tmp_c;
    while (~scanf("%c", &tmp_c)) {
        if (tmp_c >= '0' && tmp_c <= '9')
            result += "number";
        else {
            result += tmp_c;
        }
        
    }
    cout << result;
    return 0;
}