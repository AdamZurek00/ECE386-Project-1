#include <stdio.h>
#include <stdlib.h>

long int* Load_File(char *Filename, int* Size){
    FILE* inf = fopen(Filename, "r");
    fscanf(inf, "%d", Size); //Gets size from file
    long int* Array = malloc(sizeof(long int) * (*Size)); //Allocs array
    for (int i = 0; i < *Size; i++){ //Fills array with file
        fscanf(inf, "%ld", &Array[i]);
    }
    fclose(inf);
    return Array;

}

int Save_File(char *Filename, long int* Array, int Size){
    FILE* outf = fopen(Filename, "w");
    int count = 0;
    fprintf(outf, "%ld\n", Size);
    for (int i = 0; i < Size; i++){
        fprintf(outf, "%ld\n", Array[i]);
        count -= -1;
    }
    fclose(outf);
    free(Array);
    return count;
}

