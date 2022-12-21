
# Đếm chuỗi con

Cho một chuỗi $s$ và $p$ lần lượt có độ dài $n \; (1 \le n \le 1000)$ và $m \; (1 \le m \le 1000)$ gồm các kí tự in thường trong bản chữ cái tiếng anh. 

***Yêu cầu:*** Đếm số lần xuất hiện của chuỗi $p$ trong chuỗi $s$. Lưu ý: các kí tự của chuỗi $p$ phải xuất hiện liên tiếp trong chuỗi $s$ mới tính là một lần xuất hiện.

## Input - Dữ liệu vào

- Gồm hai dòng, dòng thứ nhất là chuỗi $s$, dòng thứ hai là chuỗi $p$.

## Output - Dữ liệu ra

- Một số nguyên duy nhất là số lần xuất hiện của chuỗi $p$ trong $s$.

## Sample - Ví dụ

#### Input:

```
abcd
bc
```

#### Output:

```
1
```

#### Explanation:

Ta có dãy `p = bc` và xuất hiện trong dãy `s` từ vị trí $2$ trở đi.
