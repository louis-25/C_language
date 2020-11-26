#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void min_ave(int* arr, int* min, int* avg);
int main() {

	int arr[100]; //배열
	int min = 100;
	int avg = 0;

	srand((unsigned int)time(NULL)); //time값을 초기화해서 매번 다른 난수값을 생성한다

	//함수호출
	min_ave(arr, &min, &avg);

	printf("배열의 평균 = %d\n배열의 최솟값 = %d", avg, min);

	return 0;
}

void min_ave(int* arr, int* min, int* avg) {
	int i, j, temp;

	for (i = 0; i < 100; i++) {
		arr[i] = rand() % 101; //0~100까지의 정수를 배열에 입력받는다      
	}

	//배열값 정렬
	for (i = 0; i < 100; i++) {
		for (j = i; j < 100; j++) {
			if (arr[i] < arr[j]) {
				//뒤의 점수가 큰경우 앞으로 옮겨준다
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		*avg += arr[i];
		if (arr[i] < min) *min = arr[i]; //배열의 최솟값을 min에 저장
		printf("%d\n", arr[i]);
	}
	*avg /= 100; //배열의 평균값
}