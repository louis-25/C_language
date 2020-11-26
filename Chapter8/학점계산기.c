#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void array_insert(int* student); //�迭�� ���������� �Է�
void array_sort(int* student); //�迭���� �������ִ� �Լ�
void check_array(int* student); //����üũ
int main() {

	int student[100]; //�л� 100��

	srand((unsigned int)time(NULL)); //time���� �ʱ�ȭ�ؼ� �Ź� �ٸ� �������� �����Ѵ�

	//�Լ�ȣ��
	array_insert(student);
	array_sort(student);
	check_array(student);

	return 0;
}

void array_insert(int* student) {
	for (int i = 0; i < 100; i++) {
		student[i] = rand() % 101; //0~100������ ������ �迭�� �Է¹޴´�
	}
}

void array_sort(int* student) {
	int i, j, temp;
	for (i = 0; i < 100; i++) {
		for (j = i; j < 100; j++) {
			if (student[i] < student[j]) {
				//���� ������ ū��� ������ �Ű��ش�
				temp = student[i];
				student[i] = student[j];
				student[j] = temp;
			}
		}
	}
}

void check_array(int* student) {
	char grade;
	for (int i = 0; i < 100; i++) {
		//������ ���Ͽ� ����� �ο��Ѵ�
		if (i < 20) grade = 'A';
		else if (i < 35) grade = 'B';
		else if (i < 60) grade = 'C';
		else if (i < 90) grade = 'D';
		else grade = 'F';

		//[����� ���� ���] ������ ���
		printf("[%3d %3d %3c]", student[i], i + 1, grade);
		if ((i + 1) % 5 == 0) printf("\n");
	}
}