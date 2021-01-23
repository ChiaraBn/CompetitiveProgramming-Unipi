#include <iostream>
#include <vector>
#include <string>

void find (std:: string const&s, std::vector<std::pair<int,int>> const &q) {

    std::vector<int> count(s.length(),0);
    
    // prefix sum into the count vector
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1])
            count[i] = count[i-1]+1;
        else
            count[i] = count[i-1];
    }

    for (int i = 0; i < q.size(); i++) {
        std::cout << count[q[i].second-1] - count[q[i].first -1] << std::endl;
    }
}

int main(void) {

    std:: string s;
    std:: vector<std::pair<int, int>> queries;
    int m = 0;

    std:: cin >> s;
    std:: cin >> m;
    queries.reserve(m);

    int l = 0, r = 0;
    for (int i = 0; i < m; i++){
        std:: cin >> l >> r;
        queries.push_back(std::make_pair(l,r));
    }

    find (s, queries);

    s.clear();
    queries.clear();
    return 0;
}