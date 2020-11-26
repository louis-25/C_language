#include <stdio.h>
#include <string.h>

int arr_check(char* str); //문자의 개수세기
int arr_check2(char* str); //탐색문자 개수세기

int main()
{
	char str[100]; //문자열 저장배열   
	int i = 0;
	int count = 0; //문자열 개수세기

	printf("문자열을 입력하시오 : ");
	gets(str); //문자열 입력받기

	count = arr_check(str);
	printf("문자열 문자 개수 : %d개\n", count);
	printf("탐색문자 : ");
	count = arr_check2(str);
	printf("탐색문자 개수 : %d개\n", count);

	return 0;
}

int arr_check(char* str) {
	int i = 0;
	int count = 0;
	while (str[i] != 0) {
		//문자열에 공백이 있으면 문자의 개수로 세지 않는다
		if (str[i] == ' ') {
			count--;
		}
		count++;
		i++;
	}
	return count;
}

int arr_check2(char* str) {
	int i = 0;
	int count = 0;
	char word; //탐색문자 저장변수
	word = getchar(); //탐색할 문자입력받기
	count = 0;

	for (i = 0; i < strlen(str); i++) { //특정문자가 문자열에 있는지 검사
		if (str[i] == word)
			count++;
	}
	return count;
}