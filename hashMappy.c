#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int *mappy = NULL;
int mappyLen = 0;

int initMappy(int initSize);
int* allocateNewMemory(int* newAdress, int newSize);

int main() {
    
    if (initMappy(20) == 2) {
        return 2;
    }

    for (size_t i = 0; i < mappyLen; i++)
    {
        printf("%d ", *(mappy + i));
    }
    

}

int initMappy(int initSize) {
    // init the new mappy
    int *newMappy = NULL;
    newMappy = allocateNewMemory(newMappy, initSize);
    if (*(newMappy) == 2) {
        // could not allocate memory
        return 2;
    }

    // free the old memory
    free(mappy);
    // insert the newly allocated memory adress in Mappy
    mappy = newMappy;
    // terminate the work pointer
    newMappy = NULL;
    
    if (insertValue(0) == 2) {
        // value allocation could not be processed
        return 2;
    }

    return 1;
}

int* allocateNewMemory(int* newAdress, int newSize) {
    newAdress = realloc(mappy, (sizeof *mappy * 1) * newSize);
    // failed to reallocate memory
    if (newAdress == NULL) {
        return NULL;
    }
    mappyLen = newSize;
    return newAdress;
}

int insertValue(int value) {
    for (size_t i = 0; i < mappyLen; i++)
    {
        *(mappy + i) = value;
    }
    return 1;
}