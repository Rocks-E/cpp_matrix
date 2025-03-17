#if defined(_VERBOSE)
#include <iostream>
#endif
#include <cassert>
#include <cinttypes>
#include "../../vector/vector.hpp"

int32_t main() {
	
	rsr::complex comp_zeros[3];
	rsr::vector<3> zero(comp_zeros);
	
#if defined(_VERBOSE)
	std::cout << "Constructor tests\n";
#endif
	rsr::complex comp_bs[3] = {{}, {1}, {1.45, -0.95}};
	rsr::complex comp_cs[3] = {{1, 1}, {2, 2}, {3, 3}};
	rsr::vector<3> a, b(comp_bs), c(comp_cs);
	rsr::vector<3> d(c);
	
	assert(a == zero);
	assert(c == d);
	
	assert(a.size() == 3);
	
	return 0;
	
}