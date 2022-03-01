#ifndef FILE_H_
#define FILE_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

#define FILE_SIZE 1024 // the standard size of a "file" in this system is 1KB
#define CHUNKS 4 // the standard number of chunks made for a file in this system
#define CHUNK_SIZE FILE_SIZE / CHUNKS // the standard size of a chunk for a file in this system (256 bytes)

/* struct to define a file */
typedef struct file {
  struct file* next;
  size_t size;
} file_t;


/* struct to define a file list a peer wants to share */
typedef struct {
  file_t* head_file;
  size_t len;
} list_t;

/* create a list of files */
list_t* create_list(size_t len);

/* destroy a list of files */
void destroy_list(list_t* list);

/* find next file in a list */
file_t* get_next(list_t* list);

/* find previous file in a list */
file_t* get_prev(list_t* list);


/* method to divide file into chunks */
void create_chunks(file_t* file);

#endif
