#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SUM(array, size) \
        ({ \
            int sum=0; \
            for (int i=0;i<size;i++) \
                sum+=array[i]; \
            sum; \
        })

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size], num;

    printf("Enter the elements of the array:\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d", &num);
        array[i]=num;
    }

    printf("The sum of the array elements = %d", ARRAY_SUM(array, sizeof(array)/sizeof(int)));

    return 0;
}
