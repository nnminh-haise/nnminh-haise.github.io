
# Tổng 3 | Editorial - Lời giải

> *Tags: Math, Basic, Function*

## Statement - Đề bài

***Yêu cầu:*** Cho số nguyên dương $n \; (1 \le n \le 10)$, viết hàm tính tổng dưới đây (có thể viết thêm hàm phụ trợ).

$$S = 1 + \dfrac{1}{2!} + \dfrac{1}{3!} + \dfrac{1}{4!} + \ldots + \dfrac{1}{n!}$$

### Input - Dữ liệu vào

- Một số nguyên dương $n$ duy nhất.

### Output - Dữ liệu ra

- Kết quả của tổng $S$ đã cho, làm tròn đến chữ số thứ $3$ sau dấu phẩy thập phân.
---

## Solution - Giải thuật



***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

double factorial(double x) {
    double res = 1;

    for (int i = 1; i <= x; ++i) {
        res *= i;
    }

    return res;
}

double f(int n) {
    double res = 0;
    for (double i = 1; i <= n; ++i) {
        res += 1.0 / factorial(i);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << fixed << setprecision(3) << f(n) << endl;

    return 0;
}
```
