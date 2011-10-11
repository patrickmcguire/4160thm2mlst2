#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <iostream>

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

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	int leftmost = -15;
	int rightmost = 15;
	int closest = -10;
	int furthest = 10;

	glPolygonMode(GL_FRONT,GL_LINE);
	glColor3f(0.5f, 0.5f, 0.5f);

	int iinc = (rightmost - leftmost) / 15;
	int jinc = (furthest - closest) / 10;

	for (int i = leftmost; i < rightmost; i = i + iinc) {
		glBegin(GL_QUAD_STRIP);
		glPolygonMode(GL_FRONT,GL_LINE);
		for (int j = closest; j < furthest; j = j + jinc) {
			glVertex3i(i,0,j);
			if(i < i - iinc) {
				glVertex3i(i + iinc, 0, j);
			}
		}
		glEnd();
	}

	glPolygonMode(GL_FRONT,GL_FILL);
	glFlush();

	glutSwapBuffers();


}
