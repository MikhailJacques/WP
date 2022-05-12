// AUTHOR:		
// PROJECT:		WorldPerception
// DOCUMENT:	None
// DESCRIPTION: This file defines validation handling functions for state machine operation

#include "fault.h"
#include <assert.h>

#ifdef _WIN32 // WIN32, _MSC_VER
#include <Windows.h>
#else
#include <unistd.h>
#endif

///----------------------------------------------------------------------------
/// FaultHandler
///----------------------------------------------------------------------------
void FaultHandler(const char* file, unsigned short line)
{
    /// If you hit this line, it means one of the ASSERT macros failed.
#if WIN32
    DebugBreak();
#else
    __builtin_trap();
#endif

    assert(0);

    /// Trap fault here
    while(1);
}
