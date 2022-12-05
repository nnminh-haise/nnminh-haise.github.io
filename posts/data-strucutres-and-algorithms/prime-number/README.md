
# Prime number & Sieve of Eratosthenes - Số nguyên tố & Thuật toán sàng nguyên tố Eratosthens

> *Đố cậu! Số nguyên tố là gì? Làm sao để tìm một số lượng lớn các số nguyên tố trong khoảng?*

---

## Prime number - Số nguyên tố

### Definition - Định nghĩa

Số nguyên tố là số tự nhiên lớn hơn $1$ có duy nhất hai ước số là $1$ và chính nó. Các số không phải số nguyên tố được gọi là hợp số.

**Ví dụ:** Số $5$ là số nguyên tố vì số $5$ có duy nhất hai ước số là $1$ và $5$. Còn số $10$ không phải là số nguyên tố vì $10$ có nhiều hơn $2$ ước số: $1, 2, 5, 10$.

### Primality test - Thuật toán kiểm tra số nguyên tố

> *Nếu một số là số nguyên tố thì nó được gọi là có tính nguyên tố (primality).*

#### Naive Algorithm - Thuật toán ngây thơ

Dựa vào định nghĩa của số nguyên tố, cậu có thể kiểm tra một số nguyên tố bằng cách đếm số lượng ước số của nó. Nếu số lượng ước số đo đúng bằng hai ước thì số đó chính là số nguyên tố.

***C++:***

```cpp
bool is_prime(int x) {
    if (x <= 1) {
        return false;
    }

    int counter = 0;

    for (int i = 1; i <= x; ++i) {
        if (x % i == 0) {
            ++counter;
        }
    }

    if (counter == 2) {
        return true;
    }
    return false;
}
```

***Python:***

```py
def is_prime(x : int):
    if x <= 1:
        return False
    
    counter = 0
    
    for i in range(1, x + 1):
        if x % i == 0:
            counter += 1
    
    if counter == 2:
        return True
    
    return False
```

Tuy giải quyết được yêu cầu bài toán nhưng thuật toán trên không tối ưu về mặt thời gian khi cậu phải thực hiện ít nhất $n$ phép so sánh và tính toán để kiểm tra số $n$ có phải là một số nguyên tố hay không.

Do vậy mà **độ phức tạp thời gian** của thuật toán trên là $O(n)$.

#### Optimized Algorithm - Thuật toán tối ưu

Để cải tiến thuật toán trên cậu cần có một số nhận xét sau:

- Số nguyên tố chẵn duy nhất là số $2$ và cũng là số nguyên tố đầu tiên.
- Các số nguyên tố, trừ số $2$, đều là số lẻ.
- Nếu giả sử ban đầu số $x$ là một số nguyên tố, nếu tồn tại một số $i \in [3, \sqrt{x}]$ là ước của $x$ thì điều đó chứng tỏ giả định ban đầu là sai, hay $x$ không phải là số nguyên tố.

Từ những nhận xét trên, cậu có một thuật toán kiểm tra tính nguyên tố tối ưu như sau:

***C++:***

```cpp
bool is_prime(int x) {
    if (x < 2) {
        return false;
    }
    if (x == 2 || x == 3) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
```

***Python:***

```py
def is_prime(x : int):
    if x <= 1:
        return False
    
    if x == 2 or x == 3:
        return True
    
    if x % 2 == 0:
        return False
    
    for i in range(3, math.ceil(math.sqrt(x)) + 1, 2):
        if x % i == 0:
            return False
    
    return True
```

**Độ phức tạp thời gian:** $O(\sqrt{n})$.

---

## Sieve of Eratosthenes - Thuật toán sàng số nguyên tố Eratosthens

> ***Đặt vấn đề:*** In ra tất cả các số nguyên tố trong đoạn $[1, 10^6]$.

### Naive Algorithm - Giải thuật ngây thơ

Cậu có thể áp dụng ngay thuật toán kiểm tra tính nguyên tố của một số nguyên bất kì ở trên để giải quyết bài toán trên. Cụ thể, cậu sẽ sử dụng vòng lặp `for` để duyệt qua các giá trị $i$ trong đoạn $[1, 10^6]$, với mỗi giá trị $i$ cậu sẽ kiểm tra $i$ có phải là số nguyên tố hay không, nếu phải thì in ra ngoài màn hình.

***C++:***

```cpp
#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int x) {
    if (x < 2) {
        return false;
    }
    if (x == 2 || x == 3) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(x); i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    for (int i = 1; i <= (int)1e6; ++i) {
        if (is_prime(i) == true) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
```

***Python:***

```py
import math


def is_prime(x : int):
    if x <= 1:
        return False
    
    if x == 2 or x == 3:
        return True
    
    if x % 2 == 0:
        return False
    
    for i in range(3, math.ceil(math.sqrt(x)) + 1, 2):
        if x % i == 0:
            return False
    
    return True


for i in range(1, 1000001):
    if is_prime(i) == True:
        print(i)
```


Vì mỗi giá trị $i \in [1, 10^6]$ thì ta sẽ gọi hàm `is_prime()` ở trên chính xác $1$ lần. Mà độ phức tạp thời gian của hàm `is_prime()` là $O(\sqrt{n})$. Do đó, giải thuật này có **độ phức tạp thời gian** sẽ là $O(n \cdot \sqrt{n})$. Với giá trị tối đa là $n = 10^6$ thì ta sẽ cần tối thiểu $10^6 \cdot \sqrt{10^6} = 10^6 \cdot 10^3 = 10^9$ phép tính để giải quyết bài toán.

### Sieve of Eratosthenes - Thuật toán sàng số nguyên tố

Thuật toán sàng số nguyên tố là thuật toán cho phép ta tìm tất cả các số nguyên tố trong đoạn $[1, n]$ với **độ phức tạp thời gian** là $O(n \log \log n)$.

Ý tưởng cơ bản của thuật toán này có thể được mô tả đơn giản như sau: nếu số $p$ là số nguyên tố thì các số $2p, 3p, \ldots, kp \le n$ chắc chắn không phải số nguyên tố. Do đó ta sẽ đánh dấu các số này là các hợp số. Tương tự với các số nguyên tố $p$ tiếp theo cho đến khi tất cả các số trong đoạn $[1, n]$ được đánh dấu hết.

Dễ thấy có vài số sẽ bị đánh dấu nhiều hơn $1$ lần, nhưng số lượng các số này không nhiều khi $n$ lớn nên ta có thể bỏ qua.

***C++:***

```cpp
void sieveOfEratosthenes() {
    int n = (int)1e6;
    vector < bool > is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p <= n; ++p) {
        if (is_prime[p] == true && (long long)p * p <= n) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (is_prime[i] == true) {
            cout << i << " ";
        }
    }
    cout << endl;
}
```

***Python:***

```py
def sieveOfEratosthenes():
    n = 1000000
    is_prime = [True for i in range(0, n + 1)]
    
    is_prime[0] = is_prime[1] = False
    
    for p in range(2, n + 1):
        if is_prime[p] == True and p * p <= n:
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
    
    for i in range(1, n + 1):
        if is_prime[i] == True:
            print(i)
```

> *Mình sẽ có một bài phân tích sâu hơn về phần chứng minh độ phức tạp của thuật toán trên, cậu hãy đón chờ trong những số tiếp theo nha.*

## Tổng kết

Vậy là mình và cậu đã cùng nhau đi qua một số chủ đề chính về số nguyên tố và hai thuật toán lớn liên quan đến số nguyên tố. Số nguyên tố có rất nhiều áp dụng và có vai trò quan trọng trong đời sống hằng ngày của chúng ta.

*Mình hi vọng cậu đã có những kiến thức quý giá cho riêng cậu. Chúc cậu may mắn và luôn chăm chỉ nhé.*

---

## Bài tập tham khảo

- [Số gần nguyên tố](/Posts/Problems-And-Solutions/Categories/Prime-Number/Almost-Prime/Statement.html).
- [Đếm số nguyên tố](/Posts/Problems-And-Solutions/Categories/Prime-Number/Count-Prime/Statement.html).
- [Số nguyên tố thứ n](/Posts/Problems-And-Solutions/Categories/Prime-Number/N-th-Prime/Statement.html).
- [Số nguyên tố tiếp theo](/Posts/Problems-And-Solutions/Categories/Prime-Number/Next-Prime/Editorial.html).
- [Số siêu nguyên tố](/Posts/Problems-And-Solutions/Categories/Prime-Number/Super-Prime/Statement.html).

---

## Tài liệu tham khảo

1. [Prime number - Số nguyên tố | Wikipedia](https://en.wikipedia.org/wiki/Prime_number).
2. [Sieve of Eratosthenes - Thuật toán sàng số nguyên tố | Wikipedia](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes).
3. [Sieve of Eratosthenes - Thuật toán sàng số nguyên tố | CP - Algorithms](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html).
