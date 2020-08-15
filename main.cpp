#include <iostream>
#include <range/v3/view/iota.hpp>

#include "iter.hpp"

int main() {
	using cppiter::iter;
	using ranges::views::iota;

	auto it = iter(iota(0, 1000)).where([](int x) { return x && (!(x&(x-1))); });

    for (int i : it) {
        std::cout << i << std::endl;
    }
}