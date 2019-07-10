#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define N 100
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond;

int a=0;

void *func1() {
	pthread_mutex_lock(&mut);
	for (int i=0; i<=N; i++) {
		if (N==a) 	
			pthread_cond_signal(&cond);
		a++;
		printf("%d\n", a);
	}
	pthread_mutex_unlock(&mut);
}

void *func2() {
	pthread_mutex_lock(&mut);
	pthread_cond_wait(&cond, &mut);
	a=a+100;
	printf("%d\n", a);
	pthread_mutex_unlock(&mut);
}

int main() {

	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread2, NULL, func2, NULL);
	pthread_create(&thread1, NULL, func1, NULL);
	
	pthread_join(thread2, NULL);
	pthread_join(thread1, NULL);
		

	return 0;
}
