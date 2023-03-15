#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ############## Start of utils ################
#define END_STRING_CHAR '\n'
#define NULL_TERMINATOR '\0'

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
            char *tempString = (char *)malloc((newSize + 1) * sizeof(char));
            tempString[newSize] = NULL_TERMINATOR;
            strcpy(tempString, string);
            tempString[newSize - 1] = inputChar;
            tempString[newSize] = NULL_TERMINATOR;

            int notFirstLoop = size != 0;
            if (notFirstLoop)
            {
                free(string);
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
enum ChainResult
{
    Exit,
    Handled,
    Pass
};

typedef struct Command
{
    char *flag;
    int (*comparison_func)(struct Command cmd, char *input);
    enum ChainResult (*operation_func)(struct Command cmd, char *filename, char *input);
} Command;

// Compare
int compare_flag(struct Command cmd, char *input)
{
    return strcmp(input, cmd.flag) == 0;
}

int compare_first_char(struct Command cmd, char *input)
{
    return input[0] == cmd.flag[0];
}

int compare_always_true(struct Command cmd, char *input)
{
    return 1;
}

// Operations
enum ChainResult exit_command(struct Command cmd, char *filename, char *input)
{
    if (!cmd.comparison_func(cmd, input))
    {
        return Pass;
    }
    return Exit;
}

enum ChainResult remove_command(struct Command cmd, char *filename, char *input)
{
    if (!cmd.comparison_func(cmd, input))
    {
        return Pass;
    }
    remove(filename);
    create_file_if_not_exists(filename);
    printf("The file \"%s\" was deleted", filename);
    printf("\n");

    return Handled;
}

enum ChainResult count_command(struct Command cmd, char *filename, char *input)
{
    if (!cmd.comparison_func(cmd, input))
    {
        return Pass;
    }
    int lines = countlines(filename);
    printf("The file \"%s\" has %d lines.", filename, lines);
    printf("\n");

    return Handled;
}

enum ChainResult append_command(struct Command cmd, char *filename, char *input)
{
    if (!cmd.comparison_func(cmd, input))
    {
        return Pass;
    }
    FILE *fp = fopen(filename, "a");
    fprintf(fp, "%s\n", input);
    fclose(fp);
    printf("The file \"%s\" was appended the string \"%s\"", filename, input);
    printf("\n");

    return Handled;
}

const char *prepend_tmp_filename = "/tmp/prepender";
enum ChainResult prepend_command(struct Command cmd, char *filename, char *input)
{
    if (!cmd.comparison_func(cmd, input))
    {
        return Pass;
    }
    remove(prepend_tmp_filename);

    char *input_without_symbol = input + 1;
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

    return Handled;
}

// Command array - ADD NEW COMMAND HERE
const struct Command commands[] = {
    {"-exit",
     &compare_flag,
     &exit_command},
    {"-remove",
     &compare_flag,
     &remove_command},
    {"-count",
     &compare_flag,
     &count_command},
    {"<",
     &compare_first_char,
     &prepend_command},
    {NULL,
     &compare_always_true,
     &append_command}};
// ############## End of commands ################

int main(int argc, char *argv[])
{
    char *filename = argv[1];

    if (create_file_if_not_exists(filename) == 1)
    {
        printf("Can't open the file \"%s\"", filename);
        return 1;
    }

    char *input = NULL;
    while (1)
    {
        printf("Enter a string (or '-exit' to exit): ");
        input = scanUnlimitedString();

        for (unsigned int i = 0; i < sizeof(commands) / sizeof(struct Command); i++)
        {
            struct Command cmd = commands[i];
            enum ChainResult chain_result = cmd.operation_func(cmd, filename, input);

            if (chain_result == Exit)
            {
                free(input);
                input = NULL;
                return 0;
            }
            else if (chain_result == Handled)
            {
                break;
            }
            else if (chain_result == Pass)
            {
                continue;
            }
        }

        free(input);
        input = NULL;
    }

    return 0;
}
