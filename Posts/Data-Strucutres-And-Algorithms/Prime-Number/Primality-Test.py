import math


def is_prime(x : int):
    if x <= 1:
        return False
    
    if x == 2 or x == 3:
        return True
    
    if x % 2 == 0:
        return False
    
    for i in range(3, math.ceil(math.sqrt(x)) + 1, 2):
        if x % i == 0:
            return False
    
    return True



p = 11
print(is_prime(p))