#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;
#pragma warning(disable:4996)
void menu()
{
	printf("\t\t\t\t******************************************\n");
	printf("\t\t\t\t\t��ӭʹ�����������Զ�����ϵͳ\n");
	printf("\t\t\t\t\t�밴��ϵͳ������ʾ���в���\n");
	printf("\t\t\t\t******************************************\n");
}
int get_int(int MAX)    //��ȡ���������
{
	int a;
	a = (rand() % MAX) + 1;
	return a;
}


float get_float(int MAX)   //��ȡ�����������
{
	float a;
	int b;
	a = (float)((rand() % 100)*0.01);//С������
	b = (rand() % MAX);
	a = a + b;
	return a;
}


char get_symbol(int x)   //��ȡ�����
{
	if (x == 1){    //��ȡ+-����������
		int a;
		char result = ' ';
		a = (rand() % 2) + 1;
		if (a == 1)result = '+';
		if (a == 2)result = '-';
		return result;
	}
	else if (x == 2){      //��ȡ*/����������
		int a;
		char result= ' ';
		a = (rand() % 2) + 1;
		if (a == 1)result = '*';
		if (a == 2)result = '/';
		return result;
	}
	else {          //��ȡ+-*/����������
		int a;
		char result= ' ';
		a = (rand() % 4) + 1;
		if (a == 1)result = '+';
		if (a == 2)result = '-';
		if (a == 3)result = '*';
		if (a == 4)result = '/';
		return result;
	}
}
int math(int operate,int symbols, int int_float, int out, int num, int MAX)		//operateΪѡ����������1Ϊ�Ӽ���2Ϊ�˳���3Ϊ�������
{																				//symbolΪ�Ƿ�������ţ�1Ϊ�����ţ�0Ϊ����
	int flag;																	//int_floatΪѡ��С����С����1ΪС����0Ϊ����
	FILE *fp = NULL;																	//outΪ�����ʽѡ��1Ϊ������ļ���0Ϊ��������ļ�
	if (out == 1)																//numΪ����������MAXΪ�����е������ֵ
	{
		fp = fopen("d:\\math.txt", "w");		//ֱ�������d��
	}
	if (int_float == 1){
		for (int i = 0; i < num; i++)
		{
			float data1, data2, data3;
			char symbol1, symbol2;
			data1 = get_float(MAX);
			data2 = get_float(MAX);
			data3 = get_float(MAX);
			symbol1 = get_symbol(operate);
			symbol2 = get_symbol(operate);
			flag = (rand() % 2) + 1;   //flagΪѡ������λ�ã�1Ϊǰ��λ���ݼ����ţ�2Ϊ����λ���ݼ�����
			if (symbols == 1)
			{
				if (flag == 1)  //ǰ��λ���ݼ�����
				{
					printf("��%d��: (%.2f %c %.2f) %c %.2f=\n\n", i+1,data1, symbol1, data2, symbol2, data3);
					if (out==1)   //������ļ�
						fprintf(fp,"��%d��: (%.2f %c %.2f) %c %.2f=\n\n",i+1, data1, symbol1, data2, symbol2, data3);
				}
				if(flag==2)  //����λ���ݼ�����
				{
					printf("��%d��: %.2f %c (%.2f %c %.2f)=\n\n",i+1, data1, symbol1, data2, symbol2, data3);
					if (out==1)     //������ļ�
						fprintf(fp,"��%d��: %.2f %c (%.2f %c %.2f)=\n\n",i+1, data1, symbol1, data2, symbol2, data3);
				}
			}
			if (symbols==0)     //��������
			{
					printf("��%d��: %.2f %c %.2f %c %.2f=\n\n",i+1, data1, symbol1, data2, symbol2, data3);
					if (out==1)    //������ļ�
						fprintf(fp,"��%d��: %.2f %c %.2f %c %.2f=\n\n",i+1, data1, symbol1, data2, symbol2, data3);
			}
		}
		if (out == 1)
			fclose(fp);   //���ѡ���������ļ�����Ҫ�ر��ļ�
	}


	if (int_float == 0){
		for (int i = 0; i < num; i++)
		{
			int data1, data2, data3;
			char symbol1, symbol2;
			data1 = get_int(MAX);
			data2 = get_int(MAX);
			data3 = get_int(MAX);
			symbol1 = get_symbol(operate);
			symbol2 = get_symbol(operate);
			flag = (rand() % 2) + 1;
			if (symbols == 1)  //������
			{
				if (flag == 1)  //ǰ��λ���ݼ������
				{
					printf("��%d��: (%d %c %d) %c %d=\n\n",i+1, data1, symbol1, data2, symbol2, data3);
					if (out == 1)   //������ļ�
						fprintf(fp, "��%d��: (%d %c %d) %c %d=\n\n",i+1, data1, symbol1, data2, symbol2, data3);
				}
				if (flag==2)   //����λ���ݼ�����
				{
					printf("��%d��: %d %c (%d %c %d)=\n\n",i+1, data1, symbol1, data2, symbol2, data3);
					if (out == 1)   //������ļ�
						fprintf(fp, "��%d��: %d %c( %d %c %d)=\n\n",i+1, data1, symbol1, data2, symbol2, data3);
				}
			}
			if (symbols==0)   //��������
			{
					printf("��%d��: %d %c %d %c %d=\n\n",i+1, data1, symbol1, data2, symbol2, data3);
					if (out == 1)    //������ļ�
						fprintf(fp, "��%d��: %d %c %d %c %d=\n\n",i+1, data1, symbol1, data2, symbol2, data3);
			}

		}
		if (out == 1)  //���ѡ���������ļ�����ʱ��Ҫ�ر��ļ�
			fclose(fp);
	}
	
	return 0;
}
int main()
{
	system("color F0");//��һ����Ӧ�����ڶ�����Ӧ������ɫ
	int reset;  //������Ƿ����³��⣬1Ϊ���³��⣬0Ϊ��
	srand((unsigned)time(NULL));
	while (1)
	{
		menu();
		int num;//��Ŀ����
		cout << "��������Ŀ������";
		while (1){
			cin >> num;
			if (num <= 0 || num > 200)
				cout << "����������������룺";
			else
				break;
		}


		int MAX;//�������������
		cout << "���������������������";
		while (1){
			cin >> MAX;
			if (MAX < 0 || MAX>200)
				cout << "��ֵ������С�����������룺";
			else
				break;
		}


		int int_float;//��������С��
		cout << "�������Ƿ��С����1Ϊ�ǣ�0Ϊ��";
		while (1){
			cin >> int_float;
			if (int_float != 1 && int_float != 0)
				cout << "����������������룺";
			else
				break;
		}

		int operate;//��������
		cout << "������ѡ����������1Ϊ���Ӽ���2Ϊ���˳�,3Ϊ�������: ";
		while (1){
			cin >> operate;
			if (operate != 1 && operate != 2 && operate != 3)
				cout << "����������������룺";
			else
				break;
		}


		int symbols;//�Ƿ������
		cout << "��ѡ���Ƿ�������ţ�1Ϊ�ǣ�0Ϊ��: ";
		while (1){
			cin >> symbols;
			if (symbols != 1 && symbols != 0)
				cout << "����������������룺";
			else
				break;
		}


		int out;//�Ƿ�������ļ�
		cout << "��ѡ���Ƿ�������ļ���1Ϊ�ǣ�0Ϊ��: ";
		while (1){
			cin >> out;
			if (out != 1 && out != 0)
				cout << "����������������룺";
			else
				break;
		}


		math(operate, symbols, int_float, out, num, MAX);
		system("pause");//��ͣ
		cout << "�Ƿ�����������Ŀ��1Ϊ�ǣ�0Ϊ��";

		while (1)
		{
			cin >> reset;
			if (reset != 1 && reset != 0)
				cout << "����������������룺";
			else
				break;
		}
		if (reset == 0)
		{
			cout << "\n��ӭ�ڴ�ʹ�ñ�ϵͳ���ټ���\n";
			break;
		}
		if (reset == 1){
			system("cls");//��������
		}
	}
}