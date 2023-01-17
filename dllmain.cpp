#include "interface.h"

#include <Windows.h>
#include <chrono>
#include <thread>
#include <iostream>

unsigned long __stdcall MainFunc(HMODULE hModule) 
{
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    n::Setup();


    while (!GetAsyncKeyState(VK_END)) 
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

    FreeConsole();
    if (f) fclose(f);

    FreeLibraryAndExitThread(hModule, EXIT_SUCCESS);
    return 0ul;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD call_reason, LPVOID lpReserved)
{
    if (call_reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainFunc, nullptr, 0, nullptr);
    }

    return TRUE;
}

