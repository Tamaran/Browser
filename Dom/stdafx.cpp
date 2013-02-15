// stdafx.cpp : Quelldatei, die nur die Standard-Includes einbindet.
// Dom.pch ist der vorkompilierte Header.
// stdafx.obj enthält die vorkompilierten Typinformationen.

#include "stdafx.h"

void debug_print(const char* msg)
{
#ifdef DEBUG
	printf(msg);
#endif
}