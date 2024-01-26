#include<stdio.h>
int main() {
    int i, s, n, k=0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    while (n <= 0){
    printf("Give me a valid input: ");
    scanf("%d", &n);}
    for (i=1; i<=n; ++i,k=0) {
        for (s=1; s<=n-i; ++s)
        { printf(" "); }
        while (k!=i) {
            printf("* ");
            ++k;
        }
        printf("\n");
    }
    for (i=n;i>1;--i){
      for (s=1;s<=n-i+1;++s)
      {printf(" ");}
      for (k=i;k>1;--k){
      printf("* ");
      }
      printf("\n");

    }
   
}

