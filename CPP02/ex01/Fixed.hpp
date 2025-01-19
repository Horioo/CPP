#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	
	public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	float 	toFloat(void) const;
	int 	toInt(void) const;
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);

	private:
	int fp_number;
	static const int bits = 8;

};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif