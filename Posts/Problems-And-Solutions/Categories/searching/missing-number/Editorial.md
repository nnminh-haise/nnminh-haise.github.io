
# Số còn thiếu | Editorial - Lời giải

> *Tags: Searching, Binary search, basic*

## Statement - Đề bài

Cho một dãy $A$ gồm $n \; (1 \le n \le 10^4)$ số phân biệt có giá trị trong đoạn $[0, n]$.

***Yêu cầu:*** Tìm số còn thiếu trong đoạn $[0, n]$.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n$.
- Dòng thứ hai gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n$ là giá trị của các phần tử trong dãy $A$.

### Output - Dữ liệu ra

- Một số nguyên duy nhất còn thiếu của dãy $A$ trong đoạn $[0, n]$.

---

## Solution - Giải thuật

Có thể áp dụng thuật toán tìm kiếm nhị phân vào bài toán như sau:

- Sắp xếp lại dãy. Khi đó dãy đã sắp xếp có thể được chia làm hai phần như sau:

    - Phần đầu tiên có dạng: $i = a_i$.
    - Phần thứ hai có dạng: $i < a_i$.
    - Ví dụ: với $A = [0, 1, 3, 4]$ thì sau khi sắp xếp ta được: $[0, 1, 3, 4]$.
    - Khi đó, phần đầu tiên sẽ là đoạn $[0, 1]$ và đoạn thứ hai sẽ là đoạn $[3, 4]$.

- Phần tử chia dãy đã cho làm hai phần chính là phần tử bị thiếu và đây cũng là phần tử có giá trị nhỏ nhất thỏa mãn tính chất $i < a_i$.
- Do vậy có thể áp dụng tính chất $i < a_i$ vào việc tìm kiếm nhị phân phần tử nhỏ nhất thỏa mãn $i < a_i$ trong dãy $A$ sau khi sắp xếp.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector < int > &a) {
    sort(a.begin(), a.end());
    int left = 0, right = a.size();
    while (left < right) {
        int mid = (right - left) / 2 + left;
        if (a[mid] > mid) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << missingNumber(a) << endl;
    return 0;
}
```

***Python:***

```py
def missingNumber(a: list)->int:
    left, right = 0, len(a)
    while left < right:
        mid = (right - left) // 2 + left
        if mid < a[mid]:
            right = mid
        else:
            left = mid + 1
    
    return left

n = int(input())
print(missingNumber(list(map(int, input().split(' ')))))
```

> *Bên cạnh cách làm trên, còn có thể áp dụng toán học vào để giải quyết bài toán này.*
