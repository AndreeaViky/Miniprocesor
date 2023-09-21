#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int a, int b)
{
    int c = 1;
    for (int i = 0; i < b; i++)
        c = c * a;

    return c;
}

int equation(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
    if (c == '/')
        return a / b;
}

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

    char op[n];

    for (int i = 0; i < n; i++, bitIndex += -2)
    {
        int var = ((number >> bitIndex) & true) * 2;
        var += ((number >> (bitIndex - 1)) & true) * 1;

        if (var == 0)
            op[i] = '+';
        if (var == 1)
            op[i] = '-';
        if (var == 2)
            op[i] = '*';
        if (var == 3)
            op[i] = '/';
    }

    for (int i = 0, p = 8; i < 4; i++, p /= 2, bitIndex += -1)
    {
        int bit = number >> bitIndex;
        dim += p * (bit & true);
    }

    printf("\nInstruction: %d ", n);
    for (int i = 0; i < n; i++)
        printf("%c ", op[i]);
    printf("%d\n", dim);

    int numbers;
    if ((((n + 1) * dim) % 16) != 0)
        numbers = (n + 1) * dim / 16 + 1;
    else
        numbers = ((n + 1) * dim) / 16;

    printf("Numbers to insert: %d\n", numbers);

    int values[numbers];
    int operands[numbers * (16 / dim)];
    int operandsIndex = 0;

    for (int i = 0; i < numbers; i++)
    {
        scanf("%d", &values[i]);
    }

    for (int i = 0; i < numbers; i++)
    {
        for (int j = bitSize / 2 - 1; j > 0; j -= dim)
        {
            int total = 0;
            for (int index = j, p = power(2, dim - 1); index > j - dim;
                 index--, p = p / 2)
            {
                int bit = values[i] >> index;
                total += p * (bit & 1);
            }
            operands[operandsIndex] = total;
            operandsIndex++;
        }
    }

    int result = operands[0];
    for (int i = 1; i < n + 1; i++)
    {
        result = equation(result, operands[i], op[i - 1]);
    }
    printf("Result: %d\n", result);
}

int main()
{
    int nr = 0;
    scanf("%d", &nr);

    getInstruction(nr);

    return 0;
}
