#pragma once
#include "ibaseclientdll.h"
#include <string_view>

#define CLIENTDLL "client.dll"

namespace i
{
	void Setup();

	inline BaseClientDll* client	 = nullptr;
}