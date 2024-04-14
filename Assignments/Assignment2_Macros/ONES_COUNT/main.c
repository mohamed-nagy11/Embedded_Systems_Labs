#include <stdio.h>
#include <stdlib.h>

#define ONES_COUNT(num) \
        ({ \
            int count=0, n=num; \
            while(n!=0) \
            { \
                if(n%2==1) \
                    count++; \
                n/=2; \
            } \
            count; \
        })

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("%d has %d one(s) in its binary representation", num, ONES_COUNT(num));

    return 0;
}
