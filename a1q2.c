#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Please provide the address of a file as an input.\n");
    return -1;
  }

  struct stat sb;
  // Get metadata about the specified file
  if (stat(argv[1], &sb) == -1) {
    perror("stat");
    return -1;
  }

  // Print the file size in bytes
  printf("%lld\n", (long long)sb.st_size);
  return 0;
}
