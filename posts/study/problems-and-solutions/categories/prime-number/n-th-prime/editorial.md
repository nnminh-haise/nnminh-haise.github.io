
# Số nguyên tố thứ n | Editorial - Lời giải

> *Tags: Prime number, Math, Basic*

## Statement - Đề bài

Cho một số nguyên dương $n$, hãy in ra màn hình số nguyên tố thứ $n$. Biết số nguyên tố thứ nhất là $2$.

***Yêu cầu:*** In ra số nguyên tố thứ $n$.

### Input - Dữ liệu vào

- Dòng đầu tiên là số nguyên dương $q \; (1 \le q \le 10000)$ - số lượng truy vấn cần trả lời.
- $q$ dòng tiếp theo, mỗi dòng là một số nguyên dương $n \; (1 \le n \le 100000)$ ứng với một truy vấn.

### Output - Dữ liệu ra

- Gồm $q$ dòng, mỗi dòng là

### Subtasks

- Subtask $1$ ($25\%$ số điểm) thỏa mãn: $q = 1$.
- Subtask $2$ ($75\%$ số điểm) không có ràng buộc gì thêm.

---

## Solution - Giải thuật

### Naive solution - Giải thuật ngây thơ

Giả sử ta có một biến $p$ có giá trị tăng từ $2 \rightarrow \inf$ và một biến $counter = 0$. Với mỗi giá trị $p$, nếu $p$ đang xét là một số nguyên tố thì ta sẽ tăng giá trị của biến $counter$ lên $1$. Nếu giá trị $counter = n$ thì dừng việc tăng $p$ và giá trị $p$ hiện tại là số nguyên tố thứ $n$.

***Độ phức tạp thuật toán:*** Vì số nguyên tố thứ $10^5$ có giá trị gần bằng $10^6$ nên độ phức tạp thuật toán trên sẽ gần bằng $O(q \times 10^6 \times \sqrt{10^6}) = O(10^4 \times 10^6 \times 10^3) = O(10^{13})$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
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

int main() {
	int queries;
    cin >> queries;
    while (queries--) {
        int n, p = 1, counter = 0;
        cin >> n;
        while (counter != n) {
            ++p;
            if (is_prime(p) == true) {
                ++counter;
            }
        }
        cout << p << endl;
    }

    return 0;
}
```

***Python:***

```py
import math


def is_prime(n: int):
    if (n < 2):
        return False
    
    if (n == 2 or n == 3):
        return True
    
    if (n % 2 == 0):
        return False
    
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if (n % i == 0):
            return False

    return True


queries = int(input())

while (queries):
    queries -= 1
    
    n = int(input())
    p = 1
    counter = 0
    
    while (counter != n):
        p += 1
        if (is_prime(p) == True):
            counter += 1
    
    print(p)
```

### Optimized solution - Giải thuật tối ưu

Giả sử, ta có một tập hợp $F$ chứa $10^5$ số nguyên tố đầu tiên. Khi đó để trả lời truy vấn, ta chỉ cần lấy ra số nguyên tố thứ $n$ trong tập hợp $F$. Thời gian để trả lời một truy vấn là $O(1)$, do đó thời gian để trả lời $q$ truy vấn là $O(q)$.

Vấn đề còn lại chỉ là làm sao để tạo ra được tập hợp $F$. Mình gợi ý thuật toán sàng số nguyên tố để tạo tập hợp $F$ với độ phức tạp $(n \log \log n)$.

***Độ phức tạp thời gian:*** $O(n \log \log n)$.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

vector < int > sieve() {
	int n = 2e6;
	vector < int > res, is_prime(n + 1, 1);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; ++i) {
		if (is_prime[i] == true && (long long)i * i <= n) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (is_prime[i] == true) {
			res.push_back(i);
		}
	}
	return res;
}

int main() {
	vector < int > primes = sieve();
	int queries;
	cin >> queries;
	while (queries--) {
		int n;
		cin >> n;
		cout << primes[n - 1] << endl;
	}

    return 0;
}
```

***Python:***

```py
def sieve():
	n = 2000000

	is_prime = [True for i in range(0, n + 1)]
	primes = list()

	is_prime[0] = is_prime[1] = False
	for i in range(2, n + 1):
		if is_prime[i] == True and i * i <= n:
			for j in range(i * i, n + 1, i):
				is_prime[j] = False
	
	for i in range(1, n + 1):
		if is_prime[i] == True:
			primes.append(i)

	return primes


primes = sieve()
queries = int(input())

while queries:
	queries -= 1
	n = int(input())
	print(primes[n - 1])
```
