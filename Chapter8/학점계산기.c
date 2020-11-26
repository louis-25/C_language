#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void array_insert(int* student); //배열에 랜덤점수값 입력
void array_sort(int* student); //배열순서 정렬해주는 함수
void check_array(int* student); //학점체크
int main() {

	int student[100]; //학생 100명

	srand((unsigned int)time(NULL)); //time값을 초기화해서 매번 다른 난수값을 생성한다

	//함수호출
	array_insert(student);
	array_sort(student);
	check_array(student);

	return 0;
}

void array_insert(int* student) {
	for (int i = 0; i < 100; i++) {
		student[i] = rand() % 101; //0~100까지의 점수를 배열에 입력받는다
	}
}

void array_sort(int* student) {
	int i, j, temp;
	for (i = 0; i < 100; i++) {
		for (j = i; j < 100; j++) {
			if (student[i] < student[j]) {
				//뒤의 점수가 큰경우 앞으로 옮겨준다
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
		//석차를 비교하여 등급을 부여한다
		if (i < 20) grade = 'A';
		else if (i < 35) grade = 'B';
		else if (i < 60) grade = 'C';
		else if (i < 90) grade = 'D';
		else grade = 'F';

		//[영어성적 석차 등급] 순으로 출력
		printf("[%3d %3d %3c]", student[i], i + 1, grade);
		if ((i + 1) % 5 == 0) printf("\n");
	}
}