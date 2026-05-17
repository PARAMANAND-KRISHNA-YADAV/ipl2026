#include <stdio.h>

// Function to print bits
void printBits(int n)
{
    int i;

    for(i = sizeof(int) * 8 - 1; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);
    }

    printf("\n");
}

// Function to count number of 1 bits
int countOnes(int n)
{
    int count = 0;

    while(n)
    {
        n = n & (n - 1);
        count++;
    }

    return count;
}

int main()
{
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Bits of %d are:\n", num);
    printBits(num);

    printf("Number of 1 bits = %d\n", countOnes(num));

    return 0;
}