
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#include <gmp.h>
#include <gmpxx.h>




int main(void)
{
	mpz_class a, b, c;

	a = 1234;
	b = "-5678";
	c = a + b;
	std::cout << "sum is " << c << "\n";
	std::cout << "absolute value is " << abs(c) << "\n" << std::endl;

	std::cout << "fibonacci " << mpz_class::fibonacci(mpz_class {1234567890}) << "\n";
	std::cout << "factorial " << mpz_class::factorial(mpz_class {15}) << std::endl;

	std::cout << "ui " << a.get_ui() << "\n";
	std::cout << "mul " << a * b * c << "\n";

	mpz_class d = mpz_class::factorial(21);
	auto s = d.get_str(16);
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);
	// std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::toupper(c); });
	std::cout << "d " << d << " (0x" << s << ")" << std::endl;

	return 0;
}

