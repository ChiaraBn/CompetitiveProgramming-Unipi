## Description of the problems

###### [Next larger element](https://practice.geeksforgeeks.org/problems/next-larger-element/0)

In order to find the next larger element, for each one, it has been used a **deque**, so a double ended queue.
Starting from the end of the array, first it pushes the last element in the front of the queue.
Then this solution compares the new element in the array with each item in the front of the queue, until it finds a bigger one, or the end of it is reached.
The new element it's pushed to the front of the queue and, if a bigger one exists then this will be pushed in the resulting array, otherwise it means that it is the maximum so far, so its result would be -1.

**Time complexity:** θ(n).
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_02/nextLarger.cc)


###### [Towers](http://codeforces.com/problemset/problem/37/A?locale=en)

The following solution scans the input array of different lenghts, to find the distinct elements.
First of all, the vector must be sorted in an increasing order, so the same elements would be contiguous.
Then, with some temporary variables it's possible to keep track of the count of similar numbers, which will be the heights of the towers, meanwhile the diverse ones will be the total number of towers.

**Time complexity:** θ(n).
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_02/towers.cc)


###### [Finding team member](http://codeforces.com/problemset/problem/579/B?locale=en)

For this problem it was necessary to create a customized data structure `team`, composed by two index representing the two people in the team, and another integer representing their strength together.

The input vector of data must be sorted in an decresing order, by strength, so it's possible to create the most powerful couples first.
Then, the solution scans the vector and it associates, for each person, the first team mate available, with the highest strength possible.

**Time complexity:** θ(n).
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_02/teamMember.cc)