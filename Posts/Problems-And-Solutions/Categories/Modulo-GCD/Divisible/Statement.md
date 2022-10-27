
# Chia hết

Cho một dãy $A$ gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots a_n$. Với mỗi số $a_i$ hãy kiểm tra số đó chia hết cho $7$ hoặc $13$ hay không.

- Nếu $a_i$ chia hết cho $7$ in `mod 7`.
- Nếu $a_i$ chia hết cho $13$ in `mod 13`.
- Nếu $a_i$ chia hết cho cả $7$ và $13$ in `both`.
- Nếu $a_i$ không chia hết cho $7$ hoặc $13$ in `none`.

***Yêu cầu:*** Với mỗi phần tử $a_i$ hãy in ra câu trả lời tương ứng.

## Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n \; (1 \le n \le 1000)$.
- Dòng thứ hai gồm $n$ số nguyên $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 1000)$.

## Output - Dữ liệu ra

- Gồm $n$ dòng, mỗi dòng là đầu ra tương ứng với phần tử $a_i$.

## Sample - Ví dụ

***Input:***

```
5
7 14 91 6 26
```

***Output:***

```
mod 7
mod 7
both
mod 13
none
```