#include<stdio.h>
void returndate(int date[6],int when[6][12],char *argv);
void Addstudent(char *argv) {
        int date[6] = { -1, };// startyear, startmonth, startday,endyear, endmonth, endday;
        int a = 1;//bool대신'
        int when[6][12] = { -1, };
        printf("%s\n",argv);
        printf("시작연도 \n");
        scanf("%d", &date[0]);
        printf("시작월 \n");
        scanf("%d", &date[1]);
        printf("시작날짜 \n");
        scanf("%d", &date[2]);
        printf("끝나는 연도 \n");
        scanf("%d", &date[3]);
        printf("끝나는 월 \n");
        scanf("%d", &date[4]);
        printf("끝나는 날짜 \n");
        scanf("%d", &date[5]);
        for (int i = 0; i < 6; i++) {
                if (date[i] < 0) {
                        a = -1;
                        printf("잘못입력된게 있습니다 \n");
                }
        }
        int i = 0;
        while (a && i < 6)
        {
                int j = 1;
                printf("요일 0=일요일 1=월요일..6=토요일  -1일시 그만입력 \n");
                scanf("%d", &when[i][0]);
                if (when[i][0] == -1) {
					printf("for confrim \n");
                        break;
                }
                while (j < 12) {
                        printf("교시 \n");
                        scanf("%d", &when[i][j]);
                        if (when[i][j] == -1) {
                                break;
                        }
                        j++;
                }
                i++;
        }
        
        returndate(date,when,argv);
}
