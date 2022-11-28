#include <stdio.h>
 
void reverse(char array[], unsigned int length);
void swap(char *a, char *b);

int main(void){
    char array[] = "niv";
    unsigned int len = sizeof(array) / sizeof(char);
    
    reverse(array, len);

    for(int i = 0; i < len; i++){
        printf("%c", array[i]);
     }
}

void reverse(char array[], unsigned int len){
    unsigned int middle = len / 2;
    for(int i = 0; i < middle; i++) {
        swap(&array[i], &array[len -1 -i]);
    }
}

void swap(char *a ,char *b){
    char t = *a;
    *a = *b;
    *b = t;   
}

    
 
