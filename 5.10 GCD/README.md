<h1>5.10 Greatest Common Divisior</h1>

**INFORMATION/COMMENTS**

Algorithm is based on a well known theorem/lemma called "Euclid". Basically gcd(a,b) = gcd(a-b,b) is what Euclid states, and I used a recursive algorithm to iterate until one of the numbers is either zero or 1. Having a or b equal to zero is sufficient, but adding more base cases will eliminate unnecessary computations. Also its good to check if the numbers are negative or no.

More about [Euclid's Lemma] ( https://proofwiki.org/wiki/Euclid's_Lemma )
More about [Euclidean Algorithm] ( https://en.wikipedia.org/wiki/Euclidean_algorithm)

**BOOK SOLUTIONS**

Book approach is mostly same, but it reduces the number of computations significantly by checking if the numbers are even or odd. This is done easily by checking the last bit of the numbers. Later, division by two is simply done by shifting the integers left. 
 
pg 179 for more information
