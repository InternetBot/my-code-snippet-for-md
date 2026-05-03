#include <windows.h>

//How to create a dll

extern __declspec(dllexport) void HelloWorld() {
    MessageBoxA(NULL, "My first DLL", "DLL Message", MB_ICONINFORMATION);
}
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}