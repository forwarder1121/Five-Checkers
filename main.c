#include <stdio.h>

#define BACKGROUND_SIZE 11

void makeBackground();
void showBackground();
void inputBackground(int isfirst, int* p_flag);


int background[BACKGROUND_SIZE][BACKGROUND_SIZE]; //0이면 비어있는 칸, 1이면 선공칸, 2이면 후공칸

int isfinish; //게임 종료

int main(void) {

	printf("바둑 프로그램을 실행합니다.\n");

	makeBackground();
	



	isfinish = 0;
	while (isfinish==0) {

		int isfirst = 1; //선공

		//매턴마다 입력칸 정보를 받는다.
		while (1) {

			int flag = 0;
			int* pointer_flag = &flag;

			//입력이 올바를때까지 정보를 받는다.
			while (1) {
				showBackground();
				inputBackground(isfirst, pointer_flag);
				if (flag == 1) { //입력이 올바름
					if (isfirst == 1) isfirst = 2;
					else if (isfirst == 2) isfirst = 1;
					printf("\n\n다음 턴\n\n"); 
					break;
				} 
				
				
			}
			



		}


		

	}





	return 0;
}


// (BACKGROUND_SIZE)*(BACKGROUND_SIZE) 크기의 바둑판을 만든다.
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

//이차원 배열을 출력한다. 
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
				printf("● \t");
			}
			else if (background[i][j] == 2) {
				printf("○ \t");
			}
		}
		printf("\n");
	}
}

//입력값을 받고, 비어있는 칸인지 확인한다. (선공1/후공2)은 매개값
void inputBackground(int isfirst, int* p_flag) {
	int object_x, object_y;
	if (isfirst == 1) {
		printf("선공 (1번)님 차례입니다.\n");
	}
	else if(isfirst==2){
		printf("후공 (2번)님 차례입니다.\n");
	}
	printf("오목알을 ( ? , ? )에 배치\n");
	scanf("%d %d", &object_x, &object_y);
	if (background[object_x][object_y] == 0) {
		background[object_x][object_y] = isfirst;
		*p_flag = 1;
	}
	else {
		printf("이미 바둑판이 있습니다.\n");
		p_flag = 0;
	}
}