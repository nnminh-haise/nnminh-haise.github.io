import math


def sieveOfEratosthenes():
    n = 1000000
    is_prime = [True for i in range(0, n + 1)]
    
    is_prime[0] = is_prime[1] = False
    
    for p in range(2, n + 1):
        if is_prime[p] == True and p * p <= n:
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
    
    for i in range(1, n + 1):
        if is_prime[i] == True:
            print(i)


sieveOfEratosthenes()
