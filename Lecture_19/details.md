## Description of the problems

###### [N meetings in a room](https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1)

This exercise is an example of a **greedy approach** applied to an **activity selection** problem. <br>
The initial values must be sorted by ending time, in an increasing order, to take first the meeting that ends first, and so on. <br>
Then, since the meetings cannot overlap, we scan the vector setting the time limit equal to end of the last meeting chosen.<br>
In this way, a meeting is selected only if its starting time will be after the ending time of its predecessor.

**Time complexity:** O(n * log n) <br>
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_19/Nmeetings.cc)


###### [Magic Numbers](https://codeforces.com/problemset/problem/320/A?locale=en)

In order to ease the resolution of this problem, the input number is saved into a string so it is possible to analyze each character. <br>
Then, with the help of two **boolean variables**, the string is scanned and we keep track of the elements already seen to check whatever the number so far is either 1, 14 or 144.

**Time complexity:** θ(n), where n is the number of digits of the input number. <br>
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_19/numbers.cc)


###### [Wilbur and array](https://codeforces.com/problemset/problem/596/B?locale=en)

The **greedy approach**, in this case, would be not to distribute the change at each step, but to calculate the minimum number of steps needed to update a single cell `i`.<br>
Then, the overall counter is updated by the difference between `b[i]` and `a[i-1]`, because we assume that `a[i]` is already set correctly.

**Time complexity:** θ(n). <br>
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_19/wilbur.cc)


###### [Alternative Thinking](https://codeforces.com/problemset/problem/603/A?locale=en)

The initial sequence is scanned just once, meanwhile keeping track of the **longest alternative subsequence** with a counter. <br>
This value can increase only if it is smaller than the size of the sequence, and it can be raised only of two digits.

**Time complexity:** θ(n). <br>
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_19/thinking.cc)