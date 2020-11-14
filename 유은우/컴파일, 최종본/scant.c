void scant()
{
    char s1[30];
    printf("이름을 입력하시오: ");
    scanf(" %[^\n]",s1);
    char s2[30];
    printf("학번을 입력하시오: ");
    scanf(" %[^\n]",s2);
    if(search("",s2)>=0){
		printf("이미 존재합니다");
		}
		else {
    addlist(s1,s2);
    Addstudent(s2);
	}
}
