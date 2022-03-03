#include "data_structs.h"

/* hash function specifically for hashing to four chunks */ 
int hash(int key) {
  return (int) floor(key / CHUNK_SIZE);
}

/* Hash table insert function specific to chunks */
void insert(chunk_t* chunk, int key, char val) {
  int i = hash(key);
  chunk.key = i;
  *(chunk + key).val = val;
}


/* Method to create chunks */
void create_chunks(sim_file* file) {
  for (int i = 0; i < MAX_FILE_SIZE; i++) {
    insert(file.chunk[hash(i)], i, file.data[i]);
  }
}
