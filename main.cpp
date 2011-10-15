#include "util.h"
#include "viewing.h"

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
void display(void) {

	clear();

	drawOrthoView( 90, 1, 0, 0, 0, 0 );
	drawPerspView( 0, 1 );
	drawOrthoView(  0, 1, 0, 0, 1, 0 );
	drawOrthoView( -90, 0, 1, 0, 1, 1 );

	// flush buffer to screen
	glFlush();
}

// initialization function
void init(void) {
	glClearColor(0.8, 0.8, 0.8, 1.0);
	glMatrixMode(GL_PROJECTION);
	glDepthFunc( GL_LESS );
	glEnable( GL_DEPTH_TEST );
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
	//glEnable (GL_BLEND);
	//glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLoadIdentity();
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

