
# Lũy thừa - POWER | Editorial - Lời giải

> *Tags: Binary Search, Binary Power*

## Statement - Đề bài

> *Đề bài: [Lũy thừa - Power | VNOI](https://oj.vnoi.info/problem/power)*

---

## Solution - Giải thuật

Dựa vào yêu cầu đề bài: **Tìm $k$ lớn nhất** suy ra giá trị $x^k$ sẽ có $x$ nhỏ. Vì khi $x$ càng lớn thì $k$ sẽ càng nhỏ và ngược lại.

> *Vậy giá trị lớn nhất có thể của $k$ là gì?*

Theo giả thuyết, đoạn $[l, r]$ dài nhất sẽ là đoạn $[2, 10^{12}]$. Do vậy $x^k$ sẽ đạt giá trị lớn nhất sẽ là $x^k = 10^{12}$. Kết hợp với lập luận trên, thử các giá trị có thể của $x$ như sau:

- $x = 1 \rightarrow k = 10^{12}$.
- $x = 2 \rightarrow k \approx 40$.
- $x = 3 \rightarrow k \approx 26$.
- $\ldots$.
- $x = 10^{12} \rightarrow k = 1$.

Như vậy, khi xét đến cận phải của đoạn $[2, 10^{12}]$ thì giá trị lớn nhất của $k$ sẽ là $10^{12}$. Song giá trị $x$ tương ứng sẽ là $1$ điều này sẽ chỉ thỏa mãn điều kiện đề bài là $l \le x^k \le r$ nếu $l = r$. Do đó không nên chọn $x = 1$. Vậy có thể chọn giá trị lớn nhất có thể của $k$ là $40$ và giảm dần xuống.

Tại mỗi giá trị của $k$, có thể thực hiện tìm kiếm nhị phân giá trị $x$ như sau:

Với giá trị $k$ đã chọn và đoạn $[l, r]$ cho trước ta có thể suy ra được đoạn giá trị của $x$ là: $[\sqrt[l]{x}, \sqrt[r]{x}]$. Gọi $l = \sqrt[l]{x}, r = \sqrt[r]{x}$. Khi đó sẽ thực hiện tìm kiếm nhị phân giá trị $x$ có thể ở trong đoạn trên. Nếu tồn tại giá trị $x$ thì trả về kết quả bài toán.

Vì giá trị $k$ được giảm dần từ giá trị lớn nhất đến giá trị nhỏ nhất nên luôn đảm bảo giá trị $k$ tìm được là lớn nhất.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

long long binary_search(long long a, long long b) {
    for (long long k = 40; k >= 1; k--) {
        long long left = ceil(pow(a, 1.0 / k)) - 1, right = ceil(pow(b, 1.0 / k)) + 1;
        while (left <= right) {
            long long mid = (right + left) / 2;
            long long res = pow(mid, k);

            if (a <= res and res <= b) {
                return k;
            }
            else if (res < a) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int queries;
    cin >> queries;
    for (int qq = 1; qq <= queries; ++qq) {
        long long l, r;
        cin >> l >> r;
        long long ans = binary_search(l, r);
        cout << "Case #" << qq << ": ";
        cout << ans << "\n";
    }
}
```

***Python:***

```py
import math

def binary_search(a: int, b: int):
    for k in range(41, 0, -1):
        left = math.ceil(math.pow(a, 1.0 / k)) - 1
        right = math.ceil(math.pow(b, 1.0 / k)) + 1
        
        while left <= right:
            mid = (right - left + 1) // 2 + left
            res = math.pow(mid, k);
            
            if a <= res and res <= b:
                return k
            elif res < a:
                left = mid + 1
            else:
                right = mid - 1
    
    return -1


queries = int(input())

for _ in range(1, queries + 1):
    l, r = list(map(int, input().split(' ')))
    res = binary_search(l, r)
    print(f'Case #{_}: {res}')
```