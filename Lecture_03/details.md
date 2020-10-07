## Description of the problems

###### [Inversion count](https://www.spoj.com/problems/INVCNT/)

In order to solve this problem, on the input vector is applied the sorting algorithm of **merge sort**, which implements the approach divide et solve.
Basically, the normal version of merge sort is modified by adding a counter during the merge phase.
Since the merge function unites the subarrays previously divided, it also compares each item so the number of comparisons will be the number of inversions, when the two numbers are not in order.

**Time complexity:** θ(n log n) comparisons.
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_03/inversionCount.cc)


###### [The monkey and the oiled bamboo](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3183)

The input vector must be scanned, starting from the end, in order to find the maximum difference between two consecutive rungs.
Note that if two rungs are equal, the minimum strength must be the difference plus one, since it decreases afterwards.

**Time complexity:** θ(n).
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_03/monkey.cc)