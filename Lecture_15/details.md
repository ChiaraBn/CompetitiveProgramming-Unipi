## Description of the problems

###### [Minimum numer of jumps](https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1)

Since each element of the array represents the **maximum jump** from there, it is necessary to keep track of the jumps taken so far. <br>
Starting from the beginning of the input array, if `arr[0]` is equal to 0, then it is obvious that it is impossible to reach the end, so we return -1. <br>
Otherwise, `arr[0]` becomes the maximum so far and now it is possible to scan the array: for each value we find the maximum and then decrease the **steps** counter, previously set to `arr[i]`. <br>
If the counter is equal to 0, it means that we need an another jump to continue the scanning.<br>
Once `arr[n-1]` is reached, we return the result computed.

**Time complexity:** O(n)<br>
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_15/min_jumps.cc)