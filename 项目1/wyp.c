#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "wyp.h"

int addStudents()
{
	int choice2;
	fflush(stdin);
	system("cls");
	add();
	printOneSpace();
	printMessage2();
	printf("\n���������ѡ��\n");
	scanf("%d", &choice2);
	switch (choice2)
	{
		case 1: break;
		case 2: addStudents();
			break;
		case 3: return 1;
	}
	return 0;
}

int delStudents(int t)
{
	int choice2;
	system("cls");
	deletedata(&t);
	printOneSpace();
	printMessage2();
	scanf("%d", &choice2);
	switch (choice2)
	{
		case 1: break;
		case 2:	t--;
			delStudents(t);
			break;
		case 3: return 1;
	}
	return 0;
}

int alterStudents(int t)
{
	int choice2;
	system("cls");
	correctdata(&t);
	printMessage2();
	scanf("%d", &choice2);
	switch (choice2)
	{
		case 1: break;
		case 2: alterStudents(t);
			break;
		case 3: return 1;
	}
	return 0;
}

int findStudents(int t)
{
	int choice2;
	int choice3;
	system("cls");
	printMessage1();
	t = stu_num();
	printf("(��ǰѧ������Ϊ%d)\n", t);
	scanf("%d", &choice3);
	t = stu_num();
	switch (choice3)
	{
		case 1:findByName(t); break;
		case 2:findById(t); break;
		case 3:findByDorm(t); break;
		case 4:findByGender(t); break;
		case 5:break;
	}
	printOneSpace();
	printMessage2();
	scanf("%d", &choice2);
	switch (choice2)
	{
		case 1: break;
		case 2: findStudents(t);
			break;
		case 3: return 1;
	}
	return 0;
}

int sortStudents()
{
	int sc;
	int choice2;
	system("cls");
	printSpacesAndLines(24, 38);
	printf("\t\t\t1.����\t\t2.��ѧ\t\t3.Ӣ��\n");
	printOneSpace();
	printSpacesAndLines(24, 38);
	printf("\n���������ѡ��\n");
	scanf("%d", &sc);
	sort(stu_num(), sc);
	printMessage2();
	printf("\n���������ѡ��\n");
	scanf("%d", &choice2);
	switch (choice2)
	{
		case 1:break;
		case 2:sortStudents();
		case 3:return 1;
	}
	return 0;
}

int printStudentsInfo()
{
	int choice2;
	system("cls");
	data(stu_num());
	printMessage2();
	scanf("%d", &choice2);
	switch (choice2)
	{
		case 1: break;
		case 2: printStudentsInfo();
		case 3: return 1;
	}
	return 0;
}

void mainface()
{
	int choice1;
	while (1)
	{
		int t = stu_num();
		int returnValue = 1;
		menu();
		printSpaces(80);
		printf("(��ǰѧ������Ϊ%d)\n", t);
		scanf("%d", &choice1);
		switch (choice1)
		{
			case 1:
				returnValue = addStudents();
				break;
			case 2:
				returnValue = delStudents(t);
				break;
			case 3:
				returnValue = alterStudents(t);
				break;
			case 4:
				returnValue = findStudents(t);
				break;
			case 5:
				returnValue = sortStudents();
				break;
			case 6:
				returnValue = printStudentsInfo();
				break;
			case 7:
				break;
			default:
				printf("�����������������룺");
				continue;

		}
		if (returnValue == 1)
		{
			break;
		}
	}
	exitProgram();

}
void printMessage1()
{
	printSpacesAndLines(33, 40);
	printf("\t\t\t\t 1.��������ѯ\t\t    2.��ѧ�Ų�ѯ\n");
	printOneSpace();
	printf("\t\t\t\t 3.�������ѯ\t\t    4.���Ա��ѯ\n");
	printOneSpace();
	printf("\t\t\t\t 5.�˻���ҳ��\n");
	printOneSpace();
	printSpacesAndLines(33, 40);
}

void printMessage2()
{
	printf("\n     1.������ҳ��\n\n     2.������һ��\n\n     3.�˳�ʹ��\n");
}

void printMessage3()
{
	printOneLine();
	printf("���   ѧ�� \t   ����    �Ա�       ��ϵ�绰     �����뷿��       ��������         ����    ��ѧ    Ӣ��\n");
	printOneLine();
}

void printStars()
{
	printf("  \t\t\t\t********************************************\n");
}

void printOneLine()
{
	printf("----------------------------------------------------------------------------------------------------------------------\n");
}


void printOneSpace()
{
	puts(" ");
}

void printSpaces(int n)
{
	for (int i = 0; i < n; i++)   printf(" ");
}

void printSpacesAndLines(int m, int n)
{
	for (int i = 0; i < m; i++)  printf(" ");
	for (int i = 0; i < n; i++)  printf("-");
	puts("\n");
}

void menu()
{
	system("cls");
	system("color 0F");
	printStars(); printOneSpace();
	printf("  \t\t\t\t\t\tѧ������ϵͳ\n");
	printOneSpace(); printStars();
	printOneSpace();
	printf("  \t\t\t\t 1.���ѧ����Ϣ\t\t    2.ɾ��ѧ����Ϣ\n");
	printOneSpace();
	printf("  \t\t\t\t 3.�޸�ѧ����Ϣ\t\t    4.��ѯѧ����Ϣ\n");
	printOneSpace();
	printf("  \t\t\t\t 5.ѧ���ɼ�����\t\t    6.��ӡѧ����Ϣ\n");
	printOneSpace();
	printf("  \t\t\t\t 7.�˳�ʹ��\n");
}

void exitProgram()
{
	printf("ллʹ��");
}








void data(int count)
{
	int t = stu_num();
	sortname(t);
	printOneSpace();
	FILE *ps;
	struct student stu[100];
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
		exit(1);
	}
	printMessage3();
	for (int i = 0; i < count; i++)
	{
		fread(&stu[i], sizeof(struct student), 1, ps);
		printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
		printf(" %-4.6s  %-4.6s     %4.4d��%2.2d��%2.2d��   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
			stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
		printOneLine();
	}
	fclose(ps);
}

void findByName(int count)
{
	char fname[15];
	int flag = 0;
	struct student stu[100];
	int i;
	printf("\n����������:");
	scanf("%s", &fname);
	FILE *ps;
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
		exit(1);
	}
	for (i = 0; i < count; i++)
	{
		if (fread(&stu[i], sizeof(struct student), 1, ps) != 1)
		{
			if (feof(ps))
			{
				fclose(ps); exit(1);
			}
			printf("���ļ�����");
		}
		if (strcmp(stu[i].name, fname) == 0)
		{
			printMessage3();
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
			printf(" %-4.6s  %-4.6s     %4.4d��%2.2d��%2.2d��   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
				stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
			printOneLine();
			flag = 1;
			break;
		}
	}
	printOneSpace();
	if (!flag)  puts("���޴���");

	fclose(ps);
}

void findById(int count)
{
	char fid[15];
	int flag = 0;
	struct student stu[100];
	int i;
	printf("\n������ѧ��:");
	scanf("%s", &fid);
	FILE *ps;
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
		exit(1);
	}
	for (i = 0; i < count; i++)
	{
		if (fread(&stu[i], sizeof(struct student), 1, ps) != 1)
		{
			if (feof(ps))
			{
				fclose(ps);  exit(1);
			}
			printf("���ļ�����");
		}
		if (strcmp(stu[i].id, fid) == 0)
		{
			printMessage3();
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
			printf(" %-4.6s  %-4.6s     %4.4d��%2.2d��%2.2d��   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
				stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
			printOneLine();
			flag = 1;
			break;
		}
	}
	printOneSpace();
	if (!flag)
		puts("���޴���");
	fclose(ps);
}

void findByDorm(int count)
{
	char fdorm[6];
	int flag = 0;
	struct student stu[100];
	int i;
	printf("\n����������:");
	scanf("%s", &fdorm);
	FILE *ps;
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
		exit(1);
	}
	for (i = 0; i < count; i++)
	{
		if (fread(&stu[i], sizeof(struct student), 1, ps) != 1)
		{
			if (feof(ps))
			{
				fclose(ps);  exit(1);
			}
			printf("���ļ�����");
		}
		if (strcmp(stu[i].dorm, fdorm) == 0)
		{
			printMessage3();
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
			printf(" %-4.6s  %-4.6s     %4.4d��%2.2d��%2.2d��   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
				stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
			flag = 1;
			printOneLine();
			break;
		}
	}
	printOneSpace();
	if (!flag)
		puts("���޴�����");
	fclose(ps);
}

void findByGender(int count)
{
	char fgender[6];
	int flag = 0;
	struct student stu[100];
	int i;
	printf("\n�������Ա�:");
	scanf("%s", &fgender);
	FILE *ps;
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
		exit(1);
	}
	for (i = 0; i < count; i++)
	{
		if (fread(&stu[i], sizeof(struct student), 1, ps) != 1)
		{
			if (feof(ps))
			{
				fclose(ps);  exit(1);
			}
			printf("���ļ�����");
		}
		if (strcmp(stu[i].gender, fgender) == 0)
		{
			printMessage3();
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
			printf(" %-4.6s  %-4.6s     %4.4d��%2.2d��%2.2d��   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
				stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
			flag = 1; printOneLine();
			break;
		}
	}
	printOneSpace();
	if (!flag)
		puts("����");
	fclose(ps);
}

void deletedata(int *count)
{
	data(stu_num());
	int flag = 0;
	char fid[12];
	struct student stu[10];
	int i, c;
	printf("\n������ѧ��:");
	scanf("%s", &fid);
	FILE *ps;
	if ((ps = fopen("stu.dat", "a+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
		exit(1);
	}
	for (i = 0; i < *count; i++)
	{
		fread(&stu[i], sizeof(struct student), 1, ps);
		if (strcmp(stu[i].id, fid) == 0)
		{
			printMessage3();
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
			printf(" %-4.6s  %-4.6s     %4.4d��%2.2d��%2.2d��   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
				stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
			printOneLine();
			flag = 1;
			break;
		}
	}
	fclose(ps);
	if (!flag)
		puts("\n���޴���\n");

	else
	{
		printf("ȷ��ɾ���� ��--1  ��--0\n");
		scanf("%d", &c);
		if (c == 1)
		{
			FILE *ps1;
			if ((ps1 = fopen("newstu.dat", "w+")) == NULL)
			{
				fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
				exit(1);
			}
			if ((ps = fopen("stu.dat", "r")) == NULL)
			{
				fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
				exit(1);
			}
			i = 0;
			printOneLine();
			puts("\n��ѧ����Ϣ����\n:");
			printMessage3();
			while (i < *count)
			{
				fread(&stu[i], sizeof(struct student), 1, ps);
				if (strcmp(stu[i].id, fid) != 0)
				{
					printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
					printf(" %-4.6s  %-4.6s     %4.4d��%2.2d��%2.2d��   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
						stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
					printOneLine();
					if (fwrite(&stu[i], sizeof(struct student), 1, ps1) != 1)
					{
						if (feof(ps1))
						{
							fclose(ps1);
							exit(1);
						}
						printf("д�ļ�����");
					}
				}
				i++;
			}
			fclose(ps); fclose(ps1);
			if (remove("stu.dat"))  printf("ɾ��ʧ�� \n");
			else                printf("ɾ���ɹ�\n");
			rename("newstu.dat", "stu.dat");
		}
	}
}

void correctdata(int *count)
{
	data(stu_num());
	int flag = 0;
	char fid[12];
	struct student stu[100];
	int i, c;
	printf("\n������ѧ��:");
	scanf("%s", &fid);

	FILE *ps;
	if ((ps = fopen("stu.dat", "a+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
		exit(1);
	}


	for (i = 0; i < *count; i++)
	{
		fread(&stu[i], sizeof(struct student), 1, ps);
		if (strcmp(stu[i].id, fid) == 0)
		{
			printMessage3();
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
			printf(" %-4.6s  %-4.6s     %4.4d��%2.2d��%2.2d��   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
				stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
			printOneLine();
			flag = 1;
			break;
		}
	}
	fclose(ps);
	if (!flag)
		puts("\n���޴���\n");

	else
	{
		printf("ȷ���޸ģ� ��--1  ��--0\n");
		scanf("%d", &c);
		if (c == 1)
		{
			FILE *ps1;
			if ((ps1 = fopen("newstu.dat", "w+")) == NULL)
			{
				fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
				exit(1);
			}
			if ((ps = fopen("stu.dat", "r")) == NULL)
			{
				fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
				exit(1);
			}
			i = 0;
			printOneLine();
			//puts("\n��ѧ����Ϣ����\n:");
			while (i < *count)
			{
				fread(&stu[i], sizeof(struct student), 1, ps);
				if (strcmp(stu[i].id, fid) != 0)
				{
					if (fwrite(&stu[i], sizeof(struct student), 1, ps1) != 1)
					{
						if (feof(ps1))
						{
							fclose(ps1);
							exit(1);
						}
						printf("д�ļ�����");
					}
				}
				else if (strcmp(stu[i].id, fid) == 0)
				{
					*stu[i].id = *fid;
					puts("\n����������Ϣ:");
					puts("\n����������");
					scanf("%s", stu[i].name);
					while (1)
					{
						puts("\n�������Ա� (��/Ů) ");
						scanf("%s", stu[i].gender);
						if ((strcmp(stu[i].gender, "��") == 0) || (strcmp(stu[i].gender, "Ů") == 0))
						{
							break;
						}
						else
						{
							printf("\n������������������\n");
						}
					}
					puts("\n��������ϵ�绰");
					scanf("%s", stu[i].tel);
					puts("\n����������");
					scanf("%s", stu[i].dorm);
					puts("\n�����뷿��");
					scanf("%s", stu[i].room);
					puts("\n�������������:��-��-��");
					scanf("%d", &stu[i].birth.year);
					scanf("%d", &stu[i].birth.month);
					scanf("%d", &stu[i].birth.day);
					puts("\n��������Ƴɼ�:");
					puts("  \n�����������Ƴɼ�");
					scanf("%f", &stu[i].score.pas);
					puts("  \n��������ѧ�ɼ�");
					scanf("%f", &stu[i].score.math);
					puts("  \n������Ӣ��ɼ�");
					scanf("%f", &stu[i].score.eng);
					fwrite(&stu[i], sizeof(struct student), 1, ps1);
				}
				i++;
			}
			fclose(ps); fclose(ps1);

			if (remove("stu.dat"))  printf("�޸�ʧ�� \n");
			else                printf("�޸ĳɹ�\n");
			rename("newstu.dat", "stu.dat");
		}
	}
}

void sort(int count, int s)
{
	system("cls");
	printOneSpace();
	struct student stu[100], tem_stu;
	int i;
	FILE *ps;
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
		exit(1);
	}
	for (i = 0; i < count; i++)
		fread(&stu[i], sizeof(struct student), 1, ps);
	fclose(ps);
	switch (s)
	{
		case 1:for (int k = 0; k < count - 1; k++)
			for (i = 0; i < count - k; i++)
			{
				if (stu[i].score.pas<stu[i + 1].score.pas)
				{
					tem_stu = stu[i];
					stu[i] = stu[i + 1];
					stu[i + 1] = tem_stu;
				}
				if (stu[i].score.pas == stu[i + 1].score.pas)
				if (strcmp(stu[i].id, stu[i + 1].id)>0)
				{
					tem_stu = stu[i];
					stu[i] = stu[i + 1];
					stu[i + 1] = tem_stu;
				}
			}
			break;
		case 2:for (int k = 0; k < count - 1; k++)
			for (i = 0; i < count - k; i++)
			{
				if (stu[i].score.math<stu[i + 1].score.math)
				{
					tem_stu = stu[i];
					stu[i] = stu[i + 1];
					stu[i + 1] = tem_stu;
				}
				if (stu[i].score.math == stu[i + 1].score.math)
				if (strcmp(stu[i].id, stu[i + 1].id)>0)
				{
					tem_stu = stu[i];
					stu[i] = stu[i + 1];
					stu[i + 1] = tem_stu;
				}
			}
			break;
		case 3:for (int k = 0; k < count - 1; k++)
			for (i = 0; i < count - k; i++)
			{
				if (stu[i].score.eng<stu[i + 1].score.eng)
				{
					tem_stu = stu[i];
					stu[i] = stu[i + 1];
					stu[i + 1] = tem_stu;
				}
				if (stu[i].score.eng == stu[i + 1].score.eng)
				if (strcmp(stu[i].id, stu[i + 1].id)>0)
				{
					tem_stu = stu[i];
					stu[i] = stu[i + 1];
					stu[i + 1] = tem_stu;
				}
			}
			break;
		default:puts("��������");
	}
	printMessage3();
	for (i = 0; i < count; i++)
	{
		printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
		printf(" %-4.6s  %-4.6s     %4.4d��%2.2d��%2.2d��   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
			stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
		printOneLine();
	}
}

void sortid(int count)
{
	FILE *ps, *ps1;
	int i, k;
	struct student stu[100], tem_stu;
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
		exit(1);
	}
	if ((ps1 = fopen("newstu.dat", "w+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
		exit(1);
	}

	for (i = 0; i < count; i++)
	if (fread(&stu[i], sizeof(struct student), 1, ps) != 1)
	{
		if (feof(ps))
		{
			fclose(ps);  exit(1);
		}
		printf("���ļ�����");
	}

	for (k = 0; k < count - 1; k++)
	for (i = 0; i<count - k - 1; i++)
	if (strcmp(stu[i].id, stu[i + 1].id)>0)
	{
		tem_stu = stu[i];
		stu[i] = stu[i + 1];
		stu[i + 1] = tem_stu;
	}
	i = 0;
	while (i < count)
	{
		if (fwrite(&stu[i], sizeof(struct student), 1, ps1) != 1)
		{
			if (feof(ps1))
			{
				fclose(ps1);
				exit(1);
			}
			printf("д�ļ�����");
		}

		i++;
	}

	fclose(ps);
	fclose(ps1);
	if (remove("stu.dat") == 0)  printf("��ѧ������ \n");
	else             printf("ʧ��");
	rename("newstu.dat", "stu.dat");

}

void sortname(int count)
{
	FILE *ps, *ps1;
	int i, k;
	struct student stu[100], tem_stu;
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
		exit(1);
	}
	if ((ps1 = fopen("newstu.dat", "w+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�\n", stderr);
		exit(1);
	}

	for (i = 0; i < count; i++)
	if (fread(&stu[i], sizeof(struct student), 1, ps) != 1)
	{
		if (feof(ps))
		{
			fclose(ps);  exit(1);
		}
		printf("���ļ�����");
	}

	for (k = 0; k < count - 1; k++)
	for (i = 0; i<count - k - 1; i++)
	if (strcmp(stu[i].name, stu[i + 1].name)>0)
	{
		tem_stu = stu[i];
		stu[i] = stu[i + 1];
		stu[i + 1] = tem_stu;
	}
	i = 0;
	while (i < count)
	{
		if (fwrite(&stu[i], sizeof(struct student), 1, ps1) != 1)
		{
			if (feof(ps1))
			{
				fclose(ps1);
				exit(1);
			}
			printf("д�ļ�����");
		}

		i++;
	}

	fclose(ps);
	fclose(ps1);
	if (remove("stu.dat"))   printf("ʧ��");
	else             printf("��ѧ������ \n");
	rename("newstu.dat", "stu.dat");

}

void add()
{
	int count = 0;
	char judge[2];
	struct student stu[100];
	int index = 1, filecount;
	FILE *ps;
	int size = sizeof(struct student);
	if ((ps = fopen("stu.dat", "a+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�T_T\n", stderr);
		exit(1);
	}
	rewind(ps);
	while (count < 100 && fread(&stu[count], size, 1, ps) == 1)
	{
		if (count == 0)
		{
			puts("--��ǰѧ����Ϣ");
			puts("");

			printMessage3();

		}
		printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", index++, stu[count].id, stu[count].name, stu[count].gender, stu[count].tel);
		printf(" %-4.6s  %-4.6s     %4.4d��%2.2d��%2.2d��   %-5.1f   %-5.1f   %-5.1f\n", stu[count].dorm, stu[count].room, stu[count].birth.year, stu[count].birth.month,
			stu[count].birth.day, stu[count].score.pas, stu[count].score.math, stu[count].score.eng);
		printOneLine();
		count++;
	}

	filecount = count;
	if (count == 100)
	{
		fputs("��Ǹ!ѧ����Ϣ�ļ��Ѿ�����", stderr);
		exit(2);
	}
	printf("--��ǰ��ѧ����Ϊ %d\n", count);
	printOneSpace();
	puts("--�Ƿ�����?\n\n  *��--���س����������\n\n  *��--�밴�س���������");
	while (count < 100 && gets(judge) != NULL && judge[0] != '\0')
	{
		puts("\n������ѧ��");
		scanf("%s", stu[count].id);
		puts("\n����������");
		scanf("%s", stu[count].name);
		while (1)
		{
			puts("\n�������Ա� (��/Ů) ");
			scanf("%s", stu[count].gender);
			if ((strcmp(stu[count].gender, "��") == 0) || (strcmp(stu[count].gender, "Ů") == 0))
			{
				break;
			}
			else
			{
				printf("\n������������������\n");
			}
		}
		puts("\n��������ϵ�绰");
		scanf("%s", stu[count].tel);
		puts("\n����������");
		scanf("%s", stu[count].dorm);
		puts("\n�����뷿��");
		scanf("%s", stu[count].room);
		puts("\n�������������:��-��-��");
		scanf("%d", &stu[count].birth.year);
		scanf("%d", &stu[count].birth.month);
		scanf("%d", &stu[count].birth.day);
		puts("\n��������Ƴɼ�:");
		puts("\n�����������Ƴɼ�");
		scanf("%f", &stu[count].score.pas);
		puts("\n��������ѧ�ɼ�");
		scanf("%f", &stu[count].score.math);
		puts("\n������Ӣ��ɼ�");
		scanf("%f", &stu[count++].score.eng);
		while (getchar() != '\n')
			continue;
		if (count<100)
			puts("  *��������--���س����������\n\n  *��������--�밴�س���������:");
	}
	if (count>0)
	{
		system("cls");
		puts("��ѧ����Ϣ:");
		printMessage3();
		for (index = 0; index < count; index++)
		{
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", index + 1, stu[index].id, stu[index].name, stu[index].gender, stu[index].tel);
			printf(" %-4.6s  %-4.6s     %4.4d��%2.2d��%2.2d��   %-5.1f   %-5.1f   %-5.1f\n", stu[index].dorm, stu[index].room,
				stu[index].birth.year, stu[index].birth.month, stu[index].birth.day, stu[index].score.pas,
				stu[index].score.math, stu[index].score.eng);
			printOneLine();
		}
		fwrite(&stu[filecount], size, count - filecount, ps);
	}
	else  puts("û��ѧ����Ϣ\n");
	fclose(ps);
}

int stu_num()
{
	FILE *ps;
	int count = 0;
	if ((ps = fopen("stu.dat", "a+")) == NULL)
	{
		fputs("ѧ����Ϣ�ļ��򲻿�T_T\n", stderr);
		exit(1);
	}
	fseek(ps, 0L, SEEK_END);
	ftell(ps);
	count = ftell(ps) / sizeof(struct student); fclose(ps);
	return count;
}
