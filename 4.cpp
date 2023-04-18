#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char filename[MAX_LINE_LENGTH];
    char search_str[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];

    printf("Enter the name of the file: ");
    fgets(filename, MAX_LINE_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0; // remove newline character

    printf("Enter the search string: ");
    fgets(search_str, MAX_LINE_LENGTH, stdin);
    search_str[strcspn(search_str, "\n")] = 0; // remove newline character

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Cannot open %s file.\n", filename);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strstr(line, search_str) != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);

    return 0;
}
