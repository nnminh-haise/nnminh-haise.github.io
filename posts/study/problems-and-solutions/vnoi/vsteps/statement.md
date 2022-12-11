
# Bậc thang - VSTEPS

> *Nguồn: [VSTEPS | VNOI](https://oj.vnoi.info/problem/vsteps).*

Bờm chơi trò chơi điện tử Lucky Luke đến màn phải điều khiển Lucky leo lên một cầu thang gồm $n$ bậc.

Các bậc thang được đánh số từ $1$ đến $n$ từ dưới lên trên. Lucky có thể đi lên một bậc thang, hoặc nhảy một bước lên hai bậc thang. Tuy nhiên một số bậc thang đã bị thủng do cũ kỹ và Lucky không thể bước chân lên được. Biết ban đầu, Lucky đứng ở bậc thang số $1$ (bậc thang số $1$ không bao giờ bị thủng).

***Yêu cầu:*** Có bao nhiêu cách để Lucky leo hết được cầu thang? (nghĩa là leo đến bậc thang thứ $n$).

## Input - Dữ liệu vào

- Dòng thứ nhất gồm hai số $n$ và $k$ như mô tả.
- Dòng thứ hai gồm $k$ số cho biết chỉ số của các bậc thang bị hỏng theo thứ tự tăng dần.

## Output - Dữ liệu ra

- In ra phần dư của số cách Lucky leo hết cầu thang khi chia cho $14062008$.

## Sample - Ví dụ

#### Input:

```
4 2
2 3
```

#### Output:

```
0
```

#### Input:

```
90000 1
49000
```

#### Output:

```
4108266
```
