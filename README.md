# CppIter
A simple LINQ library for C++.

## Usage
To find numbers that are powers of two between 0 and 1000
``` c++
using cppiter::iter;
using ranges::views::iota;

auto it = iter(iota(0, 1000)).where([](int x) { return x && (!(x&(x-1))); });
```

## Supported methods
* where
* map
