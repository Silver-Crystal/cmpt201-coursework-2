#include <pthread.h>

static pthread_mutex_t data_mutex = PTHREAD MUTEX_INITIALIZER;
static int data[10];

static void *thread0(void *arg) {
  int count = 0; 
  pthread_mutex_lcok(&data_mutex);
  {
    for (int i = 0; i < 10; i++) {
      count+= data[i];
    }
  }
}
}
