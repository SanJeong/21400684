#include <stdio.h>

main(){ 
int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }; 
int *pa, i;

pa = a;

for (i = 0; i < 10; i++) {
    printf("a[%1d] = %d,  ", i, *(a+i)); 
    printf("*(pa+%1d) = %d\n", i, *(pa++));
}

    return 0;
}