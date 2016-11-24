#include <stdio.h>

int main() {
  FILE *file;
  char buffer[11];
  int i;
  file = fopen("samples/L1M0MAP1.PCX", "rb");
  fread(buffer, 1, 12, file);
  fclose(file);

  printf("Here is file's hex:\n\n");

  for (i = 0; i < 12; i++) {
    printf("%02X ",buffer[i]);
  }
  //todo: read PCX header
  //todo: read PCX data
  return 0;
}
