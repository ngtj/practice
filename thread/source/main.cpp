/*! @file main.cpp
 * @brief サンプルエントリ
 */
#include <cstdio>
#include <cstdlib>
#include <pthread.h>

static void *func(void *args) {
	for (int i = 0; i < 10; i++) {
		puts(" b");
		sleep(1);
	}

	return NULL;
}

int main (void) {
	pthread_t thread;

	// スレッド生成
	if (pthread_create(&thread, NULL, func, NULL) != 0) {
		return EXIT_FAILURE;
	}

	for (int i = 0; i < 10; i++) {
		puts("a");
		sleep(1);
	}

	// スレッド待機
	if (pthread_join(thread, NULL) != 0) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
