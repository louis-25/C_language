#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void min_ave(int* arr, int* min, int* avg);
int main() {

	int arr[100]; //�迭
	int min = 100;
	int avg = 0;

	srand((unsigned int)time(NULL)); //time���� �ʱ�ȭ�ؼ� �Ź� �ٸ� �������� �����Ѵ�

	//�Լ�ȣ��
	min_ave(arr, &min, &avg);

	printf("�迭�� ��� = %d\n�迭�� �ּڰ� = %d", avg, min);

	return 0;
}

void min_ave(int* arr, int* min, int* avg) {
	int i, j, temp;

	for (i = 0; i < 100; i++) {
		arr[i] = rand() % 101; //0~100������ ������ �迭�� �Է¹޴´�      
	}

	//�迭�� ����
	for (i = 0; i < 100; i++) {
		for (j = i; j < 100; j++) {
			if (arr[i] < arr[j]) {
				//���� ������ ū��� ������ �Ű��ش�
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		*avg += arr[i];
		if (arr[i] < min) *min = arr[i]; //�迭�� �ּڰ��� min�� ����
		printf("%d\n", arr[i]);
	}
	*avg /= 100; //�迭�� ��հ�
}