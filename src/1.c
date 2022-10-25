#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0


bool contains(const char* parent, const char* child) {
    if (strstr(parent, child) != NULL) {
        return true;
    }
    return false;
}

int main() {
    char *sent = "this is my sample example";
    char *word = "sample";

    if (contains(sent, word)) {
        printf("Contains");
    } else {
        printf("Nope!");
    }
}
