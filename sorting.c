#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    fprintf(outf, "%ld\n", Size); //Places size of Array at top
    for (int i = 0; i < Size; i++){
        fprintf(outf, "%ld\n", Array[i]);
        count -= -1;
    }

    //Free all memory
    free(Array);
    fclose(outf);
    return count;
}

void Shell_Insertion_Sort(long int* Array, int Size, double *NComp, double *NMove){
    
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

void Improved_Bubble_Sort (long int *Array, int Size, double *NComp, double *NMove){
    //Finds he sequence
    long int* seq = malloc(sizeof(long int) * Size);
    seq[0] = floor(Size / 1.3);
    long int i = 0;
    long int SizeofKArray = 1;
    int temp;
    int j;
    int last_swap;
    while (seq[i++] != 1){
        seq[i] = floor(seq[i-1] / 1.3);
        SizeofKArray++;
    }
    
    //Sorts the array
    for (i = 0; i < SizeofKArray; i++){
        j = Size - seq[i] - 1; 
        do{
            last_swap = -1; 
            for (int k = 0; k <= j; k++){
                *NComp += 1;
                if (Array[k] > Array[k + seq[i]]){
                    temp = Array[k];
                    Array[k] = Array[k + seq[i]];
                    Array[k + seq[i]] = temp;
                    *NMove += 3;
                    last_swap = k;
                } 
            }
            j = last_swap - 1; //loop stops at last swap it performed.
        }while(last_swap > 0); //Stops the loop if no swaps are performed
    }
}

void Save_Seq1(char *Filename, int N){
    int* seq = malloc(sizeof(int) * N);
    seq[0] = 1;
    int p = 0;
    int q = 0;
    int p2;
    int q2;
    int i = 0;
    int sizeOfKArray = 0;
    while (seq[i++] < N){
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
    FILE* outf = fopen(Filename, "w");
        for (int i = 0; i < N; i++){
        fprintf(outf, "%ld\n", seq[i]);
    }
}

void Save_Seq2(char *Filename, int N){
    long int* seq = malloc(sizeof(long int) * N);
    seq[0] = floor(N / 1.3);
    long int i = 0;
    long int SizeofKArray = 1;
    int temp;
    int j;
    int last_swap;
    while (seq[i++] != 1){
        seq[i] = floor(seq[i-1] / 1.3);
        SizeofKArray++;
    }
    FILE* outf = fopen(Filename, "w");
        for (int i = N-1; i >= 0; i++){
        fprintf(outf, "%ld\n", seq[i]);
    }
}

int main( int argc, char * * argv){
    if (argc < 4)
        return 1;
    /*Arg [1] is the input file
    Arg [2] is the output file for the Shell_Insertion Sort
    Arg[3] is the output files for the improved bubble sort
    */
    //Loading data
    int Size = 0;
    long int* Array = Load_File(argv[1], &Size);
    //Using shell sort
    double NCompShell;
    double NMoveShell;
    Shell_Insertion_Sort(Array, Size, &NCompShell, &NMoveShell);
    Save_File(argv[2], Array, Size);
    printf("Number of comparisons made by Shell_Insertion_Sort: %.0lf\n", NCompShell);
    printf("Number of moves made by Shell_Insertion_Sort: %.0lf\n", NMoveShell);
    //Using Bubble Sort
    Array = Load_File(argv[1], &Size);
    double NCompBubble;
    double NMoveBubble;
    Improved_Bubble_Sort(Array, Size, &NCompBubble, &NMoveBubble);
    Save_File(argv[3], Array, Size);
    printf("Number of comparisons made by Improved_Bubble_Sort: %.0lf\n", NCompBubble);
    printf("Number of moves made by Improved_Bubble_Sort: %.0lf\n", NMoveBubble);

}