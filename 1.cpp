#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* input_file_name = "input.txt";
  char* output_file_name = "error_log.txt";
  char* error_word = "error";

  // Open input file
  FILE* input_file = fopen(input_file_name, "r");
  if (input_file == NULL) {
    printf("Failed to open input file.\n");
    exit(1);
  }

  // Create output file
  FILE* output_file = fopen(output_file_name, "w");
  if (output_file == NULL) {
    printf("Failed to create output file.\n");
    exit(1);
  }

  char line[256];
  while (fgets(line, sizeof(line), input_file)) {
    if (strstr(line, error_word) != NULL) {
      // Write line to output file if it contains the error word
      fprintf(output_file, "%s", line);
    }
  }

  // Close files
  fclose(input_file);
  fclose(output_file);

  // Open error log file and print contents to console
  FILE* error_log_file = fopen(output_file_name, "r");
  if (error_log_file == NULL) {
    printf("Failed to open error log file.\n");
    exit(1);
  }

  printf("Contents of error log file:\n");
  while (fgets(line, sizeof(line), error_log_file)) {
    printf("%s", line);
  }

  // Close error log file
  fclose(error_log_file);

  return 0;
}
