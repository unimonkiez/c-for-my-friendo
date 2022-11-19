#include <stdio.h>

#define NULL_TERMINATOR '\0'

unsigned int getLength(const char* arr) {
    unsigned int i;
    for (i = 0; 1; i++) {
        if (arr[i] == NULL_TERMINATOR) {
            break;
        }
    }
    return i;
}

void shiftArr(char* arr, const int shiftBy) {
    unsigned int length = getLength(arr);
    unsigned int timesMoved = 0;


    unsigned int startIndex = 0;
    unsigned int i = (startIndex + shiftBy) % length;
    char lastValue = arr[startIndex];
    while (timesMoved < length) {
        char temp = arr[i];
        arr[i] = lastValue;
        lastValue = temp;

        if (i != startIndex) {
            i = (i + shiftBy) % length;
        } else {
            i = (startIndex + shiftBy + 1) % length;
            startIndex++;
            lastValue = arr[startIndex];
        }
        timesMoved++;
    }
}

int main() {
    char arr[] = "1234";
    char shiftedArr[] = "1234";
    shiftArr(shiftedArr, 0);

    printf("arr is: %s, shifted is: %s", arr, shiftedArr);
}
