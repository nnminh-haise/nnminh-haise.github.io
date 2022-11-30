n = int(input())
a = list(map(int, input().split(' ')))

f = {}

for item in a:
    f[str(item)] = 1

for i in range(0, 1000001):
    if f.get(str(i)) == None:
        print(i)
        break
