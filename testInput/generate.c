#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){

    srand(63427462131);
    FILE* outf;
    outf = fopen("test4", "w");
    long int Size = 1000000;
    fprintf(outf, "%d\n",  Size);
    for(int i = 0; i < Size; i++)
        fprintf(outf, "%d\n", rand() % 10000);

    


    return 0;


}
