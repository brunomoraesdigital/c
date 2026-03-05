#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
// Sistema: Windows 
#include <windows.h>
#else
// Sistema: Linux / Android 
#include <unistd.h>
#endif



int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif
	

	return 0;
}


