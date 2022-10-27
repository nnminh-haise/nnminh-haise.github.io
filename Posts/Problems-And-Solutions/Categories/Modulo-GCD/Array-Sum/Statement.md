
# Tổng dãy

Cho một dãy $A$ gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n$ và một số nguyên dương $k$.

***Yêu cầu:*** Tính tổng các phần tử trong dãy và đưa ra kết quả là phần dư của tổng vừa tìm cho $k$.

## Input - Dữ liệu vào

- Dòng đầu tiên gồm hai số nguyên dương $n \; (1 \le n \le 1000)$ và $k \; (1 \le n \le 1000)$.
- Dòng thứ hai gồm $n$ số nguyên $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 1000)$.

## Output - Dữ liệu ra

- Một số nguyên duy nhất là phần dư của phép chia giữa tổng các phần tử trong dãy $A$ với số nguyên dương $k$.

## Sample - Ví dụ

***Input:***

```
5 4
1 2 3 4 5
```

***Output:***

```
3
```

***Explanation:***

Ta có: $\sum\limits_{i = 1}^{n}i = 15 \Rightarrow 15 \% 4 = 3$
