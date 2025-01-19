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
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed operator++(void);
	Fixed operator++(int);
	Fixed operator--(void);
	Fixed operator--(int);
	

	~Fixed();

	float 	toFloat(void) const;
	int 	toInt(void) const;
	int 	getRawBits(void) const;
	void 	setRawBits(int const raw);
	static Fixed min(Fixed &n1, Fixed &n2);
	static const Fixed min(const Fixed &n1, const Fixed &n2);
	static Fixed max(Fixed &n1, Fixed &n2);
	static const Fixed max(const Fixed &n1, const Fixed &n2);

	private:
	int fp_number;
	static const int bits = 8;

};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif