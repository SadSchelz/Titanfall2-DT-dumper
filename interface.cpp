#include "interface.h"

#include <Windows.h>
#include <stdexcept>
#include <format>

void* CaptureInterface(const char* module_name, const char* interface_name)
{
	auto create_interface_fn = reinterpret_cast<void* (*)(const char* pName, int* pReturnCode)>(GetProcAddress(GetModuleHandleA(module_name), "CreateInterface"));
	return create_interface_fn(interface_name, nullptr);
}

void i::Setup()
{
	client = reinterpret_cast<BaseClientDll*>(CaptureInterface("client.dll", "VClient018"));
}