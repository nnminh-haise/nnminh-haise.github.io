
# Xóa phần tử | Editorial - Lời giải

> *Tags: Modulo, GCD, Basic, Math*

## Statement - Đề bài

Cho một dãy $A$ có $n$ phần tử là các số nguyên dương $a_1, a_2, a_3 \ldots, a_n$. Bạn có thể xóa đi một số phần tử (hoặc không xóa bất cứ phần tử nào) sao cho ước chung lớn nhất của dãy $A$ bằng $1$.

***Yêu cầu:*** Hãy đếm số lượng phần tử cần xóa ít nhất sao cho ước chung lớn nhất của cả dãy $A$ bằng $1$.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $q \; (1 \le q \le 100)$ - số truy vấn cần trả lời. Mỗi truy vấn có dạng như sau:

    - Dòng đầu tiên là số nguyên dương $n \; (1 \le n \le 10^3)$ - số lượng phần tử của dãy $A$.
    - Dòng thứ hai gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 5 \cdot 10^4)$ như đã mô tả.

### Output - Dữ liệu ra

- Gồm $q$ dòng, dòng thứ $i$ là câu trả lời cho truy vấn thứ $i$ tương ứng.

---

## Solution - Giải thuật

Dựa trên tính chất của ước chung lớn nhất của hai số nguyên $a$ và $b$ ta có công thức:

$$\gcd(a, b) \le \min(a, b)$$

Dựa trên yêu cầu đề bài là tìm ra số lượng phần tử ít nhất cần phải xóa khỏi dãy $A$ ta thấy rằng khi số lượng phần tử trong dãy $A$ càng nhiều thì ước chung lớn nhất của dãy $A$ càng nhỏ. Vì khi số lượng phần tử trong dãy $A$ bị xóa bớt đi thì $\gcd(A)$ sẽ tăng lên. Do đó để tối thiểu hóa số lượng phần tử cần xóa đi thì tốt nhất chính là không xóa phần tử nào.

Nếu ban đầu $\gcd(A) = 1$ thì ta sẽ không xóa phần tử nào. Ngược lại nếu không bằng $1$ thì ta sẽ in $-1$.

***Độ phức tạp thời gian:*** $O(n)$.

***C++:***

```cpp
#include <iostream>

using namespace std;

const int MAX_N = 1e3 + 7;

int queries, n, a[MAX_N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    cin >> queries;

    while (queries--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int p = a[0];
        for (int i = 1; i < n; ++i) {
            p = gcd(p, a[i]);
        }

        if (p == 1) {
            cout << 0 << "\n";
        }
        else {
            cout << -1 << "\n";
        }
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


queries = int(input())

while queries:
    queries -= 1
    
    n = int(input())
    a = list(map(int, input().split(' ')))
    
    p = a[0]
    
    for i in range(1, n):
        p = gcd(p, a[i])
    
    if p == 1:
        print(0)
    else:
        print(-1)
```
