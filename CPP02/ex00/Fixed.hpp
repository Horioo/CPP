#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	
	public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

	private:
	int fp_number;
	static const int bits = 8;

};

#endif