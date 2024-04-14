#include <stdio.h>
#include <stdlib.h>

#define REVERSE_BIT(num) \
        ({ \
            int reverse=0; \
            while(num!=0) \
            { \
                reverse = reverse*10 + num%10; \
                num/=10; \
            } \
            reverse; \
        })

int main()
{
    int num;
    printf("Enter a 8-bit binary number: ");
    scanf("%d", &num);
    printf("The reversed number = %d", REVERSE_BIT(num));

    return 0;
}
