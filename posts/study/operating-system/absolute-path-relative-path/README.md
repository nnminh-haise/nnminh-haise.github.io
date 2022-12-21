
# Absolute path & Relative path

> *Tags: Operating system, UNIX, MacOS, Linux.*

## Definition

A path is a unique location to a file or folder in a file system of an OS. A path is a collection of '/' and alpha-numeric characters.

---

## Absolute path

An absolute path is specifying location of a file or directory from the *root directory* (`/`).

To write an absolute-path name:

- Start at the root directory `/` and then work down.
- Write a `/` to seperate each directory name (*last one is optional*).

**Example:**

- `/home/code/solution.cpp`.
- `/home/usr/local/bin`.

*Here, `/home` is the root directory. And the file `solution.cpp` is two level away from `/home`.*

---

## Relative path

Relative path is defined as a path related to the present working directory (pwd). It starts at the current working directory and never starts with a `/`.

**Example:**

- `haise/code/solution.cpp`.
- `usr/local/bin`.

---

## Using `.` and `..` in relative path-names

- `.` (a single dot): represents the current directory.
- `..` (two dots): represents the parent directory.


