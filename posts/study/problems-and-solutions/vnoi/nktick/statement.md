
# Xếp hàng mua vé - NKTICK

> *Nguồn: [NKTICK | VNOI](https://oj.vnoi.info/problem/nktick)*

Có $n$ người sắp hàng mua vé dự buổi hoà nhạc. Ta đánh số họ từ $1$ đến $n$ theo thứ tự đứng trong hàng. Mỗi người cần mua một vé, song người bán vé được phép bán cho mỗi người tối đa hai vé. Vì thế, một số người có thể rời hàng và nhờ người đứng trước mình mua hộ vé. Biết $t_i$ là thời gian cần thiết để người $i$ mua xong vé cho mình. Nếu người $i + 1$ rời khỏi hàng và nhờ người $i$ mua hộ vé thì thời gian để người thứ $i$ mua được vé cho cả hai người là $r_i$.

***Yêu cầu:*** Xác định xem những người nào cần rời khỏi hàng và nhờ người đứng trước mua hộ vé để tổng thời gian phục vụ bán vé là nhỏ nhất.

## Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n \; (1 \le n \le 60000)$.
- Dòng thứ hai là $n$ số nguyên dương $t_1, t_2, t_3, \ldots, t_n \; (1 \le t_i \le 30000)$.
- Dòng thứ ba là $n - 1$ số nguyên dương $r_1, r_2, r_3, \ldots, r_{n - 1} \; (1 \le r_i \le 30000)$

## Output - Dữ liệu ra

In ra tổng thời gian phục vụ nhỏ nhất.

## Sample - Ví dụ

#### Input:

```
5
2 5 7 8 4
4 9 10 10
```

#### Output:

```
18
```
