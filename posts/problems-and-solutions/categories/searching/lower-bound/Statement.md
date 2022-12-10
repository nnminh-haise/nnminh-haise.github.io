
# Cận dưới

Cho dãy $A$ có $n \; (1 \le n \le 10000)$ phần tử $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 10000)$ là các số nguyên dương và một số nguyên dương $k \; (1 \le k \le 10000)$. Dãy $A$ được đánh chỉ số từ $0$.

Cận dưới của một số $k$ bất kì trong dãy $A$ là vị trí nhỏ nhất của $k$ trong dãy $A$ đã sắp xếp hoặc vị trí lớn nhất của số nguyên lớn nhất nhỏ hơn $k$.

***Yêu cầu:*** Tìm cận dưới của $k$ trong dãy $A$.

## Input - Dữ liệu vào

- Dòng đầu tiên gồm hai số nguyên dương $n$ và $k$.
- Dòng thứ hai gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n$.

## Output - Dữ liệu ra

- Một số nguyên duy nhất là chỉ số của cận dưới của $k$ trong dãy $A$.

## Sample - Ví dụ

#### Input:

```
5 3
1 2 3 4 5
```

#### Output:

```
2
```

#### Input:

```
5 2
1 2 2 4 5
```

#### Output:

```
1
```

#### Input:

```
5 3
1 2 2 4 5
```

#### Output:

```
3
```
