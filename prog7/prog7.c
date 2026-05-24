#include <stdio.h>
#include <string.h>

// Function to create LPS array
void computeLPS(char pattern[], int m, int lps[])
{
    int len = 0;
    lps[0] = 0;

    int i = 1;

    while(i < m)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to find substring index using KMP
int KMP_Search(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[m];

    computeLPS(pattern, m, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while(i < n)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }

        // Pattern found
        if(j == m)
        {
            return (i - j);
        }

        // Mismatch after j matches
        else if(i < n && text[i] != pattern[j])
        {
            if(j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return -1; // Pattern not found
}

int main()
{
    char text[100], pattern[100];

    printf("Enter the main string: ");
    scanf("%s", text);

    printf("Enter the substring: ");
    scanf("%s", pattern);

    int index = KMP_Search(text, pattern);

    if(index != -1)
    {
        printf("Substring found at index %d\n", index);
    }
    else
    {
        printf("Substring not found\n");
    }

    return 0;
}