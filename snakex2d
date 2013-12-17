#include <GL/glut.h>

#include <stdlib.h>
#include <fstream>


#include "vars.hpp"
#include "game.hpp"




game snake;

int temp = 0;
int num;
int starting;



void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	snake.drawField();
	
	snake.drawSnake();
	
	fru1.draw();
	fru2.draw();

	wall->draw();

	for(temp = 0 ; temp < num ;temp++)
	{
		w[temp]->draw();
	}
	
	
	glutSwapBuffers();
}



void timer(int = 0) {
	display();
	
	
	snake.stroke();
	
	
	glutTimerFunc(step, timer, 0);
}



void firstRecordSetup() {
	std::ifstream RI("save.snk");
	RI >> MX;
	myMX = MX;
}



void firstGameSetup() {
	for(int i = 0; i < sh; i++) {
		s[i].x = VM_N / 2;
		s[i].y = (VM_M + sh) / 2 - i;
	}
	
	
	fru1.gen();
	fru2.gen();

	wall->gen();
	
	for(temp = 0 ; temp < num ;temp++)
	{
		w[temp]->gen();
	}

}



void firstSetup() {
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);
}




int main(int argc, char **argv) {


start:

	printf("1을 입력하면 시작합니다.\n");
	scanf("%d", &starting);

	while(starting == 1)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowSize(VD_W, VD_H);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("XSnake 2D");
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0, VD_W, 0, VD_H);
	
		w[0] = new block(0);
		num=1;

		firstSetup();
		firstGameSetup();
		firstRecordSetup();
	
		glutSpecialFunc(game::keyboard);
	
		glutDisplayFunc(display);
		glutTimerFunc(step, timer, 0);
	
		glutMainLoop();
	}
	
	if(starting == 2)
	{
		starting = 1;
		goto start;
	}
	
	return 0;
}
