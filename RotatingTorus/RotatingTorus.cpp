// CS368 - SUMMER 2014
// Author - Lee, Juhyun
// Date - 08/06/2014
// Project 3 3d model with functions and idle.


#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/GL.h>
#include <iostream>

using namespace std;

// constant variable for the window creatation only.
const int WIDTH = 700 , HEIGHT = 700;

// variable to be used on rotational speed.
static double xspeed = 0.0 , yspeed = 0.0 ;

// variable for the keyboard function.
bool zstop = false , xstop = false , ystop = false , polymod = false ;

// bool to be used on console, output to console.
bool optocons = true;

// variables used for rotation. rotate on x , totate on y 
float rotonx, rotony , rotonz;

// variables used for the light source and position.
GLfloat frontamdiff[] = {0.7 , 0.5, 0.1 , 1.0};
GLfloat amb[] = {0.3 , 0.3, 0.3 , 0.1};
GLfloat pos[] = {-3 , 3, 8 , 1};


// method for rotating element in y axis.
void yrotating (){

	glLoadIdentity();
	glPushMatrix();

	glTranslatef(0.0,0.0,-10.0);
    glRotatef(rotony,0.0,1.0,0.0);

}//end of y rotating.

// method for rotating element in x axis.
void xrotating (){

	glLoadIdentity();
	glPushMatrix();

	glTranslatef(0.0,0.0,-10.0);
    glRotatef(rotonx,1.0,0.0,0.0);

} //end of method x rotationg

//method to rotate element in z axis.
void zrotating (){

	glLoadIdentity();
	glPushMatrix();

	glTranslatef(0.0,0.0,-10.0);
    glRotatef(rotonz,0.0,0.0,1.0);

}//end of y rotating.


// method to create inner anchor that is a box
void inneranchors(){

	glBegin( GL_QUADS );

	// right anchor
	glColor3f( 1.0 , 1.0 , 1.0);
	glVertex3f( 1.0 , -0.1 , 0.1 ); glVertex3f( 2.0 , -0.1 , 0.1 );
	glVertex3f( 2.0 , 0.1 , 0.1 ); glVertex3f( 1.0 , 0.1 , 0.1 );

	glColor3f( 1.0 , 0.0 , 0.0);
	glVertex3f( 1.0 , -0.1 , -0.1 ); glVertex3f( 2.0 , -0.1 , -0.1 );
	glVertex3f( 2.0 , 0.1 , -0.1 ); glVertex3f( 1.0 , 0.1 , -0.1 );

	glColor3f( 0.0 , 1.0 , 0.0);
	glVertex3f( 1.0 , 0.1 , 0.1 ); glVertex3f( 2.0 , 0.1 , 0.1 );
	glVertex3f( 2.0 , 0.1 , -0.1 ); glVertex3f( 1.0 , 0.1 , -0.1 );

	glColor3f( 0.0 , 0.0 , 1.0);
	glVertex3f( 1.0 , -0.1 , 0.1 ); glVertex3f( 2.0 , -0.1 , 0.1 );
	glVertex3f( 2.0 , -0.1 , -0.1 ); glVertex3f( 1.0 , -0.1 , -0.1 );

	// left anchor.
	glColor3f( 1.0 , 1.0 , 1.0);
	glVertex3f( -1.0 , -0.1 , 0.1 ); glVertex3f( -2.0 , -0.1 , 0.1 );
	glVertex3f( -2.0 , 0.1 , 0.1 ); glVertex3f( -1.0 , 0.1 , 0.1 );

	glColor3f( 1.0 , 0.0 , 0.0);
	glVertex3f( -1.0 , -0.1 , -0.1 ); glVertex3f( -2.0 , -0.1 , -0.1 );
	glVertex3f( -2.0 , 0.1 , -0.1 ); glVertex3f( -1.0 , 0.1 , -0.1 );

	glColor3f( 0.0 , 1.0 , 0.0);
	glVertex3f( -1.0 , 0.1 , 0.1 ); glVertex3f( -2.0 , 0.1 , 0.1 );
	glVertex3f( -2.0 , 0.1 , -0.1 ); glVertex3f( -1.0 , 0.1 , -0.1 );

	glColor3f( 0.0 , 0.0 , 1.0);
	glVertex3f( -1.0 , -0.1 , 0.1 ); glVertex3f( -2.0 , -0.1 , 0.1 );
	glVertex3f( -2.0 , -0.1 , -0.1 ); glVertex3f( -1.0 , -0.1 , -0.1 );

	glColor3f( 0.7 , 0.0 , 0.0);

	glEnd();

}//end of inner anchor 

// method to create outter anchor as a box.
void outteranchor(){

	glBegin( GL_QUADS );

	//upper anchor
	glColor3f( 1.0 , 1.0 , 1.0);
	glVertex3f( -0.1 , 2.0 , 0.1 ); glVertex3f( 0.1 , 2.0 , 0.1 );
	glVertex3f( 0.1 , 3.0 , 0.1 ); glVertex3f( -0.1 , 3.0 , 0.1 );

	glColor3f( 1.0 , 0.0 , 0.0);
	glVertex3f( -0.1 , 2.0 , -0.1 ); glVertex3f( 0.1 , 2.0 , -0.1 );
	glVertex3f( 0.1 , 3.0 , -0.1 ); glVertex3f( -0.1 , 3.0 , -0.1 );

	glColor3f( 0.0 , 1.0 , 0.0);
	glVertex3f( 0.1 , 2.0 , 0.1 ); glVertex3f( 0.1 , 2.0 , -0.1 );
	glVertex3f( 0.1 , 3.0 , -0.1 ); glVertex3f( 0.1 , 3.0 , 0.1 );

	glColor3f( 0.0 , 0.0 , 1.0);
	glVertex3f( -0.1 , 2.0 , 0.1 ); glVertex3f( -0.1 , 2.0 , -0.1 );
	glVertex3f( -0.1 , 3.0 , -0.1 ); glVertex3f( -0.1 , 3.0, 0.1 );

	//lower anchor
	glColor3f( 1.0 , 1.0 , 1.0);
	glVertex3f( -0.1 , -2.0 , 0.1 ); glVertex3f( 0.1 , -2.0 , 0.1 );
	glVertex3f( 0.1 , -3.0 , 0.1 ); glVertex3f( -0.1 , -3.0 , 0.1 );

	glColor3f( 1.0 , 0.0 , 0.0);
	glVertex3f( -0.1 , -2.0 , -0.1 ); glVertex3f( 0.1 , -2.0 , -0.1 );
	glVertex3f( 0.1 , -3.0 , -0.1 ); glVertex3f( -0.1 , -3.0 , -0.1 );

	glColor3f( 0.0 , 1.0 , 0.0);
	glVertex3f( 0.1 , -2.0 , 0.1 ); glVertex3f( 0.1 , -2.0 , -0.1 );
	glVertex3f( 0.1 , -3.0 , -0.1 ); glVertex3f( 0.1 , -3.0 , 0.1 );

	glColor3f( 0.0 , 0.0 , 1.0);
	glVertex3f( -0.1 , -2.0 , 0.1 ); glVertex3f( -0.1 , -2.0 , -0.1 );
	glVertex3f( -0.1 , -3.0 , -0.1 ); glVertex3f( -0.1 , -3.0, 0.1 );

	glColor3f( 0.0 , 0.0 , 0.7);

	glEnd();

}//end of outter anchor

//method to display the function.
void display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
	glTranslatef(0.0,0.0,-10.0 );

	// middle ring that does not move.
	glColor3f( 0.0 , 0.7 , 0.0);
	glutSolidTorus( 0.3 , 2.0 , 20 , 50);
	glPopMatrix();
	
	xrotating();
	// rotate on z when r is pressed.
	if(zstop == true)
		glRotatef(rotonz,0.0,0.0,1.0);
	inneranchors();
	glutSolidTorus( 0.3 , 1.0 , 20 , 50);
	glPopMatrix();


	yrotating();
	// rotate on z when r is pressed.
	if(zstop == true)
		glRotatef(rotonz,0.0,0.0,1.0);
	outteranchor();
	glutSolidTorus( 0.3 , 3.0, 20 , 50);
	glPopMatrix();
	
	// since glut_double is used need swapbuffer.
	glutSwapBuffers();

}//end of display.

//idle function but mostly to do calculations for the rotation.
void idletor(void){

	//when r is not pressed do nothing.
	if( zstop == false) ;		
	else
		rotonz += 0.1;

	//when y is pressed stop the outter torus by doing nothing. 
	if( ystop == true);		
	else
		rotony += 0.1 + yspeed;

	//when x is pressed stop the inner torus by doing nothing.
	if(xstop == true);
	else
		rotonx += 0.1 + xspeed;

	//push to re display.
	glutPostRedisplay();


}//end of idletor


// method to handle all keyboard method.
void keyboard(unsigned char key, int kbx, int kby){
	switch(key){
		case 'w':			// increase x rotation when w is pressed.
			xspeed = xspeed + 0.05;
			break;

		case 's':			// decrease x rotation when s is pressed.
			xspeed = xspeed - 0.05;
			break;

		case 'a':			// decrease y rotation when a is pressed.
			yspeed = yspeed - 0.05;
			break;

		case 'd':			// increase y rotation when d is pressed.
			yspeed += 0.05;
			break;

		case 'x':			// stops x rotation when x is pressed.
			xstop = !xstop;
			break;

		case 'y':			// stops y rotation when y is pressed.
			ystop = !ystop;
			break;

		case 'r':			// toggle z rotation and reset.
			zstop = !zstop;
			break;

		case 'p':			// toggle z rotation and reset.
			polymod = !polymod;

			if(polymod)
				glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			else
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			break;

	}//end of switch

	glutPostRedisplay();

}//end of keyboard

// method to out put to console the menu
void consolecmd(){
	if( optocons == true){

		cout << "OUTTER RING SPEED:	W to increase	::	S to decrease \n";
		cout << "INNER RING SPEED:	D to increase	::	A to decrease \n";
		cout << " ** note that decresing speed enough will reverse the rotation ** \n \n";
		cout << "TO STOP THE RING:	X to stop inner	::	Y to stop outter \n";
		cout << "PRESS P to See line mode, P again to See Filled Mode \n \n";
		cout << "Press R to rotate in Z Axis, Press R again to Reset. \n ";
		cout << " ** note that while Z rotation is on, Stop and Speed command still works.** \n";

		
		optocons = false;

	}//end of if statment


}//end of console command.



//method of main to run the program.
int main(int argc, char* argv[]){

	glutInit(&argc,argv);
 
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB | GLUT_DEPTH );

	glutInitWindowSize(WIDTH,HEIGHT);
	glutInitWindowPosition(200,100);

	glutCreateWindow("project 3");
	glClearColor( 0.0 , 0.0 , 0.0 , 0.0);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity;
	
	glOrtho(-5.0 , 5.0 , -5.0 , 5.0 , 5 , 20);

	glMaterialf(GL_FRONT, GL_AMBIENT , 1.0);
	glLightfv(GL_LIGHT0, GL_AMBIENT , amb);
	glLightModeli(GL_LIGHT_MODEL_AMBIENT, GL_TRUE);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0,0,-5);
	glLightfv(GL_LIGHT0 , GL_POSITION , pos);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idletor);

	consolecmd();

	glutMainLoop();

  return 0;
 
}//end of main