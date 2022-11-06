def sieve():
	n = 2000000

	is_prime = [True for i in range(0, n + 1)]
	primes = list()

	is_prime[0] = is_prime[1] = False
	for i in range(2, n + 1):
		if is_prime[i] == True and i * i <= n:
			for j in range(i * i, n + 1, i):
				is_prime[j] = False
	
	for i in range(1, n + 1):
		if is_prime[i] == True:
			primes.append(i)

	return primes


primes = sieve()
queries = int(input())

while queries:
	queries -= 1
	n = int(input())
	print(primes[n - 1])
	
