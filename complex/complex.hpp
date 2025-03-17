#pragma once

/* For trig functions */
#include <cmath>
/* For overloading ostream << for printing */
#include <ostream>
/* to_string() */
#include <sstream>
#include <string>

namespace rsr {
	
	struct complex {

	public:
		double real;
		double imag;
	
		complex();
		complex(double real);
		complex(double real, double imag);
		complex(const complex &z);
		
		std::string to_string() const;
		
		/* "Hypotenuse" - sometimes called absolute value for complex numbers, using hyp here to allow us to use abs for making both parts positive */
		double hyp() const;
		/* "Absolute value" - used here like real absolute values */
		complex abs() const;
		double arg() const; 
		
		/* Simple copy */
		void operator=(const complex &z);
		
		/* Basic arithmetic operations */
		void operator+=(const complex &z);
		void operator-=(const complex &z);
		void operator*=(const complex &z);
		void operator/=(const complex &z);
		complex operator+(const complex &z) const;
		complex operator-(const complex &z) const;
		complex operator*(const complex &z) const;
		complex operator/(const complex &z) const;
		
		/* Powers (oh goodness) */
		void operator^=(const complex &z);
		complex operator^(const complex &z) const;
		
		/* Complex conjugate */
		complex operator~() const;
		/* Negation */
		complex operator-() const;
		
		/* Comparisons will be done on the hypotenuse length, meaning values like (a + bi), (a - bi), (-a + bi), and (-a - bi) are all equal */
		bool operator==(const complex &z) const;
		bool operator!=(const complex &z) const;
		bool operator<=(const complex &z) const;
		bool operator>=(const complex &z) const;
		bool operator<(const complex &z) const;
		bool operator>(const complex &z) const;
		
	};
	
}

inline std::ostream &operator<<(std::ostream &os, const rsr::complex &z) {
	
	os << z.to_string();
	return os;
	
}

/* Overloads for real numbers on the LHS, complex on the RHS */
rsr::complex operator+(const double a, const rsr::complex &z);
rsr::complex operator-(const double a, const rsr::complex &z);
rsr::complex operator*(const double a, const rsr::complex &z);
rsr::complex operator/(const double a, const rsr::complex &z);
rsr::complex operator^(const double a, const rsr::complex &z);

bool operator==(const double a, const rsr::complex &z);
bool operator!=(const double a, const rsr::complex &z);
bool operator<=(const double a, const rsr::complex &z);
bool operator>=(const double a, const rsr::complex &z);
bool operator<(const double a, const rsr::complex &z);
bool operator>(const double a, const rsr::complex &z);