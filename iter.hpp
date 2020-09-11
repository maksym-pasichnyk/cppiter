#pragma once

#include <range/v3/view/filter.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/all.hpp>

namespace cppiter {
	template <typename T>
	struct Iterator : T {
		using Item = decltype(*std::declval<T>().begin());

		template <typename Fn>
		inline constexpr auto where(Fn&& fn) noexcept {
			return cppiter::Iterator{ranges::views::filter(*this, std::forward<Fn>(fn))};
		}

		template <typename Fn>
		inline constexpr auto map(Fn&& fn) noexcept {
			return cppiter::Iterator{ranges::views::transform(*this, std::forward<Fn>(fn))};
		}

		template <typename U>
		inline constexpr auto zip(Iterator<U> iter) noexcept {
			return cppiter::Iterator{ranges::views::zip(*this, iter)};
		}

		template <typename Tp>
		inline constexpr Tp to() noexcept {
			return ranges::to<Tp>(*this);
		}

		inline constexpr auto collect() noexcept {
			return ranges::to<std::vector<Item>>(*this);
		}
	};

	template <typename T>
	Iterator(T) -> Iterator<T>;

	template <typename T>
	auto iter(T& self) {
		return Iterator{ranges::views::ref(self)};
	}

	template <typename T>
	auto iter(T&& self) {
		return Iterator{ranges::make_view_closure(std::forward<T>(self))};
	}
}