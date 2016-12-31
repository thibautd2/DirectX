// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#pragma warning(push)
#pragma warning(disable : 4005)
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define NODRAWTEXT
#define NOGDI
#define NOBITMAP
#define NOMCX
#define NOSERVICE
#define NOHELP
#pragma warning(pop)

// Windows Header Files:
#include <windows.h>
#include <mmsystem.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdint.h>
#include <utility>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <stack>
#include <vector>


#include <d3d11.h>
#include <dinput.h>

#include "d3dclass.h"

#include "DirectXTK/SimpleMath.h"
#include "inputclass.h"

#include "fontshaderclass.h"
#include "colorshaderclass.h"

#include "textureclass.h"
#include "Fontclass.h"
#include "positionclass.h"
#include "systemclass.h"
#include "applicationclass.h"
#include "timerclass.h"
#include "fpsclass.h"
#include "textclass.h"