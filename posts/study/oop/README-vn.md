
# Lập trình hướng đối tượng

- Lập trình cấu trúc tập trung vào việc viết các hàm/thủ tục để thực hiện các thao tác trên dữ liệu. Trong khi đó lập trình hướng đối tượng tập trung vào việc thiết kế các đối tượng chứa các thủ tục và dữ liệu.

- Lập trình hướng đối tượng sẽ có các ưu điểm sau khi so với lập trình hướng cấu trúc.

    - OOP nhanh và dễ thực thi.
    - OOP khiến chương trình có cấu trúc rõ ràng.
    - OOP hạn chế việc lặp lại code và khiến việc bảo trì, thay đổi và sửa lỗi dễ dàng hơn.
    - OOP tạo điều kiện cho việc tạo ra một chương trình có thể tái sử dụng, với ít code và thời gian phát triển ngắn hơn.


## Lớp (class) & Đối tượng (object)

- Lớp và đối tượng là hai khía cạnh chính của lập trình hướng đối tượng.
- Lớp là một khuôn mẫu cho đối tượng, còn đối tượng là một đại diện của lớp. Khi một đối tượng được tạo ra thì nó sẽ kế thừa tất cả các biến và hàm của lớp tương ứng.

## Lớp và đối tượng trong C++

- C++ là một ngôn ngữ lập trình hướng đối tượng.
- Mọi thứ trong C++ đều có liên quan đến lớp và đối tượng cùng với các thuộc tính và phương thức của đối tượng đó.
- Thuộc tính và phương thức chính về cơ bản chính là biến và hàm ở trong lớp tương ứng.
- Một lớp chính là một kiểu dữ liệu do người dùng định nghĩa, và sẽ hoạt động như một khuôn mẫu để tạo ra đối tượng.

### Tạo lớp trong C++

Dưới đây là ví dụ cho một lớp `Student` bao gồm hai thuộc tính: `name` và `englishGrade`.

```cpp
class Student {
public:
    string name;
    int englishGrade;
};
```

**Giải thích ví dụ:**

- Từ khóa 'class' được sử dụng để tạo một lớp mới.
- Sau từ khóa 'class' là tên của lớp được tạo, cụ thể trong ví dụ là `Student`. Quy tắc đặt tên của lớp cũng tương tự với quy tắc đặt tên biến.
- Các thuộc tính (biến) và phương thức (hàm) của lớp sẽ được đặt trong cặp ngoặc nhọn `{}` và kết thúc bằng một dấu `;`.
- Trong ví dụ trên, lớp `Student` sẽ có hai thuộc tính là:
    
    - `name`: tên của học sinh, thuộc kiểu `string.
    - `englishGrade`: điểm tiếng anh của học sinh, thuộc kiểu `int`.

- Cuối cùng, từ khóa `public` là một từ khóa định danh truy cập (access specifier), cho biết rằng các thuộc tính và phương thức sau sẽ có thể được truy cập từ ngoài của lớp.

### Tạo đối tượng trong C++

- Đối tượng trong C++ sẽ được tạo từ lớp.
- Để tạo một đối tượng cần chỉ ra tên của lớp và tên đối tượng tương ứng.
- Để truy cập đến các thuộc tính hoặc phương thức của đối tượng thì sẽ sử dụng kí tự `.`.

```cpp
class Student {
public:
    string name;
    int englishGrade;
};

int main() {
    Student a;
    a.name = "Minh";
    a.englishGrade = 9;

    cout << a.name << endl;
    cout << a.englishGrade << endl;

    return 0;
}
```

**Giải thích ví dụ:**

- Giữ nguyên lớp `Student` đã tạo, ở trong hàm `main()`, một đối tượng thuộc lớp `Student` có tên `a` được tạo.
- Thuộc tính `name` của `a` được gán bằng `"Minh"` và thuộc tính `englishGrade` của `a` được gán bằng giá trị $9$.
- Sau đó hai thuộc tính này được in ra ngoài màn hình.
