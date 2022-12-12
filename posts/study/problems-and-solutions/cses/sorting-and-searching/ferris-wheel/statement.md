
# Ferris Wheel

> *Nguồn: [Ferris Wheel - CSES Problem set](https://cses.fi/problemset/task/1090/).*

There are $n$ children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed $x$. You know the weight of every child.

What is the minimum number of gondolas needed for the children?

## Input - Dữ liệu vào

- The first input line contains two integers $n \; (1 \le n \le 2 \cdot 10^5)$ and $x \; (1 \le x \le 10^9)$: the number of children and the maximum allowed weight.

- The next line contains $n$ integers $p_1, p_2, \ldots, p_n \; (1 \le p_i \le x)$: the weight of each child.

## Output - Dữ liệu ra

- Print one integer: the minimum number of gondolas.

## Sample - Ví dụ

#### Input:

```
4 10
7 2 3 9
```

#### Output:

```
3
```

