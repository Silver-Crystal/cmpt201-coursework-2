


#define _GNU_SOURCE
#include <pthread.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int cnt = 0;
void *threadFuncCount(void *a) {

  
 /*return (void *)0;*/
  return NULL;
}

int main() {
  /*pthread_t tid = 0;*/
  pthread_t tid[2] = {0};
  int main_var* = NULL;
  for (int i = 0; i < 2; i++) {
    int ret = pthread_create(&(tid[i]), NULL, threadFuncCount, (void *)(main_var));
    if (ret != 0) {
      perror("pthread_create");
      exit(EXIT_FAILURE);
    }
  }
  void *retVal = NULL;
  for (int i = 0; i < 2; i++) {
    int ret2 = pthread_join(tid[i], &retVal);
    if (ret2 != 0) {
      perror("pthread_join");
      exit(EXIT_FAILURE);
    }
  }
  /*printf("tid: %lu\n", (uint64_t)tid);*/
  /*printf("%lu\n", (uint64_t)retVal);*/
  printf("Cnt: %d\n", cnt);
}
