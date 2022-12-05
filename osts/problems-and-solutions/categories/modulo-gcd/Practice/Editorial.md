
# Luyện tập | Editorial - Lời giải

> *Tags: Modulo, GCD, LCM, Math, Basic*

## Statement - Đề bài

Kì thi học kì sắp diễn ra nên Tùng và Nhi quyết định lên kế hoạch ôn tập để đạt được kết quả thật cao. Có $n$ bài tập để Tùng và Nhi có thể cùng nhau ôn luyện được đánh số từ $1$ đến $n$. Tùng và Nhi quyết định phải làm tối thiểu $k$ bài tập thì mới được nghỉ ngơi. Nhưng Tùng chỉ làm những bài có chỉ số chia hết cho $a$ còn Nhi chỉ làm những bài có chỉ số chia hết cho $b$ và sẽ bỏ qua những bài có chỉ số cùng chia hết cho cả $a, b$.

***Yêu cầu:*** Đếm số bài tập mà Tùng và Nhi sẽ làm và xác định liệu cả hai có hoàn thành mục tiêu làm tối thiểu $k$ bài tập đã đề ra hay không.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $q \; (1 \le q \le 10)$ - số truy vấn cần trả lời. Mỗi truy vấn có dạng như sau:

    - Mỗi truy vấn gồm $4$ số nguyên dương $n, a, b, k \; (1 \le n, k \le 10^{18}, 1 \le a, b \le 10^6)$ theo thứ tự như đã mô tả.

### Output - Dữ liệu ra

- Gồm $q$ dòng, mỗi dòng là câu trả lời tương ứng với truy vấn nếu Tùng và Nhi có thể làm được tối thiểu $k$ bài tập in `Yes`, ngược lại in `No`.

### Subtasks

- Subtask $1$ ($50\%$ số điểm) thỏa mãn:

    - $1 \le n, k \le 10^6$.
    - $1 \le a, b \le 10^3$.

- Subtask $2$ ($50\%$ số điểm còn lại) không có yêu cầu gì thêm. 

---

## Solution - Giải thuật

### Naive solution - Giải thuật ngây thơ

Đối với Subtask $1$, ta có thể dễ dàng sử dụng một vòng `for` từ $1$ đến $n$ để đếm những số chia hết cho $a$ hoặc chia hết cho $b$.

***Độ phức tạp thời gian:*** $O(n)$.

***C++:***

```cpp
#include <iostream>

using namespace std;

unsigned long long queries = 0, n = 0, k = 0, ans = 0, a = 0, b = 0;

int main() {
	cin >> queries;
	
	while (queries--) {
        cin >> n >> a >> b >> k;
        ans = 0;
        
        for (int i = 1; i <= n; ++i) {
            if ((a % i == 0 && b % i != 0) || (a % i != 0 && b % i == 0)) {
                ++ans;
            }
        }

        if (ans >= k) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
	}
	return 0;
}
```

***Python:***

```py
queries = int(input())

while queries:
    queries -= 1

    n, a, b, k = list(map(int, input().split(' ')))
    ans = 0

    for i in range(1, n + 1):
        if (a % i == 0 and b % i != 0) or (a % i != 0 and b % i == 0):
            ans += 1

    if ans >= k:
        print("Yes")
    else:
        print("No")
```

### Optimized solution - Giải thuật tối ưu

Đối với subtask $2$, ta không thể dùng vòng lặp `for` đối với subtask $1$ vì giá trị tối đa của $n$ có thể lên đến $10^{18}$. Do vậy ta cần phải nghĩ ra một cách khác để giải quyết bài toán.

Ta gọi $A$ là tập các số chia hết cho $a$ trong đoạn từ $1$ đến $n$ và $B$ là tập các số chia hết cho $b$ trong đoạn từ $1$ đến $n$. Với cách định nghĩa như vậy thì tập các phần tử chia hết cho cả $a$ và $b$ trong đoạn từ $1$ đến $n$ sẽ được xác định bằng: $C = A \cap B$.

Ví dụ: với $a = 2, b = 4, n = 10$ ta có: $A = \{2, 4, 6, 8, 10\}, \; B = \{4, 8\}$ và $C = A \cap B = \{4, 8\}$. Lúc này, kết quả bài toán sẽ là số lượng các phần tử trong $A$ và $B$ nhưng không thuộc tập $C$.

$$S = (A \cup B) \setminus (A \cap B)$$

Ta có thể đếm số lượng phần tử của tập $A$ bằng công thức: $|A| = \left\lfloor \dfrac{n}{a} \right\rfloor$. Áp dụng tương tự cho $B$ và $C$ ta được $|B| = \left\lfloor \dfrac{n}{b} \right\rfloor$ và $|C| = \left\lfloor \dfrac{n}{a \cdot b} \right\rfloor$. Vậy số lượng phần tử của tập $S$ sẽ được xác định bằng cong thức:

$$|S| = |A| + |B| - 2 \times |C|$$

***Độ phức tạp thời gian:*** $O(1)$.

***C++:***

```cpp
#include <iostream>
#include <math.h>

using namespace std;

unsigned long long queries = 0, n = 0, k = 0, ans = 0, a = 0, b = 0;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    return b ? gcd(b, a % b) : a;
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
    return a / gcd(a, b) * b;
}

int main() {
	cin >> queries;
	
	while (queries--) {
        cin >> n >> a >> b >> k;
        ans = 0;
        
        ans = floor(n / a) + floor(n / b) - 2 * floor(n / lcm(a, b));

        if (ans >= k) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
	}
	return 0;
}
```

***Python:***

```py
import math

def gcd(a, b):
    if b == 0:
        return a

    return gcd(b, a % b)

def lcm(a, b):
    return a // gcd(a, b) * b


queries = int(input())

while queries:
    queries -= 1
    
    n, a, b, k = list(map(int, input().split(' ')))

    ans = math.floor(n // a) + math.floor(n // b) - 2 * math.floor(n // lcm(a, b))

    if ans >= k:
        print("Yes")
    else:
        print("No")
```