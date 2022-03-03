#ifndef FILE_H_
#define FILE_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

#define FILE_SIZE 1024 // the standard size of a "file" in this system is 1KB
#define CHUNKS 4 // the standard number of chunks made for a file in this system
#define CHUNK_SIZE FILE_SIZE / CHUNKS // the standard size of a chunk for a file in this system (256 bytes)

/* struct to represent chunks for files */
typedef struct {
  int key;
  char val[CHUNK_SIZE];
} chunk_t;

/* struct to simulate files */ 
typedef struct {
  char name[50];
  char data[MAX_FILE_SIZE];
  int lenth;
  chunk_t chunks[CHUNKS];
} sim_file;


/* This function hashes a key, which in this case is an
iterate of the bytes in a file, into an index between 
0 and 3 such that continguous blocks of 256 bytes are
hashed to the same index */
int hash(int key);

/* This function inserts keys and values into a chunk,
much like a standard insert into hash table function
would operate */  
void insert(chunk_t* chunk, int key, char val);

/* This function creates chunks from a given simulated file,
   effectively populating the chunk field of the sim file struct */
void create_chunks(sim_file* file);
#endif
