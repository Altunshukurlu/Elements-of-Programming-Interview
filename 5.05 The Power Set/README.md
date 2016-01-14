<h1>5.5 The Power Set</h1>

**INFORMATION/COMMENTS**

It is known that power set will contain 2^n number of subsets, where n is the size of S. Brute force algorithm would be to iterate through all binary numbers from 0 to size of S and print the corresponding subset. Modified brute force algorithm would be slight more efficient. Instead of going through each bit of the binary number we have, find the most significant bit ( x & !(x-1) ) and print the corresponding element of S, apply until x doesn't have 1's anymore. Recursive solution however is much more efficient, time complexity is O(n*2^n) where n is the size of S. 

**BOOK SOLUTIONS**

1. Book solutions are written in java/C++. Recursion algorithm is pretty similar. 

pg 176 for more information
