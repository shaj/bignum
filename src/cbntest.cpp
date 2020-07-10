
#include <iostream>

#include <ctbignum/ctbignum.hpp>

// Initialization via (user-defined) literal 
// (with automatic deduction of number of limbs)

using namespace cbn::literals;
constexpr auto number = cbn::to_big_int(6513020836420374401749667047018991798096360820_Z);
constexpr cbn::big_int<3> expected_result = {1315566964, 326042948, 19140048};

static_assert(number == expected_result, "initialization failure");

int main(void)
{
	std::cout << cbn::to_big_int(123456789012345678901234567890_Z) << '\n';
	std::cout << number << "\n";
	std::cout << expected_result << "\n";

	std::cout << std::endl;

	return 0;
}