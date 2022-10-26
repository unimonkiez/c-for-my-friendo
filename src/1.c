#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0


bool contains(const char* string, const char* substring) {
    if (strstr(string, substring) != NULL) {
        return true;
    }
    return false;
}

int main() {
    char *sentence = "this is my sample example";
    char *word = "sample";

    if (contains(sentence, word)) {
        printf("Contains");
    } else {
        printf("Nope!");
    }
}
