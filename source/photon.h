#ifndef RANDOM_PHOTON_H_
#define RANDOM_PHOTON_H_

#include "terry.h"

#ifndef PHOTON_BLOCK_SIZE
#define PHOTON_BLOCK_SIZE 20
#endif

#ifndef PHOTON_SPIN_INCREMENT
#define PHOTON_SPIN_INCREMENT 111111U
#endif

typedef struct {
    u32 elements[PHOTON_BLOCK_SIZE];
    u32 a;
    u32 b;
    u32 c;
    int index;                  /* has to contain 0..PHOTON_BLOCK_SIZE */
    int has_primed;
} photon_t;

photon_t photon_init(u64 init_a, u64 init_b);
u32 photon32(photon_t * randomp);

photon_t random_init(u64 initial);
u32 random32(photon_t * randomp);

#endif /* RANDOM_PHOTON_H_ */
