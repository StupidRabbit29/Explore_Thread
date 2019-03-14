#include<stdio.h>
#include<windows.h>//创建线程函数需要操作系统函数
#include <process.h> //创建线程函数头文件


HANDLE hMutex;
int tickets = 100;

//线程函数的返回值是指定类型，形参也只能有一个
unsigned __stdcall Fun1Proc(void* pArguments)
{
	while (tickets>0)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets>0)
			printf("thread%d sell ticket : %d\n", *(int*)pArguments, tickets--);
		ReleaseMutex(hMutex);
	}
	_endthreadex(0);//线程完成时要调用_endthread

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
	HANDLE hThread1, hThread2;//线程的访问句柄

	int num1 = 1, num2 = 2;
	int *p1 = &num1, *p2 = &num2;
	hMutex = CreateMutex(NULL, FALSE, NULL);
   
	/*创建对应于Fun1Proc函数的线程 */
	hThread1 = (HANDLE) _beginthreadex(NULL, 0, Fun1Proc, p1, 0, NULL);   
	hThread2 = (HANDLE) _beginthreadex(NULL, 0, Fun1Proc, p2, 0, NULL);

	WaitForSingleObject(hThread1, INFINITE);//等待线程结束
	CloseHandle(hThread1);//无须控制线程时删除此句柄，可防止内核对象泄露
	WaitForSingleObject(hThread2, INFINITE);
	CloseHandle(hThread2);

	system("pause");
	return 0;
}

