#include <stdio.h>
#include <math.h>

#define ROWS 25
#define COLS 50

// Function prototypes
void initializeBuffer(char buffer[ROWS][COLS]);
void drawCircle(char buffer[ROWS][COLS], int centerX, int centerY, int radius);
void printBuffer(char buffer[ROWS][COLS]);
int isCirclePoint(int x, int y, int centerX, int centerY, int radius);

int main()
{
    char buffer[ROWS][COLS];

    initializeBuffer(buffer);

    drawCircle(buffer, 25, 12, 10);

    printBuffer(buffer);

    return 0;
}

// Fill buffer with spaces
void initializeBuffer(char buffer[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            buffer[i][j] = ' ';
        }
    }
}

// Check whether point belongs to circle boundary
int isCirclePoint(int x, int y, int centerX, int centerY, int radius)
{
    int dx = x - centerX;
    int dy = y - centerY;

    int distanceSquared = dx * dx + dy * dy;
    int radiusSquared = radius * radius;

    // Small tolerance for smoother circle
    return abs(distanceSquared - radiusSquared) <= radius;
}

// Draw circle into buffer
void drawCircle(char buffer[ROWS][COLS], int centerX, int centerY, int radius)
{
    int x, y;

    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLS; x++)
        {
            if(isCirclePoint(x, y, centerX, centerY, radius))
            {
                buffer[y][x] = '*';
            }
        }
    }
}

// Print buffer on screen
void printBuffer(char buffer[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", buffer[i][j]);
        }
        printf("\n");
    }
}