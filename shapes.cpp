/*
 * shapes.cpp
 *
 *  Created on: Oct 9, 2011
 *      Author: agis
 */

#include "shapes.h"

// just a function that gives the x,y coordinates of a slice of a circle
void _discrete2dCircle( float r, int slices, int selectedSlice, float& x, float& y )
{
	x = r*cos( 2*PI*selectedSlice/(float)slices );
	y = r*sin( 2*PI*selectedSlice/(float)slices );
}

// solid sphere implementation. Stacks are stashed along the z-axis. Slices are on the xy plane.
void cg_SolidSphere( GLint slices, GLint stacks)
{
	for ( int i=0; i<stacks; i++ )
		{
			float currR = sin( PI/(float)stacks*i );
			float nextR = sin( PI/(float)stacks*(i+1) );

			float currZ = cos( PI/(float)stacks*i );
			float nextZ = cos( PI/(float)stacks*(i+1) );

			glBegin( GL_QUAD_STRIP );
			glColor3f( 0.5, 0.2, 0.2 );
			for ( int j=0; j<=slices; j++ )
			{
				float lowX, lowY, highX, highY;
				_discrete2dCircle( currR, slices, j, lowX, lowY );
				_discrete2dCircle( nextR, slices, j, highX, highY );

				glVertex3f( lowX, lowY, currZ );
				glVertex3f( highX, highY, nextZ );
			}
			glEnd();
		}
}



void drawFloor(void)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	for ( int i=0; i<=10; i++ )
	{
		float currZ = -10+i*2;
		float nextZ = currZ+2;

		glBegin( GL_QUAD_STRIP );
		glColor3f( 0.6, 0.6, 0.6 );
		for ( int j=0; j<=15; j++ )
		{
			float currX = -15+j*2;
			glVertex3f( currX, 0, currZ );
			glVertex3f( currX, 0, nextZ );
		}
		glEnd();
	}

	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}


void drawTorus()
{
	float innerR = 1.0;
	float outerR = 3.0;

	glPushMatrix();
		glTranslatef( -4.0, 1.0, 0.0 );
		glRotatef( 90, 1, 0, 0 );
		glColor3f( 0.5, 0.5, 1.0 );
		glutSolidTorus ( innerR, outerR, 20, 20 );
	glPopMatrix();
}

void drawBox_Teapot()
{
	float side = 6;

	glPushMatrix();
		glTranslatef( 1.0, 3.0, 4.0 );
		glColor3f( 0.3, 1.0, 0.3 );
		glutSolidCube( side );
		glPushMatrix();
			glTranslatef( 0.0, 5.2, 0.0 );
			glColor3f( 0.3, 0.3, 0.3 );
			glutSolidTeapot( side/2 );
		glPopMatrix();
	glPopMatrix();
}

void drawSphere()
{
	glPushMatrix();
		glTranslatef( 1.0, 3.0, -3.0 );
		glScalef( 1, 3, 1 );
		cg_SolidSphere( 20, 20 );
	glPopMatrix();
}



