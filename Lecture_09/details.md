## Description of the problems

###### [Nested segments](https://codeforces.com/problemset/problem/652/D?locale=en)

In order to solve this problem it is necessary to have two supporting structures: one `Fenwick tree`, to keep track of the sum of the elements, and a vector for the results. <br>
First, the endpoints of the segments are sorted by starting value and they are mapped into a vector whose size then becomes 2*n. <br>
Then, using the **Fenwick tree** we scan the endpoints and add 1 in correspondence of the right endpoint of the segments. <br>
At the left endpoint of the segment, there will be an adding of -1 to the value. <br>
The resulting vector will cointain the sum of the segments up unitl each positions.

**Time complexity:** θ(n log n) <br>
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_09/nested_segment.cc)


###### [Pashmak and Parmida's problem](https://codeforces.com/problemset/problem/459/D?locale=en)

Given an input sequence of integers, this problem is mainly focused on calculating the **frequencies** of its elements. <br>
More in detail, the number of indexes such as `f(1, i, a_i) > f(i, n, a_j)`. <br>
The first part of the equation is simple to compute using a `map` which keeps track of the occurrencies of the elements. <br>
For the comparisons it has been used a `Fenwick tree`, created from the end of the input sequence, which keeps track of the frequencies that satify the equation.<br>
The final result is a query to the **ft** in the form of `ft.sum(f[i]-1)`, which represents the total frequence of the i-th element.

**Time complexity:** θ(n log n) <br>
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_09/pashmak.cc)