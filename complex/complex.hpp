#pragma once

/* For trig functions */
#include <cmath>
/* For overloading ostream << for printing */
#include <ostream>
/* to_string() */
#include <sstream>
#include <string>

namespace rsr {
	
	class complex {
		
	private:
	
	protected:
		double a;
		double b;
	
	public:
		complex();
		complex(double real);
		complex(double real, double imag);
		complex(const &z);
		
		std::string to_string() const;
		
		double real() const;
		double &real();
		double imag() const;
		double &imag();
		
		/* "Hypotenuse" - sometimes called absolute value for complex numbers, using hyp here to allow us to use abs for making both parts positive */
		double hyp() const;
		/* "Absolute value" - used here like real absolute values */
		complex abs() const;
		
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
		
		
	}
	
}

inline std::ostream &operator<<(std::ostream &os, const complex &z) {
	
	os << z.to_string();
	return os;
	
}

/* Overloads for real numbers on the LHS, complex on the RHS */
complex operator+(const double a, const complex &z);
complex operator-(const double a, const complex &z);
complex operator*(const double a, const complex &z);
complex operator/(const double a, const complex &z);
complex operator^(const double a, const complex &z);