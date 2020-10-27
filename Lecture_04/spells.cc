/*
 * Original problem at:
 * https://codeforces.com/contest/1398/problem/E?locale=en
 */


#include <iostream>
#include <vector>
#include <algorithm>


struct spell {
    int type;           // 0: fire, 1: lightning
    unsigned long damage; 

    spell(int t, unsigned long d) : type{t}, damage{d} {}
} ;


bool compare (spell sp1, spell sp2) {
    return (sp1.type > sp2.type);
}
//return (sp1.type > sp2.type && sp1.damage > sp2.damage);

void maxDamage (std:: vector<spell> &v) {
    std:: sort(v.begin(), v.end(), compare);

    bool doubleD = false;
    unsigned long tot = 0;
    for (auto it = v.begin(); it != v.end(); it++) {
        if (doubleD) {
            tot += 2 * (it -> damage);
        }
        else {
            tot += it -> damage;
        }

        doubleD = (it -> type == 1)? true: false;
    }

    printf ("%lu \n", tot);
}


void forget (std:: vector<spell> &v, int tp, long int d) {
    
    for (auto it = v.begin(); it != v.end(); it++){
        if (it->damage == abs(d) && it->type == tp) {
            v.erase(it);
            break;
        }
    }
}


int main (void) {
    std::ios_base::sync_with_stdio(false);

    std:: vector<spell> spells;
    int n = 0, tp = 0;
    long int d = 0;

    scanf ("%d", &n);
    spells.reserve(n);

    for (int i = 0; i < n; i++) {
        scanf ("%d", &tp);
        scanf ("%ld", &d);

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