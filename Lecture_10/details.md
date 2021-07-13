## Description of the problems

###### [Nested Segments](https://codeforces.com/problemset/problem/652/D?locale=en)

This problem requires the use of a `Segment Tree` to keep the information about the endpoints of the segments.<br>
First, it is necessary to remap the values of the segments into a single vector and sort them by starting points.<br>
Then, using the segment tree, one must scan the input vector and add one at the position of each ending value.<br>
The result would be the sum of elements between the endpoints of each segment.

**Time complexity:** θ(n log n). <br>
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_10/nested.cc)