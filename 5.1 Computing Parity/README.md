5.1 Computing Parity 

EXTRA INFORMATION

Signed vs Unsigned 
- Unsigned can hold a larger positive value, and no negative value 
- Unsigned uses the leading bit as a part of the value, signed uses to determine the sign of the number. More common usage is 'twos complement' 
- Signed integers can hold both positive and negative values.

Parity 
- Even if number of 1's is even, odd otherwise

Check for more about computing parity site:http://stackoverflow.com/questions/17350906/computing-the-parity

BOOK SOLUTIONS

1- Brute force: compute each bits parity one-by-one
2- Edited Brute Force: erase LSB in a single operation 
3- Precompute the answer and store it in an array. 

pg 173 for more information