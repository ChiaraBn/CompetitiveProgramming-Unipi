## Description of the problems

###### [Frogs and mosquitoes](https://codeforces.com/contest/609/problem/F?locale=en)

This particular problem could be solved by the aid of a **BST**, a data structure that maintains an order within its elements. <br>
First of all it is necessary to create two vectors, based upon the structs that will represent the **frogs** and the **moquitoes**. <br>
```
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

```
Thereafter, it is possible to create the BSTs. <br>
- Each frog, represented by a segment, must be indexed into a bst sorted by its initial position.
- **Managing overlapping segments**.
In case of overlapping segments, the priority must be assigned to the leftmost one.
- **Dynamic segments**.
The ability of a frog to eat a moquito is not fixed in time, since its tongue could grow depending on how many moquitoes it reaches.<br>
For this reason, when a frog manages to reach a mosquito, it is also checked if its segment overlaps one other frog and if it is the case, the last frog will be deleted from the bst.
- **Uneaten mosquitoes**. The moquitoes will be saved into a bst to be checked later on. <br>
When a frog manages to reach a mosquito, there will be also the check upon the bst of uneaten mosquitoes, in case it can now reach one of those.

**Time complexity:** O((n + m) log(n + m)). <br>
**Space complexity:** O(n + m).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_05/frogs.cc)