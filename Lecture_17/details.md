## Description of the problems

###### [Longest Increasing Subsequence](https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1)

In order to solve this problem in `O(n log n)` time, using the **dynamic programming** approach, it is necessary to use a supporting vector **lis**, which stores the longest increasing subsequence during the scan of the input array. <br>
For each new element of the input array `A[]`, there are 3 possible cases: <br>
- A[i] is the smaller so far, so it means that a new sequence must start from it. <br>
The length stored returns to 1, since we have to start a new sequence.<br>
- A[i] is the largest element so far, so it is inserted into the **lis** vector and the length is increased too. <br>
- A[i] is an element in between: in this case the algorithm must find the **lower bound** of A[i] and put it into the sequence. <br>

**Time complexity:** O(n log n). <br>
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_17/lis.cc)


###### [Longest Bitonic Subsequence](https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1)

This problem is an example of using the calculation of the **longest increasing subsequence**, into different variants.<br>
In order to solve this, we use two supporting vectors: <br>
- `lis[i]`, which stores the longest incresing subsequence, from left to right, ending in i <br>
- `lds[i]`, which stores the longest decreasing subsequence, from right to left, starting in i <br>

Then, the two solutions must be combined in order to find the **longest bitonic subsequence**: for each element, `lbs[i] = lis[i] + lds[i] -1`.<br>
Finally, it returns the **maximum** element in the calculated vector.

**Time complexity:** O(n^2) <br>
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_17/lbs.cc)