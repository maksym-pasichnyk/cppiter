# CppIter
A simple iterator library for C++.

## Usage
``` c++
using cppiter::iter;
using ranges::views::iota;

//To find numbers that are powers of two between 0 and 1000
auto it = iter(iota(0, 1000)).where([](int x) { return x && (!(x&(x-1))); });

auto vector_of_nums = it.collect();

```

## Supported methods
* where
* map
* collect
* to<T>
