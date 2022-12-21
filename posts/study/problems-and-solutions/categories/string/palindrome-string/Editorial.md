
# Chuỗi đối xứng | Editorial - Lời giải

> *Tags: string, basic, palindrome string*

## Statement - Đề bài

Một chuỗi được gọi là đối xứng nếu chuỗi đọc từ trái sang phải giống với chuỗi đọc từ phải sang trái. Cho chuỗi $s$ có độ dài $n \; (1 \le n \le 1000)$ gồm các kí tự in thường trong bản chữ cái tiếng anh.

***Yêu cầu:*** Kiểm tra xem chuỗi $s$ có phải chuỗi đối xứng hay không?

### Input - Dữ liệu vào

- Một dòng duy nhất là chuỗi $s$.

### Output - Dữ liệu ra

- Nếu chuỗi $s$ đã cho là chuỗi đối xứng in `yes`, ngược lại in `no`.

---

## Solution - Giải thuật

Việc kiểm tra chuỗi đối xứng không khó và có nhiều cách làm.

**Cách 1:** có thể tạo một chuỗi $p$ là chuỗi đảo ngược của $s$ và kiểm tra xem hai chuỗi $s$ và $p$ có giống nhau hay không.

**Cách 2:** giống với cách 1 nhưng thay vì tạo một chuỗi $p$ mới thì gọi $i$ và $j$ lần lượt là chỉ số đầu và chỉ số cuối của chuỗi $s$. Khi đó, vì tính chất đối xứng nên $s[i]$ phải bằng $s[j]$. Do đó, với mọi $i \in [0, \lfloor|s| / 2\rfloor]$ nếu $s[i] != s[|s| - i]$ thì $s$ không phải là chuỗi đối xứng. Ngược lại, nếu không tồn tại bất cứ trường hợp trên thì $s$ là chuỗi đối xứng.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length() - 1;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[n - i]) {
            flag = false;
        }
    }

    cout << (flag ? "yes\n" : "no\n");
    return 0;
}
```

***Python:***

```py
s = input()
n = len(s) - 1
flag = True

for i in range(0, n + 1):
    if s[i] != s[n - i]:
        flag = False
        break

print("yes" if flag else "no")
```
