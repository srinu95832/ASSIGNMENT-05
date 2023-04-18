#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char input_filename[] = "input.txt";
    char output_filename[] = "output.txt";
    char search_str[] = "red";
    char replace_str[] = "blue";
    char line[MAX_LINE_LENGTH];

    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (input_file == NULL) {
        printf("Error: Cannot open %s file.\n", input_filename);
        return 1;
    }

    if (output_file == NULL) {
        printf("Error: Cannot create %s file.\n", output_filename);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        char *found = strstr(line, search_str);

        while (found != NULL) {
            strncpy(found, replace_str, strlen(replace_str));
            found = strstr(found + strlen(replace_str), search_str);
        }

        fputs(line, output_file);
    }

    printf("Successfully replaced '%s' with '%s' in %s and saved to %s.\n", search_str, replace_str, input_filename, output_filename);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
