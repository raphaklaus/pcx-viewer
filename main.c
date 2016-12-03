#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;

  struct header {
    int manufacturer_byte;
    int pcx_version;
    int encoding_byte;
    int bits_number_per_plane;
    int resolution;
  };

  struct header h;

  char buffer[11];
  int i;
  file = fopen("samples/L1M0MAP1.PCX", "rb");
  fread(buffer, 1, 12, file);
  fclose(file);

  printf("Here is file's hex:\n\n");
  for (i = 0; i < 12; i++) {
    switch (i) {
      case 0: h.manufacturer_byte = 10;
        break;
      case 1: h.pcx_version = (int)buffer[i];
        break;
      case 2: h.encoding_byte = 1;
        break;
      case 3: h.bits_number_per_plane = (int)buffer[i];
        break;
      //todo adjust offsets...
      case 4 ... 8: h.resolution (int)buffer[i]
    }
  }

  //todo: read PCX header
  printf("manufacturer_byte: %i\n", h.manufacturer_byte);
  printf("pcx version: %i\n", h.pcx_version);
  printf("encoding_byte: %i\n", h.encoding_byte);
  printf("bits_number_per_plane: %i\n", h.bits_number_per_plane);
  //todo: read PCX data
  return 0;
}
