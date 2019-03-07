#include<stdio.h>
#include<windows.h>
#include <process.h> 

HANDLE hMutex;
int tickets = 100;

unsigned __stdcall Fun1Proc(void* pArguments)
{
	while (tickets>0)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets>0)
			printf("thread1 sell ticket : %d\n", tickets--);
		ReleaseMutex(hMutex);
	}
	_endthreadex(0);
	return 0;
}

unsigned __stdcall Fun2Proc(void* pArguments) 
{
	while (tickets>0)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets>0)
			printf("thread2 sell ticket : %d\n", tickets--);
		ReleaseMutex(hMutex);
	}
	_endthreadex(0);
	return 0;
}

int main()
{
	HANDLE hThread1, hThread2;

	hMutex = CreateMutex(NULL, FALSE, NULL);

	hThread1 = (HANDLE) _beginthreadex(NULL, 0, Fun1Proc, NULL, 0, NULL);   
	hThread2 = (HANDLE) _beginthreadex(NULL, 0, Fun2Proc, NULL, 0, NULL);

	WaitForSingleObject(hThread1, INFINITE);
	CloseHandle(hThread1);
	WaitForSingleObject(hThread2, INFINITE);
	CloseHandle(hThread2);

	system("pause");
	return 0;
}

