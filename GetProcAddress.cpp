#include <stdio.h>
#include <windows.h>

int main(int argc, char** argv) {
	if (argc <= 1 || !argv[1] || !argv[2]) {
		printf("Usage: nameDLL Function\nExample: user32.dll MessageBoxA");
		ExitProcess(0);
	};
	
	HMODULE hDll = LoadLibrary(argv[1]);

	if (hDll) {
		FARPROC proc = GetProcAddress(hDll, argv[2]);
		if (proc) {
			printf("[ + ] Offset: 0x%X = %s\n", proc, argv[2]);
			FreeLibrary(hDll);
		} else
			printf("[ - ] GetProcAddress failed: %s\n", argv[2]);
	} else
		printf("[ - ] LoadLibrary failed\n: %s\n", argv[1]);
	
	ExitProcess(0);
};