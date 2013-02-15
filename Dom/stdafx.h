// stdafx.h : Includedatei f�r Standardsystem-Includedateien
// oder h�ufig verwendete projektspezifische Includedateien,
// die nur in unregelm��igen Abst�nden ge�ndert werden.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Selten verwendete Teile der Windows-Header nicht einbinden.

#include <vector>
#include <memory>
#include <sstream>
#include <exception>
#include <cstdarg>
#include <set>

using namespace std;

#define DEBUG 1

void debug_print(const char* msg);
