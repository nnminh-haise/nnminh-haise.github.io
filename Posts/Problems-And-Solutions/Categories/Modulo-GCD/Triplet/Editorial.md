
# Bộ ba | Editorial - Lời giải

> *Tags: Math, Combination, Basic*

## Statement - Đề bài

Cho một dãy $A$ gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n$. Hãy đếm số bộ $3$ số $a_i, a_j, a_k$ sao cho $i \neq j \neq k$ và $(a_i + a_j + a_j) \mid 5$.

***Yêu cầu:*** Đưa ra số lượng bộ $3$ số trong dãy $A$ thỏa mãn tính chất trên.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n \; (1 \le n \le 1000)$.
- Dòng thứ hai gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 1000)$.

### Output - Dữ liệu ra

- Một số duy nhất là số lượng bộ $3$ số thỏa mãn tính chất trên.

---

## Solution - Giải thuật

### Naive solution - Giải thuật ngây thơ

Theo đề bài, ta sẽ đi tìm bộ ba số khác nhau sao cho tổng của chúng chia hết cho $5$. Do đó ta có thể sử dụng $3$ vòng lặp `for` lồng nhau, mỗi vòng `for` sẽ là một giá trị $a_i, a_j, a_k$ tương ứng. Sau đó ta áp điều kiện đề bài vào và đếm số lượng bộ ba thỏa mãn. Lưu ý điều kiện $a_i \neq a_j \neq a_k$.

***Độ phức tạp thời gian:*** $O(n^3)$.

***C++:***

```cpp
#include <iostream>

using namespace std;

int main() {
    int n;
    int ans = 0;
    cin >> n;
    int* a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if ((a[i] + a[j] + a[k]) % 5 == 0) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;

    delete[] a;

    return 0;
}
```

***Python:***

```py
n = int(input())
a = list(map(int, input().split(' ')))

ans = 0

for i in range(0, n - 2):
    for j in range(i + 1, n - 1):
        for k in range(j + 1, n):
            if (a[i] + a[j] + a[k]) % 5 == 0:
                ans += 1

print(ans)
```

### Optimized solution - Giải thuật tối ưu

Khi số lượng phần tử của dãy $A$ đủ lớn thì giải thuật trên sẽ không thể đáp ứng và đưa ra kết quả bài toán trong thời gian yêu cầu.

Ta sẽ lợi dụng một số chi tiết cố định của bài toán để giảm thời gian chạy lại như sau. Ta thấy tổng bộ ba $a_i + a_j + a_k$ phải chia hết cho $5$.

Mặt khác, ta lại có:

- Nếu có ba số $x, y, z \% 5 = 0$ thì $(x + y + z) \% 5 = 0$.
- Nếu có ba số $x \% 5 = 0, y \% 5 = 1, z \% 5 = 4$ thì $(x + y + z) \% 5 = 0$.
- Nếu có ba số $x \% 5 = 0, y \% 5 = 2, z \% 5 = 3$ thì $(x + y + z) \% 5 = 0$.
- Nếu có hai số $x \% 5 = 1$ và $y \% 5 = 3$ thì $(2x + y) \% 5 = 0$.
- Nếu có hai số $x \% 5 = 2$ và $y \% 5 = 1$ thì $(2x + y) \% 5 = 0$.
- Nếu có hai số $x \% 5 = 3$ và $y \% 5 = 4$ thì $(2x + y) \% 5 = 0$.
- Nếu có hai số $x \% 5 = 4$ và $y \% 5 = 2$ thì $(2x + y) \% 5 = 0$.

Gọi $F_i$ là tập các phần tử trong dãy $A$ sao cho $a_j \% 5 = i$ hay nói cách khác $F_i$ là tập các phần tử trong dãy $A$ mà phần dư của nó cho $5$ bằng $i$. Theo tính chất của số dư ta rút ra sẽ có các tập hợp $F_0, F_1, F_2, F_3, F_4$. Dựa vào tính chất vừa nêu ở trên cùng với $5$ tập hợp này ta dùng công thức tổ hợp để tính ra số bộ $3$ thỏa mãn yêu cầu đề bài.

***Độ phức tạp thời gian:*** $O(n)$.

***C++:***

```cpp
#include <iostream>

using namespace std;

unsigned long long f[5];
unsigned long long ans = 0;

unsigned long long combination(unsigned long long n, unsigned long long k) {
    if (k == 1) {
        return n;
    }
    else if (k == 2) {
        return n * (n - 1) / 2;
    }
    return n * (n - 1) * (n - 2) / 6;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        ++f[val % 5];
    }

    ans += combination(f[0], 3);
    ans += combination(f[4], 2) * combination(f[2], 1);
    ans += combination(f[3], 2) * combination(f[4], 1);
    ans += combination(f[2], 2) * combination(f[1], 1);
    ans += combination(f[1], 2) * combination(f[3], 1);
    ans += f[0] * f[4] * f[1];
    ans += f[0] * f[2] * f[3];

    cout << ans << endl;

    return 0;
}
```

***Python:***

```py
def combination(n, k): # Hàm tính tổ hợp chập k của n.
    if k == 1:
        return n
    elif k == 2:
        return n * (n - 1) // 2
    else:
        return n * (n - 1) * (n - 2) // 6


n = int(input())
a = list(map(int, input().split(' ')))

f = [0 for i in range(0, 5)]
for x in a:
    f[x % 5] += 1

ans = combination(f[0], 3)
ans += combination(f[4], 2) * combination(f[2], 1)
ans += combination(f[3], 2) * combination(f[4], 1)
ans += combination(f[2], 2) * combination(f[1], 1)
ans += combination(f[1], 2) * combination(f[3], 1)
ans += combination(f[0], 1) * combination(f[1], 1) * combination(f[4], 1);
ans += combination(f[0], 1) * combination(f[2], 1) * combination(f[3], 1);

print(ans)
```