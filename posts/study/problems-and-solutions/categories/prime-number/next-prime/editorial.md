
# Số nguyên tố tiếp theo | Editorial - Lời giải

> *Tags: Prime number, Math, Basic*

## Statement - Đề bài

Số nguyên tố là số chỉ có đúng hai ước là $1$ và chính nó. Cho một số nguyên dương $n$.

***Yêu cầu:*** Tìm số nguyên tố $x$ nhỏ nhất sao cho $x \ge n$.

### Input - Dữ liệu vào

- Một số nguyên dương $n \; (1 \le n \le 10^5)$ duy nhất.

### Output - Dữ liệu ra

- Số nguyên dương $x$ duy nhất thỏa mãn yêu cầu đề bài.

---

## Solution - Giải thuật

### Naive solution - Giải thuật ngây thơ

Gọi $p$ là một biến có giá trị từ $2 \rightarrow \infty$, với mỗi giá trị $p$, sử dụng hàm `primality()` để kiểm tra tính nguyên tố của số $p$. Nếu $p$ là một số nguyên tố và $p \ge n$ thì $p$ chính là số cần tìm.

***Độ phức tạp thời gian:*** $O(n \sqrt{n})$

### Optimized solution - Giải thuật tối ưu

Sử dụng thuật toán sàng số nguyên tố từ $1 \rightarrow 10^6$. Sau đó sử dụng vòng lặp `for` để duyệt tuyến tính các số nguyên tố tìm được cho đến khi xác định được số nguyên tố đầu tiên thỏa mãn yêu cầu đề bài.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

unsigned int sieve(unsigned int n) {
    const unsigned int N = 1e6 + 7;
    unsigned int *primality = new unsigned int [N];
    
    for (int p = 2; p <= N; ++p) {
        primality[p] = true;
    }

    primality[0] = primality[1] = 0;
    for (unsigned int p = 2; p <= N; ++p) {
        if (primality[p] == true && (unsigned long long)p * p <= N) {
            for (int i = p * p; i <= N; i += p) {
                primality[i] = false;
            }
        }
    }

    for (unsigned int p = 2; p <= N; ++p) {
        if (primality[p] && p >= n) {
            return p;
        }
    }
    return -1;
}

int main() {
    unsigned int n;
    cin >> n;
    cout << sieve(n) << endl;

    return 0;
}
```

***Python:***

```py
def sieve(n: int) -> int:
    N = 1000000
    primality = [True for i in range(0, N + 1)]
    
    primality[0] = primality[1] = False
    
    for p in range(2, N + 1):
        if primality[p] == True and p * p <= N:
            for i in range(p * p, N, p):
                primality[i] = False
    
    for i in range(2, N + 1):
        if primality[i] == True and i >= n:
            return i
    
    return -1


print(sieve(int(input())))
```