#include "util.h"
#include "viewing.h"
#include "menu.h"
#include <iostream>

void init();
void display();
void clear();

/*
 * main_t02m02.cpp
 *
 *  Created on: Oct 5, 2011
 *      Author: agis
 */


// clearing/refreshing routines
void clear()
{
	glClear( GL_COLOR_BUFFER_BIT );
	glClear( GL_DEPTH_BUFFER_BIT );
}

// the main display function
void display(void)
{

	clear();

	drawOrthoView( 90, 1, 0, 0, 0, 0 );
	drawPerspView( 0, 1 );
	drawOrthoView(  0, 1, 0, 0, 1, 0 );
	drawOrthoView( -90, 0, 1, 0, 1, 1 );

	glFlush();
}

// initialization function
void init(void)
{
	glDisable( GL_LIGHT1 );
	glClearColor(0.8, 0.8, 0.8, 1.0);
	glMatrixMode(GL_PROJECTION);
	glDepthFunc( GL_LESS );
	glEnable( GL_DEPTH_TEST );
	glEnable( GL_COLOR_MATERIAL );
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
	//glEnable (GL_BLEND);
	//glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLoadIdentity();
	glEnable(GL_NORMALIZE);

	glEnable( GL_LIGHTING );

	glColorMaterial( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 0);
	glShadeModel (GL_SMOOTH);

	GLfloat light_ambient0[] = { 0.05, 0.05, 0.05, 1.0 };
	GLfloat light_diffuse0[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position0[] = { 0.0, 10000.0, 0.0 };
	GLfloat light_specular0[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glEnable( GL_LIGHT0 );

	GLfloat light_ambient1[] = { 0.1, 0.00, 0.00, 1.0 };
	GLfloat light_diffuse1[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular1[] = { 1.0, 0, 1.0, 1.0 };
	GLfloat light_position1[] = { 0.0, 10000.0, 0.0 };
	GLfloat spot_direction1[] = {0.0, 0.0, -1.0};
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction1);
	glEnable( GL_LIGHT1 );

	glEnable( GL_DEPTH_TEST );
	createMenu();
}

/* * Declare initial window size, position, and display mode * (single buffer and RGBA). Open window with �hello� * in its title bar. Call initialization routines. * Register callback function to display graphics. * Enter main loop and process events. */
int main(int argc, char** argv) {
	glutInit(&argc, argv);											// it is always there
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH );		// single buffer (no animation), rgb
	glutInitWindowSize(window_width, window_height);				// window size
	glutInitWindowPosition(100, 100);								// window position
	glutCreateWindow("t02m02");										// new window + title
	init();															// initialization (not necessarily glut)
	glutDisplayFunc(display);										// callback registration
	glutMainLoop();
	return 0;
}
