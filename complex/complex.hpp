#include <cmath> // For trig functions

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

/* Overloads for real numbers on the LHS, complex on the RHS */
complex operator+(const double a, const complex &z);
complex operator-(const double a, const complex &z);
complex operator*(const double a, const complex &z);
complex operator/(const double a, const complex &z);
complex operator^(const double a, const complex &z);