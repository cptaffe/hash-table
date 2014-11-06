
// Hash header

#ifndef HASH_H_
#define HASH_H_

#include <stdint.h> // int64_t

// hash function takes a string as a key,
// returns hash value as an int64_t.
uint64_t hash(char *key);

#endif // HASH_H_
