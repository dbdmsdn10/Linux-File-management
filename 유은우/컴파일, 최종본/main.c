#include <stdio.h>


int main()
{
	
	int a=0;
	while(a>=0){
			printf("무엇을 하시겠습니까?\n 1. 학생조회\n 2. 학생 추가\n 3. 학생 삭제\n 4. 학생 선택\n ");
			printf("-1은 돌아가기입니다\n");
			printf("숫자로 입력해주세요>> ");
			
			if(1!=scanf("%d",&a)){
				printf("숫자가 아니거나 오류가났습니다");
				a=0;
				}
			else if(a==1){
				listread();
				}
			else if(a==2){
				scant();
				}
			else if(a==3){
				remove2("");
				}
		}
       
}
