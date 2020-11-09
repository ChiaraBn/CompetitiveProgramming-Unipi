/*
 * Original problem at:
 * https://codeforces.com/contest/609/problem/F?locale=en
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


struct frog {
    int x;             // position
    int t;            
    int eaten;

    frog(int x, int l, int e) : x{x}, t{l}, eaten{e} {}
};

struct mosquito {
    int p;             // position
    int size;

    mosquito(int p, int s) : p{p}, size{s} {}
};


bool compare (frog f1, frog f2) {
    return (f1.x < f2.x);
}

void maxMosquito (std:: vector<frog> &f, std:: vector<mosquito> &m) {
    std:: sort (f.begin(), f.end(), compare);

    std:: set<int> uneaten_mosquitoes;

    for (auto it = m.begin(); it != m.end(); it++) {
        if (it -> size != -1) {        //mosquito not eaten yet


            it -> size = -1;
        }
    }

    for (auto it = f.begin(); it != f.end(); it++) {
        printf("%d %d\n", it -> eaten, it -> t);
    }   
}


int main (void) {
    std::ios_base::sync_with_stdio(false);

    std:: vector<frog> frogs;
    std:: vector<mosquito> mosquitoes;
    
    int n = 0, m = 0;
    scanf("%d", &n);
    scanf("%d", &m);

    frogs.reserve(n);
    mosquitoes.reserve(m);

    int x = 0, value = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        scanf("%d", &value);

        frogs.push_back(frog(x, value, 0));
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        scanf("%d", &value);

        mosquitoes.push_back(mosquito(x, value));
    }

    maxMosquito (frogs, mosquitoes);

    frogs.clear();
    mosquitoes.clear();

    return 0;
}