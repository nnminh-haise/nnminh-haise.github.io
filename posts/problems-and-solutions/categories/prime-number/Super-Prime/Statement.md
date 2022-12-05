
# Super prime number -  Số siêu nguyên tố

Số nguyên tố là số lớn hơn $1$ và chỉ có hai ước số là $1$ và chính nó. Ví dụ các số $2, 3, 5, 7, 11, \dots$ là các số nguyên tố. Số siêu nguyên tố là số mà mỗi lần bỏ đi một chữ số ở phía trước của số đó thì phần còn lại vẫn là một số nguyên tố. Ví dụ như số $23$ là một số siêu nguyên tố vì khi bỏ đi số $2$ ở phía trước thì phần còn lại là số $3$ vẫn là một số nguyên tố.

***Yêu cầu:*** Cho một số nguyên $k$ có $10$ chữ số. Kiểm tra số đã cho có phải là số siêu nguyên tố hay không.

## Input - Dữ liệu vào

- Một số nguyên $k$ duy nhất.

## Output - Dữ liệu ra

- In ra `True` nếu $k$ là số siêu nguyên tố và `False` trong trường hợp ngược lại.

## Subtasks

- Subtask $1$ ($50\%$ số điểm) thỏa mãn: số $k$ có tối đa $5$ chữ số.
- Subtask $2$ ($50\%$ số điểm) không có ràng buộc gì thêm.

## Sample - Ví dụ

#### Input:

```
23
```

#### Output:

```
True
```

#### Explanation:

Số $23$ là một số nguyên tố. Khi bỏ đi số $2$ ta được số $3$ cũng là một số nguyên tố. Vậy số $23$ là số siêu nguyên tố.
