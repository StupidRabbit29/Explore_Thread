//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <windows.h>
//#include <process.h> 
//
//
//unsigned __stdcall getInput(void* pArguments);
//unsigned __stdcall output(void* pArguments);
//
//char ch = 'A';
//
//
//int new_sign = 0; //�������ͬ����
//int exit_sign = 0; //��ӽ������
//unsigned __stdcall getInput(void* pArguments)
//{
//	int i = 0;
//	while (!exit_sign) {
//		if (new_sign == 0) {
//			printf("input a char\n");
//			ch = getchar();
//			new_sign = 1;
//			getchar();//�Ե�\n
//		}
//		}
//		_endthreadex(0);
//		return 0;
//}
//
//unsigned __stdcall output(void* pArguments)
//	{
//		FILE * cfPtr = NULL;
//		cfPtr =fopen("data.txt", "w");
//		/*if (( ) == NULL)
//		printf("can't open file\n");
//		else {*/
//			while (!exit_sign) {
//				if (new_sign) {
//					fputc(ch, cfPtr);  //д�ļ� 
//					printf("get:%c\n", ch);
//					new_sign = 0;    //��λ���ٶ�
//				}//end if new_sign
//				//fclose(cfPtr);
//			}//end while    
//		//}//end else
//
//		return 0;
//	}//end func output
//
//
//int main()
//{   //�����߳�1�����ڴӼ��̽����ַ���д�뵽ȫ�ֱ���ch��    
//	HANDLE hRead1 = (HANDLE)_beginthreadex(NULL, 0, getInput, NULL, 0, NULL);
//	//�����߳�2�����ڽ�ȫ�ֱ���chд���ļ� 
//	HANDLE hRead2 = (HANDLE)_beginthreadex(NULL, 0, output, NULL, 0, NULL);
//	WaitForSingleObject(hRead1, INFINITE);
//	CloseHandle(hRead1);
//	WaitForSingleObject(hRead2, INFINITE);
//	CloseHandle(hRead2);
//	return 0;
//}