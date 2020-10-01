
## Description of the problems

###### [Leaders in un array](https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0)

In order to implement this problem, it was necessary to use a dynamic data structure such as a **vector**.
After the user has filled the array, it just takes _linear time_ to produce in output all the **leaders**.

```
void leaders (std:: vector<int> const& array) {
    std:: vector<int> res;
    res.reserve(array.size());
    int max = array.back();


    for (int i = array.size()- 1; i >= 0; i--) {
        if (array[i] >= max) {
            max = array[i];
            res.push_back(max);
        }
    }
}
```

This function keeps track of the maximum seen so far, starting from the end of the vector, and it compares it to the next element to see.

**Time complexity:** θ(n).
**Space complexity:** θ(n), the resulting vector.

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_01/leadersInArray.cc)


###### [Kadane's algorithm](https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0)

Taking a **vector** as input, it takes _linear time_ to keep track of the intermediate sums, calcolated so far.

```
void maximum_sum (std:: vector<int> const& array) {
    int sum = array.front();
    int max = sum;

    for (int i = 1; i < array.size(); i++) {
        if (sum > 0) {
            sum = sum + array[i];
        }
        else {
            sum = array[i];
        }

        if (sum > max) {
            max = sum;
        }        
    }
    std:: cout << max << std:: endl;
}
```

This solution keeps track of the intermediate sum, taking to the account the fact that if it's negative, it has to start from the beginning, in the position _i_, which is the one currently being scanned.

**Time complexity:** θ(n).
**Space complexity:** constant.

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_01/kadane.cc)


###### [Missing number](https://practice.geeksforgeeks.org/problems/missing-number-in-array/0)

In order to find the missing element within an array, it must be compared the total sum of the elements with the sum that would come off if no element was missing.
The correct sum would be:  

```
tot_sum = n * (n+1) / 2;
```
The difference is the missing element.

**Time complexity:** θ(n).
**Space complexity:** constant.

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_01/missingNumber.cc)


###### [Trapping rain water](https://practice.geeksforgeeks.org/problems/trapping-rain-water/0)

With the aid of two indexes, it's possibile to scan the given array, one starting from the beginning and one starting from the end.
During this loop it keeps track, with a counter, the level of "blank" spaces between the heights of the components, which will be the level of the trapped water.
The counter starts from the heightest element and goes on, keep score of the maximum.

**Time complexity:** θ(n).
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_01/trappingWater.cc)


###### [Sliding window maximum](http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0)

The solution presented requires a **deque**, which is a double ended queue with one pointer to the front and one to the back of the queue.
Using this data structure, it's possible to scan the array and keep track of the maximum in each subarray.
For each iteration, it removes from the head each element whose position is not in the range `< i - k `.
Then adds the new element in the back, while removing also from the back each element smaller than the new one.
The maximum in each subarray is in the head of the queue.

**Time complexity:** θ(n), numbers of comparisons.
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_01/slidingWindow.cc)