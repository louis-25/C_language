#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct{ // 좌표값
	int x, y, z;
}point;

typedef struct{ // 두 점
	point point1;  // 선분 (point1, point2) = 대각선
	point point2;
}cube;

float cube_check(cube* p); // 정사각형인지 확인하고 겉넓이 구하는 함수
int cube_line1(cube* p); // 모서리 길이 구하는 함수
int cube_line2(cube* p); // 대각선 길이 구하는 함수
void random_point(cube* p); // 임의의 포인트값 부여하기

int main()
{
	cube p = { 0 }; //구조체 초기화
	
	srand((unsigned int)time(NULL)); //time값을 초기화해서 매번 다른 난수	
	for (int i = 0; i < 20; i++) {
		random_point(&p);
		if (cube_check(&p)) { // 정사각형인 경우
			printf("점1 (%d, %d, %d), 점2 (%d, %d, %d), %.2f)\n", p.point1.x, p.point1.y, p.point1.z,
				p.point2.x, p.point2.y, p.point2.z, cube_check(&p));
		}
		else {
			printf("정사각형이 아닙니다\n");
		}
	}
	
	return 0;
}

float cube_check(cube* p) { // 정사각형인지 확인하고 겉넓이 구하는 함수

	int x = abs(p->point1.x - p->point2.x);
	int y = abs(p->point1.y - p->point2.y);
	int z = abs(p->point1.z - p->point2.z);
	int line = 0; //모서리 길이
	int D = 0; //대각선 길이
	int result = 0;

	if (x == y && y == z) { // 세 변의 길이가 같을때 (정사각형)
		line = cube_line1(p); // 모서리 길이 구하기
		result = 6 * line * line; // 정사각형의 겉넓이
		return result;
	}
	else // 정사각형이 아니면 0 반환
		return 0;
}

int cube_line1(cube* p) { // 모서리 길이 구하는 함수

	int line = 0; //모서리 길이
	int x = abs(p->point1.x - p->point2.x);
	int y = abs(p->point1.y - p->point2.y);
	int z = abs(p->point1.z - p->point2.z);

	line = sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)) / 3); // 모서리 구하는 공식

	return line;
}

int cube_line2(cube* p) { // 대각선 길이 구하는 함수
	int D = 0; // 대각선 길이
	int line = cube_line1(p); // 모서리 길이
	int x = abs(p->point1.x - p->point2.x);
	int y = abs(p->point1.y - p->point2.y);
	int z = abs(p->point1.z - p->point2.z);

	D = 3 * line * line;
	D /= D;

	return D;
}

void random_point(cube* p) { // 임의의 포인트값 부여하기

	p->point1.x = (rand() % 10) + 1; // 1~10 까지의 정수
	p->point1.y = (rand() % 10) + 1;
	p->point1.z = (rand() % 10) + 1;
	p->point2.x = (rand() % 10) + 1;
	p->point2.y = (rand() % 10) + 1;
	p->point2.z = (rand() % 10) + 1;
}