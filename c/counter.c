#include <stdio.h>
#include <limits.h>

/*!
 * @brief Write a function that takes an integer as input, and returns the
 * number of bits that are equal to one in the binary representation of that
 * number. You can guarantee that input is non-negative.
 * Example: The binary representation of 1234 is 10011010010, so the function should return 5 in this case
 * @param value[in] The original value from which to count the bits that are equal to one
*/
size_t countBits(const unsigned int value);

int main(void)
{
    int original = 1234;
    unsigned int count = countBits(original);
    printf("%u\n", count);

    return 0;
}

size_t countBits(const unsigned int value)
{
    unsigned int bits = 1 << ((sizeof (value) * 8) - 1);
    unsigned int count = 0;

    while (bits) {
        count += value & bits ? 1 : 0;
	bits >>= 1;
    }

    return count;
}

