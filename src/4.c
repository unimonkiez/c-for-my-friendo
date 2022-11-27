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

    int shiftByAbs = shiftBy;
    int shiftBySign = 1;
    int jStart = 0;
    int jEnd = length;
    if (shiftBy < 0) {
        shiftByAbs = -1 * shiftByAbs;
        shiftBySign = -1;
        jStart = length - 1;
        jEnd = -1;
    }

    for (unsigned int i = 0; i < shiftByAbs; i++) {
        char lastValue = arr[jStart];
        for (unsigned int j = jStart + shiftBySign; j != jEnd; j+=shiftBySign) {
            char temp = arr[j];
            arr[j] = lastValue;
            lastValue = temp;
        }
        arr[jStart] = lastValue;
    }
}

int main() {
    char arr[] = "123456";
    char shiftedArr[] = "123456";
    shiftArr(shiftedArr, -3);

    printf("arr is: %s, shifted is: %s", arr, shiftedArr);
}
