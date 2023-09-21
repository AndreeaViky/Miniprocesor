#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void getInstruction(int number) 
{
    int bitSize = 32;
    int n = 1, dim = 1;
    int bitIndex = bitSize - 1, bit;

    printf("Binary: ");
    for (int i = bitSize - 1; i > 0; i--) 
    {
        bit = number >> i;
        printf("%d", (bit & true));
    }

    for (int i = 0, p = 4; i < 3; i++, bitIndex += -1, p /= 2) 
    {
        bit = number >> bitIndex;
        n += p * (bit & true);
    }

    char op[n]

    for (int i = 0; i < n; i++, bitIndex += -2) 
    {
        int var = ((number >> bitIndex) & true) * 2;
        var += ((number >> (bitIndex - 1)) & true) * 1;

        if (var == 0) op[i] = '+';
        if (var == 1) op[i] = '-';
        if (var == 2) op[i] = '*';
        if (var == 3) op[i] = '/';
    }

    for (int i = 0, p = 8; i < 4; i++, p /= 2, bitIndex += -1) 
    {
        int bit = number >> bitIndex;
        dim += p * (bit & true);
    }

    printf("\nInstruction: %d ", n);
    for (int i = 0; i < n; i++) printf("%c ", op[i]);
    printf("%d\n", dim);
}

int main() 
{
    int number;

    printf("Insert number: ");
    scanf("%d", &number);

    getInstruction(number);

    return 0;
}
