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
	printf("\n请输入你的选择\n");
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
	printf("(当前学生人数为%d)\n", t);
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
	printf("\t\t\t1.程设\t\t2.数学\t\t3.英语\n");
	printOneSpace();
	printSpacesAndLines(24, 38);
	printf("\n请输入你的选择\n");
	scanf("%d", &sc);
	sort(stu_num(), sc);
	printMessage2();
	printf("\n请输入你的选择\n");
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
		printf("(当前学生人数为%d)\n", t);
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
				printf("输入有误，请重新输入：");
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
	printf("\t\t\t\t 1.按姓名查询\t\t    2.按学号查询\n");
	printOneSpace();
	printf("\t\t\t\t 3.按宿舍查询\t\t    4.按性别查询\n");
	printOneSpace();
	printf("\t\t\t\t 5.退回主页面\n");
	printOneSpace();
	printSpacesAndLines(33, 40);
}

void printMessage2()
{
	printf("\n     1.返回主页面\n\n     2.返回上一步\n\n     3.退出使用\n");
}

void printMessage3()
{
	printOneLine();
	printf("序号   学号 \t   姓名    性别       联系电话     宿舍与房号       出生日期         程设    数学    英语\n");
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
	printf("  \t\t\t\t\t\t学籍管理系统\n");
	printOneSpace(); printStars();
	printOneSpace();
	printf("  \t\t\t\t 1.添加学生信息\t\t    2.删除学生信息\n");
	printOneSpace();
	printf("  \t\t\t\t 3.修改学生信息\t\t    4.查询学生信息\n");
	printOneSpace();
	printf("  \t\t\t\t 5.学生成绩排序\t\t    6.打印学籍信息\n");
	printOneSpace();
	printf("  \t\t\t\t 7.退出使用\n");
}

void exitProgram()
{
	printf("谢谢使用");
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
		fputs("学生信息文件打不开\n", stderr);
		exit(1);
	}
	printMessage3();
	for (int i = 0; i < count; i++)
	{
		fread(&stu[i], sizeof(struct student), 1, ps);
		printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
		printf(" %-4.6s  %-4.6s     %4.4d年%2.2d月%2.2d日   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
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
	printf("\n请输入名字:");
	scanf("%s", &fname);
	FILE *ps;
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("学生信息文件打不开\n", stderr);
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
			printf("读文件错误");
		}
		if (strcmp(stu[i].name, fname) == 0)
		{
			printMessage3();
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
			printf(" %-4.6s  %-4.6s     %4.4d年%2.2d月%2.2d日   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
				stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
			printOneLine();
			flag = 1;
			break;
		}
	}
	printOneSpace();
	if (!flag)  puts("查无此人");

	fclose(ps);
}

void findById(int count)
{
	char fid[15];
	int flag = 0;
	struct student stu[100];
	int i;
	printf("\n请输入学号:");
	scanf("%s", &fid);
	FILE *ps;
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("学生信息文件打不开\n", stderr);
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
			printf("读文件错误");
		}
		if (strcmp(stu[i].id, fid) == 0)
		{
			printMessage3();
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
			printf(" %-4.6s  %-4.6s     %4.4d年%2.2d月%2.2d日   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
				stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
			printOneLine();
			flag = 1;
			break;
		}
	}
	printOneSpace();
	if (!flag)
		puts("查无此人");
	fclose(ps);
}

void findByDorm(int count)
{
	char fdorm[6];
	int flag = 0;
	struct student stu[100];
	int i;
	printf("\n请输入宿舍:");
	scanf("%s", &fdorm);
	FILE *ps;
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("学生信息文件打不开\n", stderr);
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
			printf("读文件错误");
		}
		if (strcmp(stu[i].dorm, fdorm) == 0)
		{
			printMessage3();
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
			printf(" %-4.6s  %-4.6s     %4.4d年%2.2d月%2.2d日   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
				stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
			flag = 1;
			printOneLine();
			break;
		}
	}
	printOneSpace();
	if (!flag)
		puts("查无此宿舍");
	fclose(ps);
}

void findByGender(int count)
{
	char fgender[6];
	int flag = 0;
	struct student stu[100];
	int i;
	printf("\n请输入性别:");
	scanf("%s", &fgender);
	FILE *ps;
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("学生信息文件打不开\n", stderr);
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
			printf("读文件错误");
		}
		if (strcmp(stu[i].gender, fgender) == 0)
		{
			printMessage3();
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
			printf(" %-4.6s  %-4.6s     %4.4d年%2.2d月%2.2d日   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
				stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
			flag = 1; printOneLine();
			break;
		}
	}
	printOneSpace();
	if (!flag)
		puts("查无");
	fclose(ps);
}

void deletedata(int *count)
{
	data(stu_num());
	int flag = 0;
	char fid[12];
	struct student stu[10];
	int i, c;
	printf("\n请输入学号:");
	scanf("%s", &fid);
	FILE *ps;
	if ((ps = fopen("stu.dat", "a+")) == NULL)
	{
		fputs("学生信息文件打不开\n", stderr);
		exit(1);
	}
	for (i = 0; i < *count; i++)
	{
		fread(&stu[i], sizeof(struct student), 1, ps);
		if (strcmp(stu[i].id, fid) == 0)
		{
			printMessage3();
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
			printf(" %-4.6s  %-4.6s     %4.4d年%2.2d月%2.2d日   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
				stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
			printOneLine();
			flag = 1;
			break;
		}
	}
	fclose(ps);
	if (!flag)
		puts("\n查无此人\n");

	else
	{
		printf("确认删除？ 是--1  否--0\n");
		scanf("%d", &c);
		if (c == 1)
		{
			FILE *ps1;
			if ((ps1 = fopen("newstu.dat", "w+")) == NULL)
			{
				fputs("学生信息文件打不开\n", stderr);
				exit(1);
			}
			if ((ps = fopen("stu.dat", "r")) == NULL)
			{
				fputs("学生信息文件打不开\n", stderr);
				exit(1);
			}
			i = 0;
			printOneLine();
			puts("\n新学生信息如下\n:");
			printMessage3();
			while (i < *count)
			{
				fread(&stu[i], sizeof(struct student), 1, ps);
				if (strcmp(stu[i].id, fid) != 0)
				{
					printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
					printf(" %-4.6s  %-4.6s     %4.4d年%2.2d月%2.2d日   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
						stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
					printOneLine();
					if (fwrite(&stu[i], sizeof(struct student), 1, ps1) != 1)
					{
						if (feof(ps1))
						{
							fclose(ps1);
							exit(1);
						}
						printf("写文件错误");
					}
				}
				i++;
			}
			fclose(ps); fclose(ps1);
			if (remove("stu.dat"))  printf("删除失败 \n");
			else                printf("删除成功\n");
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
	printf("\n请输入学号:");
	scanf("%s", &fid);

	FILE *ps;
	if ((ps = fopen("stu.dat", "a+")) == NULL)
	{
		fputs("学生信息文件打不开\n", stderr);
		exit(1);
	}


	for (i = 0; i < *count; i++)
	{
		fread(&stu[i], sizeof(struct student), 1, ps);
		if (strcmp(stu[i].id, fid) == 0)
		{
			printMessage3();
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
			printf(" %-4.6s  %-4.6s     %4.4d年%2.2d月%2.2d日   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
				stu[i].birth.day, stu[i].score.pas, stu[i].score.math, stu[i].score.eng);
			printOneLine();
			flag = 1;
			break;
		}
	}
	fclose(ps);
	if (!flag)
		puts("\n查无此人\n");

	else
	{
		printf("确认修改？ 是--1  否--0\n");
		scanf("%d", &c);
		if (c == 1)
		{
			FILE *ps1;
			if ((ps1 = fopen("newstu.dat", "w+")) == NULL)
			{
				fputs("学生信息文件打不开\n", stderr);
				exit(1);
			}
			if ((ps = fopen("stu.dat", "r")) == NULL)
			{
				fputs("学生信息文件打不开\n", stderr);
				exit(1);
			}
			i = 0;
			printOneLine();
			//puts("\n新学生信息如下\n:");
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
						printf("写文件错误");
					}
				}
				else if (strcmp(stu[i].id, fid) == 0)
				{
					*stu[i].id = *fid;
					puts("\n请输入新信息:");
					puts("\n请输入姓名");
					scanf("%s", stu[i].name);
					while (1)
					{
						puts("\n请输入性别 (男/女) ");
						scanf("%s", stu[i].gender);
						if ((strcmp(stu[i].gender, "男") == 0) || (strcmp(stu[i].gender, "女") == 0))
						{
							break;
						}
						else
						{
							printf("\n输入有误，请重新输入\n");
						}
					}
					puts("\n请输入联系电话");
					scanf("%s", stu[i].tel);
					puts("\n请输入宿舍");
					scanf("%s", stu[i].dorm);
					puts("\n请输入房间");
					scanf("%s", stu[i].room);
					puts("\n请输入出生日期:年-月-日");
					scanf("%d", &stu[i].birth.year);
					scanf("%d", &stu[i].birth.month);
					scanf("%d", &stu[i].birth.day);
					puts("\n请输入各科成绩:");
					puts("  \n请输入程序设计成绩");
					scanf("%f", &stu[i].score.pas);
					puts("  \n请输入数学成绩");
					scanf("%f", &stu[i].score.math);
					puts("  \n请输入英语成绩");
					scanf("%f", &stu[i].score.eng);
					fwrite(&stu[i], sizeof(struct student), 1, ps1);
				}
				i++;
			}
			fclose(ps); fclose(ps1);

			if (remove("stu.dat"))  printf("修改失败 \n");
			else                printf("修改成功\n");
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
		fputs("学生信息文件打不开\n", stderr);
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
		default:puts("参数错误");
	}
	printMessage3();
	for (i = 0; i < count; i++)
	{
		printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", i + 1, stu[i].id, stu[i].name, stu[i].gender, stu[i].tel);
		printf(" %-4.6s  %-4.6s     %4.4d年%2.2d月%2.2d日   %-5.1f   %-5.1f   %-5.1f\n", stu[i].dorm, stu[i].room, stu[i].birth.year, stu[i].birth.month,
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
		fputs("学生信息文件打不开\n", stderr);
		exit(1);
	}
	if ((ps1 = fopen("newstu.dat", "w+")) == NULL)
	{
		fputs("学生信息文件打不开\n", stderr);
		exit(1);
	}

	for (i = 0; i < count; i++)
	if (fread(&stu[i], sizeof(struct student), 1, ps) != 1)
	{
		if (feof(ps))
		{
			fclose(ps);  exit(1);
		}
		printf("读文件错误");
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
			printf("写文件错误");
		}

		i++;
	}

	fclose(ps);
	fclose(ps1);
	if (remove("stu.dat") == 0)  printf("按学号排序 \n");
	else             printf("失败");
	rename("newstu.dat", "stu.dat");

}

void sortname(int count)
{
	FILE *ps, *ps1;
	int i, k;
	struct student stu[100], tem_stu;
	if ((ps = fopen("stu.dat", "r+")) == NULL)
	{
		fputs("学生信息文件打不开\n", stderr);
		exit(1);
	}
	if ((ps1 = fopen("newstu.dat", "w+")) == NULL)
	{
		fputs("学生信息文件打不开\n", stderr);
		exit(1);
	}

	for (i = 0; i < count; i++)
	if (fread(&stu[i], sizeof(struct student), 1, ps) != 1)
	{
		if (feof(ps))
		{
			fclose(ps);  exit(1);
		}
		printf("读文件错误");
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
			printf("写文件错误");
		}

		i++;
	}

	fclose(ps);
	fclose(ps1);
	if (remove("stu.dat"))   printf("失败");
	else             printf("按学号排序 \n");
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
		fputs("学生信息文件打不开T_T\n", stderr);
		exit(1);
	}
	rewind(ps);
	while (count < 100 && fread(&stu[count], size, 1, ps) == 1)
	{
		if (count == 0)
		{
			puts("--当前学生信息");
			puts("");

			printMessage3();

		}
		printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", index++, stu[count].id, stu[count].name, stu[count].gender, stu[count].tel);
		printf(" %-4.6s  %-4.6s     %4.4d年%2.2d月%2.2d日   %-5.1f   %-5.1f   %-5.1f\n", stu[count].dorm, stu[count].room, stu[count].birth.year, stu[count].birth.month,
			stu[count].birth.day, stu[count].score.pas, stu[count].score.math, stu[count].score.eng);
		printOneLine();
		count++;
	}

	filecount = count;
	if (count == 100)
	{
		fputs("抱歉!学生信息文件已经满了", stderr);
		exit(2);
	}
	printf("--当前的学生数为 %d\n", count);
	printOneSpace();
	puts("--是否输入?\n\n  *是--除回车键的任意键\n\n  *否--请按回车键后输入");
	while (count < 100 && gets(judge) != NULL && judge[0] != '\0')
	{
		puts("\n请输入学号");
		scanf("%s", stu[count].id);
		puts("\n请输入姓名");
		scanf("%s", stu[count].name);
		while (1)
		{
			puts("\n请输入性别 (男/女) ");
			scanf("%s", stu[count].gender);
			if ((strcmp(stu[count].gender, "男") == 0) || (strcmp(stu[count].gender, "女") == 0))
			{
				break;
			}
			else
			{
				printf("\n输入有误，请重新输入\n");
			}
		}
		puts("\n请输入联系电话");
		scanf("%s", stu[count].tel);
		puts("\n请输入宿舍");
		scanf("%s", stu[count].dorm);
		puts("\n请输入房间");
		scanf("%s", stu[count].room);
		puts("\n请输入出生日期:年-月-日");
		scanf("%d", &stu[count].birth.year);
		scanf("%d", &stu[count].birth.month);
		scanf("%d", &stu[count].birth.day);
		puts("\n请输入各科成绩:");
		puts("\n请输入程序设计成绩");
		scanf("%f", &stu[count].score.pas);
		puts("\n请输入数学成绩");
		scanf("%f", &stu[count].score.math);
		puts("\n请输入英语成绩");
		scanf("%f", &stu[count++].score.eng);
		while (getchar() != '\n')
			continue;
		if (count<100)
			puts("  *继续输入--除回车键的任意键\n\n  *结束输入--请按回车键后输入:");
	}
	if (count>0)
	{
		system("cls");
		puts("新学生信息:");
		printMessage3();
		for (index = 0; index < count; index++)
		{
			printf(" %d  %s \t %-8.8s   %-6.6s   %-11.11s  ", index + 1, stu[index].id, stu[index].name, stu[index].gender, stu[index].tel);
			printf(" %-4.6s  %-4.6s     %4.4d年%2.2d月%2.2d日   %-5.1f   %-5.1f   %-5.1f\n", stu[index].dorm, stu[index].room,
				stu[index].birth.year, stu[index].birth.month, stu[index].birth.day, stu[index].score.pas,
				stu[index].score.math, stu[index].score.eng);
			printOneLine();
		}
		fwrite(&stu[filecount], size, count - filecount, ps);
	}
	else  puts("没有学生信息\n");
	fclose(ps);
}

int stu_num()
{
	FILE *ps;
	int count = 0;
	if ((ps = fopen("stu.dat", "a+")) == NULL)
	{
		fputs("学生信息文件打不开T_T\n", stderr);
		exit(1);
	}
	fseek(ps, 0L, SEEK_END);
	ftell(ps);
	count = ftell(ps) / sizeof(struct student); fclose(ps);
	return count;
}
