
# Hàm lũy thừa | Editorial - Lời giải

> *Tags: C++, Function, basic*

## Statement - Đề bài

***Yêu cầu:*** Viết hàm tính lũy thừa $a^b$ với $1 \le a \le 10, 1 \le b \le 10$.

### Input - Dữ liệu vào

- Hai số nguyên dương $a$ và $b$.

### Output - Dữ liệu ra

- Kết quả phép tính $a^b$.

---

## Solution - Giải thuật



***C++:***

```cpp
long long pow(int a, int b) {
    long long res = 1;
    for (int i = 1; i <= b; ++i) {
        res *= (long long)a;
    }
    return res;
}

// or

long long pow(int a, int b) {
    if (b == 0) {
        return 1;
    }

    if (b == 1) {
        return a;
    }

    long long tmp = pow(a, b / 2);
    if (b % 2 == 0) {
        return tmp * tmp;
    }
    return tmp * tmp * a;
}
```

***Python:***

```py
def pow(a: int, b: int):
    res = 1
    for i in range(b):
        res *= a

    return res
```
