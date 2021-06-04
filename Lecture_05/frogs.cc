#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct frog {
    int64_t x, end, i, eaten;

    frog(int64_t x, int64_t end, int64_t i, int64_t e) : 
    x{x}, end{end}, i{i}, eaten{e} {}
};

struct mosquito {
    int64_t p;
    int64_t b;

    mosquito(int64_t p, int64_t b) : p{p}, b{b} {}
};

bool compare (frog f1, frog f2) {
    return (f1.x < f2.x);
}

bool compare_i (frog f1, frog f2) {
    return (f1.i < f2.i);
}

void eat (map<int64_t, frog>::iterator ub_frog, vector<frog> &f,
         map<int64_t, frog> &bst_frog, multimap<int64_t, int64_t> &bst_mos) {
    
    //dynamic intervals
    auto to_eat = bst_mos.lower_bound(ub_frog->first);
    auto length = ub_frog->second.end;
    
    if (to_eat != bst_mos.end() && to_eat->first <= length) {
        ub_frog->second.end += to_eat->second;
        f[ub_frog->second.i].end += to_eat->second;
        f[ub_frog->second.i].eaten++;
        to_eat = bst_mos.erase(to_eat);

        auto n = next(ub_frog);
        bool del = true;
        while (del) {
            del = false;
            if (n != bst_frog.end()) {
                if (n->first <= ub_frog->second.end) {
                    if (n->second.end <= ub_frog->second.end) {
                        bst_frog.erase(n);
                        n = next(ub_frog);
                        del = true;
                    }
                    else {
                        frog nf = frog (ub_frog->second.end+1, n->second.end, n->second.i, n->second.eaten);
                        bst_frog.erase(n);
                        bst_frog.insert(make_pair(nf.x, nf));
                    }
                }
            }
        }

        return eat (ub_frog, f, bst_frog, bst_mos);       
    }
}

void maxMosquito (vector<frog> f, vector<mosquito> m) {
    sort (f.begin(), f.end(), compare);

    map<int64_t, frog> bst_frog;
    multimap<int64_t, int64_t> bst_mos;

    bst_frog.insert(make_pair(f[0].x, f[0]));
    auto prec = f[0].end;
    for (int i = 1; i < f.size(); i++) {
        //overlapping
        if (f[i].end > prec) {
            bst_frog.insert(make_pair(max(prec+1, f[i].x), f[i]));
            prec = f[i].end;
        }
    }
    
    sort (f.begin(), f.end(), compare_i);
    for (int i = 0; i < m.size(); i++) {
        auto ub_frog = bst_frog.upper_bound(m[i].p);
        ub_frog = prev(ub_frog);

        if (ub_frog != bst_frog.end()) {
            bst_mos.insert(make_pair(m[i].p, m[i].b));
            eat (ub_frog, f, bst_frog, bst_mos);
        }
        else {
            bst_mos.insert(make_pair(m[i].p, m[i].b));
        }
    }
    
    for (auto &frog : f) {
        cout << frog.eaten << " " << (frog.end - frog.x) << endl;
    }

}

int main (void) {
    std::ios_base::sync_with_stdio(false);

    vector<frog> frogs;
    vector<mosquito> mosquitoes;
    
    int n = 0, m = 0;
    cin >> n >> m;

    frogs.reserve(n);
    mosquitoes.reserve(m);

    int64_t x = 0, value = 0;
    for (auto i = 0; i < n; i++) {
        cin >> x >> value;        
        frogs.push_back(frog(x, x+value, i, 0));
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> value;
        mosquitoes.push_back(mosquito(x, value));
    }

    maxMosquito (frogs, mosquitoes);
   
    frogs.clear();
    mosquitoes.clear();

    return 0;
}