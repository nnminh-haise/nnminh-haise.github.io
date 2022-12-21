
# So sánh chuỗi | Editorial - Lời giải

> *Tags: Function, basic, string*

## Statement - Đề bài

***Yêu cầu:*** Cho hai chuỗi $s$ và $p$ có độ dài không quá $1000$ phần tử là các kí tự trong bảng chữ cái tiếng anh in thường. Viết hàm so sánh hai chuỗi. **Lưu ý:** vì mục đích luyện tập nên không được sử dụng hàm có sẵn.

### Input - Dữ liệu vào

- Dòng thứ nhất là chuỗi $s$.
- Dòng thứ hai là chuỗi $p$.

### Output - Dữ liệu ra

- Dữ liệu ra sẽ là một trong $3$ giá trị sau:
    - Hàm trả về $-1$ nếu $s$ bé hơn $p$.
    - Hàm trả về $0$ nếu $s$ bằng $p$.
    - Hàm trả về $1$ nếu $s$ lớn hơn $p$.

---

## Solution - Giải thuật



***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int compareString(string s, string p) {
    if (s.length() < p.length()) {
        return -1;
    }
    if (s.length() > p.length()) {
        return 1;
    }

    int i = 0, n = s.length();
    while (i < n) {
        if (s[i] < p[i]) {
            return -1;
        }
        else if (s[i] > p[i]) {
            return 1;
        }
        ++i;
    }
    return 0;
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << compareString(s, p) << endl;

    return 0;
}
```
