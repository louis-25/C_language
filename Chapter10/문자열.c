#include <stdio.h>
#include <string.h>

int arr_check(char* str); //������ ��������
int arr_check2(char* str); //Ž������ ��������

int main()
{
	char str[100]; //���ڿ� ����迭   
	int i = 0;
	int count = 0; //���ڿ� ��������

	printf("���ڿ��� �Է��Ͻÿ� : ");
	gets(str); //���ڿ� �Է¹ޱ�

	count = arr_check(str);
	printf("���ڿ� ���� ���� : %d��\n", count);
	printf("Ž������ : ");
	count = arr_check2(str);
	printf("Ž������ ���� : %d��\n", count);

	return 0;
}

int arr_check(char* str) {
	int i = 0;
	int count = 0;
	while (str[i] != 0) {
		//���ڿ��� ������ ������ ������ ������ ���� �ʴ´�
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
	char word; //Ž������ ���庯��
	word = getchar(); //Ž���� �����Է¹ޱ�
	count = 0;

	for (i = 0; i < strlen(str); i++) { //Ư�����ڰ� ���ڿ��� �ִ��� �˻�
		if (str[i] == word)
			count++;
	}
	return count;
}