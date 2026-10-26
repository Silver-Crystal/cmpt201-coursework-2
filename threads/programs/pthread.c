#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

void * threadFunc(void *a) {
  printf("argument: %s\n",(char*) a);
  printf("self: %d\n")
  printf("id: %d\n", gettid());
  return (void*)strlen((char*)a);
}

int main() {
  pthread_t tid = 0;
  int ret = pthread_create(&tid, NULL, threadFunc, "hi");
  void *retVal = NULL;
  int ret2 = pthread_join(tid, &retVal);
  printf("tid: %lu\n", (uint64_t)tid);
  printf("%lu\n", (uint64_t)retVal);

}
