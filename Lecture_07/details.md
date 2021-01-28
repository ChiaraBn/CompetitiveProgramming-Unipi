## Description of the problems

###### [Ilya and Queries](https://codeforces.com/problemset/problem/313/B?locale=en)

This solution uses a support **vector** count, in order to keep track of the sum of the elements that are equal to their successor: count[i] would be equal to 1 only in the case that s[i] = s[i-1], where s[] is the initial string.<br>
This problem is an example of using the **range sum** to solve a **static prefix sum** problem, so the answer to the queries just takes constant time.

**Time complexity:** θ(n+q), q = #queries <br>
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_07/ilya.cc)


###### [Number of ways](https://codeforces.com/problemset/problem/466/C?locale=en)

This problem requires to split an array A[n] of integers into 3 parts with the same sum.<br>
The first control to perform is whatever the overall sum of the elements would be divisible by 3.<br>
In this case, using a temporary vector B, it is possible to keep track of the positions in which the **prefix sum** of the elements of the array, starting from the end, is equal to 1/3 of the overall sum.<br>
Then, the array A is scanned again to compute the sum of the prefixes and, whenever the result would be equal to 1/3 of the sum, it will update the counter for the ways for splitting.<br>

**Time complexity:** θ(n).<br>
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_07/numberOfWays.cc)


###### [Little girl and maximum sum](https://codeforces.com/problemset/problem/276/C?locale=en)

The idea behind this problem is to compute a **vector** of **frequencies**, that is the number of times in which an element appears into the interval of a query.<br>
This is performed using two vectors: the vector B keeps track of the queries, meanwhile the vector P is the **prefix sum** over B, which results into the actual frequencies.<br>
Then, the starting array and the frequencies' one are sorted in an increaing order, to maximize the result of the queries.<br>
Finally, to solve problem it is enough to multiply each element for its frequency and sum all the results.

**Time complexity:** θ(n log n).<br>
**Space complexity:** θ(n+q).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_07/littleGirl.cc)