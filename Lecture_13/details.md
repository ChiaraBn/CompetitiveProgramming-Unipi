## Description of the problems

###### [Powerful Array](https://codeforces.com/contest/86/problem/D)

This problem cannot be solved by using `Segment Tree`, but instead one must choose the `Mo's algorithm`, which is an offline approach to solve problems in `θ(sqrt(n))` time. <br>
The queries must be divided into sqrt(n) blocks, and inside each blocks they are sorted by ending values.<br>
Then, using a vector of frequencies for the remapped input values, that will always reflect the range `[cl, cr]`, it is possible to compute the power of each subarrays.

**Time complexity:** θ(t log t + (n + t) * sqrt(n)). <br>
**Space complexity:** θ(n + t).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_13/poweful_array.cc)


###### [Tree and Queries](https://codeforces.com/contest/375/problem/D)

Since the queries do not change the values inside the intervals, it is possible to solve this problem using the `Mo's algorithm.`<br>
First it is necessary to compute a DFS visit of the graph, in order to take the endpoints of the queries themselves; then, using two `frequency vectors` we are going to keep track of the colors of the nodes.<br>
The first vector stores the frequency of the elements, meanwhile the second one stores the frequency of the colors. <br>

**Time complexity:** θ((n+m) * sqrt(n)). <br>
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_13/tree.cc)