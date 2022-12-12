#include <stdio.h>
#include <windows.h>
int main()
{
    FILE *in_ptr;
    FILE *out_ptr;
    char source[50];
    char destination[50];
    printf("Enter the name of the source file\n");
    scanf("%s", source);
    in_ptr = fopen(source, "r");
    if (in_ptr == NULL)
    {
        printf("Error opening source file");
        return 1;
    }

    printf("Enter the name of the destination file\n");
    scanf("%s", destination);
    out_ptr = fopen(destination, "w");
    printf("Files successfully opened\n");

    int ch = 0;

    while (ch != -1)
    {
        ch = getc(in_ptr);
        if (ch != -1)
            putc(ch, out_ptr);
    }
    printf("File successfully copied");
    fclose(in_ptr);
    fclose(out_ptr);
    return 0;
}