
# Hàm trong C++

> *Trong toán học có hàm số, hàm lượng giác, hàm hợp. Vậy trong lập trình có hàm gì?*

Trong lập trình, sẽ có những lúc những câu lệnh giống nhau sẽ được lặp lại nhiều lần. Việc viết lại những câu lệnh đã viết trước đó trong cùng một đoạn code sẽ tốn nhiều thời gian và khiến cho tổng thể đoạn code trông rất lê thê và dài dòng. Để giải quyết vấn đề này thì điều nên làm chính là sử dụng hàm để thể hiện những câu lệnh được lặp lại, sau đó mỗi khi cần chỉ cần thực hiện lời gọi hàm.

## Khái niệm chung

Hàm (*function*) là một tập hợp các câu lệnh thực hiện một nhiệm vụ nào đó.

Giống như toán học, hàm số sẽ trả về kết quả của phép tính thì đối với hàm ở trong ngôn ngữ lập trình nói chung cũng có thể trả về một giá trị bất kì, tùy thuộc vào mục đích của người viết, song cũng có thể không trả về bất cứ giá trị gì. Đối với những hàm như vậy thường sẽ được gọi là một thủ tục.

Đối với ngôn ngữ lập trình C/C++ hàm sẽ có cấu trúc như sau:

```cpp
<kiểu dữ liệu> <tên hàm> (<các tham số>) {
    <các câu lệnh>;
    return <giá trị trả về>;
}
```

***Ví dụ 1:*** Hàm thực hiện tính phép tính $n^3$ với $n$ là một số nguyên dương bé hơn $10^3$.

```cpp
int cube(int n) {
    return n * n * n;
}
```

***Ví dụ 2:*** Hàm thực hiện in ra $10$ lần cụm từ "Thank you!".

```cpp
void print() {
    for (int i = 0; i < 10; ++i) {
        cout << "Thank you!\n";
    }
    return;
}
```

## Hướng dẫn sử dụng hàm

> *Với cấu trúc như vậy, ví dụ như vậy, nhưng khi bắt tay vào viết một hàm theo ý muốn thì cần nắm bắt được những gì?*

Như đã nói, hàm được sinh ra để thực hiện một nhiệm vụ nào đó tùy thuộc vào mong muốn của người viết. Do vậy trước khi bắt tay vào viết hàm, điều tiên quyết cần phải có chính là xác định được nhiệm vụ của hàm!

Hiểu rõ hàm được viết ra để làm những gì với mục đích gì, sử dụng trong hoàn cảnh nào sẽ giúp việc viết hàm trở nên rõ ràng và dễ dàng hơn!

Sau khi xác định được nhiệm vụ hay chức năng của hàm cần viết. Dựa trên điều đó, lần lượt xác định những yếu tố sau:

- **Kiểu dữ liệu của hàm:** Đây là kiểu dữ liệu của giá trị mà hàm số sẽ trả về. Hoặc có thể hiểu là kiểu dữ liệu của cả hàm số. Đối với các thủ tục (hàm không trả về giá trị) thì không cần yếu tố này! Lúc này kiểu dữ liệu của hàm sẽ là `void`.
- **Các tham số cần sử dụng:** Các câu lệnh trong hàm thường sẽ thao tác với dữ liệu. Do đó, các tham số này đóng vai trò quản lí dữ liệu và đôi khi quyết định nhiều yếu tố phụ của hàm. Sự xuất hiện của các tham số này là không bắt buộc.
- **Các câu lệnh trong hàm:** Từ nhiệm vụ của hàm đã được xác định trước đó, xác định những câu lệnh cần viết sao cho tối ưu và trả về giá trị mong muốn. Dĩ nhiên nếu hàm không làm gì thì cũng chẳng cần câu lệnh nào và cũng chẳng cần viết hàm làm gì!

Bên cạnh những yếu tố trên thì cũng có những điểm cần lưu ý sau:

- ***Tham trị*** (*Tham số truyền giá trị*): Đây là kiểu tham số thường gặp. Mỗi khi có *lời gọi hàm* thì chương trình sẽ **tạo ra một biến mới (bản sao)**, **sao chép giá trị** được truyền vào. Và tất cả các thay đổi sẽ chỉ tác động lên bản sao này!

- ***Tham biến*** (*Tham số truyền biến hoặc tham chiếu*): Khác với tham trị, thay vì tạo ra một biến mới là bản sao của biến được truyền vào thì tham biến sẽ là một **biến tham chiếu** (*reference variable*) chiếu tới biến được truyền vào. Do vậy, khi thực hiện lời gọi hàm không thể truyền vào một **giá trị hằng** (*literal*) mà phải là một biến.
    *Ví dụ:* `void swap(int &a, int &b) {}`.

- ***Tham số truyền con trỏ:*** Tương tự, thay vì truyền vào một biến hay một biến tham chiếu thì có thể truyền một **con trỏ**. Và con trỏ này sẽ trỏ đến biến được truyền vào.
    *Ví dụ:* `void swap(int *a, int *b) {}`.

## Một số ví dụ

Để có một cái nhìn thực tế hơn về hàm, xét các ví dụ dưới đây:

### Ví dụ 1: Đổi giá trị hai biến

***Yêu cầu:*** Viết hàm `swap(a, b)` có nhiệm vụ đổi giá trị của hai biến $a$ và $b$.

*Ví dụ:* với $a = 5, b = 10$, sau khi gọi hàm `swap(a, b)` thì giá trị của $a$ và $b$ lần lượt sẽ là $10$ và $5$.

<p style="text-align: center; font-weight: bold">Hướng dẫn:</p>

*Ngôn ngữ lập trình `C++` có hỗ trợ sẵn hàm `swap()`. Song với mục đích ví dụ và luyện tập thì nên tránh sử dụng hàm có sẵn!*

Từ ví dụ trên, có thể hình dung đơn giản rằng: Lấy giá trị của biến này gán cho biến kia và ngược lại. Với tư tưởng như vậy thì hàm sẽ thực hiện các bước sau:

- **Bước 1:** Lấy giá trị biến $b$ gán cho biến $a$.
- **Bước 2:** Lấy giá trị biến $a$ gán cho biến $b$.

> *Trông có vẻ hợp lí!*

Thử nháp kiểm tra thế nào? Với $a = 5, b = 10$ thì theo trình tự hai bước trên sẽ như sau:

- **Bước 1:** Lấy giá trị biến $b$ gán cho biến $a$. Lúc này, giá trị hai biến $a$ và $b$ sẽ là: $10$ và $10$.
- **Bước 2:** Lấy giá trị biến $a$ gán cho biến $b$. Lúc này, giá trị hai biến $a$ và $b$ sẽ là: $10$ và $10$.

> *Ủa gì kì? Đáng lẽ sau bước 2 thì giá trị hai biến $a$ và $b$ phải là $10$ và $5$ chứ?*

Trả lời cho câu hỏi này thì sau bước 1, giá trị ban đầu của biến $a$ là $5$ đã bị "**GHI ĐÈ**" bởi giá trị mới là $10$. Vì vậy mà giá trị $5$ này hoàn toàn biến mất!

Để giải quyết vấn đề này, giải pháp chính là sử dụng một biến phụ, lưu lại một bản sao của giá trị $a$ trước khi thực hiện ghi đè biến $a$ bởi 1 giá trị mới. Sau đó, sử dụng giá trị đã được lưu vào biến phụ trước đó và ghi đè ở biến thứ hai. Như vậy, với giải pháp này, lời giải cho bài toán trên sẽ thực hiện qua 3 bước như sau:

- **Bước 1:** Lưu tạm giá trị biến $a$ vào một biến phụ, tạm gọi là $tmp$.
- **Bước 2:** Lấy giá trị biến $b$ gán cho biến $a$.
- **Bước 3:** Lấy giá trị của biến $a$ được lưu tạm thời ở biến $tmp$ gán cho biến $b$.

Khi thử ở nháp sẽ như sau:

- Ban đầu: $a = 5, b = 10, tmp = 0$.
- Sau bước 1: $a = 5, b = 10, tmp = 5$.
- Sau bước 2: $a = 10, b = 10, tmp = 5$.
- Sau bước 3: $a = 10, b = 5, tmp = 5$.

Thấy rằng giá trị ở hai biến $a$ và $b$ đã được đổi chỗ cho nhau đúng với yêu cầu bài toán!

> *Bên cạnh cách làm này vẫn còn nhiều phương pháp khác!*

Vậy, nhiệm vụ của hàm và các thao tác sẽ thực hiện của hàm đã được xác định rõ, giờ cần xác định các yếu tố "giá trị trả về của hàm" và "các tham số được truyền vào hàm".

- Với giá trị trả về của hàm thì tương đối rõ. Dựa trên các tham tác sẽ thực hiện của hàm đã nói ở trên thì hàm sẽ không trả về giá trị gì. Lúc này kiểu dữ liệu của hàm sẽ là `void`.
- Còn đối với các tham số được truyền vào hàm cũng dễ thấy rằng chỉ cần hai biến $a$ và $b$. Nhưng, chú ý ở điểm **giá trị hai biến này sẽ được hoán đổi cho nhau**. Do vậy mà nếu chỉ truyền tham số như bình thường sẽ không cho ra được kết quả mong muốn. Vì vậy phải truyềm vào tham chiếu hoặc truyền vào con trỏ.

> *Các yếu tố cần thiết đã đủ, bắt tay vào code thôi!*

***Cách viết truyền con trỏ:***

```cpp
void swap(int *a, int *b) {
    int tmp = *a;
    a = b;
    *b = tmp;
    return;
}

int main() {
    int a = 5, b = 10;
    cout << "Before: " << a << " " << b << endl;
    swap(a, b);
    cout << "After : " << a << " " << b << endl;
    return 0;
}
```

***Cách viết truyền tham chiếu:***

```cpp
void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
    return;
}

int main() {
    int a = 5, b = 10;
    cout << "Before: " << a << " " << b << endl;
    swap(a, b);
    cout << "After : " << a << " " << b << endl;
    return 0;
}
```

### Ví dụ 2: Tính khoảng cách hai điểm A và B

***Yêu cầu:*** Cho hai điểm $A$ và $B$ có tọa độ lần lượt là $(x_A, y_A)$ và $(x_B, y_B)$. Tính khoảng cách hai điểm $A$ và $B$.

*Ví dụ:* Với $A(2, 4)$ và $B(6, 7)$ thì khoảng cách giữa hai điểm $A$ và $B$ hay độ dài đoạn $AB$ sẽ là $5$.

<p style="text-align:center; font-weight: bold">Hướng dẫn:</p>

Đây là một bài toán đơn giản, chỉ cần áp dụng công thức dưới đây là ra: 

$$d(A, B) = \sqrt{{\left(x_A - x_B\right)}^2 + {\left(y_A - y_B\right)}^2}$$

Song, nếu chương trình có sử dụng công thức này nhiều lần thì việc viết đi viết lại công thức này sẽ rất tốn thời gian và chương trình sẽ cực kì lê thê và dài dòng.

Do đó cần tạo ra một hàm, thực hiện phép tính này và trả về giá trị cần tìm, chính là khoảng cách của hai điểm $A$ và $B$.

Tương tự như ví dụ trên, ta cũng cần xác định các yếu tố quan trọng khi viết hàm.

- **Kiểu dữ liệu trả về:** Dễ thấy kết quả của công thức trên có thể là một số thực, do đó kiểu dữ liệu trả về của hàm sẽ là `double` hoặc `float`.
- **Các tham số:** Để xác định khoảng cách giữa hai điểm thì cần tọa độ của hai điểm $A$ và $B$. Có thể thiết kế một cấu trúc dữ liệu "Tọa độ" hoặc đơn giản hóa thành hai biến $x$ và $y$. Để cho đơn giản thì tọa độ của điểm $A$ sẽ là `(xA, yA)` và tọa độ điểm $B$ sẽ là `(xB, yB)`.
- **Các câu lệnh ở trong hàm:** Với bài toán này thì không có quá nhiều câu lệnh cần viết, áp dụng công thức đã cho và trả về giá trị cần tìm là được!

Các yếu tố cần thiết đã đủ giờ bắt tay vào triển khai hàm như sau:

```cpp
double d(int xA, int yA, int xB, int yB) {
    return sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
}
```

Hàm không quá phức tạp, với 4 tham số là tọa độ của hai điểm $A$ và $B$ và hàm chỉ trả về kết quả của phép tính dựa trên công thức.

> **Lưu ý!** Trong khuôn khổ bài viết không đặt nặng tính chính xác của số thực!

Song, trong hàm có một điểm có thể cải thiện như sau: Khi tính giá trị ${\left(x_A - x_B\right)}^2$ thì phải triển khai bằng cách `(xA - xB) * (xA - xB)`. Cách làm này **đúng** nhưng không được hay và khiến cho công thức không được dễ đọc.

Do vậy có thể cải thiện hơn bằng việc xây dựng hàm tính bình phương của số $x$ bất kì như sau:

```cpp
double sqr(double x) {
    return x * x;
}

double d(int xA, int yA, int xB, int yB) {
    return sqrt(sqr(xA - xB) + sqr(yA - yB));
}
```

Sau khi bổ sung thêm hàm `sqr()` tính bình phương của một số thì hàm `d()` đã trở nên tường minh và dễ đọc hơn rất nhiều!

---

## Tổng kết

Vừa rồi là những sơ lược về hàm trong C++ và gợi ý cho cách thiết kế một hàm trong C++ cùng với một vài ví dụ. Hi vọng là cậu đã có được những kiến thức thật bổ ích và ý nghĩa.

Hàm trong C++ còn có thể làm nhiều hơn thế với `template`, `overloadign functions`, vân vân. Những kiến thức trên mình sẽ đề cập ở những bài viết trong tương lai nha.

## Tài liệu tham khảo

1. [C++ Primer](https://www.amazon.com/Primer-5th-Stanley-B-Lippman/dp/0321714113).
2. [Function in C++ | cplusplus.com](https://cplusplus.com/doc/tutorial/functions/)
3. [Function in C++ | Programiz](https://www.programiz.com/cpp-programming/function)
