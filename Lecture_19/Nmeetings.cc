#include <bits/stdc++.h>
using namespace std;

bool compare (pair<int, int> v1, pair<int, int> v2) {
    return v1.second < v2.second;
}

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> meetings (n);

    for (int i = 0; i < n; i++) {
        meetings[i].first = start[i];
        meetings[i].second = end[i];
    }

    sort (meetings.begin(), meetings.end(), compare);

    int count = 1, last = meetings[0].second;
    for (int i = 1; i < n; i++) {
        if (meetings[i].first > last) {
            count++;
            last = meetings[i].second;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}