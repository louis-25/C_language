#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char* dynamic_char(char* arr); // 동적할당
void print_text(char* arr[]); // 배열값 출력

int main() {
	char* sample[11] = { NULL };
	char arr[200] = { 0 };
	char* line = malloc(sizeof(char) * 200);
	int i = 0;
	FILE* in = fopen("sample.txt", "r");
	
	if (in == NULL) {
		printf("파일열기 실패\n");
		return 0;
	}

	while (!feof(in)) { // 파일이 끝날때까지 반복
		sample[i] = dynamic_char(sample[i]);  // 동적할당
		//sample[i] = (char*)malloc(sizeof(sample[i]) * 200);
		line = fgets(arr, 200, in);  // 파일 한줄씩읽기		
		strcpy(sample[i], line); //문자열 복사		
		i++;
	}
	
	print_text(sample); // 배열값 출력		
	
	// 메모리반환	
	for (int i = 0; i < 11; i++) {
		free(sample[i]);
	}
	line = NULL;
	free(line);	

	fclose(in); // 파일닫기
	
	return 0;
}

char* dynamic_char(char* arr) {
	arr = (char*)malloc(sizeof(arr) * 200);
	return arr;
}

void print_text(char* arr[]) {
	for (int i = 0; i < 11; i++) {
		printf("%s", arr[i]);
	}
}