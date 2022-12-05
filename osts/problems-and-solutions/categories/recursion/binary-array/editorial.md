
# Dãy nhị phân | Editorial - Lời giải

> *Tags: Recursion, Basic*

## Statement - Đề bài

Một dãy gồm $n$ phần tử chỉ bao gồm các số $0$ hoặc $1$ được gọi là dãy nhị phân độ dài $n$.

***Yêu cầu:*** Cho số nguyên dương $n$. In ra tất cả các dãy nhị phân độ dài $n$ được sắp xếp theo thứ tự từ điển.

### Input - Dữ liệu vào

- Một số nguyên dương $n$ duy nhất.

### Output - Dữ liệu ra

- Gồm nhiều dòng, mỗi dòng là một dãy nhị phân độ dài $n$. Mỗi phần tử của dãy được ngăn cách bởi dấu cách.

---

## Solution - Giải thuật



***C++:***

```cpp
class Solution {
public:
    void binaryArray(const int n, int index, int *x) {
        if (index == n) {
            for (int i = 0; i < n; ++i) {
                cout << x[i] << (i < n - 1 ? " " : "\n");
            }
            return;
        }
        for (int i = 0; i <= 1; ++i) {
            x[index] = i;
            recursion(n, index + 1, x);
        }
    }
};
```

***Python:***

```py
def binaryArray(n: int, index: int, arr):
    if (index == n):
        print(" ".join(list(map(str, arr))))
    else:
        for i in range(0, 2):
            arr[index] = i
            recursion(n, index + 1, arr)


n = int(input())
arr = [0 for i in range(0, n)]

binaryArray(n, 0, arr)

```
