## Description of the problems

###### [Subset sum](https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1)

The first thing that has to be checked is whatever the overall sum is divisible by 2. <br>
Then, using a **boolean matrix b**, it is possible to keep track of every subsequence seen so far, and construct the result.<br>
A generic entry `b[i][j]` is true if there's a subsequence, up until j-1, that equals to i, because it would mean that is possible to sum up until there. <br>
The final result will be stored in the last entry of b, which is `b[sum/2][n]`.

**Time complexity:** O(n * S), where S is the sum of elements. <br>
**Space complexity:** O(n * S).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_16/subset_sum.cc)


###### [0/1 Knapsack](https://www.spoj.com/problems/KNAPSACK/)

This problem is possible to solve by using **dynamic progamming** and have a matrix `b[C+1][n+1]` which stores the results obtained so far.<br>
For each item, the solution has to compute the maximum between the overall value of adding the item, and the value obtained by ignoring it. <br>
The final result will end up in the last position of the matrix, in `b[C][n]`, where C is the maximum capacity of the knapsack.

**Time complexity:** Θ(n * C), where C is the max capacity. <br>
**Space complexity:** O(n * C).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_16/knapsack.cc)