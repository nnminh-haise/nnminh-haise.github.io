
# Tính toán 1 | Editorial - Lời giải

> *Tags: Basic, Recursion*

## Statement - Đề bài

Cho số nguyên dương $n$.

***Yêu cầu:*** Thiết kế một hàm đệ quy tính giá trị sau.

$$S = 1 + \dfrac{1}{2} + \dfrac{1}{3} + \dfrac{1}{4} + \ldots + \dfrac{1}{n}$$

### Input - Dữ liệu vào

- Một số nguyên dương $n$ duy nhất.

### Output - Dữ liệu ra

- Một số thực $S$ duy nhất là kết quả của phép tính.

---

## Solution - Giải thuật

Gọi hàm $f(n)$ là hàm đệ quy tính tổng $S$ tại $n$. Như mọi hàm đệ quy khác thì cần phải xác định điểm neo và công thức truy hồi cho hàm.

- **Điểm neo:** Dựa trên công thức, số hạng đầu tiên của tổng trên luôn là $1$. Do đó, có thể chọn $n = 1$ là điểm neo của hàm số.

- **Công thức truy hồi:** Giả sử, xét hàm số $f(n)$, giá trị $f(n) = \dfrac{1}{n} + f(n - 1)$ vì số hạng thứ $n$ sẽ là $\dfrac{1}{n}$ và $S = f(n) = \dfrac{1}{n} + \dfrac{1}{n - 1} + \dfrac{1}{n - 2} + \ldots + 1 = \dfrac{1}{n} + f(n - 1)$.

<!-- ***C++:***

```cpp
``` -->

***Python:***

```py
def f(n: float) -> float:
    if n == 1:
        return 1
    
    return (1 / n + f(n - 1))


n = float(input())
print(f(n))
```
