#include <stdio.h>

int main() {
  char* file_name = "data.bin";

  // Open file
  FILE* file = fopen(file_name, "rb");
  if (file == NULL) {
    printf("Failed to open file.\n");
    return 1;
  }

  // Read data from file
  int data[100];
  fread(data, sizeof(int), 100, file);

  // Print data to console
  printf("Data read from file:\n");
  for (int i = 0; i < 100; i++) {
    printf("%d\n", data[i]);
  }

  // Close file
  fclose(file);

  return 0;
}
