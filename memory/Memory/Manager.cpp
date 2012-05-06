/*! @file Memory/Manager.cpp
 * @brief メモりマネージャ実装
 */

#include <Memory/Manager.h>
#include "Type.h"

namespace {

struct Block
{
	Block *next;
	Block *prev;
	u32   size;
	u32   stat;
	char  comment[32];
};

}

namespace Memory {

bool Memory::Manager::Initialize(void *buffer, u32 buffer_size) {
	if (!buffer) return false;

	return true;
}

void Memory::Manager::Terminate() {
}

}
