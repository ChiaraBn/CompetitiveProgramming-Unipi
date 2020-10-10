/*
 * Original problem at:
 * https://codeforces.com/contest/1398/problem/E?locale=en
 */


#include <iostream>
#include <vector>
#include <algorithm>


struct spell {
    int type;           // 0: fire, 1: lightning
    int damage;

    spell(int t, int d) : type{t}, damage{d} {}
} ;


bool compareDamage (spell sp1, spell sp2) {
    return (sp1.type > sp2.type);
}


void maxDamage (std:: vector<spell> &v) {
    std:: sort(v.begin(), v.end(), compareDamage);

    bool doubleD = false;
    int tot = 0;
    for (int i = 0; i < v.size(); i++) {
        if (doubleD) {
            tot += (2 * v[i].damage);
        }
        else {
            tot += v[i].damage;
        }

        doubleD = (v[i].type == 1)? true: false;
    }

    std:: cout << tot << std:: endl;
}


void forget (std:: vector<spell> &v, int tp, int d) {
    
    for (auto it = v.begin(); it != v.end(); it++){
        if (it->damage == abs(d) && it->type == tp) {
            v.erase(it);
            break;
        }
    }
}


int main (void) {

    std:: vector<spell> spells;

    int n = 0, tp = 0, d = 0;
    std:: cin >> n;
    spells.reserve(n);

    for (int i = 0; i < n; i++) {
        std:: cin >> tp;
        std:: cin >> d;

        if (d < 0) 
            forget (spells, tp, d);
        else {
            spell elem = spell (tp, d);
            elem.type = (tp == 0)? 0: 1;
            spells.push_back(elem);
        }

        maxDamage(spells); 
    }

    spells.clear();
    return 0;
}