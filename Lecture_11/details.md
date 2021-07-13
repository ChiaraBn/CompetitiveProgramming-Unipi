## Description of the problems

###### [Circular RMQ](https://codeforces.com/problemset/problem/52/C)

This is an example of a Range Minimum Query problem, in which it is necessary to build a `Segment Tree` to keep track of the minimum in each range. <br>
Since we have two possible queries, an update and a rmq, it is also possible to apply the `Lazy Propagation` of the change inside the tree: the actual data structure will be updated only when there is the need to compute the minimum and not before, in order to be more efficient.<br>
The fact that this array is `circular` does not change the computation: this will just solved by invoking twice the functions, first within the range `[right, n-1]` and then `[0, left]`.

**Time complexity:** O(n log n). <br>
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_11/rmq.cc)