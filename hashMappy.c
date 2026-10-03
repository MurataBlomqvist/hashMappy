#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int *mappy = NULL;
int mappyLen = 0;

int initMappy(int initSize);
int* allocateNewMemory(int* newAdress, int newSize);
int insertAllValues(int value);
int insertNewValues(int value);
int insertOneValue(int value);
int deleteOneValue(int value);
int getHash(int value);
void showMappy();

int main() {
    
    if (initMappy(20) == 2) {
        return 2;
    }

    showMappy();
    insertOneValue(125);
    insertOneValue(125);
    showMappy();
    deleteOneValue(100);
    showMappy();
    deleteOneValue(125);
    deleteOneValue(125);

    showMappy();

}

void showMappy() {
    for (size_t i = 0; i < mappyLen; i++)
    {
        printf("%d ", *(mappy + i));
    }
    printf("\n");
}

int initMappy(int initSize) {
    // init the new mappy
    int *newMappy = NULL;
    newMappy = allocateNewMemory(newMappy, initSize);
    if (newMappy == NULL) {
        // could not allocate memory
        return 2;
    }

    // free the old memory
    free(mappy);
    // insert the newly allocated memory adress in Mappy
    mappy = newMappy;
    // terminate the work pointer
    newMappy = NULL;
    
    if (insertAllValues(0) == 2) {
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

int insertAllValues(int value) {
    for (size_t i = 0; i < mappyLen; i++)
    {
        *(mappy + i) = value;
    }
    return 1;
}

int getHash(int value) {
    if (0 >= value)
    {
        return 2;
    }
    int hash = value % mappyLen;
    return hash;
}

int insertOneValue(int value) {
    int hashkey = getHash(value);
    while (1) {
        if (*(mappy + hashkey) == 0) {
            *(mappy + hashkey) = value;
            break;
        }
        else
        {
            hashkey += 1;
        }
        
        if (hashkey >= mappyLen) {
            printf("%d : cant be inserted\n", value);
            return 2;
        }
    }
    return 1;
}

int deleteOneValue(int value) {
    int hashkey = getHash(value);
    while (1) {
        if (*(mappy + hashkey) == value && *(mappy + (hashkey + 1)) != value)
        {
            *(mappy + hashkey) = 0;
            break;
        }
        else if (*(mappy + hashkey) == 0)
        {
            printf("%d : does not exist\n", value);
            return 2;
        }
        else
        {
            hashkey += 1;
        }

        if (hashkey >= mappyLen) {
            printf("%d : does not exist\n", value);
            return 2;
        }
    }
    return 1;
}