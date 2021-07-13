#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);

    int64_t num = 0;
    cin >> num;
    string s = to_string(num);

    bool one = false, ten = false;
    for (int i = 0; i < s.length(); i++) {

        if (s[i] == '1') {
            one = true;
            ten = false;
        }
        else if (s[i] == '4') {
            if (!one && !ten) {
                cout << "NO\n";
                return 0;
            }
            else if (one) {
                ten = true;
                one = false;
            }
            else {
                ten = false;
                one = false;
            }
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}