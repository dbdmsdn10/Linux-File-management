#include <stdio.h>
#include <stdlib.h>

void ReadAndPrint(const char* fname);

int main(void)
{

	char fname[200];

	printf("���� �̸�: ");
	//������ ������ ���� �̸� �Է��� �� gets_s(fname,sizeof(fname));

	scanf_s("%s", fname, sizeof(fname));

	ReadAndPrint(fname);

	return 0;
}


void ReadAndPrint(const char* fname)
{
	FILE* fp;

	//fp = fopen(fname,"r")�� fopen_s(&fp,fname,"r")�� ���� ��� ����

	fopen_s(&fp, fname, "r");//�б� ���� ���� ����

	if (fp == NULL)
	{

		perror("���� ���� ����");//���� ���
		exit(0); //���α׷� ����

	}

	while (!feof(fp))//������ ���� ������ �ʾҴٸ� �ݺ�
	{
		printf("%c", fgetc(fp));//�ϳ��� ���ڸ� �о�ͼ� �ܼ� ȭ�鿡 ���
	}

	fclose(fp);//���� ��Ʈ�� �ݱ�


	printf("\n==%s ����==\n", fname);

}