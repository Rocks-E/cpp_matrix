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
#if defined(_VERBOSE)
	std::cout << "\tEmpty constructor pass\n";
#endif
	assert((b[0] == rsr::complex(0, 0)) && (b[1] == rsr::complex(1, 0)) && (b[2] == rsr::complex(1.45, -0.95)));
#if defined(_VERBOSE)
	std::cout << "\tArray constructor pass\n";
#endif
	assert(c == d);
#if defined(_VERBOSE)
	std::cout << "\tCopy constructor pass\n";
#endif

	
	assert(a.size() == 3);
	
#if defined(_VERBOSE)
	std::cout << "Index tests\n";
#endif
	rsr::vector<7> vec7;
	for(size_t c = 0; c < vec7.size(); c++)
		vec7[c] = rsr::complex(c);
	assert(vec7[-9].real == 5);
	assert(vec7[-8].real == 6);
	assert(vec7[-7].real == 0);
	assert(vec7[-6].real == 1);
	assert(vec7[-5].real == 2);
	assert(vec7[-4].real == 3);
	assert(vec7[-3].real == 4);
	assert(vec7[-2].real == 5);
	assert(vec7[-1].real == 6);
	assert(vec7[0].real == 0);
	assert(vec7[1].real == 1);
	assert(vec7[2].real == 2);
	assert(vec7[3].real == 3);
	assert(vec7[4].real == 4);
	assert(vec7[5].real == 5);
	assert(vec7[6].real == 6);
	assert(vec7[7].real == 0);
	assert(vec7[8].real == 1);
	assert(vec7[9].real == 2);
#if defined(_VERBOSE)
	std::cout << "\tIndexes pass\n";
#endif

	
	return 0;
	
}