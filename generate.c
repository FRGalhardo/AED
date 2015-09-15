#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i;
    srand( (unsigned)time(NULL) );
    printf("10000000\n");
    for(i=1 ; i <= 10000000; i++)
        printf("%d\n", rand()%100);
}

