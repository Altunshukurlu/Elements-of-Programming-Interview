<h1>5.12 Checking If Rectangles Intersect </h1>

**INFORMATION/COMMENTS**

My solution consists of couple steps. First we check if the rectangles intersect at all. Assume they intersect. One observation is that the x and y coordinates of these rectangles are independent, so we can just assume we are looking at parallel lines intersection problem and solve it. WLOG we can apply the same about the lines parallel to x and y axis. There are 2 cases: when part of one line is same as the other line but the rest is extending out AND when one line is inside the other line. Couple if statements are enough to check this. 

More about [Rectangle Intersection] (http://www.geeksforgeeks.org/find-two-rectangles-overlap/)

**BOOK SOLUTIONS**

Book solution is same, in fact this problem doesn't have many various solutions. However, the code is much shorter. Its observed that no matter which of my cases are appearing, the x coordinate of the intersected rectangle will always be max(R.x, S.x) (same for y). The height and width on the other hand are just simply written by a shorter code that combines all of my if statements. 

pg 184 for more information
