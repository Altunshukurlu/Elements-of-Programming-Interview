<h1>6.01 Dutch National Flag </h1>

**INFORMATION/COMMENTS**

Problem is relatively simple if there is no space constraints. Simply make 3 lists, iterate through the given array and populate our lists based on pivot. Then rewrite original list using temporary lists we built. Space complexity is O(n) for this solution. To reduce the space complexity to O(1) we have to work on the given array. One way of doing this would be to iterate through the array twice. First one, stack up all smaller numbers in the beginning of the array. Second iteration, do the same for larger numbers. However, the time complexity for this solution would be O(n^2). In order to reduce time complexity we can make lists within our array. These lists would be accessed by integers smaller, equal and larger. There will be 4 sub-lists. Bottom list is all numbers smaller that the pivot, Middle list is all numbers equal to the pivot, Unclassified list is all numbers initially, and Top list is all numbers greater than the pivot. We run a loop until all elements of the array are classified. More in the code. 

More about (Dutch national flag) [https://en.wikipedia.org/wiki/Dutch_national_flag_problem]
More about (DNF Solution) [http://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/]

*BOOK SOLUTIONS**

pg 184 for more information
