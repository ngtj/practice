/*! @file Memory/Manager.h
 * @brief メモリマネージャ
 */

#ifndef __MEMORY_MANAGER_H_2012_05_05__
#define __MEMORY_MANAGER_H_2012_05_05__

#include "Type.h"

namespace Memory {

class Manager
{
public:
	static bool Initialize(void *buffer, u32 buffer_size);
	static void Terminate();
private:
};

} // Memory

#endif // __MEMORY_MANAGER_H_2012_05_05__

