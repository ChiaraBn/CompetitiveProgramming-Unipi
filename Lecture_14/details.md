## Description of the problems

###### [Longest common subsequence](https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1)

This problem is an example of **dynamic programming**, in which it is possible to find the solution by dividing the problem into multiple sub problems.<br>
Giving two sequences, the common subsequence it is computed by scanning both of them and keeping track of the differences between each element, storing them into a **matrix** c. <br>

```
c[i][j] = {
            0,                          if i = 0 or j = 0,
            1 + c[i-1][j-1]             if s1[i] = s2[j],
            max(c[i,j-1], c[i-1][j])    ow
          }

```
The result will be the bottom right element of the matrix, at c[n][m].

**Time complexity:** O(n * m), n is the length of the first sequence and m is the length of the second one. <br>
**Space complexity:** O(n*m).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_14/lcs.cc)