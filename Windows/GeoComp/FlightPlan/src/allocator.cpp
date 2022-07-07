// AUTHOR:		https://www.codeproject.com/Articles/1087619/State-Machine-Design-in-Cplusplus-2
// PROJECT:		WorldPerception
// DOCUMENT:	None
// DESCRIPTION: This file defines memory allocator that allocates/deallocates blocks of memory
//              from a pre-allocated static memory pool for state machine events

#include "allocator.h"
#include "fault.h"
#include <new>

Allocator::Allocator(size_t size, unsigned int objects, char* memory, const char* name) :
    m_blockSize(size < sizeof(long*) ? sizeof(long*):size),
    m_objectSize(size),
    m_maxObjects(objects),
    m_pHead(NULL),
    m_pPool(NULL),
    m_poolIndex(0),
    m_blockCnt(0),
    m_blocksInUse(0),
    m_allocations(0),
    m_deallocations(0),
    m_name(name)
{
    /// If using a fixed memory pool 
	if (m_maxObjects)
	{
		/// If caller provided an external memory pool
		if (memory)
		{
			m_pPool = memory;
			m_allocatorMode = STATIC_POOL;
		}
		else 
		{
			m_pPool = (char*)new char[m_blockSize * m_maxObjects];
			m_allocatorMode = HEAP_POOL;
		}
	}
	else
		m_allocatorMode = HEAP_BLOCKS;
}

Allocator::~Allocator()
{
	/// If using pool then destroy it, otherwise traverse free-list and 
	/// destroy each individual block
    if (m_allocatorMode == HEAP_POOL)
    {
        delete[] m_pPool;
    }
	else if (m_allocatorMode == HEAP_BLOCKS)
	{
		while(m_pHead)
			delete [] (char*)Pop();
	}
}

void* Allocator::Allocate(size_t size)
{
    ASSERT_TRUE(size <= m_objectSize);
	
    /// Get an existing block of memory
    void* pBlock = Pop();

    /// If can't obtain an existing block then get a new one
    if (pBlock == NULL)
    {
        /// If using a pool method then get block from pool,
        /// otherwise using dynamic so get block from heap
        if (m_maxObjects)
        {
            /// If we have not exceeded the pool maximum
            if (m_poolIndex < m_maxObjects)
            {
                pBlock = (void*)(m_pPool + (m_poolIndex++ * m_blockSize));
            }
            else
            {
                /// Get the pointer to the new handler
                new_handler handler = set_new_handler(0);
                set_new_handler(handler);

                /// If a new handler is defined, call it
                if (handler)
                    (*handler)();
                else
                    ASSERT();
            }
        }
        else
        {
        	m_blockCnt++;
            pBlock = (void*)new char[m_blockSize];
        }
    }

    m_blocksInUse++;
    m_allocations++;
	
    return pBlock;
}

void Allocator::Deallocate(void* pBlock)
{
    Push(pBlock);
	m_blocksInUse--;
	m_deallocations++;
}

void Allocator::Push(void* pMemory)
{
    Block* pBlock = (Block*)pMemory;
    pBlock->pNext = m_pHead;
    m_pHead = pBlock;
}

void* Allocator::Pop()
{
    Block* pBlock = NULL;

    if (m_pHead)
    {
        pBlock = m_pHead;
        m_pHead = m_pHead->pNext;
    }

    return (void*)pBlock;
}