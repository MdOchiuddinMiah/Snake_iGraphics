/*                                    
                                    "UIU" 
                                  
                         "UNITED  INTERNATIONAL  UNIVERSITY"                     


	  Author: MD.OCHIUDDIN MIAH.
	  ID. 011 131 145.
	  md.imdadul haque imran
	  id.011 131 144  .
	  DEPT: CSE.
	  last modified: december 10, 2013.
*/
# include "iGraphics.h"
# include<time.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
int rx=10,ry=20;
int dx=70,dy=10;
int foodX,foodY;
int direction;
int count=5;
int counter= 0,start = 0;
char str[10];
void iDraw()
{

	iClear();
	iShowBMP(50, 50, "1.bmp");
	iSetColor(100, 255, 0);
	iFilledRectangle(300, 105,100,25);
	
	iSetColor(255, 0, 0);
	iText(310, 110, "START", GLUT_BITMAP_TIMES_ROMAN_24);
	if(start == 1){
		iShowBMP(50, 50, "2.bmp");
		iSetColor(0,255,0);
		iText(500, 360,"SCORE : " , GLUT_BITMAP_TIMES_ROMAN_24);
	if(foodX!=-1&&foodY!=-1 ){
		iFilledCircle(foodX,foodY,10);
		
		 
		iText(650, 360,str , GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
		
	iSetColor(255,255,255);
	iFilledRectangle(rx,ry,dx,dy);
	if((rx >= 640 && ry <400) || (rx == 0 && ry <400) || (ry >= 340 && rx <700) ||(ry == 0 && rx < 700)){
		iPauseTimer(0);
		iSetColor(0,0,0);
		iShowBMP(100, 150, "sgo.bmp");
		iFilledRectangle(rx,ry,dx,dy);
		iFilledCircle(foodX,foodY,10);
		

	}
	}
}


void iMouseMove(int mx, int my)
{
	 
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	
	
		if(mx >= 300 && mx <= 400 && my >= 105 && my <= 130 && start == 0)
		{
			start = 1;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

 
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		
	}
}

 
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	else if(key == GLUT_KEY_UP)
	{
		direction = UP;
      	
	}
	else if(key == GLUT_KEY_DOWN)
	{
		direction = DOWN;

	}
	else if(key == GLUT_KEY_LEFT)
	{
	   direction = LEFT;
	}
	else if(key == GLUT_KEY_RIGHT)
	{
	    direction = RIGHT;
	}
	
}
double distance(int x1,int y1,int x2,int y2)
{
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
void changePosition()
{
	switch(direction)
	{
	case UP:
		ry+= 5;
		dx=10;
		dy=70;
		break;
	case DOWN:
		ry-= 5;
		dx=10;
		dy=70;
		break;
	case LEFT:
		rx-= 5;
		dx=70;
		dy=10;
		break;
	case RIGHT:
		rx+= 5;
		dx=70;
		dy=10;
		break;
	}
	if(distance(rx,ry,foodX,foodY)<10)
	{
		foodX = rand()%540 + 70;
		foodY = rand()% 240 + 70;

        counter++ ;
		itoa(counter,str,10);
		count++;

	}
	if(rx>700)
	{
		rx-=5;
	
	}
	else if(rx<0)
	{
	   rx+=5;
	}
	else if(ry>400)
	{
	   ry-=5;
	}
	else if(ry<0)
	{
	   ry+=5;
	
	}

}
int main()
{
	
	
	direction = RIGHT;
	srand(time(NULL));
	foodX = rand()%540 + 70;
	foodY = rand()% 240 + 70;
	
	iSetTimer(35,changePosition);
	
	iInitialize(700, 400, "Snake");
	

	return 0;

}