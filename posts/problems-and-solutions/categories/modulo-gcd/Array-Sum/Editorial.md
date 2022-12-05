
# Tổng dãy | Editorial - Lời giải

> *Tag: Array, Math, Modulo, Basic*

## Statement - Đề bài

Cho một dãy $A$ gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n$ và một số nguyên dương $k$.

***Yêu cầu:*** Tính tổng các phần tử trong dãy và đưa ra kết quả là phần dư của tổng vừa tìm cho $k$.

### Input - Dữ liệu vào

- Dòng đầu tiên gồm hai số nguyên dương $n \; (1 \le n \le 1000)$ và $k \; (1 \le k \le 1000)$.
- Dòng thứ hai gồm $n$ số nguyên $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 1000)$.

### Output - Dữ liệu ra

- Một số nguyên duy nhất là phần dư của phép chia giữa tổng các phần tử trong dãy $A$ với số nguyên dương $k$.

---

## Solution - Giải thuật

### Naive solution - Giải thuật ngây thơ

Sử dụng vòng lặp `for` để tính tổng các phần tử trong dãy $A$ sau đó lấy kết quả vừa tìm được chia lấy dư cho $k$.

***Độ phức tạp thời gian:*** $O(n)$.

***C++:***

```cpp
#include <iostream>

using namespace std;

int n, k, sum = 0;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        sum += val;
    }
    cout << sum % k << endl;
    return 0;
}
```

***Python:***

```py
n, k = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))

s = 0

for x in a:
    s += x

print(s % k)
```

### Optimized solution - Giải thuật tối ưu

Giả sử, dãy $A$ có $n = 10^6$ giá trị $a_1, a_2, a_3, \ldots, a_n$ và $a_i = 10^{18} \forall i \in [1, n]$ thì ta có tổng các phần tử trong dãy sẽ là: $\sum\limits_{i = 1}^{10^6}10^{18} = 10^6 \times 10^{18} = 10^{24}$ là một số rất lớn. Đối với một số ngôn ngữ lập trình không hỗ trợ xử lí số lớn như `C++` thì sẽ không thể sử dụng các kiểu dữ liệu thông thường để lưu trữ giá trị này.

Do đó ta sẽ áp dụng tính chất $(a + b) \% c = (a \% c + b \% c) \% c$ của đồng dư thức để xử lí bài toán. Cụ thể như sau:

- Ta sử dụng vòng lặp `for` để duyệt qua từng phần tử trong dãy, sử dụng một biến `sum` để chứa giá trị tổng, cũng như là kết quả bài toán. Ta sẽ lần lượt cộng dồn `a_i` vào `sum` và công thức cộng dồn như sau: $sum = sum + a[i]$.
- Xét vế phải của công thức cộng dồn, lúc này, ta áp dụng tính chất vừa nêu của đồng dư thức ta được công thức sau: $sum = (sum \% k + a[i] \% k) \% k$. Khi được cộng dồn liên tục ta sẽ được kết quả cần tìm.

Ở lời giải này ta không tập trung vào việc tối ưu hóa thời gian tính tổng mà tập trung vào việc tối ưu hóa bộ nhớ và các tính. Vì số dư không bao giờ lớn hơn số chia nên kết quả bài toán luôn nằm trong khoảng $[0, k - 1]$. Do đó việc xử lí số lớn như giải thuật ngây thơ là không cần thiết.

***Độ phức tạp thời gian:*** $O(n)$.

***C++:***

```cpp
#include <iostream>

using namespace std;

int n, k, sum = 0;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        sum = (sum % k + val % k) % k;
    }
    cout << sum << endl;
    return 0;
}
```

***Python:***

```py
n, k = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))

s = 0

for x in a:
    s = (s % k) + (x % k) % k

print(s)
```
