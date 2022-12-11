
# C Vacation | DP Contest | Atcoder

> *Nguồn: [C | DP Contest | Atcoder](https://atcoder.jp/contests/dp/tasks/dp_c).*

Kì nghỉ hè của Taro sẽ bắt đầu vào ngày mai và anh ấy đã quyết định lên kế hoạch cho nó từ bây giờ.

Kì nghỉ hè sẽ diễn ra $n$ ngày. Và mỗi ngày thứ $i \; (1 \le i \le n)$ của kì nghỉ hè, Taro sẽ chọn một trong các hoạt động sau và làm nó vào ngày hôm ấy.

- `A`: bơi lội và được $a_i$ điểm hạnh phúc.
- `B`: bắt bọ cánh cứng ở sau núi và được $b_i$ điểm hạnh phúc.
- `C`: làm bài tập về nhà và được $c_i$ điểm hạnh phúc.

Taro sẽ trở nên chán một cách nhanh chóng nếu anh ấy làm hai hoạt động giống nhau trong hai hoặc nhiều ngày liên tục.

***Yêu cầu:*** Trong suốt $n$ ngày, hãy tính số điểm hạnh phúc lớn nhất mà Taro có thể nhận được.

## Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $n \; (1 \le n \le 10^5)$.
- $n$ dòng tiếp theo, mỗi dòng gồm ba số nguyên dương $a_i, b_i, c_i$ lần lượt là số điểm hành phúc của các hoạt động `A, B` và `C` vào ngày thứ $i$.

## Output - Dữ liệu ra

- Một số nguyên duy nhất là tổng số điểm hạnh phúc lớn nhất mà Taro có thể nhận được.

## Sample - Ví dụ

#### Input:

```
3
10 40 70
20 50 80
30 60 90
```

#### Output:

```
210
```

#### Input:

```
7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1
```

#### Output:

```
46
```

