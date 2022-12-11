
# Lát gạch - LATGACH | Editorial - Lời giải

> *Tags: Dynamic programming, Basic*

## Statement - Đề bài

> *Nguồn: [LATGACH | VNOI](https://oj.vnoi.info/problem/latgach).*

Cho một hình chữ nhật kích thước $2 \times N \; (1 \le N \le 100)$. 

***Yêu cầu:*** Hãy đếm số cách lát các viên gạch nhỏ kích thước $1 \times 2$ và $2 \times 1$ vào hình trên sao cho không có phần nào của các viên gạch nhỏ thừa ra ngoài, cũng không có vùng diện tích nào của hình chữ nhật không được lát.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $q \; (1 \le q \le 100)$ - số lượng truy vấn cần trả lời.
- $q$ dòng tiếp theo, mỗi dòng gồm $1$ số nguyên dương $N$.

### Output - Dữ liệu ra

- Gồm $q$ dòng, mỗi dòng là số cách lát các viên gạch.

---

## Solution - Giải thuật

Với hình chữ nhật diện tích $2 \times N$ thì số cách lát viên gạch sẽ là số fibonacii thứ $n$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

vector < int > toBignum(string s) {
    vector < int > res;

    for (int i = s.length() - 1; i >= 0; --i) {
        res.push_back(s[i] - '0');
    }

    return res;
}

vector < int > toBognum(int n) {
    vector < int > res;

    while (n > 1) {
        res.push_back(n % 10);
        n /= 10;
    }

    return res;
}
    
void balance(vector < int >& a, vector < int >& b) {
    while (a.size() < b.size()) {
        a.push_back(0);
    }
    while (a.size() > b.size()) {
        b.push_back(0);
    }
    return;
}

vector < int > operator + (vector < int > a, vector < int > b) {
    vector < int > res;
    
    balance(a, b);

    int remain = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        int s = a[i] + b[i] + remain;
        res.push_back(s % 10);
        remain = s / 10;
    }

    if (remain) {
        res.push_back(remain);
    }

    return res;
}

ostream& operator<< (ostream& cout, vector < int >& target) {
    for (int i = (int)target.size() - 1; i >= 0; --i) {
        cout << target[i];
    }
    return cout;
}

int main() {
    vector < int >* dp = new vector < int > [101];
    dp[1] = toBignum("1");
    dp[2] = toBignum("2");
    for (int i = 3; i <= 100; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int queries;
    cin >> queries;
    while (queries--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}
```

***Python:***

```py
def prepare():
    dp = [0 for _ in range(101)]
    
    dp[1] = 1
    dp[2] = 2
    for i in range(3, 101):
        dp[i] = dp[i - 1] + dp[i - 2]
    
    return dp

dp = prepare()
queries = int(input())

while queries:
    queries -= 1
    
    n = int(input())
    print(dp[n])
```