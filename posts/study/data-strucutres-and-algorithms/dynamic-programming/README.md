
# QUY HOẠCH ĐỘNG - DYNAMIC PROGRAMMING

---

> *Khi giải quyết các bài toán, phần lớn sẽ yêu cầu kết hợp rất nhiều kiến thức với nhau để đưa ra lời giải. Với khả năng giải quyết được chìa khóa của bài toán có liên quan, việc làm chủ và áp dụng quy hoạch động sẽ giúp cải thiện tư duy và suy luận của cậu rất nhiều.*

*Đây là bài viết được dịch lại tại [Topcoder](https://www.topcoder.com/thrive/articles/Dynamic%20Programming:%20From%20Novice%20to%20Advanced).*

---

## Mở đầu về quy hoạch động - Beginner Level

Quy hoạch động (gọi tắt là DP) là một kỹ năng giải thuật thường được dựa trên **công thức truy hồi** và **trạng thái bắt đầu**.

**Lời giải của bài toán con** sẽ được xây dựng dựa trên lời giải của bài toán con nhỏ hơn.

Lời giải bằng quy hoạch động có **độ phức tạp thời gian đa thức**, đảm bảo cho ra kết quả nhanh hơn các thuật toán khác như duyệt trâu, quay lui, vân vân.

### Bài toán đồng xu

Cho một danh sách các đồng xu có $n$ mệnh giá $V_1, V_2, V_3, \ldots, V_n$ (*các giá trị này là các số nguyên dương*) và cho một số nguyên dương $S$.

***Yêu cầu:*** Tìm số lượng đồng xu ít nhất sao cho tổng số tiền chọn ra đúng bằng $S$. Lưu ý rằng mỗi loại mệnh giá có vô hạn số lượng đồng xu. Nếu không thể xác định được cách chọn nào in $-1$.

**Ví dụ:** Với danh sách các mệnh giá như sau và $S = 13$.

<div id="table">

| Chỉ số | 0 | 1 |2 | 3 | 4 | 5 | 6 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| Mệnh giá | 2 | 3 | 5 | 7 | 20 | 100 | 500 |

</div>

Có thể chọn ra ít nhất $3$ đồng xu như sau:

- Hai đồng xu mệnh giá $3$.
- Một đồng xu mệnh giá $7$.

Như vậy tổng số tiền sẽ là $3 + 3 + 7 = 13 = S$.

### Lời giải quy hoạch động

*Đối với trường hợp số lượng mệnh giá nhỏ thì có thể áp dụng các thuật toán quay lui để tìm lời giải cho bài toán. Song đối với giá trị $n$ lớn thì sẽ cần một lời giải tối ưu hơn!*

Việc bắt tay vào giải quyết bài toán trên là **rất khó** đối với người mới bắt đầu. Dĩ nhiên, điều tương tự cũng sẽ được áp dụng cho các bài toán khác đó là: **"Không đi tìm lời giải cho bài toán lớn ngay khi đọc xong đề bài!"**

Điều cần làm chính là tìm ra một bài toán cùng dạng nhưng đơn giản nhất sao cho việc xác định câu trả lời cho bài toán đơn giản này có thể được thực hiện ngay! Đây sẽ là nền tảng để xây dựng lời giải cho bài toán lớn hơn!

#### Cách tiếp cận thứ nhất

**"Trạng thái"** là gì? Đây là thuật ngữ được sử dụng để chỉ đến thông tin của một lời giải, một lời giải con của bài toán lớn.

Ví dụ với bài toán trên, trạng thái của bài toán có thể là: danh sách các mệnh giá trên với tổng số tiền cần đạt được là $i \; (i \le S)$. Hay trạng thái nhỏ hơn nữa sẽ là trạng thái có tổng số tiền cần đạt được là $j \; (j < i)$.

Để tìm được lời giải cho trạng thái $i$ thì cần phải tìm được lời giải cho tất cả các trạng thái $j \; (j < i)$. Sau khi tìm được lời giải cho trạng thái $i$, nghĩa là số lượng đồng xu ít nhất có tổng bằng $i$ thì sẽ giải quyết được bài toán có trạng thái lớn hơn $1$ bậc chính là trạng thái $i + 1$.

***Làm sao để xác định lời giải cho trạng thái i?***

> Giả sử, ở trạng thái $i$ tìm được số đồng xu ít nhất có tổng tiền bằng $i$ là $q$.

Với mọi đồng xu $j : V_j \le i$, gọi $m$ là giá trị số lượng đồng xu ít nhất có tổng tiền bằng $i - V_j$ (*theo giả thuyết giá trị này đã được tìm ra trước đó*). Nếu $m + 1 < q$ nghĩa là bé hơn số lượng đồng xu ít nhất có tổng tiền bằng $i$ **đã tìm được trước đó**. Như vậy, vừa tìm ra kết quả tối ưu hơn cho trạng thái $i$ đó là $m + 1$.

Một ví dụ cụ thể để dễ hình dung: Với các mệnh giá $1, 3, 5$ và tổng $S = 11$.

- Ban đầu có thể mặc định số lượng đồng xu cần thiết cho mọi trạng thái sẽ là vô cực, sau đó kết quả của trạng thái sẽ được **cập nhật** bởi kết quả tối ưu hơn.

- Ở trạng thái $0$, thấy rằng không có mệnh giá nào bé hơn hoặc bằng $0$ nên không có cách chọn các đồng xu nào. Nói cách khác kết quả của trạng thái $0$ là $0$.

- Ở trạng thái $1$, thấy rằng có mệnh giá $V_1 = 1$ bé hơn hoặc bằng $1$. Khi đó trạng thái $1 - V_1 = 1 - 1 = 0$ có kết quả là $0$ sẽ được thêm $1$ đồng xu mệnh giá $1$. Do vậy, kết quả của trạng thái $1$ là $0 + 1 = 1$.

- Ở trạng thái $2$, thấy rằng có mệnh giá $V_1 = 1$ bé hơn hoặc bằng $2$. Khi đó trạng thái $2 - V_1 = 2 - 1 = 1$ có kết quả là $1$ sẽ được thêm $1$ đồng xu mệnh giá $1$. Do vậy, kết quả của trạng thái $2$ là $1 + 1 = 2$.

- Ở trạng thái $3$, thấy rằng có mệnh giá $V_1 = 1$ và mệnh giá $V_2 = 3$ bé hơn hoặc bằng $3$. Khi đó xét hai trạng thái:

    1. Trạng thái $3 - V_1 = 3 - 1 = 2$ có kết quả là $2$ sẽ được cộng thêm $1$ đồng xu mệnh giá $1$. Do vậy, kết quả của trạng thái $3$ lúc này sẽ là $2 + 1 = 3$.

    2. Trạng thái $3 - V_2 = 3 - 3 = 0$ có kết quả là $0$ sẽ được cộng thêm $1$ đồng xu mệnh giá $3$. Do vậy, kết quả của trạng thái $3$ lúc này sẽ là $\min(3, 0 + 1 = 1) = 1$.

    Vậy, kết quả cuối cùng và tối ưu nhất cho trạng thái $3$ sẽ là $1$.

- Ở trạng thái $4$, thấy rằng có mệnh giá $V_1 = 1$ và mệnh giá $V_2 = 3$ bé hơn hoặc bằng $4$. Khi đó xét hai trạng thái:

    1. Trạng thái $4 - V_1 = 4 - 1 = 3$ có kết quả là $1$ sẽ được cộng thêm $1$ đồng xu mệnh giá $1$. Do vậy, kết quả của trạng thái $4$ lúc này sẽ là $1 + 1 = 2$.

    2. Trạng thái $4 - V_2 = 4 - 3 = 1$ có kết quả là $1$ sẽ được cộng thêm $1$ đồng xu mệnh giá $1$. Do vậy, kết quả của trạng thái $4$ lúc này sẽ là $\min(2, 1 + 1 = 2) = 2$.

    Vậy, kết quả cuối cùng và tối ưu nhất cho trạng thái $4$ sẽ là $2$.

- Tiếp tục lặp lại quá trình này với các trạng thái $5, 6, 7, \ldots, 11$.

***Mã giả:***

*Gọi $f(i)$ là số lượng đồng xu ít nhất cần chọn để có tổng số tiền bằng $i$.*

```
Khởi tạo f(i) = vô cực với mọi i <= S và f(0) = 0.

Với mọi i từ 1 đến S {
    Với mọi mệnh giá V[j] từ 1 đến n {
        Nếu V[j] <= i và f(i - V[j]) + 1< f(i) thì {
            f(i) = f(i - V[j]) + 1
        }
    }
}

Kết quả bài toán chính là f(S).
```

***Bảng trạng thái và kết quả của ví dụ trên:***

<div id="table">

| Trạng thái | Số lượng đồng xu ít nhất | Giá trị của đồng xu (trạng thái đứng trước) |
| :---: | :---: | :---: |
| 0 | 0 |  |
| 1 | 1 | 1 (0) |
| 2 | 2 | 1 (1) |
| 3 | 1 | 3 (0) |
| 4 | 2 | 1 (3) |
| 5 | 1 | 5 (0) |
| 6 | 2 | 3 (3) |
| 7 | 3 | 1 (6) |
| 8 | 2 | 3 (5) |
| 9 | 3 | 1 (8) |
| 10 | 2 | 5 (5) |
| 11 | 3 | 1 (10) |

</div>

Với bảng này, việc xác định được cách chọn các đồng xu ở từng trạng thái rất dễ dàng. Ví dụ ở trạng thái $11$ cần $3$ đồng xu, cụ thể là $1$ đồng xu mệnh giá $1$ và $2$ đồng xu mệnh giá $2$.

#### Cách tiếp cận thứ hai

Sau khi hiểu phương pháp quy hoạch động cơ bản này thì có thể xem xét một phương pháp khác như sau: Ý tưởng chính của phương pháp này là cập nhật lại kết quả của trạng thái $i$ khi một kết quả mới được tìm ra tối ưu hơn kết quả cũ.

Cụ thể, bắt đầu với trạng thái $0$ có kết quả là $0$. Xét lần lượt các mệnh giá $V_1 = 1, V_2 = 3, V_3 = 5$, ở mỗi mệnh giá, lần lượt thêm đồng mệnh giá $1$ vào các trạng thái đã tìm được kết quả. Trong trường hợp này chỉ có trạng thái $0$ đã tìm được kết quả, khi đó trạng thái $0$ được cộng thêm đồng mệnh giá $1$ sẽ được $0 + 1 = 1$. Vì trạng thái $1$ chưa được tìm ra kết quả nên đây sẽ là kết quả mới của trạng thái $1$, đánh dấu $f(1) = 1$. Tiếp tục thêm đồng mệnh giá $1$ vào trạng thái $1$, khi đó trạng thái $1$ được cộng thêm mệnh giá $1$ sẽ được $1 + 1 = 2$. Vì trạng thái $2$ chưa tìm ra kết quả nên đây sẽ là kết quả mới của trạng thái $2$, đánh dấu $f(2) = 2$.

> *Bảng mô tả kết quả trạng thái sau khi cập nhật bởi đồng mệnh giá $1$.*

<div id="table">

| Trạng thái | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| Kết quả | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |

</div>

Tiếp tục với đồng mệnh giá $3$, lần lượt thêm đồng mệnh giá $3$ vào các trạng thái đã tìm được kết quả.

- Ở trạng thái $0$, khi thêm đồng mệnh giá $3$ vào sẽ được $0 + 3 = 3$. Lúc này, trạng thái $3$ đang có kết quả là $3$, nghĩa là được tạo bởi $3$ đồng mệnh giá $1$. Mặt khác, vừa tìm được kết quả mới là trạng thái $3$ có thể được tạo bởi $1$ đồng mệnh giá $3$. Do vậy, cập nhật lại kết quả của trạng thái $3$ là $1$: $f(3) = 1$.
- Ở trạng thái $1$, khi thêm đồng mệnh giá $1$ vào sẽ được $1 + 3 = 4$. Lúc này, trạng thái $4$ đang có kết quả là $4$, nghĩa là được tạo bởi $4$ đồng mệnh giá $1$. Mặt khác, vừa tìm được kết quả mới là trạng thái $4$ có thể được tạo bởi $2$ đồng có mệnh giá $1$ và $3$. Do vậy, cập nhật lại kết quả của trạng thái $4$ là $2$: $f(4) = 2$.
- Làm tương tự với các trạng thái $2, 3, 4, \ldots, S$.

> *Bảng mô tả kết quả trạng thái sau khi cập nhật bởi đồng mệnh giá $3$.*

<div id="table">

| Trạng thái | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| Kết quả | 0 | 1 | 2 | 1 | 2 | 3 | 2 | 3 | 4 | 3 | 4 | 5 |

</div>

Cuối cùng, lặp lại quá trình trên cho đồng mệnh giá $5$.

- Ở trạng thái $0$, khi thêm đồng mệnh giá $5$ vào sẽ được $0 + 5 = 5$. Lúc này, trạng thái $5$ đang có kết quả là $3$, nghĩa là được tạo bởi $2$ đồng mệnh giá $1$ và $1$ đồng mệnh giá $3$. Mặt khác, vừa tìm được kết quả mới là trạng thái $5$ có thể được tạo bởi $1$ đồng mệnh giá $5$. Do vậy, cập nhật lại kết quả của trạng thái $5$ là $1$: $f(5) = 1$.
- Ở trạng thái $1$, khi thêm đồng mệnh giá $5$ vào sẽ được $1 + 5 = 6$. Lúc này, trạng thái $6$ đang có kết quả là $2$, nghĩa là được tạo bởi $2$ đồng mệnh giá $3$. Mặt khác, vừa tìm được kết quả mới là trạng thái $6$ có thể được tạo bởi $1$ đồng có mệnh giá $1$ và $1$ đồng mệnh giá $5$ Vì số lượng đồng xu cần ở cả hai kết quả cho ra đều là $2$. Do vậy, không cần cập nhật lại kết quả của trạng thái $6$.
- Làm tương tự với các trạng thái $2, 3, 4, \ldots, S$.

> *Bảng mô tả kết quả trạng thái sau khi cập nhật bởi đồng mệnh giá $5$.*

<div id="table">

| Trạng thái | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| Kết quả | 0 | 1 | 2 | 1 | 2 | 1 | 2 | 3 | 2 | 3 | 2 | 3 |

</div>

Và kết quả cuối cùng thu được chắc chắn giống với phương pháp ban đầu được đề cập đến.

---

## Công thức truy hồi

Một chủ đề quan trọng trong quy hoạch động đó là làm sao để chuyển từ trạng thái này sang trạng thái khác. Chủ đề này sẽ xoay quanh việc thiết kế công thức truy hồi cho giải thuật quy hoạch động. Đây là cầu nối để liên kết trạng thái nhỏ hơn sang trạng thái lớn hơn của bài toán.

### Bài toán dãy con không giảm dài nhất

Để dễ bàn luận thì xét một ví dụ nhỏ sau: Cho một dãy $A$ có $n$ phần tử $a_1, a_2, a_3, \ldots, a_n$ là các số nguyên dương. 

***Yêu cầu:*** Tìm độ dài của dãy con không giảm dài nhất của dãy $A$.

### Trạng thái của bài toán

Như đã nói ở trước, đầu tiên cần phải xác định được trạng thái của bài toán con từ đó sẽ tìm được lời giải cho bài toán lớn. *Chú ý rằng, phần lớn trạng thái của bài toán sẽ phụ thuộc vào trạng thái nhỏ hơn và độc lập với trạng thái lớn hơn.*

Gọi **$dp(i)$ là độ dài của dãy con không giảm dài nhất với $a_i$ là phần tử cuối cùng của dãy**. Phần được in đậm là "trạng thái" của bài toán và $dp(i)$ là kết quả của trạng thái $i$.

Chú ý rằng các trạng thái $j$ với $j < i$ thì trạng thái $i$ sẽ độc lập với $j$, nghĩa là khi $i$ thay đổi thì các trạng thái $j$ sẽ không bị thay đổi.

Có thể dễ dàng rút ra nhận xét: **"Nếu dãy chỉ có $1$ phần tử thì chắc chắn độ dài của dãy con không giảm dài nhất sẽ là $1$"**. Từ nhận xét này, kết hợp với cách định nghĩa trạng thái của bài toán thì có thể rút ra rằng: **"Nêu coi mọi phần tử $a_i$ là một dãy có độ dài $1$ thì $dp(i) = 1 \; \forall i \in [1, n]$"** và đây cũng chính là trạng thái "cơ bản" của bài toán.

Vậy, để chuyển từ trạng thái $j$ sang trạng thái $i$ với $j < i$ thì cần có nhận xét sau: 

- Giả sử, hiện tại đã có một dãy không giảm [1, 3, 4, 5, 7, 9] có độ dài $6$ phần tử và đang xét đến phần tử thứ $7$  là $a_7 = 13$. Điều này đồng nghĩa $dp(6) = 6$ và đang tìm kết quả cho $dp(7)$. Lúc này, **phần tử thứ $7$ sẽ có thể là phần tử "cuối cùng" của dãy trên nếu $a_7 \ge a_6$ và điều này hoàn toàn đúng với ví dụ trên!**
- Mặt khác, trong các trường hợp ngược lại, nếu $a_7 < a_6$ thì có thể kết luận rằng **không thể nhận $a_7$ làm phần tử cuối cùng của dãy không giảm có độ dài $6 + 1 = 7$ được.**

Như vậy, với bài toán trên, khi chuyển từ trạng thái $j$ sang trạng thái $i$ với $j < i$ thì sẽ thực hiện như sau: Với mọi $j < i$ xét:

- Nếu $a_j \le a_i$ thì $dp(i) = \max(dp(i), dp(j) + 1)$. *Điều này có nghĩa rằng, kết quả của trạng thái $i$ sẽ được so sánh với kết quả được tính từ trạng thái $j$. Nếu kết quả vừa tính được tối ưu hơn thì sẽ ghi nhận kết quả đó, ngược lại sẽ không thay đổi kết quả của trạng thái $i$.*
- Ngược lại, nếu $a_j > a_i$ thì theo định nghĩa của trạng thái $i$ thì $a_i$ không thể là phần tử cuối cùng của dãy con chung dài nhất với $i$ phần tử đầu tiên của dãy $A$. Khi đó, kết quả của trạng thái sẽ được không được cập nhật.

Đây là quá trình sẽ diễn ra khi chuyển từ trạng thái $j$ sang trạng thái $i \; (j < i)$. Quá trình này sẽ được lặp đi lặp lại cho đến khi bài toán lớn tìm được kết quả.

Ví dụ với dãy $A = [5, 3, 4, 8, 6, 7]$ thì sẽ có được bảng trạng thái như sau:

<div id="table">

| Chỉ số | Độ dài của dãy con | Chỉ số của phần tử đứng trước phần tử cuối cùng |
| :---: | :---: | :---: |
| 1 | 1 | 1 (phần tử đầu tiên) |
| 2 | 1 | 2 (phần tử thứ hai) |
| 3 | 2 | 2 |
| 4 | 3 | 3 |
| 5 | 3 | 3 |
| 6 | 4 | 5 |

</div>

### Luyện tập thêm

Cho một đồ thị vô hướng $G$ có $N \; (1 \le N \le 1000)$ đỉnh và có trọng số dương.

***Yêu cầu:*** Tìm đường đi ngắn nhất từ đỉnh $1$ đến đỉnh $N$, nếu không có, in ra $-1$.

*Gợi ý:* Xét đỉnh $u$ (chưa được thăm), với mọi đường đi xuất phát từ đỉnh $1$ đến $u$ đã tìm được trước đó, chọn đường đi ngắn nhất.

> *Cậu hãy thử giải một số bài tập dưới đây để luyện tập thêm:*
>
> 1. [ZigZag – 2003 TCCC Semifinals 3](https://community.topcoder.com/tc?module=ProblemDetail&rd=4493&pm=1259).
> 2. [BadNeighbors – 2004 TCCC Round 4](https://community.topcoder.com/tc?module=ProblemDetail&rd=5009&pm=2402).
> 3. [FlowerGarden – 2004 TCCC Round 1](https://community.topcoder.com/tc?module=ProblemDetail&rd=5006&pm=1918).

---

## Quy hoạch động hai chiều - Intermediate Level

> *Một mức tao hơn của quy hoạch động chính là quy hoạch động hai chiều!*

### Bài toán nhặt táo

Trên một mảnh đất hình chữ nhật kích thước $n \times m$ được chia thành các ô vuông kích thước $1 \times 1$ và trên mỗi ô vuông sẽ có một số lượng quả táo nhất định (*số tự nhiên*).

***Yêu cầu:*** Bắt đầu từ ô vuông trên cùng bên trái, tại mỗi bước chỉ được sang phải hoặc đi xuống, tìm số lượng táo nhặt được nhiều nhất.

### Hướng giải

Cũng như các bài toán trên, khi xác định tiếp cận theo hướng quy hoạch động cần xác định được **trạng thái** của bài toán.

Trước tiên cần nhận xét đề bài: từ ô có tọa độ $(i, j)$ **có thể** đi sang các ô $(i + 1, j)$ và $(i, j + 1)$. Như vậy, cần phải **tối ưu hóa** số lượng táo nhặt được trước đó trước khi xét tới việc di chuyển đến ô khác.

Vậy có thể xác định trạng thái của bài toán này như sau: Gọi $dp(i, j)$ là số lượng táo nhiều nhất khi đi đến ô $(i, j)$. Với định nghĩa này kết hợp với nhận xét trên thấy rằng, có thể đến ô $(i, j)$ từ hai ô $(i - 1, j)$ và $(i, j - 1)$. Khi đi đến ô $(i, j)$ sẽ nhận được lượng táo là $a[i][j]$. Từ đây, công thức truy hồi của bài toán sẽ là:

$$dp(i, j) = \max(dp(i - 1, j), dp(i, j - 1)) + a[i][j]$$

*Vì có thể đến ô $(i, j)$ từ hai ô khác nhau, nên cần chọn ra ô có nhiều táo hơn! Để số lượng táo ở ô $(i, j)$ sẽ là số lượng táo của ô liền trước cộng với số táo có sẵn ở ô $(i, j)$.*

***Mã giả:***

```
Với mọi i từ 1 đến n {
    Với mọi j từ 1 đến m {
        dp(i, j) = max(dp(i - 1, j), dp(i, j - 1)) + a[i][j]
    }
}

Kết quả bài toán: dp(n, m)
```

**Lưu ý:** Các ô $(i - 1, j); (i, j - 1)$ có thể không hợp lệ (*nằm ngoài ma trận*). Do đó vậy cần chú ý xử lí tình huống này.

- Một cách xử lí đơn giản là kiểm tra tính hợp lệ của tọa độ các ô trước khi thực hiện tối ưu hóa ô $(i, j)$.
- Cách thứ hai chính là gán các ô nằm ngoài ma trận giá trị $0$, khi đó, công thức tối ưu sẽ đúng.

> *Cậu hãy thử giải một số bài tập dưới đây để luyện tập thêm:*
>
> 1. [AvoidRoads – 2003 TCO Semifinals 4](https://community.topcoder.com/tc?module=ProblemDetail&rd=4709&pm=1889).
> 2. [ChessMetric – 2003 TCCC Round 4](https://community.topcoder.com/tc?module=ProblemDetail&rd=4482&pm=1592).


<!-- TODO: continue the last two part! -->

---

## Tài liệu tham khảo

- [Tài liệu nguồn | topcoder](https://www.topcoder.com/thrive/articles/Dynamic%20Programming:%20From%20Novice%20to%20Advanced).

<style>

#table {
    margin-left: auto;
    margin-right: auto;
    width: max-content
}

</style>
