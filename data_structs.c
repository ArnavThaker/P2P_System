#include "data_structs.h"

list_t* create_list(size_t len) {
  list_t* list = (list_t*) malloc(len * sizeof(file_t));

  if (list == NULL) {
    return -1;
  }
  
  list->head_file->next = NULL;
  list->head_file->size = FILE_SIZE;
  return list;
}

void destroy_list(list* list) {
  if (list == NULL) {
    return;
  } else {
    list->next = NULL;
    free(list);
  }
}

file_t* get_next(list_t* list) {
  
}

file_t* get_prev(list_t* list) {
}

void create_chunks(file_t* file) {
}
