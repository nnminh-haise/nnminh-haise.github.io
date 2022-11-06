import math


def is_prime(n: int):
    if (n < 2):
        return False
    
    if (n == 2 or n == 3):
        return True
    
    if (n % 2 == 0):
        return False
    
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if (n % i == 0):
            return False

    return True


queries = int(input())

while (queries):
    queries -= 1
    
    n = int(input())
    p = 1
    counter = 0
    
    while (counter != n):
        p += 1
        if (is_prime(p) == True):
            counter += 1
    
    print(p)