
#include <stdint.h>
#include <math.h>
#include "hash.h"

// hash function
uint64_t hash(char *key) {

	uint64_t h = 0; // hash

	// CRC sequence of character hashing
	for (uint64_t i = 0; key[i] != '\0'; i++) {
		uint64_t hb = 0; // high bits

		// using bitmasking, endian dependant
		hb = h & 0xf800000000000000; // keeps high 5 bits of 64 bit number
		h = h << 5; // right shift by 5 bits
		h = h ^ (hb >> 59); // shift high 5 bits to lower 5 bits & xor with h
		h = h ^ key[i];
	}

	return h;
}
