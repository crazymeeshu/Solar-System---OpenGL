//Meeshaan Shah
//Assignment 6
//solar system

#ifndef MAC //if not MAC
#include <GL\glut.h>
#else // MAC includes below
#include <GLUT/glut.h>
#endif

//object sizes
#define sunRadius 1.0
#define mercuryRadius 0.02
#define venusRadius 0.059
#define earthRadius 0.06
#define moonRadius 0.016
#define marsRadius 0.035
#define jupiterRadius 0.2
#define saturnRadius 0.15
#define uranusRadius 0.08
#define neptuneRadius 0.078

//declare menu options
#define FRONT 1
#define TOP 2
#define MID_TOP 3
#define MID_BOTTOM 4
#define SPEED_INC 5
#define SPEED_DEC 6

GLfloat rotSpeed = 0.5;
GLfloat mercuryYear = 87.989;
GLfloat merYear = 0.0; //degree
GLfloat merDay = 0.0; 
GLfloat venusYear = 224.70;
GLfloat venYear = 0.0; //degree
GLfloat venDay = 0.0; 
GLfloat earthYear = 365.25;   
GLfloat eYear = 0.0; //degree
GLfloat eDay = 0.0;
GLfloat marsYear = 686.97;   
GLfloat marYear = 0.0; //degree
GLfloat marDay = 0.0;
GLfloat jupiterYear = 4332.59;   
GLfloat jupYear = 0.0; //degree
GLfloat jupDay = 0.0;
GLfloat saturnYear = 10759.22;
GLfloat satYear = 0.0; //degree
GLfloat satDay = 0.0;
GLfloat uranusYear = 30687.15;
GLfloat uraYear = 0.0; //degree
GLfloat uraDay = 0.0;
GLfloat neptuneYear = 60190.03;
GLfloat nepYear = 0.0; //degree
GLfloat nepDay = 0.0;
GLfloat moonOrbit = 0.0;
GLfloat moonRotation = 0.0;

//orbit radius for each planet
GLfloat mercuryOrbitRadius = 1.5;
GLfloat venusOrbitRadius = 1.9;
GLfloat earthOrbitRadius = 2.2;
GLfloat moonOrbitRadius = 0.1;
GLfloat marsOrbitRadius = 2.5;
GLfloat jupiterOrbitRadius = 3.5;
GLfloat saturnOrbitRadius = 4.2;
GLfloat uranusOrbitRadius = 4.7;
GLfloat neptuneOrbitRadius = 5.2;

//for camera viewport
GLfloat cameraY = 0.0;
GLfloat cameraZ = -10.0;


void init()
{
	glClearColor(0.0, 0.0, 0.0, 0); //black background
	glClearDepth(10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawSolarSystem()
{
	glPushMatrix();
		gluLookAt(0.0, cameraY, cameraZ, //for changing camera
				  0.0, 0.0, 0.0,
				  0.0, -3.0, 0.0);
		
		//sun
		glColor3f(1.0, 0.8, 0.3);
		glutSolidSphere(sunRadius, 50, 50);
		//mercury
		glPushMatrix();
			glRotatef(-merYear, 0.0, 1.0, 0.0); //orbit
			glTranslatef(mercuryOrbitRadius, 0.0, 0.0); //move from center
			glRotatef(merYear, 0.0, 1.0, 0.0);
			glPushMatrix();
				glRotatef(merDay, 0.0, 1.0, 0.0);	//rotation
				glColor3f(0.752941, 0.752941, 0.752941);	// color
				glutSolidSphere(mercuryRadius, 9, 9); //draw planet
			glPopMatrix();
		glPopMatrix();
		//venus
		glPushMatrix();
			glRotatef(venYear, 0.0, 1.0, 0.0); //orbit
			glTranslatef(venusOrbitRadius, 0.0, 0.0); //move from center
			glRotatef(-venYear, 0.0, 1.0, 0.0);
			glPushMatrix();
				glRotatef(venDay, 1.77, 1.0, 0.0);	//rotation
				glColor3f(0.623529, 0.623529, 0.372549);	// color
				glutSolidSphere(venusRadius, 10, 10); //draw planet
			glPopMatrix();
		glPopMatrix();
		//earth
		glPushMatrix();
			glRotatef(-eYear, 0.0, 1.0, 0.0); //orbit
			glTranslatef(earthOrbitRadius, 0.0, 0.0); //move from center
			glRotatef(eYear, 0.0, 1.0, 0.0);
			glPushMatrix();
				glRotatef(eDay, 0.23, 1.0, 0.0);	//rotation 
				glColor3f(0.196078, 0.8, 0.6);	//color
				glutSolidSphere(earthRadius, 10, 10); //draw planet
			glPopMatrix();
			//moon
			glRotatef(moonOrbit, 0.0, 1.0, 0.0); //orbit for moon
			glTranslatef(moonOrbitRadius, 0.0, 0.0); //moves moon from earth
			glRotatef(-moonOrbit, 0.0, 1.0, 0.0); //orbit around earth
			glRotatef(moonRotation, 0.66, 1.0, 0.0); //moon rotation
			glColor3f(0.3, 0.3, 0.3);
			glutSolidSphere(moonRadius, 8, 8);
		glPopMatrix();
		//mars
		glPushMatrix();
			glRotatef(-marYear, 0.0, 1.0, 0.0); //orbit
			glTranslatef(marsOrbitRadius, 0.0, 0.0); //move from center
			glRotatef(marYear, 0.0, 1.0, 0.0);
			glPushMatrix();
				glRotatef(marDay, 0.25, 1.0, 0.0);	//rotation
				glColor3f(0.59, 0.41, 0.31);	// color
				glutSolidSphere(marsRadius, 10, 10); //draw planet
			glPopMatrix();
		glPopMatrix();
		//jupiter
		glPushMatrix();
			glRotatef(-jupYear, 0.0, 1.0, 0.0); //orbit
			glTranslatef(jupiterOrbitRadius, 0.0, 0.0); //move from center
			glRotatef(jupYear, 0.0, 1.0, 0.0);
			glPushMatrix();
				glRotatef(jupDay, 0.03, 1.0, 0.0);	//rotation
				glColor3f(0.36, 0.25, 0.20);	// color
				glutSolidSphere(jupiterRadius, 25, 25); //draw planet
			glPopMatrix();
		glPopMatrix();
		//saturn
		glPushMatrix();
			glRotatef(-satYear, 0.0, 1.0, 0.0); //orbit
			glTranslatef(saturnOrbitRadius, 0.0, 0.0); //move from center
			glRotatef(satYear, 0.0, 1.0, 0.0);
			glPushMatrix();
				glRotatef(satDay, 0.26, 1.0, 0.0);	//rotation
				glColor3f(0.81, 0.71, 0.23);	// color
				glutSolidSphere(saturnRadius, 20, 20); //draw planet
			glPopMatrix();
		glPopMatrix();
		//uranus
		glPushMatrix();
			glRotatef(-uraYear, 0.0, 1.0, 0.0); //orbit
			glTranslatef(uranusOrbitRadius, 0.0, 0.0); //move from center
			glRotatef(uraYear, 0.0, 1.0, 0.0);
			glPushMatrix();
				glRotatef(uraDay, 1.0, 0.0, 0.0);	//rotation
				glColor3f(0.678431, 0.917647, 0.917647);	// color
				glutSolidSphere(uranusRadius, 15, 15); //draw planet
			glPopMatrix();
		glPopMatrix();
		//neptune
		glPushMatrix();
			glRotatef(-nepYear, 0.0, 1.0, 0.0); //orbit
			glTranslatef(neptuneOrbitRadius, 0.0, 0.0); //move from center
			glRotatef(nepYear, 0.0, 1.0, 0.0);
			glPushMatrix();
				glRotatef(nepDay, 0.28, 1.0, 0.0);	//rotation
				glColor3f(0.196078, 0.196078, 0.8);	// color
				glutSolidSphere(neptuneRadius, 13, 13); //draw planet
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

//displays objects to screen
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawSolarSystem();
	glFlush();
	glutSwapBuffers();
}

//reshape function to make sure objects and window scales correctly
void reshape(int width, height)
{
	if (width == 0 || height == 0)
		return;
		
	glLoadIdentity();
	gluPerspective(40.0, (GLdouble)width/(GLdouble)height, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, width, height);
	display();
}

//idle function to manage rotations speeds
void idle()
{
	//mercury
	merDay += (5.0 * rotSpeed);
    merYear += (mercuryYear / 360.0 * (70.0 * rotSpeed) * rotSpeed);
    
    //venus
	venDay += (2.5 * rotSpeed);
    venYear += (venusYear / 360.0 * (10.0 * rotSpeed) * rotSpeed);
	
	//earth
	eDay += (5.0 * rotSpeed);
    eYear += (earthYear / 360.0 * (5.0 * rotSpeed) * rotSpeed);
    //moon
    moonRotation += (5.0 * rotSpeed);
    moonOrbit += (5.0 * rotSpeed);
    
    //mars
	marDay += (5.0 * rotSpeed);
    marYear += (marsYear / 360.0 * (1.2 * rotSpeed) * rotSpeed);
    
    //jupiter
	jupDay += (12.0 * rotSpeed);
    jupYear += (jupiterYear / 360.0 * (0.035 * rotSpeed) * rotSpeed);
    
    //saturn
	satDay += (12.0 * rotSpeed);
    satYear += (saturnYear / 360.0 * (0.0055 * rotSpeed) * rotSpeed);
    
    //uranus
	uraDay += (10.0 * rotSpeed);
    uraYear += (uranusYear / 360.0 * (0.0007 * rotSpeed) * rotSpeed);
    
    //neptune
	nepDay += (10.5 * rotSpeed);
    nepYear += (uranusYear / 360.0 * (0.0004 * rotSpeed) * rotSpeed);
    
    display();
}

//menu events for camera change 
void menuEvents(int option) 
{	
	switch (option) 
	{
		//for default camera
		case FRONT :
			cameraY = 0.0;
			cameraZ = -10.0;
			break;
		//top 
		case TOP :
			cameraY = -10.0;
			cameraZ = -0.000001;
			break;
		//top middle 
		case MID_TOP :
			cameraY = -5.0;
			cameraZ = -10.0;
			break;
		//bottom middle
		case MID_BOTTOM :
			cameraY = 5.0;
			cameraZ = -10.0;
			break;
		//increase speed of rotation
		case SPEED_INC :
			rotSpeed += 0.2;
			break;
		//increase speed of rotation
		case SPEED_DEC :
			rotSpeed -= 0.2;
			break;
	}
	display();
}

//display menu
void createMenu() 
{	
	display();
	
	int menu;

	//create menu and process events
	menu = glutCreateMenu(menuEvents);

	//add entries to menu
	glutAddMenuEntry("Front", FRONT);
	glutAddMenuEntry("Top", TOP);
	glutAddMenuEntry("Top Middle", MID_TOP);
	glutAddMenuEntry("Bottom Middle", MID_BOTTOM);
	glutAddMenuEntry("Increase Rotation Speed", SPEED_INC);
	glutAddMenuEntry("Decrease Rotation Speed", SPEED_DEC);
	
	//make menu appear upon righ click
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//main
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1200, 700);
	glutCreateWindow("My Sexy Window");
	//glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(createMenu);
	glutIdleFunc(idle);
  	glutMainLoop();
  	return 0;
}
