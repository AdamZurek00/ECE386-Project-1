#include <stdio.h>
#include <stdlib.h>
#include "Dynamic_Stacks.h"

void Shell_Insertation_Sort(long int* Array, int Size, double *NComp, double *NMove){
    
    //Generates the sequence of K Values
    int* seq = malloc(sizeof(int) * Size);
    seq[0] = 1;
    int p = 0;
    int q = 0;
    int p2;
    int q2;
    int i = 0;
    int sizeOfKArray = 0;
    while (seq[i++] < Size){
        if (seq[p] * 2 ==  seq[i - 1])
            p++;
        if (seq[q] * 3 == seq[i - 1])
            q++;
        p2  = seq[p] * 2;
        q2 = seq[q] * 3;
        if (p2 < q2){
            p++;
            seq[i] = p2;
            sizeOfKArray++;
        }
        else{
            q++;
            seq[i] = q2;
            sizeOfKArray++;
        }
    }

    //Actually sorting the array
    long int temp_r;
    int k;
    for (i = sizeOfKArray; i >=0; i--){
        for (int j = seq[i]; j <= Size - 1; j++){
            temp_r =  Array[j];
            *NMove += 1;
            k = j; //Not sequence but innermost loop control variable
            if (k >= seq[i])
                *NComp += 1;
            while ((k >= seq[i]) && (Array[k - seq[i]] > temp_r)){
                Array[k] = Array[k - seq[i]];
                *NMove += 1;
                k = k - seq[i];
            }
            Array[k] = temp_r;
            *NMove += 1;
        }
    }

}

int main(){
    int Size = 3;
    double NMove = 0;
    double NComp = 0;
    long int* Array = malloc(sizeof(long int) * Size);
    Array[0] = 3;
    Array[1] = 1;
    Array[2] = 2;
    Shell_Insertation_Sort(Array, Size, &NComp, &NMove);
    for (int i = 0; i < Size; i++)
        printf("%d ", Array[i]);
    printf("\n");
    printf("NComp: %lf NMove: %lf\n", NComp, NMove);
}

/*
int main(){
    int p = 0;
    int q = 0;
    int p2;
    int q2;
    int i = 0;
    int n = 20;
    int* seq = malloc(sizeof(int) * n);
    seq[0] = 1;
    int sizeOfKArray = 0;
    while (seq[i++] < n){
        if (seq[p] * 2 ==  seq[i - 1])
            p++;
        if (seq[q] * 3 == seq[i - 1])
            q++;
        p2  = seq[p] * 2;
        q2 = seq[q] * 3;
        if (p2 < q2){
            p++;
            seq[i] = p2;
            sizeOfKArray++;
        }
        else{
            q++;
            seq[i] = q2;
            sizeOfKArray++;
        }
    }
    for (int i = 0; i < sizeOfKArray; i++)
        printf("%d ", seq[i]);
}
*/