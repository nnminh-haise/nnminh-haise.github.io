
# Xóa phần tử

Cho một dãy $A$ có $n$ phần tử là các số nguyên dương $a_1, a_2, a_3 \ldots, a_n$. Bạn có thể xóa đi một số phần tử (hoặc không xóa bất cứ phần tử nào) sao cho ước chung lớn nhất của dãy $A$ bằng $1$.

***Yêu cầu:*** Hãy đếm số lượng phần tử cần xóa ít nhất sao cho ước chung lớn nhất của cả dãy $A$ bằng $1$.

## Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $q \; (1 \le q \le 100)$ - số truy vấn cần trả lời. Mỗi truy vấn có dạng như sau:

    - Dòng đầu tiên là số nguyên dương $n \; (1 \le n \le 10^3)$ - số lượng phần tử của dãy $A$.
    - Dòng thứ hai gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 5 \cdot 10^4)$ như đã mô tả.

## Output - Dữ liệu ra

- Gồm $q$ dòng, dòng thứ $i$ là câu trả lời cho truy vấn thứ $i$ tương ứng.

## Sample - Ví dụ

#### Input:

```
2
2
2 3
2
2 4
```

#### Output:

```
0
-1
```
