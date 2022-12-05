
# GCD & LCM | Editorial - Lời giải

> *Tags: Modulo, GCD, Math, Basic*

## Statement - Đề bài

Cho hai số nguyên dương $a$ và $b$.

***Yêu cầu:*** Tìm ước chung lớn nhất và bội chung nhỏ nhất của $a$ và $b$.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $q \; (1 \le q \le 1000)$ - số truy vấn cần trả lời. Mỗi truy vấn sẽ gồm hai số nguyên dương $a_i$ và $b_i$.
- $q$ dòng tiếp theo, mỗi dòng là hai số $a_i, b_i \; (1 \le a_i, b_i \le 10^6)$ ứng với mỗi truy vấn.

### Output - Dữ liệu ra

- Gồm $q$ dòng, mỗi dòng gồm hai số lần lượt là $\gcd(a_i, b_i)$ và $\text{lcm}(a_i, b_i)$ tương ứng với truy vấn.

---

## Solution - Giải thuật

Đây là bài toán cơ bản áp dụng giải thuật tìm ước chung lớn nhất và bội chung nhỏ nhất của hai số nguyên dương. Lưu ý về độ lớn của bội chung nhỏ nhất khi thực hiện tính toán.

***C++:***

```cpp
#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    return (b ? gcd(b, a % b) : a);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main() {
	int queries;
	cin >> queries;
	while (queries--) {
        long long a, b;
        cin >> a >> b;
        cout << gcd(a, b) << " " << lcm(a, b) << endl;
	}
	return 0;
}
```

***Python:***

```py
def gcd(a, b):
    if b == 0:
        return a

    return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)


queries = int(input())

while queries:
    queries -= 1
    
    a, b = list(map(int, input().split(' ')))
    print(gcd(a, b), lcm(a, b))
```
