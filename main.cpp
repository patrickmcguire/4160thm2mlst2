#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <stddef.h>

#include "Teapot.h"
#include "Floor.h"
#include "Box.h"
#include "Torus.h"
#include "Sphere.h"

const int WIDTH = 600;
const int HEIGHT = 480;

void init();
void display();

int main( int argc, char *argv[] ) {

	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowPosition( 100, 100 );
	glutInitWindowSize( WIDTH, HEIGHT );
	glutCreateWindow( argv[0] );
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

void init() {
	glClearColor( 0.0, 0.0, 0.0, 1.0 );
}

void display() {
	glClear( GL_COLOR_BUFFER_BIT );
	glutSwapBuffers();

	int leftmost = -15;
	int rightmost = 15;
	int closest = -10;
	int furthest = 10;

	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glColor3i(128, 128, 128);
	glBegin(GL_QUAD_STRIP);
		for(int i = leftmost; i < rightmost; i += ((rightmost - leftmost) / 15)) {
			for(int j = closest; j < furthest; j += ((furthest - closest) / 10)) {
				glVertex3i(i,0,j);
				if(i < rightmost - 1) {
					glVertex3i(i+1,0,j);
				}
			}
		}
	glEnd();

	gluLookAt(2, 4, 2,
			 0, 0, 0,
			 0, 1, 0);
}
