#include <stdio.h>

// Structure with bitfields
struct Bitfield
{
    unsigned int firstbit  : 1;
    unsigned int secondbit : 2;
    unsigned int thirdbit  : 3;
};

int main()
{
    struct Bitfield a;

    // Assigning values
    a.firstbit = 1;
    a.secondbit = 2;
    a.thirdbit = 5;

    // Printing values
    printf("firstbit  = %u\n", a.firstbit);
    printf("secondbit = %u\n", a.secondbit);
    printf("thirdbit  = %u\n", a.thirdbit);

    return 0;
}