#include <stdlib.h> 
#include <math.h> // math definitions\par
#include <stdio.h> // standard I/O\par
//par
// include files are in a slightly different location for MacOS\par#include <GLUT/glut.h>
#include <GL/glut.h>


// escape key (for exit)\par
#define ESC 27/*\par
\par*/
//----------------------------------------------------------------------\par
// Global variables\par
//\par
// The coordinate system is set up so that the (x,y)-coordinate plane\par
// is the ground, and the z-axis is directed upwards. The y-axis points\par
// to the north and the x-axis points to the east.\par
//\par
// The values (x,y) are the current camera position. The values (lx, ly)\par
// point in the direction the camera is looking. The variables angle and\par
// deltaAngle control the camera's angle. The variable deltaMove\par
// indicates the amount of incremental motion for the camera with each\par
// redraw cycle. The variables isDragging and xDragStart are used to\par
// monitor the mouse when it drags (with the left button down).\par
//----------------------------------------------------------------------\par

// Camera position\par
float x = 0.0, y = -5.0; // initially 5 units south of origin\par
float deltaMove = 0.0; 
// initially camera doesn't move\par

// Camera direction\par
float lx = 0.0, ly = 1.0; // camera points initially along y-axis\par
float angle = 0.0; // angle of rotation for the camera direction\par
float deltaAngle = 0.0; // additional angle change when dragging\par

// Mouse drag control\par
int isDragging = 0; // true when dragging\par
int xDragStart = 0; // records the x-coordinate when dragging starts\par

//----------------------------------------------------------------------\par
// Reshape callback\par
//\par
// Window size has been set/changed to w by h pixels. Set the camera\par
// perspective to 45 degree vertical field of view, a window aspect\par
// ratio of w/h, a near clipping plane at depth 1, and a far clipping\par
// plane at depth 100. The viewport is the entire window.\par
//\par
//----------------------------------------------------------------------\par
void changeSize(int w, int h) 
{
 float ratio =  ((float) w) / ((float) h); // window aspect ratio\par
 glMatrixMode(GL_PROJECTION); // projection matrix is active\par
 glLoadIdentity(); // reset the projection\par
 gluPerspective(45.0, ratio, 0.1, 100.0); // perspective transformation\par
 glMatrixMode(GL_MODELVIEW); // return to modelview mode\par
 glViewport(0, 0, w, h); // set viewport (drawing area) to entire window\par
}

//----------------------------------------------------------------------\par
// Draw one snowmen (at the origin)\par
//\par
// A snowman consists of a large body sphere and a smaller head sphere.\par
// The head sphere has two black eyes and an orange conical nose. To\par
// better create the impression they are sitting on the ground, we draw\par
// a fake shadow, consisting of a dark circle under each.\par
//\par
// We make extensive use of nested transformations. Everything is drawn\par
// relative to the origin. The snowman's eyes and nose are positioned\par
// relative to a head sphere centered at the origin. Then the head is\par
// translated into its final position. The body is drawn and translated\par
// into its final position.\par
//----------------------------------------------------------------------\par
void drawSnowman()
{
 // Draw body (a 20x20 spherical mesh of radius 0.75 at height 0.75)\par
 glColor3f(1.0, 1.0, 1.0); // set drawing color to white\par
 glPushMatrix();
 glTranslatef(0.0, 0.0, 0.75);
glutSolidSphere(0.75, 20, 20);
glPopMatrix();

 // Draw the head (a sphere of radius 0.25 at height 1.75)\par
 glPushMatrix();
glTranslatef(0.0, 0.0, 1.75); // position head\par
glutSolidSphere(0.25, 20, 20); // head sphere\par
//\par
 // Draw Eyes (two small black spheres)\par
glColor3f(0.0, 0.0, 0.0); // eyes are black\par
glPushMatrix();
glTranslatef(0.0, -0.18, 0.10); // lift eyes to final position\par
glPushMatrix();
glTranslatef(-0.05, 0.0, 0.0);
glutSolidSphere(0.05, 10, 10); // right eye\par
glPopMatrix();
glPushMatrix();
glTranslatef(+0.05, 0.0, 0.0);
glutSolidSphere(0.05, 10, 10); // left eye\par
glPopMatrix();
glPopMatrix();

// Draw Nose (the nose is an orange cone)\par
 glColor3f(1.0, 0.5, 0.5); // nose is orange\par
 glPushMatrix();
 glRotatef(90.0, 1.0, 0.0, 0.0); // rotate to point along -y\par
 glutSolidCone(0.08, 0.5, 10, 2); // draw cone\par
 glPopMatrix();//par
 glPopMatrix();//par

 // Draw a faux shadow beneath snow man (dark green circle)\par
 glColor3f(0.0, 0.5, 0.0);
 glPushMatrix();
 glTranslatef(0.2, 0.2, 0.001); // translate to just above ground\par
 glScalef(1.0, 1.0, 0.0); // scale sphere into a flat pancake\par
 glutSolidSphere(0.75, 20, 20); // shadow same size as body\par
 glPopMatrix();
}
//----------------------------------------------------------------------\par
// Update with each idle event\par
//\par
// This incrementally moves the camera and requests that the scene be\par
// redrawn.\par
//----------------------------------------------------------------------\par
void update(void)
{
	if (deltaMove) 
	{
 x += deltaMove * lx * 0.1;
 y += deltaMove * ly * 0.1;
}
 glutPostRedisplay(); // redisplay everything\par}\par
}
void drawSnowman1()
{
 // Draw body (a 20x20 spherical mesh of radius 0.75 at height 0.75)\par
 glColor3f(1.0,0.0, 0.0); // set drawing color to white\par
 glPushMatrix();
 glTranslatef(0.0, 0.0, 0.75);
glutSolidSphere(0.75, 20, 20);
glPopMatrix();

 // Draw the head (a sphere of radius 0.25 at height 1.75)\par
 glPushMatrix();
glTranslatef(0.0, 0.0, 1.75); // position head\par
glutSolidSphere(0.25, 20, 20); // head sphere\par
//\par
 // Draw Eyes (two small black spheres)\par
glColor3f(0.0, 0.0, 0.0); // eyes are black\par
glPushMatrix();
glTranslatef(0.0, -0.18, 0.10); // lift eyes to final position\par
glPushMatrix();
glTranslatef(-0.05, 0.0, 0.0);
glutSolidSphere(0.05, 10, 10); // right eye\par
glPopMatrix();
glPushMatrix();
glTranslatef(+0.05, 0.0, 0.0);
glutSolidSphere(0.05, 10, 10); // left eye\par
glPopMatrix();
glPopMatrix();

// Draw Nose (the nose is an orange cone)\par
 glColor3f(1.0, 0.5, 0.5); // nose is orange\par
 glPushMatrix();
 glRotatef(90.0, 1.0, 0.0, 0.0); // rotate to point along -y\par
 glutSolidCone(0.08, 0.5, 10, 2); // draw cone\par
 glPopMatrix();//par
 glPopMatrix();//par

 // Draw a faux shadow beneath snow man (dark green circle)\par
 glColor3f(0.0, 0.5, 0.0);
 glPushMatrix();
 glTranslatef(0.2, 0.2, 0.001); // translate to just above ground\par
 glScalef(1.0, 1.0, 0.0); // scale sphere into a flat pancake\par
 glutSolidSphere(0.75, 20, 20); // shadow same size as body\par
 glPopMatrix();
}

void drawSnowman2()
{
 // Draw body (a 20x20 spherical mesh of radius 0.75 at height 0.75)\par
 glColor3f(0.0,0.0, 1.0); // set drawing color to white\par
 glPushMatrix();
 glTranslatef(0.0, 0.0, 0.75);
glutSolidSphere(0.75, 20, 20);
glPopMatrix();

 // Draw the head (a sphere of radius 0.25 at height 1.75)\par
 glPushMatrix();
glTranslatef(0.0, 0.0, 1.75); // position head\par
glutSolidSphere(0.25, 20, 20); // head sphere\par
//\par
 // Draw Eyes (two small black spheres)\par
glColor3f(0.0, 0.0, 0.0); // eyes are black\par
glPushMatrix();
glTranslatef(0.0, -0.18, 0.10); // lift eyes to final position\par
glPushMatrix();
glTranslatef(-0.05, 0.0, 0.0);
glutSolidSphere(0.05, 10, 10); // right eye\par
glPopMatrix();
glPushMatrix();
glTranslatef(+0.05, 0.0, 0.0);
glutSolidSphere(0.05, 10, 10); // left eye\par
glPopMatrix();
glPopMatrix();

// Draw Nose (the nose is an orange cone)\par
 glColor3f(1.0, 0.5, 0.5); // nose is orange\par
 glPushMatrix();
 glRotatef(90.0, 1.0, 0.0, 0.0); // rotate to point along -y\par
 glutSolidCone(0.08, 0.5, 10, 2); // draw cone\par
 glPopMatrix();//par
 glPopMatrix();//par

 // Draw a faux shadow beneath snow man (dark green circle)\par
 glColor3f(0.0, 0.5, 0.0);
 glPushMatrix();
 glTranslatef(0.2, 0.2, 0.001); // translate to just above ground\par
 glScalef(1.0, 1.0, 0.0); // scale sphere into a flat pancake\par
 glutSolidSphere(0.75, 20, 20); // shadow same size as body\par
 glPopMatrix();
}
//----------------------------------------------------------------------\par
// Update with each idle event\par
//\par
// This incrementally moves the camera and requests that the scene be\par
// redrawn.\par
//----------------------------------------------------------------------\pa
//----------------------------------------------------------------------\par
// Draw the entire scene\par
//\par
// We first update the camera location based on its distance from the\par
// origin and its direction.\par
//----------------------------------------------------------------------\par
void renderScene(void) 
{
 int i, j;

 // Clear color and depth buffers\par
 glClearColor(0.0, 0.7, 1.0, 1.0); // sky color is light blue\par
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 // Reset transformations\par
 glLoadIdentity();

 // Set the camera centered at (x,y,1) and looking along directional\par
 // vector (lx, ly, 0), with the z-axis pointing up\par
 gluLookAt(
  x,      y,      1.0,
 x + lx, y + ly, 1.0,
 0.0,    0.0,    1.0);

 // Draw ground - 200x200 square colored green\par
 glColor3f(0.0, 0.7, 0.0);
 glBegin(GL_QUADS);
glVertex3f(-100.0, -100.0, 0.0);
 glVertex3f(-100.0,  100.0, 0.0);
 glVertex3f( 100.0,  100.0, 0.0);
 glVertex3f( 100.0, -100.0, 0.0);
 glEnd();

 // Draw 36 snow men\par
 for(i = -3; i < 3; i++)
 for(j = -3; j < 3; j++) {
 glPushMatrix();
 glTranslatef(i*7.5, j*7.5, 0);
 drawSnowman();
 glPopMatrix();
}
 glutSwapBuffers(); // Make it all visible\par} \par
}
void renderScene2(void) 
{
 int i, j;

 // Clear color and depth buffers\par
 glClearColor(0.0, 0.7, 1.0, 1.0); // sky color is light blue\par
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 // Reset transformations\par
 glLoadIdentity();

 // Set the camera centered at (x,y,1) and looking along directional\par
 // vector (lx, ly, 0), with the z-axis pointing up\par
 gluLookAt(
  x,      y,      1.0,
 x + lx, y + ly, 1.0,
 0.0,    0.0,    1.0);

 // Draw ground - 200x200 square colored green\par
 glColor3f(0.0, 0.7, 0.0);
 glBegin(GL_QUADS);
glVertex3f(-100.0, -100.0, 0.0);
 glVertex3f(-100.0,  100.0, 0.0);
 glVertex3f( 100.0,  100.0, 0.0);
 glVertex3f( 100.0, -100.0, 0.0);
 glEnd();

 // Draw 36 snow men\par
 for(i = -3; i < 3; i++)
 for(j = -3; j < 3; j++) {
 glPushMatrix();
 glTranslatef(i*7.5, j*7.5, 0);
 drawSnowman2();
 glPopMatrix();
}
 glutSwapBuffers(); // Make it all visible\par} \par
}

void renderScene1(void) 
{
 int i, j;

 // Clear color and depth buffers\par
 glClearColor(0.0, 0.7, 1.0, 1.0); // sky color is light blue\par
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 // Reset transformations\par
 glLoadIdentity();

 // Set the camera centered at (x,y,1) and looking along directional\par
 // vector (lx, ly, 0), with the z-axis pointing up\par
 gluLookAt(
  x,      y,      1.0,
 x + lx, y + ly, 1.0,
 0.0,    0.0,    1.0);

 // Draw ground - 200x200 square colored green\par
 glColor3f(0.0, 0.7, 0.0);
 glBegin(GL_QUADS);
glVertex3f(-100.0, -100.0, 0.0);
 glVertex3f(-100.0,  100.0, 0.0);
 glVertex3f( 100.0,  100.0, 0.0);
 glVertex3f( 100.0, -100.0, 0.0);
 glEnd();

 // Draw 36 snow men\par
 for(i = -3; i < 3; i++)
 for(j = -3; j < 3; j++) {
 glPushMatrix();
 glTranslatef(i*7.5, j*7.5, 0);
 drawSnowman1();
 glPopMatrix();
}
 glutSwapBuffers(); // Make it all visible\par} \par
}

//----------------------------------------------------------------------\par
// User-input callbacks\par
//\par
// processNormalKeys: ESC, q, and Q cause program to exit\par
// pressSpecialKey: Up arrow = forward motion, down arrow = backwards\par
// releaseSpecialKey: Set incremental motion to zero\par
//----------------------------------------------------------------------\par
void processNormalKeys(unsigned char key, int xx, int yy)
{
if (key == ESC || key == 'q' || key == 'Q') exit(0);
}

void pressSpecialKey(int key, int xx, int yy)
{
 switch (key) {
 case GLUT_KEY_UP : deltaMove = 1.0; break;
 case GLUT_KEY_DOWN : deltaMove = -1.0; break;
}
} 

void releaseSpecialKey(int key, int x, int y) 
{
 switch (key) {
 case GLUT_KEY_UP : deltaMove = 0.0; break;
 case GLUT_KEY_DOWN : deltaMove = 0.0; break;
}
} 

//----------------------------------------------------------------------\par
// Process mouse drag events\par
// \par
// This is called when dragging motion occurs. The variable\par
// angle stores the camera angle at the instance when dragging\par
// started, and deltaAngle is a additional angle based on the\par
// mouse movement since dragging started.\par
//----------------------------------------------------------------------\par
void mouseMove(int x, int y) 
{ 
 if (isDragging) { // only when dragging\par
// update the change in angle\par
deltaAngle = (x - xDragStart) * 0.005;

 // camera's direction is set to angle + deltaAngle\par
 lx = -sin(angle + deltaAngle);
ly = cos(angle + deltaAngle);
}
}

void mouseButton(int button, int state, int x, int y) 
{
 if (button == GLUT_LEFT_BUTTON) {
 if (state == GLUT_DOWN) { // left mouse button pressed\par
 isDragging = 1; // start dragging\par
 xDragStart = x; // save x where button first pressed\par
}
 else  { /* (state = GLUT_UP) */
 angle += deltaAngle; // update camera turning angle\par
 isDragging = 0; // no longer dragging\par
}
}
}


void demo_menu(int id)
{
	switch(id)
	{
	case 1:exit(0);
			break;

	case 2:renderScene1();
		glutDisplayFunc(renderScene1); 
			break;

	case 3:renderScene2();
		glutDisplayFunc(renderScene2); 
			break;

	case 4:renderScene();
		glutDisplayFunc(renderScene); 
			break;

	}
}





//----------------------------------------------------------------------\par
// Main program  - standard GLUT initializations and callbacks\par
//----------------------------------------------------------------------\par
int main(int argc, char **argv) 
{
/*	printf("\\n\\\par
-----------------------------------------------------------------------\\n\\\par
  OpenGL Sample Program:\\n\\\par
  - Drag mouse left-right to rotate camera\\n\\\par
  - Hold up-arrow/down-arrow to move camera forward/backward\\n\\\par
  - q or ESC to quit\\n\\\par
-----------------------------------------------------------------------\\n");\par

 // general initializations\par  */
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
 glutInitWindowPosition(100, 100);
 glutInitWindowSize(800, 400);
 glutCreateWindow("OpenGL/GLUT Sampe Program");



 // register callbacks\par
 glutReshapeFunc(changeSize); // window reshape callback\par
 glutDisplayFunc(renderScene); // (re)display callback\par

 glEnable(GL_FOG);
 float color[]={0.5,0.5,0.5,1.0};
 glFogfv(GL_FOG_COLOR,color);
 glFogi(GL_FOG_MODE,GL_LINEAR);
 glFogf(GL_FOG_START,6.00);
 glFogf(GL_FOG_END,8.50);

 glutCreateMenu(demo_menu);
 glutAddMenuEntry("quit",1);
 glutAddMenuEntry("red",2);
 glutAddMenuEntry("blue",3);
 glutAddMenuEntry("white",4);
 glutAttachMenu(GLUT_RIGHT_BUTTON);

 glutIdleFunc(update); // incremental update \par
 glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down\par
 glutMouseFunc(mouseButton); // process mouse button push/release\par
 glutMotionFunc(mouseMove); // process mouse dragging motion\par
 glutKeyboardFunc(processNormalKeys); // process standard key clicks\par
 glutSpecialFunc(pressSpecialKey); // process special key pressed\par
 // Warning: Nonstandard function! Delete if desired.\par
 glutSpecialUpFunc(releaseSpecialKey); // process special key release\par

 // OpenGL init\par
 glEnable(GL_DEPTH_TEST);

 // enter GLUT event processing cycle\par
 glutMainLoop();
 return 0; // this is just to keep the compiler happy\par
}

 