
# Dãy con tăng dài nhất (bản dễ) - LIQ

> *Nguồn: [LIQ | VNOI](https://oj.vnoi.info/problem/liq).*

Cho một dãy số nguyên $A$ gồm $n \; (1 \le n \le 1000)$ phần tử $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 10000)$.

Biết dãy con tăng đơn điệu là $1$ dãy $a_{i_1}, a_{i_2}, a_{i_3}, \ldots, a_{i_k}$ thỏa mãn $i_1 < i_2 < i_3 < \ldots < i_k$ và $a_{i_1} < a_{i_2} < a_{i_3} < \ldots < a_{i_k}$.

***Yêu cầu:*** Cho biết dãy con tăng đơn điệu dài nhất của dãy $A$ đã cho có bao nhiêu phần tử.

## Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n$ - số lượng phần tử của dãy $A$.
- Dòng thứ hai gồm $n$ số nguyên $a_1, a_2, a_3, \ldots, a_n$.

## Output - Dữ liệu ra

- Độ dài của dãy con tăng đơn điệu dài nhất.

## Sample - Ví dụ

#### Input:

```
6
1 2 5 4 6 2
```

#### Output:

```
4
```

#### Explanation:

Dãy con tăng đơn điệu dài nhất là dãy $[1, 2, 4, 6]$.
