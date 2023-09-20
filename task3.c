#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

long power(int a, int b)
{
    int c = 1;
    for (int i = 0; i < b; i++)
    {
        c = c * a;
    }
    return c;
}

int ecuation(int a, int b, char c)
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

void getInstruction(int nr)
{
    int n = 0, dim = 0, i = 31;

    for (int j = 0, p = 4; j < 3; j++, p /= 2)
    {
        int k = nr >> i;
        n += p * (k & 1);
        i--;
    }
    n += 1;
    char op[n];

    for (int j = 0; j < n; j++)
    {
        int a = nr >> i;
        i += -1;
        int b = nr >> i;
        i += -1;

        int temp = (a & 1) * 2 + (b & 1);

        if (temp == 0)
            op[j] = '+';
        if (temp == 1)
            op[j] = '-';
        if (temp == 2)
            op[j] = '*';
        if (temp == 3)
            op[j] = '/';
    }

    for (int j = 0, p = 8; j < 4; j++, p /= 2)
    {
        int k = nr >> i;
        dim += p * (k & 1);
        i--;
    }
    dim += 1;

    int numbers; 
    if ((( (n+1) * dim) % 16) != 0)
        numbers = ((n+1) * dim)/16 + 1;
    else numbers = ((n+1) * dim)/16;
    
    int v[numbers];
    int operands[numbers * 16/dim];
    int operandsIndex = 0; 

    for (int i = 0; i < numbers; i++)
    {
        scanf ("%d", &v[i]);
    }

    int p;
    int bitIndex = 15; 
    int numbersIndex = 0; 
    for (int i = 0; i < numbers * (16/dim); i++)
    {
        int value = 0;
        for (int j = 0, p = power(2, dim - 1); j < dim; j++, p = p/2)
        {
            int a = v[numbersIndex] >> bitIndex;
            value += p * (a & 1);
            bitIndex --;

            if (bitIndex < 0)
            {
                numbersIndex++;
                bitIndex = 15;
            }
        } 
        operands[operandsIndex] = value;
        operandsIndex ++;
    }

    int result = operands[0];
    for (int i = 1; i < n+1; i++)
    {
        result = ecuation(result, operands[i], op[i-1]);
    }
    printf("%d\n", result);
}
int main()
{
    int nr = 0;
    scanf("%d", &nr);

    getInstruction(nr);

    return 0;
}