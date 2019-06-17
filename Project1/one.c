#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

int score = 0, a = 3;
int pan[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 1, 2, 1},
	{1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 1, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 2, 0, 0, 1},
	{1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
	{1, 2, 1, 0, 0, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
};
void print_maze() {
	system("cls");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", pan[i][j]);
		}
		printf("\n");
	}
	printf("���� : %d", score);
}
void clear() {
	system("cls");
	printf("%s", "�����մϴ�! ������ �����ϴ�!");
	a = 4;
}

void process(int* a) {
	if (*a == 2) {
		score++;
	}
	*a = 9;
}

int main()
{	
	int x = 1, y = 1, z;
	int key;
	while(a < 4) {
		printf("%s", "�־��� ������ ������ �����Ͻ÷��� 1��, ������ ���� �Է��Ͻ÷��� 2�� �Է����ּ���. : \n");
		scanf_s("%d", &z);
		if (z == 1) {
			break;
		}
		else if (z == 2 ) {
			printf("%s", "10*10 ������ �Է��ϼ��� : \n");
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					scanf_s("%d", &pan[i][j]);
				}
			}
			break;
		}
		else {
			printf("%s", "��ȿ���� ���� �Է°��Դϴ�.\n");
		}
	}
	
	pan[x][y] = 9;
	print_maze();
	
	while (a < 4) {
		if (_kbhit()) {
			key = _getch();
			if (key == 224 || key == 0) {
				key = _getch();
				switch (key) {
				case 72: // ��
					if (x-1 >= 0 && pan[x - 1][y] == 1) break;
					if (x == 0) { clear(); break; }
					pan[x][y] = 0;
					process(&pan[x - 1][y]);
					x--;
					print_maze();
					break;
				case 75: // ����
					if (y-1 >= 0 && pan[x][y - 1] == 1) break;
					if (y == 0) { clear(); break; }
					pan[x][y] = 0;
					process(&pan[x][y - 1]);
					y--;
					print_maze();
					break;
				case 77: // ������
					if (y+1 <= 9 && pan[x][y + 1] == 1) break;
					if (y == 9) { clear(); break; }
					pan[x][y] = 0;
					process(&pan[x][y + 1]);
					y++;
					print_maze();
					break;
				case 80: // �Ʒ�
					if (x+1 <= 9 && pan[x+1][y] == 1) break;
					if (x == 9) { clear(); break; }
					pan[x][y] = 0;
					process(&pan[x + 1][y]);
					x++;
					print_maze();
					break;
				}
			}

		}

	}
}