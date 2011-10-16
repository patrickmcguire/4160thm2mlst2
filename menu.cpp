#include "menu.h"

void createMenu(void){

  int lights_id = glutCreateMenu(menu);
  glutAddMenuEntry( "Light one", LIGHT_ONE );
  glutAddMenuEntry( "Light two", LIGHT_TWO );

  int shading_id = glutCreateMenu(menu);
  glutAddMenuEntry( "Flat shading", FLAT_SHADING );
  glutAddMenuEntry( "Smooth shading", SMOOTH_SHADING );

  int menu_id = glutCreateMenu(menu);
  glutAddSubMenu("Lights", lights_id);
  glutAddSubMenu("Shading", shading_id);

  // Let the menu respond on the right mouse button
  glutAttachMenu( GLUT_LEFT_BUTTON );

}

void menu(int value)
{
	switch( value )
	{
		case LIGHT_ONE:
			lightOne();
			break;
		case LIGHT_TWO:
			lightTwo();
			break;
		case FLAT_SHADING:
			glShadeModel( GL_FLAT );
			break;
		case SMOOTH_SHADING:
			glShadeModel( GL_SMOOTH );
			break;
		default:
			break;
	}
  // you would want to redraw now
  glutPostRedisplay();
}

void lightOne()
{
	if(l1)
	{
		glDisable( GL_LIGHT0 );
		l1 = false;
	}
	else
	{
		glEnable(GL_LIGHT0);
		l1 = true;
	}
}

void lightTwo()
{
	if(l2)
	{
		glDisable( GL_LIGHT1 );
		l2 = false;
	}
	else
	{
		glEnable(GL_LIGHT1);
		l2 = true;
	}
}

void lightsOff()
{
	glDisable(GL_LIGHTING);
}

