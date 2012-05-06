/*! @file main.cpp
 * @brief メインエントリ
 */

#include <cstdio>
#include <Memory/Manager.h>

#define BUFFER_SIZE (1024)
int main() {
	printf("sample\n");
	if (!Memory::Initialize(BUFFER_SIZE)) {
		printf("failed initialize.\n");
	}


	Memory::Terminate();
}

