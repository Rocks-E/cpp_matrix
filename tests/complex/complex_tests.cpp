#include <iostream>
#include <cassert>
#include <cinttypes>
#include "../../complex/complex.hpp"

#define DEG(x) ((x) * 180 / M_PI)
#define EQUALS(a, b) (((a).real == (b).real) && ((a).imag == (b).imag))

int32_t main() {
	
	rsr::complex zero;
	
#if defined(_VERBOSE)
	std::cout << "Constructor tests\n";
#endif
	rsr::complex a, b(3.14), c(-1, 57.9412);
	rsr::complex d(c);
	
	assert(EQUALS(a, zero));
#if defined(_VERBOSE)
	std::cout << "\tEmpty constructor pass\n";
#endif
	assert(EQUALS(b, rsr::complex(3.14, 0)));
#if defined(_VERBOSE)
	std::cout << "\tReal constructor pass\n";
#endif
	assert(EQUALS(c, rsr::complex(-1, 57.9412)));
#if defined(_VERBOSE)
	std::cout << "\tFull constructor pass\n";
#endif
	assert(EQUALS(c, d));
#if defined(_VERBOSE)
	std::cout << "\tCopy constructor pass\n";
#endif
	
#if defined(_VERBOSE)
	std::cout << "Print/string tests\n";
#endif
#if defined(_VERBOSE)
	std::cout << "\tTo string: " << c.to_string() << '\n';
#endif
#if defined(_VERBOSE)
	std::cout << "\tImplicit print: " << d << '\n';
#endif
#if defined(_VERBOSE)
	std::cout << '\t' << a << '\n';
#endif
#if defined(_VERBOSE)
	std::cout << '\t' << b << '\n';
#endif
#if defined(_VERBOSE)
	std::cout << '\t' << rsr::complex(1, -1) << '\n';
#endif
#if defined(_VERBOSE)
	std::cout << '\t' << rsr::complex(0, 5.5) << '\n';
#endif
	
#if defined(_VERBOSE)
	std::cout << "Assignment test\n";
#endif
	a = c;
	assert(a == c);
#if defined(_VERBOSE)
	std::cout << "\tAssignment pass\n";
#endif
	
#if defined(_VERBOSE)
	std::cout << "Unary tests\n";
#endif
	rsr::complex pyth(3, 4), neg_pyth(-3, -4), conj_pyth(3, -4), neg_conj_pyth(-3, 4);
	assert(EQUALS(-pyth, neg_pyth));
#if defined(_VERBOSE)
	std::cout << "\tNegation pass\n";
#endif
	assert(EQUALS(~pyth, conj_pyth));
#if defined(_VERBOSE)
	std::cout << "\tConjugate pass\n";
#endif
	assert(EQUALS(-(~pyth), neg_conj_pyth));
	assert(EQUALS(~(-pyth), neg_conj_pyth));
#if defined(_VERBOSE)
	std::cout << "\tChaining negation and conjugate pass\n";
#endif
	assert((pyth.hyp() == neg_pyth.hyp()) && (pyth.hyp() == conj_pyth.hyp()) && (pyth.hyp() == neg_conj_pyth.hyp()) && (pyth.hyp() == 5));
#if defined(_VERBOSE)
	std::cout << "\tHypotenuse pass\n";
#endif
	assert(EQUALS(pyth, neg_conj_pyth.abs()));
#if defined(_VERBOSE)
	std::cout << "\tAbsolute value pass\n";
#endif
	assert(DEG(rsr::complex(1, 1).arg()) == 45);
#if defined(_VERBOSE)
	std::cout << "\tArgument pass\n";
#endif
	
#if defined(_VERBOSE)
	std::cout << "Binary tests\n";
#endif
	a = zero;
	a += c;
	assert(EQUALS(c + -d + c, a));
#if defined(_VERBOSE)
	std::cout << "\t+ pass\n";
#endif
	a -= d;
	assert(EQUALS(-c - -d, a));
#if defined(_VERBOSE)
	std::cout << "\t- pass\n";
#endif
	b = pyth;
	b *= conj_pyth;
	assert(EQUALS(pyth * conj_pyth, b));
#if defined(_VERBOSE)
	std::cout << "\t* pass\n";
#endif
	b = pyth;
	b /= conj_pyth;
	assert(EQUALS(b, pyth / conj_pyth));
#if defined(_VERBOSE)
	std::cout << "\t/ pass\n";
#endif
	b = pyth;
	b ^= conj_pyth;
	assert(EQUALS(b, pyth ^ conj_pyth));
#if defined(_VERBOSE)
	std::cout << "\t^ pass\n";
#endif
	
#if defined(_VERBOSE)
	std::cout << "Comparison tests\n";
#endif
	assert(pyth == neg_pyth);
	assert(pyth != zero);
	assert(c >= pyth);
	assert(a <= pyth);
	assert((pyth - 1) < pyth);
	assert((pyth + 1) > pyth);
#if defined(_VERBOSE)
	std::cout << "\tComparison pass\n";
#endif
	
	return 0;
	
}