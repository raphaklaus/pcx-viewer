#include <stdio.h>

int main(int argc, char const *argv[]) {
  FILE *file;
  char buffer[10];
  file = fopen("samples/pure_text.txt", "rb");
  while(!feof(file)) {
    fread(buffer, sizeof(*buffer), sizeof(buffer) / sizeof(*buffer), file);
    printf("%04X\n", buffer);
  }
  fclose(file);

  for (int i = 0; i < sizeof(buffer); i++) {
    printf("%04x",buffer[2]);
  }
  //todo: read PCX header
  //todo: read PCX data
  return 0;
}
