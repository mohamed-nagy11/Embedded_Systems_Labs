#include <stdio.h>
#include <stdlib.h>

#define GET_BIT(num,bit) ((num>>bit)&1)

int main()
{
    unsigned long num;
    int bit;

    printf("Enter a decimal number: ");
    scanf("%lu", &num);

    printf("Enter the order of the bit (0-31): \n");
    printf("Note: the ordering starts from right to left\n");
    scanf("%d", &bit);

    printf("The bit no. %d of %lu is %lu", bit, num, GET_BIT(num,bit));

    return 0;
}
