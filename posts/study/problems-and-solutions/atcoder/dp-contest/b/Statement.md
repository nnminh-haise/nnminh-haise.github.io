
# B Frog 2 | DP Contest | Atcoder

> *Nguồn: [B | DP Contest | Atcoder](https://atcoder.jp/contests/dp/tasks/dp_b)*

Có $n$ hòn đá được đánh số từ $1$ đến $n$. Với mỗi hòn đá thứ $i$ sẽ có độ cao $h_i$. Có một chú ếch đang ở trên hòn đá $1$. Chú ếch sẽ nhảy từ hòn đá này sang hòn đá khác cho đến khi đến được hòn đá $n$. Mỗi lần, chú ếch có thể nhảy từ hòn đá $i$ sang các hòn đá $i + 1, i + 2, i + 3, \ldots, i + k$. Và chi phí sẽ là chênh lệch chiều cao giữa hai hòn đá mà chú ếch vừa di chuyển.

***Yêu cầu:*** Đưa ra chi phí nhỏ nhất có thể để chú ếch từ hòn đá $1$ di chuyển sang hòn đá $n$.

## Input - Dữ liệu vào

- Dòng đầu tiên là hai số nguyên dương $n \; (2 \le n \le 10^5)$ và $k \; (1 \le k \le 100)$.
- Dòng thứ hai là $n$ số nguyên $h_1, h_2, h_3, \ldots, h_n \; (1 \le h_i \le 10^4)$.

## Output - Dữ liệu ra

- Chi phí nhỏ nhất để chi chuyển từ hòn đá $1$ đến hòn đá $n$.

## Sample - Ví dụ

#### Input:

```
5 3
10 30 40 50 20
```

#### Output:

```
30
```

#### Explanation:

Hành trình di chuyển của chú ếch sẽ là $1 \rightarrow 2 \rightarrow 5$ và chi phí là $|10 - 30| + |30 - 20| = 30$.

#### Input:

```
10 4
40 10 20 70 80 10 20 70 80 60
```

#### Output:

```
40
```

#### Explanation:

Hành trình di chuyển của chú ếch sẽ là $1 \rightarrow 4 \rightarrow 8 \rightarrow 10$ và chi phí là $|40 - 70| + |70 - 70| + |70 - 60| = 40$.

