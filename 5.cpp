#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int main() {
    char input_filename[] = "data.txt";
    char output_filename[] = "statistics.txt";
    int letter_count[ALPHABET_SIZE] = {0};
    char ch;

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

    while ((ch = fgetc(input_file)) != EOF) {
        if (isalpha(ch)) {
            letter_count[toupper(ch) - 'A']++;
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        fprintf(output_file, "%c: %d\n", 'A' + i, letter_count[i]);
    }

    printf("Successfully wrote the statistics to %s.\n", output_filename);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
