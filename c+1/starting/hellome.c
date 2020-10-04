#include <stdio.h>

void printer(char *x);
int main(void){
  printer("Hello, World");
}

void printer(char *x){
  printf("%s\n",x);
}
