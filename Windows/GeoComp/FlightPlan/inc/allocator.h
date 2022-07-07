// AUTHOR:	    https://www.codeproject.com/Articles/1087619/State-Machine-Design-in-Cplusplus-2	
// PROJECT:		WorldPerception
// DOCUMENT:	None
// DESCRIPTION: This file declares memory allocator that allocates/deallocates blocks of memory
//              from a pre-allocated static memory pool for state machine events

#ifndef __ALLOCATOR_H
#define __ALLOCATOR_H

#include <stddef.h>

using namespace std;

class Allocator
{
    public:
        /// Constructor
        /// @param[in]  size - size of the fixed blocks.
        /// @param[in]  objects - maximum number of objects. If 0, new blocks are created from the heap as necessary.
	    /// @param[in]	memory - pointer to a block of static memory for allocator or NULL to obtain memory from global heap. 
        /// If not NULL, the objects argument defines the size of the memory block (size x objects = memory size in bytes).
	    ///	@param[in]	name - optional allocator name string.
        Allocator(size_t size, unsigned int objects = 0, char* memory = NULL, const char* name = NULL);

        /// Destructor
        ~Allocator();

        /// Get a pointer to a newly alocated memory block.
        /// @param[in]  size - size of the block to allocate.
        /// @return     Returns pointer to the block. Otherwise NULL if unsuccessful.
        void* Allocate(size_t size);

        /// Return a pointer to the memory pool. 
        /// @param[in]  pBlock - block of memory deallocate (i.e. push onto the free-list)
        void Deallocate(void* pBlock);

        /// Get the allocator name string.
        /// @return		A pointer to the allocator name or NULL if none has been assigned.
        const char* GetName() { return m_name; }

        /// Gets the fixed block memory size, in bytes, handled by the allocator.
        /// @return		The fixed block size in bytes.
        size_t GetBlockSize() { return m_blockSize; }

        /// Gets the maximum number of blocks created by the allocator.
        /// @return		The number of fixed memory blocks created.
        unsigned int GetBlockCount() { return m_blockCnt; }

        /// Gets the number of blocks in use.
        /// @return		The number of blocks in use by the application.
        unsigned int GetBlocksInUse() { return m_blocksInUse; }

        /// Gets the total number of allocations for this allocator instance.
        /// @return		The total number of allocations.
        unsigned int GetAllocations() { return m_allocations; }

        /// Gets the total number of deallocations for this allocator instance.
        /// @return		The total number of deallocations.
        unsigned int GetDeallocations() { return m_deallocations; }

    private:

        /// Push a memory block onto head of free-list.
        /// @param[in]  pMemory - block of memory to push onto free-list
        void Push(void* pMemory);

        /// Pop a memory block from head of free-list.
        /// @return     Returns pointer to the block. Otherwise NULL if unsuccessful.
        void* Pop();

        struct Block
        {
            Block* pNext;
        };

	    enum AllocatorMode { HEAP_BLOCKS, HEAP_POOL, STATIC_POOL };

        const size_t m_blockSize;
        const size_t m_objectSize;
        const unsigned int m_maxObjects;
	    AllocatorMode m_allocatorMode;
        Block* m_pHead;
        char* m_pPool;
        unsigned int m_poolIndex;
        unsigned int m_blockCnt;
        unsigned int m_blocksInUse;
        unsigned int m_allocations;
        unsigned int m_deallocations;
        const char* m_name;
};

/// Template class to create external memory pool
template <class T, unsigned int Objects>
class AllocatorPool : public Allocator
{
    public:
	    AllocatorPool() : Allocator(sizeof(T), Objects, m_memory) { }

    private:
	    char m_memory[sizeof(T) * Objects];
};

/// Macro to provide header file interface
#define DECLARE_ALLOCATOR \
    public: \
        void* operator new(size_t size) { \
            return _allocator.Allocate(size); \
        } \
        void operator delete(void* pObject) { \
            _allocator.Deallocate(pObject); \
        } \
    private: \
        static Allocator _allocator; 

/// Macro to provide source file interface
#define IMPLEMENT_ALLOCATOR(class, objects, memory) \
	Allocator class::_allocator(sizeof(class), objects, memory, #class);

#endif