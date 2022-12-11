
# Số cận nguyên tố | Editorial - Lời giải

> *Tags: Prime number, Math, Basic*

---

## Statement - Đề bài

Số cận nguyên tố là số khi phân tích ra thừa số nguyên tố thì chỉ có đúng hai số nguyên tố khác nhau.

Ví dụ số cận nguyên tố là số $6, 12, 18$ và các số $4, 11$ không phải là số cận nguyên tố.

***Yêu cầu:*** Cho một số nguyên dương $n$, đếm số lượng số cận nguyên tố trong đoạn $[1, n]$.

### Input - Dữ liệu vào

- Một số nguyên dương $n \; (1 \le n \le 3000)$ duy nhất.

### Output - Dữ liệu ra

- Một số nguyên dương $m$ duy nhất là số lượng số cận nguyên tố đếm được trong đoạn $[1, n]$.

---

## Solution - Giải thuật

Mình gợi ý cho cậu một giải thuật đơn giản như sau: cậu sẽ thiết kế một hàm `check()` đơn giản để kiểm tra một số nguyên $x$ bất kì có phải là số cận nguyên tố hay không. Sau đó với hàm `check()` này, cậu sẽ duyệt qua các số $i$ trong đoạn $[1, n]$ và đếm số lượng các số cận nguyên tố.

Vậy, chìa quá của lời giải này là hàm `check()`, mình sẽ hướng dẫn cậu viết hàm `check()` như sau:

- Khởi gán $p = 2$. Chừng nào $x > 1$ thì thực hiện các bước dưới đây.
- Chừng nào $x \mid p$ thì $x \leftarrow x \div p$. Vòng lặp này sẽ dừng lại khi $x \nmid p$.
- Sau mỗi lần lặp, cậu sẽ tăng giá trị $p$ lên $1$ đơn vị. Và cứ thế lặp lại cho đến khi nào $x = 1$.

Sau khi hàm `check()` được hoàn chỉnh, bây giờ việc còn lại chỉ là kiểm tra và đếm các số cận nguyên tố trong đoạn $[1, n]$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

bool check(int x) {
    if (x == 1) {
        return false;
    }

    int counter = 0;
    int p = 2;
    while (x > 1) {
        bool divided = false;
        while (x % p == 0) {
            if (x % p == 0) {
                divided = true;
            }
            x /= p;
        }
        if (divided) {
            ++counter;
        }
        ++p;
    }
    return (counter == 2);
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (check(i)) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
```

***Python:***

```py
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
```
