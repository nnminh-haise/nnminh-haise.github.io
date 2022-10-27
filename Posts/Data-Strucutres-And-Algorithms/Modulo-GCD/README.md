
# Modulo & Ước chung lớn nhất

> *Gặp lại những phép toán mà ta đã bỏ qua khi còn ngồi trên ghế nhà trường.*

## Modulo - Đồng dư thức

Phép đồng dư thức là phép tính cho bạn số dư của số nguyên này cho số nguyên khác. Kí hiệu thường dùng cho phép đồng dư thức là $\%$.

***Ví dụ:*** ta có: $5 \div 2 = 2$ dư $1$, $5 \%  2 = 1$.

### Một số tính chất của đồng dư thức

- $(a + b) \% c = (a \% c + b \% c) \% c$.
- $(a \cdot b) \% c = ((a \% c) \cdot (b \% c)) \% c$.

***Ví dụ:*** Với $a = 5, b = 3, c = 2$, ta có:

- $(5 + 3) \% 2 = (5 \% 2 + 3 \% 2) \% 2 = (1 + 1) \% 2 = 2 \% 2 = 0$.
- $(5 \cdot 3) \% 2 = ((5 \% 2) \cdot (3 \% 2)) \% 2 = (1 \cdot 1) \% 2 = 1 \% 2 = 1$.

---

## Ước chung lớn nhất

Ước chung lớn nhất *(hay còn gọi là Greatest Common Divisor - GCD)* của hai hay nhiều số nguyên là số nguyên lớn nhất mà là ước chung của các số đó.

***Ví dụ:*** Ta có ước chung lớn nhất của $6$ và $10$ là $2$ vì $2$ là số nguyên lớn nhất là ước chung của $6$ và $10$.

## Thuật toán xác định ước chung lớn nhất

### Thuật toán ngây thơ

Ta sẽ duyệt từ $\min(a, b)$ về đến $1$, nếu số đang xét hiện tại là ước của $a$ và $b$ thì số đó chính là $\gcd(a, b)$

***C++:***

```cpp
int gcd(int a, int b) {
	for (int i = min(a, b); i >= 1; --i) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
    // Chương trình sẽ không bao giờ chạy đến điểm này.
}
```

***Python:***

```py
def gcd(a, b):
    for i in range(min(a, b), 1, -1):
        if a % i == 0 and b % i == 0:
            return i
```

***Độ phức tạp thuật toán:*** $O(\min(a, b))$.

### Thuật toán Euclid

Ban đầu thuật toán được mô tả như sau: với hai số nguyên $a$ và $b$, ta sẽ lần lượt lấy số lớn hơn trừ cho số nhỏ hơn, cho đến khi một trong hai số bằng $0$. Khi đó, số còn lại chính là ước chung lớn nhất của cả hai.

***Ví dụ:*** Với $a = 16, b = 6$ ta có:

- Lần $1$: ta lấy $a - b$, ta được $a = 10, b = 6$.
- Lần $2$: ta lấy $a - b$, ta được $a = 4, b = 6$.
- Lần $3$: ta lấy $b - a$, ta được $a = 4, b = 2$.
- Lần $4$: ta lấy $a - b$, ta được $a = 2, b = 2$.
- Lần $5$: ta lấy $a - b$, ta được $a = 0, b = 2$.

Vì $a = 0$ nên ước chung lớn nhất của $16$ và $6$ là $2$.

***C++:***

```cpp
int gcdEuclid(int a, int b) {
	while (a != 0 && b != 0) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}

	if (a != 0) {
		return a;
	}

	return b;
}
```

***Python:***

```py
def gcdEuclid(a, b):
    while a != 0 and b != 0:
        if a > b:
            a -= b
        else:
            b -= a

    if a != 0:
        return a
    return b
```

Mặt khác ta nhận xét sau: **Với ba số nguyên $a, b, c$ thỏa $a - b = c$ ta có $c$ chia hết cho $\gcd(a, b)$.**

*Chứng minh:*

Theo giả thuyết ta có: $a - b = c$. Gọi $p = \gcd(a, b)$, ta có:

$$
\begin{cases}
a = p \times x \\
b = p \times y
\end{cases}
\Rightarrow a - b = p \times x - p \times y = p \times (x - y) = c \rightarrow c \mid \gcd(a, b)
$$

Một cách tương tự, ta cũng có thể chứng minh được **Với ba số nguyên $a, b, c$ thỏa $a - b = c$ ta có $a$ chia hết cho $\gcd(b, c)$.**

Từ hai nhận xét trên, ta rút ra được:
$$
\begin{cases}
\gcd(a, b) \le \gcd(b, c) \; (b, c \mid \gcd(a, b)) \\
\gcd(b, c) \le \gcd(a, b) \; (a, b \mid \gcd(b, c))
\end{cases}
\Rightarrow \gcd(a, b) = \gcd(b, c) \Leftrightarrow \gcd(a, b) = \gcd(b, a - b)
$$

Ta đã chứng minh được $\gcd(a, b) = \gcd(b, a - b)$. Song, thứ tự phát biểu không quan trọng. Ta cũng có thể phát biểu: $\gcd(a, b) = \gcd(a - b, b)$. Và khi ta tiếp tục khai triển theo công thức trên, ta được:

$$\gcd(a, b) = \gcd(a - b, b) = \gcd(a - 2b, b) = \gcd(a - 3b, b) = \cdots = \gcd(a - qb, b)$$

Mặt khác: $a = qb + r$ với $r = a \% b$. Nên: $a - qb = r \Rightarrow \gcd(a, b) = \gcd(r, b) = \gcd(b, r)$.

Với chứng minh trên, ta có có một đoạn code mới như sau:

*Cách viết đệ quy:*

***C++:***

```cpp
int gcdEuclid(int a, int b) {
	return (b ? gcdEuclid(b, a % b) : a);
}
```

***Python:***

```py
def gcdEuclid(a, b):
    if b == 0:
        return a

    return gcdEuclid(b, a % b)
```

*Cách viết tuyến tính:*

***C++:***

```cpp
int gcdEuclid(int a, int b) {
	while (b != 0) {
		a %= b;
		swap(a, b);
	}

	return a;
}
```

***Python:***

```py
def gcdEuclid(a, b):
    while b != 0:
        a %= b
        a, b = b, a

    return a
```

***Độ phức tạp thuật toán:*** $O(\log(\max(a, b)))$.

## Bội chung nhỏ nhất

Bội chung nhỏ nhất của hai hay nhiều số (*Least Common Multiple hay LCM*) là số nguyên nhỏ nhất sao cho nó là bội của các số đó.

Ta có thể xác định bội chung nhỏ nhất của hai số bằng cách lấy tích hai số đó và chia cho ước chung lớn nhất của nó:

$$\text{lcm}(a, b) = \dfrac{a \times b}{\gcd(a, b)}$$

Do vậy ta có thể thiết kế một thuật toán tìm bội chung nhỏ nhất như sau:

***C++:***

```cpp
int lcm(int a, int b) {
	return a * b / gcdEuclid(a, b);
}
```

***Python:***

```py
def lcm(a, b):
    return a * b // gcd(a, b)
```

## Tài liệu tham khảo

1. [Modulo - Đồng dư thức | Wikipedia](https://en.wikipedia.org/wiki/Modulo_operation).
2. [Greatest Common Divisor - Ước chung lớn nhất | Wikipedia](https://en.wikipedia.org/wiki/Greatest_common_divisor).
3. [Euclidean algorithm for computing the greatest common divisor - Thuật toán Euclid tính ước chung lớn nhất | CP - Algorithms](https://cp-algorithms.com/algebra/euclid-algorithm.html).
4. [Modulo & GCD - Đồng dư thức và Ước chung lớn nhất | VNOI](https://vnoi.info/wiki/translate/he/So-hoc-Phan-1-Modulo-gcd.md).
5. [std::gcd | cppreference](https://en.cppreference.com/w/cpp/numeric/gcd).
6. [Greatest Common Divisor | Tutorialspoint](https://www.tutorialspoint.com/cplusplus-program-to-find-gcd).

## Bài tập tham khảo

- [Array Sum - Tổng dãy](/Posts/Problems-And-Solutions/Categories/Modulo-GCD/Array-Sum/Statement.md).
- [Divisible - Chia hết](/Posts/Problems-And-Solutions/Categories/Modulo-GCD/Divisible/Statement.md).
- [Triplet - Bộ ba](/Posts/Problems-And-Solutions/Categories/Modulo-GCD/Triplet/Statement.md).
- [GCD & LCM - Ước chung lớn nhất và Bộ chung nhỏ nhất](/Posts/Problems-And-Solutions/Categories/Modulo-GCD/GCD-LCM/Statement.md).
- [Practice - Luyện tập](/Posts/Problems-And-Solutions/Categories/Modulo-GCD/Practice/Statement.md).
- [Remove Elements - Xóa phần tử](/Posts/Problems-And-Solutions/Categories/Modulo-GCD/Remove-Elements/Statement.md).