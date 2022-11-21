
# Count Prime - Đếm số nguyên tố | Editorial - Lời giải

> *Tags: Prime number, Math, Basic*

## Statement - Đề bài

Số nguyên tố là số chỉ có duy nhất hai ước là $1$ và chính nó. Cho trước một số nguyên dương $n$.

***Yêu cầu:*** Đếm số lượng số nguyên tố bé hơn $n$.

### Input - Dữ liệu vào

- Một số nguyên dương $n \; (0 < n \le 5 \times 10^6)$ duy nhất.

### Output - Dữ liệu ra

- Một số nguyên dương $m$ duy nhất là số lượng số nguyên tố bé hơn $n$.

---

## Solution - Giải thuật

### Naive solution - Giải thuật ngây thơ

Sử dụng hàm kiểm tra tính nguyên tố của số nguyên dương $n$. Với mỗi số nguyên dương $p \; (p < n)$, nếu $p$ là số nguyên tố thì tăng biến đếm lên $1$. Kết quả bài toán là giá trị của biến đếm khi kết thúc vòng lặp.

***Độ phức tạp thời gian:*** Hàm kiểm tra tính nguyên tố có độ phức tạp thời gian trung bình là $O(\sqrt{n})$. Với mỗi giá trị $p$ trong nửa khoảng $[1, n)$ ta sẽ thực hiện kiểm tra tính nguyên tố của $p$. Do đó độ phức tạp thời gian trung bình của giải thuật này sẽ là $O(n \sqrt{n})$.

### Optimized solution - Giải thuật tối ưu

Áp dụng thuật toán sàng nguyên tố, tìm tất cả các số nguyên tố bé hơn $n$ trong $O(n \log \log n)$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

int countPrimes(int n) {
    bool *primality = new bool [n];
    for (int p = 2; p < n; ++p) {
        primality[p] = true;
    }

    int counter = 0;
    for (int p = 2; p < n; ++p) {
        if (primality[p] == true && (long long)p * p < n) {
            for (int i = p * p; i < n; i += p) {
                primality[i] = false;
            }
        }
        if (primality[p]) ++counter;
    }

    delete[] primality;

    return counter;
}

int main() {
    int n;
    cin >> n;
    cout << countPrimes(n) << endl;

    return 0;
}
```

***Python:***

```py
def countPrimes(n: int) -> int:
    primality = [True for i in range(0, n)]
    counter = 0

    for p in range(2, n):
        if primality[p] == True and p * p < n:
            for i in range(p * p, n, p):
                primality[i] = False
        counter += int(primality[p])

    return counter


print(countPrimes(int(input())))
```