#include <iostream>
#include <stdio.h>
using namespace std;

extern int temp;
extern int num;
extern int starting;

class fruct{
	public:
		int x, y;
	
		void gen() {
			x = rand() % VM_N;
			y = rand() % VM_M;
			
			for(int i = 0; i < sh; i++)
				if(s[i].x == x && s[i].y == y)
					gen();
		}
		
		virtual void draw() {
			glColor3f(1, 0, 0);
			glRecti(x * VM_Scale - 1, y * VM_Scale, (x + 1) * VM_Scale, (y + 1) * VM_Scale + 1);
		}
};

class block : public fruct{
	public:
		block() {}
		block(int n) { num = n; color = 255; }
		block(int n, int c) { num = n; color = c; }
	
		void draw() {
			glColor3f(255, 255, 255);
			glRecti(x * VM_Scale - 1, y * VM_Scale, (x + 1) * VM_Scale, (y + 1) * VM_Scale + 1);
		}
	private:
		int num;
		int color;
};


fruct fru1;
fruct fru2;

block * wall = new class block(1);
//class block * walls[100];
block * w[100];

//walls[1] = new class block;

class game {
	public:
		void over() {
			std::ofstream RO("save.snk");
			
			RO << myMX;
			
			RO.close();

			exit(0);
			
			starting = 2;
		}
		
		
		
		void drawField() {
			glColor3f(1, 1, 1);
			
			glBegin(GL_LINES);
				for(int i = 0; i < VM_N; i++) {
					glVertex2i(i * VM_Scale, 0);	glVertex2i(i * VM_Scale, VD_H);
				}
				for(int i = 0; i < VM_M; i++) {
					glVertex2i(0, i * VM_Scale);	glVertex2i(VD_W, i * VM_Scale);
				}
			glEnd();
				
		}



		void drawSnake() {
			glColor3f(1, 1, 0);
			glRecti(s[0].x * VM_Scale - 1, s[0].y * VM_Scale, (s[0].x + 1) * VM_Scale, (s[0].y + 1) * VM_Scale + 1);
			
			glColor3f(1, 0, 1);
			for(int i = 1; i < sh; i++)
				glRecti(s[i].x * VM_Scale - 1, s[i].y * VM_Scale, (s[i].x + 1) * VM_Scale, (s[i].y + 1) * VM_Scale + 1);
		}
		
		
		
		void stroke() {
			for(int i = sh; i > 0; i--) {
				s[i].x = s[i-1].x;
				s[i].y = s[i-1].y;
			}
			
			if(dir == 1)
				s[0].y += 1;
			if(dir == 2)
				s[0].x += 1;
			if(dir == 3)
				s[0].y -= 1;
			if(dir == 4)
				s[0].x -= 1;
			
			
			if(fru1.x == s[0].x && fru1.y == s[0].y) {
				sh++;
				fru1.gen();
				
				if(sh > MX)
					myMX = sh;
				
				if(step > 1)
					step -= step / 20;
				wall->gen();

				w[num] = new block;
				num++;

				for(temp = 0 ; temp < num ;temp++)
				{
					w[temp]->gen();
				}
			}
			
			if(fru2.x == s[0].x && fru2.y == s[0].y) {
				sh++;
				fru2.gen();
				
				if(sh > MX)
					myMX = sh;
				
				if(step > 1)
					step -= step / 20;
				wall->gen();
				
		
				w[num] = new block;
				num++;
	
				for(temp = 0 ; temp < num ;temp++)
				{
					w[temp]->gen();
				}
			}
//			--------------------------------------------------------------------------- wall and fru
		if( 1==1 )
		{
			for(temp = 0 ; temp < num ; temp++)
			{
				if(w[temp]->x == s[0].x && w[temp]->y == s[0].y)
				{
					over();
				}
			}

		}

			if(wall->x == s[0].x && wall->y == s[0].y)
			{
				over();
			}
				
			/*
				sh++;
				wall->gen();
				
				if(sh > MX)
					myMX = sh;
				
				if(step > 1)
					step -= step / 20;
			*/
			
			if(s[0].x < 0 || s[0].x >= VM_N || s[0].y < 0 || s[0].y >= VM_M)
				over();
			
			
			for(int i = 1; i < sh; i++)
				if(s[0].x == s[i].x && s[0].y == s[i].y)
					sh = i+1;
		}



		static void keyboard(int key, int a, int b) {
			switch(key) {
				case 101:
					if(dir != 3)
						dir = 1;
				break;
				
				case 102:
					if(dir != 4)
						dir = 2;
				break;
				
				case 103:
					if(dir != 1)
						dir = 3;
				break;
				
				case 100:
					if(dir != 2)
						dir = 4;
				break;

				case GLUT_KEY_PAGE_UP:
					system("PAUSE");
				
				break;
			}
		}
};
