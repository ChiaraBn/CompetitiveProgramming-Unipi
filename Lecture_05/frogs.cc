/*
 * Original problem at:
 * https://codeforces.com/contest/609/problem/F?locale=en
 */

#include <iostream>
#include <vector>
#include <algorithm>


struct frog {
    int x;             // position
    int t;             // tongue
    int eaten;

    frog(int x, int t, int e) : x{x}, t{t}, eaten{e} {}
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

    for (int i = 0; i < m.size(); i++) {
        if (m[i].size != -1) {        //mosquito not eaten yet


            m[i].size = -1;
        }
    }

    // output n righe con <eaten, lungLingua> per rana i
}


int main (void) {

    std:: vector<frog> frogs;
    std:: vector<mosquito> mosquitoes;
    
    int n = 0, m = 0;
    std:: cin >> n;
    std:: cin >> m;

    frogs.reserve(n);
    mosquitoes.reserve(m);

    int x = 0, value = 0;
    for (int i = 0; i < n; i++) {
        std:: cin >> x;
        std:: cin >> value;

        frogs.push_back(frog(x,value,0));
    }

    for (int i = 0; i < m; i++) {
        std:: cin >> x;
        std:: cin >> value;

        mosquitoes.push_back(mosquito(x,value));
    }

    maxMosquito (frogs, mosquitoes);

    frogs.clear();
    mosquitoes.clear();

    return 0;
}