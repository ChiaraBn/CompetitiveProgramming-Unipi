## Description of the problems

###### [Update the array](https://www.spoj.com/problems/UPDATEIT/)

Starting from an array A[n] of integers, initilizated at 0, it is possible to solve efficiently this problem using a temporary vector B, which collects the results of the updates. <br>
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
The idea is add **+val** at the initial position of every query and then subtract **-val** at the next position after the final one.<br>
In this way, the array A is used for the **prefix sum** upon the temporary vector B, in order to garantee that the answer to the i-th query would just be accessing to A[i].

**Time complexity:** θ((u+q) log n) <br>
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_08/update.cc)