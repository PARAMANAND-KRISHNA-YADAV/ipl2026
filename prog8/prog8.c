#include <stdio.h>
#include <math.h>

// Function to move a disk
void moveDisk(char from, char to, int disk)
{
    printf("Move Disk %d from %c to %c\n", disk, from, to);
}

// Function to perform legal move
void legalMove(int rods[], char names[], int from, int to)
{
    // If source rod is empty
    if(rods[from] == 0)
    {
        rods[from] = rods[to];
        rods[to] = 0;
        moveDisk(names[to], names[from], rods[from]);
    }

    // If destination rod is empty
    else if(rods[to] == 0)
    {
        rods[to] = rods[from];
        rods[from] = 0;
        moveDisk(names[from], names[to], rods[to]);
    }

    // Smaller disk moves
    else if(rods[from] < rods[to])
    {
        int temp = rods[from];
        rods[from] = 0;
        rods[to] = temp;
        moveDisk(names[from], names[to], temp);
    }
    else
    {
        int temp = rods[to];
        rods[to] = 0;
        rods[from] = temp;
        moveDisk(names[to], names[from], temp);
    }
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    int totalMoves = pow(2, n) - 1;

    char A = 'A', B = 'B', C = 'C';

    // For even disks swap destination and auxiliary
    if(n % 2 == 0)
    {
        char temp = B;
        B = C;
        C = temp;
    }

    // Top disk on each rod
    int rods[3];

    rods[0] = 1; // smallest disk initially
    rods[1] = 0;
    rods[2] = 0;

    char names[3] = {A, B, C};

    int i;

    for(i = 1; i <= totalMoves; i++)
    {
        if(i % 3 == 1)
        {
            legalMove(rods, names, 0, 2);
        }
        else if(i % 3 == 2)
        {
            legalMove(rods, names, 0, 1);
        }
        else
        {
            legalMove(rods, names, 1, 2);
        }
    }

    return 0;
}