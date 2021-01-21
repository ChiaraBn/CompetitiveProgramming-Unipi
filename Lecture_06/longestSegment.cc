#include <iostream>
#include <vector>
#include <unordered_map>

void findK (std:: vector<int> const&a, int k) {

    int l = 0, r = 0, max = 0;
    std::unordered_map<int, int> map;       // <int, int> = <element, occurences>
    std::pair<int, int> final;

    while (r < a.size()) {
        if (map.find(a[r]) == map.end()) {
            map.insert(std::make_pair(a[r], 1));
        }
        else {
            map[a[r]]++;
        }

        while (map.size() > k) {
            map[a[l]]--;

            if (map[a[l]] == 0) {
                map.erase(a[l]);
            }
            l++;
        }
        if ((r - l) >= max) {
            max = (r - l);
            final = std::make_pair(l,r);
        }

        r++;
    }

    printf ("%d %d\n", final.first+1, final.second+1);
}

int main (void) {
    
    std:: vector<int> array;
    int n = 0, k = 0, elem = 0;

    scanf("%d", &n);
    scanf("%d", &k);

    array.reserve(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &elem);
        array.push_back(elem);
    }

    findK (array, k);

    array.clear();
    return 0;
}