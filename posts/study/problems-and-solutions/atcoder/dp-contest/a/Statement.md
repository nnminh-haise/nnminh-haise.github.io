
# A Frog 1 | DP Contest | Atcoder

> *Nguồn: [A | DP Contest | Atcoder](https://atcoder.jp/contests/dp/tasks/dp_a)*

Có $n$ hòn đá được đánh số từ $1$ đến $n$. Với mỗi hòn đá thứ $i$ sẽ có độ cao $h_i$. Có một chú ếch đang ở trên hòn đá $1$. Chú ếch sẽ nhảy từ hòn đá này sang hòn đá khác cho đến khi đến được hòn đá $n$. Mỗi lần, chú ếch có thể nhảy từ hòn đá $i$ sang hòn đá $i + 1$ hoặc hòn đá $i + 2$. Và chi phí sẽ là chênh lệch chiều cao giữa hai hòn đá mà chú ếch vừa di chuyển.

***Yêu cầu:*** Đưa ra chi phí nhỏ nhất có thể để chú ếch từ hòn đá $1$ di chuyển sang hòn đá $n$.

## Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n \; (2 \le n \le 10^5)$ - là số lượng hòn đá.
- Dòng thứ hai là $n$ số nguyên $h_1, h_2, h_3, \ldots, h_n \; (1 \le h_i \le 10^4)$.

## Output - Dữ liệu ra

- Chi phí nhỏ nhất để chi chuyển từ hòn đá $1$ đến hòn đá $n$.

## Sample - Ví dụ

#### Input:

```
4
10 30 40 20
```

#### Output:

```
30
```

#### Explanation:

Hành trình di chuyển của chú ếch sẽ là $1 \rightarrow 2 \rightarrow 4$ và chi phí là $|10 - 30| + |30 - 20| = 30$.

#### Input:

```
6
30 10 60 10 60 50
```

#### Output:

```
40
```

#### Explanation:

Hành trình di chuyển của chú ếch sẽ là $1 \rightarrow 3 \rightarrow 5 \rightarrow 6$ và chi phí là $|30 - 60| + |60 - 60| + |60 - 50| = 40$.

