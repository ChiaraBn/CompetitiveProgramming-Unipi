## Description of the problems

###### [Update the array](https://www.spoj.com/problems/UPDATEIT/)

Starting from an array A[n] of integers, initilizated at 0, it is possible to solve efficiently by transforming it into a **Fenwick Tree**. <br>
This is an implicit data structure which supports queries such as: <br>
- `sum(i)` : which is the static prefix sum up until the position `i`.
- `add(i, val)` : which is the update of the element in the position `i` by adding the value `val`.

Each **update** is formed upon a structure as follow:

```
struct update {
    int l;
    int r;
    int val;

    update (int left, int right, int val) : 
        l{left}, 
        r{right}, 
        val{val} 
        {}
};
```
The idea is to add `+val` at the initial position of every query, given by `l`,  and then subtract `-val` at the next position given by `r`. <br>
To answer the queries it is enough to compute the sum up until the position indicated by the query itself.

**Time complexity:** θ((u+q) log n) <br>
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_08/update.cc)