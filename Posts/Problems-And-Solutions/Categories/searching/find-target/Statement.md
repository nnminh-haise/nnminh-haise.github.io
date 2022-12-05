
# Số cần tìm

Cho một dãy $A$ gồm $n \; (1 \le n \le 100)$ phần tử $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 100)$ là các số nguyên dương và số nguyên dương $k \; (1 \le k \le 100)$.

***Yêu cầu:*** Sau khi sắp xếp dãy, đưa ra tất cả vị trí xuất hiện số $k$ trong dãy đã sắp xếp theo chiều tăng dần. Lưu ý: dãy được đánh chỉ số từ $0$.

## Input - Dữ liệu vào

- Dòng đầu tiên gồm hai số nguyên dương $n$ và $k$ như mô tả.
- Dòng thứ hai gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n$.

## Output - Dữ liệu ra

- Một dòng duy nhất có (hoặc không) các giá trị là vị trí xuất hiện của số $k$ trong dãy đã sắp xếp theo thứ tự tăng dần.

## Sample - Ví dụ

#### Input:

```
5 2
1 2 3 5 2
```

#### Output:

```
1 2
```

#### Explanation:

Sau khi sắp xếp dãy thì ta được: $[1, 2, 2, 3, 5]$ và số $2$ ở các vị trí $1, 2$.
