#include<stdio.h>
 
unsigned int get_times_containes(
    const char* str,
    const char* sub
);

unsigned int get_str_size(
    const char* str
);

void print_str(
    const char* str
);

int main() {
   char str1[] = "nivniv";
   char str2[] = "niv";

   const unsigned int times_containes = get_times_containes(str1, str2);
   
   printf("The string \"");
   print_str(str2);
   printf("\" is contained in \"");
   print_str(str1);
   printf("\" %d times.\n", times_containes);
 
   return 0;
}

unsigned int get_times_containes(
    const char* str,
    const char* sub_str
) {
    unsigned int res = 0;

    const unsigned int str_size = get_str_size(str);
    const unsigned int sub_size = get_str_size(sub_str);

    unsigned int i = 0;
    unsigned int j = 0;
    while (i < str_size) {
        const char current_char = str[i];
        const char current_sub_char = sub_str[j];
        if (current_char == current_sub_char) {
            j++;
            i++;
            if (j == sub_size) {
                res++;
                j = 0;
            }
        } else if (j != 0) {
            j = 0;
        } else {
            i++;
        }
    }

    return res;
}

void print_str(
    const char* str
) {
    const unsigned int size = get_str_size(str);

    for(unsigned int i = 0; i < size; i++){
        printf("%c", str[i]);
    }
}

unsigned int get_str_size(
    const char* str
) {
    unsigned int size = 0;
    while(str[size] != '\0') {
        size++;
    }
    return size;
}
