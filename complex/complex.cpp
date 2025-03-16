#include "rsr::complex.hpp"

namespace rsr {

	complex::complex() : real(0), imag(0) {};
	complex::complex(double real) : real(real), imag(0) {};
	complex::complex(double real, double imag) : real(real), imag(imag) {};
	complex::complex(const complex &z) : real(z.real), imag(z.imag) {};

	std::string to_string() const {
		
		std::stringstream sstream;
		
		// No parentheses if only one component is non-zero
		if(!this->imag)
			sstream << this->real;
		else if(!this->real)
			sstream << this->imag << 'i';
		// Otherwise, convert to format ({a} [+-] {b}i)
		else
			sstream << '(' << this->real << ' ' << (this->imag < 0 ? '-' : '+') << ' ' << std::abs(this->imag) << "i)";
		
		return sstream.str();
		
	}

	/* "Hypotenuse" - sometimes called absolute value for complex numbers, using hyp here to allow us to use abs for making both parts positive */
	double complex::hyp() const {
		return std::sqrt(std::pow(this->real, 2) + std::pow(this->imag, 2));
	}
	/* "Absolute value" - used here like real absolute values */
	complex complex::abs() const {
		return complex(std::abs(this->real), std::abs(this->imag));
	}
	/* "Argument" - gives the principal angle from the positive X-axis to the hypotenuse line of the complex number */
	double complex::arg() const {
		return std::atan2(this->imag, this->real);
	}

	/* Simple copy */
	void complex::operator=(const complex &z) {
		this->real = z.real;
		this->imag = z.imag;
	}

	/* Basic arithmetic operations */
	// (a + bi) + (c + di) = (a + c) + (b + d)i
	void complex::operator+=(const complex &z) {
		this->real += z.real;
		this->imag += z.imag;
	}
	// (a + bi) - (c + di) = (a - c) + (b - d)i
	void complex::operator-=(const complex &z) {
		this->real -= z.real;
		this->imag -= z.imag;
	}
	// (a + bi) * (c + di) = (ac - bd) + (bc + ad)i
	void complex::operator*=(const complex &z) {
		this->real = (this->real * z.real - this->imag * z.imag);
		this->imag = (this->imag * z.real + this->real * z.imag);
	}
	// (a + bi) / (c + di) = ((a + bi) / (c + di)) * (~(c + di) / ~(c + di))
	//						 ((ac + bd) / (c^2 + d^2)) + ((bc - ad) / (c^2 + d^2))i
	void complex::operator/=(const complex &z) {
		
		double denominator = std::pow(z.real, 2) + std::pow(z.imag, 2);
		*this *= z;
		
		this->real /= denominator;
		this->imag /= denominator;
		
	}
	complex complex::operator+(const complex &z) const {
		
		complex result(*this);
		
		result += z;
		return result;
		
	}
	complex complex::operator-(const complex &z) const {
		
		complex result(*this);
		
		result -= z;
		return result;
		
	}
	complex complex::operator*(const complex &z) const {
		
		complex result(*this);
		
		result *= z;
		return result;
		
	}
	complex complex::operator/(const complex &z) const {
		
		complex result(*this);
		
		result /= z;
		return result;
		
	}

	/* Powers (oh goodness) */
	void complex::operator^=(const complex &z) {
		
		double r = std::sqrt(std::pow(this->real, 2) + std::pow(this->imag, 2));
		double d_ln_r = z.imag * std::log(r);
		
		double theta = this->arg();
		double c_theta = z.real * theta;
		
		// r^c * e^(-d * theta)
		double r_tt_c_e_tt_neg_d_theta = std::pow(r, z.real) * exp(-z.imag * theta);
		
		this->real = r_tt_c_e_tt_neg_d_theta * std::cos(c_theta + d_ln_r);
		this->imag = r_tt_c_e_tt_neg_d_theta * std::sin(c_theta + d_ln_r);
		
	}
	complex complex::operator^(const complex &z) const;

	/* complex conjugate */
	complex complex::operator~() const {
		return complex(this->real, -this->imag);
	}
	/* Negation */
	complex complex::operator-() const {
		return complex(-this->real, -this->imag);
	}
	
	bool complex::operator==(const complex &z) const {
		return this->hyp() == z.hyp();
	}
	bool complex::operator!=(const complex &z) const {
		return this->hyp() != z.hyp();
	}
	bool complex::operator<=(const complex &z) const {
		return this->hyp() <= z.hyp();
	}
	bool complex::operator>=(const complex &z) const {
		return this->hyp() >= z.hyp();
	}
	bool complex::operator<(const complex &z) const {
		return this->hyp() < z.hyp();
	}
	bool complex::operator>(const complex &z) const {
		return this->hyp() > z.hyp();
	}

}

/* Overloads for real numbers on the LHS, complex on the RHS */
rsr::complex operator+(const double a, const rsr::complex &z) {
	return complex(a) + z;
}
rsr::complex operator-(const double a, const rsr::complex &z) {
	return complex(a) - z;
}
rsr::complex operator*(const double a, const rsr::complex &z) {
	return complex(a) * z;
}
rsr::complex operator/(const double a, const rsr::complex &z) {
	return complex(a) / z;
}
rsr::complex operator^(const double a, const rsr::complex &z) {
	return complex(a) ^ z;
}

bool operator==(const double a, const rsr::complex &z) {
	return a == z.hyp();
}
bool operator!=(const double a, const rsr::complex &z) {
	return a != z.hyp();
}
bool operator<=(const double a, const rsr::complex &z) {
	return a <= z.hyp();
}
bool operator>=(const double a, const rsr::complex &z) {
	return a >= z.hyp();
}
bool operator<(const double a, const rsr::complex &z) {
	return a < z.hyp();
}
bool operator>(const double a, const rsr::complex &z) {
	return a > z.hyp();
}