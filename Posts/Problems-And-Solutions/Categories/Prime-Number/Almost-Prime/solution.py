def check(x: int):
    if (x < 2):
        return False
    
    counter = 0
    p = 2
    
    while (x > 1):
        divided = False
        
        while (x % p == 0):
            divided = True
            x //= p
        
        p += 1
        
        if (divided == True):
            counter += 1
    
    return counter == 2


n = int(input())
ans = 0

for i in range(1, n + 1):
    if (check(i) == True):
        ans += 1

print(ans)