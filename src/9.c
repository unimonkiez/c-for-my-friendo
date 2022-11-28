#include <stdio.h>
 
void reverse(int array[], unsigned int length);
void swap(int *a, int *b);

int main(void){
    int array[] = {1, 2, 3};
    unsigned int len = sizeof(array) / sizeof(int);
    
    reverse(array, len);

    for(int i = 0; i < len; i++){
        printf("%d", array[i]);
     }
}

void reverse(int * array, unsigned int len){
    unsigned int middle = len / 2;
    for(int i = 0; i < middle; i++) {
        swap(array + i, array + (len -1 -i));
    }
}

void swap(int *a ,int *b){
    int t = *a;
    *a = *b;
    *b = t;   
}

    
 
