#include <iostream>
using namespace std;
#include <windows.h>  // for MS Windows
#include<mmsystem.h>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<stdio.h>
#include<math.h>>
#include <GL/gl.h>
#include <GL/glu.h>
# define PI           3.14159265358979323846
int triangleAmount = 100;
GLfloat twicePi = 2.0f * PI;
int i;
int lineAmount = 100;
void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-10.0,10.0);
}
void Idle()
{
    glutPostRedisplay();
}
void renderBitmapString(float x, float y, float z, void *font, char *string)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void drawEllipse(float centerX, float centerY, float radiusX, float radiusY, int numSegments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radiusX * cosf(theta);
        float y = radiusY * sinf(theta);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();
}
void drawEllipse1(float centerX, float centerY, float radiusX, float radiusY, int numSegments) {
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radiusX * cosf(theta);
        float y = radiusY * sinf(theta);
        glVertex2f(centerX + x, centerY + y);
    }
    glEnd();

}


GLfloat Tspeed = 0.0;
GLfloat Dspeed = 0.0;
GLfloat TPosition = 0.0;
GLfloat DPosition = 0.0;
GLfloat pika = 0.0f;
GLfloat pikaa = 0.0f;
GLfloat pikaaa = 0.0f;
GLfloat speedpi = 0.001f;
GLfloat twicePii = 2.0f * PI;

GLfloat j = 0.0f;
GLfloat l = 0.0f;
GLfloat k = 0.0f;
float objectp = 0.0f;
float directionp = 1.0f;


GLfloat meteorP1=0.0; GLfloat meteorP2=0.0;
GLfloat meteorS1=0.05;GLfloat meteorS2=0.03;

void meteorUp(int value){
       if(meteorP1 < -1.0)
        meteorS1 = 0.5f;

        if(meteorP2 > 1.0)
        meteorS2 = 0.0f;

         meteorP1 -= meteorS1;
         meteorP2 += meteorS2;

	glutPostRedisplay();
	glutTimerFunc(100, meteorUp, 0);

}

void updatep(int value) {
    // Update the object's Y position
    objectp += 0.005f * directionp; // Adjust the value for desired speed

    // Reverse the direction when the object reaches the top or bottom
    if (objectp >= 0.01f || objectp <= 0.0f) {
        directionp *= -1.0f;
    }

    glutPostRedisplay(); // Trigger a display update
    glutTimerFunc(16, updatep, 0); // Call the update function every 16ms (approximately 60fps)
}

void star1()
{
    ///STAR1
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(1.10f,4.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

}

void star2()
{
    ///STAR 2
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(1.60f,6.00f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 5
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(3.40f,4.f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();
}


void display3()
{
    glClearColor(0.11f, 0.271f, 0.49f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

///........................................................full screen................................................................................................
    glBegin(GL_QUADS);

    glColor3f(0.114f, 0.388f, 0.588f);
    glVertex2f(0.0f,0.0f);
    glColor3f(0.102f, 0.075f, 0.235f);
    glVertex2f(0.0f,1.0f);
    glColor3f(0.102f, 0.075f, 0.235f);
    glVertex2f(1.0f,1.0f);
    glColor3f(0.722f, 0.875f, 0.961f);
    glVertex2f(1.0f,0.0f);
    glEnd();

        glPointSize(1.5);
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.10f, 0.99f);
    glVertex2f(0.05f, 0.50f);
    glVertex2f(0.15f, 0.75f);
    glVertex2f(0.20f, 0.80f);
    glVertex2f(0.25f, 0.45f);
    glVertex2f(0.30f, 0.67f);
    glVertex2f(0.35f, 0.35f);
    glVertex2f(0.45f, 0.25f);
    glVertex2f(0.55f, 0.30f);
    glVertex2f(0.60f, 0.27f);
    glVertex2f(0.65f, 0.85f);
    glVertex2f(0.70f, 0.33f);
    glVertex2f(0.75f, 0.29f);
    glVertex2f(0.80f, 0.55f);
    glVertex2f(0.85f, 0.37f);
    glVertex2f(0.90f, 0.58f);
    glVertex2f(0.95f, 0.99f);
    glVertex2f(0.02f, 0.81f);
    glVertex2f(0.08f, 0.91f);
    glVertex2f(0.13f, 0.75f);
    glVertex2f(0.28f, 0.77f);
    glVertex2f(0.39f, 0.57f);
    glVertex2f(0.425f,0.86f);
    glVertex2f(0.53f, 0.81f);
    glVertex2f(0.54f, 0.50f);
    glVertex2f(0.535f,0.75f);
    glVertex2f(0.66f, 0.91f);
    glVertex2f(0.73f, 0.75f);
    glVertex2f(0.81f, 0.77f);
    glVertex2f(0.87f, 0.57f);
    glVertex2f(0.92f, 0.86f);
    glVertex2f(0.86f, 0.99f);
    glVertex2f(0.99f, 0.93f);
    glVertex2f(0.24f, 0.99f);
    glVertex2f(0.4f, 0.3f);

    glEnd();

    glPointSize(2.5);
    glBegin(GL_POINTS);
    glVertex2f(0.05f, 0.70f);
    glVertex2f(0.07f, 0.50f);
    glVertex2f(0.02f, 0.80f);
    glVertex2f(0.10f, 0.40f);
    glVertex2f(0.20f, 0.35f);
    glVertex2f(0.26f, 0.66f);
    glVertex2f(0.22f, 0.50f);
    glVertex2f(0.50f, 0.40f);
    glVertex2f(0.67f, 0.60f);
    glVertex2f(0.45f, 0.95f);
    glVertex2f(0.91f, 0.50f);
    glEnd();

    glPushMatrix();
    glTranslatef(meteorP2,meteorP1,0.0f);

    ///Meteor - 1
    glPushMatrix();
    glScalef(.2,.2,0);
	glTranslatef(1.10f,4.10f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(1.0f,1.0f,1.0f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.43f,0.614f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor4f(0.722f,0.718f,0.706f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.48f,0.499f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPopMatrix();

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLfloat A63=0.5f; GLfloat P63=0.5f; GLfloat O63 =0.012f;
    glColor3f(0.945f, 0.663f, 0.165f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A63, P63); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A63 + (O63 * cos(i *  twicePi/ triangleAmount)),
                        P63 + (O63 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Meteor Inside Circle
    GLfloat A64=0.505f; GLfloat P64=0.5045f; GLfloat O64 =0.005f;
    glColor3f(0.965f, 0.859f, 0.518f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A64, P64); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A64 + (O64 * cos(i *  twicePi/ triangleAmount)),
                        P64 + (O64 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();
    k +=0.009f;
    glPopMatrix();


    glPopMatrix();




    star1();

    star2();






    ///STAR 3
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(2.50f,3.20f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 4
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(2.40f,4.6f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();




    ///STAR 6
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(3.30f,6.f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 7
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(5.10f,6.20f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 8
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(4.1f,5.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 9
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(4.50f,2.50f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 10
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(4.50f,6.20f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 11
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(5.15f,3.59f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 12
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(6.2f,4.2f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();


    ///STAR 13
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(5.9f,5.2f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();





    ///.........................................................CLOUD 3RD LAYER.....................................................................................///

 ///circle 1
    GLfloat t30=0.05f, r30=0.24f, radi30 =.04f;

    glColor3f(0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t30, r30);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t30 + (radi30 * cos(i12 *  twicePi / triangleAmount)),
                    r30+ (radi30 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();

     ///circle 2
    GLfloat t31=0.10f, r31=0.28f, radi31 =.05f;

    glColor3f(0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t31, r31);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t31 + (radi31 * cos(i12 *  twicePi / triangleAmount)),
                    r31+ (radi31 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();

     ///circle 3
    GLfloat t32=0.15f, r32=0.25f, radi32 =.03f;

    glColor3f(0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t32, r32);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t32 + (radi32 * cos(i12 *  twicePi / triangleAmount)),
                    r32+ (radi32 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();

     ///circle 4
    GLfloat t33=0.18f, r33=0.21f, radi33 =.03f;

    glColor3f(0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t33, r33);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t33 + (radi33 * cos(i12 *  twicePi / triangleAmount)),
                    r33+ (radi33 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();
     ///circle 5
    GLfloat t34=0.24f, r34=0.22f, radi34=.04f;

    glColor3f(0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t34, r34);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t34 + (radi34 * cos(i12 *  twicePi / triangleAmount)),
                    r34 + (radi34 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();
    ///circle 6
    GLfloat t35=0.30f, r35=0.19f, radi35 =.04f;

    glColor3f(0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t35, r35);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t35 + (radi35 * cos(i12 *  twicePi / triangleAmount)),
                    r35+ (radi35 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();

     ///circle 7
    GLfloat t36=0.36f, r36=0.145f, radi36 =.05f;

    glColor3f(0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t36, r36);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t36 + (radi36 * cos(i12 *  twicePi / triangleAmount)),
                    r36+ (radi36 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 8
    GLfloat t37=0.52f, r37=0.17f, radi37 =.05f;

    glColor3f(0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t37, r37);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t37 + (radi37 * cos(i12 *  twicePi / triangleAmount)),
                    r37+ (radi37 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();
    ///circle 9
    GLfloat t38=0.57f, r38=0.245f, radi38 =.05f;

    glColor3f(0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t38, r38);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t38 + (radi38 * cos(i12 *  twicePi / triangleAmount)),
                    r38+ (radi38 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 10
    GLfloat t39=0.64f, r39=0.21f, radi39 =.04f;

    glColor3f(0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t39, r39);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t39 + (radi39 * cos(i12 *  twicePi / triangleAmount)),
                    r39 + (radi39 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 11
    GLfloat t40=0.66f, r40=0.16f, radi40=.05f;

    glColor3f(0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t40, r40);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t40 + (radi40 * cos(i12 *  twicePi / triangleAmount)),
                    r40 + (radi40 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 12
    GLfloat t41=0.95f, r41=0.33f, radi41=.06f;

    glColor3f(0.388f, 0.463f, 0.733f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t41, r41);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t41 + (radi41 * cos(i12 *  twicePi / triangleAmount)),
                    r41 + (radi41 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.388f, 0.463f, 0.733f);
    glVertex2f(0.05f,0.235f);
    glVertex2f(0.19f,0.235f);
    glVertex2f(0.05f,0.00f);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.388f, 0.463f, 0.733f);
    glVertex2f(0.52f,0.21f);
    glVertex2f(0.52f,0.00f);
    glVertex2f(0.64f,0.0f);
    glVertex2f(0.64f,0.21f);

    glVertex2f(0.05f,0.193f);
    glVertex2f(0.05f,0.00f);
    glVertex2f(0.34f,0.0f);
    glVertex2f(0.34f,0.193);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(0.388f, 0.463f, 0.733f);
    glVertex2f(0.208f,0.197f);
    glEnd();


        ///________________________________Main____________________
    glPushMatrix();
    glTranslatef(0.0f,TPosition,0.0f);
    glTranslatef(0.1f,-0.5f,0.0f);
    ///.......................................Cylinder .................
    glBegin(GL_QUADS);
    ///_______11 Right small rocket Body_____///
    glColor3f(0.196, 0.51, 0.984);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Body_____///
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    glBegin(GL_TRIANGLES);
    ///_______11 Right small rocket Head_____///
    glColor3f(0.98, 0.549, 0.11);
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Head_____///
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
     ///_______11 Right small rocket Body_____///
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.445f,0.39f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.445f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    ///_______12 Left small rocket Body_____///
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    glVertex2f(0.375f,0.39f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.375f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    ///_______11 Right small rocket Head_____///
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Head_____///
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    ///_________ Fire left ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.535,0.340,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    ///_________ Fire Right ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.685,0.340,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    glPopMatrix();

///_____________________________________________ROCKET(START)___________________________________________________///
    ///_________ 1________///
    glPushMatrix();
    glTranslatef(0.0f,DPosition,0.0f);
    glTranslatef(0.1f,-0.5f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.455, 0.525, 0.553);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    ///_________ 2________///
    glColor3f(0.345, 0.416, 0.424);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    ///_________ 3________///
    glColor3f(0.224, 0.49, 0.886);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    ///_________ 4________///
    glColor3f(0.478, 0.537, 0.565);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    ///_________ 5________///
    glColor3f(0.976, 0.475, 0.133);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glColor3f(0.925, 0.431, 0.075);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    ///_________ 6________///
    glColor3f(0.471, 0.529, 0.557);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glColor3f(0.208, 0.247, 0.251);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);

    ///_________ 9________///
    glColor3f(0.588, 0.647, 0.663);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    ///_________ 10________///
    glColor3f(0.976, 0.475, 0.133);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.835, 0.388, 0.09);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    ///_________ Upper and Lower border________///
    ///_______Lower L_____///
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.39f,0.34f);
    glVertex2f(0.39f,0.25f);
    glVertex2f(0.392f,0.25f);
    glVertex2f(0.392f,0.34f);
    ///_______Lower R_____///
    glVertex2f(0.4185f,0.34f);
    glVertex2f(0.4185f,0.25f);
    glVertex2f(0.42f,0.25f);
    glVertex2f(0.42f,0.34f);
    ///_______upper_____///
    glVertex2f(0.372f,0.452f);
    glVertex2f(0.372f,0.449f);
    glVertex2f(0.438f,0.449f);
    glVertex2f(0.438f,0.452f);
    glEnd();
    glBegin(GL_QUADS);
    ///_________ 7(Wing 1)________///
    glColor3f(0.224, 0.494, 0.882);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    ///_________ 8(Wing 2)________///
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glEnd();

    ///_____________________________Rocket TOP window___________________________________///
    ///_________ 11________///
    glColor3f(0.976, 0.482, 0.125);
    GLfloat xrtw1=0.405f; GLfloat yrtw1=0.45f; GLfloat rrtw1 =.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrtw1, yrtw1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.976, 0.482, 0.125);
            glVertex2f( xrtw1 + (rrtw1 * cos(i *  twicePi / triangleAmount)),
                        yrtw1 + (rrtw1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 12________///
    glColor3f(0.314, 0.863, 0.98);
    GLfloat xrtw2=0.405f; GLfloat yrtw2=0.45f; GLfloat rrtw2 =.010f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrtw2, yrtw2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.863, 0.98);
            glVertex2f( xrtw2 + (rrtw2 * cos(i *  twicePi / triangleAmount)),
                        yrtw2 + (rrtw2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket bottom window___________________________________///
    ///_________ 13________///
    glColor3f(0.31, 0.847, 0.973);
    GLfloat xrbw3=0.405f; GLfloat yrbw3=0.30f; GLfloat rrbw3 =.010f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrbw3, yrbw3); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.31, 0.847, 0.973);
            glVertex2f( xrbw3 + (rrbw3 * cos(i *  twicePi / triangleAmount)),
                        yrbw3 + (rrbw3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Mini window___________________________________///
    ///_________ 14________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw1=0.385f; GLfloat yrmw1=0.52f; GLfloat rrmw1 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw1, yrmw1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw1 + (rrmw1 * cos(i *  twicePi / triangleAmount)),
                        yrmw1 + (rrmw1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 15________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw2=0.405f; GLfloat yrmw2=0.52f; GLfloat rrmw2 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw2, yrmw2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw2 + (rrmw2 * cos(i *  twicePi / triangleAmount)),
                        yrmw2 + (rrmw2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 16________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw3=0.425f; GLfloat yrmw3=0.52f; GLfloat rrmw3 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw3, yrmw3); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw3 + (rrmw3 * cos(i *  twicePi / triangleAmount)),
                        yrmw3 + (rrmw3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Border___________________________________///
    ///_________ 1________///
    glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    ///_________ 2________///
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    ///_________ 3________///
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    ///_________ 4________///
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    ///_________ 5________///
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    ///_________ 6________///
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    ///_________ 7(Wing 1)________///
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    ///_________ 8(Wing 2)________///
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    ///_________ 9________///
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    ///_________ 10________///
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glEnd();


    ///_____________________________Rocket TOP window(Border)___________________________________///
    ///_________ 11________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrtwb1=0.405f; GLfloat yrtwb1=0.45f; GLfloat rrtwb1 =.015f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrtwb1, yrtwb1); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrtwb1 + (rrtwb1 * cos(i *  twicePi / lineAmount)),
                        yrtwb1 + (rrtwb1 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
     ///_________ 12________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrtwb2=0.405f; GLfloat yrtwb2=0.45f; GLfloat rrtwb2 =.010f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrtwb2, yrtwb2); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrtwb2 + (rrtwb2 * cos(i *  twicePi / lineAmount)),
                        yrtwb2 + (rrtwb2 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
    ///_____________________________Rocket bottom window(Border)___________________________________///
    ///_________ 13________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrbwb3=0.405f; GLfloat yrbwb3=0.30f; GLfloat rrbwb3 =.010f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrbwb3, yrbwb3); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrbwb3 + (rrbwb3 * cos(i *  twicePi / lineAmount)),
                        yrbwb3 + (rrbwb3 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Mini window(Border)___________________________________///
    ///_________ 14________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb1=0.385f; GLfloat yrmwb1=0.52f; GLfloat rrmwb1 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb1, yrmwb1); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb1 + (rrmwb1 * cos(i *  twicePi / lineAmount)),
                        yrmwb1 + (rrmwb1 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
     ///_________ 15________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb2=0.405f; GLfloat yrmwb2=0.52f; GLfloat rrmwb2 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb2, yrmwb2); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb2 + (rrmwb2 * cos(i *  twicePi / lineAmount)),
                        yrmwb2 + (rrmwb2 * sin(i * twicePi /lineAmount)) );
        }
    glEnd();
     ///_________ 16________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb3=0.425f; GLfloat yrmwb3=0.52f; GLfloat rrmwb3 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb3, yrmwb3); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb3 + (rrmwb3 * cos(i *  twicePi / lineAmount)),
                        yrmwb3 + (rrmwb3 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();

    ///_________ Fire main 1________///
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.20f);
    glVertex2f(0.36f,0.14f);
    glVertex2f(0.388f,0.17f);
    glVertex2f(0.4f,0.12f);
    glVertex2f(0.42f,0.18f);
    glVertex2f(0.45f,0.14f);
    glVertex2f(0.42f,0.20f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.20f);
    glVertex2f(0.38f,0.168f);
    glVertex2f(0.395f,0.19f);
    glVertex2f(0.40f,0.14f);
    glVertex2f(0.41f,0.19f);
    glVertex2f(0.43f,0.17f);
    glVertex2f(0.417f,0.20f);
    glEnd();
    ///_________ Fire main 2________///
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    ///_____________________________________________ROCKET(END)___________________________________________________///


///.........................................................CLOUD 2ND LAYER....................................................................................///

   ///circle 11

    GLfloat t21 =0.07f, r21=0.12f, radi21 =.04f;
    twicePi = 2.0f * PI;

    glColor3f(0.298f, 0.38f, 0.69f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t21, r21); // center of circle
    for(int i1 = 0; i1 <= triangleAmount; i1++)
    {
        glVertex2f( t21 + (radi21 * cos(i1 *  twicePi / triangleAmount)),
                    r21 + (radi21 * sin(i1 * twicePi / triangleAmount)) );
    }
    glEnd();

   ///circle 2

    GLfloat t22=0.15f, r22=0.17, radi22 =.065f;
    twicePi = 2.0f * PI;

    glColor3f(0.298f, 0.38f, 0.69f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t22, r22); // center of circle
    for(int i2 = 0; i2 <= triangleAmount; i2++)
    {
        glVertex2f( t22 + (radi22 * cos(i2 *  twicePi / triangleAmount)),
                    r22 + (radi22 * sin(i2 * twicePi / triangleAmount)) );
    }
    glEnd();

///circle 3

    GLfloat t23=0.15f, r23=0.04f, radi23 =.10f;
    twicePi = 2.0f * PI;

    glColor3f(0.298f, 0.38f, 0.69f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t23, r23); // center of circle
    for(int i3 = 0; i3 <= triangleAmount; i3++)
    {
        glVertex2f( t23 + (radi23 * cos(i3 *  twicePi / triangleAmount)),
                    r23 + (radi23 * sin(i3 * twicePi / triangleAmount)) );
    }
    glEnd();

   ///circle 4

    GLfloat t24=0.23f, r24=0.125f, radi24 =.045f;
    twicePi = 2.0f * PI;

    glColor3f(0.298f, 0.38f, 0.69f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t24, r24); // center of circle
    for(int i4 = 0; i4 <= triangleAmount; i4++)
    {
        glVertex2f( t24 + (radi24 * cos(i4 *  twicePi / triangleAmount)),
                    r24 + (radi24 * sin(i4 * twicePi / triangleAmount)) );
    }
    glEnd();


    ///circle 5

    GLfloat t25=0.26, r25=0.07f, radi25 =.07f;
    glColor3f(0.298f, 0.38f, 0.69f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t25, r25); // center of circle
    for(int i5 = 0; i5 <= triangleAmount; i5++)
    {
        glVertex2f( t25 + (radi25 * cos(i5 *  twicePi / triangleAmount)),
                    r25 + (radi25 * sin(i5 * twicePi / triangleAmount)) );
    }
    glEnd();


    ///circle 6

    GLfloat t26=0.35f, r26=0.07f, radi26 =.05f;
    glColor3f(0.298f, 0.38f, 0.69f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t26, r26); // center of circle
    for(int i6 = 0; i6 <= triangleAmount; i6++)
    {
        glVertex2f( t26 + (radi26 * cos(i6 *  twicePi / triangleAmount)),
                    r26 + (radi26 * sin(i6 * twicePi / triangleAmount)) );
    }
    glEnd();


    ///circle 7
    GLfloat t27=0.60f, r27=0.09f, radi27 =.05f;
    glColor3f(0.298f, 0.38f, 0.69f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t27, r27); // center of circle
    for(int i10 = 0; i10 <= triangleAmount; i10++)
    {
        glVertex2f( t27 + (radi27 * cos(i10 *  twicePi / triangleAmount)),
                    r27 + (radi27 * sin(i10 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 8
    GLfloat t28=0.69f, r28=0.09f, radi28 =.05f;

    glColor3f(0.298f, 0.38f, 0.69f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t28, r28); // center of circle
    for(int i11 = 0; i11 <= triangleAmount; i11++)
    {
        glVertex2f( t28 + (radi28 * cos(i11 *  twicePi / triangleAmount)),
                    r28 + (radi28 * sin(i11 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 9
    GLfloat t29=0.75f, r29=0.16f, radi29 =.07f;
    glColor3f(0.298f, 0.38f, 0.69f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t29, r29);// center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t29 + (radi29 * cos(i12 *  twicePi / triangleAmount)),
                    r29+ (radi29 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();



///.........................................................................initial part.......................................................

    ///circle 1

    GLfloat t =0.0f, r=0.178f, radi =.07f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t, r); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( t + (radi * cos(i *  twicePi / triangleAmount)),
                    r + (radi * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 2

    GLfloat t1 =0.05f, r1=0.09f, radi1 =.05f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t1, r1); // center of circle
    for(int i1 = 0; i1 <= triangleAmount; i1++)
    {
        glVertex2f( t1 + (radi1 * cos(i1 *  twicePi / triangleAmount)),
                    r1 + (radi1 * sin(i1 * twicePi / triangleAmount)) );
    }
    glEnd();

   ///circle 3

    GLfloat t2=0.105f, r2=0.047, radi2 =.03f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t2, r2); // center of circle
    for(int i2 = 0; i2 <= triangleAmount; i2++)
    {
        glVertex2f( t2 + (radi2 * cos(i2 *  twicePi / triangleAmount)),
                    r2 + (radi2 * sin(i2 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 4

    GLfloat t3=0.153f, r3=0.05f, radi3 =.04f;
    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t3, r3); // center of circle
    for(int i3 = 0; i3 <= triangleAmount; i3++)
    {
        glVertex2f( t3 + (radi3 * cos(i3 *  twicePi / triangleAmount)),
                    r3 + (radi3 * sin(i3 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 5

    GLfloat t4=0.19f, r4=0.02f, radi4 =.03f;
    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t4, r4); // center of circle
    for(int i4 = 0; i4 <= triangleAmount; i4++)
    {
        glVertex2f( t4 + (radi4 * cos(i4 *  twicePi / triangleAmount)),
                    r4 + (radi4 * sin(i4 * twicePi / triangleAmount)) );
    }
    glEnd();


   ///circle 6

    GLfloat t5=0.24, r5=0.029f, radi5 =.03f;
    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t5, r5); // center of circle
    for(int i5 = 0; i5 <= triangleAmount; i5++)
    {
        glVertex2f( t5 + (radi5 * cos(i5 *  twicePi / triangleAmount)),
                    r5 + (radi5 * sin(i5 * twicePi / triangleAmount)) );
    }
    glEnd();


    ///circle 7

    GLfloat t6=0.28f, r6=0.010f, radi6 =.025f;
    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t6, r6); // center of circle
    for(int i6 = 0; i6 <= triangleAmount; i6++)
    {
        glVertex2f( t6 + (radi6 * cos(i6 *  twicePi / triangleAmount)),
                    r6 + (radi6 * sin(i6 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 8

    GLfloat t7=0.30f, r7=0.023f, radi7 =.04f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t7, r7); // center of circle
    for(int i7 = 0; i7 <= triangleAmount; i7++)
    {
        glVertex2f( t7 + (radi7 * cos(i7 *  twicePi / triangleAmount)),
                    r7 + (radi7 * sin(i7 * twicePi / triangleAmount)) );
    }
    glEnd();


    ///circle 9

    GLfloat t8=0.35f, r8=0.07f, radi8 =.035f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t8, r8); // center of circle
    for(int i8 = 0; i8 <= triangleAmount; i8++)
    {
        glVertex2f( t8 + (radi8 * cos(i8 *  twicePi / triangleAmount)),
                    r8 + (radi8 * sin(i8 * twicePi / triangleAmount)) );
    }
    glEnd();


    ///circle 10
    GLfloat t9=0.40f, r9=0.10f, radi9 =.035f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t9, r9); // center of circle
    for(int i9 = 0; i9 <= triangleAmount; i9++)
    {
        glVertex2f( t9 + (radi9 * cos(i9 *  twicePi / triangleAmount)),
                    r9 + (radi9 * sin(i9 * twicePi / triangleAmount)) );
    }
    glEnd();


    ///circle 11
    GLfloat t10=0.445f, r10=0.14f, radi10 =.04f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t10, r10); // center of circle
    for(int i10 = 0; i10 <= triangleAmount; i10++)
    {
        glVertex2f( t10 + (radi10 * cos(i10 *  twicePi / triangleAmount)),
                    r10 + (radi10 * sin(i10 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 12
    GLfloat t11=0.49f, r11=0.10f, radi11 =.045f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t11, r11); // center of circle
    for(int i11 = 0; i11 <= triangleAmount; i11++)
    {
        glVertex2f( t11 + (radi11 * cos(i11 *  twicePi / triangleAmount)),
                    r11 + (radi11 * sin(i11 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 13
    GLfloat t12=0.54f, r12=0.06f, radi12 =.03f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t12, r12); // center of circle
    for(int i12 = 0; i12 <= triangleAmount; i12++)
    {
        glVertex2f( t12 + (radi12 * cos(i12 *  twicePi / triangleAmount)),
                    r12 + (radi12 * sin(i12 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 14
    GLfloat t13=0.45f, r13=0.00f, radi13 =.105f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t13, r13); // center of circle
    for(int i13 = 0; i13 <= triangleAmount; i13++)
    {
        glVertex2f( t13 + (radi13 * cos(i13 *  twicePi / triangleAmount)),
                    r13 + (radi13 * sin(i13 * twicePi / triangleAmount)) );
    }
    glEnd();

 ///circle 15
    GLfloat t14=0.595f, r14=0.01f, radi14 =.05f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t14, r14); // center of circle
    for(int i14 = 0; i14 <= triangleAmount; i14++)
    {
        glVertex2f( t14 + (radi14 * cos(i14 *  twicePi / triangleAmount)),
                    r14 + (radi14 * sin(i14 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 16
    GLfloat t15=0.67f, r15=0.03f, radi15 =.05f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t15, r15); // center of circle
    for(int i15 = 0; i15 <= triangleAmount; i15++)
    {
        glVertex2f( t15 + (radi15 * cos(i15 *  twicePi / triangleAmount)),
                    r15 + (radi15 * sin(i15 * twicePi / triangleAmount)) );
    }
    glEnd();

    ///circle 17
   GLfloat t16=0.72f, r16=0.07f, radi16 =.04f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t16, r16); // center of circle
    for(int i16 = 0; i16 <= triangleAmount; i16++)
    {
        glVertex2f( t16 + (radi16 * cos(i16 *  twicePi / triangleAmount)),
                    r16 + (radi16 * sin(i16 * twicePi / triangleAmount)) );
    }
    glEnd();

        ///circle 18
   GLfloat t17=0.76f, r17=0.10f, radi17 =.04f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t17, r17); // center of circle
    for(int i17 = 0; i17 <= triangleAmount; i17++)
    {
        glVertex2f( t17 + (radi17 * cos(i17 *  twicePi / triangleAmount)),
                    r17 + (radi17 * sin(i17 * twicePi / triangleAmount)) );
    }
    glEnd();
       ///circle 19
   GLfloat t18=0.81f, r18=0.17f, radi18 =.055f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t18, r18); // center of circle
    for(int i18 = 0; i18 <= triangleAmount; i18++)
    {
        glVertex2f( t18 + (radi18 * cos(i18 *  twicePi / triangleAmount)),
                    r18 + (radi18 * sin(i18 * twicePi / triangleAmount)) );
    }
    glEnd();

        ///circle 20
   GLfloat t19=0.87, r19=0.20f, radi19 =.04f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t19, r19); // center of circle
    for(int i19 = 0; i19 <= triangleAmount; i19++)
    {
        glVertex2f( t19 + (radi19 * cos(i19 *  twicePi / triangleAmount)),
                    r19 + (radi19 * sin(i19 * twicePi / triangleAmount)) );
    }
    glEnd();

        ///circle 21
   GLfloat t20=0.90f, r20=0.26f, radi20 =.04f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t20, r20); // center of circle
    for(int i20 = 0; i20 <= triangleAmount; i20++)
    {
        glVertex2f( t20 + (radi20 * cos(i20 *  twicePi / triangleAmount)),
                    r20 + (radi20 * sin(i20 * twicePi / triangleAmount)) );
    }
    glEnd();


        ///circle 22
   GLfloat t211=0.95f, r211=0.31f, radi211 =.04f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t211, r211); // center of circle
    for(int i211 = 0; i211 <= triangleAmount; i211++)
    {
        glVertex2f( t211 + (radi211 * cos(i211 *  twicePi / triangleAmount)),
                    r211 + (radi211 * sin(i211 * twicePi / triangleAmount)) );
    }
    glEnd();

        ///circle 23
   GLfloat t221=1.0f, r221=0.37f, radi221 =.05f;

    glColor3f(0.231f, 0.255f, 0.545f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(t221, r221); // center of circle
    for(int i221 = 0; i221 <= triangleAmount; i221++)
    {
        glVertex2f( t221 + (radi221 * cos(i221 *  twicePi / triangleAmount)),
                    r221 + (radi221 * sin(i221 * twicePi / triangleAmount)) );
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.231f, 0.255f, 0.545f);
    glVertex2f(0.65f,0.0f);
    glVertex2f(1.0f,0.35f);
    glVertex2f(1.0f,0.0f);

    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,0.10f);
    glVertex2f(0.20f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.231f, 0.255f, 0.545f);
    glVertex2f(0.20f,0.05f);
    glVertex2f(0.20f,0.00f);
    glVertex2f(0.35f,0.0f);
    glVertex2f(0.35f,0.05f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3f(0.231f, 0.255f, 0.545f);
    glVertex2f(0.0f, 0.105f);
    glEnd();




///..................................SATELLITE.......................................................................................................................
    glPushMatrix();
    glTranslatef(pika,0.0f, 0.0f);
    glLoadIdentity();//Reset the current matrix
    glTranslatef(.95,.10,0);
    glRotatef(j,0.0,0.40,1.0);//i=how many degree you want to rotate around an axis
///body
    glBegin(GL_QUADS);
    glColor3f(0.071f, 0.035f, 0.035f);
    glVertex2f(0.10f,0.60f);
    glColor3f(0.898f,0.898f,0.898f);
    glVertex2f(0.12f,0.60f);
    glColor3f(0.898f,0.898f,0.898f);
    glVertex2f(0.12f,0.65f);
    glColor3f(0.071f, 0.035f, 0.035f);
    glVertex2f(0.10f,0.65f);
///RIGHT WINGS
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.125f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.175f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.175f,0.645f);
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.125f,0.645f);
///LEFT WINGS
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.095f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.045f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.045f,0.645f);
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.095,0.645f);
    glEnd();

///LINES
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    ///BETWEEN BODY
    glVertex2f(0.11f,0.635f);
    glVertex2f(0.12f,0.635f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    ///right
    glVertex2f(0.12f,0.625f);
    glVertex2f(0.125f,0.625f);
    ///left
    glVertex2f(0.10f,0.625f);
    glVertex2f(0.095f,0.625f);
    ///upper
    glVertex2f(0.105f,0.65f);
    glVertex2f(0.105f,0.66f);
    glVertex2f(0.115f,0.65f);
    glVertex2f(0.115f,0.66f);
    ///with mini circle
    glVertex2f(0.11f,0.68f);
    glVertex2f(0.11f,0.69f);

    glVertex2f(0.12f,0.68f);
    glVertex2f(0.11f,0.69f);

    glVertex2f(0.10f,0.68f);
    glVertex2f(0.11f,0.69);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    ///MIDDLE IN RIGHT WINGS
    glVertex2f(0.125f,0.615f);
    glVertex2f(0.175f,0.615f);
    glVertex2f(0.125f,0.625f);
    glVertex2f(0.175f,0.625f);
    glVertex2f(0.125f,0.635f);
    glVertex2f(0.175f,0.635f);
    glVertex2f(0.135f,0.605f);
    glVertex2f(0.135f,0.645f);
    glVertex2f(0.145f,0.605f);
    glVertex2f(0.145f,0.645f);
    glVertex2f(0.155f,0.605f);
    glVertex2f(0.155f,0.645f);
    glVertex2f(0.165f,0.605f);
    glVertex2f(0.165f,0.645f);

    ///MIDDLE LINE IN LEFT WINGS
    glVertex2f(0.095f,0.615f);
    glVertex2f(0.045f,0.615f);
    glVertex2f(0.095f,0.625f);
    glVertex2f(0.045f,0.625f);
    glVertex2f(0.095f,0.635f);
    glVertex2f(0.045f,0.635f);
    glVertex2f(0.055f,0.605f);
    glVertex2f(0.055f,0.645f);
    glVertex2f(0.065f,0.605f);
    glVertex2f(0.065f,0.645f);
    glVertex2f(0.075f,0.605f);
    glVertex2f(0.075f,0.645f);
    glVertex2f(0.085f,0.605f);
    glVertex2f(0.085f,0.645f);
    glEnd();

///mini circle
    GLfloat p=0.11f, k=0.70f, ra=.005;
    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.812f, 0.89f, 0.98f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p, k); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( p + (ra * cos(i *  twicePi / triangleAmount)),
                    k + (ra * sin(i * twicePi / triangleAmount)) );
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glEnd();

    ///HALF CIRCLE
    GLfloat p1=0.11f, k1=0.68f, ra1=.025;
    twicePi= -1.0f *PI;

    glColor3f(0.086f, 0.149f, 0.149f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p1, k1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( p1 + (ra1 * cos(i *  twicePi / triangleAmount)),
                    k1 + (ra1 * sin(i * twicePi / triangleAmount)) );
        glColor3f(0.294f, 0.388f, 0.388f);
    }
    glEnd();

    j+=0.0015f;
    glPopMatrix();

///.............................................SATELLITE 2.......................................................................................///

    glPushMatrix();
    glTranslatef(pika,0.0f, 0.0f);
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.0,0.65,0);
    glPushMatrix();
    glLoadIdentity();//Reset the current matrix
    glTranslatef(-1.15,.10,0);
    glRotatef(l,0.0,0.50,1.0);//i=how many degree you want to rotate around an axis
///body
    glBegin(GL_QUADS);
    glColor3f(0.071f, 0.035f, 0.035f);
    glVertex2f(0.10f,0.60f);
    glColor3f(0.898f,0.898f,0.898f);
    glVertex2f(0.12f,0.60f);
    glColor3f(0.898f,0.898f,0.898f);
    glVertex2f(0.12f,0.65f);
    glColor3f(0.071f, 0.035f, 0.035f);
    glVertex2f(0.10f,0.65f);
///RIGHT WINGS
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.125f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.175f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.175f,0.645f);
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.125f,0.645f);
///LEFT WINGS
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.095f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.045f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.045f,0.645f);
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.095,0.645f);
    glEnd();

///LINES
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    ///BETWEEN BODY
    glVertex2f(0.11f,0.635f);
    glVertex2f(0.12f,0.635f);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    ///right
    glVertex2f(0.12f,0.625f);
    glVertex2f(0.125f,0.625f);

    ///left
    glVertex2f(0.10f,0.625f);
    glVertex2f(0.095f,0.625f);
    ///upper
    glVertex2f(0.105f,0.65f);
    glVertex2f(0.105f,0.66f);
    glVertex2f(0.115f,0.65f);
    glVertex2f(0.115f,0.66f);
    ///with mini circle
    glVertex2f(0.11f,0.68f);
    glVertex2f(0.11f,0.69f);

    glVertex2f(0.12f,0.68f);
    glVertex2f(0.11f,0.69f);

    glVertex2f(0.10f,0.68f);
    glVertex2f(0.11f,0.69);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    ///MIDDLE IN RIGHT WINGS
    glVertex2f(0.125f,0.615f);
    glVertex2f(0.175f,0.615f);
    glVertex2f(0.125f,0.625f);
    glVertex2f(0.175f,0.625f);
    glVertex2f(0.125f,0.635f);
    glVertex2f(0.175f,0.635f);
    glVertex2f(0.135f,0.605f);
    glVertex2f(0.135f,0.645f);
    glVertex2f(0.145f,0.605f);
    glVertex2f(0.145f,0.645f);
    glVertex2f(0.155f,0.605f);
    glVertex2f(0.155f,0.645f);
    glVertex2f(0.165f,0.605f);
    glVertex2f(0.165f,0.645f);

    ///MIDDLE LINE IN LEFT WINGS
    glVertex2f(0.095f,0.615f);
    glVertex2f(0.045f,0.615f);
    glVertex2f(0.095f,0.625f);
    glVertex2f(0.045f,0.625f);
    glVertex2f(0.095f,0.635f);
    glVertex2f(0.045f,0.635f);
    glVertex2f(0.055f,0.605f);
    glVertex2f(0.055f,0.645f);
    glVertex2f(0.065f,0.605f);
    glVertex2f(0.065f,0.645f);
    glVertex2f(0.075f,0.605f);
    glVertex2f(0.075f,0.645f);
    glVertex2f(0.085f,0.605f);
    glVertex2f(0.085f,0.645f);
    glEnd();


    ///mini circle
    GLfloat p2=0.11f, k2=0.70f, ra2=.005;
    GLfloat twicePii = 2.0f * PI;

    glColor3f(0.812f, 0.89f, 0.98f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p2, k2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( p2 + (ra2 * cos(i *  twicePii / triangleAmount)),
                    k2 + (ra2 * sin(i * twicePii / triangleAmount)) );
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glEnd();

    ///HALF CIRCLE
    GLfloat p3=0.11f, k3=0.68f, ra3=.025;
    twicePi= -1.0f *PI;

    glColor3f(0.086f, 0.149f, 0.149f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p3, k3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( p3 + (ra3 * cos(i *  twicePi / triangleAmount)),
                    k3 + (ra3 * sin(i * twicePi / triangleAmount)) );
        glColor3f(0.294f, 0.388f, 0.388f);
    }
    glEnd();

    l-=0.0015f;
    glPopMatrix();
    glPopMatrix();



    glFlush(); // Render now
}

///.........Rocket
void updateT(int value)
{
    if(TPosition >2.0 )
        TPosition = -1.0f;
    TPosition += Tspeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateT, 0);
}
void updateD(int value)
{
    if(DPosition >2.0 )
        DPosition = -1.0f;
    DPosition += Dspeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateD, 0);
}


GLfloat s= 0.0f;
GLfloat meteorP10=0.0; GLfloat meteorP20=0.0;
GLfloat meteorS10=0.005;GLfloat meteorS20=0.003;

void meteorUps(int value){

       if(meteorP10 < -1.0)
        meteorS10 = 0.5f;

        if(meteorP20 > 1.0)
        meteorS20 = 0.0f;

         meteorP10 -= meteorS10;
         meteorP20 += meteorS20;
         glutPostRedisplay();
	glutTimerFunc(100, meteorUps, 0);

}

GLfloat ya = 0.005f, xa = .001f;
GLfloat yspeed = 0.02f, xspeed = 0.01;
int yFlag = 1, xFlag = 1, AniFlag = 1;

void updates(int value)
{
    if(AniFlag == 1)
    {
        //y
        if(ya>-0.05 && yFlag == 1)
            ya = ya - yspeed;

        if(ya<=-0.05 && yFlag == 1)
            yFlag = 0;


        if(ya<0.05 && yFlag == 0)
            ya = ya + yspeed;

        if(ya>=0.05 && yFlag == 0)
            yFlag = 1;
        //x

        if(xa>-0.02 && xFlag == 1)
            xa = xa - xspeed;

        if(xa<=-0.02 && xFlag == 1)
            xFlag = 0;


        if(xa<0.02 && xFlag == 0)
            xa = xa + xspeed;

        if(xa>=0.002 && xFlag == 0)
            xFlag = 1;
    }

    glutPostRedisplay();
    glutTimerFunc(100, updates, 0);
}

GLfloat positions = 1.0f;
GLfloat speeds = 0.05f;
///for rocket
void updates1(int value)
{
    if(positions < -1.0)
        positions = 1.0f;

    positions -= speeds;

    glutPostRedisplay();
    glutTimerFunc(200, updates1, 0);
}
GLfloat positions2 = 1.0f;
GLfloat speeds2 = 0.09f;
///for stairs
void updates2(int value)
{
    if(positions2 < 1.0f)
          positions2 =0.765f;
    positions2 -= speeds2;
    glutPostRedisplay();
    glutTimerFunc(4000, updates2, 0);

}
GLfloat positions3 = 1.0f;
GLfloat speeds3 = 0.2f;
GLfloat positions4 = 1.0f;
GLfloat speeds4 = 0.2f;
GLfloat positions5 = 1.0f;
GLfloat speeds5 = 0.2f;
///for man
void updates3(int value)
{
    ///man1
    if(positions3 < 2.0)
        positions3 -= speeds;
            positions3 = 0.0f;

   ///aiun banner
   if(positions4 < 1.5)
       positions4 -= speeds;
            positions4 = 0.0f;

   ///man 2
   if(positions5 < 1.5)
       positions5 -= speeds;
            positions5 = 0.0f;

	glutPostRedisplay();
	glutTimerFunc(9000, updates3, 0);
}

void SpecialInputs(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        speeds = 0.005f;
        break;
    case GLUT_KEY_DOWN:
        speeds = 0.0f;
        break;
    case GLUT_KEY_LEFT:
        speeds2 = 0.007f;
        speeds3 = 0.007f;
        break;
    case GLUT_KEY_RIGHT:
        speeds2 = 0.0f;
        speeds3 = 0.0f;
        break;
    }
    glutPostRedisplay();
}
void display5()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    int triangleAmount= 150; //# of lines used to draw circle
    int lineAmount = 100;
    GLfloat twicePi = 2.0f * PI;

    ///Meteor - 1
    glPushMatrix();
    glTranslatef(meteorP20,meteorP10,0.0f);
    glPushMatrix();
    glScalef(.2,.2,0);
	glTranslatef(0.10f,4.10f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(1.0f,1.0f,1.0f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.43f,0.614f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor4f(0.722f,0.718f,0.706f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.48f,0.499f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPopMatrix();

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLfloat A63=0.5f; GLfloat P63=0.5f; GLfloat O63 =0.012f;
    glColor3f(0.945f, 0.663f, 0.165f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A63, P63); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A63 + (O63 * cos(i *  twicePi/ triangleAmount)),
                        P63 + (O63 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Meteor Inside Circle
    GLfloat A64=0.505f; GLfloat P64=0.5045f; GLfloat O64 =0.005f;
    glColor3f(0.965f, 0.859f, 0.518f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A64, P64); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A64 + (O64 * cos(i *  twicePi/ triangleAmount)),
                        P64 + (O64 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();
    s+=0.003f;
    glPopMatrix();
    glPopMatrix();

    ///Meteor - 2
    glPushMatrix();
    glTranslatef(meteorP20,meteorP10,0.0f);
    glPushMatrix();
    glScalef(.2,.2,0);
	glTranslatef(1.10f,5.10f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(1.0f,1.0f,1.0f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.43f,0.614f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor4f(0.722f,0.718f,0.706f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.48f,0.499f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPopMatrix();

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLfloat A603=0.5f; GLfloat P603=0.5f; GLfloat O603 =0.012f;
    glColor3f(0.945f, 0.663f, 0.165f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A603, P603); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A603 + (O603 * cos(i *  twicePi/ triangleAmount)),
                        P603 + (O603 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Meteor Inside Circle
    GLfloat A604=0.505f; GLfloat P604=0.5045f; GLfloat O604 =0.005f;
    glColor3f(0.965f, 0.859f, 0.518f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A604, P604); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A604 + (O604 * cos(i *  twicePi/ triangleAmount)),
                        P604 + (O604 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();
    s+=0.003f;
    glPopMatrix();
    glPopMatrix();

    ///Meteor - 3
    glPushMatrix();
    glTranslatef(meteorP20,meteorP10,0.0f);

    glPushMatrix();
    glScalef(.2,.2,0);
	glTranslatef(2.10f,5.10f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(1.0f,1.0f,1.0f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.43f,0.614f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor4f(0.722f,0.718f,0.706f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.48f,0.499f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPopMatrix();

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLfloat A630=0.5f; GLfloat P630=0.5f; GLfloat O630 =0.012f;
    glColor3f(0.945f, 0.663f, 0.165f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A630, P630); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A630 + (O630 * cos(i *  twicePi/ triangleAmount)),
                        P630 + (O630 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Meteor Inside Circle
    GLfloat A640=0.505f; GLfloat P640=0.5045f; GLfloat O640 =0.005f;
    glColor3f(0.965f, 0.859f, 0.518f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A640, P640); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A640 + (O640 * cos(i *  twicePi/ triangleAmount)),
                        P640 + (O640 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();
    s+=0.003f;
    glPopMatrix();

    glPopMatrix();

    ///Meteor - 4
    glPushMatrix();
    glTranslatef(meteorP20,meteorP10,0.0f);

    glPushMatrix();
    glScalef(.2,.2,0);
	glTranslatef(3.10f,5.10f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(1.0f,1.0f,1.0f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.43f,0.614f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor4f(0.722f,0.718f,0.706f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.48f,0.499f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPopMatrix();

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLfloat A0630=0.5f; GLfloat P0630=0.5f; GLfloat O0630 =0.012f;
    glColor3f(0.945f, 0.663f, 0.165f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A0630, P0630); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A0630 + (O0630 * cos(i *  twicePi/ triangleAmount)),
                        P0630 + (O0630 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Meteor Inside Circle
    GLfloat A0640=0.505f; GLfloat P0640=0.5045f; GLfloat O0640 =0.005f;
    glColor3f(0.965f, 0.859f, 0.518f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A0640, P0640); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A0640 + (O0640 * cos(i *  twicePi/ triangleAmount)),
                        P0640 + (O0640 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();
    s+=0.003f;
    glPopMatrix();

    glPopMatrix();

    ///start
    ///.................................Stars.........................
    glPointSize(3.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.9f,0.9f);glVertex2f(0.7f,0.6f);glVertex2f(0.5f,0.5f);glVertex2f(0.4f,0.5f);glVertex2f(0.4f,0.9f);glVertex2f(0.5f,0.7f);glVertex2f(0.6f,0.4f);glVertex2f(0.8f,0.5f);
    glPointSize(4.0);
    glVertex2f(0.6f,0.9f);glVertex2f(0.6f,0.7f);glVertex2f(0.3f,0.5f);glVertex2f(0.6f,0.4f);glVertex2f(0.4f,0.9f);glVertex2f(0.9f,0.5f);glVertex2f(0.1f,0.46f);glVertex2f(0.8f,0.6f);
    glPointSize(5.0);
    glVertex2f(0.7f,0.8f);glVertex2f(0.65f,0.4f);glVertex2f(0.2f,0.7f);glVertex2f(0.15f,0.45f);glVertex2f(0.43f,0.69f);glVertex2f(0.55f,0.75f);glVertex2f(0.05f,0.56f);glVertex2f(0.86f,0.96f);
    glPointSize(3.0);
    glColor3f(0.89f, 0.867f, 0.875f);
    glVertex2f(0.04f, 0.04f);glVertex2f(0.04f, 0.3f);glVertex2f(0.04f, 0.55f);glVertex2f(0.08f, 0.018f);glVertex2f(0.08f, 0.18f);glVertex2f(0.14f, 0.2f);glVertex2f(0.14f, 0.5f);
    glVertex2f(0.25f, 0.5f);glVertex2f(0.2f, 0.35f);glVertex2f(0.06f, 0.62f);
    glPointSize(4.0);
    glVertex2f(0.5f, 0.62f);glVertex2f(0.5f, 0.18f);glVertex2f(0.4f, 0.09f);glVertex2f(0.3f, 0.13f);glVertex2f(0.22f, 0.08f);glVertex2f(0.35f, 0.8f);glVertex2f(0.49f, 0.83f);
    glVertex2f(0.3f, 0.65f);glVertex2f(0.3f, 0.9f);glVertex2f(0.45f, 0.94f);glVertex2f(0.45f, 0.8f);
    glPointSize(5.0);
    glVertex2f(0.53f, 0.75f);glVertex2f(0.63f, 0.5f);glVertex2f(0.63f, 0.75f);glVertex2f(0.69f, 0.8f);glVertex2f(0.73f, 0.95f);glVertex2f(0.94f, 0.95f);glVertex2f(0.86f, 0.98f);
    glVertex2f(0.8f, 0.43f);glVertex2f(0.75f, 0.48f);glVertex2f(0.7f, 0.28f);glVertex2f(0.7f, 0.63f);glVertex2f(0.45f, 0.28f);glVertex2f(0.6f, 0.28f);glVertex2f(0.5f, 0.46f);glVertex2f(0.08f,0.66f);
    glPointSize(6.0);
    glVertex2f(0.2f,0.6f);glVertex2f(0.40f,0.52f);glVertex2f(0.28f,0.26f);glVertex2f(0.40f,0.7f);glVertex2f(0.56f,0.06f);glVertex2f(0.60f,0.9f);glVertex2f(0.84f,0.84f);glVertex2f(0.12f,0.4f);glVertex2f(0.32f,0.4f);
    glVertex2f(0.9f,0.83f);glVertex2f(0.8f,0.6f);glVertex2f(0.8f,0.9f);glVertex2f(0.95f,0.86f);glVertex2f(0.9f,0.66f);glVertex2f(0.97f,0.76f);glVertex2f(0.88f,0.56f);glVertex2f(0.98f,0.6f);
    glEnd();

    ///STAR 3
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(2.50f,3.20f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 4
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(2.40f,4.6f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();




    ///STAR 6
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(3.30f,6.f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 7
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(5.10f,6.20f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 8
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(4.1f,5.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 9
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(4.50f,2.50f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 10
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(4.50f,6.20f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 11
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(5.15f,3.59f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 12
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(6.2f,4.2f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();


    ///STAR 13
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(5.9f,5.2f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();



    ///earth
    GLfloat s0=0.0f, u0=0.9f, radi0 =.27f, j = 0.0f;
    glColor3f(0.043f, 0.678f, 0.937f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s0, u0); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s0 + (radi0 * cos(i *  twicePi / triangleAmount)),
                    u0 + (radi0 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///1
    glPushMatrix();

    GLfloat s6=0.0f, u6=0.84f, radi6 =.11f, q = 0.0f;;
    glPushMatrix();
    glRotatef(q,+0.42,-0.05,0.0);

    glColor3f(0.62f, 0.827f, 0.271f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s6, u6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s6 + (radi6 * cos(i *  twicePi / triangleAmount)),
                    u6 + (radi6 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///2
    GLfloat s7=0.1f, u7=0.85f, radi7 =.09f;

    glColor3f(0.62f, 0.827f, 0.271f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s7, u7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s7 + (radi7 * cos(i *  twicePi / triangleAmount)),
                    u7 + (radi7 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///3
    GLfloat s8=0.15f, u8=1.0f, radi8 =.05f;

    glColor3f(0.62f, 0.827f, 0.271f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s8, u8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s8 + (radi8 * cos(i *  twicePi / triangleAmount)),
                    u8 + (radi8 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///4
    GLfloat s9=-0.08f, u9=1.05f, radi9 =.05f;

    glColor3f(0.62f, 0.827f, 0.271f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s9, u9); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s9 + (radi9 * cos(i *  twicePi / triangleAmount)),
                    u9 + (radi9 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///5
    GLfloat s700=-0.15f, u700=0.95f, radi700 =.07f;

    glColor3f(0.62f, 0.827f, 0.271f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s700, u700); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s700 + (radi700 * cos(i *  twicePi / triangleAmount)),
                    u700 + (radi700 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///6
    GLfloat s6000=0.0f, u6000=1.03f, radi6000 =.09f;

    glColor3f(0.62f, 0.827f, 0.271f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s6000, u6000); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s6000 + (radi6000 * cos(i *  twicePi / triangleAmount)),
                    u6000 + (radi6000 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    ///green
    ///1
    GLfloat r10=-0.07f, e10=1.06f, radi010 =.02f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(r10, e10); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( r10 + (radi010 * cos(i *  twicePi / triangleAmount)),
                    e10 + (radi010 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    ///2
    GLfloat a40=-0.09f;
    GLfloat b40=1.04f;
    GLfloat radi121 =.03f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a40, b40); // center of circle
    for(int j0 = 0; j0 <= triangleAmount; j0++)
    {
        glVertex2f( a40 + (radi121 * cos(j0 *  twicePi / triangleAmount)),
                    b40 + (radi121 * sin(j0 * twicePi / triangleAmount)));
    }
    glEnd();

    ///3
    GLfloat s10=0.14f, u10=0.98f, radi10 =.02f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s10, u10); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s10 + (radi10 * cos(i *  twicePi / triangleAmount)),
                    u10 + (radi10 * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    ///4
    GLfloat a0=0.16f;
    GLfloat b0=0.99f;
    GLfloat radi11 =.018f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a0, b0); // center of circle
    for(int j0 = 0; j0 <= triangleAmount; j0++)
    {
        glVertex2f( a0 + (radi11 * cos(j0 *  twicePi / triangleAmount)),
                    b0 + (radi11 * sin(j0 * twicePi / triangleAmount)));
    }
    glEnd();
    ///5
    GLfloat a1=0.01f;
    GLfloat b1=0.81f;
    GLfloat radi1 =.04f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a1, b1); // center of circle
    for(int j1 = 0; j1 <= triangleAmount; j1++)
    {
        glVertex2f( a1 + (radi1 * cos(j1 *  twicePi / triangleAmount)),
                    b1 + (radi1 * sin(j1 * twicePi / triangleAmount)));
    }
    glEnd();

    ///6
    GLfloat a2=0.05f;
    GLfloat b2=0.8f;
    GLfloat radi2 =.03f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a2, b2); // center of circle
    for(int j2 = 0; j2 <= triangleAmount; j2++)
    {
        glVertex2f( a2 + (radi2 * cos(j2 *  twicePi / triangleAmount)),
                    b2 + (radi2 * sin(j2 * twicePi / triangleAmount)));
    }
    glEnd();

    ///7
    GLfloat a3=0.075f;
    GLfloat b3=0.85f;
    GLfloat radi3 =.05f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a3, b3); // center of circle
    for(int j3 = 0; j3 <= triangleAmount; j3++)
    {
        glVertex2f( a3 + (radi3 * cos(j3 *  twicePi / triangleAmount)),
                    b3 + (radi3 * sin(j3 * twicePi / triangleAmount)));
    }
    glEnd();

    ///8
    GLfloat a4=0.12f;
    GLfloat b4=0.86f;
    GLfloat radi4 =.035f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a4, b4); // center of circle
    for(int j4 = 0; j4 <= triangleAmount; j4++)
    {
        glVertex2f( a4 + (radi4 * cos(j4 *  twicePi / triangleAmount)),
                    b4 + (radi4 * sin(j4 * twicePi / triangleAmount)));
    }
    glEnd();

    ///9
    GLfloat a5=0.01f;
    GLfloat b5=0.92f;
    GLfloat radi5 =.03f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a5, b5); // center of circle
    for(int j5 = 0; j5 <= triangleAmount; j5++)
    {
        glVertex2f( a5 + (radi5 * cos(j5 *  twicePi / triangleAmount)),
                    b5 + (radi5 * sin(j5 * twicePi / triangleAmount)));
    }
    glEnd();
     ///10
    GLfloat a60=-0.04f;
    GLfloat b60=0.90f;
    GLfloat radi60 =.04f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a60, b60); // center of circle
    for(int j5 = 0; j5 <= triangleAmount; j5++)
    {
        glVertex2f( a60 + (radi60 * cos(j5 *  twicePi / triangleAmount)),
                    b60 + (radi60 * sin(j5 * twicePi / triangleAmount)));
    }
    glEnd();
      ///11
    GLfloat a50=-0.05f;
    GLfloat b50=0.86f;
    GLfloat radi50 =.035f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a50, b50); // center of circle
    for(int j5 = 0; j5 <= triangleAmount; j5++)
    {
        glVertex2f( a50 + (radi50 * cos(j5 *  twicePi / triangleAmount)),
                    b50 + (radi50 * sin(j5 * twicePi / triangleAmount)));
    }
    glEnd();
    ///12
    GLfloat a500=-0.15f;
    GLfloat b500=0.93f;
    GLfloat radi500 =.035f;


    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(a500, b500); // center of circle
    for(int j5 = 0; j5 <= triangleAmount; j5++)
    {
        glVertex2f( a500 + (radi500 * cos(j5 *  twicePi / triangleAmount)),
                    b500 + (radi500 * sin(j5 * twicePi / triangleAmount)));
    }
    glEnd();
    ///13
    GLfloat s100=-0.13f, u100=0.97f, radiu100 =0.04f;

    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s100, u100); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s100 + (radiu100 * cos(i *  twicePi / triangleAmount)),
                    u100 + (radiu100 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///14
    GLfloat s7000=-0.02f, u7000=1.0f, radiu7000 =0.04f;

    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s7000, u7000); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s7000 + (radiu7000 * cos(i *  twicePi / triangleAmount)),
                    u7000 + (radiu7000 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///15
    GLfloat s8000=-0.02f, u8000=1.05f, radiu8000 =0.03f;

    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s8000, u8000); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s8000 + (radiu8000 * cos(i *  twicePi / triangleAmount)),
                    u8000 + (radiu8000 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
      ///16
    GLfloat s9000=0.03f, u9000=1.04f, radiu9000 =0.05f;

    glColor3f(0.451f, 0.733f, 0.2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s9000, u9000); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s9000 + (radiu9000 * cos(i *  twicePi / triangleAmount)),
                    u9000 + (radiu9000 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
glPopMatrix();
glPopMatrix();
q += 0.007f;



    ///_________ Fire main 1________///
    glPushMatrix();
    glScalef(1.2,1.2,0);
    glTranslatef(+0.25f, positions, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, objectp, 0.0f); // Translate the object vertically
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.20f);
    glVertex2f(0.36f,0.14f);
    glVertex2f(0.388f,0.17f);
    glVertex2f(0.4f,0.12f);
    glVertex2f(0.42f,0.18f);
    glVertex2f(0.45f,0.14f);
    glVertex2f(0.42f,0.20f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.20f);
    glVertex2f(0.38f,0.168f);
    glVertex2f(0.395f,0.19f);
    glVertex2f(0.40f,0.14f);
    glVertex2f(0.41f,0.19f);
    glVertex2f(0.43f,0.17f);
    glVertex2f(0.417f,0.20f);
    glEnd();
    ///_________ Fire main 2________///
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    ///moon ground

    //1
    GLfloat s1=0.1f, u1=0.2f, radiu1 =0.17f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(s1, u1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( s1 + (radiu1 * cos(i *  twicePi / triangleAmount)),
                    u1 + (radiu1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //2
    int i2;

    GLfloat x2=0.25f, y2=0.25f, radius2 =.07f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
                    y2 + (radius2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //3
    GLfloat x3=0.45f, y3=0.08f, radius3 =.27f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
                    y3 + (radius3 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //4
    GLfloat x4=0.76f, y4=0.17f, radius4 =.2f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
                    y4 + (radius4 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //5
    GLfloat x5=0.97f, y5=0.27f, radius5 =.07f;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x5 + (radius5 * cos(i *  twicePi / triangleAmount)),
                    y5 + (radius5 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.0f,0.3f);
    glVertex2f(0.765f,0.3f);
    glColor3f(0.573f, 0.596f, 0.616f);
    glVertex2f(0.765f,0.0f);
    glVertex2f(0.0f,0.0f);
    glEnd();

    ///spots on moon
    ///1
    glColor3f(0.839f, 0.839f, 0.839f); // Set color to red
    drawEllipse(0.05f, 0.35f, 0.055f, 0.025f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.05f, 0.35f, 0.05f, 0.02f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.05f, 0.35f, 0.045f, 0.015f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments
    ///2
    glColor3f(0.706f, 0.706f, 0.706f); // Set color to red
    drawEllipse(0.01f, 0.1f, 0.065f, 0.025f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.01f, 0.1f, 0.06f, 0.02f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.01f, 0.1f, 0.055f, 0.015f, 100);
    ///3
    glColor3f(0.706f, 0.706f, 0.706f); // Set color to red
    drawEllipse(0.2f, 0.2f, 0.05f, 0.025f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.2f, 0.2f, 0.045f, 0.02f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.2f, 0.2f, 0.04f, 0.015f, 100);
    ///4
    glColor3f(0.839f, 0.839f, 0.839f); // Set color to red
    drawEllipse(0.5f, 0.32f, 0.06f, 0.025f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.5f, 0.32f, 0.055f, 0.02f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.5f, 0.32f, 0.05f, 0.015f, 100);
    ///5
    glColor3f(0.647f, 0.647f, 0.647f); // Set color to red
    drawEllipse(0.44f, 0.12f, 0.057f, 0.025f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.44f, 0.12f, 0.052f, 0.02f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.44f, 0.12f, 0.047f, 0.015f, 100);
    ///6
    glColor3f(0.839f, 0.839f, 0.839f); // Set color to red
    drawEllipse(0.37f, 0.24f, 0.037f, 0.015f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.37f, 0.24f, 0.032f, 0.01f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.37f, 0.24f, 0.027f, 0.005f, 100);
    ///7
    glColor3f(0.597f, 0.597f, 0.597f); // Set color to red
    drawEllipse(0.2f, 0.01f, 0.067f, 0.025f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.2f, 0.01f, 0.062f, 0.02f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.2f, 0.01f, 0.057f, 0.015f, 100);
     ///8
    glColor3f(0.839f, 0.839f, 0.839f); // Set color to red
    drawEllipse(0.76f, 0.33f, 0.057f, 0.02f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.76f, 0.33f, 0.052f, 0.015f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.76f, 0.33f, 0.047f, 0.01f, 100);
    ///9
    glColor3f(0.706f, 0.706f, 0.706f); // Set color to red
    drawEllipse(0.66f, 0.09f, 0.057f, 0.02f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.66f, 0.09f, 0.052f, 0.015f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.66f, 0.09f, 0.047f, 0.01f, 100);



    ///Man in Moon
    ///***********************Man
    GLfloat m=0.2f, a=0.28f, n =0.02f;
    glPushMatrix();
    glScalef(0.5,0.5,0);
    glTranslatef(positions4 , 0.257f, 0.0f);
    glTranslatef(+0.4f, 0.0f, 0.0f);
    glColor3f(0.78f, 0.788f, 0.839f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(m, a); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( m + (n * cos(i *  twicePi / triangleAmount)),
                       a + (n * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    ///Border
    glLineWidth(1);
    GLfloat m1=0.2f; GLfloat a12=0.28f; GLfloat n1 =0.02f;
    glColor3f(0.008f,0.043f,0.031f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    m1 + (n1 * cos(i *  twicePi / lineAmount)),
			    a12 + (n1  * sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.133f, 0.196f, 0.243f);
    ///Helmate glass
    glVertex2f(0.181f,0.288f);
    glVertex2f(0.218f,0.288f);
    glVertex2f(0.21f,0.27f);
    glVertex2f(0.182f,0.27f);
    ///Neck
    glColor3f(0.78f, 0.788f, 0.839f);
    glVertex2f(0.182f,0.263f);
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.224f,0.235f);
    glVertex2f(0.218f,0.265f);
    ///Right Hand with Sholder
    glVertex2f(0.218f,0.265f);
    glVertex2f(0.224f,0.235f);
    glVertex2f(0.255f,0.24f);
    glVertex2f(0.243f,0.26f);
    ///Right Hand Rest part
    glVertex2f(0.255f,0.24f);
    glVertex2f(0.243f,0.26f);
    glVertex2f(0.26f,0.276f);
    glVertex2f(0.27f,0.27f);

    ///Left Hand with Sholder
    glVertex2f(0.182f,0.263f);
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.144f,0.24f);
    glVertex2f(0.157f,0.26f);

    ///Left Hand Rest part
    glVertex2f(0.144f,0.24f);
    glVertex2f(0.157f,0.26f);
    glVertex2f(0.14f,0.276f);
    glVertex2f(0.13f,0.27f);
    ///Body
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.224f,0.19f);
    glVertex2f(0.224f,0.235f);
    ///Pant Upper Part
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.173f,0.175f);
    glVertex2f(0.226f,0.175f);
    glVertex2f(0.224f,0.19f);

    ///Right Leg1
    glVertex2f(0.198f,0.175f);
    glVertex2f(0.206f,0.14f);
    glVertex2f(0.229f,0.14f);
    glVertex2f(0.226f,0.175f);
    ///Right Leg2
    glVertex2f(0.206f,0.14f);
    glVertex2f(0.209f,0.12f);
    glVertex2f(0.232f,0.118f);
    glVertex2f(0.229f,0.14f);
    ///Right Leg shoe
    glVertex2f(0.208f,0.12f);
    glVertex2f(0.208f,0.1f);
    glVertex2f(0.24f,0.1f);
    glVertex2f(0.237f,0.116f);
    ///Left Leg1
    glVertex2f(0.173f,0.175f);
    glVertex2f(0.1667f,0.14f);
    glVertex2f(0.1897f,0.14f);
    glVertex2f(0.199f,0.175f);
    ///Left Leg2
    glVertex2f(0.1667f,0.14f);
    glVertex2f(0.1664f,0.12f);
    glVertex2f(0.1894f,0.117f);
    glVertex2f(0.1897f,0.14f);
    ///Left Leg shoe
    glVertex2f(0.159f,0.117f);
    glVertex2f(0.159f,0.1f);
    glVertex2f(0.1895f,0.1f);
    glVertex2f(0.1895f,0.12f);
    glEnd();

    ///Right Hand
    GLfloat m13=0.27f, a13=0.278f, n13 =0.009f;

    glColor3f(0.78f, 0.788f, 0.839f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(m13, a13); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( m13 + (n13 * cos(i *  twicePi / triangleAmount)),
                       a13 + (n13 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    /// Right Border
    glLineWidth(1);
    GLfloat m14=0.27f; GLfloat a14=0.278f; GLfloat n14 =0.009f;
    glColor3f(0.008f,0.043f,0.031f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    m14 + (n14 * cos(i *  twicePi / lineAmount)),
			    a14 + (n14  * sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	///Left Hand
    GLfloat m15=0.13f, a15=0.278f, n15 =0.009f;

    glColor3f(0.78f, 0.788f, 0.839f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(m15, a15); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( m15 + (n15 * cos(i *  twicePi / triangleAmount)),
                       a15 + (n15 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    /// Left Border
    glLineWidth(1);
    GLfloat m16=0.13f; GLfloat a16=0.278f; GLfloat n16 =0.009f;
    glColor3f(0.008f,0.043f,0.031f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    m16 + (n16 * cos(i *  twicePi / lineAmount)),
			    a16 + (n16  * sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

    ///Detailing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.008f,0.043f,0.031f);

    ///Belt
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.175f,0.2f);

    glVertex2f(0.224f,0.2f);
    glVertex2f(0.224f,0.19f);

    glVertex2f(0.175f,0.2f);
    glVertex2f(0.224f,0.2f);

    glVertex2f(0.175f,0.19f);
    glVertex2f(0.224f,0.19f);

    ///Middle Line
    glVertex2f(0.18f,0.19f);
    glVertex2f(0.18f,0.2f);

    glVertex2f(0.19f,0.19f);
    glVertex2f(0.19f,0.2f);

    glVertex2f(0.2f,0.19f);
    glVertex2f(0.2f,0.2f);

    glVertex2f(0.21f,0.19f);
    glVertex2f(0.21f,0.2f);

    glVertex2f(0.22f,0.19f);
    glVertex2f(0.22f,0.2f);

    ///Neck Border
    glVertex2f(0.187f,0.263f);
    glVertex2f(0.182f,0.263f);

    glVertex2f(0.215f,0.265f);
    glVertex2f(0.218f,0.265f);

    ///Right Hand with Sholder Border
    glVertex2f(0.218f,0.265f);
    glVertex2f(0.243f,0.26f);

    glVertex2f(0.255f,0.24f);
    glVertex2f(0.224f,0.235f);
    ///Right Hand Rest part Border
    glVertex2f(0.255f,0.24f);
    glVertex2f(0.27f,0.27f);

    glVertex2f(0.243f,0.26f);
    glVertex2f(0.26f,0.276f);

    ///Left Hand with Sholder Border
    glVertex2f(0.182f,0.263f);
    glVertex2f(0.157f,0.26f);

    glVertex2f(0.175f,0.235f);
    glVertex2f(0.144f,0.24f);
    ///Left Hand Rest part Border
    glVertex2f(0.144f,0.24f);
    glVertex2f(0.13f,0.27f);

    glVertex2f(0.157f,0.26f);
    glVertex2f(0.14f,0.276f);
    ///Body Border
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.175f,0.19f);

    glVertex2f(0.224f,0.19f);
    glVertex2f(0.224f,0.235f);

    ///Suit Design
    glVertex2f(0.2f,0.26f);
    glVertex2f(0.2f,0.19f);

    glVertex2f(0.2f,0.26f);
    glVertex2f(0.185f,0.265f);

    glVertex2f(0.2f,0.26f);
    glVertex2f(0.215f,0.265f);

    ///Pant Upper Part Border
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.173f,0.175f);

    glVertex2f(0.226f,0.175f);
    glVertex2f(0.224f,0.19f);

    ///Right Leg1 Border
    glVertex2f(0.198f,0.175f);
    glVertex2f(0.206f,0.14f);

    glVertex2f(0.229f,0.14f);
    glVertex2f(0.226f,0.175f);

    ///Right Leg2 Border
    glVertex2f(0.206f,0.14f);
    glVertex2f(0.209f,0.12f);

    glVertex2f(0.232f,0.118f);
    glVertex2f(0.229f,0.14f);

    ///Right Leg shoe Border
    glVertex2f(0.208f,0.12f);
    glVertex2f(0.208f,0.1f);

    glVertex2f(0.24f,0.1f);
    glVertex2f(0.237f,0.116f);

    glVertex2f(0.232f,0.118f);
    glVertex2f(0.237f,0.116f);

    glVertex2f(0.208f,0.1f);
    glVertex2f(0.24f,0.1f);

    ///RIGHT Shoe lines
    glVertex2f(0.207f,0.13f);
    glVertex2f(0.232f,0.13f);

    glVertex2f(0.207f,0.135f);
    glVertex2f(0.23f,0.135f);
    ///Left Leg1 Border
    glVertex2f(0.173f,0.175f);
    glVertex2f(0.1667f,0.14f);

    glVertex2f(0.1897f,0.14f);
    glVertex2f(0.199f,0.175f);
    ///Left Leg2 Border
    glVertex2f(0.1667f,0.14f);
    glVertex2f(0.1664f,0.12f);

    glVertex2f(0.1894f,0.12f);
    glVertex2f(0.1897f,0.14f);
    ///Left Leg shoe Border
    glVertex2f(0.159f,0.117f);
    glVertex2f(0.159f,0.1f);

    glVertex2f(0.1895f,0.1f);
    glVertex2f(0.1895f,0.12f);

    glVertex2f(0.1664f,0.12f);
    glVertex2f(0.159f,0.117f);

    glVertex2f(0.159f,0.1f);
    glVertex2f(0.1895f,0.1f);

    ///LEFT Shoe lines
    glVertex2f(0.1667f,0.13f);
    glVertex2f(0.1895f,0.13f);

    glVertex2f(0.1667f,0.135f);
    glVertex2f(0.1895f,0.135f);

    glEnd();
    glPopMatrix();

    ///AIUB Banner
    glLineWidth(5);
    glPushMatrix();
    glTranslatef(positions3 , 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(0.498f, 0.498f, 0.498f);
    glVertex2f(0.335f,0.33f);
    glVertex2f(0.335f,0.25f);
    glVertex2f(0.265f,0.33f);
    glVertex2f(0.265f,0.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.565f, 0.588f, 0.616f);
    glVertex2f(0.34f,.385f);
    glVertex2f(0.34f,0.33f);
    glVertex2f(0.26f,0.33f);
    glVertex2f(0.26f,0.385f);
    glEnd();

    glColor3f(0.035f, 0.38f, 0.569f);
    renderBitmapString(0.28f, 0.35f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "A");
    glColor3f(0.047f, 0.384f, 0.224f);
    renderBitmapString(0.29f, 0.35f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "I");
    glColor3f(0.792f, 0.09f, 0.259f);
    renderBitmapString(0.295f, 0.35f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "U");
    glColor3f(0.745f, 0.455f, 0.133f);
    renderBitmapString(0.305f, 0.35f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "B");
    glPopMatrix();

    ///..........................................Man-2....................................////
    glPushMatrix();
    glScalef(0.5,0.5,0);
    glTranslatef(positions5, 0.3f, 0.0f);
    glTranslatef(+0.73f, 0.0f, 0.0f);
    GLfloat m17=0.2f, a17=0.28f, n17 =0.02f;
    glColor3f(0.78f, 0.788f, 0.839f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(m17, a17); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( m17 + (n17 * cos(i *  twicePi / triangleAmount)),
                       a17 + (n17 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    ///Border
    glLineWidth(1);
    GLfloat m18=0.2f; GLfloat a18=0.28f; GLfloat n18 =0.02f;
    glColor3f(0.008f,0.043f,0.031f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    m18 + (n18 * cos(i *  twicePi / lineAmount)),
			    a18 + (n18 * sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.133f, 0.196f, 0.243f);
    ///Helmate glass
    glVertex2f(0.181f,0.288f);
    glVertex2f(0.218f,0.288f);
    glVertex2f(0.21f,0.27f);
    glVertex2f(0.182f,0.27f);
    ///Neck
    glColor3f(0.78f, 0.788f, 0.839f);
    glVertex2f(0.182f,0.263f);
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.224f,0.235f);
    glVertex2f(0.218f,0.265f);
    ///Right Hand with Sholder
    glVertex2f(0.218f,0.265f);
    glVertex2f(0.224f,0.235f);
    glVertex2f(0.255f,0.24f);
    glVertex2f(0.243f,0.26f);
    ///Right Hand Rest part
    glVertex2f(0.255f,0.24f);
    glVertex2f(0.243f,0.26f);
    glVertex2f(0.27f,0.26f);
    glVertex2f(0.27f,0.24f);

    ///Left Hand with Sholder
    glVertex2f(0.182f,0.263f);
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.144f,0.24f);
    glVertex2f(0.157f,0.26f);

    ///Left Hand Rest part
    glVertex2f(0.144f,0.24f);
    glVertex2f(0.157f,0.26f);
    glVertex2f(0.148f,0.28f);
    glVertex2f(0.135f,0.275f);
    ///Body
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.224f,0.19f);
    glVertex2f(0.224f,0.235f);
    ///Pant Upper Part
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.173f,0.175f);
    glVertex2f(0.226f,0.175f);
    glVertex2f(0.224f,0.19f);

    ///Right Leg1
    glVertex2f(0.198f,0.175f);
    glVertex2f(0.206f,0.14f);
    glVertex2f(0.229f,0.14f);
    glVertex2f(0.226f,0.175f);
    ///Right Leg2
    glVertex2f(0.206f,0.14f);
    glVertex2f(0.209f,0.12f);
    glVertex2f(0.232f,0.118f);
    glVertex2f(0.229f,0.14f);
    ///Right Leg shoe
    glVertex2f(0.208f,0.12f);
    glVertex2f(0.208f,0.1f);
    glVertex2f(0.24f,0.1f);
    glVertex2f(0.237f,0.116f);
    ///Left Leg1
    glVertex2f(0.173f,0.175f);
    glVertex2f(0.1667f,0.14f);
    glVertex2f(0.1897f,0.14f);
    glVertex2f(0.199f,0.175f);
    ///Left Leg2
    glVertex2f(0.1667f,0.14f);
    glVertex2f(0.1664f,0.12f);
    glVertex2f(0.1894f,0.117f);
    glVertex2f(0.1897f,0.14f);
    ///Left Leg shoe
    glVertex2f(0.159f,0.117f);
    glVertex2f(0.159f,0.1f);
    glVertex2f(0.1895f,0.1f);
    glVertex2f(0.1895f,0.12f);
    glEnd();

    ///Right Hand
    GLfloat m19=0.27f, a19=0.25f, n19 =0.009f;

    glColor3f(0.78f, 0.788f, 0.839f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(m19, a19); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( m19 + (n19 * cos(i *  twicePi / triangleAmount)),
                       a19 + (n19 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    /// Right Border
    glLineWidth(1);
    GLfloat m20=0.27f; GLfloat a20=0.25f; GLfloat n20 =0.009f;
    glColor3f(0.008f,0.043f,0.031f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    m20 + (n20 * cos(i *  twicePi / lineAmount)),
			    a20 + (n20  * sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

	///Left Hand
    GLfloat m21=0.14f, a21=0.283f, n21 =0.009f;
    glColor3f(0.78f, 0.788f, 0.839f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(m21, a21); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( m21 + (n21 * cos(i *  twicePi / triangleAmount)),
                       a21 + (n21 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    /// Left Border
    glLineWidth(1);
    GLfloat m22=0.14f; GLfloat a22=0.283f; GLfloat n22 =0.009f;
    glColor3f(0.008f,0.043f,0.031f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++) {
			glVertex2f(
			    m22 + (n22 * cos(i *  twicePi / lineAmount)),
			    a22 + (n22  * sin(i * twicePi / lineAmount))
			);
		}
	glEnd();
    ///Detailing
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.008f,0.043f,0.031f);

    ///Belt
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.175f,0.2f);

    glVertex2f(0.224f,0.2f);
    glVertex2f(0.224f,0.19f);

    glVertex2f(0.175f,0.2f);
    glVertex2f(0.224f,0.2f);

    glVertex2f(0.175f,0.19f);
    glVertex2f(0.224f,0.19f);

    ///Middle Line
    glVertex2f(0.18f,0.19f);
    glVertex2f(0.18f,0.2f);

    glVertex2f(0.19f,0.19f);
    glVertex2f(0.19f,0.2f);

    glVertex2f(0.2f,0.19f);
    glVertex2f(0.2f,0.2f);

    glVertex2f(0.21f,0.19f);
    glVertex2f(0.21f,0.2f);

    glVertex2f(0.22f,0.19f);
    glVertex2f(0.22f,0.2f);

    ///Neck Border
    glVertex2f(0.187f,0.263f);
    glVertex2f(0.182f,0.263f);

    glVertex2f(0.215f,0.265f);
    glVertex2f(0.218f,0.265f);

    ///Right Hand with Sholder Border
    glVertex2f(0.218f,0.265f);
    glVertex2f(0.243f,0.26f);

    glVertex2f(0.255f,0.24f);
    glVertex2f(0.224f,0.235f);
    ///Right Hand Rest part Border
    glVertex2f(0.255f,0.24f);
    glVertex2f(0.27f,0.24f);

    glVertex2f(0.243f,0.26f);
    glVertex2f(0.27f,0.26f);

    ///Left Hand with Sholder Border
    glVertex2f(0.182f,0.263f);
    glVertex2f(0.157f,0.26f);

    glVertex2f(0.175f,0.235f);
    glVertex2f(0.144f,0.24f);
    ///Left Hand Rest part Border
    glVertex2f(0.144f,0.24f);
    glVertex2f(0.135f,0.275f);

    glVertex2f(0.157f,0.26f);
    glVertex2f(0.148f,0.28f);
    ///Body Border
    glVertex2f(0.175f,0.235f);
    glVertex2f(0.175f,0.19f);

    glVertex2f(0.224f,0.19f);
    glVertex2f(0.224f,0.235f);

    ///Suit Design
    glVertex2f(0.2f,0.26f);
    glVertex2f(0.2f,0.19f);

    glVertex2f(0.2f,0.26f);
    glVertex2f(0.185f,0.265f);

    glVertex2f(0.2f,0.26f);
    glVertex2f(0.215f,0.265f);

    ///Pant Upper Part Border
    glVertex2f(0.175f,0.19f);
    glVertex2f(0.173f,0.175f);

    glVertex2f(0.226f,0.175f);
    glVertex2f(0.224f,0.19f);

    ///Right Leg1 Border
    glVertex2f(0.198f,0.175f);
    glVertex2f(0.206f,0.14f);

    glVertex2f(0.229f,0.14f);
    glVertex2f(0.226f,0.175f);

    ///Right Leg2 Border
    glVertex2f(0.206f,0.14f);
    glVertex2f(0.209f,0.12f);

    glVertex2f(0.232f,0.118f);
    glVertex2f(0.229f,0.14f);

    ///Right Leg shoe Border
    glVertex2f(0.208f,0.12f);
    glVertex2f(0.208f,0.1f);

    glVertex2f(0.24f,0.1f);
    glVertex2f(0.237f,0.116f);

    glVertex2f(0.232f,0.118f);
    glVertex2f(0.237f,0.116f);

    glVertex2f(0.208f,0.1f);
    glVertex2f(0.24f,0.1f);

    ///RIGHT Shoe lines
    glVertex2f(0.207f,0.13f);
    glVertex2f(0.232f,0.13f);

    glVertex2f(0.207f,0.135f);
    glVertex2f(0.23f,0.135f);
    ///Left Leg1 Border
    glVertex2f(0.173f,0.175f);
    glVertex2f(0.1667f,0.14f);

    glVertex2f(0.1897f,0.14f);
    glVertex2f(0.199f,0.175f);
    ///Left Leg2 Border
    glVertex2f(0.1667f,0.14f);
    glVertex2f(0.1664f,0.12f);

    glVertex2f(0.1894f,0.12f);
    glVertex2f(0.1897f,0.14f);
    ///Left Leg shoe Border
    glVertex2f(0.159f,0.117f);
    glVertex2f(0.159f,0.1f);

    glVertex2f(0.1895f,0.1f);
    glVertex2f(0.1895f,0.12f);

    glVertex2f(0.1664f,0.12f);
    glVertex2f(0.159f,0.117f);

    glVertex2f(0.159f,0.1f);
    glVertex2f(0.1895f,0.1f);

    ///LEFT Shoe lines
    glVertex2f(0.1667f,0.13f);
    glVertex2f(0.1895f,0.13f);

    glVertex2f(0.1667f,0.135f);
    glVertex2f(0.1895f,0.135f);

    glEnd();
    glPopMatrix();

    ///Flag BD
    glPushMatrix();
    glScalef(0.5,0.5,0);
    glTranslatef(positions5, 0.0f, 0.0f);
    glTranslatef(+0.5f, 0.3f, 0.0f);
    glLineWidth(5);
    glColor3f(0.62f, 0.506f, 0.278f);
    glBegin(GL_LINES);
    glVertex2f(0.5f,0.43f);
    glVertex2f(0.5f,0.15f);
    glEnd();

    GLfloat x[4], y[4], yy[4];
    GLdouble xt[300], yt[300], yyt[300], t;
    int i, c;

    x[0]=0.5;x[1]=0.55;x[2]=0.55;x[3]=0.6-xa;
    y[0]=0.41;y[1]=0.41+ya;y[2]=0.41-ya;y[3]=0.41;
    yy[0]=0.31;yy[1]=0.31+ya;yy[2]=0.31-ya;yy[3]=0.31;

    for(i=0, t=0, c=0; t<=1; i++, t=t+0.02)
    {
        xt[i] = pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
        yt[i] = pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
        yyt[i] = pow(1-t,3)*yy[0]+3*t*pow(1-t,2)*yy[1]+3*pow(t,2)*(1-t)*yy[2]+pow(t,3)*yy[3];
        c++;
    }

    glPointSize(4);
    glColor3f(0.0f, 0.404f, 0.298f);
    glBegin(GL_QUAD_STRIP);
    for(i=0; i<c; i++)
    {
        glVertex2d(xt[i],yt[i]);
        glVertex2d(xt[i],yyt[i]);
    }
    glEnd();

    ///red circle
    GLfloat xc=0.55f-xa, yc=0.36f, radiusc =.03f;

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xc, yc); // center of circle
    for(int ic = 0; ic <= triangleAmount; ic++)
    {
        glVertex2f( xc + (radiusc * cos(ic *  twicePi / triangleAmount)),
                    yc + (radiusc * sin(ic * twicePi / triangleAmount)) );
    }
    glEnd();
    glPopMatrix();

    ///Stairs
    glPushMatrix();
    glTranslatef(positions2,0.15f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.345f, 0.42f, 0.427f);
    glVertex2f(0.08f,0.02f);
    glVertex2f(0.077f,0.1f);
    glVertex2f(0.065f,0.1f);
    glVertex2f(0.065f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.06f);
    glVertex2f(0.035f,0.06f);
    glVertex2f(0.035f,0.04f);
    glVertex2f(0.02f,0.04f);
    glVertex2f(0.02f,0.02f);
    glEnd();
    glPopMatrix();

    ///Moonland Right side
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(1.0f,0.3f);
    glVertex2f(0.76f,0.3f);
    glColor3f(0.573f, 0.596f, 0.616f);
    glVertex2f(0.76f,0.0f);
    glVertex2f(1.0f,0.0f);
    glEnd();

    ///10
    glColor3f(0.647f, 0.647f, 0.647f); // Set color to red
    drawEllipse(0.9f, 0.07f, 0.057f, 0.02f, 100);

    glColor3f(0.51f, 0.51f, 0.51f); // Set color to red
    drawEllipse(0.9f, 0.07f, 0.052f, 0.015f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments

    glColor3f(0.518f, 0.518f, 0.518f); // Set color to red
    drawEllipse(0.9f, 0.07f, 0.047f, 0.01f, 100);



    ///Rocket
///_____________________________________________ROCKET(START)___________________________________________________///
    ///_________ 1________///
    glPushMatrix();
    glScalef(1.2,1.2,0);
    glTranslatef(+0.25f, positions, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.455, 0.525, 0.553);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    ///_________ 2________///
    glColor3f(0.345, 0.416, 0.424);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    ///_________ 3________///
    glColor3f(0.224, 0.49, 0.886);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    ///_________ 4________///
    glColor3f(0.478, 0.537, 0.565);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    ///_________ 5________///
    glColor3f(0.976, 0.475, 0.133);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glColor3f(0.925, 0.431, 0.075);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    ///_________ 6________///
    glColor3f(0.471, 0.529, 0.557);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glColor3f(0.208, 0.247, 0.251);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);

    ///_________ 9________///
    glColor3f(0.588, 0.647, 0.663);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    ///_________ 10________///
    glColor3f(0.976, 0.475, 0.133);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.835, 0.388, 0.09);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    ///_________ Upper and Lower border________///
    ///_______Lower L_____///
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.39f,0.34f);
    glVertex2f(0.39f,0.25f);
    glVertex2f(0.392f,0.25f);
    glVertex2f(0.392f,0.34f);
    ///_______Lower R_____///
    glVertex2f(0.4185f,0.34f);
    glVertex2f(0.4185f,0.25f);
    glVertex2f(0.42f,0.25f);
    glVertex2f(0.42f,0.34f);
    ///_______upper_____///
    glVertex2f(0.372f,0.452f);
    glVertex2f(0.372f,0.449f);
    glVertex2f(0.438f,0.449f);
    glVertex2f(0.438f,0.452f);

    glBegin(GL_QUADS);
    ///_________ 7(Wing 1)________///
    glColor3f(0.224, 0.494, 0.882);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    ///_________ 8(Wing 2)________///
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glEnd();

    ///_____________________________Rocket TOP window___________________________________///
    ///_________ 11________///
    glColor3f(0.976, 0.482, 0.125);
    GLfloat xrtw1=0.405f; GLfloat yrtw1=0.45f; GLfloat rrtw1 =.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrtw1, yrtw1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.976, 0.482, 0.125);
            glVertex2f( xrtw1 + (rrtw1 * cos(i *  twicePi / triangleAmount)),
                        yrtw1 + (rrtw1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 12________///
    glColor3f(0.314, 0.863, 0.98);
    GLfloat xrtw2=0.405f; GLfloat yrtw2=0.45f; GLfloat rrtw2 =.010f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrtw2, yrtw2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.863, 0.98);
            glVertex2f( xrtw2 + (rrtw2 * cos(i *  twicePi / triangleAmount)),
                        yrtw2 + (rrtw2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket bottom window___________________________________///
    ///_________ 13________///
    glColor3f(0.31, 0.847, 0.973);
    GLfloat xrbw3=0.405f; GLfloat yrbw3=0.30f; GLfloat rrbw3 =.010f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrbw3, yrbw3); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.31, 0.847, 0.973);
            glVertex2f( xrbw3 + (rrbw3 * cos(i *  twicePi / triangleAmount)),
                        yrbw3 + (rrbw3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Mini window___________________________________///
    ///_________ 14________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw1=0.385f; GLfloat yrmw1=0.52f; GLfloat rrmw1 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw1, yrmw1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw1 + (rrmw1 * cos(i *  twicePi / triangleAmount)),
                        yrmw1 + (rrmw1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 15________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw2=0.405f; GLfloat yrmw2=0.52f; GLfloat rrmw2 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw2, yrmw2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw2 + (rrmw2 * cos(i *  twicePi / triangleAmount)),
                        yrmw2 + (rrmw2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 16________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw3=0.425f; GLfloat yrmw3=0.52f; GLfloat rrmw3 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw3, yrmw3); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw3 + (rrmw3 * cos(i *  twicePi / triangleAmount)),
                        yrmw3 + (rrmw3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Border___________________________________///
    ///_________ 1________///
    glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    ///_________ 2________///
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    ///_________ 3________///
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    ///_________ 4________///
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    ///_________ 5________///
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    ///_________ 6________///
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    ///_________ 7(Wing 1)________///
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    ///_________ 8(Wing 2)________///
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    ///_________ 9________///
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    ///_________ 10________///
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glEnd();


    ///_____________________________Rocket TOP window(Border)___________________________________///
    ///_________ 11________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrtwb1=0.405f; GLfloat yrtwb1=0.45f; GLfloat rrtwb1 =.015f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrtwb1, yrtwb1); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrtwb1 + (rrtwb1 * cos(i *  twicePi / lineAmount)),
                        yrtwb1 + (rrtwb1 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
     ///_________ 12________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrtwb2=0.405f; GLfloat yrtwb2=0.45f; GLfloat rrtwb2 =.010f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrtwb2, yrtwb2); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrtwb2 + (rrtwb2 * cos(i *  twicePi / lineAmount)),
                        yrtwb2 + (rrtwb2 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
    ///_____________________________Rocket bottom window(Border)___________________________________///
    ///_________ 13________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrbwb3=0.405f; GLfloat yrbwb3=0.30f; GLfloat rrbwb3 =.010f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrbwb3, yrbwb3); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrbwb3 + (rrbwb3 * cos(i *  twicePi / lineAmount)),
                        yrbwb3 + (rrbwb3 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Mini window(Border)___________________________________///
    ///_________ 14________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb1=0.385f; GLfloat yrmwb1=0.52f; GLfloat rrmwb1 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb1, yrmwb1); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb1 + (rrmwb1 * cos(i *  twicePi / lineAmount)),
                        yrmwb1 + (rrmwb1 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
     ///_________ 15________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb2=0.405f; GLfloat yrmwb2=0.52f; GLfloat rrmwb2 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb2, yrmwb2); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb2 + (rrmwb2 * cos(i *  twicePi / lineAmount)),
                        yrmwb2 + (rrmwb2 * sin(i * twicePi /lineAmount)) );
        }
    glEnd();
     ///_________ 16________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb3=0.425f; GLfloat yrmwb3=0.52f; GLfloat rrmwb3 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb3, yrmwb3); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb3 + (rrmwb3 * cos(i *  twicePi / lineAmount)),
                        yrmwb3 + (rrmwb3 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();

    glPopMatrix();
    ///_____________________________________________ROCKET(END)___________________________________________________///



    glFlush(); // Render now
}



GLfloat A = 0.0f;
GLfloat P = 0.0f;
GLfloat Aspeed = 0.0;
GLfloat Pspeed = 0.0;
GLfloat Ospeed = 0.0;
GLfloat APosition = 0.0;
GLfloat PPosition = 0.0;
GLfloat OPosition = 0.0;


GLfloat meteorP3=0.0; GLfloat meteorP4=0.0;
GLfloat meteorS3=0.05;GLfloat meteorS4=0.03;

void meteorUpp(int value){

       if(meteorP3 < -1.0)
        meteorS3 = 0.5f;

        if(meteorP4 > 1.0)
        meteorS4 = 0.0f;

         meteorP3 -= meteorS3;
         meteorP4 += meteorS4;

	glutPostRedisplay();
	glutTimerFunc(100, meteorUpp, 0);

}


void display4() {
    glClearColor(0.016f, 0.016f, 0.016f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

///FULL SCREEN
    glBegin(GL_QUADS);
    glColor3f(0.082f, 0.133f, 0.169f);
    glVertex2f(0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(1.0f, 1.0);
    glColor3f(0.259f, 0.333f, 0.349f);
    glVertex2f(1.0f, 0.0f);
    glEnd();
    ///.................................Stars.........................
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(0.89f, 0.867f, 0.875f);
    glVertex2f(0.04f, 0.04f);
    glVertex2f(0.04f, 0.3f);
    glVertex2f(0.04f, 0.55f);
    glVertex2f(0.08f, 0.018f);
    glVertex2f(0.08f, 0.18f);
    glVertex2f(0.14f, 0.2f);
    glVertex2f(0.14f, 0.5f);
    glVertex2f(0.25f, 0.5f);
    glVertex2f(0.2f, 0.35f);
    glVertex2f(0.06f, 0.62f);
    glVertex2f(0.5f, 0.62f);
    glVertex2f(0.5f, 0.18f);
    glVertex2f(0.4f, 0.09f);
    glVertex2f(0.3f, 0.13f);
    glVertex2f(0.22f, 0.08f);
    glVertex2f(0.35f, 0.8f);
    glVertex2f(0.49f, 0.83f);
    glVertex2f(0.3f, 0.65f);
    glVertex2f(0.3f, 0.9f);
    glVertex2f(0.45f, 0.94f);
    glVertex2f(0.45f, 0.8f);
    glVertex2f(0.53f, 0.75f);
    glVertex2f(0.63f, 0.5f);
    glVertex2f(0.63f, 0.75f);
    glVertex2f(0.69f, 0.8f);
    glVertex2f(0.73f, 0.95f);
    glVertex2f(0.94f, 0.95f);
    glVertex2f(0.86f, 0.98f);
    glVertex2f(0.8f, 0.43f);
    glVertex2f(0.75f, 0.48f);
    glVertex2f(0.7f, 0.28f);
    glVertex2f(0.7f, 0.63f);
    glVertex2f(0.45f, 0.28f);
    glVertex2f(0.6f, 0.28f);
    glVertex2f(0.5f, 0.46f);
    glVertex2f(0.08f,0.66f);
    glVertex2f(0.2f,0.6f);
    glVertex2f(0.40f,0.52f);
    glVertex2f(0.28f,0.26f);
    glVertex2f(0.40f,0.7f);
    glVertex2f(0.56f,0.06f);
    glVertex2f(0.60f,0.9f);
    glVertex2f(0.84f,0.84f);
    glVertex2f(0.12f,0.4f);
    glVertex2f(0.32f,0.4f);
    glVertex2f(0.9f,0.83f);
    glVertex2f(0.8f,0.6f);
    glVertex2f(0.8f,0.9f);
    glVertex2f(0.95f,0.86f);
    glVertex2f(0.9f,0.66f);
    glVertex2f(0.97f,0.76f);
    glVertex2f(0.88f,0.56f);
    glVertex2f(0.98f,0.6f);
    glVertex2f(0.05f,0.8f);
    glVertex2f(0.06f,0.9f);
    glVertex2f(0.09f,0.86f);
    glVertex2f(0.16f,0.96f);
    glVertex2f(0.18f,0.83f);
    glEnd();

    ///________________________________Main____________________
    glPushMatrix();
    glTranslatef(0.0f,APosition,0.0f);
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.515f,-0.59f,0.0f);

    ///.......................................Cylinder .................
    glBegin(GL_QUADS);
    ///_______11 Right small rocket Body_____///
    glColor3f(0.196, 0.51, 0.984);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Body_____///
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    glBegin(GL_TRIANGLES);
    ///_______11 Right small rocket Head_____///
    glColor3f(0.98, 0.549, 0.11);
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Head_____///
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
     ///_______11 Right small rocket Body_____///
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.445f,0.39f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.445f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    ///_______12 Left small rocket Body_____///
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    glVertex2f(0.375f,0.39f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.375f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    ///_______11 Right small rocket Head_____///
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Head_____///
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    ///_________ Fire left ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.535,0.340,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    ///_________ Fire Right ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.685,0.340,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    glPopMatrix();

///_____________________________________________ROCKET(START)___________________________________________________///
    ///_________ 1________///
    glPushMatrix();
    glTranslatef(0.0f,PPosition,0.0f);
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.515f,-0.59f,0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.455, 0.525, 0.553);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    ///_________ 2________///
    glColor3f(0.345, 0.416, 0.424);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    ///_________ 3________///
    glColor3f(0.224, 0.49, 0.886);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    ///_________ 4________///
    glColor3f(0.478, 0.537, 0.565);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    ///_________ 5________///
    glColor3f(0.976, 0.475, 0.133);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glColor3f(0.925, 0.431, 0.075);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    ///_________ 6________///
    glColor3f(0.471, 0.529, 0.557);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glColor3f(0.208, 0.247, 0.251);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);

    ///_________ 9________///
    glColor3f(0.588, 0.647, 0.663);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    ///_________ 10________///
    glColor3f(0.976, 0.475, 0.133);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.835, 0.388, 0.09);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    ///_________ Upper and Lower border________///
    ///_______Lower L_____///
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.39f,0.34f);
    glVertex2f(0.39f,0.25f);
    glVertex2f(0.392f,0.25f);
    glVertex2f(0.392f,0.34f);
    ///_______Lower R_____///
    glVertex2f(0.4185f,0.34f);
    glVertex2f(0.4185f,0.25f);
    glVertex2f(0.42f,0.25f);
    glVertex2f(0.42f,0.34f);
    ///_______upper_____///
    glVertex2f(0.372f,0.452f);
    glVertex2f(0.372f,0.449f);
    glVertex2f(0.438f,0.449f);
    glVertex2f(0.438f,0.452f);
    glEnd();
    glBegin(GL_QUADS);
    ///_________ 7(Wing 1)________///
    glColor3f(0.224, 0.494, 0.882);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    ///_________ 8(Wing 2)________///
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glEnd();

    ///_____________________________Rocket TOP window___________________________________///
    ///_________ 11________///
    glColor3f(0.976, 0.482, 0.125);
    GLfloat xrtw1=0.405f; GLfloat yrtw1=0.45f; GLfloat rrtw1 =.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrtw1, yrtw1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.976, 0.482, 0.125);
            glVertex2f( xrtw1 + (rrtw1 * cos(i *  twicePi / triangleAmount)),
                        yrtw1 + (rrtw1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 12________///
    glColor3f(0.314, 0.863, 0.98);
    GLfloat xrtw2=0.405f; GLfloat yrtw2=0.45f; GLfloat rrtw2 =.010f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrtw2, yrtw2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.863, 0.98);
            glVertex2f( xrtw2 + (rrtw2 * cos(i *  twicePi / triangleAmount)),
                        yrtw2 + (rrtw2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket bottom window___________________________________///
    ///_________ 13________///
    glColor3f(0.31, 0.847, 0.973);
    GLfloat xrbw3=0.405f; GLfloat yrbw3=0.30f; GLfloat rrbw3 =.010f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrbw3, yrbw3); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.31, 0.847, 0.973);
            glVertex2f( xrbw3 + (rrbw3 * cos(i *  twicePi / triangleAmount)),
                        yrbw3 + (rrbw3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Mini window___________________________________///
    ///_________ 14________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw1=0.385f; GLfloat yrmw1=0.52f; GLfloat rrmw1 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw1, yrmw1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw1 + (rrmw1 * cos(i *  twicePi / triangleAmount)),
                        yrmw1 + (rrmw1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 15________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw2=0.405f; GLfloat yrmw2=0.52f; GLfloat rrmw2 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw2, yrmw2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw2 + (rrmw2 * cos(i *  twicePi / triangleAmount)),
                        yrmw2 + (rrmw2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 16________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw3=0.425f; GLfloat yrmw3=0.52f; GLfloat rrmw3 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw3, yrmw3); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw3 + (rrmw3 * cos(i *  twicePi / triangleAmount)),
                        yrmw3 + (rrmw3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Border___________________________________///
    ///_________ 1________///
    glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    ///_________ 2________///
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    ///_________ 3________///
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    ///_________ 4________///
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    ///_________ 5________///
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    ///_________ 6________///
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    ///_________ 7(Wing 1)________///
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    ///_________ 8(Wing 2)________///
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    ///_________ 9________///
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    ///_________ 10________///
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glEnd();


    ///_____________________________Rocket TOP window(Border)___________________________________///
    ///_________ 11________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrtwb1=0.405f; GLfloat yrtwb1=0.45f; GLfloat rrtwb1 =.015f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrtwb1, yrtwb1); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrtwb1 + (rrtwb1 * cos(i *  twicePi / lineAmount)),
                        yrtwb1 + (rrtwb1 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
     ///_________ 12________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrtwb2=0.405f; GLfloat yrtwb2=0.45f; GLfloat rrtwb2 =.010f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrtwb2, yrtwb2); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrtwb2 + (rrtwb2 * cos(i *  twicePi / lineAmount)),
                        yrtwb2 + (rrtwb2 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
    ///_____________________________Rocket bottom window(Border)___________________________________///
    ///_________ 13________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrbwb3=0.405f; GLfloat yrbwb3=0.30f; GLfloat rrbwb3 =.010f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrbwb3, yrbwb3); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrbwb3 + (rrbwb3 * cos(i *  twicePi / lineAmount)),
                        yrbwb3 + (rrbwb3 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Mini window(Border)___________________________________///
    ///_________ 14________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb1=0.385f; GLfloat yrmwb1=0.52f; GLfloat rrmwb1 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb1, yrmwb1); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb1 + (rrmwb1 * cos(i *  twicePi / lineAmount)),
                        yrmwb1 + (rrmwb1 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
     ///_________ 15________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb2=0.405f; GLfloat yrmwb2=0.52f; GLfloat rrmwb2 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb2, yrmwb2); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb2 + (rrmwb2 * cos(i *  twicePi / lineAmount)),
                        yrmwb2 + (rrmwb2 * sin(i * twicePi /lineAmount)) );
        }
    glEnd();
     ///_________ 16________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb3=0.425f; GLfloat yrmwb3=0.52f; GLfloat rrmwb3 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb3, yrmwb3); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb3 + (rrmwb3 * cos(i *  twicePi / lineAmount)),
                        yrmwb3 + (rrmwb3 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();

    ///_________ Fire main 1________///
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.20f);
    glVertex2f(0.36f,0.14f);
    glVertex2f(0.388f,0.17f);
    glVertex2f(0.4f,0.12f);
    glVertex2f(0.42f,0.18f);
    glVertex2f(0.45f,0.14f);
    glVertex2f(0.42f,0.20f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.20f);
    glVertex2f(0.38f,0.168f);
    glVertex2f(0.395f,0.19f);
    glVertex2f(0.40f,0.14f);
    glVertex2f(0.41f,0.19f);
    glVertex2f(0.43f,0.17f);
    glVertex2f(0.417f,0.20f);
    glEnd();
    ///_________ Fire main 2________///
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    ///_____________________________________________ROCKET(END)___________________________________________________///


    ///STAR 2
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(1.60f,6.00f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 3
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(2.50f,3.20f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 4
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(2.40f,4.6f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 5
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(3.40f,4.f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();


    ///STAR 6
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(3.30f,6.f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 7
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(5.10f,6.20f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR 8
	glPushMatrix();
	glScalef(.15,.15,0);
	glTranslatef(4.1f,5.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

///something
    glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(0.50f,1.50f,0.0f);
    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.14f,0.18f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.14f,0.18f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
	glScalef(.3,.3,0);
	glTranslatef(1.0f,0.50f,0.0f);
    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.14f,0.18f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.03f,0.09f);
    glVertex2f(.06f,0.15f);
    glVertex2f(.09f,0.09f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.13f,0.11f);
    glVertex2f(.14f,0.18f);
    glEnd();
    glPopMatrix();

    glPointSize(4.9);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.9f,0.9f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(.91f,0.9f);
    glVertex2f(.89f,0.9f);
    glVertex2f(.90f,0.91f);
    glVertex2f(.901f,0.89f);

    glEnd();

     glPushMatrix();
    glTranslatef(meteorP4,meteorP3,0.0f);

    ///........Meteor - 1..........................................
    glPushMatrix();
    glTranslatef(OPosition,0.0f, 0.0f);
    glScalef(.2,.2,0);
	glTranslatef(1.10f,4.10f,0.0f);
    glBegin(GL_POLYGON);
    glColor4f(1.0f,1.0f,1.0f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.43f,0.614f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor4f(0.722f,0.718f,0.706f,0.5f);
    glVertex2f(0.487f,0.5f);
    glVertex2f(0.48f,0.499f);
    glVertex2f(0.514f,0.4985f);
    glEnd();
    glPopMatrix();

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    GLfloat A81=0.5f; GLfloat P81=0.5f; GLfloat O81 =0.013f;
    glColor3f(0.945f, 0.663f, 0.165f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A81, P81); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A81 + (O81 * cos(i *  twicePi/ triangleAmount)),
                        P81 + (O81 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Meteor Inside Circle
    GLfloat A82=0.505f; GLfloat P82=0.5045f; GLfloat O82 =0.005f;
    glColor3f(0.965f, 0.859f, 0.518f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A82, P82); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A82 + (O82 * cos(i *  twicePi/ triangleAmount)),
                        P82 + (O82 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    ///........................................Earth.....................................................///


    glPushMatrix();
    glTranslatef(0.42f, -0.20f, 0.0f);
    glPushMatrix();
    glScalef(0.9,0.9,0);

    GLfloat A0=0.54f; GLfloat P0=0.32f; GLfloat O0 =0.27f;
    glColor3f(0.0f, 0.651f, 0.886f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A0, P0); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A0 + (O0 * cos(i *  twicePi/ triangleAmount)),
                        P0 + (O0 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();

    ///.........................Earth Inside Light Green-1
    ///1
    glPushMatrix();
    glScalef(7.50,7.50,0);
    glPushMatrix();
    glLoadIdentity();//Reset the current matrix
    glTranslatef(0.30,-1.20,0);
    glRotatef(A,0.0,0.0,1.0);//
    GLfloat A1=0.54f; GLfloat P1=0.5f; GLfloat O1 =0.06f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A1, P1); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A1 + (O1 * cos(i *  twicePi / triangleAmount)),
                        P1 + (O1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///2
    GLfloat A2=0.46f; GLfloat P2=0.52f; GLfloat O2 =0.04f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A2, P2); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A2 + (O2 * cos(i *  twicePi / triangleAmount)),
                        P2 + (O2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///3
    GLfloat A3=0.4f; GLfloat P3=0.422f; GLfloat O3 =0.0975f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A3, P3); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A3 + (O3 * cos(i *  twicePi / triangleAmount)),
                        P3 + (O3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///4
    GLfloat A4=0.48f; GLfloat P4=0.4f; GLfloat O4 =0.08f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A4, P4); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A4 + (O4 * cos(i *  twicePi / triangleAmount)),
                        P4 + (O4 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///Earth Inside Dark Green-1
    ///1
    GLfloat A5=0.5f; GLfloat P5=0.5f; GLfloat O5 =0.047f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A5, P5); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A5 + (O5 * cos(i *  twicePi / triangleAmount)),
                        P5 + (O5 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///2
    GLfloat A6=0.46f; GLfloat P6=0.52f; GLfloat O6 =0.056f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A6, P6); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A6 + (O6 * cos(i *  twicePi / triangleAmount)),
                        P6 + (O6 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///3
    GLfloat A7=0.4f; GLfloat P7=0.465f; GLfloat O7 =0.069f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A7, P7); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A7 + (O7 * cos(i *  twicePi / triangleAmount)),
                        P7 + (O7 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///4
    GLfloat A8=0.48f; GLfloat P8=0.45f; GLfloat O8 =0.045f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A8, P8); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A8 + (O8 * cos(i *  twicePi / triangleAmount)),
                        P8 + (O8 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///5
    GLfloat A9=0.45f; GLfloat P9=0.43f; GLfloat O9 =0.045f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A9, P9); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A9 + (O9 * cos(i *  twicePi / triangleAmount)),
                        P9 + (O9 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///6
    GLfloat A10=0.415f; GLfloat P10=0.503f; GLfloat O10 =0.049f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A10, P10); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A10 + (O10 * cos(i *  twicePi / triangleAmount)),
                        P10 + (O10 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///7
    GLfloat A1000=0.4f; GLfloat P1000=0.5f; GLfloat O1000 =0.043f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A1000, P1000); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A1000 + (O1000 * cos(i *  twicePi / triangleAmount)),
                        P1000 + (O1000 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///8
    GLfloat A1001=0.43f; GLfloat P1001=0.518f; GLfloat O1001 =0.0435f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A1001, P1001); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A1001 + (O1001 * cos(i *  twicePi / triangleAmount)),
                        P1001 + (O1001 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///.........................Earth Inside Light Green-2
    ///1
    GLfloat A11=0.48f; GLfloat P11=0.2f; GLfloat O11 =0.04f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A11, P11); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A11 + (O11 * cos(i *  twicePi / triangleAmount)),
                        P11 + (O11 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///2
    GLfloat A12=0.44f; GLfloat P12=0.17f; GLfloat O12 =0.06f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A12, P12); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A12 + (O12 * cos(i *  twicePi / triangleAmount)),
                        P12 + (O12 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///3
    GLfloat A13=0.44f; GLfloat P13=0.22f; GLfloat O13 =0.06f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A13, P13); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A13 + (O13 * cos(i *  twicePi / triangleAmount)),
                        P13 + (O13 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///4
    GLfloat A14=0.54f; GLfloat P14=0.15f; GLfloat O14 =0.06f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A14, P14); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A14 + (O14 * cos(i *  twicePi / triangleAmount)),
                        P14 + (O14 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///Earth Inside Dark Green-2
    ///1
    GLfloat A15=0.48f; GLfloat P15=0.21f; GLfloat O15 =0.04f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A15, P15); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A15 + (O15 * cos(i *  twicePi / triangleAmount)),
                        P15 + (O15 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///2
    GLfloat A16=0.46f; GLfloat P16=0.17f; GLfloat O16 =0.041f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A16, P16); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A16 + (O16 * cos(i *  twicePi / triangleAmount)),
                        P16 + (O16 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///3
    GLfloat A17=0.435f; GLfloat P17=0.23f; GLfloat O17 =0.04f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A17, P17); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A17 + (O17 * cos(i *  twicePi / triangleAmount)),
                        P17 + (O17 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///4
    GLfloat A18=0.41f; GLfloat P18=0.2f; GLfloat O18 =0.04f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A18, P18); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A18 + (O18 * cos(i *  twicePi / triangleAmount)),
                        P18 + (O18 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///.........................Earth Inside Light Green-3
    ///1
    GLfloat A19=0.76f; GLfloat P19=0.38f; GLfloat O19 =0.04f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A19, P19); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A19 + (O19 * cos(i *  twicePi / triangleAmount)),
                        P19 + (O19 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///2
    GLfloat A20=0.74f; GLfloat P20=0.32f; GLfloat O20 =0.07f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A20, P20); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A20 + (O20 * cos(i *  twicePi / triangleAmount)),
                        P20 + (O20 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///3
    GLfloat A21=0.7f; GLfloat P21=0.35f; GLfloat O21 =0.06f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A21, P21); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A21 + (O21 * cos(i *  twicePi / triangleAmount)),
                        P21 + (O21 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///4
    GLfloat A22=0.67f; GLfloat P22=0.29f; GLfloat O22 =0.06f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A22, P22); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A22 + (O22 * cos(i *  twicePi / triangleAmount)),
                        P22 + (O22 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///5
    GLfloat A23=0.72f; GLfloat P23=0.27f; GLfloat O23 =0.07f;
    glColor3f(0.659f, 0.843f, 0.33f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A23, P23); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A23 + (O23 * cos(i *  twicePi / triangleAmount)),
                        P23 + (O23 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///Earth Inside Dark Green-3
    ///1
    GLfloat A24=0.76f; GLfloat P24=0.38f; GLfloat O24 =0.027f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A24, P24); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A24 + (O24 * cos(i *  twicePi / triangleAmount)),
                        P24 + (O24 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///2
    GLfloat A25=0.75f; GLfloat P25=0.34f; GLfloat O25 =0.05f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A25, P25); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A25 + (O25 * cos(i *  twicePi / triangleAmount)),
                        P25 + (O25 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///3
    GLfloat A26=0.7f; GLfloat P26=0.35f; GLfloat O26 =0.04f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A26, P26); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A26 + (O26 * cos(i *  twicePi / triangleAmount)),
                        P26 + (O26 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///4
    GLfloat A27=0.69f; GLfloat P27=0.29f; GLfloat O27 =0.04f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A27, P27); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A27 + (O27 * cos(i *  twicePi / triangleAmount)),
                        P27 + (O27 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///5
    GLfloat A28=0.72f; GLfloat P28=0.27f; GLfloat O28 =0.05f;
    glColor3f(0.502f, 0.753f, 0.263f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A28, P28); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A28 + (O28 * cos(i *  twicePi / triangleAmount)),
                        P28 + (O28 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    A+=0.001f;
    glPopMatrix();

    /// ................EARTH'S Border........................................................///
    glLineWidth(3);
    GLfloat A29=0.54f; GLfloat P29=0.32f; GLfloat O29 =0.27f;
    glColor3f(0.259f, 0.333f, 0.349f);
	glBegin(GL_LINE_LOOP);
		for(int i = 0; i <= lineAmount;i++)
            {
			glVertex2f(
			    A29 + (O29 * cos(i *  twicePi / lineAmount)),
			    P29 + (O29* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();


    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

	///..................................Planet...........................................///
	glPushMatrix();
	glTranslatef(0.05f,0.2f,0.0f);
	glScalef(0.6f,0.6f,0.0f);
    GLfloat A30=0.09f; GLfloat P30=0.9f; GLfloat O30 =0.13f;
    glColor3f(0.659f, 0.392f, 0.886f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A30, P30); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A30 + (O30 * cos(i *  twicePi / triangleAmount)),
                        P30 + (O30 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();

    ///Black Spot
    /// 1.
    GLfloat A33=0.07f; GLfloat P33=0.795f; GLfloat O33 =0.022f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A33, P33); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A33 + (O33 * cos(i *  twicePi / triangleAmount)),
                        P33 + (O33 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 1
    GLfloat A34=0.07f; GLfloat P34=0.795f; GLfloat O34 =0.013f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A34, P34); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A34 + (O34 * cos(i *  twicePi / triangleAmount)),
                        P34 + (O34 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// 2.
    GLfloat A35=0.185f; GLfloat P35=0.86f; GLfloat O35 =0.025f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A35, P35); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A35 + (O35 * cos(i *  twicePi / triangleAmount)),
                        P35 + (O35 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 2
    GLfloat A36=0.18f; GLfloat P36=0.86f; GLfloat O36 =0.015f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A36, P36); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A36 + (O36 * cos(i *  twicePi / triangleAmount)),
                        P36 + (O36 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// 3.
    GLfloat A37=0.13f; GLfloat P37=0.82f; GLfloat O37 =0.019f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A37, P37); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A37 + (O37 * cos(i *  twicePi / triangleAmount)),
                        P37 + (O37 * sin(i * twicePi / triangleAmount)) );

        }
        glEnd();
    /// Inside Round of Number 3
    GLfloat A38=0.125f; GLfloat P38=0.82f; GLfloat O38 =0.01f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A38, P38); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A38 + (O38 * cos(i *  twicePi / triangleAmount)),
                        P38 + (O38 * sin(i * twicePi / triangleAmount)) );

        }
        glEnd();
    /// 4.
    GLfloat A39=0.015f; GLfloat P39=0.85f; GLfloat O39 =0.03f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A39, P39); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A39 + (O39 * cos(i *  twicePi / triangleAmount)),
                        P39 + (O39 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 4
    GLfloat A40=0.015f; GLfloat P40=0.85f; GLfloat O40 =0.017f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A40, P40); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A40 + (O40 * cos(i *  twicePi / triangleAmount)),
                        P40 + (O40 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///5.
    GLfloat A41=0.09f; GLfloat P41=0.85f; GLfloat O41 =0.015f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A41, P41); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A41 + (O41 * cos(i *  twicePi / triangleAmount)),
                        P41 + (O41 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 5
    GLfloat A42=0.09f; GLfloat P42=0.85f; GLfloat O42 =0.009f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A42, P42); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A42 + (O42 * cos(i *  twicePi / triangleAmount)),
                        P42 + (O42 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///6.
    GLfloat A43=0.13f; GLfloat P43=0.89f; GLfloat O43 =0.022f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A43, P43); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A43 + (O43 * cos(i *  twicePi / triangleAmount)),
                        P43 + (O43 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 6
    GLfloat A44=0.13f; GLfloat P44=0.89f; GLfloat O44 =0.013f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A44, P44); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A44 + (O44 * cos(i *  twicePi / triangleAmount)),
                        P44 + (O44 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///7.
    GLfloat A45=0.194f; GLfloat P45=0.93f; GLfloat O45 =0.022f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A45, P45); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A45 + (O45 * cos(i *  twicePi / triangleAmount)),
                        P45 + (O45 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 7
    GLfloat A46=0.19f; GLfloat P46=0.93f; GLfloat O46 =0.013f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A46, P46); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A46 + (O46 * cos(i *  twicePi / triangleAmount)),
                        P46 + (O46 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///8.
    GLfloat A47=0.15f; GLfloat P47=0.98f; GLfloat O47 =0.03f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A47, P47); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A47 + (O47 * cos(i *  twicePi / triangleAmount)),
                        P47 + (O47 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 8
    GLfloat A48=0.15f; GLfloat P48=0.985f; GLfloat O48 =0.019f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A48, P48); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A48 + (O48 * cos(i *  twicePi / triangleAmount)),
                        P48 + (O48 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///9.
    GLfloat A49=0.11f; GLfloat P49=0.94f; GLfloat O49 =0.015f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A49, P49); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A49 + (O49 * cos(i *  twicePi / triangleAmount)),
                        P49 + (O49 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 9
    GLfloat A50=0.11f; GLfloat P50=0.94f; GLfloat O50 =0.01f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A50, P50); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A50 + (O50 * cos(i *  twicePi / triangleAmount)),
                        P50 + (O50 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///10.
    GLfloat A51=0.07f; GLfloat P51=0.9f; GLfloat O51 =0.022f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A51, P51); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A51 + (O51 * cos(i *  twicePi / triangleAmount)),
                        P51 + (O51 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 10
    GLfloat A52=0.07f; GLfloat P52=0.9f; GLfloat O52 =0.013f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A52, P52); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A52 + (O52 * cos(i *  twicePi / triangleAmount)),
                        P52 + (O52 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///12.
    GLfloat A53=0.09f; GLfloat P53=0.99f; GLfloat O53 =0.025f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A53, P53); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A53 + (O53 * cos(i *  twicePi / triangleAmount)),
                        P53 + (O53 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 12
    GLfloat A54=0.09f; GLfloat P54=0.99f; GLfloat O54 =0.015f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A54, P54); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A54 + (O54 * cos(i *  twicePi / triangleAmount)),
                        P54 + (O54 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///13.
    GLfloat A55=0.038f; GLfloat P55=0.95f; GLfloat O55 =0.02f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A55, P55); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A55 + (O55 * cos(i *  twicePi / triangleAmount)),
                        P55 + (O55 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    /// Inside Round of Number 13
    GLfloat A56=0.038f; GLfloat P56=0.95f; GLfloat O56 =0.012f;
    glColor3f(0.525f, 0.267f, 0.749f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A56, P56); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A56 + (O56 * cos(i *  twicePi / triangleAmount)),
                        P56 + (O56 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();

    /// Small Circle
    ///1.
    GLfloat A57=0.04f; GLfloat P57=0.995f; GLfloat O57 =0.015f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A57, P57); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A57 + (O57 * cos(i *  twicePi / triangleAmount)),
                        P57 + (O57 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///2.
    GLfloat A58=0.06f; GLfloat P58=0.835f; GLfloat O58 =0.01f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A58, P58); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A58 + (O58 * cos(i *  twicePi / triangleAmount)),
                        P58 + (O58 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///3.
    GLfloat A59=0.03f; GLfloat P59=0.9f; GLfloat O59 =0.013f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A59, P59); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A59 + (O59 * cos(i *  twicePi / triangleAmount)),
                        P59 + (O59 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///4.
    GLfloat A60=0.075f; GLfloat P60=0.945f; GLfloat O60 =0.013f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A60, P60); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A60 + (O60 * cos(i *  twicePi / triangleAmount)),
                        P60 + (O60 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///6.
    GLfloat A62=0.007f; GLfloat P62=0.97f; GLfloat O62 =0.013f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A62, P62); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A62 + (O62 * cos(i *  twicePi / triangleAmount)),
                        P62 + (O62 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///7.
    GLfloat A63=0.007f; GLfloat P63=0.92f; GLfloat O63 =0.01f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A63, P63); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A63 + (O63 * cos(i *  twicePi / triangleAmount)),
                        P63 + (O63 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///8.
    GLfloat A64=0.16f; GLfloat P64=0.92f; GLfloat O64 =0.01f;
    glColor3f(0.565f, 0.329f, 0.773f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A64, P64); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A64 + (O64 * cos(i *  twicePi / triangleAmount)),
                        P64 + (O64 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    glPopMatrix();

    ///.............................................Planet...........MARS....................................///
    GLfloat A31=0.9f; GLfloat P31=0.75f; GLfloat O31 =0.030f;
    glColor3f(0.741f, 0.275f, 0.157f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A31, P31); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glColor3f( 0.878f, 0.4f, 0.263f);
            glVertex2f( A31 + (O31 * cos(i *  twicePi/ triangleAmount)),
                        P31 + (O31 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Planet...........Venus
    GLfloat A32=0.07f; GLfloat P32=0.20f; GLfloat O32 =0.035f;
    glColor3f(0.753f, 0.62f, 0.439f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A32, P32); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
               glColor3f(0.545f, 0.439f, 0.231f);
            glVertex2f( A32 + (O32 * cos(i *  twicePi/ triangleAmount)),
                        P32 + (O32 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///Circle Starts From 81

    ///..............................................Moon................................
    GLfloat A65=0.55f; GLfloat P65=0.95f; GLfloat O65 =0.13f;
    glColor3f(0.925f, 0.925f, 0.925f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A65, P65); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
                glColor3f(0.694f, 0.694f, 0.694f);
            glVertex2f( A65 + (O65 * cos(i *  twicePi / triangleAmount)),
                        P65 + (O65 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();
    ///..................................moon...................................................///
    ///moon
    glColor3f(0.686, 0.686, 0.686); // Set color to re
    drawEllipse(0.55f, 0.95f, 0.02f, 0.005f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments







///...................................satrun ...................................................///
    glPushMatrix();
    glScalef(0.7f,0.7f,0.0f);
    glTranslatef(0.05f,0.3f,0.0f);
    glColor3f(0.824, 0.518, 0.337); // Set color to re
    drawEllipse(0.4f, 0.4f, 0.05f, 0.05f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments
    glColor3f(0.91, 0.765, 0.608); // Set color to red
    drawEllipse1(0.4f, 0.4f, 0.07f, 0.01f, 100); // Center (0.5, 0.5), radiusX = 0.3, radiusY = 0.2, 100 segments
    glBegin(GL_QUADS);
    glColor3f(0.824, 0.518, 0.337);
    glVertex2f(0.351f,0.413f);
    glVertex2f(0.351f,0.404f);
    glVertex2f(0.449f,0.404f);
    glVertex2f(0.449f,0.413f);
    glEnd();
    glPopMatrix();


    /// PLANET A
    GLfloat A66=0.20f; GLfloat P66=0.20f; GLfloat O66 =0.01f;
    glColor3f(0.212f, 0.341f, 0.431f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A66, P66); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A66 + (O66 * cos(i *  twicePi / triangleAmount)),
                        P66 + (O66 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();

    ///PLANET B

    GLfloat A67=0.70f; GLfloat P67=0.50f; GLfloat O67 =0.01f;
    glColor3f(0.243f, 0.306f, 0.349f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A67, P67); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A67 + (O67 * cos(i *  twicePi / triangleAmount)),
                        P67 + (O67 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();

    ///PLANET C
    GLfloat A68=0.50f; GLfloat P68=0.10f; GLfloat O68 =0.01f;
    glColor3f(0.243f, 0.306f, 0.349f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A68, P68); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A68 + (O68 * cos(i *  twicePi / triangleAmount)),
                        P68 + (O68 * sin(i * twicePi / triangleAmount)) );

        }
      glEnd();

      ///PLANET D
    GLfloat A69=0.25f; GLfloat P69=0.50f; GLfloat O69 =0.01f;
    glColor3f(0.243f, 0.306f, 0.349f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A69, P69); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A69 + (O69 * cos(i *  twicePi / triangleAmount)),
                        P69 + (O69 * sin(i * twicePi / triangleAmount)) );

        }
      glEnd();

      ///PLANET E
    GLfloat A70=0.15f; GLfloat P70=0.90f; GLfloat O70 =0.01f;
    glColor3f(0.243f, 0.306f, 0.349f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(A70, P70); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( A70 + (O70 * cos(i *  twicePi / triangleAmount)),
                        P70 + (O70 * sin(i * twicePi / triangleAmount)) );

        }
    glEnd();




    ///...................................Satellite...................................................///
    glPushMatrix();
    glScalef(0.5f,0.5f,0.0f);
    glTranslatef(1.8f,0.4f, 0.0f);
    glRotatef(P,0.0,0.40,1.0);
    ///body
    glBegin(GL_QUADS);
    glColor3f(0.071f, 0.035f, 0.035f);
    glVertex2f(0.10f,0.60f);
    glColor3f(0.898f,0.898f,0.898f);
    glVertex2f(0.12f,0.60f);
    glColor3f(0.898f,0.898f,0.898f);
    glVertex2f(0.12f,0.65f);
    glColor3f(0.071f, 0.035f, 0.035f);
    glVertex2f(0.10f,0.65f);
    ///RIGHT WINGS
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.125f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.175f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.175f,0.645f);
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.125f,0.645f);
    ///LEFT WINGS
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.095f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.045f,0.605f);
    glColor3f(0.486f, 0.561f, 0.557f);
    glVertex2f(0.045f,0.645f);
    glColor3f(0.341f, 0.561f, 0.557f);
    glVertex2f(0.095,0.645f);
    glEnd();
///LINES
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.773f, 0.788f, 0.776f);
    ///right
    glVertex2f(0.12f,0.625f);
    glVertex2f(0.125f,0.625f);

    ///left
    glVertex2f(0.10f,0.625f);
    glVertex2f(0.095f,0.625f);
    ///upper
    glVertex2f(0.105f,0.65f);
    glVertex2f(0.105f,0.66f);
    glVertex2f(0.115f,0.65f);
    glVertex2f(0.115f,0.66f);
    ///with mini circle
    glVertex2f(0.11f,0.68f);
    glVertex2f(0.11f,0.69f);

    glVertex2f(0.12f,0.68f);
    glVertex2f(0.11f,0.69f);

    glVertex2f(0.10f,0.68f);
    glVertex2f(0.11f,0.69);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    ///MIDDLE IN RIGHT WINGS
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.125f,0.615f);
    glVertex2f(0.175f,0.615f);
    glVertex2f(0.125f,0.625f);
    glVertex2f(0.175f,0.625f);
    glVertex2f(0.125f,0.635f);
    glVertex2f(0.175f,0.635f);
    glVertex2f(0.135f,0.605f);
    glVertex2f(0.135f,0.645f);
    glVertex2f(0.145f,0.605f);
    glVertex2f(0.145f,0.645f);
    glVertex2f(0.155f,0.605f);
    glVertex2f(0.155f,0.645f);
    glVertex2f(0.165f,0.605f);
    glVertex2f(0.165f,0.645f);
    ///MIDDLE LINE IN LEFT WINGS
    glVertex2f(0.095f,0.615f);
    glVertex2f(0.045f,0.615f);
    glVertex2f(0.095f,0.625f);
    glVertex2f(0.045f,0.625f);
    glVertex2f(0.095f,0.635f);
    glVertex2f(0.045f,0.635f);
    glVertex2f(0.055f,0.605f);
    glVertex2f(0.055f,0.645f);
    glVertex2f(0.065f,0.605f);
    glVertex2f(0.065f,0.645f);
    glVertex2f(0.075f,0.605f);
    glVertex2f(0.075f,0.645f);
    glVertex2f(0.085f,0.605f);
    glVertex2f(0.085f,0.645f);
    glEnd();
    ///mini circle
    GLfloat A83=0.11f, P83=0.70f, O83=.005;
    GLfloat twicePi = 2.0f * PI;
    glColor3f(0.812f, 0.89f, 0.98f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(A83, P83); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( A83 + (O83 * cos(i *  twicePi / triangleAmount)),
                    P83 + (O83 * sin(i * twicePi / triangleAmount)) );
        glColor3f(1.0f, 1.0f, 1.0f);
    }
    glEnd();
    ///HALF CIRCLE
    GLfloat A84=0.11f, P84=0.68f, O84=.025;
    twicePi= -1.0f *PI;
    glColor3f(0.086f, 0.149f, 0.149f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(A84, P84); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( A84 + (O84 * cos(i *  twicePi / triangleAmount)),
                    P84 + (O84 * sin(i * twicePi / triangleAmount)) );
        glColor3f(0.294f, 0.388f, 0.388f);
    }
    glEnd();
    P+=0.003f;
    glPopMatrix();


    glFlush(); // Render now
}

///...........Separate
void updateA(int value)
{
    if(APosition >2.0 )
        APosition = -1.0f;
    APosition += Aspeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateA, 0);
}
///.........Rocket
void updateP(int value)
{
    if(PPosition >2.0 )
        PPosition = -1.0f;
    PPosition += Pspeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateP, 0);
}


GLfloat Position1 = 0.0f;
GLfloat Position2 = 0.0f;
GLfloat Position3 = 0.0f;
GLfloat Speed1 = 0.0f;
GLfloat Speed2 = 0.0f;
GLfloat Speed3 = 0.0f;

void display2() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
///___________________________________________________start___________________________________________________///


///_________________________________________________SKY(1)___________________________________________________///

    glBegin(GL_QUADS);
    glColor3f(0.184, 0.702, 0.945);
    glVertex2f(0.0f,1.00f);
    glColor3f(0.514, 0.792, 0.976);
    glVertex2f(0.0f,0.00f);
    glVertex2f(1.0f,0.00f);
    glColor3f(0, 0.502, 0.757);
    glVertex2f(1.0f,1.00f);
    glEnd();

///_________________________________________________SUN___________________________________________________///
    glColor3ub(243,149,0);
    GLfloat xs=0.79f; GLfloat ys=0.89f; GLfloat rs =.045f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xs, ys); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3ub(250, 235, 0.0);
            glVertex2f( xs + (rs * cos(i *  twicePi / triangleAmount)),
                        ys + (rs * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///_________________________________________________Clouds 1___________________________________________________///
    ///_________ 11 ________///
    glPushMatrix();
    glTranslatef(Position1, 0.0, 0.0);  // Move the cloud horizontally
    GLfloat xc11=0.120f; GLfloat yc11=0.92f; GLfloat rc11 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc11, yc11);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc11 + (rc11 * cos(i*  twicePi / triangleAmount)),
                        yc11 + (rc11 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 12 ________///
    GLfloat xc12=0.140f; GLfloat yc12=0.94f; GLfloat rc12 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc12, yc12); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc12 + (rc12 * cos(i *  twicePi / triangleAmount)),
                        yc12 + (rc12 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 13 ________///
    GLfloat xc13=0.135f; GLfloat yc13=0.92f; GLfloat rc13 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc13, yc13); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc13 + (rc13 * cos(i*  twicePi / triangleAmount)),
                        yc13 + (rc13 * sin(i* twicePi / triangleAmount)) );
        }

    ///_________ 16 ________///
    GLfloat xc16=0.160f; GLfloat yc16=0.94f; GLfloat rc16 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc16, yc16); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc16 + (rc16 * cos(i *  twicePi / triangleAmount)),
                        yc16 + (rc16 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 17 ________///
    GLfloat xc17=0.155f; GLfloat yc17=0.92; GLfloat rc17 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc17, yc17); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc17 + (rc17 * cos(i*  twicePi / triangleAmount)),
                        yc17 + (rc17 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 18 ________///
    GLfloat xc18=0.175f; GLfloat yc18=0.92f; GLfloat rc18 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc18, yc18); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc18 + (rc18 * cos(i *  twicePi / triangleAmount)),
                        yc18 + (rc18 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///_________________________________________________Clouds 2___________________________________________________///
    ///_________ 21 ________///
    GLfloat xc21=0.210f; GLfloat yc21=0.90f; GLfloat rc21 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc21, yc21);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc21 + (rc21 * cos(i*  twicePi / triangleAmount)),
                        yc21 + (rc21 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 22 ________///
    GLfloat xc22=0.230f; GLfloat yc22=0.92f; GLfloat rc22 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc22, yc22); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc22 + (rc22 * cos(i *  twicePi / triangleAmount)),
                        yc22 + (rc22 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 23 ________///
    GLfloat xc23=0.225f; GLfloat yc23=0.90f; GLfloat rc23 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc23, yc23); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc23 + (rc23 * cos(i*  twicePi / triangleAmount)),
                        yc23 + (rc23 * sin(i* twicePi / triangleAmount)) );
        }

    ///_________ 26 ________///
    GLfloat xc26=0.250f; GLfloat yc26=0.92f; GLfloat rc26 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc26, yc26); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc26 + (rc26 * cos(i *  twicePi / triangleAmount)),
                        yc26 + (rc26 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 27 ________///
    GLfloat xc27=0.245f; GLfloat yc27=0.90f; GLfloat rc27 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc27, yc27); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc27 + (rc27 * cos(i*  twicePi / triangleAmount)),
                        yc27 + (rc27 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 28 ________///
    GLfloat xc28=0.265f; GLfloat yc28=0.90f; GLfloat rc28 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc28, yc28); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc28 + (rc28 * cos(i *  twicePi / triangleAmount)),
                        yc28 + (rc28 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///_________________________________________________Clouds 3___________________________________________________///
    ///_________ 31 ________///
    GLfloat xc31=0.720f; GLfloat yc31=0.92f; GLfloat rc31 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc31, yc31);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc31 + (rc31 * cos(i*  twicePi / triangleAmount)),
                        yc31 + (rc31 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 32 ________///
    GLfloat xc32=0.740f; GLfloat yc32=0.94f; GLfloat rc32 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc32, yc32); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc32 + (rc32 * cos(i *  twicePi / triangleAmount)),
                        yc32 + (rc32 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 33 ________///
    GLfloat xc33=0.735f; GLfloat yc33=0.92f; GLfloat rc33 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc33, yc33); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc33 + (rc33 * cos(i*  twicePi / triangleAmount)),
                        yc33 + (rc33 * sin(i* twicePi / triangleAmount)) );
        }


    ///_________ 36 ________///
    GLfloat xc36=0.760f; GLfloat yc36=0.94f; GLfloat rc36 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc36, yc36); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc36 + (rc36 * cos(i *  twicePi / triangleAmount)),
                        yc36 + (rc36 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 37 ________///
    GLfloat xc37=0.755f; GLfloat yc37=0.92f; GLfloat rc37 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc37, yc37); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc37 + (rc37 * cos(i*  twicePi / triangleAmount)),
                        yc37 + (rc37 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 38 ________///
    GLfloat xc38=0.775f; GLfloat yc38=0.92f; GLfloat rc38 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc38, yc38); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc38 + (rc38 * cos(i *  twicePi / triangleAmount)),
                        yc38 + (rc38 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_________________________________________________Clouds 4___________________________________________________///
    ///_________ 41 ________///
    GLfloat xc41=0.810f; GLfloat yc41=0.90f; GLfloat rc41 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc41, yc41);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc41 + (rc41 * cos(i*  twicePi / triangleAmount)),
                        yc41 + (rc41 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 42 ________///
    GLfloat xc42=0.830f; GLfloat yc42=0.92f; GLfloat rc42 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc42, yc42); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc42 + (rc42 * cos(i *  twicePi / triangleAmount)),
                        yc42 + (rc42 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 43 ________///
    GLfloat xc43=0.825f; GLfloat yc43=0.90f; GLfloat rc43 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc43, yc43); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc43 + (rc43 * cos(i*  twicePi / triangleAmount)),
                        yc43 + (rc43 * sin(i* twicePi / triangleAmount)) );
        }

    ///_________ 46 ________///
    GLfloat xc46=0.850f; GLfloat yc46=0.92f; GLfloat rc46 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc46, yc46); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc46 + (rc46 * cos(i *  twicePi / triangleAmount)),
                        yc46 + (rc46 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 47 ________///
    GLfloat xc47=0.845f; GLfloat yc47=0.90f; GLfloat rc47 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc47, yc47); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc47 + (rc47 * cos(i*  twicePi / triangleAmount)),
                        yc47 + (rc47 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 48 ________///
    GLfloat xc48=0.865f; GLfloat yc48=0.90f; GLfloat rc48 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc48, yc48); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc48 + (rc48 * cos(i *  twicePi / triangleAmount)),
                        yc48 + (rc48 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_________________________________________________Clouds 5___________________________________________________///
   ///_________ 111 ________///
    GLfloat xc111=1.120f; GLfloat yc111=0.92f; GLfloat rc111 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc111, yc111);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc111 + (rc111 * cos(i*  twicePi / triangleAmount)),
                        yc111 + (rc111 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 112 ________///
    GLfloat xc112=1.140f; GLfloat yc112=0.94f; GLfloat rc112 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc112, yc112); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc112 + (rc112 * cos(i *  twicePi / triangleAmount)),
                        yc112 + (rc112 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 113 ________///
    GLfloat xc113=1.135f; GLfloat yc113=0.92f; GLfloat rc113 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc113, yc113); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc113 + (rc113 * cos(i*  twicePi / triangleAmount)),
                        yc113 + (rc113 * sin(i* twicePi / triangleAmount)) );
        }

    ///_________ 116 ________///
    GLfloat xc116=1.160f; GLfloat yc116=0.94f; GLfloat rc116 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc116, yc116); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc116 + (rc116 * cos(i *  twicePi / triangleAmount)),
                        yc116 + (rc116 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 117 ________///
    GLfloat xc117=1.155f; GLfloat yc117=0.92; GLfloat rc117 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc117, yc117); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc117 + (rc117 * cos(i*  twicePi / triangleAmount)),
                        yc117 + (rc117 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 118 ________///
    GLfloat xc118=1.175f; GLfloat yc118=0.92f; GLfloat rc118 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc118, yc118); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc118 + (rc118 * cos(i *  twicePi / triangleAmount)),
                        yc118 + (rc118 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_________________________________________________Clouds 6___________________________________________________///
    ///_________ 221 ________///
    GLfloat xc221=1.210f; GLfloat yc221=0.90f; GLfloat rc221 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc221, yc221);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc221 + (rc221 * cos(i*  twicePi / triangleAmount)),
                        yc221 + (rc221 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 222 ________///
    GLfloat xc222=1.230f; GLfloat yc222=0.92f; GLfloat rc222 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc222, yc222); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc222 + (rc222 * cos(i *  twicePi / triangleAmount)),
                        yc222 + (rc222 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 223 ________///
    GLfloat xc223=1.225f; GLfloat yc223=0.90f; GLfloat rc223 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc223, yc223); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc223 + (rc223 * cos(i*  twicePi / triangleAmount)),
                        yc223 + (rc223 * sin(i* twicePi / triangleAmount)) );
        }

    ///_________ 226 ________///
    GLfloat xc226=1.250f; GLfloat yc226=0.92f; GLfloat rc226 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc226, yc226); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc226 + (rc226 * cos(i *  twicePi / triangleAmount)),
                        yc226 + (rc226 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 227 ________///
    GLfloat xc227=1.245f; GLfloat yc227=0.90f; GLfloat rc227 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc227, yc227); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc227 + (rc227 * cos(i*  twicePi / triangleAmount)),
                        yc227 + (rc227 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 228 ________///
    GLfloat xc228=1.265f; GLfloat yc228=0.90f; GLfloat rc228 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc228, yc228); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc228 + (rc228 * cos(i *  twicePi / triangleAmount)),
                        yc228 + (rc228 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_________________________________________________Clouds 7___________________________________________________///
    ///_________ 331 ________///
    GLfloat xc331=1.720f; GLfloat yc331=0.92f; GLfloat rc331 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc331, yc331);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc331 + (rc331 * cos(i*  twicePi / triangleAmount)),
                        yc331 + (rc331 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 332 ________///
    GLfloat xc332=1.740f; GLfloat yc332=0.94f; GLfloat rc332 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc332, yc332); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc332 + (rc332 * cos(i *  twicePi / triangleAmount)),
                        yc332 + (rc332 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 333 ________///
    GLfloat xc333=1.735f; GLfloat yc333=0.92f; GLfloat rc333 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc333, yc333); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc333 + (rc333 * cos(i*  twicePi / triangleAmount)),
                        yc333 + (rc333 * sin(i* twicePi / triangleAmount)) );
        }


    ///_________ 336 ________///
    GLfloat xc336=1.760f; GLfloat yc336=0.94f; GLfloat rc336 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc336, yc336); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc336 + (rc336 * cos(i *  twicePi / triangleAmount)),
                        yc336 + (rc336 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 37 ________///
    GLfloat xc337=1.755f; GLfloat yc337=0.92f; GLfloat rc337 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc337, yc337); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc337 + (rc337 * cos(i*  twicePi / triangleAmount)),
                        yc337 + (rc337 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 338 ________///
    GLfloat xc338=1.775f; GLfloat yc338=0.92f; GLfloat rc338 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc338, yc338); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc338 + (rc338 * cos(i *  twicePi / triangleAmount)),
                        yc338 + (rc338 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_________________________________________________Clouds 8___________________________________________________///
    ///_________ 441 ________///
    GLfloat xc441=1.810f; GLfloat yc441=0.90f; GLfloat rc441 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xc441, yc441);
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc441 + (rc441 * cos(i*  twicePi / triangleAmount)),
                        yc441 + (rc441 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 442 ________///
    GLfloat xc442=1.830f; GLfloat yc442=0.92f; GLfloat rc442 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc442, yc442); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc442 + (rc442 * cos(i *  twicePi / triangleAmount)),
                        yc442 + (rc442 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 443 ________///
    GLfloat xc443=1.825f; GLfloat yc443=0.90f; GLfloat rc443 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc443, yc443); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc443 + (rc443 * cos(i*  twicePi / triangleAmount)),
                        yc443 + (rc443 * sin(i* twicePi / triangleAmount)) );
        }

    ///_________ 46 ________///
    GLfloat xc446=1.850f; GLfloat yc446=0.92f; GLfloat rc446 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc446, yc446); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc446 + (rc446 * cos(i *  twicePi / triangleAmount)),
                        yc446 + (rc446 * sin(i * twicePi / triangleAmount)) );
        }
    ///_________ 47 ________///
    GLfloat xc447=1.845f; GLfloat yc447=0.90f; GLfloat rc447 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc447, yc447); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc447 + (rc447 * cos(i*  twicePi / triangleAmount)),
                        yc447 + (rc447 * sin(i* twicePi / triangleAmount)) );
        }
    ///_________ 48 ________///
    GLfloat xc448=1.865f; GLfloat yc448=0.90f; GLfloat rc448 =.015f;
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(xc448, yc448); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xc448 + (rc448 * cos(i *  twicePi / triangleAmount)),
                        yc448 + (rc448 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();

    glPopMatrix();



///______________________________________________Annex Tower___________________________________________________///
    ///_________ Pillar ________///
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.412, 0.412, 0.412f);
    glVertex2f(0.210f,0.60f);
    glVertex2f(0.210f,0.20f);

    glVertex2f(0.238f,0.60f);
    glVertex2f(0.238f,0.20f);

    glVertex2f(0.208f,0.60f);
    glVertex2f(0.240f,0.60f);
    ///_________ Middle Cross(1) ________///
    glVertex2f(0.212f,0.60f);
    glVertex2f(0.236f,0.4f);
    glVertex2f(0.212f,0.4f);
    glVertex2f(0.236f,0.60f);
    ///_________ Middle Cross(2) ________///
    glVertex2f(0.212f,0.4f);
    glVertex2f(0.236f,0.2f);
    glVertex2f(0.212f,0.2f);
    glVertex2f(0.236f,0.4f);
    glEnd();
    ///_________Tower Signal line L1________///
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.412, 0.412, 0.412f);
    glVertex2f(0.188f,0.5f);
    glVertex2f(0.21f,0.5f);
    ///_________Tower Signal line R1________///
    glVertex2f(0.26f,0.56f);
    glVertex2f(0.238f,0.56f);
    ///_________Tower Signal line R2________///
    glVertex2f(0.26f,0.44f);
    glVertex2f(0.238f,0.44f);
    glEnd();
    ///_________Tower Signal line L1________///
    ///_________ OUTSIDE L1________///
    glColor3f(0.086f, 0.149f, 0.149f);
    GLfloat xl1=0.19f; GLfloat yl1=0.505f; GLfloat rl1 =.013f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xl1, yl1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xl1 + (rl1 * cos(i *  twicePi / triangleAmount)),
                        yl1+ (rl1 * sin(i * twicePi / triangleAmount)) );
                         glColor3f(0.294f, 0.388f, 0.388f);
        }


    glEnd();
    ///_________Tower Signal line R1________///
    ///_________ OUTSIDE R1________///
    glColor3f(0.086f, 0.149f, 0.149f);
    GLfloat xr11=0.26f; GLfloat yr11=0.565f; GLfloat rr11 =.013f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xr11, yr11); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xr11 + (rr11 * cos(i *  twicePi / triangleAmount)),
                        yr11+ (rr11 * sin(i * twicePi / triangleAmount)) );
                        glColor3f(0.294f, 0.388f, 0.388f);
        }

        glEnd();
    ///_________Tower Signal line R2________///
    ///_________ OUTSIDE R2________///
    glColor3f(0.086f, 0.149f, 0.149f);
    GLfloat xr21=0.26f; GLfloat yr21=0.445f; GLfloat rr21 =.013f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xr21, yr21); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xr21 + (rr21 * cos(i *  twicePi / triangleAmount)),
                        yr21+ (rr21 * sin(i * twicePi / triangleAmount)) );
                        glColor3f(0.294f, 0.388f, 0.388f);
        }

glEnd();

 ///_________Tower Signal line R1________///
    glBegin(GL_QUADS);
    glColor3f(0.275, 0.69, 0.91);
    glVertex2f(0.247f,0.585f);
    glColor3f(0.286, 0.69, 0.91);
    glVertex2f(0.269f,0.545f);
    glColor3f(0.282, 0.686, 0.906);
    glVertex2f(0.28f,0.545f);
    glColor3f(0.271, 0.682, 0.906);
    glVertex2f(0.28f,0.585f);
    glEnd();
 ///_________Tower Signal line R2________///
    glBegin(GL_QUADS);
    glColor3f(0.314, 0.702, 0.914);
    glVertex2f(0.269f,0.425f);
    glColor3f(0.325, 0.698, 0.914);
    glVertex2f(0.247f,0.465f);
    glColor3f(0.322, 0.698, 0.91);
    glVertex2f(0.28f,0.465f);
    glColor3f(0.31, 0.694, 0.91);
    glVertex2f(0.28f,0.425f);
    glEnd();
    ///_________Tower Signal line L1________///
    glBegin(GL_QUADS);
    glColor3f(0.31, 0.71, 0.929);
    glVertex2f(0.170f,0.482f);
glColor3f(0.322, 0.714, 0.929);
    glVertex2f(0.170f,0.522f);
glColor3f(0.322, 0.714, 0.925);
    glVertex2f(0.203f,0.522f);

glColor3f(0.306, 0.706, 0.922);
    glVertex2f(0.181f,0.482f);
    glEnd();

///_________________________________________________Annex(2)___________________________________________________///

    ///_________Annex 2 Body________///
    glBegin(GL_QUADS);
    glColor3f(0.318, 0.341, 0.341);
    glVertex2f(0.135f,0.36f);
    glVertex2f(0.135f,0.20f);
    glVertex2f(0.220f,0.20f);
    glVertex2f(0.220f,0.36f);
    ///_________Annex 2 Top________///
    glColor3f(0.91, 0.902, 0.745);
    glVertex2f(0.135f,0.38f);
    glVertex2f(0.125f,0.34f);
    glVertex2f(0.230f,0.34f);
    glVertex2f(0.220f,0.38f);
    glEnd();
    ///_________Annex 2 Window 1________///
    glBegin(GL_QUADS);
    glColor3f(0.91, 0.902, 0.745);
    glVertex2f(0.188f,0.32f);
    glVertex2f(0.188f,0.30f);
    glVertex2f(0.203f,0.30f);
    glVertex2f(0.203f,0.32f);
    ///_________Annex 2 Window 2________///
    glVertex2f(0.15f,0.32f);
    glVertex2f(0.15f,0.30f);
    glVertex2f(0.165f,0.30f);
    glVertex2f(0.165f,0.32f);
    glEnd();
    ///_________Annex 2 Top Border________///
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.135f,0.38f);
    glVertex2f(0.125f,0.34f);
    glVertex2f(0.230f,0.34f);
    glVertex2f(0.220f,0.38f);
    glVertex2f(0.125f,0.34f);
    glVertex2f(0.230f,0.34f);
    glVertex2f(0.135f,0.38f);
    glVertex2f(0.220f,0.38f);
    ///_________Annex 2 Window(1) Border________///
    glVertex2f(0.188f,0.32f);
    glVertex2f(0.188f,0.30f);
    glVertex2f(0.203f,0.30f);
    glVertex2f(0.203f,0.32f);
    glVertex2f(0.188f,0.32f);
    glVertex2f(0.203f,0.32f);
    glVertex2f(0.188f,0.30f);
    glVertex2f(0.203f,0.30f);
    glVertex2f(0.1955f,0.32f);
    glVertex2f(0.1955f,0.3f);
    ///_________Annex 2 Window(2) Border________///
    glVertex2f(0.15f,0.32f);
    glVertex2f(0.15f,0.30f);
    glVertex2f(0.165f,0.30f);
    glVertex2f(0.165f,0.32f);
    glVertex2f(0.15f,0.32f);
    glVertex2f(0.165f,0.32f);
    glVertex2f(0.15f,0.30f);
    glVertex2f(0.165f,0.30f);
    glVertex2f(0.1575f,0.32f);
    glVertex2f(0.1575f,0.3f);
    glEnd();

///_________________________________________________Annex(1)___________________________________________________///

    ///_________Annex 1 Body________///

    glBegin(GL_QUADS);
    glColor3f(0.647, 0.486, 0.412);
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.00f,0.20f);
    glVertex2f(0.20f,0.20f);
    glVertex2f(0.20f,0.26f);
    ///_________Annex 1 Top________///
    glColor3f(0.039f, 0.459f, 0.02f);
    glVertex2f(0.00f,0.29f);
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.21f,0.26f);
    glVertex2f(0.20f,0.29f);
    ///_________Annex 1 Under Top________///
    glColor3f(0.91, 0.902, 0.745);
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.00f,0.256f);
    glVertex2f(0.20f,0.256f);
    glVertex2f(0.20f,0.26f);
    ///_________Annex 1 Window (1)________///
    glColor3f(0.91, 0.902, 0.745);
    glVertex2f(0.00f,0.24f);
    glVertex2f(0.00f,0.22f);
    glVertex2f(0.015f,0.22f);
    glVertex2f(0.015f,0.24f);
    ///_________Annex 1 Window (2)________///
    glVertex2f(0.045f,0.24f);
    glVertex2f(0.045f,0.22f);
    glVertex2f(0.060f,0.22f);
    glVertex2f(0.060f,0.24f);
    ///_________Annex 1 Window (3)________///
    glVertex2f(0.090f,0.24f);
    glVertex2f(0.090f,0.22f);
    glVertex2f(0.105f,0.22f);
    glVertex2f(0.105f,0.24f);
    ///_________Annex 1 Window (4)________///
    glVertex2f(0.135f,0.24f);
    glVertex2f(0.135f,0.22f);
    glVertex2f(0.150f,0.22f);
    glVertex2f(0.150f,0.24f);
    ///_________Annex 1 Window (5)________///
    glVertex2f(0.18f,0.24f);
    glVertex2f(0.18f,0.22f);
    glVertex2f(0.195f,0.22f);
    glVertex2f(0.195f,0.24f);
    glEnd();
    ///_________Annex 1 Top Border________///
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.00f,0.29f);
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.21f,0.26f);
    glVertex2f(0.20f,0.29f);
    glVertex2f(0.00f,0.29f);
    glVertex2f(0.20f,0.29f);
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.21f,0.26f);
    ///_________Annex 1 Body Border________///
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.00f,0.20f);
    glVertex2f(0.20f,0.20f);
    glVertex2f(0.20f,0.26f);
    glVertex2f(0.00f,0.20f);
    glVertex2f(0.20f,0.20f);
    glVertex2f(0.00f,0.26f);
    glVertex2f(0.20f,0.26f);
    ///_________Annex 1 Window(1)Border________///
    glVertex2f(0.00f,0.24f);
    glVertex2f(0.00f,0.22f);
    glVertex2f(0.015f,0.22f);
    glVertex2f(0.015f,0.24f);
    glVertex2f(0.015f,0.22f);
    glVertex2f(0.00f,0.22f);
    glVertex2f(0.015f,0.24f);
    glVertex2f(0.00f,0.24f);
    glVertex2f(0.007f,0.22f);
    glVertex2f(0.007f,0.24f);
    ///_________Annex 1 Window(2)Border________///
    glVertex2f(0.045f,0.24f);
    glVertex2f(0.045f,0.22f);
    glVertex2f(0.060f,0.22f);
    glVertex2f(0.060f,0.24f);
    glVertex2f(0.045f,0.24f);
    glVertex2f(0.060f,0.24f);
    glVertex2f(0.045f,0.22f);
    glVertex2f(0.060f,0.22f);
    glVertex2f(0.0525f,0.22f);
    glVertex2f(0.0525f,0.24f);
    ///_________Annex 1 Window(3)Border________///
    glVertex2f(0.090f,0.24f);
    glVertex2f(0.090f,0.22f);
    glVertex2f(0.105f,0.22f);
    glVertex2f(0.105f,0.24f);
    glVertex2f(0.090f,0.24f);
    glVertex2f(0.105f,0.24f);
    glVertex2f(0.090f,0.22f);
    glVertex2f(0.105f,0.22f);
    glVertex2f(0.0975f,0.22f);
    glVertex2f(0.0975f,0.24f);

    ///_________Annex 1 Window(4)Border________///
    glVertex2f(0.135f,0.24f);
    glVertex2f(0.135f,0.22f);
    glVertex2f(0.150f,0.22f);
    glVertex2f(0.150f,0.24f);
    glVertex2f(0.135f,0.24f);
    glVertex2f(0.150f,0.24f);
    glVertex2f(0.135f,0.22f);
    glVertex2f(0.150f,0.22f);
    glVertex2f(0.1425f,0.22f);
    glVertex2f(0.1425f,0.24f);

    ///_________Annex 1 Window(5)Border________///
    glVertex2f(0.18f,0.24f);
    glVertex2f(0.18f,0.22f);
    glVertex2f(0.195f,0.22f);
    glVertex2f(0.195f,0.24f);
    glVertex2f(0.18f,0.24f);
    glVertex2f(0.195f,0.24f);
    glVertex2f(0.18f,0.22f);
    glVertex2f(0.195f,0.22f);
    glVertex2f(0.1875f,0.22f);
    glVertex2f(0.1875f,0.24f);
    ///_________Annex 1 Partition Border________///
    glVertex2f(0.120f,0.26f);
    glVertex2f(0.120f,0.20f);
    glVertex2f(0.030f,0.26f);
    glVertex2f(0.030f,0.20f);
    glEnd();
///_____________________________________________ROCKET Stand(START)___________________________________________________///
    ///_________ 1________///
    glBegin(GL_QUADS);
    ///_________ 2________///
    glColor3f(0.549, 0.639, 0.635);
    glVertex2f(0.52f,0.56f);
    glVertex2f(0.52f,0.20f);
    glVertex2f(0.58f,0.20f);
    glVertex2f(0.58f,0.56f);

    ///_________ 3________///
    glColor3f(0.549, 0.639, 0.635);
    glVertex2f(0.436f,0.51f);
    glVertex2f(0.436f,0.46f);
    glVertex2f(0.52f,0.46f);
    glVertex2f(0.52f,0.51f);
    ///_________ 4________///
    glColor3f(0.035, 0.506, 0.733);
    glVertex2f(0.53f,0.54f);
    glVertex2f(0.53f,0.20f);
    glVertex2f(0.57f,0.20f);
    glVertex2f(0.57f,0.54f);
    ///_________ 5________///
    glVertex2f(0.436f,0.50f);
    glVertex2f(0.436f,0.47f);
    glVertex2f(0.53f,0.47f);
    glVertex2f(0.53f,0.50f);
    ///_________ 6________///
    glColor3f(0.635, 0.733, 0.82);
    glVertex2f(0.54f,0.25f);
    glVertex2f(0.54f,0.20f);
    glVertex2f(0.56f,0.20f);
    glVertex2f(0.56f,0.25f);


    glEnd();


    ///_________ 1 border________///
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    ///_________ 2 border________///
    glVertex2f(0.52f,0.56f);
    glVertex2f(0.52f,0.20f);
    glVertex2f(0.58f,0.20f);
    glVertex2f(0.58f,0.56f);
    glVertex2f(0.52f,0.56f);
    glVertex2f(0.58f,0.56f);
    glVertex2f(0.52f,0.20f);
    glVertex2f(0.58f,0.20f);

   ///_________ 3 border________///
    glVertex2f(0.436f,0.51f);
    glVertex2f(0.436f,0.46f);
    glVertex2f(0.52f,0.46f);
    glVertex2f(0.52f,0.51f);
    glVertex2f(0.436f,0.51f);
    glVertex2f(0.52f,0.51f);
    glVertex2f(0.436f,0.46f);
    glVertex2f(0.52f,0.46f);
    ///_________ 4 border________///
    glVertex2f(0.53f,0.54f);
    glVertex2f(0.53f,0.20f);
    glVertex2f(0.57f,0.20f);
    glVertex2f(0.57f,0.54f);
    glVertex2f(0.53f,0.54f);
    glVertex2f(0.57f,0.54f);
    glVertex2f(0.53f,0.20f);
    glVertex2f(0.57f,0.20f);
    ///_________ 5 border________///
    glVertex2f(0.436f,0.50f);
    glVertex2f(0.436f,0.47f);
    glVertex2f(0.53f,0.47f);
    glVertex2f(0.53f,0.50f);
    glVertex2f(0.436f,0.50f);
    glVertex2f(0.53f,0.50f);
    glVertex2f(0.436f,0.47f);
    glVertex2f(0.53f,0.47f);
    ///_________ 6 border________///
    glVertex2f(0.54f,0.25f);
    glVertex2f(0.54f,0.20f);
    glVertex2f(0.56f,0.20f);
    glVertex2f(0.56f,0.25f);
    glVertex2f(0.54f,0.25f);
    glVertex2f(0.56f,0.25f);
    glVertex2f(0.54f,0.20f);
    glVertex2f(0.56f,0.20f);
    ///_________ UPPER MID border________///
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.45f,0.47f);
    glVertex2f(0.46f,0.47f);
    glVertex2f(0.47f,0.50f);
    glVertex2f(0.48f,0.50f);
    glVertex2f(0.49f,0.47f);
    glVertex2f(0.50f,0.47f);
    glVertex2f(0.51f,0.50f);
    ///_________ 7 borders________///
        ///_________ 7 top________///
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.52f,0.39f);
        ///_________ 7 bottom________///
    glVertex2f(0.435f,0.36f);
    glVertex2f(0.52f,0.36f);
        ///_________ 7 Mid________///
    glVertex2f(0.435f,0.375f);
    glVertex2f(0.52f,0.375f);
    ///_________ 7 left line________///
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.435f,0.36f);
        ///_________ 7 cross(Top to Bottom)________///
    glVertex2f(0.438f,0.39f);
    glVertex2f(0.458f,0.36f);
    glVertex2f(0.458f,0.36f);
    glVertex2f(0.478f,0.39f);
    glVertex2f(0.478f,0.39f);
    glVertex2f(0.498f,0.36f);
    glVertex2f(0.498f,0.36f);
    glVertex2f(0.518f,0.39f);
        ///_________ 7 cross(Bottom to top)________///
    glVertex2f(0.438f,0.36f);
    glVertex2f(0.458f,0.39f);
    glVertex2f(0.458f,0.39f);
    glVertex2f(0.478f,0.36f);
    glVertex2f(0.478f,0.36f);
    glVertex2f(0.498f,0.39f);
    glVertex2f(0.498f,0.39f);
    glVertex2f(0.518f,0.36f);
        ///_________ Lift line________///
    glColor3f(0.157, 0.6, 0.835);
    glVertex2f(0.55f,0.538f);
    glVertex2f(0.55f,0.25f);
    glEnd();
///_____________________________________________ROCKET Stand(END)___________________________________________________///

///_____________________________________________ROCKET(START)___________________________________________________///
    ///_________ 1________///
    glPushMatrix();
    glTranslatef(0.0f,Position2, 0.0f);
    glBegin(GL_QUADS);

    ///_________ 3________///
    glColor3f(0.224, 0.49, 0.886);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    ///_________ 4________///
    glColor3f(0.478, 0.537, 0.565);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    ///_________ 5________///
    glColor3f(0.976, 0.475, 0.133);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glColor3f(0.925, 0.431, 0.075);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    ///_________ 6________///
    glColor3f(0.471, 0.529, 0.557);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glColor3f(0.208, 0.247, 0.251);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);

    ///_________ 9________///
    glColor3f(0.588, 0.647, 0.663);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    ///_________ 10________///
    glColor3f(0.976, 0.475, 0.133);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.835, 0.388, 0.09);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    ///_________ Upper and Lower border________///
    ///_______Lower L_____///
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.39f,0.34f);
    glVertex2f(0.39f,0.25f);
    glVertex2f(0.392f,0.25f);
    glVertex2f(0.392f,0.34f);
    ///_______Lower R_____///
    glVertex2f(0.4185f,0.34f);
    glVertex2f(0.4185f,0.25f);
    glVertex2f(0.42f,0.25f);
    glVertex2f(0.42f,0.34f);
    ///_______upper_____///
    glVertex2f(0.372f,0.452f);
    glVertex2f(0.372f,0.449f);
    glVertex2f(0.438f,0.449f);
    glVertex2f(0.438f,0.452f);
    ///_______11 Right small rocket Body_____///
    glColor3f(0.196, 0.51, 0.984);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Body_____///
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    glBegin(GL_TRIANGLES);
    ///_______11 Right small rocket Head_____///
    glColor3f(0.98, 0.549, 0.11);
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Head_____///
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
     ///_______11 Right small rocket Body_____///
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.445f,0.39f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.445f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    ///_______12 Left small rocket Body_____///
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    glVertex2f(0.375f,0.39f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.375f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    ///_______11 Right small rocket Head_____///
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Head_____///
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    glBegin(GL_QUADS);
    ///_________ 7(Wing 1)________///
    glColor3f(0.224, 0.494, 0.882);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    ///_________ 8(Wing 2)________///
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glEnd();

    ///_____________________________Rocket TOP window___________________________________///
    ///_________ 11________///
    glColor3f(0.976, 0.482, 0.125);
    GLfloat xrtw1=0.405f; GLfloat yrtw1=0.45f; GLfloat rrtw1 =.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrtw1, yrtw1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.976, 0.482, 0.125);
            glVertex2f( xrtw1 + (rrtw1 * cos(i *  twicePi / triangleAmount)),
                        yrtw1 + (rrtw1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 12________///
    glColor3f(0.314, 0.863, 0.98);
    GLfloat xrtw2=0.405f; GLfloat yrtw2=0.45f; GLfloat rrtw2 =.010f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrtw2, yrtw2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.863, 0.98);
            glVertex2f( xrtw2 + (rrtw2 * cos(i *  twicePi / triangleAmount)),
                        yrtw2 + (rrtw2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket bottom window___________________________________///
    ///_________ 13________///
    glColor3f(0.31, 0.847, 0.973);
    GLfloat xrbw3=0.405f; GLfloat yrbw3=0.30f; GLfloat rrbw3 =.010f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrbw3, yrbw3); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.31, 0.847, 0.973);
            glVertex2f( xrbw3 + (rrbw3 * cos(i *  twicePi / triangleAmount)),
                        yrbw3 + (rrbw3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Mini window___________________________________///
    ///_________ 14________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw1=0.385f; GLfloat yrmw1=0.52f; GLfloat rrmw1 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw1, yrmw1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw1 + (rrmw1 * cos(i *  twicePi / triangleAmount)),
                        yrmw1 + (rrmw1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 15________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw2=0.405f; GLfloat yrmw2=0.52f; GLfloat rrmw2 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw2, yrmw2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw2 + (rrmw2 * cos(i *  twicePi / triangleAmount)),
                        yrmw2 + (rrmw2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 16________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw3=0.425f; GLfloat yrmw3=0.52f; GLfloat rrmw3 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw3, yrmw3); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw3 + (rrmw3 * cos(i *  twicePi / triangleAmount)),
                        yrmw3 + (rrmw3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Border___________________________________///
    ///_________ 1________///
    glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    ///_________ 2________///
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    ///_________ 3________///
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    ///_________ 4________///
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    ///_________ 5________///
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    ///_________ 6________///
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    ///_________ 7(Wing 1)________///
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    ///_________ 8(Wing 2)________///
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    ///_________ 9________///
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    ///_________ 10________///
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glEnd();


    ///_____________________________Rocket TOP window(Border)___________________________________///
    ///_________ 11________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrtwb1=0.405f; GLfloat yrtwb1=0.45f; GLfloat rrtwb1 =.015f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrtwb1, yrtwb1); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrtwb1 + (rrtwb1 * cos(i *  twicePi / lineAmount)),
                        yrtwb1 + (rrtwb1 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
     ///_________ 12________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrtwb2=0.405f; GLfloat yrtwb2=0.45f; GLfloat rrtwb2 =.010f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrtwb2, yrtwb2); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrtwb2 + (rrtwb2 * cos(i *  twicePi / lineAmount)),
                        yrtwb2 + (rrtwb2 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
    ///_____________________________Rocket bottom window(Border)___________________________________///
    ///_________ 13________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrbwb3=0.405f; GLfloat yrbwb3=0.30f; GLfloat rrbwb3 =.010f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrbwb3, yrbwb3); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrbwb3 + (rrbwb3 * cos(i *  twicePi / lineAmount)),
                        yrbwb3 + (rrbwb3 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Mini window(Border)___________________________________///
    ///_________ 14________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb1=0.385f; GLfloat yrmwb1=0.52f; GLfloat rrmwb1 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb1, yrmwb1); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb1 + (rrmwb1 * cos(i *  twicePi / lineAmount)),
                        yrmwb1 + (rrmwb1 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
     ///_________ 15________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb2=0.405f; GLfloat yrmwb2=0.52f; GLfloat rrmwb2 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb2, yrmwb2); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb2 + (rrmwb2 * cos(i *  twicePi / lineAmount)),
                        yrmwb2 + (rrmwb2 * sin(i * twicePi /lineAmount)) );
        }
    glEnd();
     ///_________ 16________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb3=0.425f; GLfloat yrmwb3=0.52f; GLfloat rrmwb3 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb3, yrmwb3); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb3 + (rrmwb3 * cos(i *  twicePi / lineAmount)),
                        yrmwb3 + (rrmwb3 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();


    glPushMatrix();

    ///_________ Fire main 1________///
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.20f);
    glVertex2f(0.36f,0.14f);
    glVertex2f(0.388f,0.17f);
    glVertex2f(0.4f,0.12f);
    glVertex2f(0.42f,0.18f);
    glVertex2f(0.45f,0.14f);
    glVertex2f(0.42f,0.20f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.20f);
    glVertex2f(0.38f,0.168f);
    glVertex2f(0.395f,0.19f);
    glVertex2f(0.40f,0.14f);
    glVertex2f(0.41f,0.19f);
    glVertex2f(0.43f,0.17f);
    glVertex2f(0.417f,0.20f);
    glEnd();


    ///_________ Fire left ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.535,0.340,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);

    glVertex2f(0.39f,0.20f);
    glVertex2f(0.36f,0.14f);
    glVertex2f(0.388f,0.17f);
    glVertex2f(0.4f,0.12f);
    glVertex2f(0.42f,0.18f);
    glVertex2f(0.45f,0.14f);
    glVertex2f(0.42f,0.20f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);

    glVertex2f(0.392f,0.20f);
    glVertex2f(0.38f,0.168f);
    glVertex2f(0.395f,0.19f);
    glVertex2f(0.40f,0.16f);
    glVertex2f(0.41f,0.19f);
    glVertex2f(0.43f,0.17f);
    glVertex2f(0.417f,0.20f);
    glEnd();
    glPopMatrix();
    ///_________ Fire Right ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.685,0.340,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.20f);
    glVertex2f(0.36f,0.14f);
    glVertex2f(0.388f,0.17f);
    glVertex2f(0.4f,0.12f);
    glVertex2f(0.42f,0.18f);
    glVertex2f(0.45f,0.14f);
    glVertex2f(0.42f,0.20f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.20f);
    glVertex2f(0.38f,0.168f);
    glVertex2f(0.395f,0.19f);
    glVertex2f(0.40f,0.16f);
    glVertex2f(0.41f,0.19f);
    glVertex2f(0.43f,0.17f);
    glVertex2f(0.417f,0.20f);
    glEnd();
    glPopMatrix();
    glPopMatrix();



    ///_________ 1________///
    glBegin(GL_QUADS);
    glColor3f(0.455, 0.525, 0.553);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    ///_________ 2________///
    glColor3f(0.345, 0.416, 0.424);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    glEnd();

    ///_________ Fire left ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.535,0.340,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    ///_________ Fire Right ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.685,0.340,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    ///_________ Fire main 2________///

    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    ///_________ 1 Rocket stand________///
    glBegin(GL_QUADS);
    glColor3f(0.431, 0.416, 0.412);
    glVertex2f(0.37f,0.23f);
    glVertex2f(0.32f,0.20f);
    glVertex2f(0.49f,0.20f);
    glVertex2f(0.44f,0.23f);
    glEnd();
    ///_________ 1 rocket stand border________///
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.37f,0.23f);
    glVertex2f(0.32f,0.20f);
    glVertex2f(0.49f,0.20f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.37f,0.23f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.32f,0.20f);
    glVertex2f(0.49f,0.20f);
    glEnd();

    ///.......Transparent wall.....//

    glBegin(GL_QUADS);
    glColor4f(0.455, 0.796, 0.949,0.5);
    glVertex2f(0.32f,0.20f);
    glVertex2f(0.32f,0.30f);
    glColor4f(0.455, 0.796, 0.949,0.5);
    glVertex2f(0.49f,0.30f);
    glVertex2f(0.49f,0.20f);

    glColor4f(0.455, 0.796, 0.949,0.5);
    glVertex2f(0.32f,0.20f);
    glVertex2f(0.31f,0.22f);
    glVertex2f(0.31f,0.28f);
    glVertex2f(0.32f,0.30f);

    glVertex2f(0.49f,0.20f);
    glVertex2f(0.49f,0.30f);
    glVertex2f(0.50f,0.28f);
    glVertex2f(0.50f,0.22f);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);

    glVertex2f(0.32f,0.20f);
    glVertex2f(0.49f,0.20f);
    glVertex2f(0.32f,0.30f);
    glVertex2f(0.49f,0.30f);


    glVertex2f(0.32f,0.20f);
    glVertex2f(0.31f,0.22f);
    glVertex2f(0.31f,0.28f);
    glVertex2f(0.32f,0.30f);
    glVertex2f(0.31f,0.22f);
    glVertex2f(0.31f,0.28f);

    glVertex2f(0.49f,0.20f);
    glVertex2f(0.50f,0.22f);
    glVertex2f(0.49f,0.30f);
    glVertex2f(0.50f,0.28f);
    glVertex2f(0.50f,0.22f);
    glVertex2f(0.50f,0.28f);

    glEnd();

    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ///_____________________________________________ROCKET(END)___________________________________________________///

///_________________________________________________D building(Start)___________________________________________________///
    ///_________ 1 ________///
    glBegin(GL_QUADS);
    glColor3f(0.196f,0.376f,0.51f);
    glVertex2f(0.95f,0.2f);
    glVertex2f(0.95f,0.61f);
    glVertex2f(1.0f,0.61f);
    glVertex2f(1.0f,0.2f);
    ///_________ body 2 ________///
    glColor3f(0.765f,0.761f,0.769f);
    glVertex2f(0.74f,0.2f);
    glVertex2f(0.74f,0.58f);
    glVertex2f(0.98f,0.58f);
    glVertex2f(0.98f,0.2f);
    ///_________ 3 ________///
    glColor3f(0.294f,0.525f,0.71f);
    glVertex2f(0.74f,0.545f);
    glVertex2f(0.74f,0.565f);
    glVertex2f(0.98f,0.565f);
    glVertex2f(0.98f,0.545f);
    ///_________ 4 ________///
    glVertex2f(0.74f,0.530f);
    glVertex2f(0.74f,0.510f);
    glVertex2f(0.98f,0.510f);
    glVertex2f(0.98f,0.530f);
    ///_________ 5 ________///
    glVertex2f(0.75f,0.495f);
    glVertex2f(0.75f,0.445f);
    glVertex2f(0.98f,0.445f);
    glVertex2f(0.98f,0.495f);
    ///_________ 6 ________///
    glVertex2f(0.74f,0.430f);
    glVertex2f(0.74f,0.495f);
    glVertex2f(0.75f,0.495f);
    glVertex2f(0.75f,0.445f);
    ///_________ 7 ________///
    glVertex2f(0.75f,0.410f);
    glVertex2f(0.98f,0.410f);
    glVertex2f(0.98f,0.43f);
    glVertex2f(0.75f,0.43f);
    ///_________ 8 ________///
    glVertex2f(0.76f,0.390f);
    glVertex2f(0.76f,0.340f);
    glVertex2f(0.98f,0.340f);
    glVertex2f(0.98f,0.390f);
    ///_________ 9 ________///
    glColor3f(0.294f,0.525f,0.71f);
    glVertex2f(0.75f,0.390f);
    glVertex2f(0.75f,0.325f);
    glVertex2f(0.76f,0.340f);
    glVertex2f(0.76f,0.390f);
    ///_________ 10 ________///
    glVertex2f(0.76f,0.325f);
    glVertex2f(0.76f,0.305f);
    glVertex2f(0.98f,0.305f);
    glVertex2f(0.98f,0.325f);
    ///_________ 11 ________///
    glVertex2f(0.76f,0.290f);
    glVertex2f(0.76f,0.270f);
    glVertex2f(0.98f,0.270f);
    glVertex2f(0.98f,0.290f);

    ///_________ 12 ________///
    glVertex2f(0.76f,0.255f);
    glVertex2f(0.76f,0.23f);
    glVertex2f(0.98f,0.23f);
    glVertex2f(0.98f,0.255f);
    ///_________ 13 ________///
    glVertex2f(0.76f,0.212f);
    glVertex2f(0.76f,0.2f);
    glVertex2f(0.98f,0.2f);
    glVertex2f(0.98f,0.212f);
    ///_________ 14 ________///
    glColor3f(0.765f,0.761f,0.769f);
    glVertex2f(0.68f,0.555f);
    glVertex2f(0.68f,0.2f);
    glVertex2f(0.74f,0.2f);
    glVertex2f(0.74f,0.58f);
    ///_________ 15 ________///
    glColor3f(0.294f,0.525f,0.71f);
    glVertex2f(0.69f,0.544f);
    glVertex2f(0.69f,0.2f);
    glVertex2f(0.732f,0.2f);
    glVertex2f(0.732f,0.560f);
    ///_________ 16 ________///
    glVertex2f(0.73f,0.400f);
    glVertex2f(0.73f,0.2f);
    glVertex2f(0.743f,0.2f);
    glVertex2f(0.743f,0.420f);
    ///_________ 17 ________///
    glVertex2f(0.73f,0.285f);
    glVertex2f(0.73f,0.2f);
    glVertex2f(0.753f,0.2f);
    glVertex2f(0.753f,0.315f);
    glEnd();


    ///_________ D window (1) ________///
    glBegin(GL_QUADS);
    glColor3f(0.298, 0.51, 0.671);
    glVertex2f(0.987f,0.56f);
    glVertex2f(0.987f,0.54f);
    glVertex2f(0.993f,0.54f);
    glVertex2f(0.993f,0.56f);
    ///_________ D window (2) ________///
    glVertex2f(0.987f,0.52f);
    glVertex2f(0.987f,0.50f);
    glVertex2f(0.993f,0.50f);
    glVertex2f(0.993f,0.52f);
    ///_________ D window (3) ________///
    glVertex2f(0.987f,0.48f);
    glVertex2f(0.987f,0.46f);
    glVertex2f(0.993f,0.46f);
    glVertex2f(0.993f,0.48f);
    ///_________ D window (4) ________///
    glVertex2f(0.987f,0.44f);
    glVertex2f(0.987f,0.42f);
    glVertex2f(0.993f,0.42f);
    glVertex2f(0.993f,0.44f);
    ///_________ D window (5) ________///
    glVertex2f(0.987f,0.40f);
    glVertex2f(0.987f,0.38f);
    glVertex2f(0.993f,0.38f);
    glVertex2f(0.993f,0.40f);
    ///_________ D window (6) ________///
    glVertex2f(0.987f,0.36f);
    glVertex2f(0.987f,0.34f);
    glVertex2f(0.993f,0.34f);
    glVertex2f(0.993f,0.36f);
    ///_________ D window (7) ________///
    glVertex2f(0.987f,0.32f);
    glVertex2f(0.987f,0.30f);
    glVertex2f(0.993f,0.30f);
    glVertex2f(0.993f,0.32f);
    ///_________ D window (8) ________///
    glVertex2f(0.987f,0.28f);
    glVertex2f(0.987f,0.26f);
    glVertex2f(0.993f,0.26f);
    glVertex2f(0.993f,0.28f);
    ///_________ D window (9) ________///
    glVertex2f(0.987f,0.24f);
    glVertex2f(0.987f,0.22f);
    glVertex2f(0.993f,0.22f);
    glVertex2f(0.993f,0.24f);
     glEnd();
     ///______________________________________________________D 7th & 5th tree___________________________________________________///
   ///_________D 7th tree 1________///
///_________BODY________///
    glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.10,1.76,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E1 =0.062, E2 =0.070f, S1=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E1, E2); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);

            glVertex2f( E1 + (S1 * cos(i *  twicePi / triangleAmount)),
                        E2 + (S1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E3 =0.057, E4 =0.09f, S2=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E3, E4); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E3 + (S2 * cos(i *  twicePi / triangleAmount)),
                        E4 + (S2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E5 =0.04, E6 =0.081f, S3=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5, E6); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E5 + (S3 * cos(i *  twicePi / triangleAmount)),
                        E6 + (S3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E7 =0.026, E8 =0.089f, S4=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E7, E8); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E7 + (S4 * cos(i *  twicePi / triangleAmount)),
                        E8 + (S4 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E9 =0.019, E10 =0.10f, S5=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E9, E10); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E9 + (S5 * cos(i *  twicePi / triangleAmount)),
                        E10 + (S5 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F =0.043, F1 =0.123f, S6=0.03f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F, F1); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F + (S6 * cos(i *  twicePi / triangleAmount)),
                        F1 + (S6 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F2 =0.07, F3 =0.12f, S7=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F2, F3); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F2 + (S7 * cos(i *  twicePi / triangleAmount)),
                        F3 + (S7 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F4 =0.07, F5 =0.10f, S8=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F4, F5); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F4 + (S8 * cos(i *  twicePi / triangleAmount)),
                        F5 + (S8 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
        ///LEAF 9
    GLfloat F6 =0.025, F7 =0.059f, S9=0.014f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F6, F7); // center of circle
        for( i = 0; i <= triangleAmount;i++) {


            glVertex2f( F6 + (S9 * cos(i *  twicePi / triangleAmount)),
                        F7 + (S9 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();
///______________________________________________________DEMO TREE 2___________________________________________________///
 ///_________D 7th tree 2________///
///_________BODY________///
    glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.30,1.76,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E11 =0.062, E12 =0.070f, S11=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E11, E12); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);
            glVertex2f( E11 + (S11 * cos(i *  twicePi / triangleAmount)),
                        E12 + (S11 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E13 =0.057, E14 =0.09f, S12=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E13, E14); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E13 + (S12 * cos(i *  twicePi / triangleAmount)),
                        E14 + (S12 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E15 =0.04, E16 =0.081f, S13=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E15, E16); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E15 + (S13 * cos(i *  twicePi / triangleAmount)),
                        E16 + (S13 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E17 =0.026, E18 =0.089f, S14=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E17, E18); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E17 + (S14 * cos(i *  twicePi / triangleAmount)),
                        E18 + (S14 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E19 =0.019, E110 =0.10f, S15=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E19, E110); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E19 + (S15 * cos(i *  twicePi / triangleAmount)),
                        E110 + (S15 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F01 =0.043, F11 =0.123f, S16=0.03f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F01, F11); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F01 + (S16 * cos(i *  twicePi / triangleAmount)),
                        F11 + (S16 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F12 =0.07, F13 =0.12f, S17=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F12, F13); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F12 + (S17 * cos(i *  twicePi / triangleAmount)),
                        F13 + (S17 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F14 =0.07, F15 =0.10f, S18=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F14, F15); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F14 + (S18 * cos(i *  twicePi / triangleAmount)),
                        F15 + (S18 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
        ///LEAF 9
    GLfloat F16 =0.025, F17 =0.059f, S19=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F16, F17); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F16 + (S19 * cos(i *  twicePi / triangleAmount)),
                        F17 + (S19 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();
    ///______________________________________________________DEMO TREE 3___________________________________________________///
 ///_________D 7th tree 3________///
///_________BODY________///
    glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.50,1.76,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E211 =0.062, E212 =0.070f, S211=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E211, E212); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);
            glVertex2f( E211 + (S211 * cos(i *  twicePi / triangleAmount)),
                        E212 + (S211 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E213 =0.057, E214 =0.09f, S212=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E213, E214); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E213 + (S212 * cos(i *  twicePi / triangleAmount)),
                        E214 + (S212 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E215 =0.04, E216 =0.081f, S213=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E215, E216); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E215 + (S213 * cos(i *  twicePi / triangleAmount)),
                        E216 + (S213 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E217 =0.026, E218 =0.089f, S214=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E17, E18); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E217 + (S214 * cos(i *  twicePi / triangleAmount)),
                        E218 + (S214 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E219 =0.019, E2110 =0.10f, S215=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E219, E2110); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E219 + (S215 * cos(i *  twicePi / triangleAmount)),
                        E2110 + (S215 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F201 =0.043, F211 =0.123f, S216=0.03f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F201, F211); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F201 + (S216 * cos(i *  twicePi / triangleAmount)),
                        F211 + (S216 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F212 =0.07, F213 =0.12f, S217=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F212, F213); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F212 + (S217 * cos(i *  twicePi / triangleAmount)),
                        F213 + (S217 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F214 =0.07, F215 =0.10f, S218=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F214, F215); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F214 + (S218 * cos(i *  twicePi / triangleAmount)),
                        F215 + (S218 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
        ///LEAF 9
    GLfloat F216 =0.025, F217 =0.059f, S219=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F216, F217); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F216 + (S219 * cos(i *  twicePi / triangleAmount)),
                        F217 + (S219 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();
    ///______________________________________________________DEMO TREE 4___________________________________________________///
 ///_________D 7th tree 4________///
///_________BODY________///
    glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.72,1.76,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E111 =0.062, E112 =0.070f, S111=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E111, E112); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);
            glVertex2f( E111 + (S111 * cos(i *  twicePi / triangleAmount)),
                        E112 + (S111 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E113 =0.057, E114 =0.09f, S112=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E113, E114); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E113 + (S112 * cos(i *  twicePi / triangleAmount)),
                        E114 + (S112 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E115 =0.04, E116 =0.081f, S113=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E115, E116); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E115 + (S113 * cos(i *  twicePi / triangleAmount)),
                        E116 + (S113 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E117 =0.026, E118 =0.089f, S114=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E117, E118); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E117 + (S114 * cos(i *  twicePi / triangleAmount)),
                        E118 + (S114 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E119 =0.019, E1110 =0.10f, S115=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E119, E1110); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( E119 + (S115 * cos(i *  twicePi / triangleAmount)),
                        E1110 + (S115 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F101 =0.043, F111 =0.123f, S116=0.03f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F101, F111); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F101 + (S116 * cos(i *  twicePi / triangleAmount)),
                        F111 + (S116 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F112 =0.07, F113 =0.12f, S117=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F112, F113); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F112 + (S117 * cos(i *  twicePi / triangleAmount)),
                        F113 + (S117 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F114 =0.07, F115 =0.10f, S118=0.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F114, F115); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F114 + (S118 * cos(i *  twicePi / triangleAmount)),
                        F115 + (S118 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
        ///LEAF 9
    GLfloat F116 =0.025, F117 =0.059f, S119=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F116, F117); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
            glVertex2f( F116 + (S119 * cos(i *  twicePi / triangleAmount)),
                        F117 + (S119 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();
///______________________________________________________D 5th TREE ___________________________________________________///
 ///_________D 5th tree 1________///
///_________BODY________///
    glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.15,1.34,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E51 =0.062, E52 =0.070f, S51=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E51, E52); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);

            glVertex2f( E51 + (S51 * cos(i *  twicePi / triangleAmount)),
                        E52 + (S51 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E53 =0.057, E54 =0.09f, S52=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E53, E54); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E53 + (S52 * cos(i *  twicePi / triangleAmount)),
                        E54 + (S52 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E55 =0.04, E56 =0.081f, S53=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E55, E56); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E55 + (S53 * cos(i *  twicePi / triangleAmount)),
                        E56 + (S53 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E57 =0.026, E58 =0.089f, S54=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E57, E58); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E57 + (S54 * cos(i *  twicePi / triangleAmount)),
                        E58 + (S54 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E59 =0.019, E510 =0.10f, S55=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E59, E510); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E59 + (S55 * cos(i *  twicePi / triangleAmount)),
                        E510 + (S55 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F05 =0.043, F51 =0.123f, S56=0.03f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F05, F51); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F05 + (S56 * cos(i *  twicePi / triangleAmount)),
                        F51 + (S56 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F52 =0.07, F53 =0.12f, S57=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F52, F53); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F52 + (S57 * cos(i *  twicePi / triangleAmount)),
                        F53 + (S57 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F54 =0.07, F55 =0.10f, S58=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F54, F55); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F54 + (S58 * cos(i *  twicePi / triangleAmount)),
                        F55 + (S58 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_________D 5th tree 2________///
///_________BODY________///
    glPopMatrix();
     glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.35,1.34,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E551 =0.062, E552 =0.070f, S551=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E551, E552); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);

            glVertex2f( E551 + (S551 * cos(i *  twicePi / triangleAmount)),
                        E552 + (S551 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E553 =0.057, E554 =0.09f, S552=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E553, E554); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E553 + (S552 * cos(i *  twicePi / triangleAmount)),
                        E554 + (S552 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E555 =0.04, E556 =0.081f, S553=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E555, E556); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E555 + (S553 * cos(i *  twicePi / triangleAmount)),
                        E556 + (S553 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E557 =0.026, E558 =0.089f, S554=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E557, E558); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E557 + (S554 * cos(i *  twicePi / triangleAmount)),
                        E558 + (S554 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E559 =0.019, E5510 =0.10f, S555=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E559, E5510); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E559 + (S555 * cos(i *  twicePi / triangleAmount)),
                        E5510 + (S555 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F505 =0.043, F551 =0.123f, S556=0.03f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F505, F551); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F505 + (S556 * cos(i *  twicePi / triangleAmount)),
                        F551 + (S556 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F552 =0.07, F553 =0.12f, S557=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F552, F553); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F552 + (S557 * cos(i *  twicePi / triangleAmount)),
                        F553 + (S557 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F554 =0.07, F555 =0.10f, S558=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F554, F555); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F554 + (S558 * cos(i *  twicePi / triangleAmount)),
                        F555 + (S558 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();

        ///_________D 5th tree 3________///
///_________BODY________///
    glPopMatrix();
     glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.55,1.34,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E5551 =0.062, E5552 =0.070f, S5551=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E551, E552); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);

            glVertex2f( E5551 + (S5551 * cos(i *  twicePi / triangleAmount)),
                        E5552 + (S5551 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E5553 =0.057, E5554 =0.09f, S5552=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5553, E5554); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E5553 + (S5552 * cos(i *  twicePi / triangleAmount)),
                        E5554 + (S5552 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E5555 =0.04, E5556 =0.081f, S5553=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5555, E5556); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E5555 + (S5553 * cos(i *  twicePi / triangleAmount)),
                        E5556 + (S5553 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E5557 =0.026, E5558 =0.089f, S5554=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5557, E5558); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E5557 + (S5554 * cos(i *  twicePi / triangleAmount)),
                        E5558 + (S5554 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E5559 =0.019, E55510 =0.10f, S5555=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5559, E55510); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E5559 + (S5555 * cos(i *  twicePi / triangleAmount)),
                        E55510 + (S5555 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F5505 =0.043, F5551 =0.123f, S5556=0.03f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F5505, F5551); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F5505 + (S5556 * cos(i *  twicePi / triangleAmount)),
                        F5551 + (S5556 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F5552 =0.07, F5553 =0.12f, S5557=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F5552, F5553); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F5552 + (S5557 * cos(i *  twicePi / triangleAmount)),
                        F5553 + (S5557 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F5554 =0.07, F5555 =0.10f, S5558=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F5554, F5555); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F5554 + (S5558 * cos(i *  twicePi / triangleAmount)),
                        F5555 + (S5558 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();
     ///_________D 5th tree 4________///
///_________BODY________///
    glPopMatrix();
     glPushMatrix();
    glScalef(0.25,0.25,0.0);
    glTranslatef(3.75,1.34,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.04f,0.02f);
    glVertex2f(0.04f,0.08f);
    glVertex2f(0.05f,0.08f);
    glVertex2f(0.05f,0.02f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.05f,0.05f);
    glVertex2f(0.05f,0.058f);
    glVertex2f(0.058f,0.065f);
    glVertex2f(0.04f,0.04f);
    glVertex2f(0.04f,0.048f);
    glVertex2f(0.028f,0.055f);
    glEnd();
    ///LEAF 1
    GLfloat E55551 =0.062, E55552 =0.070f, S55551=0.01f;
    glColor3f(0.314, 0.51, 0.125);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5551, E5552); // center of circle
        for( i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.51, 0.125);

            glVertex2f( E55551 + (S55551 * cos(i *  twicePi / triangleAmount)),
                        E55552 + (S55551 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 2
    GLfloat E55553 =0.057, E55554 =0.09f, S55552=0.017f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E55553, E55554); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E55553 + (S55552 * cos(i *  twicePi / triangleAmount)),
                        E55554 + (S55552 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 3
    GLfloat E55555 =0.04, E55556 =0.081f, S55553=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E5555, E5556); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E55555 + (S55553 * cos(i *  twicePi / triangleAmount)),
                        E55556 + (S55553 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 4
    GLfloat E55557 =0.026, E55558 =0.089f, S55554=0.014f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E55557, E55558); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E55557 + (S55554 * cos(i *  twicePi / triangleAmount)),
                        E55558 + (S55554 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
///LEAF 5
    GLfloat E55559 =0.019, E555510 =0.10f, S55555=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(E55559, E555510); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( E55559 + (S55555 * cos(i *  twicePi / triangleAmount)),
                        E555510 + (S55555 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 6
    GLfloat F55505 =0.043, F55551 =0.123f, S55556=0.03f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F5505, F5551); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F55505 + (S55556 * cos(i *  twicePi / triangleAmount)),
                        F55551 + (S55556 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 7
    GLfloat F55552 =0.07, F55553 =0.12f, S55557=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F55552, F55553); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F55552 + (S55557 * cos(i *  twicePi / triangleAmount)),
                        F55553 + (S55557 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///LEAF 8
    GLfloat F55554 =0.07, F55555 =0.10f, S55558=0.015f;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(F55554, F5555); // center of circle
        for( i = 0; i <= triangleAmount;i++) {

            glVertex2f( F55554 + (S55558 * cos(i *  twicePi / triangleAmount)),
                        F55555 + (S55558 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    glPopMatrix();


     ///_________ D Building border ________///
     glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    ///_________ 7th floor ________///
    glVertex2f(0.98f,0.453f);
    glVertex2f(0.75f,0.453f);
    glVertex2f(0.75f,0.453f);
    glVertex2f(0.74f,0.439f);
    glVertex2f(0.75f,0.453f);
    glVertex2f(0.75f,0.445f);

    glVertex2f(0.81f,0.453f);
    glVertex2f(0.81f,0.445f);
    glVertex2f(0.87f,0.453f);
    glVertex2f(0.87f,0.445f);
    glVertex2f(0.93f,0.453f);
    glVertex2f(0.93f,0.445f);
    ///_________ 5th floor ________///
    glVertex2f(0.76f,0.348f);
    glVertex2f(0.98f,0.348f);
    glVertex2f(0.76f,0.348f);
    glVertex2f(0.75f,0.335f);
    glVertex2f(0.76f,0.348f);
    glVertex2f(0.76f,0.340f);

    glVertex2f(0.81f,0.348f);
    glVertex2f(0.81f,0.340f);

    glVertex2f(0.87f,0.348f);
    glVertex2f(0.87f,0.340f);

    glVertex2f(0.93f,0.348f);
    glVertex2f(0.93f,0.340f);
    ///_________ D window (1) ________///
    glVertex2f(0.987f,0.56f);
    glVertex2f(0.987f,0.54f);
    glVertex2f(0.993f,0.54f);
    glVertex2f(0.993f,0.56f);
    glVertex2f(0.993f,0.56f);
    glVertex2f(0.987f,0.56f);
    glVertex2f(0.987f,0.54f);
    glVertex2f(0.993f,0.54f);
    ///_________ D window (2) ________///
    glVertex2f(0.987f,0.52f);
    glVertex2f(0.987f,0.50f);
    glVertex2f(0.993f,0.50f);
    glVertex2f(0.993f,0.52f);
    glVertex2f(0.993f,0.52f);
    glVertex2f(0.987f,0.52f);
    glVertex2f(0.987f,0.50f);
    glVertex2f(0.993f,0.50f);
    ///_________ D window (3) ________///
    glVertex2f(0.987f,0.48f);
    glVertex2f(0.987f,0.46f);
    glVertex2f(0.993f,0.46f);
    glVertex2f(0.993f,0.48f);
    glVertex2f(0.987f,0.48f);
    glVertex2f(0.993f,0.48f);
    glVertex2f(0.987f,0.46f);
    glVertex2f(0.993f,0.46f);
    ///_________ D window (4) ________///
    glVertex2f(0.987f,0.44f);
    glVertex2f(0.987f,0.42f);
    glVertex2f(0.993f,0.42f);
    glVertex2f(0.993f,0.44f);
    glVertex2f(0.993f,0.44f);
    glVertex2f(0.987f,0.44f);
    glVertex2f(0.987f,0.42f);
    glVertex2f(0.993f,0.42f);
    ///_________ D window (5) ________///
    glVertex2f(0.987f,0.40f);
    glVertex2f(0.987f,0.38f);
    glVertex2f(0.993f,0.38f);
    glVertex2f(0.993f,0.40f);
    glVertex2f(0.993f,0.40f);
    glVertex2f(0.987f,0.40f);
    glVertex2f(0.987f,0.38f);
    glVertex2f(0.993f,0.38f);
    ///_________ D window (6) ________///
    glVertex2f(0.987f,0.36f);
    glVertex2f(0.987f,0.34f);
    glVertex2f(0.993f,0.34f);
    glVertex2f(0.993f,0.36f);
    glVertex2f(0.993f,0.36f);
    glVertex2f(0.987f,0.36f);
    glVertex2f(0.987f,0.34f);
    glVertex2f(0.993f,0.34f);
    ///_________ D window (7) ________///
    glVertex2f(0.987f,0.32f);
    glVertex2f(0.987f,0.30f);
    glVertex2f(0.993f,0.30f);
    glVertex2f(0.993f,0.32f);
    glVertex2f(0.993f,0.32f);
    glVertex2f(0.987f,0.32f);
    glVertex2f(0.987f,0.30f);
    glVertex2f(0.993f,0.30f);
    ///_________ D window (8) ________///
    glVertex2f(0.987f,0.28f);
    glVertex2f(0.987f,0.26f);
    glVertex2f(0.993f,0.26f);
    glVertex2f(0.993f,0.28f);
    glVertex2f(0.993f,0.28f);
    glVertex2f(0.987f,0.28f);
    glVertex2f(0.987f,0.26f);
    glVertex2f(0.993f,0.26f);
    ///_________ D window (9) ________///
    glVertex2f(0.987f,0.24f);
    glVertex2f(0.987f,0.22f);
    glVertex2f(0.993f,0.22f);
    glVertex2f(0.993f,0.24f);
    glVertex2f(0.993f,0.24f);
    glVertex2f(0.987f,0.24f);
    glVertex2f(0.987f,0.22f);
    glVertex2f(0.993f,0.22f);
    ///_________ 1 ________///
    glVertex2f(0.95f,0.58f);
    glVertex2f(0.95f,0.61f);
    glVertex2f(0.95f,0.61f);
    glVertex2f(1.0f,0.61f);
    glVertex2f(0.98f,0.2f);
    glVertex2f(0.98f,0.58f);
    ///_________ body 2 ________///
    glVertex2f(0.74f,0.58f);
    glVertex2f(0.98f,0.58f);
    ///_________ 3 ________///
    glVertex2f(0.74f,0.545f);
    glVertex2f(0.98f,0.545f);
    glVertex2f(0.74f,0.565f);
    glVertex2f(0.98f,0.565f);
    ///_________ 4 ________///
    glVertex2f(0.74f,0.530f);
    glVertex2f(0.98f,0.530f);
    glVertex2f(0.74f,0.510f);
    glVertex2f(0.98f,0.510f);
    ///_________ 5 ________///
    glVertex2f(0.75f,0.495f);
    glVertex2f(0.98f,0.495f);
    glVertex2f(0.75f,0.445f);
    glVertex2f(0.98f,0.445f);
    ///_________ 6 ________///
    glVertex2f(0.74f,0.430f);
    glVertex2f(0.75f,0.445f);
    glVertex2f(0.74f,0.495f);
    glVertex2f(0.75f,0.495f);
    ///_________ 7 ________///
    glVertex2f(0.75f,0.410f);
    glVertex2f(0.98f,0.410f);
    glVertex2f(0.98f,0.43f);
    glVertex2f(0.75f,0.43f);
    glVertex2f(0.75f,0.410f);
    glVertex2f(0.75f,0.43f);
    ///_________ 8 ________///
    glVertex2f(0.76f,0.390f);
    glVertex2f(0.98f,0.390f);
    glVertex2f(0.76f,0.340f);
    glVertex2f(0.98f,0.340f);
    ///_________ 9 ________///
    glVertex2f(0.75f,0.390f);
    glVertex2f(0.76f,0.390f);
    glVertex2f(0.75f,0.325f);
    glVertex2f(0.76f,0.340f);
    glVertex2f(0.75f,0.390f);
    glVertex2f(0.75f,0.325f);
    ///_________ 10 ________///
    glVertex2f(0.76f,0.325f);
    glVertex2f(0.98f,0.325f);
    glVertex2f(0.76f,0.305f);
    glVertex2f(0.98f,0.305f);
    glVertex2f(0.76f,0.305f);
    glVertex2f(0.76f,0.325f);
    ///_________ 11 ________///
    glVertex2f(0.76f,0.290f);
    glVertex2f(0.98f,0.290f);
    glVertex2f(0.76f,0.270f);
    glVertex2f(0.98f,0.270f);
    glVertex2f(0.76f,0.290f);
    glVertex2f(0.76f,0.270f);
    ///_________ 12 ________///
    glVertex2f(0.76f,0.255f);
    glVertex2f(0.98f,0.255f);
    glVertex2f(0.76f,0.23f);
    glVertex2f(0.98f,0.23f);
    glVertex2f(0.76f,0.255f);
    glVertex2f(0.76f,0.23f);
    ///_________ 13 ________///
    glVertex2f(0.76f,0.212f);
    glVertex2f(0.98f,0.212f);
    glVertex2f(0.76f,0.2f);
    glVertex2f(0.98f,0.2f);
    glVertex2f(0.76f,0.212f);
    glVertex2f(0.76f,0.2f);
    ///_________ 14 ________///
    glVertex2f(0.68f,0.555f);
    glVertex2f(0.68f,0.2f);
    glVertex2f(0.74f,0.43f);
    glVertex2f(0.74f,0.58f);
    glVertex2f(0.68f,0.555f);
    glVertex2f(0.74f,0.58f);
    ///_________ 15 ________///
    glVertex2f(0.69f,0.544f);
    glVertex2f(0.69f,0.2f);
    glVertex2f(0.732f,0.405f);
    glVertex2f(0.732f,0.560f);
    glVertex2f(0.69f,0.544f);
    glVertex2f(0.732f,0.560f);
    glVertex2f(0.69f,0.2f);
    glVertex2f(0.732f,0.2f);
    glVertex2f(0.732f,0.403f);
    glVertex2f(0.743f,0.420f);
    ///_________ 16 ________///
    glVertex2f(0.743f,0.3f);
    glVertex2f(0.743f,0.420f);
    ///_________ 17 ________///
    glVertex2f(0.7425f,0.30f);
    glVertex2f(0.753f,0.315f);

    glVertex2f(0.753f,0.2f);
    glVertex2f(0.753f,0.315f);

    glEnd();

    ///_________________________________________________FIELD(2)___________________________________________________///

    glBegin(GL_QUADS);
    glColor3f(0.69, 0.851, 0.31);
    glVertex2f(0.0f,0.16f);
    glColor3f(0.396, 0.671, 0.141);
    glVertex2f(0.0f,0.00f);
    glVertex2f(1.0f,0.00f);
    glColor3f(0.69, 0.851, 0.31);
    glVertex2f(1.0f,0.16f);
    glEnd();

///_________________________________________________ROAD(3)___________________________________________________///
    glBegin(GL_QUADS);
    glColor3f(0.004f, 0.0f, 0.004f);
    glVertex2f(0.0f,0.2f);
    glVertex2f(0.0f,0.16f);
    glVertex2f(1.0f,0.16f);
    glVertex2f(1.0f,0.2f);
    glEnd();

///_____________________________________________ROAD CROSS LINE(4)___________________________________________________///
    glBegin(GL_LINES);
    glColor3f(1.00f, 1.0f, 1.00f);
    ///_________1________///
    glVertex2f(0.10f,0.18f);
    glVertex2f(0.20f,0.18f);
    ///_________2________///
    glVertex2f(0.30f,0.18f);
    glVertex2f(0.40f,0.18f);
    ///_________3________///
    glVertex2f(0.50f,0.18f);
    glVertex2f(0.60f,0.18f);
    ///_________4________///
    glVertex2f(0.70f,0.18f);
    glVertex2f(0.80f,0.18f);
    ///_________5________///
    glVertex2f(0.90f,0.18f);
    glVertex2f(1.00f,0.18f);
    glEnd();



///_______________________________________________FIELD Trees(1-4)___________________________________________________///

    ///_________TREE 1________///

    ///_________BODY________///
    glBegin(GL_QUADS);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.049f,0.0f);
    glVertex2f(0.049f,0.02f);
    glVertex2f(0.052f,0.02f);
    glVertex2f(0.052f,0.0f);
    ///_______Leaf 1_______///
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.075f,0.02f);
    glVertex2f(0.075f,0.04f);
    glVertex2f(0.025f,0.04f);
    glVertex2f(0.025f,0.02f);
    ///_______Leaf 2________///
    glVertex2f(0.03f,0.04f);
    glVertex2f(0.03f,0.06f);
    glVertex2f(0.07f,0.06f);
    glVertex2f(0.07f,0.04f);
    ///________Leaf 3_______///
    glVertex2f(0.035f,0.06f);
    glVertex2f(0.035f,0.08f);
    glVertex2f(0.0665f,0.08f);
    glVertex2f(0.0665f,0.06f);
    glEnd();
    ///_______HEAD________///
    glBegin(GL_TRIANGLES);
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.040f,0.08f);
    glVertex2f(0.05075f,0.12f);
    glVertex2f(0.0615f,0.08f);
    glEnd();

    ///_________TREE 2________///

    ///_________BODY________///
    glBegin(GL_QUADS);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.109f,0.0f);
    glVertex2f(0.109f,0.02f);
    glVertex2f(0.112f,0.02f);
    glVertex2f(0.112f,0.0f);
    ///_______Leaf 1_______///
    glBegin(GL_QUADS);
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.085f,0.02f);
    glVertex2f(0.085f,0.04f);
    glVertex2f(0.135f,0.04f);
    glVertex2f(0.135f,0.02f);
     ///_______Leaf 2_______///
    glVertex2f(0.09f,0.04f);
    glVertex2f(0.09f,0.06f);
    glVertex2f(0.13f,0.06f);
    glVertex2f(0.13f,0.04f);
    ///_______Leaf 3_______///
    glVertex2f(0.095f,0.06f);
    glVertex2f(0.095f,0.08f);
    glVertex2f(0.125f,0.08f);
    glVertex2f(0.125f,0.06f);
    glEnd();
    ///_______HEAD________///
    glBegin(GL_TRIANGLES);
    glVertex2f(0.10f,0.08f);
    glVertex2f(0.11f,0.12f);
    glVertex2f(0.12f,0.08f);
    glEnd();

    ///_________TREE 3________///

    ///_________BODY________///
    glBegin(GL_QUADS);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.95f,0.0f);
    glVertex2f(0.95f,0.02f);
    glVertex2f(0.953f,0.02f);
    glVertex2f(0.953f,0.0f);
    ///_______Leaf 1_______///
    glBegin(GL_QUADS);
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.925f,0.02f);
    glVertex2f(0.925f,0.04f);
    glVertex2f(0.975f,0.04f);
    glVertex2f(0.975f,0.02f);
    ///_______Leaf 2_______///
    glVertex2f(0.93f,0.04f);
    glVertex2f(0.93f,0.06f);
    glVertex2f(0.97f,0.06f);
    glVertex2f(0.97f,0.04f);
    ///_______Leaf 3_______///
    glVertex2f(0.935f,0.06f);
    glVertex2f(0.935f,0.08f);
    glVertex2f(0.965f,0.08f);
    glVertex2f(0.965f,0.06f);
    glEnd();
    ///_______HEAD________///
    glBegin(GL_TRIANGLES);
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.940f,0.08f);
    glVertex2f(0.95f,0.12f);
    glVertex2f(0.96f,0.08f);
    glEnd();

    ///_________TREE 4________///

    ///_________BODY________///
    glBegin(GL_QUADS);
    glColor3f(0.42f, 0.235f, 0.012f);
    glVertex2f(0.89f,0.0f);
    glVertex2f(0.89f,0.02f);
    glVertex2f(0.893f,0.02f);
    glVertex2f(0.893f,0.0f);
    ///_______Leaf 1_______///
    glBegin(GL_QUADS);
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.915f,0.02f);
    glVertex2f(0.915f,0.04f);
    glVertex2f(0.865f,0.04f);
    glVertex2f(0.865f,0.02f);
    ///_______Leaf 2_______///
    glVertex2f(0.91f,0.04f);
    glVertex2f(0.91f,0.06f);
    glVertex2f(0.87f,0.06f);
    glVertex2f(0.87f,0.04f);
    ///_______Leaf 3_______///
    glVertex2f(0.905f,0.06f);
    glVertex2f(0.905f,0.08f);
    glVertex2f(0.875f,0.08f);
    glVertex2f(0.875f,0.06f);
    glEnd();
    ///_______HEAD________///
    glBegin(GL_TRIANGLES);
    glColor3f(0.063f, 0.51f, 0.063f);
    glVertex2f(0.900f,0.08f);
    glVertex2f(0.89f,0.12f);
    glVertex2f(0.880f,0.08f);
    glEnd();
     ///_________________________________________________transparent stand ___________________________________________________///
     ///_________ T2________///
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.45f,0.20f);
    glVertex2f(0.45f,0.27f);
    glVertex2f(0.45f,0.27f);
    glVertex2f(0.45f,0.20f);

    glVertex2f(0.44f,0.27f);
    glVertex2f(0.46f,0.27f);
    glVertex2f(0.44f,0.269f);
    glVertex2f(0.46f,0.269f);

    glVertex2f(0.36f,0.20f);
    glVertex2f(0.36f,0.27f);
    glVertex2f(0.36f,0.27f);
    glVertex2f(0.36f,0.20f);

    glVertex2f(0.35f,0.27f);
    glVertex2f(0.37f,0.27f);

    glVertex2f(0.35f,0.269f);
    glVertex2f(0.37f,0.269f);

    glEnd();
    ///_________________________________________________TOP LAMP POST ___________________________________________________///
    ///_________ T1________///
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.075f,0.2f);
    glVertex2f(0.075f,0.28f);
    glVertex2f(0.075f,0.28f);
    glVertex2f(0.08f,0.27f);
    glEnd();
    glPointSize(6.0);
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.08f, 0.27f);
    glEnd();
    ///_________ T2________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.25f,0.2f);
    glVertex2f(0.25f,0.28f);
    glVertex2f(0.25f,0.28f);
    glVertex2f(0.255f,0.27f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.255f, 0.27f);
    glEnd();
    ///_________ T3________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.62f,0.2f);
    glVertex2f(0.62f,0.28f);
    glVertex2f(0.62f,0.28f);
    glVertex2f(0.625f,0.27f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.625f, 0.27f);
    glEnd();
    ///_________ T4________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.77f,0.2f);
    glVertex2f(0.77f,0.28f);
    glVertex2f(0.77f,0.28f);
    glVertex2f(0.775f,0.27f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.775f, 0.27f);
    glEnd();
    ///_________ T5________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.94f,0.2f);
    glVertex2f(0.94f,0.28f);
    glVertex2f(0.94f,0.28f);
    glVertex2f(0.945f,0.27f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.945f, 0.27f);
    glEnd();


///______________________________________________________CAR___________________________________________________///
///........................................Bus-1
   glPushMatrix();
    glTranslatef(Position3, 0.0, 0.0);  // Move the car horizontally
    glBegin(GL_QUADS);
    glColor3f(0.78f,0.137f,0.204f);
    glVertex2f(0.14f,0.175f);
    glVertex2f(0.14f,0.225f);
    glVertex2f(0.27f,0.225f);
    glVertex2f(0.27f,0.175f);
    ///Front Side Extra Part
    glVertex2f(0.27f,0.175f);
    glVertex2f(0.273f,0.175f);
    glVertex2f(0.273f,0.2f);
    glVertex2f(0.27f,0.205f);
    ///Window Slide Green Part
    glColor3f(0.031f,0.125f,0.059f);
    glVertex2f(0.143f,0.205f);
    glVertex2f(0.143f,0.223f);
    glVertex2f(0.268f,0.223f);
    glVertex2f(0.268f,0.205f);
    ///Window
    ///1. (Left To Right)
    glColor3f(0.655f,0.725f,0.725f);
    glVertex2f(0.1445f,0.207f);
    glVertex2f(0.1445f,0.221f);
    glVertex2f(0.157f,0.221f);
    glVertex2f(0.157f,0.207f);
    ///2.
    glVertex2f(0.159f,0.207f);
    glVertex2f(0.159f,0.221f);
    glVertex2f(0.173f,0.221f);
    glVertex2f(0.173f,0.207f);
    ///3.
    glVertex2f(0.175f,0.207f);
    glVertex2f(0.175f,0.221f);
    glVertex2f(0.1885f,0.221f);
    glVertex2f(0.1885f,0.207f);
    ///4.
    glVertex2f(0.191f,0.207f);
    glVertex2f(0.191f,0.221f);
    glVertex2f(0.205f,0.221f);
    glVertex2f(0.205f,0.207f);
    ///5.
    glVertex2f(0.207f,0.207f);
    glVertex2f(0.207f,0.221f);
    glVertex2f(0.222f,0.221f);
    glVertex2f(0.222f,0.207f);
    ///6.
    glVertex2f(0.245f,0.207f);
    glVertex2f(0.245f,0.221f);
    glVertex2f(0.258f,0.221f);
    glVertex2f(0.258f,0.207f);
    ///7.
    glVertex2f(0.26f,0.207f);
    glVertex2f(0.26f,0.221f);
    glVertex2f(0.266f,0.221f);
    glVertex2f(0.266f,0.207f);
    ///......Door
    glVertex2f(0.225f,0.175f);
    glVertex2f(0.225f,0.217f);
    glVertex2f(0.243f,0.217f);
    glVertex2f(0.243f,0.175f);
    glEnd();
    ///....Bus Door Line
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.234f,0.175f);
    glVertex2f(0.234f,0.219f);
    ///.....Side Mirror Stand
    glColor3f(0.78f,0.137f,0.204f);
    glVertex2f(0.27f,0.22f);
    glVertex2f(0.277f,0.22f);
    glEnd();
    ///........Side Mirror
    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.277f,0.22f);
    glVertex2f(0.277f,0.205f);
    glEnd();
    ///...........Bus Tier Right
    GLfloat Ak50=0.257f; GLfloat Pk50=0.175f; GLfloat Ok50 =0.008f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(Ak50, Pk50); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( Ak50 + (Ok50 * cos(i *  twicePi/ triangleAmount)),
                        Pk50 + (Ok50 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///...........Bus Tier Alloy Right
    GLfloat Ak51=0.257f; GLfloat Pk51=0.175f; GLfloat Ok51 =0.004f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(Ak51, Pk51); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( Ak51 + (Ok51 * cos(i *  twicePi/ triangleAmount)),
                        Pk51 + (Ok51 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///...........Bus Tier left
    GLfloat Ak52=0.166f; GLfloat Pk52=0.175f; GLfloat Ok52 =0.008f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(Ak52, Pk52); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( Ak52 + (Ok52 * cos(i *  twicePi/ triangleAmount)),
                        Pk52 + (Ok52 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///...........Bus Tier Alloy Left
    GLfloat Ak53=0.166f; GLfloat Pk53=0.175f; GLfloat Ok53 =0.004f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(Ak53, Pk53); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( Ak53 + (Ok53 * cos(i *  twicePi/ triangleAmount)),
                        Pk53 + (Ok53 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
///______________________________________________________CAR___________________________________________________///
///...........................................Bus-2
    glPushMatrix();
    glTranslatef(+0.4f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(0.114f,0.18f,0.612f);
    glVertex2f(0.14f,0.175f);
    glVertex2f(0.14f,0.225f);
    glVertex2f(0.27f,0.225f);
    glVertex2f(0.27f,0.175f);
    ///Front Side Extra Part
    glVertex2f(0.27f,0.175f);
    glVertex2f(0.273f,0.175f);
    glVertex2f(0.273f,0.2f);
    glVertex2f(0.27f,0.205f);
    ///Window Slide Green Part
    glColor3f(0.031f,0.125f,0.059f);
    glVertex2f(0.143f,0.205f);
    glVertex2f(0.143f,0.223f);
    glVertex2f(0.268f,0.223f);
    glVertex2f(0.268f,0.205f);
    ///Window
    ///1. (Left To Right)
    glColor3f(0.655f,0.725f,0.725f);
    glVertex2f(0.1445f,0.207f);
    glVertex2f(0.1445f,0.221f);
    glVertex2f(0.157f,0.221f);
    glVertex2f(0.157f,0.207f);
    ///2.
    glVertex2f(0.159f,0.207f);
    glVertex2f(0.159f,0.221f);
    glVertex2f(0.173f,0.221f);
    glVertex2f(0.173f,0.207f);
    ///3.
    glVertex2f(0.175f,0.207f);
    glVertex2f(0.175f,0.221f);
    glVertex2f(0.1885f,0.221f);
    glVertex2f(0.1885f,0.207f);
    ///4.
    glVertex2f(0.191f,0.207f);
    glVertex2f(0.191f,0.221f);
    glVertex2f(0.205f,0.221f);
    glVertex2f(0.205f,0.207f);
    ///5.
    glVertex2f(0.207f,0.207f);
    glVertex2f(0.207f,0.221f);
    glVertex2f(0.222f,0.221f);
    glVertex2f(0.222f,0.207f);
    ///6.
    glVertex2f(0.245f,0.207f);
    glVertex2f(0.245f,0.221f);
    glVertex2f(0.258f,0.221f);
    glVertex2f(0.258f,0.207f);
    ///7.
    glVertex2f(0.26f,0.207f);
    glVertex2f(0.26f,0.221f);
    glVertex2f(0.266f,0.221f);
    glVertex2f(0.266f,0.207f);
    ///......Door
    glVertex2f(0.225f,0.175f);
    glVertex2f(0.225f,0.217f);
    glVertex2f(0.243f,0.217f);
    glVertex2f(0.243f,0.175f);
    glEnd();
    ///....Bus Door Line
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.234f,0.175f);
    glVertex2f(0.234f,0.219f);
    ///.....Side Mirror Stand
    glColor3f(0.114f,0.18f,0.612f);
    glVertex2f(0.27f,0.22f);
    glVertex2f(0.277f,0.22f);
    glEnd();
    ///........Side Mirror
    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.277f,0.22f);
    glVertex2f(0.277f,0.205f);
    glEnd();
    ///...........Bus Tier Right
    GLfloat Ak54=0.257f; GLfloat Pk54=0.175f; GLfloat Ok54 =0.008f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(Ak54, Pk54); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( Ak54 + (Ok54 * cos(i *  twicePi/ triangleAmount)),
                        Pk54 + (Ok54 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///...........Bus Tier Alloy Right
    GLfloat Ak55=0.257f; GLfloat Pk55=0.175f; GLfloat Ok55 =0.004f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(Ak55, Pk55); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( Ak55 + (Ok55 * cos(i *  twicePi/ triangleAmount)),
                        Pk55 + (Ok55 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///...........Bus Tier left
    GLfloat Ak56=0.166f; GLfloat Pk56=0.175f; GLfloat Ok56 =0.008f;
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(Ak56, Pk56); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( Ak56 + (Ok56 * cos(i *  twicePi/ triangleAmount)),
                        Pk56 + (Ok56 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    ///...........Bus Tier Alloy Left
    GLfloat Ak57=0.166f; GLfloat Pk57=0.175f; GLfloat Ok57 =0.004f;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(Ak57, Pk57); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f( Ak57 + (Ok57 * cos(i *  twicePi/ triangleAmount)),
                        Pk57 + (Ok57 * sin(i * twicePi / triangleAmount)));
        }
    glEnd();
    glPopMatrix();
    glPopMatrix();



///_________________________________________________DOWN LAMP POST ___________________________________________________///
    ///_________ D1________///
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.165f,0.16f);
    glVertex2f(0.165f,0.24f);
    glVertex2f(0.165f,0.24f);
    glVertex2f(0.17f,0.23f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.17f, 0.23f);
    glEnd();
    ///_________ D2 ________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.33f,0.16f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.335f,0.23f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.335f, 0.23f);
    glEnd();
    ///_________ D3________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.69f,0.16f);
    glVertex2f(0.69f,0.24f);
    glVertex2f(0.69f,0.24f);
    glVertex2f(0.695f,0.23f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.695f, 0.23f);
    glEnd();
    ///_________ D4________///
    glBegin(GL_LINES);
    glColor3f(0.31f, 0.31f, 0.31f);
    glVertex2f(0.85f,0.16f);
    glVertex2f(0.85f,0.24f);
    glVertex2f(0.85f,0.24f);
    glVertex2f(0.855f,0.23f);
    glEnd();
    glPointSize(6.0);// multiple pixels nia point show korte
    glBegin(GL_POINTS);
    glColor3f(0.992f, 0.875f, 0.424f);
    glVertex2f(0.855f, 0.23f);
    glEnd();
///______________________________________________________Soil___________________________________________________///
    ///_______soil 2______///
    GLfloat sp=0.485f;GLfloat sp1=0.023f;GLfloat o1 =.05f;
    glColor3f(0.898f, 0.651f, 0.502f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sp, sp1); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( sp + (o1 * cos(i *  twicePi / triangleAmount)),
                    sp1 + (o1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
    ///_______soil 2 border______///
     glColor3f(0.0,0.0,0.0);
    GLfloat sp411=0.485f;GLfloat sp111=0.023f;GLfloat o111 =.05f;
    glBegin(GL_LINE_LOOP);
    glVertex2f(sp411, sp111); // center of circle
    for(i = 0; i <= lineAmount; i++)
    {glColor3f(0.0,0.0,0.0);
        glVertex2f( sp411 + (o111 * cos(i *  twicePi / lineAmount)),
                    sp111 + (o111 * sin(i * twicePi / lineAmount)) );
    }
    glEnd();
    ///_______soil 1______///
    GLfloat sp4=0.38f;GLfloat sp5=0.021f;GLfloat o3 =.08f;
    glColor3f(0.898f, 0.651f, 0.502f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sp4, sp5); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( sp4+ (o3 * cos(i *  twicePi / triangleAmount)),
                    sp5 + (o3 * sin(i * twicePi / triangleAmount)) );
    }
     glEnd();
    ///_______soil 3______///
    GLfloat sp2 =0.60f;GLfloat sp3=0.023f;GLfloat o2 =.09f;
    glColor3f(0.898f, 0.651f, 0.502f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sp2, sp3); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( sp2 + (o2 * cos(i *  twicePi / triangleAmount)),
                    sp3 + (o2 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///______________________________________________________Soil border___________________________________________________///
    ///_______soil 1 border______///
    GLfloat sp114=0.38f;GLfloat sp115=0.021f;GLfloat o113 =.08f;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(sp114, sp115); // center of circle
    for(i = 0; i <= lineAmount; i++)
    {
        glVertex2f( sp114+ (o113 * cos(i *  twicePi /lineAmount)),
                    sp115 + (o113 * sin(i * twicePi / lineAmount)) );
    }
     glEnd();
    ///_______soil 3 Border______///
    glColor3f(0.0,0.0,0.0);
    GLfloat sp112 =0.60f;GLfloat sp113=0.023f;GLfloat o112 =.09f;
    glBegin(GL_LINE_LOOP);
    glVertex2f(sp112, sp113); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {glColor3f(0.0,0.0,0.0);
        glVertex2f( sp112 + (o112 * cos(i *  twicePi / lineAmount)),
                    sp113 + (o112 * sin(i * twicePi / lineAmount)) );

    }
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.898f, 0.651f, 0.502f);
    glVertex2f(0.35,0.059);
    glVertex2f(0.35,0.0);
    glVertex2f(0.67,0.0);
    glVertex2f(0.67,0.06);
    glEnd();
///______________________________________________________Pool___________________________________________________///
    ///_______pool 2 border______///
    GLfloat spp21=0.485f;GLfloat spp11=0.023f;GLfloat op11 =.04f;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(spp21, spp11); // center of circle
    for(i = 0; i <= lineAmount; i++)
    {
        glVertex2f( spp21 + (op11 * cos(i *  twicePi / lineAmount)),
                    spp11 + (op11 * sin(i * twicePi / lineAmount)) );
    }
    glEnd();

     ///_______pool 1______///
    GLfloat sp14=0.38f;GLfloat sp15=0.021f;GLfloat o13 =.07f;
    glColor3f(0.443, 0.78, 0.898);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sp14, sp15); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( sp14+ (o13 * cos(i *  twicePi / triangleAmount)),
                    sp15 + (o13 * sin(i * twicePi / triangleAmount)) );
    }
     glEnd();

     ///_______pool 2______///
    GLfloat sp21=0.485f;GLfloat sp11=0.023f;GLfloat o11 =.04f;
    glColor3f(0.443, 0.78, 0.898);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sp21, sp11); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( sp21 + (o11 * cos(i *  twicePi / triangleAmount)),
                    sp11 + (o11 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    ///_______pool 3______///
    GLfloat sp12 =0.60f;GLfloat sp13=0.023f;GLfloat o12 =.08f;
    glColor3f(0.443, 0.78, 0.898);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(sp12, sp13); // center of circle
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( sp12 + (o12 * cos(i *  twicePi / triangleAmount)),
                    sp13 + (o12 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();
///______________________________________________________Pool border___________________________________________________///

///_______pool 1______///
    GLfloat spp14=0.38f;GLfloat spp15=0.021f;GLfloat op13 =.07f;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(spp14, spp15); // center of circle
    for(i = 0; i <= lineAmount; i++)
    {
        glVertex2f( spp14+ (op13 * cos(i *  twicePi / lineAmount)),
                    spp15 + (op13 * sin(i * twicePi / lineAmount)) );
    }
     glEnd();


    ///_______pool 3______///
    GLfloat spp12 =0.60f;GLfloat spp13=0.023f;GLfloat op12 =.08f;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(spp12, spp13); // center of circle
    for(i = 0; i <= lineAmount; i++)
    {
        glVertex2f( spp12 + (op12 * cos(i *  twicePi / lineAmount)),
                    spp13 + (op12 * sin(i * twicePi / lineAmount)) );
    }
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.443, 0.78, 0.898);
    glVertex2f(0.35,0.039);
    glVertex2f(0.35,0.0);
    glVertex2f(0.67,0.0);
    glVertex2f(0.67,0.039);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.443, 0.78, 0.898);
    glVertex2f(0.67,0.024);
    glVertex2f(0.679,0.024);
    glColor3f(0.898f, 0.651f, 0.502f);
    glVertex2f(0.681,0.024);
    glVertex2f(0.69,0.024);
    glEnd();


     glFlush(); // Render now
}

void update1(int value)
{
    if(Position1 >2.0 )
        Position1 = -1.0f;
    Position1 += Speed1;
    glutPostRedisplay();
    glutTimerFunc(100, update1, 0);
}

void update2(int value)
{
    if(Position2 >2.0 )
        Position2 = -1.0f;
    Position2 += Speed2;
    glutPostRedisplay();
    glutTimerFunc(100, update2, 0);
}

void update3(int value)
{
    if(Position3 >2.0 )
        Position3 = -1.0f;
    Position3 += Speed3;
    glutPostRedisplay();
    glutTimerFunc(100, update3, 0);
}

GLfloat MPosition = 0.0f;
GLfloat IPosition = 0.0f;
GLfloat Mspeed = 0.005f;
GLfloat Ispeed = 0.005f;
GLfloat m = 0.0f;

void display1() {
	glClearColor(0.f, 0.f, 0.f, .0f); // Set background color to gray and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

	////Small Star
	glPointSize(3.0);
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_POINTS);
	glVertex2f(0.9f,0.9f);
	glVertex2f(0.01f,0.8f);
	glVertex2f(0.1f,0.7f);
	glVertex2f(0.95f,0.15f);
	glVertex2f(0.76f,0.26f);
	glVertex2f(0.70f,0.36f);
	glEnd();

	glPointSize(3.0);
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_POINTS);
    glVertex2f(0.14f,0.74f);
	glVertex2f(0.04f,0.34f);
	glVertex2f(0.84f,0.24f);
	glVertex2f(0.93f,0.33f);
	glEnd();


    ///circle1
	GLfloat m0=0.45f; GLfloat g0=0.45f; GLfloat h0 =.35f;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m0, g0); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( m0+ (h0 * cos(i *  twicePi / triangleAmount)),
                        g0 + (h0 * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();

	///circle2
	GLfloat m01=0.53f; GLfloat g01=0.53f; GLfloat h01 =.35f;
	glColor3f(.0f, .0f, .0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(m01, g01); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f( m01+ (h01 * cos(i *  twicePi / triangleAmount)),
                        g01 + (h01 * sin(i * twicePi / triangleAmount)) );
		}
	glEnd();

	///Text
	glPushMatrix();
	glTranslatef(0.0f, -0.10f, 0.0f);
	glColor3f(0.247f, 0.722f, 0.773f);
    renderBitmapString(0.30f, 0.9f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "AMERICAN INTERNATION UNIVERSITY BANGLADESH");
    glColor3f(0.78f, 0.914f, 0.71f);
    renderBitmapString(0.45f, 0.85f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "NOBORANJAN DEY");
    glColor3f(1.0f, 0.518f, 0.486f);
    renderBitmapString(0.44f, 0.80f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, " PROJECT SPACE");
    glColor3f(0.855f, 0.71f, 0.4f);

    renderBitmapString(0.30f, 0.70f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ID:23-50738-1  NAME:MD.KAMRUL HASAN");
    renderBitmapString(0.30f, 0.65f, 0.0f, GLUT_BITMAP_HELVETICA_18 ,"ID:23-50413-1  NAME:ABIDUR RAHMAN");
    renderBitmapString(0.30f, 0.60f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ID:23-50433-1  NAME:MD.AMIR HOSSAEN");
    renderBitmapString(0.30f, 0.55f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ID:23-50985-1  NAME:MD.ASICKUZZAMAN");

    glPopMatrix();
    ///Point
    glPointSize(3.0);
	glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.6f,0.4f);
	glVertex2f(0.4f,0.24f);
	glVertex2f(0.54f,0.20f);
	glVertex2f(0.70f,0.16f);
	glVertex2f(0.8f,0.8f);
	glVertex2f(0.9f,0.94f);
	glVertex2f(0.94f,0.70f);
	glVertex2f(0.7f,0.66f);
	glColor3f(1.0f,.0f,1.0f);
	glVertex2f(0.07f,1.36f);
	glEnd();

    ///STAR1
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(0.60f,0.6f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR2
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(0.30f,0.10f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();
    ///STAR3
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(1.40f,1.20f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();
    ///STAR3
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(1.20f,0.0f,0.0f);
	glTranslatef(1.20f,0.0f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();
    ///STAR4
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(.05f,1.70f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();
    ///STAR5
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(1.5f,.05f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();
    ///STAR6
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(.65f,1.50f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();
    //STAR7
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(1.9f,.70f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();
     ///STAR9
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(.07f,.80f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();

    ///STAR13
	glPushMatrix();
	glScalef(.5,.5,0);
	glTranslatef(1.30f,1.88f,0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(.030f,.040f);
    glVertex2f(.050f,0.030f);
    glVertex2f(.040f,.050f);
    glVertex2f(.057f,.060f);
    glVertex2f(.037f,.060f);
    glVertex2f(.030f,.080f);
    glVertex2f(.023f,.060f);
    glVertex2f(.003f,.060f);
    glVertex2f(.020f,.050f);
    glVertex2f(.010f,0.030f);
    glEnd();
    glPopMatrix();


     ///Point
    glPointSize(3.0);
	glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.16f,0.94f);
	glVertex2f(0.04f,0.84f);
	glVertex2f(.54f,.980f);
	glVertex2f(0.70f,0.96f);
	glVertex2f(.79f,0.98f);
	glVertex2f(.49f,0.04f);
	glVertex2f(.54f,0.70f);
	glVertex2f(.67f,0.46f);
	glVertex2f(.67f,.06f);
	glEnd();
	     ///Point
    glPointSize(2.5);
	glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.6f,0.04f);
	glVertex2f(0.04f,0.24f);
	glVertex2f(.54f,.28f);
	glVertex2f(0.70f,0.26f);
	glVertex2f(.39f,0.08f);
	glVertex2f(.89f,0.44f);
	glVertex2f(.94f,0.79f);
	glVertex2f(.17f,0.04f);
	glVertex2f(.07f,.26f);
	glEnd();


    ///_________ 1________///

    glPushMatrix();
    glTranslatef(0.0f,MPosition, 0.0f);
    glScalef(0.4,0.4,0);
    glTranslatef(1.80,0.05,0.0);
    ///.......................................Cylinder .................
    glBegin(GL_QUADS);
    ///_______11 Right small rocket Body_____///
    glColor3f(0.196, 0.51, 0.984);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Body_____///
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    glBegin(GL_TRIANGLES);
    ///_______11 Right small rocket Head_____///
    glColor3f(0.98, 0.549, 0.11);
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Head_____///
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
     ///_______11 Right small rocket Body_____///
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    glVertex2f(0.445f,0.39f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.445f,0.39f);
    glVertex2f(0.43f,0.23f);
    glVertex2f(0.44f,0.23f);
    ///_______12 Left small rocket Body_____///
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    glVertex2f(0.375f,0.39f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.375f,0.39f);
    glVertex2f(0.370f,0.23f);
    glVertex2f(0.380f,0.23f);
    ///_______11 Right small rocket Head_____///
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.435f,0.39f);
    glVertex2f(0.440f,0.42f);
    glVertex2f(0.445f,0.39f);
    ///_______12 Left small rocket Head_____///
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.365f,0.39f);
    glVertex2f(0.370f,0.42f);
    glVertex2f(0.375f,0.39f);
    glEnd();
    ///_________ Fire left ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.535,0.340,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    ///_________ Fire Right ________///
    glPushMatrix();
    glScalef(0.4,0.4,0.0);
    glTranslatef(0.685,0.340,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

///_____________________________________________ROCKET(START)___________________________________________________///
    ///_________ 1________///
    glPushMatrix();
    glTranslatef(0.0f,IPosition, 0.0f);
    glScalef(0.4,0.4,0);
    glTranslatef(1.80,0.05,0.0);
    glBegin(GL_QUADS);
    glColor3f(0.455, 0.525, 0.553);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    ///_________ 2________///
    glColor3f(0.345, 0.416, 0.424);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    ///_________ 3________///
    glColor3f(0.224, 0.49, 0.886);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    ///_________ 4________///
    glColor3f(0.478, 0.537, 0.565);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glColor3f(0.349, 0.42, 0.435);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    ///_________ 5________///
    glColor3f(0.976, 0.475, 0.133);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glColor3f(0.925, 0.431, 0.075);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    ///_________ 6________///
    glColor3f(0.471, 0.529, 0.557);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glColor3f(0.208, 0.247, 0.251);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);

    ///_________ 9________///
    glColor3f(0.588, 0.647, 0.663);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    ///_________ 10________///
    glColor3f(0.976, 0.475, 0.133);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glColor3f(0.835, 0.388, 0.09);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    ///_________ Upper and Lower border________///
    ///_______Lower L_____///
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.39f,0.34f);
    glVertex2f(0.39f,0.25f);
    glVertex2f(0.392f,0.25f);
    glVertex2f(0.392f,0.34f);
    ///_______Lower R_____///
    glVertex2f(0.4185f,0.34f);
    glVertex2f(0.4185f,0.25f);
    glVertex2f(0.42f,0.25f);
    glVertex2f(0.42f,0.34f);
    ///_______upper_____///
    glVertex2f(0.372f,0.452f);
    glVertex2f(0.372f,0.449f);
    glVertex2f(0.438f,0.449f);
    glVertex2f(0.438f,0.452f);
    glEnd();
    glBegin(GL_QUADS);
    ///_________ 7(Wing 1)________///
    glColor3f(0.224, 0.494, 0.882);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    ///_________ 8(Wing 2)________///
    glColor3f(0.125, 0.42, 0.776);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glEnd();

    ///_____________________________Rocket TOP window___________________________________///
    ///_________ 11________///
    glColor3f(0.976, 0.482, 0.125);
    GLfloat xrtw1=0.405f; GLfloat yrtw1=0.45f; GLfloat rrtw1 =.015f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrtw1, yrtw1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.976, 0.482, 0.125);
            glVertex2f( xrtw1 + (rrtw1 * cos(i *  twicePi / triangleAmount)),
                        yrtw1 + (rrtw1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 12________///
    glColor3f(0.314, 0.863, 0.98);
    GLfloat xrtw2=0.405f; GLfloat yrtw2=0.45f; GLfloat rrtw2 =.010f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrtw2, yrtw2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.314, 0.863, 0.98);
            glVertex2f( xrtw2 + (rrtw2 * cos(i *  twicePi / triangleAmount)),
                        yrtw2 + (rrtw2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket bottom window___________________________________///
    ///_________ 13________///
    glColor3f(0.31, 0.847, 0.973);
    GLfloat xrbw3=0.405f; GLfloat yrbw3=0.30f; GLfloat rrbw3 =.010f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrbw3, yrbw3); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
                glColor3f(0.31, 0.847, 0.973);
            glVertex2f( xrbw3 + (rrbw3 * cos(i *  twicePi / triangleAmount)),
                        yrbw3 + (rrbw3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Mini window___________________________________///
    ///_________ 14________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw1=0.385f; GLfloat yrmw1=0.52f; GLfloat rrmw1 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw1, yrmw1); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw1 + (rrmw1 * cos(i *  twicePi / triangleAmount)),
                        yrmw1 + (rrmw1 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 15________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw2=0.405f; GLfloat yrmw2=0.52f; GLfloat rrmw2 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw2, yrmw2); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw2 + (rrmw2 * cos(i *  twicePi / triangleAmount)),
                        yrmw2 + (rrmw2 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
     ///_________ 16________///
    glColor3f(0.808, 0.839, 0.847);
    GLfloat xrmw3=0.425f; GLfloat yrmw3=0.52f; GLfloat rrmw3 =.005f;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(xrmw3, yrmw3); // center of circle
        for(i = 0; i <= triangleAmount;i++) {
            glVertex2f( xrmw3 + (rrmw3 * cos(i *  twicePi / triangleAmount)),
                        yrmw3 + (rrmw3 * sin(i * twicePi / triangleAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Border___________________________________///
    ///_________ 1________///
    glLineWidth(1.4);
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.24f);
    glVertex2f(0.423f,0.24f);
    glVertex2f(0.387f,0.23f);
    glVertex2f(0.423f,0.23f);
    ///_________ 2________///
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.38f,0.24f);
    glVertex2f(0.43f,0.24f);
    ///_________ 3________///
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    ///_________ 4________///
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.37f,0.50f);
    glVertex2f(0.44f,0.50f);
    ///_________ 5________///
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.37f,0.51f);
    glVertex2f(0.44f,0.51f);
    ///_________ 6________///
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.403f,0.59f);
    glVertex2f(0.407f,0.59f);
    glVertex2f(0.38f,0.56f);
    glVertex2f(0.43f,0.56f);
    ///_________ 7(Wing 1)________///
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.376f,0.36f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.33f,0.24f);
    glVertex2f(0.32f,0.23f);
    ///_________ 8(Wing 2)________///
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.36f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.48f,0.24f);
    glVertex2f(0.49f,0.23f);
    ///_________ 9________///
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.35f);
    glVertex2f(0.434f,0.35f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    ///_________ 10________///
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.376f,0.34f);
    glVertex2f(0.434f,0.34f);
    glVertex2f(0.38f,0.25f);
    glVertex2f(0.43f,0.25f);
    glEnd();


    ///_____________________________Rocket TOP window(Border)___________________________________///
    ///_________ 11________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrtwb1=0.405f; GLfloat yrtwb1=0.45f; GLfloat rrtwb1 =.015f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrtwb1, yrtwb1); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrtwb1 + (rrtwb1 * cos(i *  twicePi / lineAmount)),
                        yrtwb1 + (rrtwb1 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
     ///_________ 12________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrtwb2=0.405f; GLfloat yrtwb2=0.45f; GLfloat rrtwb2 =.010f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrtwb2, yrtwb2); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrtwb2 + (rrtwb2 * cos(i *  twicePi / lineAmount)),
                        yrtwb2 + (rrtwb2 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
    ///_____________________________Rocket bottom window(Border)___________________________________///
    ///_________ 13________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrbwb3=0.405f; GLfloat yrbwb3=0.30f; GLfloat rrbwb3 =.010f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrbwb3, yrbwb3); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrbwb3 + (rrbwb3 * cos(i *  twicePi / lineAmount)),
                        yrbwb3 + (rrbwb3 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
    ///_____________________________Rocket Mini window(Border)___________________________________///
    ///_________ 14________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb1=0.385f; GLfloat yrmwb1=0.52f; GLfloat rrmwb1 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb1, yrmwb1); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb1 + (rrmwb1 * cos(i *  twicePi / lineAmount)),
                        yrmwb1 + (rrmwb1 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();
     ///_________ 15________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb2=0.405f; GLfloat yrmwb2=0.52f; GLfloat rrmwb2 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb2, yrmwb2); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb2 + (rrmwb2 * cos(i *  twicePi / lineAmount)),
                        yrmwb2 + (rrmwb2 * sin(i * twicePi /lineAmount)) );
        }
    glEnd();
     ///_________ 16________///
    glColor3f(0.0,0.0,0.0);
    GLfloat xrmwb3=0.425f; GLfloat yrmwb3=0.52f; GLfloat rrmwb3 =.005f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(xrmwb3, yrmwb3); // center of circle
        for(i = 0; i <= lineAmount;i++) {
            glVertex2f( xrmwb3 + (rrmwb3 * cos(i *  twicePi / lineAmount)),
                        yrmwb3 + (rrmwb3 * sin(i * twicePi / lineAmount)) );
        }
    glEnd();

    ///_________ Fire main 1________///
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.20f);
    glVertex2f(0.36f,0.14f);
    glVertex2f(0.388f,0.17f);
    glVertex2f(0.4f,0.12f);
    glVertex2f(0.42f,0.18f);
    glVertex2f(0.45f,0.14f);
    glVertex2f(0.42f,0.20f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.20f);
    glVertex2f(0.38f,0.168f);
    glVertex2f(0.395f,0.19f);
    glVertex2f(0.40f,0.14f);
    glVertex2f(0.41f,0.19f);
    glVertex2f(0.43f,0.17f);
    glVertex2f(0.417f,0.20f);
    glEnd();
    ///_________ Fire main 2________///
    glBegin(GL_POLYGON);
    glColor3f(0.988f, 0.702f, 0.11f);
    glVertex2f(0.39f,0.23f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.388f,0.2f);
    glVertex2f(0.4f,0.15f);
    glVertex2f(0.42f,0.21f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.42f,0.23f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.953f, 0.906f, 0.396f);
    glVertex2f(0.392f,0.23f);
    glVertex2f(0.38f,0.198f);
    glVertex2f(0.395f,0.22f);
    glVertex2f(0.40f,0.19f);
    glVertex2f(0.41f,0.22f);
    glVertex2f(0.43f,0.2f);
    glVertex2f(0.417f,0.23f);
    glEnd();
    glPopMatrix();
    ///_____________________________________________ROCKET(END)___________________________________________________///

    glFlush();
}

void updateM(int value)
{
    if(MPosition >2.0 )
        MPosition = -1.0f;
    MPosition += Mspeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateM, 0);
}
///.........Rocket
void updateI(int value)
{
    if(IPosition >2.0 )
        IPosition = -1.0f;
    IPosition += Ispeed;
    glutPostRedisplay();
    glutTimerFunc(100, updateI, 0);
}



void handleKeypressM(unsigned char key, int x, int y)
{
    switch(key)
    {

                    /// ........Rocket Fast
                         case 'j':
                         Mspeed=0.015f;
                         Ispeed=0.015f;
                         break;
                         /// .......Rocket Slow
                         case 'l':
                         Mspeed=0.01f;
                         Ispeed=0.01f;
                         break;
                         ///.........Rocket stop
                         case 'k':
                         Mspeed=0.0f;
                         Ispeed=0.0f;
                         break;
                         ///........Rocket BackWord
                         case ';':
                         Mspeed=-0.01f;
                         Ispeed=-0.01f;
                         break;

                    ///................Cloud and Bus start
                        case 'v':
                         Speed1=-0.005f;
                         Speed3=0.015f;
                         break;
                         ///Cloud and Bus stop
                         case 'b':
                         Speed1=0.0f;
                         Speed3=0.0f;
                         break;
                         ///Rocket start
                         case 'n':
                         Speed2=0.015f;
                         break;
                         ///Rocket stop
                         case 'm':
                         Speed2=0.0f;
                         break;

                         case 't':
                         Tspeed=0.017f;
                         Dspeed=0.017f;
                         break;
                         case 'u':
                         Tspeed=-0.017f;
                         Dspeed=-0.017f;
                         break;
                         ///.......Rocket stop
                         case 'y':
                         Tspeed=0.0f;
                         Dspeed=0.0f;
                         break;

                         case 'w':
                         Aspeed=0.015f;
                         Pspeed=0.015f;
                         break;
                         case 's':
                         Aspeed=-0.02f;
                         break;
                         case 'a':
                         Pspeed=-0.02f;
                         break;
                         ///.......Rocket
                         case 'd':
                         Pspeed=0.0f;
                         Aspeed=0.0f;
                         break;


    case '1':
    glutDisplayFunc(display1);

    glutPostRedisplay();
    break;
    case '2':
    glutDisplayFunc(display2);
    glutPostRedisplay();
    break;
    case '3':
    glutDisplayFunc(display3);
    glutPostRedisplay();
    break;
    case '4':
    glutDisplayFunc(display4);
    glutPostRedisplay();
    break;
    case '5':
    glutDisplayFunc(display5);
    glutPostRedisplay();
    break;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitWindowSize(1400, 800);
	glutCreateWindow("Project - Space");
    glutPositionWindow(80, 50);
    init();
    glutKeyboardFunc(handleKeypressM);
    glutTimerFunc(100, updateM, 0);
    glutTimerFunc(100, updateI, 0);
	glutDisplayFunc(display1);
	glutFullScreen();
    sndPlaySound(("audio", SND_ASYNC);
    glutTimerFunc(100, update1, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update3, 0);

    glutTimerFunc(100, updateT, 0);
    glutTimerFunc(100, updateD, 0);
    glutTimerFunc(0, updatep, 0);
    glutTimerFunc(25000, meteorUp, 0);

    glutTimerFunc(100, updateA, 0);
    glutTimerFunc(100, updateP, 0);
    glutTimerFunc(30000, meteorUpp, 0);

    glutTimerFunc(100, updates, 0);
    glutTimerFunc(100, updates1, 0);
    glutTimerFunc(45000, updates2, 0);
    glutTimerFunc(50000, updates3, 0);
    glutTimerFunc(40000, meteorUps, 0);
    glutTimerFunc(0, updatep, 0);
    glutSpecialFunc(SpecialInputs);
    glutIdleFunc(Idle);
	glutMainLoop();
	return 0;
}

