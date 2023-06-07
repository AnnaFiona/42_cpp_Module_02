#include "Fixed.hpp"
#include "limits.h"
/* void	fail(int my_output, int right_output)
{
	std::cout << "\033[0;91mFAIL\033[0m" << std::endl;
	std::cout << "My output:	" << my_output << std::endl;
	std::cout << "Right output:	" << right_output << std::endl << std::endl;
}
void	fail(float my_output, float right_output)
{
	std::cout << "\033[0;91mFAIL\033[0m" << std::endl;
	std::cout << "My output:	" << my_output << std::endl;
	std::cout << "Right output:	" << right_output << std::endl << std::endl;
}
void	fail(Fixed my_output, Fixed right_output)
{
	std::cout << "\033[0;91mFAIL\033[0m" << std::endl;
	std::cout << "My output:	" << my_output << std::endl;
	std::cout << "Right output:	" << right_output << std::endl << std::endl;
} */

void	ok(void)
{
	std::cout << "\033[0;92mOK \033[0m";
}
void	fail(void)
{
	std::cout << "\033[0;91mFAIL \033[0m";
}

void	compare(const char *test, float my_output, float right_output, char last)
{
	if (test != NULL)
		std::cout << test;
	if (my_output == right_output)
		std::cout << "\033[0;92mOK \033[0m";
	else
	{
		std::cout << "\033[0;91mFAIL\033[0m" << std::endl;
		std::cout << "My output:	" << my_output << std::endl;
		std::cout << "Right output:	" << right_output << std::endl;
	}
	if (last == 'y')
		std::cout << std::endl;
}
void	compare(const char *test, int my_output, int right_output, char last)
{
	if (test != NULL)
		std::cout << test;
	if (my_output == right_output)
		std::cout << "\033[0;92mOK \033[0m";
	else
	{
		std::cout << "\033[0;91mFAIL\033[0m" << std::endl;
		std::cout << "My output:	" << my_output << std::endl;
		std::cout << "Right output:	" << right_output << std::endl;
	}
	if (last == 'y')
		std::cout << std::endl;
}

int	main()
{
	Fixed	a(23.79f);
	Fixed	b(23.7948f);
	Fixed	c(29);
	Fixed	d(-2);
	Fixed	e(0);
	// Fixed	max(INT_MAX);
	// Fixed	maxPlusOne(INT_MAX + 1);
	// Fixed	min(INT_MIN);
	// Fixed	minMinusOne(INT_MIN - 1);

	compare("getRawBits: ", a.getRawBits(), 6090, 'n');
	compare(NULL, a.getRawBits(), 6090, 'y');

	c.setRawBits(2890);
	compare("setRawBits: ", c.getRawBits(), 2890, 'y');

	compare("toFloat: ", a.toFloat(), 23.79f, 'n');
	compare(NULL, d.toFloat(), -2.0, 'n');
	compare(NULL, e.toFloat(), 0.0, 'y');

	compare("toInt: ", a.toInt(), 23, 'n');
	compare(NULL, d.toInt(), -2, 'n');
	compare(NULL, e.toInt(), 0, 'y');
	// compare(NULL, max.toInt(), INT_MAX, 'y');
	// compare(NULL, maxPlusOne.toInt(), INT_MAX + 1, 'y');
	// compare(NULL, min.toInt(), INT_MIN, 'y');
	// compare(NULL, minMinusOne.toInt(), INT_MIN, 'y');

	//comparison-operators
	std::cout << "/// comparison operators ///" << std::endl;
	std::cout << ">: ";
	if (d > 0)
		fail();
	else {ok();}
	if (b > a)
		ok();
	else {fail();}
	std::cout << std::endl;

	std::cout << "<: ";
	if (d < 0)
		ok();
	else {fail();}
	if (b < a)
		fail();
	else {ok();}
	std::cout << std::endl;

	std::cout << ">=: ";
	if (e >= 0)
		ok();
	else {fail();}
	if (a >= b)
		fail();
	else {ok();}
	std::cout << std::endl;

	std::cout << "<=: ";
	if (d <= e)
		ok();
	else {fail();}
	if (b <= a)
		fail();
	else {ok();}
	std::cout << std::endl;

	std::cout << "==: ";
	if (e == 0)
		ok();
	else {fail();}
	if (a == b)
		fail();
	else {ok();}
	std::cout << std::endl;

	std::cout << "!=: ";
	if (b != a)
		ok();
	else {fail();}
	if (e != 0)
		fail();
	else {ok();}
	std::cout << std::endl;

	std::cout << "/// arithmetic operators ///" << std::endl;
	compare("+: ", e + d, -2.0, 'n');
	compare(NULL, d + a, 21.79, 'n');
	compare(NULL, c + b, 35.0838, 'n');
	compare(NULL, c + b, 35.082, 'y');

	compare("-: ", e - d, 2.0, 'n');
	compare(NULL, d - a, 25.79, 'n');
	compare(NULL, c - b, -12.5058, 'n');
	compare(NULL, c - b, -12.5039, 'y');

	compare("*: ", e * d, 2.0, 'n');
	compare(NULL, d * a, -47.58, 'n');
	compare(NULL, c * b, 268.6194972, 'n');
	compare(NULL, c * b, 268.6194972, 'y');

	compare("/: ", e / d, 0.0, 'n');
	compare(NULL, d / a, -0.084068937, 'n');
	compare(NULL, c / b, 0.474431388, 'y');

	//compare(NULL, , , 'n');
	// Fixed	a(23.79f);
	// Fixed	b(23.7948f);
	// Fixed	c(11.2890f);
	// Fixed	d(-2);
	// Fixed	e(0);
/* 	Fixed h(Fixed::max(a, b));
	Fixed::min(b, a);
	a.max(a, b);
	a.min(b, a); */


	return (0);
}