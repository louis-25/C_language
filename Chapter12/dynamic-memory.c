#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char* dynamic_char(char* arr); // �����Ҵ�
void print_text(char* arr[]); // �迭�� ���

int main() {
	char* sample[11] = { NULL };
	char arr[200] = { 0 };
	char* line = malloc(sizeof(char) * 200);
	int i = 0;
	FILE* in = fopen("sample.txt", "r");
	
	if (in == NULL) {
		printf("���Ͽ��� ����\n");
		return 0;
	}

	while (!feof(in)) { // ������ ���������� �ݺ�
		sample[i] = dynamic_char(sample[i]);  // �����Ҵ�
		//sample[i] = (char*)malloc(sizeof(sample[i]) * 200);
		line = fgets(arr, 200, in);  // ���� ���پ��б�		
		strcpy(sample[i], line); //���ڿ� ����		
		i++;
	}
	
	print_text(sample); // �迭�� ���		
	
	// �޸𸮹�ȯ	
	for (int i = 0; i < 11; i++) {
		free(sample[i]);
	}
	line = NULL;
	free(line);	

	fclose(in); // ���ϴݱ�
	
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