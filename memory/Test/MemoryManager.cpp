/*! @file Test/MemoryManager.cpp
 * @brief メモリマネージャテスト
 */
#include <cstdlib>
#include "gtest/gtest.h"
#include "Memory/Manager.h"

namespace {

class MemoryManagerTest : public ::testing::Test
{
public:
	MemoryManagerTest() {
	}
	virtual ~MemoryManagerTest() {
	}
	virtual void SetUp() {
	}
	virtual void TearDown() {
	}
};

}

TEST(MemoryManagerTest, Initialize) {
	u32 buffer_size = 1024 * 1024;
	ASSERT_FALSE(Memory::Manager::Initialize(NULL, buffer_size)) << "buffer -> NULL";

	void *buffer = malloc(buffer_size);
	ASSERT_TRUE(Memory::Manager::Initialize(buffer, buffer_size)) << "initialize";
}

TEST(MemoryManagerTeset, Terminate) {
	Memory::Manager::Terminate();	
}
