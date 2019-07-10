// -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func (void* ptr) {
	int *num;
	num=(int*)ptr;
	printf("%d [in tid %zu]; Size of tid %lu bytes\n", *num, pthread_self(), sizeof(pthread_self()));
	pthread_exit(NULL);
}


int main() {
	
	pthread_t tid[6];
	int i;
	int a[6];
	
		
	for (i=1; i<=5; i++) {
		a[i-1]=i;
		pthread_create(&tid[i-1], NULL, func, &a[i-1]);
	}
	for (i=1; i<=5; i++) 
		pthread_join(tid[i-1], NULL);

	
	return 0;
}
