/*
 * shapes.cpp
 *
 *  Created on: Oct 9, 2011
 *      Author: agis
 */

#include "shapes.h"
#include "util.h"

// just a function that gives the x,y coordinates of a slice of a circle
void _discrete2dCircle( float r, int slices, int selectedSlice, float& x, float& y )
{
	x = r*cos( 2*PI*selectedSlice/(float)slices );
	y = r*sin( 2*PI*selectedSlice/(float)slices );
}

// solid sphere implementation. Stacks are stashed along the z-axis. Slices are on the xy plane.
// Uses mathematical normal rather than averaging faces



void cg_SolidSphere( GLint slices, GLint stacks)
{

	float * current = new float[3];
	float * next = new float[3];
	float * normal = new float[3];

	for ( int i=0; i<stacks; i++ )
	{
		float currR = sin( PI/(float)stacks*i );
		float nextR = sin( PI/(float)stacks*(i+1) );

		current[2] = cos( PI/(float)stacks*i );
		next[2] = cos( PI/(float)stacks*(i+1) );

		glBegin( GL_QUAD_STRIP );
		glColor3f( 0.5, 0.2, 0.2 );
		for ( int j=0; j<=slices; j++ )
		{
			_discrete2dCircle( currR, slices, j, current[0], current[1] );
			_discrete2dCircle( nextR, slices, j, next[0], next[1] );

			glVertex3fv( current );
			//cg_norm3( current, normal );
			glNormal3fv( current );
			glVertex3fv( next );
			//cg_norm3( next, normal );
			glNormal3fv( next );
		}
		glEnd();
		glFlush();
	}
	delete current;
	delete next;
	delete normal;
}

/* Normalizes in place */
void cg_norm3(float * vertex, float * normal)
{
	float norm = vertex[0]*vertex[0] + vertex[1]*vertex[1] + vertex[2]*vertex[2];

	normal[0] = vertex[0] / norm;
	normal[1] = vertex[1] / norm;
	normal[2] = vertex[2] / norm;

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
			glNormal3f( 0, 1, 0);
			glVertex3f( currX, 0, nextZ );
			glNormal3f( 0, 1, 0);
		}
		glEnd();
	}

	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}


void drawTorus()
{
	float innerR = 1.0;
	float outerR = 3.0;
	GLfloat specs[] = {0,0,0,1};
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specs);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 0);
	glPushMatrix();
		glTranslatef( -4.0, 1.0, 0.0 );
		glRotatef( 90, 1, 0, 0 );
		glColor3f( 0.5, 0.5, 1.0 );
		glutSolidTorus ( innerR, outerR, 20, 20 );
	glPopMatrix();
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, exponent);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specs);
	/* This is all same as default but it's just a good habit*/
}

void drawBox_Teapot()
{
	float side = 6;
	float glow[] = {0.0,0.0,0.0,0};
	float defaults[] = {0,0,0,1};
	glPushMatrix();
		glTranslatef( 1.0, 3.0, 4.0 );
		glColor3f( 0.3, 1.0, 0.3 );
		glutSolidCube( side );
		glPushMatrix();
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, glow);
			glTranslatef( 0.0, 5.2, 0.0 );
			glColor3f( 0.3, 0.3, 0.3 );
			glutSolidTeapot( side/2 );
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, defaults);
		glPopMatrix();
	glPopMatrix();
}

void drawSphere()
{
	float specular[] = {1,1,1,1};
	float defaultSpecular[] = {0.0,0.0,0.0,1};
	//glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, exponent);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glPushMatrix();
		glTranslatef( 1.0, 3.0, -3.0 );
		glScalef( 1, 3, 1 );
		cg_SolidSphere( 60, 20 );
	glPopMatrix();
	//glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, 1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, defaultSpecular);
}




