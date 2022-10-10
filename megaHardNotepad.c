//		Mega Hard Word
//		version 0.0-alpha
//		by Zxmon and Haides002

// include libs
#include <stdio.h>
#include <stdlib.h>

// deffine constants
const unsigned int BUFFER_HEADROOM = 512;

// initialze variables
char *mainBuffer_ptr;
unsigned long long int fileSize_int;

// Creates buffer and writes file contents to buffer. It takes in a File path
// and writes to mainBuffer_ptr and fileSize_int.
void loadFileToBuffer(char filePath[]) {
  FILE *tempFile;
  tempFile = fopen(filePath, "r");
  fseek(tempFile, 0L, SEEK_END);
  fileSize_int = ftell(tempFile);
  mainBuffer_ptr = malloc(sizeof(char) * fileSize_int + BUFFER_HEADROOM);
  fseek(tempFile, 0L, SEEK_SET);
  fread(mainBuffer_ptr, sizeof(char), fileSize_int, tempFile);
  fclose(tempFile);
}

void printBuffer() {
  for (int i = 0; i < fileSize_int; ++i) {
    printf("%c", mainBuffer_ptr[i]);
  }
}

int main() {
  loadFileToBuffer("megaHardNotepad.c");
  printBuffer();
  free(mainBuffer_ptr);
  return 0;
}
