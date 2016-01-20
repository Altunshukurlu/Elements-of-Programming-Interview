<h1>6.05 0 mod N Problem </h1>

**SOLUTION/COMMENTS**

I have seen this problem in high school during preparations for Math Olympiads. Basically if you make a new array 
a[0], 
a[0]+a[1]. 
... 
a[0]+a[1]+ ... a[n-1],
We will get 'n' numbers. Assume that one of that has a remainder 0 when divided by n, then problem is solved. Assume none of them are divisible by n, then according to pigeonhole principle there is going to be 2 of them such that give same remainder when divided by n. Take their difference and that subset of array will be our solution. 

The difference between mathematical/abstract version of this problem here is that, we HAVE to find that subset. In order to do that we keep a table (flag array) which represents remainders when divided by n. For example, table[h] = -1 means that remainder h has not been found in any of the sums yet. table[h] = j means that remainder h was found in sum a[0]+...a[j]. We constantly check if table for current element is -1 or not before populating it. When found a duplicate, we get our answer! 


pg 184 for more information
