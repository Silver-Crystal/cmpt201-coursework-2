

#define _GNU_SOURCE
#include <pthread.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int cnt = 0;

pthread_mutex_t A = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t B = PTHREAD_MUTEX_INITIALIZER;

void *threadFuncA(void *a) {
  /*sleep(1);*/
  pthread_mutex_lock(&A);
  printf("0: mutex A\n");
  pthread_mutex_lock(&B);
  printf("0: mutex B\n");
  pthread_mutex_unlock(&B);
  printf("0: mutex unlock B\n");
  pthread_mutex_unlock(&A);
  printf("0: mutex unlock A\n");
  return NULL;
}
void *threadFuncB(void *a) {
  pthread_mutex_lock(&B);
  printf("1: mutex B\n");
  pthread_mutex_lock(&A);
  printf("1: mutex A\n");
  pthread_mutex_unlock(&A);
  printf("1: mutex unlock A\n");
  pthread_mutex_unlock(&B);
  printf("1: mutex unlock B\n");
  return NULL;
}

int main() {
  /*pthread_t tid = 0;*/
  pthread_t tid[2] = {0};
  void *(*threadFuncList[2])(void *) = {threadFuncA, threadFuncB};
  for (int i = 0; i < 2; i++) {
    int ret = pthread_create(&(tid[i]), NULL, threadFuncList[i], NULL);
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
