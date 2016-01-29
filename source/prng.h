#ifndef PRNG
#define PRNG

inline unsigned int prng_tetra_master(quint32 seed)
{
    return seed * 0x41C64E6D + 0x3039;
}

#endif // PRNG

