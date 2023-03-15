#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ############## Start of utils ################
#define END_STRING_CHAR '\n'
#define NULL_TERMINATOR '\0'

char *allocateString(unsigned int size)
{
    char *string = (char *)malloc((size + 1) * sizeof(char));
    string[size] = NULL_TERMINATOR;
    return string;
}

void deallocateString(char *string)
{
    free(string);
}

char *scanUnlimitedString()
{
    char *string = "";
    char inputChar = 0;
    int size = 0;
    int firstScan = 1;
    while (inputChar != END_STRING_CHAR)
    {
        if (firstScan)
        {
            scanf(" %c", &inputChar); // So won't get the last Enter
            firstScan = 0;
        }
        else
        {
            scanf("%c", &inputChar);
        }

        if (inputChar != END_STRING_CHAR)
        {
            int newSize = size + 1;
            char *tempString = allocateString(newSize);
            strcpy(tempString, string);
            tempString[newSize - 1] = inputChar;
            tempString[newSize] = NULL_TERMINATOR;

            int notFirstLoop = size != 0;
            if (notFirstLoop)
            {
                deallocateString(string);
            }

            string = tempString;
            size = newSize;
        }
    }
    return string;
}

int countlines(char *filename)
{
    // count the number of lines in the file called filename
    FILE *fp = fopen(filename, "r");
    int ch = 0;
    int lines = 0;

    if (fp == NULL)
    {
        return 0;
    }

    lines++;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            lines++;
        }
    }
    fclose(fp);
    return lines;
}

int create_file_if_not_exists(char *filename)
{
    FILE *file = fopen(filename, "ab+");
    if (file == NULL)
    {
        file = fopen(filename, "wb");
        if (file == NULL)
        {
            return 1;
        }
    }
    fclose(file);
    return 0;
}

char *readfile(char *filename)
{
    FILE *f = fopen(filename, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET); /* same as rewind(f); */

    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, f);
    fclose(f);

    string[fsize] = NULL_TERMINATOR;

    return string;
}

// ############## End of utils ################

// ############## Start of commands ################
void remove_command(char *filename, char *input)
{
    remove(filename);
    create_file_if_not_exists(filename);
    printf("The file \"%s\" was deleted", filename);
    printf("\n");
}

void count_command(char *filename, char *input)
{
    int lines = countlines(filename);
    printf("The file \"%s\" has %d lines.", filename, lines);
    printf("\n");
}

void append_command(char *filename, char *input)
{
    FILE *fp = fopen(filename, "a");
    fprintf(fp, "%s\n", input);
    printf("The file \"%s\" was appended the string \"%s\"", filename, input);
    printf("\n");
    fclose(fp);
}

const char *prepend_tmp_filename = "/tmp/prepender";
void prepend_command(char *filename, char *input)
{
    char *input_without_symbol = input + 1;
    remove(prepend_tmp_filename);
    FILE *tmp_fp = fopen(prepend_tmp_filename, "a");
    fprintf(tmp_fp, "%s\n", input_without_symbol);
    char *filecontents = readfile(filename);
    fprintf(tmp_fp, "%s\n", filecontents);
    fclose(tmp_fp);
    free(filecontents);
    remove(filename);
    rename(prepend_tmp_filename, filename);
    printf("The file \"%s\" was prepended the string \"%s\"", filename, input_without_symbol);
    printf("\n");
}
// ############## End of commands ################

int main(int argc, char *argv[])
{
    char *filename = argv[1];

    FILE *file = fopen(filename, "a");
    if (create_file_if_not_exists(filename) == 1)
    {
        printf("Can't open the file \"%s\"", filename);
        return 1;
    }

    char *input = NULL;
    while (1)
    {
        printf("Enter a string (or 'exit' to exit): ");
        input = scanUnlimitedString();

        if (strcmp(input, "exit") == 0)
        {
            break;
        }
        else if (strcmp(input, "-remove") == 0)
        {
            remove_command(filename, input);
        }
        else if (strcmp(input, "-count") == 0)
        {
            count_command(filename, input);
        }
        else if (input[0] == '<')
        {
            prepend_command(filename, input);
        }
        else
        {
            append_command(filename, input);
        }

        deallocateString(input);
        input = NULL;
    }
    deallocateString(input);
    input = NULL;

    return 0;
}
