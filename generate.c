#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i;
    srand( (unsigned)time(NULL) );
    int x;
    scanf("%d", &x);
    printf("%d\n",x);
    for(i=1 ; i <= x; i++)
        printf("%d\n", rand()%100);
}

