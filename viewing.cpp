/*
 * Views.cpp
 *
 *  Created on: Oct 14, 2011
 *      Author: pjm
 */

#include "viewing.h"
#include "shapes.h"


void drawScene()
{
	glPushMatrix();
		drawFloor();
	glPopMatrix();
}

void drawOrthoView( float angle, float x, float y, float z, int quadRow, int quadCol)
{
	glPushMatrix();
	glOrtho(-20.0, 20.0, -20.0, 20.0, -20.0, 20.0);
		glMatrixMode( GL_MODELVIEW );
		glPushMatrix();
			glRotatef( angle, x, y, z );
			drawSceneMatrix( quadRow, quadCol );
		glPopMatrix();
	glMatrixMode( GL_PROJECTION );
	glPopMatrix();
}

void drawSceneMatrix( int quadRow, int quadCol)
{
	glViewport(quadCol * window_width/2, (1 - quadRow) * window_height/2,
				window_width/2, window_height/2);
	drawScene();
}

void drawPerspView( int quadRow, int quadCol )
{
	glPushMatrix();
		glFrustum(-5.0, 5.0, -5.0, 5.0, 3.5, 80.0);
		glMatrixMode( GL_MODELVIEW );
		glPushMatrix();
			gluLookAt( -15,15,10, 0,0,0, 0,1,0 );
			drawSceneMatrix( quadRow, quadCol );
		glPopMatrix();
	glMatrixMode( GL_PROJECTION );
	glPopMatrix();
}


