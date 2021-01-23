#include <iostream>
#include <vector>
#include <algorithm>


void maximum (std::vector<long long> &a, std::vector<std::pair<long long, long long>> const &q) {
    long long res = 0; 
    std::vector<long long> p(a.size(),0);
    std::vector<long long> b(a.size(),0);      
 
    // prefix sum
    for (int i = 0; i < q.size(); i++) {
        b[q[i].first-1] += 1;
        if (q[i].second != a.size())
            b[q[i].second] -= 1;
    }
        
    p[0] = b[0];
    for (int i = 1; i < b.size(); i++) {
        p[i] = p[i-1] + b[i];
    }

    std::sort (a.begin(), a.end());
    std::sort (p.begin(), p.end());

    // answering the queries
    for (int i = 0; i < a.size(); i++) {
        res = res + (a[i] * p[i]);
    }    
    std::cout << res << std::endl;

    p.clear();
    b.clear();
}

int main (void) {
    std::ios_base::sync_with_stdio(false);

    int n = 0, q = 0;
    long long elem = 0, l = 0, r = 0;
    std::cin >> n >> q;

    std::vector<long long> array;
    array.reserve(n);
    std::vector<std::pair<long long,long long>> queries;
    queries.reserve(q);

    for (int i = 0; i < n; i++){
        std::cin >> elem;
        array.push_back(elem);
    }

    for (int i = 0; i < q; i++) {
        std::cin >> l >> r;
        queries.push_back(std::make_pair(l,r));
    }

    maximum (array, queries);

    array.clear();
    queries.clear();
    return 0;
}