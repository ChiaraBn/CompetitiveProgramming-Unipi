## Description of the problems

###### [Maximum path sum](https://practice.geeksforgeeks.org/problems/maximum-path-sum/1)

The solution computes a **post-order** visit of the tree, meanwhile keeping track of the maximum sum seen so far.
Once the visit of the tree is done, it computes the sum going back up through the nodes.

**Time complexity:** O(n).
**Space complexity:** O(Height of the tree).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_06/maxPathSum.cc)


###### [Longest k-good segment](https://codeforces.com/contest/616/problem/D?locale=en)

This problem could be solved using the **two pointers trick** and an hash table to keep track of the occurrences of the elements.
Starting at the first index of the array, with both of the pointers, it has to be scanned just once and, if one element has already been seen, then it increases its counter in the hash table.
Otherwise it increases the number of the **distinct** element seen so far, thus the size of the map.
If this number is bigger than **k**, it means that the lenght of the segment must be reduced: the left index increases and the occurrences of it decrease.

**Time complexity:** θ(n).
**Space complexity:** O(n), the size of the hash table.

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_06/longestSegment.cc)