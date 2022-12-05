
# Super prime number -  Số siêu nguyên tố | Editorial - Lời giải

> *Tags: Prime number, Math, Basic*

## Statement - Đề bài

Số nguyên tố là số lớn hơn $1$ và chỉ có hai ước số là $1$ và chính nó. Ví dụ các số $2, 3, 5, 7, 11, \dots$ là các số nguyên tố. Số siêu nguyên tố là số mà mỗi lần bỏ đi một chữ số ở phía trước của số đó thì phần còn lại vẫn là một số nguyên tố. Ví dụ như số $23$ là một số siêu nguyên tố vì khi bỏ đi số $2$ ở phía trước thì phần còn lại là số $3$ vẫn là một số nguyên tố.

***Yêu cầu:*** Cho một số nguyên $k$ có $10$ chữ số. Kiểm tra số đã cho có phải là số siêu nguyên tố hay không.

### Input - Dữ liệu vào

- Một số nguyên $k$ duy nhất.

### Output - Dữ liệu ra

- In ra `True` nếu $k$ là số siêu nguyên tố và `False` trong trường hợp ngược lại.

### Subtasks

- Subtask $1$ ($50\%$ số điểm) thỏa mãn: số $k$ có tối đa $5$ chữ số.
- Subtask $2$ ($50\%$ số điểm) không có ràng buộc gì thêm.

---

## Solution - Giải thuật

Đây là một bài không quá phức tạp, chỉ cần làm theo các bước kiểm tra một số siêu nguyên tố như đã được nêu ở đề bài. Subtask $1$ là để duyệt trâu đối với trường hợp không có cách kiểm tra số siêu nguyên tố.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

unsigned long long n;

bool primality(unsigned long long n) {
    if (n < 2) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    } 
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

unsigned long long binaryPower(unsigned long long a, unsigned long long b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    unsigned long long tmp = binaryPower(a, b / 2);
    if (b % 2 == 0) {
        return tmp * tmp;
    }
    return tmp * tmp * a;
}

int main() {
    cin >> n;
    while (n > 0) {
        if (!primality(n)) {
            cout << "False\n";
            return 0;
        }
        int cnt = 0;
        unsigned long long tmp = n;
        n = 0;
        while (tmp > 9) {
            n += binaryPower(10, cnt) * (tmp % 10);
            ++cnt;
            tmp /= 10;
        }
    }
    cout << "True\n";
    return 0;
}
```

***Python:***

```py
import math

def primality(n: int):
    if n < 2:
        return False
    
    if n == 2 or n == 3:
        return True
    
    if n % 2 == 0:
        return False
    
    for i in range(3, math.ceil(math.sqrt(n)), 2):
        if n % i == 0:
            return False
    
    return True


def binaryPower(a: int, b: int):
    if b == 0:
        return 1
    
    if b == 1:
        return a
    
    temp = binaryPower(a, b // 2)
    if b % 2 == 0:
        return temp * temp
    
    return temp * temp * a


def solution(n: int):
    while n > 0:
        if primality(n) == False:
            return False
        
        counter = 0
        temp = n
        n = 0
        
        while temp > 9:
            n += binaryPower(10, counter) * (temp % 10);
            counter += 1
            temp //= 10
    
    return True
    


n = int(input())
print(solution(n))
```
