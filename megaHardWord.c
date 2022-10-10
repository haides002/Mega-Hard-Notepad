//		Mega Hard Word
//		version 0.0-alpha
//		by Zxmon and Haides002

// include libs
#include <stdio.h>
#include <stdlib.h>

// initialze variables
char *mainBuffer_ptr;
unsigned long long int fileSize_int;

void mapFile() { // creates buffer and writes file contents to buffer
  FILE *pFile;
  pFile = fopen("example.txt", "r");
  fseek(pFile, 0L, SEEK_END);
  fileSize_int = ftell(pFile);
  mainBuffer_ptr = malloc(sizeof(char) * +512);

  fseek(pFile, 0L, SEEK_SET);
  fread(mainBuffer_ptr, sizeof(char), fileSize_int, pFile);
  fclose(pFile);
}

void printBuffer() {
  for (int i = 0; i < fileSize_int; ++i) {
    printf("%c", mainBuffer_ptr[i]);
  }
}

int main() {
  mapFile();
  printBuffer();
  free(mainBuffer_ptr);
  return 0;
}
