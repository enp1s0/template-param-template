#include <iostream>


template <int _a>
struct policy_with_int {static const int a = _a;};

struct policy{};

template <class, class=void>
struct main_struct {void operator()(){std::printf("Default op()\n");}};

template <int a>
struct main_struct<policy_with_int<a>, std::enable_if_t<(a < 64)>> {
	void operator()(){std:printf("op() for paramed-mode, a < 64\n");}
};

template <int a>
struct main_struct<policy_with_int<a>, std::enable_if_t<(a < 128 && 64 <= a)>> {
	void operator()(){std:printf("op() for paramed-mode, a < 128\n");}
};

template <int a>
struct main_struct<policy_with_int<a>, std::enable_if_t<(a >= 128)>> {
	void operator()(){std:printf("op() for paramed-mode, otherwise\n");}
};

int main() {
	main_struct<void>{}();
	main_struct<int>{}();
	main_struct<policy>{}();
	main_struct<policy_with_int<10>>{}();
	main_struct<policy_with_int<100>>{}();
	main_struct<policy_with_int<1000>>{}();
}
