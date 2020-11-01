#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *x = malloc(1);
    char * y = malloc(1);
    printf("Before Swap\n");
    printf("%p\n",x);
    printf("%p\n",y);
    printf("-------\n\n");
    char * temp = x;
    x = y;
    y = temp;
    printf("After Swap\n");
    printf("%p\n",x);
    printf("%p\n",y);
}
