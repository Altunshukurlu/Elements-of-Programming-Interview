<h1>5.4 Closest integer with the same weight</h1>

**COMMENTS**

Fairly simple problem. Closest y to x will be the same binary with the first different bits in x switched. If weight is 0 or 64, x will not have any different consecutive bits, therefore weight must be between 0 and 64. Once the place of first consecutive bits is found, swapping them is enough to find y. Refer to 5.2 for swapping. Time complexity is O(n) where n is the width of our x. 

Brute force approach might to be to compute weights of all integers x-1, x+1, x=2, x+2 and etc, and stop at the first one which has same weight as x. And that would be our y. But this is a very inefficient way, since if x is 2^30 then this algorithm would have to compute weights for over one billion integers. 



**BOOK SOLUTIONS**

1. Same as stated above

pg 174 for more information
