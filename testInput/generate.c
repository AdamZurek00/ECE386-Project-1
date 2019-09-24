#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){

    srand(63427462131);
    FILE* outf;
    outf = fopen("test4", "w");
    fprintf(outf, "%d\n",  30);
    for(int i = 0; i < 30; i++)
        fprintf(outf, "%d\n", rand() % 10000);

    


    return 0;


}
