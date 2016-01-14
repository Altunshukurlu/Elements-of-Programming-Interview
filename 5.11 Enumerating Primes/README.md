<h1>5.11 Enumerating Primes </h1>

**INFORMATION/COMMENTS**

Here is the pseudocode for my algorithm.
ALG Primes(input n)
	init array PRIMES to empty
	init array NUMBERS to [2..n]
	for each x in NUMBERS
		add x to PRIMES
		set y = x
		while y is less than or equal to n 
			remove y from PRIMES
			y -> y + x 
		end while
	end for 
	return PRIMES
	
The logic is simple, extract the prime number from the list, and remove all numbers which are divisible by that number. Since next number in the array won't have any number less than itself that can be divided into, it must be prime. Repeat until list is empty. 
Update: Obviously, this algorithm is called Sieve_of_Eratosthenes

More about [Sieve_of_Eratosthenes] (https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
[Brute Force Algorithm] (http://www.cs.cmu.edu/~scandal/cacm/node8.html)

**BOOK SOLUTIONS**

Book approach is completely different, it implements a 'isPrime' function which checks whether the input is prime or not by checking numbers smaller than sqrt(p). Once it finds a prime number, it marks rest of numbers (divisible by p) marked as not prime (like I did.) 
pg 179 for more information
