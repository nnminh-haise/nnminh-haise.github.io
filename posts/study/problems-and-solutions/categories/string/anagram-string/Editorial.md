
# Chuỗi anagram | Editorial - Lời giải

> *Tags: stirng, basic*

## Statement - Đề bài

Chuỗi anagram là chuỗi được tạo ra bằng việc sắp xếp lại thứ tự của các chuỗi khác. Cho hai chuỗi $s$ và $t$ có độ dài không quá $5 \times 10^4$ phần tử gồm các kí tự là chữ cái in thường trong bảng chữ cái tiếng anh.

Ví dụ: `s = abc` và `t = bac` thì hai chuỗi `s` và `t` là hai chuỗi anagram.

***Yêu cầu:*** Cho biết hai chuỗi $s$ và $t$ có phải là hai chuỗi anagram hay không. 

### Input - Dữ liệu vào

- Gồm hai dòng, dòng đầu tiên là chuỗi $s$, dòng thứ hai là chuỗi $t$.

### Output - Dữ liệu ra

- Nếu hai chuỗi $s$ và $t$ là hai chuỗi anagram của nhau thì in `yes`, ngược lại in `no`.

---

## Solution - Giải thuật



***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length())
        return false;

    vector <unsigned int> f(26, 0);
    for (int i = 0; i < s.length(); ++i) {
        ++f[s[i] - 'a'];
        --f[t[i] - 'a'];
    }

    for (int i = 0; i < s.length(); ++i)
        if (f[s[i] - 'a'] != 0)
            return false;

    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << (isAnagram(s, t) ? "yes\n" : "no\n");

    return 0;
}
```

***Python:***

```py
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        f = [0] * 26
        g = [0] * 26
        for i in s:
            f[ord(i) - 97] += 1
        for i in t:
            g[ord(i) - 97] += 1
        if f==g:
            return True
        else:
            return False
```
