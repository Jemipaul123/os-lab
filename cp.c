#include <stdio.h>

int main() {
    char source_file[100];
    char destination_file[100];
    char ch;

    printf("Enter the source file name: ");
    scanf("%s", source_file);

    printf("Enter the destination file name: ");
    scanf("%s", destination_file);

    FILE *source = fopen(source_file, "r");
    if (source == NULL) {
        printf("Unable to open the source file %s\n", source_file);
        return 1;
    }

    FILE *destination = fopen(destination_file, "w");
    if (destination == NULL) {
        printf("Unable to open or create the destination file %s\n", destination_file);
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(destination);

    return 0;
}
