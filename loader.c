#include <windows.h>
#include <stdio.h>
typedef void(WINAPI* HelloWorldFunctionPointer)();

// loads the dll
void call() {
	//find dll
	HMODULE hmodule = GetModuleHandleA("sampledll.dll");

	if (hmodule == NULL) {
		hmodule = LoadLibraryA("sampledll.dll");
	}
	// find fun in dll and gets the address
	PVOID pHelloWorld = GetProcAddress(hmodule, "HelloWorld");

	HelloWorldFunctionPointer HelloWorld = (HelloWorldFunctionPointer)pHelloWorld;

	HelloWorld(); //invoking the function in the DLL


} 


int main() {

	call();

	return 0;
}