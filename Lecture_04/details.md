## Description of the problems

###### [Two types of spells](https://codeforces.com/contest/1398/problem/E?locale=en)

This problem can be solved by using 3 additional structures: one for the input value to be analyzed, one for the `fire spells` and the last one for the `lighting spells`. <br>
It is inserted also a counter to keep track of the values to be doubled. <br>
Then, for each value, it must be checked if the spell is to be added or deleted (`damage > 0` or not).<br>
Finally, we scan the two sets adding the damages of each spell.

**Time complexity:** θ(n log n). <br>
**Space complexity:** θ(n).

The complete [solution.](https://github.com/Claire-gip/CompetitiveProgramming-Unipi/blob/master/Lecture_04/spells.cc)