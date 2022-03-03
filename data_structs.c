#include "data_structs.h"

#define MAX_FILE_SIZE 1024
#define CHUNKS 4

typedef struct {
  char[50] name;
  char[MAX_FILE_SIZE] data;
  int lenth; 
} sim_file;

void divide_file (sim_file file) {
  for (int i = 0; i < MAX_FILE_SIZE; i++) {
    
  }
}
