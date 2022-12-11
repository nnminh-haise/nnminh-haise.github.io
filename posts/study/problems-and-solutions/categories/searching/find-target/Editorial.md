
# Số cần tìm | Editorial - Lời giải

> *Tags: Searching, Binary search, basic*

## Statement - Đề bài

Cho một dãy $A$ gồm $n \; (1 \le n \le 100)$ phần tử $a_1, a_2, a_3, \ldots, a_n \; (1 \le a_i \le 100)$ là các số nguyên dương và số nguyên dương $k \; (1 \le k \le 100)$.

***Yêu cầu:*** Sau khi sắp xếp dãy, đưa ra tất cả vị trí xuất hiện số $k$ trong dãy đã sắp xếp theo chiều tăng dần. Lưu ý: dãy được đánh chỉ số từ $0$.

### Input - Dữ liệu vào

- Dòng đầu tiên gồm hai số nguyên dương $n$ và $k$ như mô tả.
- Dòng thứ hai gồm $n$ số nguyên dương $a_1, a_2, a_3, \ldots, a_n$.

### Output - Dữ liệu ra

- Một dòng duy nhất có (hoặc không) các giá trị là vị trí xuất hiện của số $k$ trong dãy đã sắp xếp theo thứ tự tăng dần.

---

## Solution - Giải thuật

Có thể áp dụng thuật toán tìm kiếm nhị phân vào bài toán như sau: tìm kiếm vị trí xuất hiện nhỏ nhất của số $k$ trong dãy và tìm kiếm vị trí xuất hiện lớn nhất của $k$ trong dãy. Kết quả bài toán là tất cả các chỉ số ở giữa hai vị trí trên.

***C++:***

```cpp
#include <bits/stdc++.h>

using namespace std;

vector < int > targetIndices(vector < int > &nums, int target) {
    int low = 1e9 + 7;
    int high = -1;

    sort(nums.begin(), nums.end());

    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (right - left + 1) / 2 + left;
        if (target <= nums[mid]) {
            if (target == nums[mid]) {
                low = min(low, mid);
            }
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
        int mid = (right - left + 1) / 2 + left;
        if (target >= nums[mid]) {
            if (target == nums[mid]) {
                high = max(high, mid);
            }
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    vector < int > res;
    if (low == 1e9 + 7 || high == -1 || low > high) {
        return res;
    }
    for (int i = low; i <= high; ++i) {
        res.push_back(i);
    }
    return res;
}

int main() {
    int n, target;
    cin >> n >> target;
    vector < int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector < int > res = targetIndices(a, target);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << (i < res.size() - 1 ? " " : "\n");
    }

    return 0;
}
```

***Python:***

```py
def targetIndices(nums: list[int], target: int) -> list[int]:
    low, high = 10000, -1
    
    nums = sorted(nums)
    
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = (right - left + 1) // 2 + left
        if target <= nums[mid]:
            if target == nums[mid]:
                low = min(low, mid)
            right = mid - 1
        else:
            left = mid + 1
    
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = (right - left + 1) // 2 + left
        if target >= nums[mid]:
            if target == nums[mid]:
                high = max(high, mid)
            left = mid + 1
        else:
            right = mid - 1
    
    if low == 10000 or high == -1 or low > high:
        return []
    return [i for i in range(low, high + 1)]
```