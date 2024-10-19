#include <GL/glut.h> // (or others, depending on the system in use)
#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>
#include <stdlib.h> 
#include <windows.h>

GLfloat tangle = 1.0f;

int adamileri = 0;

int starsize = 0;
//int tangle = 0;

void init(void)
{
	glClearColor(0.5, 0.8, 1, 0); // Set display-window color to white.
	glMatrixMode(GL_PROJECTION); // Set projection parameters.
	gluOrtho2D(0.0, 600, 0.0, 200);
	glEnable(GL_COLOR_MATERIAL);
}
//void colorfill(float x, float y)
void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}
void drawCircle(float r, float x, float y) {
	float i = 0.0f;

	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(x, y); // Center
	for (i = 0.0f; i <= 360; i++)
		glVertex2f(r * cos(M_PI * i / 180.0) + x, r * sin(M_PI * i / 180.0) + y);

	glEnd();
}
void circleoutline(float cx, float cy, float r, int num_segments) {
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++) {
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
}
void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(10,timer, 0);
	tangle += 1;
	if (tangle > 360) {
		tangle = 0;
	}


}
	void lineSegment(void)
{

	glColor3ub(153, 255, 255);
	glRecti(0, 150, 600, 200);

	glColor3ub(0, 153, 0);
	glRecti(0, 0, 600, 150);

	glColor3ub(51, 153, 255);
	glRecti(0, 50, 600, 100);

	
	//glClear(GL_COLOR_BUFFER_BIT); // Clear display window.
	glColor3f(0, 0, 0);// Set line segment color to black.
	glBegin(GL_LINES);
	glVertex2i(600, 50); // Specify line-segment geometry.
	glVertex2i(0, 50);

	glVertex2i(600, 100); // Specify line-segment geometry.
	glVertex2i(0, 100);

	glVertex2i(600, 150); // Specify line-segment geometry.
	glVertex2i(0, 150);

	glEnd();

	
	glColor3ub(255, 178, 102);//bot
	glRecti(50 , 120, 90 , 180);//ev


	//BOT /////////////////////////////////////////////////////////////////

	

	glPushMatrix();
	glTranslatef(adamileri, 0, 0);
	
	glBegin(GL_QUADS);


	glColor3ub(204, 204, 0);

	glVertex2i(100, 90);//bot
	glVertex2i(120, 70);
	glVertex2i(160, 70);
	glVertex2i(180, 90);

	glEnd();
	//glLoadIdentity();
	
	
	
	
	glColor3ub(255, 255, 255);
	drawCircle(5, 140 , 110);
	
	
	
	glRecti(135, 90, 145 , 105);//adam govde
	
	
	glLineWidth(2);
	glColor3ub(0, 0, 0);
	circleoutline(140 , 110, 5, 360);

	
	
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0);

	glVertex2i(135 , 90); // tekne adam cizgi.
	glVertex2i(135, 105);
	glVertex2i(145 , 105); // Specify line-segment geometry.
	glVertex2i(145 , 90);
	
	glEnd();
	glFlush();
	glPopMatrix();
	
	
	////////////////////////////////////////////////////////////////////
	//yildizlar

	

	glColor3ub(255, 255, 51);  //yildiz3
	glRecti(300 - starsize, 170 + starsize, 305+ starsize, 165 - starsize);
	glRecti(315 - starsize, 180 + starsize, 320 + starsize, 175 - starsize);
	glRecti(305 - starsize, 180 + starsize, 310 + starsize, 175 - starsize);
	glRecti(335 - starsize, 185 - starsize, 340 + starsize, 190 + starsize);
	glRecti(315 - starsize, 190 - starsize, 320 + starsize, 195 + starsize);

	

	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0);

	glVertex2i(300 - starsize, 170 + starsize); // Specify line-segment geometry.
	glVertex2i(300 - starsize, 165 - starsize);
	glVertex2i(305 + starsize, 165 - starsize); // Specify line-segment geometry.
	glVertex2i(305 + starsize, 170 + starsize);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glVertex2i(315 - starsize, 180 + starsize); // Specify line-segment geometry.
	glVertex2i(315 - starsize, 175 - starsize);
	glVertex2i(320 + starsize, 175 - starsize); // Specify line-segment geometry.
	glVertex2i(320 + starsize, 180 + starsize);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glVertex2i(305 - starsize, 180 + starsize); // Specify line-segment geometry.
	glVertex2i(305 - starsize, 175 - starsize);
	glVertex2i(310 + starsize, 175 - starsize); // Specify line-segment geometry.
	glVertex2i(310 + starsize, 180 + starsize);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glVertex2i(315 - starsize, 190 - starsize); // Specify line-segment geometry.
	glVertex2i(315 - starsize, 195 + starsize);
	glVertex2i(320 + starsize, 195 + starsize); // Specify line-segment geometry.
	glVertex2i(320 + starsize, 190 - starsize);

	glEnd();

	glBegin(GL_LINE_LOOP);

	glVertex2i(335 - starsize, 185 - starsize); // Specify line-segment geometry.
	glVertex2i(335 - starsize, 190 + starsize);
	glVertex2i(340 + starsize, 190 + starsize); // Specify line-segment geometry.
	glVertex2i(340 + starsize, 185 - starsize);

	glEnd();
	

	int shinecount =0;

	bool parla = false;
	for (int i = 3; i > 0; i--) {

		starsize = 0;
		

		
		int index = i * 40;
		glColor3ub(0, 102, 51);
		glRecti(index + 390, 125, index + 410, 145);

		glColor3ub(102, 102, 0);
		glRecti(index + 395, 110, index + 405, 125);

	
		if (300 + index > 180 + adamileri) {
			starsize =0 ;
			glColor3ub(255-i*30, 0, 0);
			drawCircle(10, 300 + index, 80); //340 380 420


		}
		 if (300 + index == 180 + adamileri) {
			parla = true;
			
		
			
		}

		
	}
	if (parla) {  //bot topa vurdugunda parla
		starsize = 1;

	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	glTranslatef(70, 175, 0);
	glRotatef(tangle, 0, 0, -1);
	glTranslatef(-70, -175, 0.0);
	




	glBegin(GL_TRIANGLES);

	glColor3ub(127, 0, 255);
	glVertex2f(40, 160);
	glVertex2f(100, 160);
	glVertex2f(70, 190);

	glEnd();
	glPopMatrix();
	glutSwapBuffers();





	glFlush(); 
	
	// Process all OpenGL routines as quickly as possible.
}
void keybrd(GLubyte key, GLint xmouse, GLint ymouse) {
	switch (key) {

	case 'x': { exit(0);

	}
	case 'r': { 
		adamileri += 10;
		glutPostRedisplay();
		
		break;

	}
	
	case 'b': { 
		starsize += 1;
		printf("%d ", starsize);
		
		
		break;

		
	}
	
	case 'k': { 
		starsize -= 1;
		printf("%d ", starsize);
	
		break;
	}
	default:
		break;
	}
	
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initialize GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode.
	glutInitWindowPosition(0, 0); // Set top-left display-window position.
	glutInitWindowSize(1600, 600); // Set display-window width and height.
	glutCreateWindow("An Example OpenGL "); // Create display window.
	 // Execute initialization procedure.
	
	glutDisplayFunc(lineSegment); // Send graphics to display window.
		
	glutTimerFunc(1, timer, 0);
	init();
	glutMainLoop(); // Display everything and wait.
}