#include <stdio.h>

#define BACKGROUND_SIZE 11

int** makeBackground();
void showBackground(int** background);

int main(void) {
	
	int** background;
	printf("바둑 프로그램을 실행합니다.\n");

	background = makeBackground();
	
	showBackground(background);
	
	return 0;
}


// (BACKGROUND_SIZE-1)*(BACKGROUND_SIZE-1)크기의 바둑판을 만든다.
int** makeBackground() {
	int background[BACKGROUND_SIZE][BACKGROUND_SIZE];
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
	
	
	return background;
}

//이차원 배열을 출력한다. 
void showBackground(int** background) {
	
	for (int i = 0; i < BACKGROUND_SIZE; i++) {
		for (int j = 0; j < BACKGROUND_SIZE; j++) {
			printf("%d\t", background[i][j]);
		}
		printf("\n");
	}
	printf("완료");
}