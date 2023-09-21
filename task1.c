#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

    printf("%d ", n);
    for (int i = 0; i < n; i++)
        printf("%c ", op[i]);
    printf("%d\n", dim);
}

int main()
{
    int nr = 0;
    scanf("%d", &nr);

    getInstruction(nr);

    return 0;
}
