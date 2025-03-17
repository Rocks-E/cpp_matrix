#pragma once

#include <array>
#include <cinttypes>
#include <cstdlib>
#include "../complex/complex.hpp"

namespace rsr {
	
	template <size_t N>
	class vector {
		
	private:
	
	protected:
		std::array<complex, N> data;
	
	public:
		vector() {}
		vector(const complex *vector_data) {
			for(size_t c = 0; c < N; c++)
				this->data[c] = vector_data[c];
		}
		vector(const vector<N> &v) : data(v.data) {}
		virtual ~vector() {}
		
		size_t size() const {
			return N;
		}
		
		std::string to_string() const {
		
			std::stringstream sstream;
			
			sstream << '[';
			for(size_t c = 0; c < (N - 1); c++)
				sstream << this->data[c] << ", ";
			sstream << this->data[N - 1] << ']';
			
			return sstream.str();
			
		}
		
		double norm(double p = 2) const {
		
			double temp;
			
			if(p >= 1) {
				
				for(size_t c = 0; c < N; c++)
					temp += std::pow(this->data[c].hyp(), p);
				
				temp = std::pow(temp, (1 / p));
				
			}
			else
				for(size_t c = 0; c < N; c++)
					if(temp < this->data[c])
						temp = this->data[c];
			
			return temp;
			
		}
		
		complex operator[](int64_t index) const {
			return (*this)[index];
		}

		complex &operator[](int64_t index) {
			
			size_t adjusted_index = static_cast<size_t>((index < 0) ? N - index : index);
			
			return (adjusted_index < N) ? this->data[adjusted_index] : COMPLEX_MAX;
			
		}
		
		/* Scalar operations - will apply to all entries */
		void operator+=(complex &z) {
			for(size_t c = 0; c < N; c++)
				this->data[c] += z;
		}
		void operator-=(complex &z) {
			for(size_t c = 0; c < N; c++)
				this->data[c] -= z;
		}
		void operator*=(complex &z) {
			for(size_t c = 0; c < N; c++)
				this->data[c] *= z;
		}
		void operator/=(complex &z) {
			for(size_t c = 0; c < N; c++)
				this->data[c] /= z;
		}
		vector operator+(complex &z) const {
			
			vector result(*this);
			result += z;
		
			return result;
			
		}
		vector operator-(complex &z) const {
			
			vector result(*this);
			result -= z;
		
			return result;
			
		}
		vector operator*(complex &z) const {
			
			vector result(*this);
			result *= z;
		
			return result;
			
		}
		vector operator/(complex &z) const {
			
			vector result(*this);
			result /= z;
		
			return result;
			
		}
		
		/* Vector operations - requires vectors of the same size */
		void operator+=(vector<N> &v) {
			for(size_t c = 0; c < N; c++)
				this->data[c] += v.data[c];
		}
		void operator-=(vector<N> &v) {
			for(size_t c = 0; c < N; c++)
				this->data[c] -= v.data[c];
		}
		// Component-wise multiplication
		void operator*=(vector<N> &v) {
			for(size_t c = 0; c < N; c++)
				this->data[c] *= v.data[c];
		}
		// Cross product - only works for 3-dimensional vector
		// Yes I am ignoring the 7-dimensional case
		void operator%=(vector &v) {
			
			// Ugh
			if(N != 3) return;
			
			complex s0 = this->data[1] * v.data[2] - this->data[2] * v.data[1];
			complex s1 = this->data[2] * v.data[0] - this->data[0] * v.data[2];
			complex s2 = this->data[0] * v.data[1] - this->data[1] * v.data[0];
			
			this->data[0] = s0;
			this->data[1] = s1;
			this->data[2] = s2;
			
		}
		vector operator+(vector<N> &v) const {
			
			vector result(*this);
			result += v;
			
			return result;
			
		}
		vector operator-(vector<N> &v) const {
			
			vector result(*this);
			result -= v;
			
			return result;
			
		}
		vector operator*(vector<N> &v) const {
			
			vector result(*this);
			result *= v;
			
			return result;
			
		}
		vector operator%(vector &v) const {
			
			vector result(*this);
			result %= v;
			
			return result;
			
		}
		
		/* Misc operations - I don't know where else to put these */
		// Inner product
		complex operator|(vector<N> &v) const {
			
			complex result;
		
			// Multiply each component of x by the conjugate component of y
			// For real vectors, this will just be xy
			for(size_t c = 0; c < N; c++)
				result += this->data[c] * ~v.data[c];
			
			return result;
			
		}
		
		/* Comparisons - I don't really see a way to consistently implement others */
		bool operator==(vector<N> &v) const {
			
			for(size_t c = 0; c < N; c++)
				if(this->data[c] != v.data[c])
					return false;
			
			return true;
			
		}
		bool operator!=(vector<N> &v) const {
			return !(*this == v);
		}
		
	};
	
}

template <size_t N>
rsr::vector<N> operator+(const rsr::complex &z, const rsr::vector<N> &v) {
	return v + z;
}
template <size_t N>
rsr::vector<N> operator-(const rsr::complex &z, const rsr::vector<N> &v) {
	return -v + z;
}
template <size_t N>
rsr::vector<N> operator*(const rsr::complex &z, const rsr::vector<N> &v) {
	return v * z;
}
template <size_t N>
rsr::vector<N> operator/(const rsr::complex &z, const rsr::vector<N> &v) {
	
	rsr::vector<N> result;
	
	for(size_t c = 0; c < N; c++)
		result[c] = 1 / v[c];
	
	return result;
	
}

template <size_t N>
std::ostream &operator<<(std::ostream &os, const rsr::vector<N> &v) {
	
	os << v.to_string();
	return os;
	
}