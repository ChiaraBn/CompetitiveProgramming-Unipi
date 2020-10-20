/*
 * There are 2n people that must be divided 
 * into groups of two people each.
 * The strength of each possible combination is given
 * and distinct.
 * A and B may form a team if each of them is the best possible teammate 
 * for the other one.
 * Find each person's teammate.
 */


#include <iostream>
#include <vector>
#include <algorithm>


struct team {
    int i;
    int j;
    int strength;

    team(int i, int j, int s) : i{i}, j{j}, strength{s} {}
};


bool compare (team t1 , team t2) {
    return (t1.strength > t2.strength);
}


void find_team(std:: vector<team> &v, int n) {
    std:: sort(v.begin(), v.end(), compare);

    std:: vector<int>res(2*n);
    for (auto it = v.begin(); it != v.end(); it++) {
        if (res[(it -> i) -1] == 0 and res[(it -> j) -1] == 0) {
            res[(it -> i) -1] = it -> j;
            res[(it -> j) -1] = it -> i;
        }
    }

    for (int i = 0; i < res.size(); i++) {
        std:: cout << res[i] << " ";
    }
    std:: cout << std:: endl;
}

int main (void) {

    std:: vector<team> array;
    int n = 0, elem = 0;

    std:: cin >> n;
    array.reserve(n* (n-1) /2);

    for (int i = 2; i <= (2*n); i++) {
        for (int j = 1; j < i; j++) {
            std:: cin >> elem;
            array.push_back(team(i, j , elem));
        }
    }

    find_team(array, n);
    array.clear();

    return 0;
}