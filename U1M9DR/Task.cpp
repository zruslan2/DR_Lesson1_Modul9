#include <stdio.h>
#include <cctype>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <malloc.h>
#include "MyFunc.h"

using namespace std;
unsigned short int nz;

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int i, j;
	while (true)
	{
		cout << "������� ����� �������, 0 - ��� ������ "; cin >> nz; cin.get();

		if (nz == 0)
		{
			break;
			system("exit");
		}
		else if (nz == 1)
		{
			/*1.	��� ��������� ������ ����� �����
				a.������������ ���������� ������, ������ ������� �������� ����� ����������� 
				�� ������ �������� ���������������� ������� ���������� �������
				b.������������ ���������� ������, ������ ������� �������� ����� ����������� 
				�� ������ �������� ��������������� ������ ���������� �������*/
			int *m = NULL, *newM = NULL, *newM1 = NULL;
			int coll, row, sum = 0;
			printf("������� ���-�� ��������: \n");
			scanf("%d", &coll);
			printf("������� ���-�� �����: \n");
			scanf("%d", &row);

			m = (int*)calloc((coll*row), sizeof(int));
			newM = (int*)calloc((coll), sizeof(int));
			newM1 = (int*)calloc((row), sizeof(int));
			if (m != NULL&&newM != NULL&&newM1 != NULL)
			{
				creatMatrix(m, row, coll);
				printMatrix(m, row, coll);

				int max = 0;

				for (j = 0; j < coll; j++)
				{
					for (i = 0; i < row; i++)
					{
						if (myAbs(*(m + i*coll + j))> myAbs(max))
							max= *(m + i*coll + j);						
					}
					*newM = max;					
					max = 0;
					newM++;
				}

				printf("a.\n");
				print_arr(newM - coll, coll);

				for (j = 0; j < row; j++)
				{
					for (i = 0; i < coll; i++)
					{
						if (myAbs(*(m + j*coll + i))> myAbs(max))
							max = *(m + j*coll + i);
					}
					*newM1 = max;
					max = 0;
					newM1++;
				}
				printf("b.\n");
				print_arr(newM1 - row, row);
			}
		}
		else if (nz == 5)
		{
			/*5. ������ ����� �����. ������� �� ��� ������. ��������� ����� ������ ��������� �������*/
			int c,sum=0,razm=0;			
			int *numbers = NULL;
			int *m;			
			do
			{
				printf("������� ����� (0 - ��� ������): ");
				scanf("%d", &c);
				razm++;
				m= (int*)realloc(numbers, razm * sizeof(int));
				if (m != NULL)
				{
					numbers = m;
					numbers[razm - 1] = c;
				}
				else
				{
					free(numbers);
					printf("������ ��������� ������");
					system("exit");
				}
			} while (c!=0);
			for (int i = 0; i < razm; i++)
			{
				if (numbers[i]%2==0)sum += numbers[i];
			}
			printf("����� ������ ��������� = %d\n", sum);
			free(numbers);		
			// ��� ��������� ������ ������ �� ���!!!
		}
		else
		{
			red();
			cout << "������ ������� �� ���������� \n";
			white();
		}
	}
}