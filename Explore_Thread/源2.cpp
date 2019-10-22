#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <process.h> 
#include <time.h>

bool exit_sign = false;//退出标志
bool print_time = false;//打印时间标志
bool time_lock = false;//时间锁定标志

int time_ = 0;

unsigned __stdcall getinput(void* pArguments)
{
	int choice = 0;//用户选择

	while (!exit_sign)
	{
		printf("请输入操作：\n");
		scanf("%d", &choice);

		if (choice == 1)//输入1打印时间
		{
			//print_time = true;
			printf("%d\n", time_);
			print_time = false;
		}
		else if (choice == 26)//输入26退出系统
		{
			exit_sign = 1;
		}
		else if (choice == 3)//输入3锁定时间
		{
			time_lock = true;
		}
		else if (choice == 4)//输入4解除锁定
		{
			time_lock = false;
		}
	}

	_endthreadex(0);
	return 0;
}

unsigned __stdcall time(void* pArguments)
{
	/*int time = 0;*/

	while (!exit_sign)
	{
		Sleep(2000);

		if (!time_lock)
			time_++;
		else
			printf("Time Locked.\n");

		/*if (print_time)
		{
			printf("%d\n", time);
			print_time = false;
		}*/

	}

	printf("退出时间：%d\n", time_);

	_endthreadex(0);
	return 0;
}

unsigned __stdcall print(void* pArguments)
{
	printf("111\n");

	Sleep(10000);
	_endthreadex(0);
	return 0;
}

int main()
{   //创建线程1： 
	HANDLE hRead1 = (HANDLE)_beginthreadex(NULL, 0, print, NULL, 0, NULL);
	//创建线程2：
	HANDLE hRead2 = (HANDLE)_beginthreadex(NULL, 0, print, NULL, 0, NULL);
	HANDLE hRead3 = (HANDLE)_beginthreadex(NULL, 0, print, NULL, 0, NULL);
	//WaitForSingleObject(hRead3, INFINITE);
	CloseHandle(hRead3);
	//WaitForSingleObject(hRead1, INFINITE);
	CloseHandle(hRead1);
	//WaitForSingleObject(hRead2, INFINITE);
	CloseHandle(hRead2);

	printf("退出系统！\n");
	system("pause");
	return 0;
}