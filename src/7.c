#include<stdio.h>
 
unsigned int removeDuplicates(int array[], const int size);
void printArray(const int array[], const int size);

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 6, 7, 7, 8};
    int size = sizeof(array)/ sizeof(array[0]);

    unsigned int newSize = removeDuplicates(array, size);
    printArray(array, newSize);
  
    return 0;
}

unsigned int removeDuplicates(int array[], const int size){
    unsigned int addedSize = 0;
    for(int i = 0; i < size; i++) {
        if (i == 0 || array[i] != array[addedSize - 1]) {
            array[addedSize] = array[i];
            addedSize++;
        }
    }
    return addedSize;
}

void printArray(const int array[], const int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
}
