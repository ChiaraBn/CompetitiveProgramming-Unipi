## Description of the problems

###### [Edit Distance](https://practice.geeksforgeeks.org/problems/edit-distance3702/1)

In order to solve this problem using the **dynamic programming**, it is necessary to use a supporting matrix `ed[n+1][m+1]`, that stores the **edit distance** computed so far. <br>
Scanning the two strings, the general cell of the matrix will be filled as follow: <br>

```
ed[i][j] = {
    i                   , if j == 0
    j                   , if i == 0
    ed [i-1][j-1]       , if s1[i-1] == s2[j-1]

    1+ min(ed[i - 1][j - 1]    // Replace
           ed[i][j - 1],       // Insert
           ed[i - 1][j],       // Remove
        );  
}        
```
The final result will be computed into the last cell of the matrix, which is `ed[n][m]`.<br>

**Time complexity:** O(n * m), where n is the size of the first string and m is the size of the second one. <br>
**Space complexity:** O(n * m).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_18/edit_distance.cc)


###### [Vertex Cover](https://www.spoj.com/problems/PT07X/)

The idea behind this problem is to have a recursive method through all the nodes: given a node, it can be part of the **vertex cover** or not. <br>
In case it is part of it, then it covers all of its children's edges, so it must be calculated the recursive result from left to right. <br>
If the node is not part of the vertex cover then all of its children must be part of it.

**Time complexity:** θ(n) <br>
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_18/vertex_cover.cc)


###### [Longest Palindromic Subsequence](https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0)

In order to find the **longest palindromic subsequence**, given a string, it must be computed the **longest common subsequence** between the input string and its reverse. <br>
Therefore given a string, its reverse is as follow: <br>

```
reverse(str.begin(), str.end());
```

**Time complexity:** O(n^2) <br>
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_18/lps.cc)