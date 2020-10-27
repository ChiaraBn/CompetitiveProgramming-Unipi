## Description of the problems

###### [Two types of spells](https://codeforces.com/contest/1398/problem/E?locale=en)

In order to solve this problem, it has been introduced a data structure `spell`, that is defined as follow:

```
struct spell {
    int type;           // 0: fire, 1: lightning
    unsigned long damage; 

    spell(int t, unsigned long d) : type{t}, damage{d} {}
} ;
```
Once this is defined, it's possible to create a **vector** out of this, in order to save all the data of the problem.

Then, the solution takes in consideration the new input and if the spell must be forgotten (damage < 0), it'll be erased from the vector.
In any case, it sorts the vector by the type of the spells and it counts the total damage of the remaining ones.

**Time complexity:** O(n log n) for the sorting and θ(n) the scan.
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_04/spells.cc)