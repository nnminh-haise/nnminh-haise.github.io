
# Kiểu dữ liệu char, C-Style string và lớp string trong C++

> Làm sao để biểu diễn một tập hợp gồm các kí tự trong bảng chữ cái?

## C++ char - kiểu dữ liệu kí tự trong C++

C++ `char` - kiểu dữ liệu kí tự trong C++ là một trong các kiểu dữ liệu nguyên thủy (*primitive data type*) của ngôn ngữ C++. Mỗi biến kiểu `char`sẽ lưu trữ một kí tự trong bảng mã ASCII.

## Sử dụng char trong C++

### Khai báo và khởi gán

Ta thực hiện khai báo một biến kiểu `char` tương tự với cách khai báo các kiểu dữ liệu nguyên thủy khác trong ngôn ngữ C++:

> *Cậu có thể đọc thêm về bảng mã ASCII ở mục tài liệu tham khảo bên dưới.*

```cpp
char <tên biến>;
```

Ví dụ:

```cpp
char chr;
```

Bên cạnh việc khai báo như trên, ta cũng có thể khởi gán một biến `char` với một kí tự bất kì trong bảng mã ASCII:

```cpp
char <tên biến> = <kí tự bất kì>;
```

Ví dụ:

```cpp
char chr = 'A';
```

***Lưu ý:*** kí tự trong C++ phải được bao quanh bởi dấu nháy đơn.

### Ép kiểu với char

Giả sử nếu ta gán cho một biến kiểu `int` kí tự `a` thì biến đó sẽ có giá trị gì?

```cpp
int a = 'a';
cout << "Value of a: " << a << endl;
```

Kết quả đầu ra sẽ là:

```
Value of a: 97
```

Vì sao lại in ra số $97$? - Nếu bạn tra thứ tự của kí tự `a` trong bảng mã ASCII sẽ ra kết quả là $97$. Quy ước rằng trình dịch khi ép kiểu từ `char` sang `int` sẽ thay kí tự đó bằng thứ tự tương ứng trong bảng mã ASCII. Tương tự cho kiểu `double` và `float`. Riêng với `bool` thì trình dịch sẽ làm tương tự. Nhưng theo quy ước, các giá trị khác $0$ sẽ là `true` và $0$ sẽ là `false` nên các biến kiểu `char` khi ép kiểu sang `bool` sẽ hiểu là $1$ hoặc $0$.

Mặt khác, ta cũng có thể ép kiểu số nguyên sang kiểu kí tự nhưng có một số các kí tự đặc biệt ta không quan sát được nên cần phải cẩn thận khi ép kiểu từ `int` sang `bool`.

Một ứng dụng cho việc ép kiểu này, ta có thể in ra danh sách các chữ cái dễ dàng như sau:

```cpp
for (int i = 0; i < 26; ++i) {
    cout << (char)(i + 'a') << " ";
}
cout << "\n";
```

*Output của chương trình:*

```
a b c d e f g h i j k l m n o p q r s t u v w x y z 
```

***Giải thích:*** bảng chữ cái tiếng anh có $26$ kí tự và kí tự đầu tiên là `a`. Do đó ta có một vòng lặp `for` lặp lại với biến $i$ có giá trị trong đoạn $[0, 25]$. Như đã đề cập ở trên, trình dịch khi ép kiểu các kí tự `char` sang `int` sẽ thay thế thứ tự của kí tự tương ứng trong bảng mã ASCII. Vì vậy biểu thức $(i + `a`)$ sẽ tương đương với biểu thức $(i + 97)$ và khi $i$ có giá trị trong đoạn $[0, 25]$ thì biểu thức cũng có giá trị trong đoạn $[97, 122]$. Cuối cùng, với mỗi giá trị của biểu thức ta sẽ ép kiểu từ `int` sang `char` và thu được kí tự tương ứng (*với lối tư duy tương tự, ta có thể thực hiện với các kí tự in hoa và kí tự chữ số*).

Bên cạnh đó, ta cũng có thể ép kiểu các kí tự trong bảng chữ cái tiếng anh sang thứ tự từ $0$ đến $25$ như sau:

```cpp
for (char i = 'a'; i <= 'z'; ++i) {
    cout << i - 'a' << " ";
}
cout << endl;
```

*Output của chương trình:*

```
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 
```

## C-Style string - Chuỗi kiểu C

Chuỗi kiểu C xuất hiện từ ngôn ngữ lập trình C. Cụ thể ta sẽ kết hợp mảng với kiểu dữ liệu `char`. Trong đó mỗi phần tử của mảng là một kí tự `char` và phần tử cuối cùng của mảng sẽ là kí tự `null`.

### Khai báo và khởi gán

Tương tự như mảng số nguyên hay số thực, ta cũng có thể khai báo C-Style string như sau:

```cpp
char <tên biến>[<số lượng phần tử>];
```

Ví dụ:

```cpp
char id[20]; // Đây là mảng chứa tối đa 20 kí tự.
```

Hoặc ta có thể khởi gán như sau:

```cpp
char id[20] = "2A5F9C";
cout << id << endl;
```

***Output của chương trình:***

```
2A5F9C
```

*Tuy khai báo một chuỗi có tối đa $20$ kí tự nhưng cậu không nhất thiết phải chứa hết $20$ kí tự đó.*

### Một số hàm thông dụng đối với C-Style string

***Hàm strcpy:*** Sao chép chuỗi nguồn vào chuỗi đích (kể cả kí tự cuối).

```cpp
char* strcpy (char* destination, const char* source);
```

Ví dụ:

```cpp
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char a[20] = "1A2B3C";
    char b[20];
    cout << "Value of a: \"" << a << "\"" << endl;
    cout << "Value of b: \"" << b << "\"" << endl;
    strcpy(b, a);
    cout << "Value of a: \"" << a << "\"" << endl;
    cout << "Value of b: \"" << b << "\"" << endl;
    return 0;
}
```

*Output của chương trình:*

```
Value of a: "1A2B3C"
Value of b: ""
Value of a: "1A2B3C"
Value of b: "1A2B3C"
```

***Hàm strcat:*** Hàm sẽ sao chép chuỗi nguồn vào cuối chuỗi đích. Cụ thể, kí tự `null` của chuỗi đích sẽ bị thay thế bởi kí tự đầu tiên của chuỗi nguồn và một kí tự `null` sẽ được thêm vào cuối chuỗi đích. *Lưu ý: hai chuỗi nguồn và đích không nên bị chồng lên nhau.*

```cpp
char* strcat (char* destination, const char* source);
```

Ví dụ:

```cpp
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char a[20] = "1A2B3C";
    char b[20] = "4D5F";
    cout << "Value of a: \"" << a << "\"" << endl;
    cout << "Value of b: \"" << b << "\"" << endl;
    strcat(b, a);
    cout << "Value of a: \"" << a << "\"" << endl;
    cout << "Value of b: \"" << b << "\"" << endl;
    return 0;
}
```

*Output của chương trình:*

```
Value of a: "1A2B3C"
Value of b: "4D5F"
Value of a: "1A2B3C"
Value of b: "4D5F1A2B3C"
```

***Hàm strcmp:*** Hàm sẽ so sánh chuỗi $str1$ với $str2$ theo quy tắc: chương trình sẽ bắt đầu so sánh từ kí tự đầu tiên của hai chuỗi, nếu hai kí tự giống nhau sẽ tiếp tục so sánh. Cho đến khi gặp hai kí tự khác nhau thì sẽ dừng và trả kết quả tương ứng.

Hàm sẽ trả về giá trị $x$ tương ứng:

- $x = 0$ nếu hai chuỗi bằng nhau.
- $x < 0$ nếu chuỗi $str1$ bé hơn chuỗi $str2$.
- $x > 0$ nếu chuỗi $str1$ lớn hơn chuỗi $str2$.

```cpp
int strcmp (const char* str1, const char* str2);
```

Ví dụ:

```cpp
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char a[20] = "1A2B3C";
    char b[20] = "4D5F";
    cout << "Value of a: \"" << a << "\"" << endl;
    cout << "Value of b: \"" << b << "\"" << endl;
    int result = strcmp(a, b);
    cout << "Value of result: " << result << endl;
    return 0;
}
```

*Output của chương trình:*

```
Value of a: "1A2B3C"
Value of b: "4D5F"
Value of result: -3
```

***Hàm strlen:*** Hàm sẽ trả về độ dài của chuỗi $str$. *Lưu ý: Độ dài của một C-Style string là số lượng kí tự tính từ kí tự đầu tiên đến kí tự `null` (không tính kí tự `null`). Do vậy không nên hiểu nhầm giữa độ dài chuỗi và kích thước mảng chứa các kí tự.*

```cpp
size_t strlen (const char* str);
```

Ví dụ:

```cpp
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char a[20] = "1A2B3C";
    cout << "Value of a: \"" << a << "\"" << endl;
    size_t len = strlen(a);
    cout << "Length of a: " << len << endl;
    cout << "Size of a: " << sizeof(a) << endl;
    return 0;
}
```

*Output của chương trình:*

```
Value of a: "1A2B3C"
Length of a: 6
Size of a: 20
```
> *Còn rất nhiều hàm khác nhau, cậu có thể tham khảo ở mục tài liệu tham khảo mình có để ở dưới.*

## C++ string - string trong C++

Basic string (*hay string class - lớp string*) là đối tượng (*object*) chứa một tập hợp các kí tự liên tiếp.

### Khai báo và khởi gán

Ta có thể khai báo một biến kiểu `string` như sau:

```cpp
string <tên biến>;
```

Ví dụ:

```cpp
string name;
```

Hoặc khởi gán một giá trị cho chuỗi như sau:

```cpp
string <tên biến> = <chuỗi khởi gán>;
```

Ví dụ:

```cpp
string name = "James";
cout << "Value of name: \"" << name << "\"" << endl;
```

*Output của chương trình:*

```
Value of name: "James"
```

### Sâu hơn về std::string

Vì được xây dựng với cấu trúc tương tự như một cấu trúc lưu trữ tiêu chuẩn (a standard container) của C++ nên `std::string` có các hàm thành viên (*member function*) như sau:

- [(constructor)](https://cplusplus.com/reference/string/string/string/).
- [(destructor)](https://cplusplus.com/reference/string/string/~string/).
- [operator=](https://cplusplus.com/reference/string/string/operator=/).
- Các hàm liên quan đến con trỏ.
- Các hàm liên quan đến kích thước.
- Các hàm liên quan đến việc truy cập đến các phần tử.
- Các hàm biến đổi `std::string`.
- Các hàm liên quan đến các phép tính `std::string`.

Mình sẽ chỉ liệt kê một số hàm thông dụng, cậu có thể tìm hiểu thêm ở phần tài liệu tham khảo ở cuối.

***Toán tử truy cập phần tử (operator[]):*** Toán tử sẽ trả về một tham chiếu (*reference*) đến kí tự $pos$ của chuỗi. *Lưu ý: nếu vị trí $pos$ bằng với độ dài chuỗi thì toán tử sẽ trả về kí tự `null`.*

```cpp
char& operator[] (size_t pos);
const char& operator[] (size_t pos) const;
```

Ví dụ:

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name = "James";
    for (int i = 0; i < name.length(); ++i) {
        cout << name[i] << endl;
    }
    return 0;
}
```

*Output của chương trình:*

```
J
a
m
e
s
```

***Hàm length() và size():*** Về mặt bản chất thì hai hàm này giống nhau và có giá trị trả về giống nhau đó là chiều dài của chuỗi.

```cpp
size_t length() const noexcept; // C++11.
```

Ví dụ:

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name = "James";
    cout << "Length of name: " << name.length() << endl;
    return 0;
}
```

*Output của chương trình:*

```
Length of name: 5
```

***Hàm empty():*** Hàm sẽ cho biết nếu chuỗi đang xét rỗng hoặc không (rỗng nếu độ dài chuối bằng $0$).

```cpp
bool empty() const noexcept;
```

Ví dụ:

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name = "James";
    bool is_empty = name.empty();
    cout << "Length of name: " << name.length() << endl;
    cout << "Value of is_empty: " << is_empty << endl;
    name = "";
    is_empty = name.empty();
    cout << "Value of is_empty: " << is_empty << endl;
    return 0;
}
```

*Output của chương trình:*

```
Length of name: 5
Value of is_empty: 0
Value of is_empty: 1
```

***Hàm copy():*** Hàm sẽ sao chép một chuỗi con có độ dài $len$ bắt đầu từ kí tự ở vị trí $pos$ của chuỗi hiện tại vào chuỗi (*c-style string*) $s$. *Lưu ý: Chuỗi được gán (hay chuỗi chứa chuỗi con) sẽ không có kí tự `null` ở cuối.*

```cpp
size_t copy (char* s, size_t len, size_t pos = 0) const;
```

Ví dụ:

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    char a[10];
    string name = "James";
    size_t len = name.copy(a, 2, 0);
    a[len] = '\0';
    cout << "Value of a: \"" << a << "\"" << endl;
    return 0;
}
```

*Output của chương trình:*

```
Value of a: "Ja"
```

---

## Tổng kết

Mình và cậu vừa tìm hiểu sơ qua về kiểu dữ liệu `char`, C-Style string và string class trong ngôn ngữ lập trình C++. Mình hi vọng cậu rút ra được những kiến thức quý gia cho bản thân và chúc cậu may mắn.

---

## Tài liệu tham khảo

- [ASCII | Wikipedia](https://en.wikipedia.org/wiki/ASCII).
- [\<cstring\> (string.h) - Thư viện string.h | cplusplus](https://cplusplus.com/reference/cstring/).
- [std::string | cplusplus](https://cplusplus.com/reference/string/string/).
