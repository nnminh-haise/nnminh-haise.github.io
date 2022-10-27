
# Luyện tập

Kì thi học kì sắp diễn ra nên Tùng và Nhi quyết định lên kế hoạch ôn tập để đạt được kết quả thật cao. Có $n$ bài tập để Tùng và Nhi có thể cùng nhau ôn luyện được đánh số từ $1$ đến $n$. Tùng và Nhi quyết định phải làm tối thiểu $k$ bài tập thì mới được nghỉ ngơi. Nhưng Tùng chỉ làm những bài có chỉ số chia hết cho $a$ còn Nhi chỉ làm những bài có chỉ số chia hết cho $b$ và sẽ bỏ qua những bài có chỉ số cùng chia hết cho cả $a, b$.

***Yêu cầu:*** Đếm số bài tập mà Tùng và Nhi sẽ làm và xác định liệu cả hai có hoàn thành mục tiêu làm tối thiểu $k$ bài tập đã đề ra hay không.

## Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $q \; (1 \le q \le 10)$ - số truy vấn cần trả lời. Mỗi truy vấn có dạng như sau:

    - Mỗi truy vấn gồm $4$ số nguyên dương $n, a, b, k \; (1 \le n, k \le 10^{18}, 1 \le a, b \le 10^6)$ theo thứ tự như đã mô tả.

## Output - Dữ liệu ra

- Gồm $q$ dòng, mỗi dòng là câu trả lời tương ứng với truy vấn nếu Tùng và Nhi có thể làm được tối thiểu $k$ bài tập in `Yes`, ngược lại in `No`.

## Subtasks

- Subtask $1$ ($50\%$ số điểm) thỏa mãn:

    - $1 \le n, k \le 10^6$.
    - $1 \le a, b \le 10^3$.

- Subtask $2$ ($50\%$ số điểm còn lại) không có yêu cầu gì thêm. 

## Sample - Ví dụ

#### Input:

```
1
6 2 3 3
```

#### Output:

```
Yes
```

#### Explanation:

Tùng và Nhi làm các bài tập $2, 3, 4$ vừa đủ $3$ bài tập nên cả hai đã hoàn thành mục tiêu đề ra.