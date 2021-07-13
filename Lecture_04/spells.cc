#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int64_t n = 0, tp = 0, d = 0;
    cin >> n;

    int cnt = 0;
    long long ans = 0;
    set<long long> all, set_one, set_two;

    for (int i = 0; i < n; i++) {
        cin >> tp >> d;

        ans += d;
        if (d > 0) {
            if (tp == 1)
                cnt++;
            else
                all.insert(d);

            if (set_one.size() && d <= *set_one.rbegin()) 
                set_one.insert(d);
            else {
                set_two.insert(d);
                ans += d;
            }
        } 
        else {
            if (tp == 1) 
                cnt--;
            else 
                all.erase(-d);

            if (set_one.size() && -d <= *set_one.rbegin()) 
                set_one.erase(-d);
            else {
                set_two.erase(-d);
                ans += d;
            } 
        }

        while (set_two.size() > cnt) {
            int x = *set_two.begin();
            set_two.erase(x);
            set_one.insert(x);
            ans -= x;
        }

        while (set_two.size() < cnt) {
            int x = *set_one.rbegin();
            set_two.insert(x);
            set_one.erase(x);
            ans += x;
        }
        
        long long x = 0;
        if (set_two.size()) {
            if (all.size()) {
                x = min(x, *all.rbegin() - *set_two.begin());
            }
            else {
                x = 0 - *set_two.begin();
            } 
        }
        cout << ans + x << endl;
    }

    return 0;
}