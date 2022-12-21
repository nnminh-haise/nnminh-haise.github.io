
# Cộng chuỗi | Editorial - Lời giải

> *Tags: string, basic*

## Statement - Đề bài

Cho hai chuỗi $s_1$ và $s_2$ có độ dài không quá $1000$ phần tử.

***Yêu cầu:*** đưa ra chuỗi $s = s_1 + s_2$.

### Input - Dữ liệu vào

- Gồm hai dòng, dòng đầu tiên là chuỗi $s_1$ và dòng thứ hai là chuỗi $s_2$.

### Output - Dữ liệu ra

- Một dòng duy nhất là chuỗi $s$.

---

## Solution - Giải thuật

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 + s2 << endl;

    return 0;
}
```

***Python:***

```py
s1 = input()
s2 = input()

print(s1 + s2)
```