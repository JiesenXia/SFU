#include <stdio.h>
  
void towerOfHanoi(int n, char from, char to, char ano)
{
    if (n == 1)
    {
        printf("%c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n-1, from, ano, to);
    printf("%c to %c\n", from, to);
    towerOfHanoi(n-1, ano, to, from);
}
  
int main()
{   int n;
    scanf("%d",&n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
} 
