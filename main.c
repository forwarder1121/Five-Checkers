#include <stdio.h>

#define BACKGROUND_SIZE 11

void makeBackground();
void showBackground();
void inputBackground(int isfirst, int* p_flag);


int background[BACKGROUND_SIZE][BACKGROUND_SIZE]; //0�̸� ����ִ� ĭ, 1�̸� ����ĭ, 2�̸� �İ�ĭ

int isfinish; //���� ����

int main(void) {

	printf("�ٵ� ���α׷��� �����մϴ�.\n");

	makeBackground();
	



	isfinish = 0;
	while (isfinish==0) {

		int isfirst = 1; //����

		//���ϸ��� �Է�ĭ ������ �޴´�.
		while (1) {

			int flag = 0;
			int* pointer_flag = &flag;

			//�Է��� �ùٸ������� ������ �޴´�.
			while (1) {
				showBackground();
				inputBackground(isfirst, pointer_flag);
				if (flag == 1) { //�Է��� �ùٸ�
					if (isfirst == 1) isfirst = 2;
					else if (isfirst == 2) isfirst = 1;
					printf("\n\n���� ��\n\n"); 
					break;
				} 
				
				
			}
			



		}


		

	}





	return 0;
}


// (BACKGROUND_SIZE)*(BACKGROUND_SIZE) ũ���� �ٵ����� �����.
void makeBackground() {

	for (int i = 0; i < BACKGROUND_SIZE; i++) {
		for (int j = 0; j < BACKGROUND_SIZE; j++) {
			background[i][j] = 0;
		}
	}
	for (int i = 0; i < BACKGROUND_SIZE; i++) {
		background[0][i] = i;
	}
	for (int i = 0; i < BACKGROUND_SIZE; i++) {
		background[i][0] = i;
	}

}

//������ �迭�� ����Ѵ�. 
void showBackground() {

	for (int i = 0; i < BACKGROUND_SIZE; i++) {
		for (int j = 0; j < BACKGROUND_SIZE; j++) {
			if (i == 0) {
				printf("%d \t", background[i][j]);
			}
			else if (j == 0) {
				printf("%d \t", background[i][j]);
			}
			else if (background[i][j] == 0) {
				printf(" \t");
			}
			else if (background[i][j] == 1) {
				printf("�� \t");
			}
			else if (background[i][j] == 2) {
				printf("�� \t");
			}
		}
		printf("\n");
	}
}

//�Է°��� �ް�, ����ִ� ĭ���� Ȯ���Ѵ�. (����1/�İ�2)�� �Ű���
void inputBackground(int isfirst, int* p_flag) {
	int object_x, object_y;
	if (isfirst == 1) {
		printf("���� (1��)�� �����Դϴ�.\n");
	}
	else if(isfirst==2){
		printf("�İ� (2��)�� �����Դϴ�.\n");
	}
	printf("������� ( ? , ? )�� ��ġ\n");
	scanf("%d %d", &object_x, &object_y);
	if (background[object_x][object_y] == 0) {
		background[object_x][object_y] = isfirst;
		*p_flag = 1;
	}
	else {
		printf("�̹� �ٵ����� �ֽ��ϴ�.\n");
		p_flag = 0;
	}
}