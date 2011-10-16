#include "menu.h"

void createMenu(void){

  int lights_id = glutCreateMenu(menu);
  glutAddMenuEntry( "Lights on", LIGHTS_ON );
  glutAddMenuEntry( "Lights off", LIGHTS_OFF );

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
		case LIGHTS_ON:
			lightsOn();
			break;
		case LIGHTS_OFF:
			lightsOff();
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

void lightsOn()
{
	glDisable(GL_LIGHT0);

	GLfloat light_ambient1[] = { 0.05, 0.05, 0.05, 1.0 };
	GLfloat light_diffuse1[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position1[] = { 0, 10000, 0 };
	GLfloat light_specular1[] = { 1.0, 1.0, 1.0, 1.0 };

	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

	GLfloat light_ambient2[] = { 0.1, 0.00, 0.00, 1.0 };
	GLfloat light_diffuse2[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular2[] = { 1.0, 0, 1.0, 1.0 };
	GLfloat light_position2[] = { 0, 10000, 0 };

	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse2);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position2);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
}

void lightsOff()
{
	glDisable(GL_LIGHTING);
}

