#include "grains.h"

#include <stddef.h>


uint64_t* create_and_populate_chessboard(void)
{
    // Should be static, because we are returning local array
    static uint64_t arr[64];

    arr[0] = 1;
    for (uint8_t i = 1; i < 64; ++i)
    {
        arr[i] = arr[i - 1] * 2;
    }

    return arr;
}

uint64_t* squares = NULL;

uint64_t square(uint8_t index)
{
    if (index < 1 || index > 64)
    {
        return 0; // Or throw an exception or add other error handling
    }
    if (squares == NULL)
    {
        squares = create_and_populate_chessboard();
    }
    return squares[index - 1];
}

uint64_t total(void)
{
    const int length = 64;
    uint64_t total = 0;
    for (int i = 0; i < length; ++i)
    {
        const uint64_t amount_on_square = squares[i];
        total += amount_on_square; // Add this line to accumulate the sum.
    }
    return total; // Don't forget to return the result.
}
