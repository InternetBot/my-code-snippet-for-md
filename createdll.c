#include <Windows.h>
#include <stdio.h>


// genearting a dll with gcc
// gcc -shared -o mydll.dll createdll.c -Wl,--out-implib,libmydll.a

void CreMessageBox (){
	MessageBoxA(NULL, "Dll loaded", NULL, MB_OK);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved){

    switch (dwReason){
        case DLL_PROCESS_ATTACH: {
            CreMessageBox();
            break;
        };
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }

    return TRUE;
}

