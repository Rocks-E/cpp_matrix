
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
		
		void operator+=(const complex &z);
		void operator-=(const complex &z);
		void operator*=(const complex &z);
		void operator/=(const complex &z);
		complex operator+(const complex &z) const;
		complex operator-(const complex &z) const;
		complex operator*(const complex &z) const;
		complex operator/(const complex &z) const;
		
	}
	
}

/* Overloads for real numbers on the LHS, complex on the RHS */
complex operator+(const double a, const complex &z);
complex operator-(const double a, const complex &z);
complex operator*(const double a, const complex &z);
complex operator/(const double a, const complex &z);