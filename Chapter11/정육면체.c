#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct{ // ��ǥ��
	int x, y, z;
}point;

typedef struct{ // �� ��
	point point1;  // ���� (point1, point2) = �밢��
	point point2;
}cube;

float cube_check(cube* p); // ���簢������ Ȯ���ϰ� �ѳ��� ���ϴ� �Լ�
int cube_line1(cube* p); // �𼭸� ���� ���ϴ� �Լ�
int cube_line2(cube* p); // �밢�� ���� ���ϴ� �Լ�
void random_point(cube* p); // ������ ����Ʈ�� �ο��ϱ�

int main()
{
	cube p = { 0 }; //����ü �ʱ�ȭ
	
	srand((unsigned int)time(NULL)); //time���� �ʱ�ȭ�ؼ� �Ź� �ٸ� ����	
	for (int i = 0; i < 20; i++) {
		random_point(&p);
		if (cube_check(&p)) { // ���簢���� ���
			printf("��1 (%d, %d, %d), ��2 (%d, %d, %d), %.2f)\n", p.point1.x, p.point1.y, p.point1.z,
				p.point2.x, p.point2.y, p.point2.z, cube_check(&p));
		}
		else {
			printf("���簢���� �ƴմϴ�\n");
		}
	}
	
	return 0;
}

float cube_check(cube* p) { // ���簢������ Ȯ���ϰ� �ѳ��� ���ϴ� �Լ�

	int x = abs(p->point1.x - p->point2.x);
	int y = abs(p->point1.y - p->point2.y);
	int z = abs(p->point1.z - p->point2.z);
	int line = 0; //�𼭸� ����
	int D = 0; //�밢�� ����
	int result = 0;

	if (x == y && y == z) { // �� ���� ���̰� ������ (���簢��)
		line = cube_line1(p); // �𼭸� ���� ���ϱ�
		result = 6 * line * line; // ���簢���� �ѳ���
		return result;
	}
	else // ���簢���� �ƴϸ� 0 ��ȯ
		return 0;
}

int cube_line1(cube* p) { // �𼭸� ���� ���ϴ� �Լ�

	int line = 0; //�𼭸� ����
	int x = abs(p->point1.x - p->point2.x);
	int y = abs(p->point1.y - p->point2.y);
	int z = abs(p->point1.z - p->point2.z);

	line = sqrt((pow(x, 2) + pow(y, 2) + pow(z, 2)) / 3); // �𼭸� ���ϴ� ����

	return line;
}

int cube_line2(cube* p) { // �밢�� ���� ���ϴ� �Լ�
	int D = 0; // �밢�� ����
	int line = cube_line1(p); // �𼭸� ����
	int x = abs(p->point1.x - p->point2.x);
	int y = abs(p->point1.y - p->point2.y);
	int z = abs(p->point1.z - p->point2.z);

	D = 3 * line * line;
	D /= D;

	return D;
}

void random_point(cube* p) { // ������ ����Ʈ�� �ο��ϱ�

	p->point1.x = (rand() % 10) + 1; // 1~10 ������ ����
	p->point1.y = (rand() % 10) + 1;
	p->point1.z = (rand() % 10) + 1;
	p->point2.x = (rand() % 10) + 1;
	p->point2.y = (rand() % 10) + 1;
	p->point2.z = (rand() % 10) + 1;
}