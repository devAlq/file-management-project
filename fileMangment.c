#include <stdio.h>

int main(void)
{
    FILE *fptr;
    FILE *copy;
    char line[256];

    fptr = fopen("file.txt", "r");
    if (fptr == NULL)
    {
        perror("Error opening file.txt");
        return 1;
    }

    copy = fopen("copy.txt", "w");
    if (copy == NULL)
    {
        perror("Error opening copy.txt");
        fclose(fptr);
        return 1;
    }

    while (fgets(line, sizeof(line), fptr) != NULL)
    {
        fputs(line, copy);
    }

    fclose(fptr);
    fclose(copy);

    return 0;
}
