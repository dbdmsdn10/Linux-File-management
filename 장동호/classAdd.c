#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char fname[200];

	printf("�����̸��� �й��� �Է��ϼ��� ex)�������ü��-1.txt\n");
	scanf_s("%s", fname, sizeof(fname));

	char strPeriod[200];
	printf("���� �������� �Է��ϼ��� ex)20200302\n");
	scanf_s("%s", strPeriod, sizeof(strPeriod));

	char endPeriod[200];
	printf("���� �������� �Է��ϼ��� ex)20200615\n");
	scanf_s("%s", endPeriod, sizeof(endPeriod));

	char week[200];
	printf("������ �ִ� ������ �Է��ϼ��� ex)��\n");
	scanf_s("%s", week, sizeof(week));

	char classTime[200];
	printf("������ �ִ� ���ø� �Է��ϼ��� ex)3\n");
	scanf_s("%s", classTime, sizeof(classTime));

	FILE* fp;



	//���� ���� ������ ���� ������ ������ ������ϴ�.

	//���� ������ ������ ���� �����մϴ�.

	//fp = fopen(fname,"w")�� fopen_s(&fp,fname,"w")�� ���� ��� ����

	fopen_s(&fp, fname, "w");//���� ���� ���� ����



	if (fp == NULL)

	{

		perror("���� ���� ����");//���� ���

		exit(0); //���α׷� ����

	}



	fprintf(fp, "������:%s\n������:%s\n��������:%s\n��������:%s\n", strPeriod, endPeriod, week, classTime);

	fclose(fp);



	printf("%s ������ ����\n", fname);

	return 0;

}