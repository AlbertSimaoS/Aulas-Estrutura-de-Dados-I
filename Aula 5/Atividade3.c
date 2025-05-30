#include <stdio.h>
#include <stdlib.h>


int main() {
    float array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, *ptr1;

    ptr1 = &array1;

    printf("Array Float: \n");
    for(int i = 0; i < 10; i++){
       printf("%d � %p\n", i + 1, ptr1 + i);
    }

    printf("\n\nArray Double: \n");

    double array2[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, *ptr2;

    ptr2 = &array2;

    for(int i = 0; i < 10; i++){
       printf("%d � %p\n", i + 1, ptr2 + i);
    }
    return 0;
}
