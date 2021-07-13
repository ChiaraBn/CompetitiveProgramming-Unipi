## Description of the problems

###### [Triplets](https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text14022018.pdf)

The `θ(n log n) solution` for this problem requires two `Fenwick Trees`, respectively one for storing the elements that are smaller than the one scanned, and the other one for storing the values that are larger. <br>
The answer will be the sum of the products of the elements in the same positions in the two trees. <br>
This trick is possible due to the fact that the input array stores only values that are smaller than n.

**Time complexity:** θ(n log n). <br>
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_12/triplets.cc)


###### [Smaller Values](https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text14012019.pdf)

The `O((n+m) sqrt(n) * log n)` solution requires the combination of the `Mo's algorithm` and the use of a `Fenwick Tree` to keep track of the counting of the values. <br>
Since each element in the input array is smaller than n, we scan through the queries and for each one of them we add or subtract 1 to `v[idx]`, depending on the index is previous or following the range of the query. <br>
The solution of the i-th query is the prefix sum up to `q[i].x`.

**Time complexity:** O((n+m) sqrt(n) * log n). <br>
**Space complexity:** O(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_12/values.cc)