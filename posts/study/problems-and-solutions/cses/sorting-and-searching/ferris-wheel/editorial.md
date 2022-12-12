
# Ferris Wheel | Editorial - Lời giải

> *Tags: Sorting, Searching*

## Statement - Đề bài

> *Nguồn: [Ferris Wheel - CSES Problem set](https://cses.fi/problemset/task/1090/).*

There are $n$ children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed $x$. You know the weight of every child.

What is the minimum number of gondolas needed for the children?

### Input - Dữ liệu vào

- The first input line contains two integers $n \; (1 \le n \le 2 \cdot 10^5)$ and $x \; (1 \le x \le 10^9)$: the number of children and the maximum allowed weight.

- The next line contains $n$ integers $p_1, p_2, \ldots, p_n \; (1 \le p_i \le x)$: the weight of each child.

### Output - Dữ liệu ra

- Print one integer: the minimum number of gondolas.

---

## Solution - Giải thuật

- Sắp xếp lại dãy $P$ theo trọng lượng $p_i$.
- Mỗi gondola sẽ có trọng lượng tối đa là $x$ và chứa tối đa $2$ người. Do vậy, cách chọn tối ưu sẽ là chọn người có trọng lượng lớn nhất và nhỏ nhất và cho họ lên cùng một gondola nếu tổng trọng lượng không quá $x$.
- Nếu không thể thì sẽ chọn người có trọng lượng lớn thứ nhì, và tiếp tục như vậy cho đến khi hết ghép được hai người vào một gondola.
- Những người không ghép được sẽ ở trong một gondola riêng. 

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int* a = new int [n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);
    int ans = 0, i = 0, j = n - 1;
    int* is_used = new int [n];
    for (int i = 0; i < n; ++i) {
        is_used[i] = false;
    }
    
    while (i < j) {
        if (a[i] + a[j] <= x) {
            is_used[i] = is_used[j] = true;
            ++i;
            --j;
            ++ans;
        }
        else {
            --j;
        }
    }

    for (int i = 0; i < n; ++i) {
        ans += (is_used[i] == false);
    }

    cout << ans << endl;
    return 0;
}
```

***Python:***

```py
n, x = [int(_) for _ in input().strip().split()]
a = [int(_) for _ in input().strip().split()]

a = sorted(a)

ans = i = 0
j = n - 1
used = [False for _ in range(n)]

while i < j:
    if a[i] + a[j] <= x:
        used[i] = used[j] = True
        i += 1
        j -= 1
        ans += 1
    else:
        j -= 1
for item in used:
    ans += (item == False)

print(ans)
```