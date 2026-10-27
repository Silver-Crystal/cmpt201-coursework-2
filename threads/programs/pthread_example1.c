#include <pthread.h>

static pthread_mutex_t data_mutex = PTHREAD MUTEX_INITIALIZER;
static int data[10];

static void *thread0(void *arg) {
  int count = 0;
  pthread_mutex_lock(&data_mutex);
  {
    for (int i = 0; i < 10; i++) {
      count += data[i];
    }
  }
  pthread_mutex_unlock(&data_mutex);
  printf("Sum is %d\n", count);
  pthread_exit(0);
}

static void *thread1(void *arg) {
  pthread_mutex_lock(&data_mutex);
  {
    for (int i = 0; i < 10; i++) {
      data[i] += 1;
    }
  }
  pthread_mutex_unlock(&data_mutex);
  printf("Done update!\n");
  pthread_exit(0);
}
