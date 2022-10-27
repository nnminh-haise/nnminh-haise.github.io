
# Chia hết | Editorial - Lời giải

> *Tags: Math, Modulo, Basic*

## Statement - Đề bài

Cho một dãy $A$ gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots a_n$. Với mỗi số $a_i$ hãy kiểm tra số đó chia hết cho $7$ hoặc $13$ hay không.

- Nếu $a_i$ chia hết cho $7$ in `mod 7`.
- Nếu $a_i$ chia hết cho $13$ in `mod 13`.
- Nếu $a_i$ chia hết cho cả $7$ và $13$ in `both`.
- Nếu $a_i$ không chia hết cho $7$ hoặc $13$ in `none`.

***Yêu cầu:*** Với mỗi phần tử $a_i$ hãy in ra câu trả lời tương ứng.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n \; (1 \le n \le 1000)$.
- Dòng thứ hai gồm $n$ số nguyên $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 1000)$.

### Output - Dữ liệu ra

- Gồm $n$ dòng, mỗi dòng là đầu ra tương ứng với phần tử $a_i$.

---

## Solution - Giải thuật

Ta sẽ duyệt tuần tự qua các phần tử trong dãy đã cho và kiểm tra từng điều kiện mà đề đã yêu cầu.

***C++:***

```cpp
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        if (val % 7 == 0 && val % 13 == 0) {
            cout << "both\n";
        }
        else if (val % 7 == 0) {
            cout << "mod 7\n";
        }
        else if (val % 13 == 0) {
            cout << "mod 13\n";
        }
        else {
            cout << "none\n";
        }
    }
    return 0;
}
```

***Python:***

```py
n = int(input())
a = list(map(int, input().split(' ')))

for x in a:
    if x % 7 == 0 and x % 13 == 0:
        print("both")
    elif x % 7 == 0:
        print("mod 7")
    elif x % 13 == 0:
        print("mod 13")
    else:
        print("none")
```
