
# Apartments | Editorial - Lời giải

> *Tags: Sorting, Searching*

## Statement - Đề bài

> *Nguồn: [Apartments - CSES](https://cses.fi/problemset/task/1084/).*

There are $n$ applicants and $m$ free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.

Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

***Yêu cầu:*** Your task is to distribute the apartments so that as many applicants as possible will get an apartment.

### Input

- The first input line has three integers $n, m$ and $k$: the number of applicants, the number of apartments, and the maximum allowed difference.

- The next line contains $n$ integers $a_1, a_2, \ldots, a_n$: the desired apartment size of each applicant. If the desired size of an applicant is x$,$ he or she will accept any apartment whose size is between $x − k$ and $x + k$.

- The last line contains $m$ integers $b_1, b_2, \ldots, b_m$: the size of each apartment.

### Constraints

- $1 \le n, m \le 2 \cdot 10^5%$.
- $0 \le k \le 10^9$.
- $1 \le a_i, b_i \le 10^9$.

### Output

- Print one integer: the number of applicants who will get an apartment.

---

## Solution - Giải thuật

- Sắp xếp lại hai dãy theo thứ tự tăng dần.
- Gọi $i$ là chỉ số đầu của dãy $a$ và $j$ là chỉ số đầu của dãy $b$.
- Nếu $|a_i - b_j| \le k$ thì có thêm $1$ người chọn được một ngôi nhà vừa ý.
- Ngược lại, nếu $a_i - b_j > k$ thì sẽ tăng $j$ lên $1$ đơn vị để $a_i - b_{j + 1} < a_i - b_j$. Tương tự cho trường hợp $a_i - b_j < k$ thì tăng $i$ lên $1$ đơn vị.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int* a = new int [n];
    int* b = new int [m];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);

    int ans = 0;
    for (int i = 0, j = 0; j < m and i < n;) {
        if (abs(a[i] - b[j]) <= k) {
            ++ans;
            ++i;
            ++j;
        }
        else if (a[i] - b[j] > k) {
            ++j;
        }
        else {
            ++i;
        }
    }
    cout << ans << endl;
    return 0;
}
```

***Python:***

```py
n, m, k = [int(_) for _ in input().strip().split()]
a = [int(_) for _ in input().strip().split()]
b = [int(_) for _ in input().strip().split()]

a = sorted(a)
b = sorted(b)

ans = 0
i = j = 0
while i < n and j < m:
    if abs(a[i] - b[j]) <= k:
        ans += 1
        i += 1
        j += 1
    elif a[i] - b[j] > k:
        j += 1
    else:
        i += 1

print(ans)
```