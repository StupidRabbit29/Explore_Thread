//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <windows.h>
//#include <process.h> 
//#include <time.h>
//
//bool exit_sign = false;//�˳���־
//bool print_time = false;//��ӡʱ���־
//bool time_lock = false;//ʱ��������־
//
//unsigned __stdcall getinput(void* pArguments)
//{
//	int choice = 0;//�û�ѡ��
//
//	while (!exit_sign)
//	{
//		printf("�����������\n");
//		scanf("%d", &choice);
//
//		if (choice == 1)//����1��ӡʱ��
//		{
//			print_time = true;
//		}
//		else if (choice == 26)//����26�˳�ϵͳ
//		{
//			exit_sign = 1;
//		}
//		else if (choice == 3)//����3����ʱ��
//		{
//			time_lock = true;
//		}
//		else if (choice == 4)//����4�������
//		{
//			time_lock = false;
//		}
//	}
//
//	_endthreadex(0);
//	return 0;
//}
//
//unsigned __stdcall time(void* pArguments)
//{
//	int time = 0;
//
//	while (!exit_sign)
//	{
//		Sleep(2000);
//
//		if (!time_lock)
//			time++;
//		else
//			printf("Time Locked.\n");
//
//		if (print_time)
//		{
//			printf("%d\n", time);
//			print_time = false;
//		}
//
//	}
//
//	printf("�˳�ʱ�䣺%d\n", time);
//
//	_endthreadex(0);
//	return 0;
//}
//
//int main()
//{   //�����߳�1�� 
//	HANDLE hRead1 = (HANDLE)_beginthreadex(NULL, 0, getinput, NULL, 0, NULL);
//	//�����߳�2��
//	HANDLE hRead2 = (HANDLE)_beginthreadex(NULL, 0, time, NULL, 0, NULL);
//	WaitForSingleObject(hRead1, INFINITE);
//	CloseHandle(hRead1);
//	WaitForSingleObject(hRead2, INFINITE);
//	CloseHandle(hRead2);
//
//	printf("�˳�ϵͳ��\n");
//	system("pause");
//	return 0;
//}