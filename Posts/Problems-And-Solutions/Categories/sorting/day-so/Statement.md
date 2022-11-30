
# Dãy số

Cho dãy số $F$ gồm $n \; (2 < n \le 10^6)$ số nguyên $F = (f_1, f_2, f_3, \ldots, f_n)$ được định nghĩa như sau: 

$$
f_i =
\begin{cases}
1, \; \text{if} \; 1 \le i \le 2 \\
(f_{i - 1} + f_{i - 2}) \mod 128, \; \text{if} \; 2 < i \le n
\end{cases}
$$

***Yêu cầu:*** Khi sắp xếp dãy $F$ theo thứ tự không giảm thì số thứ $k \; (k \le n)$ có giá trị là bao nhiêu?

## Input - Dữ liệu vào

- Một dòng duy nhất gồm hai số $n$ và $k$ như mô tả.

## Output - Dữ liệu ra

- Một số nguyên duy nhất là giá trị $f_k$ cần tìm.

## Sample - Ví dụ

#### Input:

```
10 5
```

#### Output:

```
5
```

#### Explanation:

Với $n = 10$ ta có dãy $F$ như sau: $1, 1, 2, 3, 5, 8, 13, 21, 34, 55$ và số thứ $5$ có giá trị là $5$.
