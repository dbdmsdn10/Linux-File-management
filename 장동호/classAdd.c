#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char fname[200];

	printf("수업이름과 분반을 입력하세요 ex)리눅스운영체제-1.txt\n");
	scanf_s("%s", fname, sizeof(fname));

	char strPeriod[200];
	printf("수업 시작일을 입력하세요 ex)20200302\n");
	scanf_s("%s", strPeriod, sizeof(strPeriod));

	char endPeriod[200];
	printf("수업 종료일을 입력하세요 ex)20200615\n");
	scanf_s("%s", endPeriod, sizeof(endPeriod));

	char week[200];
	printf("수업이 있는 요일을 입력하세요 ex)월\n");
	scanf_s("%s", week, sizeof(week));

	char classTime[200];
	printf("수업이 있는 교시를 입력하세요 ex)3\n");
	scanf_s("%s", classTime, sizeof(classTime));

	FILE* fp;



	//쓰기 모드로 파일을 열면 파일의 내용은 사라집니다.

	//만약 파일이 없으면 새로 생성합니다.

	//fp = fopen(fname,"w")과 fopen_s(&fp,fname,"w")는 같은 기능 수행

	fopen_s(&fp, fname, "w");//파일 쓰기 모드로 열기



	if (fp == NULL)

	{

		perror("파일 열기 실패");//에러 출력

		exit(0); //프로그램 종료

	}



	fprintf(fp, "시작일:%s\n종료일:%s\n수업요일:%s\n수업교시:%s\n", strPeriod, endPeriod, week, classTime);

	fclose(fp);



	printf("%s 파일의 내용\n", fname);

	return 0;

}