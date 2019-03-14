#include<stdio.h>
#include<windows.h>//�����̺߳�����Ҫ����ϵͳ����
#include <process.h> //�����̺߳���ͷ�ļ�


HANDLE hMutex;
int tickets = 100;

//�̺߳����ķ���ֵ��ָ�����ͣ��β�Ҳֻ����һ��
unsigned __stdcall Fun1Proc(void* pArguments)
{
	while (tickets>0)
	{
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets>0)
			printf("thread%d sell ticket : %d\n", *(int*)pArguments, tickets--);
		ReleaseMutex(hMutex);
	}
	_endthreadex(0);//�߳����ʱҪ����_endthread

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
	HANDLE hThread1, hThread2;//�̵߳ķ��ʾ��

	int num1 = 1, num2 = 2;
	int *p1 = &num1, *p2 = &num2;
	hMutex = CreateMutex(NULL, FALSE, NULL);
   
	/*������Ӧ��Fun1Proc�������߳� */
	hThread1 = (HANDLE) _beginthreadex(NULL, 0, Fun1Proc, p1, 0, NULL);   
	hThread2 = (HANDLE) _beginthreadex(NULL, 0, Fun1Proc, p2, 0, NULL);

	WaitForSingleObject(hThread1, INFINITE);//�ȴ��߳̽���
	CloseHandle(hThread1);//��������߳�ʱɾ���˾�����ɷ�ֹ�ں˶���й¶
	WaitForSingleObject(hThread2, INFINITE);
	CloseHandle(hThread2);

	system("pause");
	return 0;
}

