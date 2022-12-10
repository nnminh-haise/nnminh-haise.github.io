
# Cấu trúc dữ liệu trừu tượng struct trong C++

---

> *Đã bao giờ cậu tự hỏi làm sao để có thể lưu các thông tin gồm họ và tên, tuổi, giới tính và ngày sinh của một $1000$ người chưa?*

## Tổng quan về struct

*Ở mục này mình và cậu sẽ cùng nhau trả lời $2$ câu hỏi lớn:*

- `struct` là gì?
- Vì sao phải sử dụng `struct`?

### Struct là gì?

`struct` hay **Structures** là một tập hợp các kiểu dữ liệu khác nhau thành cùng một đối tượng.

> ***Hay nói đơn giản chính là cách để gom nhiều thông tin khác nhau về cùng một chỗ và định nghĩa cho nó.***
>
> *Quay trở lại câu hỏi đề bài, cậu hãy hình dung rằng cậu có một đối tượng là người, đối tượng này có họ và tên, tuổi, giới tính và ngày sinh tương ứng.*

```
* Người:
    |- Họ và tên;
    |- Tuổi;
    |- Giới tính;
    |- Ngày sinh.
```

Như vậy, cậu có thể hình dung danh sách chứa $1000$ người sẽ gần giống như sau:

```
* Người thứ nhất:
    |- Họ và tên;
    |- Tuổi;
    |- Giới tính;
    |- Ngày sinh.

* Người thứ hai:
    |- Họ và tên;
    |- Tuổi;
    |- Giới tính;
    |- Ngày sinh.

* Người thứ ba:
    |- Họ và tên;
    |- Tuổi;
    |- Giới tính;
    |- Ngày sinh.

...

* Người thứ 10000:
    |- Họ và tên;
    |- Tuổi;
    |- Giới tính;
    |- Ngày sinh.
```

### Vì sao lại dùng struct?

*Sau khi hình dung được `Struct` là gì thì vì sao cậu nên sử dụng `Struct`?*

Quay trở lại câu hỏi ở đầu bài viết, mình sẽ đưa ra một câu trả lời cho câu hỏi này như sau:

- Để lưu danh sách $10000$ gồm họ và tên của $10000$ khác nhau cậu có thể sử dụng một mảng gồm $10000$ phần tử kiểu `string` (chuỗi).
- Tương tự đối với "tuổi", "giới tính" và "ngày sinh" của mỗi người.

*Như vậy, cậu sẽ cần sử dụng $4$ mảng khác nhau, mỗi mảng có $1000$ phần tử. Nếu danh sách có nhiều hơn $1000$ người và số lượng thông tin của mỗi người nhiều hơn $4$ thì chắc chắn cậu sẽ tốn rất nhiều mảng và mỗi mảng lại có rất nhiều phần tử. Do đó cậu sẽ rất khó khăn khi quản lí và xử lí chỗ dữ liệu đó.*

Vì sự kém linh hoạt này, `struct` sẽ là một sự lựa chọn tốt để cậu tối ưu hóa dữ liệu. Cậu có thể thấy rằng các thông tin cậu lưu đều có tính chất giống nhau gồm "họ và tên", "tuổi", "giới tính" và "ngày sinh". Lúc này thay vì xử lí như câu trả lời ở trên cậu có thể lưu thành một mảng có $1000$ phần tử có kiểu dữ liệu là đối tượng "người".

**Do vậy, cậu nên sử dụng `struct` đối với những dữ liệu nào chứa nhiều thông tin của cùng một sự vật (đối tượng) và cậu cần xử lí hết những thông tin đó thì hãy nghĩ đến `struct`.**

---

## Sử dụng struct cơ bản

> *Trước khi đọc tiếp các mục dưới đây, mình hi vọng cậu hình dung được struct là gì. Nếu không, cậu hãy dành thời gian để suy nghĩ và hình dung nhé!*

### Khai báo struct

Để cậu dễ nắm bắt được cách khai báo, mình sẽ đưa ra cấu trúc trước để cậu dễ hình dung và mình sẽ giải thích từng chi tiết.

```bash
struct <tên struct> {
	<kiểu dữ liệu> <tên biến thứ nhất>;
	<kiểu dữ liệu> <tên biến thứ hai>;
	<kiểu dữ liệu> <tên biến thứ ba>;
	...
	<kiểu dữ liệu> <tên biến thứ n>;

    <hàm thành viên thứ nhất>
    <hàm thành viên thứ hai>
    <hàm thành viên thứ ba>
    ...
    <hàm thành viên thứ n>
};
```

Trong đoạn mã giả trên là cách khai báo một `struct` cơ bản trong `c++`:

- Mở đầu bằng từ khóa `struct`, tiếp theo sau chính là tên của `struct`. Cái tên này đóng vai trò tương tự như tên biến, được dùng để phân biệt, xác định đối tượng này với đối tượng khác. Các thành phần tiếp theo của `struct` sẽ được bao bọc bởi một cặp ngoặc nhọn và sau dấu đóng ngoặc nhọn cậu hãy lưu ý để dấu ";" nha.
- Bên trong `struct` cậu thấy sẽ có hai thành phần chính đó là:

    - `<kiểu dữ liệu> <tên biến thứ i>;`: là một thành viên dữ liệu (*hay còn gọi là trường - field*). Chính là một biến lưu trữ một phần thông tin của đối tượng. *Ví dụ như biến `string name;` để lưu tên, biến `int age;` để lưu tuổi, biến `bool sex;` để lưu giới tính.*
    - `<hàm thành viên thứ i>`: là một hàm thành viên (*hay còn gọi là phương thức - method*). Chính là các hàm có thể thao các trên các thành viên dữ liệu. *Ví dụ như cậu có thể viết một hàm in ra thông tin của một người.*

Mình sẽ minh họa đối tượng `struct` đã nói ở trên cho cậu dễ hiểu hơn. Bên trong `struct` sẽ có $3$ thành viên dữ liệu đó là "họ và tên", "tuổi" và "giới tính"; bên cạnh đó mình sẽ thêm hai hàm thành viên nữa có chức năng cho phép cậu nhập thông tin và in thông tin của đối tượng ra ngoài màn hình.

#### Ví dụ 1

```cpp
struct Person {
	string name;
	int age;
	bool sex;

	void setInformation() {
		cout << "Nhap ho va ten: ";
		getline(cin, this->name);
		cout << "Nhap tuoi: ";
		cin >> this->age;
		cout << "Nhap gioi tinh (neu la nam nhap 0, neu la nu nhap 1): ";
		cin >> this->sex;
	}

	void getInformation() {
		cout << "Ho va ten: " << this->name << "\n";
		cout << "Tuoi: " << this->age << "\n";
		cout << "Gioi tinh: " << (this->sex == 0 ? "nam\n" : "nu\n");
	}
};
```

*Cậu hãy dành một chút thời gian để đọc và xác định được các thành phần trong `struct Person` như mình đã mô tả ở trên.*

Theo như mô tả trước ví dụ thì ta có:

- `string name;`, `int age;` và `bool sex` là các thành viên dữ liệu. Mỗi thành viên sẽ chứa một thông tin duy nhất của đối tượng.
- `setInformation()` và `getInformation()` là hai hàm thành viên (*hay method*) của đối tượng `Person` với hai chức năng lần lượt là lấy thông tin và in ra thông tin của đối tượng.

Cậu thấy đó, về mặt cú pháp, các *thành viên dữ liệu* và các *phương thức* có cú pháp tương tự như khai báo biến và định nghĩa hàm.

```cpp
int main() {
	Person person;
	person.setInformation();
	person.getInformation();
	return 0;
}
```

*Đây là đoạn code với chức năng tạo một đối tượng trên và sử dụng hai hàm thành viên:*

Ở trong hàm `main()` cậu có thể thấy mình tạo một biến `person` có kiểu dữ liệu là một `struct Person`. Sau đó mình có hai câu lệnh `person.setInformation();` và `person.getInformation();` để lấy thông tin và in thông tin.

Dấu `.` (dấu chấm) là một toán tử truy cập thành viên (*member access operator hay member of object*) được sử dụng để truy cập đến các thành viên dữ liệu hoặc các hàm thành viên. Ví dụ cậu có thể lấy thông tin tên của người đó như sau: `string username = person.name;`. Lúc này, biến `username sẽ chứa thông tin là tên của người mà cậu đã nhập vào.

Nhìn kĩ vào hai hàm `getInformation()` và `setInformation()` cậu sẽ thấy một toán tử khác: `->` cũng giống như dấu `.` thì đây cũng là một toán tử được sử dụng để truy cập đến các thông tin của một `struct` nhưng khác với dấu `.` thì `->` là một toán tử truy cập con trỏ (*member of pointer*).

Từ khóa `this` được sử dụng trong hai hàm `getInformation()` và `setInformation()` là một con trỏ, trỏ đến đối tượng hiện tại. *Giải thích: ở trong hàm main(), biến (cũng có thể hiểu là một đối tượng) `person` được khai báo. Sau đó mình sử dụng toán tứ `.` để truy cập đến hàm thành viên `setInformation()` của `person`. Lúc này, bên trong hàm `setInformation()`, từ khóa `this` là một con trỏ, trỏ đến biến `person` ở ngoài hàm `main()`.*

Ngoài hai cách truy cập thành viên đó, cậu còn có thể truy cập đến các thành viên bằng các cách sau:

```cpp
Person* person_pointer = &person;   // Khai báo một con trỏ, trỏ đến biến person.
person_pointer->name;
(*person_pointer).name;
(&person)->name;
```

#### Ví dụ 2

Cậu hãy tạo ra một `struct Date` dùng để chứa thông tin về ngày, tháng, năm và có các hàm nhập hoặc in ra các thông tin trên.

```cpp
struct Date {
    int date, month, year;

    void setDate() {
        cout << "Nhap ngay: ";
        cin >> this->date;
        cout << "Nhap thang: ";
        cin >> this->month;
        cout << "Nhap nam: ";
        cin >> this->year;
    }

    void getDate() {
        cout << this->date << "/" << this->month << "/" << this->year << endl;
    }
};
```

*Đây là đáp án tham khảo cho cậu.*

Trong `struct Person` vẫn còn một thông tin đang bị thiếu đó là ngày sinh. Mình có thể sử dụng `struct Date` vừa tạo để lưu trữ thông tin về ngày sinh của một người nào đó.

```cpp
struct Date {
    int date, month, year;

    void setDate() {
        cout << "Nhap ngay: ";
        cin >> this->date;
        cout << "Nhap thang: ";
        cin >> this->month;
        cout << "Nhap nam: ";
        cin >> this->year;
    }

    void getDate() {
        cout << this->date << "/" << this->month << "/" << this->year << endl;
    }
};

struct Person {
	string name;
	int age;
	bool sex;
    Date date_of_birth;

	void setInformation() {
		cout << "Nhap ho va ten: ";
		getline(cin, this->name);
		cout << "Nhap tuoi: ";
		cin >> this->age;
		cout << "Nhap gioi tinh (neu la nam nhap 0, neu la nu nhap 1): ";
		cin >> this->sex;
        cout << "Nhap ngay sinh:\n";
        (this->date_of_birth).setDate();
	}

	void getInformation() {
		cout << "Ho va ten: " << this->name << "\n";
		cout << "Tuoi: " << this->age << "\n";
		cout << "Gioi tinh: " << (this->sex == 0 ? "nam\n" : "nu\n");
        cout << "Ngay sinh: ";
        (this->date_of_birth).getDate();
	}
};
```

Như vậy cậu có thể sử dụng `struct` này bên trong `struct` khác thay vì cậu phải tạo ra ba biến khác để lưu thông tin ngày tháng năm sinh của một người.

### Hàm khởi tạo

> *Phương thức khởi tạo hay hàm khởi tạo (constructor function) là một hàm được gọi khi đối tượng (biến) được khởi tạo. Đây là một hàm đặc biệt có tên trùng với tên của đối tượng và không có kiểu hay giá trị trả về.*

Mã giả cho hàm khởi tạo:

```bash
struct <tên cấu trúc> {
    // các thành viên dữ liệu được khai báo ở đây.
    ...

    <tên cấu trúc> (<các tham số>) { // lưu ý, hàm có thể có tham số hoặc không.

    }

    // các phương thức khác được khai báo ở đây.
    ...
};
```

#### Ví dụ 1

Quay trở lại với `struct Date` ở bên trên:

```cpp
struct Date {
    int date, month, year;

    void setDate() {
        cout << "Nhap ngay: ";
        cin >> this->date;
        cout << "Nhap thang: ";
        cin >> this->month;
        cout << "Nhap nam: ";
        cin >> this->year;
    }

    void getDate() {
        cout << this->date << "/" << this->month << "/" << this->year << endl;
    }
};
```

Giả sử nếu mình tạo một đối tượng `date_of_birth` mới thì ban đầu các thông tin như ngày, tháng, năm sẽ có giá trị gì nhỉ?

```cpp
int main() {
    Date date_of_birth;
    cout << date_of_birth.date << ", " << date_of_birth.month << ", " << date_of_birth.year << endl;
    return 0;
}
```

Và đây là Output trên máy tính của mình: `-449661096, 32766, 222961718`, một dãy các số không xác định. Có thể trên máy tính của cậu sẽ khác.

Nếu cậu để như vậy, có thể trong một số trường hợp sẽ tạo ra lỗi khi cậu sử dụng đối tượng `date_of_birth` này. Do đó mình sẽ sử dụng hàm khởi tạo để khởi gán một giá trị mặc định cho đối tượng ngay khi được khởi tạo. Cách làm như sau:

```cpp
struct Date {
    int date, month, year;

    Date() {
        this->date = 1;
        this->month = 1;
        this->year = 1;
    }

    void setDate() {
        cout << "Nhap ngay: ";
        cin >> this->date;
        cout << "Nhap thang: ";
        cin >> this->month;
        cout << "Nhap nam: ";
        cin >> this->year;
    }

    void getDate() {
        cout << this->date << "/" << this->month << "/" << this->year << endl;
    }
};
```

Vẫn giữ nguyên hàm `main()` như lúc nãy thì kết quả Output của mình sẽ là: `1, 1, 1`.

> *Nhưng nếu cậu muốn khởi tạo một giá trị bất kì cho đối tượng thì sao nhỉ?*

Lúc này mình sẽ truyền tham số: ngày, tháng, năm vào hàm `Date()` và khởi tạo các giá trị mặc định cho các tham số này bằng $1$. Hàm `Date()` sẽ thực hiện cập nhật các tham số này vào các thành viên tương ứng của đối tượng.

```cpp
struct Date {
    int date, month, year;

    Date(int _date = 1, int _month = 1, int _year = 1) {
        this->date = _date;
        this->month = _month;
        this->year = _year;
    }

    void setDate() {
        cout << "Nhap ngay: ";
        cin >> this->date;
        cout << "Nhap thang: ";
        cin >> this->month;
        cout << "Nhap nam: ";
        cin >> this->year;
    }

    void getDate() {
        cout << this->date << "/" << this->month << "/" << this->year << endl;
    }
};
```

Với hàm `main()` có nội dung như sau:

```cpp
int main() {
    Date date_of_birth;
    cout << date_of_birth.date << ", " << date_of_birth.month << ", " << date_of_birth.year << endl;

    date_of_birth = Date(20, 10, 2010);
    cout << date_of_birth.date << ", " << date_of_birth.month << ", " << date_of_birth.year << endl;
    return 0;
}
```

Thì mình có Output như sau:

```
1, 1, 1
20, 10, 2010
```

Với cách viết hàm `Date()` mới thì mình có thể khởi gán một giá trị bất kì cho đối tượng. Cậu cũng có thể áp dụng tương tự đối với các `struct` khác nhau. Chỉ cần định nghĩa hàm khởi tạo cho phù hợp là được.

#### Ví dụ 2

Cậu hãy thử viết hàm khởi tạo cho `struct Person` ở trên nha.

*Lời giải gợi ý của mình:*

```cpp
struct Person {
	string name;
	int age;
	bool sex;
    Date date_of_birth;

    Person(Date _date_of_birth = Date(0, 0, 0), string _name = "###", int _age = 0, bool _sex = true) {
        this->date_of_birth = _date_of_birth;
        this->name = _name;
        this->age = _age;
        this->sex = _sex;
    }

	void setInformation() {
		cout << "Nhap ho va ten: ";
		getline(cin, this->name);
		cout << "Nhap tuoi: ";
		cin >> this->age;
		cout << "Nhap gioi tinh (neu la nam nhap 0, neu la nu nhap 1): ";
		cin >> this->sex;
        cout << "Nhap ngay sinh:\n";
        (this->date_of_birth).setDate();
	}

	void getInformation() {
		cout << "Ho va ten: " << this->name << "\n";
		cout << "Tuoi: " << this->age << "\n";
		cout << "Gioi tinh: " << (this->sex == 0 ? "nam\n" : "nu\n");
        cout << "Ngay sinh: ";
        (this->date_of_birth).getDate();
	}
};
```

Với hàm `main()` có nội dung như sau:

```cpp
int main() {
    Person person;
    person = Person(Date(20, 10, 2010), "Sunny", 12);
    person.getInformation();
    return 0;
}
```

Thì mình có Output:

```
Ho va ten: Sunny
Tuoi: 12
Gioi tinh: nu
Ngay sinh: 20/10/2010
```

***Lưu ý:*** Có thể trong lúc tạo các tham số mặc định (*default arguments*) cho hàm khởi tạo cậu gặp lỗi sau: `default argument not at end of parameter list`. Thì hãy xem lại về phần tham số mặc định cho hàm. Một gợi ý của mình đó là hãy thử đổi thứ tự của các tham số. *Cậu có thể kéo xuống phần tài liệu tham khảo, mình có đính kèm một vài trang tài liệu cậu có thể đọc thêm về phần này nha.*

## Kết luận

Như vậy mình và cậu đã cùng nhau đi qua một số những kiến thức cơ bản về `struct` trong ngôn ngữ lập trình `c++`. Cậu hãy luyện tập thêm nha. Chúc cậu may mắn.

---

## Tài liệu tham khảo

- [Data Structures | cplusplus](https://cplusplus.com/doc/tutorial/structures/)
- [Member access Operator | cppreference](https://en.cppreference.com/w/cpp/language/operator_member_access)
- [Default argument in the middle of parameter list? | StackOverFlow](https://stackoverflow.com/questions/5637679/default-argument-in-the-middle-of-parameter-list)
- [C++ Default arguments | cppreference](https://en.cppreference.com/w/cpp/language/default_arguments)
