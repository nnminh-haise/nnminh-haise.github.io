
# Bài toán tìm kiếm - Searching

> *Tìm kiếm là một bài toán thường gặp ở trong lập trình nói chung và trong cuộc sống nói riêng. Chúng ta có thể tìm kiếm một số trong một dãy, hoặc tìm kiếm một cuốn sách trong tủ sách. Hai vấn đề trên đều giống nhau chỉ khác nhau về quy mô. Vậy hãy thử tìm hiểu xem có bao nhiêu cách giải bài toán tìm kiếm.*

---

## Bài toán tìm kiếm

Một cách tổng quát có thể phát biểu đơn giản bài toán tìm kiếm như sau: Trong một không gian tìm kiếm $X$ hữu hạn có $n$ phần tử được đánh số từ $1$ đến $n$. Cần tìm đối tượng $p$ ở trong $X$. Sẽ có hai trường hợp có thể xảy ra như sau:

- **Trường hợp $1$**: đối tượng $p$ có ở trong $X$, điều này cũng tương đương với việc bài toán tìm kiếm có nghiệm (thành công).
- **Trường hợp $2$**: đối tượng $p$ không có ở trong $X$, điều này cũng tương đương với việc bài toán tìm kiếm vô nghiệm (không thành công).

Trong lập trình có thể cụ thể hóa bài toán trên như sau: Cho một dãy $A$ có $n$ phần tử (*ở trong khuôn khổ bài viết này các đói tượng cần tìm là các số nguyên*) được đánh số từ $1$ đến $n$. Cần tìm giá trị $x$ có xuất hiện trong dãy $A$ hay không!

---

## Tìm kiếm tuần tự - Sequential Search

> *Trong khuôn khổ bài viết này không nhắc đến những hàm tìm kiếm có sẵn được built-in trong các ngôn ngữ lập trình. Thay vào đó sẽ đi tìm hiểu về chi tiết thuật toán!*

Tìm kiếm tuần tự là một phương pháp tìm kiếm đơn giản nhất. Theo đó, việc xét tuần tự các phần tử trong không gian tìm kiếm $X$ và kiếm tra tính giống nhau của hai đối tượng $x_i$ và $p$ sẽ cho ra kết quả của bài toán mong muốn.

Trong lập trình, cụ thể với bài toán trên, sử dụng vòng lặp trong các ngôn ngữ lập trình, duyệt tuần tự qua từng phần tử trong day $A$ và kiểm tra tính giống nhau của phần tử hiện tại và giá trị cần tìm $x$ sẽ thu được kết quả cần tìm.

```
sequentialSearch(arr, key) {
    result = false;

    for every item in arr {
        if (equal(item, key) == true) {
            result = true;
        }
    }

    return result;
}
```

*Trên đây là một mô hình cơ bản cho phương pháp tìm kiếm tuần tự. Tùy vào từng ngôn ngữ lập trình mà mô hình trên sẽ khác nhau. Song, mô hình trên sử dụng phương pháp "đặt cờ" có thể đung để xác định vị trí xuất hiện đối tượng cần tìm (nếu cần thiết).*

Một lời giải gợi ý bằng `C++` và `Python` cho bài toán đặt ra đầu bài:

***C++:***

```cpp
bool sequentialSearch(int *arr, const unsigned int n, int key) {
    bool result = true;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            result = true;
        }
    }

    return result;
}
```

***Python:***

```py
def sequentialSearch(arr: list, key: int):
    result = False
    
    for item in arr:
        if key == item:
            result = True
    
    return result
```

Với mô hình và cách cài đặt thuật toán như trên thì trong trường hợp **xấu nhất** thì sẽ kiểm tra tất cả các phần tử trong không gian tìm kiếm (dãy $A$). Với không gian tìm kiếm hữu hạn có $n$ phần tử thì sẽ cần tối đa $n$ phép toán để thu được kết quả bài toán.

Như vậy, độ phức tạp thời gian của thuật toán này là $O(n)$.

> *Đối với những bài toán có không gian tìm kiếm nhỏ thì thuật toán dễ dàng cho ra kết quả trong thời gian ngắn, nhưng sẽ gặp nhiều bất lợi về thời gian đối với không gian tìm kiếm có kích thước lớn hơn!*

---

## Tìm kiếm nhị phân - Binary Search

Trước khi bước sâu vào thuật toán tìm kiếm nhị phân, thì cần phải đặt đề bài vào một trường hợp đặc biệt: Không gian tìm kiếm cần phải được sắp xếp lại theo một tiêu chí nào đó mà từ tiêu chí này, có thể được sử dụng để xác định và so khớp các phần tử trong không gian tìm kiếm.

Cụ thể, trong bài toán đã nêu thì dãy $A$ sẽ cần được sắp xếp lại (tăng dần hoặc giảm dần tùy mục đích). Trong bài viết, ở thuật toán này thì dãy $A$ đã được sắp xếp theo thứ tự tăng dần.

Một ví dụ cụ thể cho dãy $A$ đã được sắp xếp theo thứ tự tăng dần như sau:

<div id="table1">

| Chỉ số | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| Giá trị | 0 | 3 | 7 | 12 | 14 | 20 | 31 | 40 | 56 | 71 | 89

</div>

Và giá trị cần tìm $x = 20$.

> Bài toán cụ thể đã rõ, bây giờ dựa trên ví dụ này xem xét tính chất sau.

Theo đề bài, luôn có: $a_1 \le a_2 \le a_4 \le \ldots \le a_n$. Khi đó, có thể dễ dàng suy ra hai tính chất sau:

- **Tính chất $1$**: nếu $a_i \le x$ thì $a_j \le x \; \forall \; 0 \le j < i$.
- **Tính chất $2$**: Nếu $a_i \ge x$ thì $a_j \ge x \; \forall \; i < j < n$.

**Tính chất $1$** có thể hiểu như sau: nếu phần tử $a_i$ ở vị trí $i$ bé hơn hoặc bằng giá trị cần tìm $x$ thì các phần tử trước đó chắc chắn sẽ bé hơn hoặc bằng $x$. Vì $a_i \le x$ mà $a_j \le a_i \; \forall \; j < i$. Nên theo tính chất bắc cầu thì $a_j \le x \; \forall \; j < i$.

**Tính chất $2$** có thể hiểu như sau: nếu phần tử $a_i$ ở vị trí $i$ lớn hơn hoặc bằng giá trị cần tìm $x$ thì các phần tử sau đó chắc chắn sẽ lớn hơn hoặc bằng $x$. Vì $a_i \ge x$ mà $a_j \ge a_i \; \forall \; j > i$. Nên theo tính chất bắc cầu thì $a_j \ge x \; \forall \; j > i$.

Nắm rõ được hai tính chất này, mô hình của thuật toán tìm kiếm nhị phân sẽ được xây dựng trên đó kết hợp với kỹ thuật chia để trị (*divide and conquer*).

### Mô hình thuật toán tìm kiếm nhị phân

Tùy theo các bài toán mà thuật toán sẽ có nhiều chỗ cần thay đổi và tùy biến lại sao cho phù hợp với cấu trúc dữ liệu cũng tiêu chí đánh giá các đối tượng cần tìm sẽ không giống nhau. Song đây vẫn là một mô hình chung cho thuật toán tìm kiếm nhị phân. Cụ thể như sau:

- ***Bước 1:*** Sắp xếp lại không gian tìm kiếm theo một tiêu chí nào đó mà có thể đánh giá được mối liên hệ giữa các đối tượng sau khi sắp xếp.
- ***Bước 2:*** Chia đôi không gian tìm kiếm thành hai nửa và chọn ra một phần tử đứng giữa để thực hiện so sánh và đánh giá với đối tượng cần tìm kiếm.
- ***Bước 3:*** Nếu đối tượng cần tìm kiếm "phù hợp" hơn với nửa trái thì sẽ bỏ đi nửa phải và ngược lại. Lúc này không gian tìm kiếm sẽ được thu gọn lại chỉ còn với một nửa tương ứng.
- ***Bước 4:*** Lặp lại hai bước 2 và 3 cho đến khi không gian tìm kiếm chỉ còn 1 phần tử hoặc không còn phần tử nào. Khi đó thực hiện kết luận dựa trên không gian tìm kiếm và giá trị cần tìm.

Với bài toán ví dụ trên, thuật toán tìm kiếm nhị phân cho bài toán sẽ được mô tả như sau:

- ***Bước 1:*** Sắp xếp lại dãy cần tìm theo chiều tăng dần của giá trị, chọn ra hai điểm `left` và `right` đại diện cho chỉ số đầu và chỉ số cuối của dãy cần tìm.
- ***Bước 2:*** Chọn ra một phần tử ở giữa xác định bởi công thức `a[mid] = (right - left) / 2 + left`.
- ***Bước 3:*** Nếu `a[mid]` bé hơn $x$, nghĩa là giá trị cần tìm sẽ từ vị trí $[mid + 1, right]$ bỏ đi phần $[left, mid]$. Ngược lại nếu `a[mid]` lớn hơn hoặc bằng $x$, nghĩa là giá trị cần tìm sẽ từ vị trí $[left, mid]$ bỏ đi phần $[mid + 1, right]$.
- ***Bước 4:*** Lặp lại bước 2 và 3 cho đến khi dãy chỉ còn 1 phần tử hoặc không tìm được phần tử nào.

***C++:***

```cpp
int binarySearch(const int *a, unsigned int left, unsigned int right, int key) {
    if (left > right) {
        return -1;
    }

    if (left == right) {
        return (key == a[left] ? left : -1);
    }

    int mid = (right - left) / 2 + left;
    if (key <= a[mid]) {
        return binarySearch(a, left, mid, key);
    }
    return binarySearch(a, mid + 1, right, key);
}
```

*Hoặc:*

```cpp
int binarySearch(const int *a, unsigned int left, unsigned int right, int key) {
    int l = left, r = right;

    while (l < r) {
        int mid = (r - l) / 2 + l;
        if (key <= a[mid]) {
            if (key == a[mid]) {
                return mid;
            }
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return (key == a[l] ? l : -1);
}
```

***Python:***

```python
def binarySearch(a, left, right, key):
    if (left > right):
        return -1
    
    if (left == right):
        return left if a[left] == key else -1
    
    mid = (right - left) // 2 + left
    if (key <= a[mid]):
        return binarySearch(a, left, mid, key)
    
    return binarySearch(a, mid + 1, right, key)
```

*Hoặc:*

```py
def binarySearch(a, left, right, key):
    l, r = left, right
    
    while l < r:
        mid = (r - l) // 2 + l
        
        if (key <= a[mid]):
            if (key == a[mid]):
                return mid
            
            r = mid
        else:
            l = mid + 1
    
    return l if key == a[l] else -1
```

---


## Tổng kết

Trên đây là hai thuật toán tìm kiếm thông dụng và cơ bản nhất. Ngoài hai thuật toán trên còn có các công cụ và thuật toán tìm kiếm khác như hash, binary search tree, vân vân. Song hai thuật toán trên là cơ bản và đóng góp những kiến thức và giá trị bền vững cho nhành.

---

## Tài liệu tham khảo

1. [Bài toán tìm kiếm - Searching | DSAP Textbook](https://studyland.edu.vn/material/view?id=883)
2. [Thuật toán tìm kiếm nhị phân | VNOI](https://vnoi.info/wiki/algo/basic/binary-search.md)

<!-- CSS styling -->

<style>

#table1 {
    margin-left: auto;
    margin-right: auto;
    width: max-content
}

</style>

