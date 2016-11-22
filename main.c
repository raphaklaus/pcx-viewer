#include <stdio.h>

int main(int argc, char const *argv[]) {
  FILE *file;
  char buffer[2];
  file = fopen("samples/L1M0MAP1.PCX", "rb");
  while(!feof(file)) {
    fread(buffer, 2, (sizeof buffer) -1, file);
    printf("%X", buffer);
  }
  fclose(file);
  //todo: read PCX header
  //todo: read PCX data
  return 0;
}
