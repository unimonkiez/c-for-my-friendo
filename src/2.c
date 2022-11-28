#include <stdio.h>
 
void power(float base, float expo);
 
int main(){
    float base = 2, expo = -2;
    power(base, expo);
}

void power(float base, float expo){
    float results =1;

    float multi;
    float add;
    if(expo > 0){
        multi = base;
        add = (-1);
    }
    else{
        multi = (1.0 / base);
        add = 1;
    }

    while (expo != 0){
        results *=  multi;
        expo = expo + add;
    }
    printf("%f", results);
}