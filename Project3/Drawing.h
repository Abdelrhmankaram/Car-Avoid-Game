#pragma once
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include "Variables.h"
#include "Lighting.h"
#include "Settings.h"
#include "Collision.h"

using namespace std;

void gamercar()
{
	glPushMatrix();
	glTranslatef(xp, -1.0, 3.5);

	glPushMatrix();
	glRotatef(-10, -1.0, 0.0, 0.0);
	glScalef(1.3, 0.8, 2.0);
	glColor3f(0, 0.5, 1);
	glutSolidCube(.3); // car's body
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, tpx, 0.0);
	glRotatef(-10, -1.0, 0.0, 0.0);
	glScalef(1.0, .5, .5);
	glColor3f(0, 0, 0); // car's roof
	glutSolidCube(.2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.21, -0.12, 0.10);
	glRotatef(80, 0.0, 1.2, 0.0);
	glScalef(.07, .14, .07);
	glColor3f(1, 0, 0);
	glutWireTorus(.2, .4, 20, 15); // lower right wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.21, 0.0, -0.2);
	glRotatef(80, 0.0, 1.2, 0.0);
	glScalef(.07, .14, .07);
	glColor3f(1, 0, 0);
	glutWireTorus(.2, .4, 20, 15); // upper right wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.21, -0.12, 0.10);
	glRotatef(80, 0.0, 1.2, 0.0);
	glScalef(.07, .14, .07);
	glColor3f(1, 0, 0);
	glutWireTorus(.2, .4, 20, 15); // lower left wheel
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.21, 0.0, -0.2);
	glRotatef(80, 0.0, 1.2, 0.0);
	glScalef(.07, .14, .07);
	glColor3f(1, 0, 0);
	glutWireTorus(.2, .4, 20, 15); // upper left wheel
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-0.10, -0.10, 0.30); // left backlight
	glRotatef(80, 0.0, 1.2, 0.0);
	glScalef(.07, .03, .07);
	glColor3f(1, .5, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.10, -0.10, 0.30); // right backlight
	glRotatef(80, 0.0, 1.2, 0.0);
	glScalef(.07, .03, .07);
	glColor3f(1, .5, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

}

void sky()
{
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);

	glColor3ub(0, 0, 1);
	glVertex3f(-4.0, 1.5, 0);
	glVertex3f(4.0, 1.5, 0);
	glVertex3f(8.0, 3, 0);
	glVertex3f(-8.0, 3, 0);
	glEnd();
}


void roadside()
{
	// tree
	for (float z = -38; z < 400; z += 4)
	{
		glPushMatrix();
		glColor3ub(200, 200, 200);
		glTranslatef(-1.20, z, .40);
		glScalef(.2, .2, 3);
		glutSolidCube(.4); // horizontal shape
		glPopMatrix();

		glPushMatrix();
		glColor3ub(200, 200, 200);
		glTranslatef(-.84, z, 1.0);
		glScalef(2, .2, .2);
		glutSolidCube(.4); // vertical shape
		glPopMatrix();

		glPushMatrix();
		glColor3ub(255, 255, 255);
		glTranslatef(-.44, z, 0.70);
		//glScalef(2, .2, .2);
		glutSolidCone(.2, .3, 15, 20); // light cone
		glPopMatrix();

	}

	glBegin(GL_QUADS);
	glColor3ub(0, 155, 20); // left side road
	glVertex3f(-5.0, -10, 0);
	glVertex3f(-1.0, -10, 0);
	glVertex3f(-1.0, 400, 0);
	glVertex3f(-5.0, 400, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0, 155, 20); // right side road
	glVertex3f(1.0, -10, 0);
	glVertex3f(5.0, -10, 0);
	glVertex3f(5.0, 400, 0);
	glVertex3f(1.0, 400, 0);
	glEnd();

}

void objectcube()
{
	// draw cubes with pattern -> R L L R
	for (float zp = -20; zp < 400; zp += 40)
	{
		glPushMatrix();
		glColor3f(0, 0.5, 0);
		glTranslatef(-.50, zp, -.1);
		glutSolidCube(.4);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0.5, 0);
		glTranslatef(.50, zp + 10, -.1);
		glutSolidCube(.4);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0.5, 0);
		glTranslatef(.50, zp + 20, -.1);
		glutSolidCube(.4);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0, 0.5, 0);
		glTranslatef(-.50, zp + 30, -.1);
		glutSolidCube(.4);
		glPopMatrix();

	}
}


void road() {
	for (float z = -10; z < 400; z += 1)
	{
		glPushMatrix();
		glColor3f(1, 1, 1);
		glBegin(GL_QUADS);

		glVertex3f(-.03, z, 0);
		glVertex3f(.03, z, 0);
		glVertex3f(.03, z + .5, 0);
		glVertex3f(-.03, z + .5, 0);
		glEnd();
		glPopMatrix();

	}

	glPushMatrix();

	glColor3ub(0, 0, 0);

	glTranslatef(0.0, 0.0, -.50);
	glBegin(GL_QUADS);
	glVertex3f(-1.3, -10, 0);
	glVertex3f(1.3, -10, 0);
	glVertex3f(1.3, 400, 0);
	glVertex3f(-1.3, 400, 0);
	glEnd();

	glPopMatrix();

}

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 7 units
	
	gamercar(); // draw the car

	setupLighting();

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0.0, 0.0, 0.0); //Move to the center of the triangle
	glRotatef(80, -1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(0.0, crmove, 0.0);

	glClearColor(0.0, 0.0, 0.0, 1.0);

	road();
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, crmove, 0.0);


	roadside();

	objectcube();

	GameScore();

	glPopMatrix();

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glTranslatef(5.52, 0.0, 2.0);

	ostringstream cnvrt;
	cnvrt << score; // Total Score
	sprint(-4, -2.3, "Score: " + cnvrt.str());
	glPopMatrix();

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glTranslatef(5.5, 0.0, 1.8);

	ostringstream cnvrt2;
	cnvrt2 << totalMeter; // Total distance traveled
	sprint(-4, -2.4, "Distance Travel: " + cnvrt2.str());
	glPopMatrix();

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glTranslatef(5.5, 0.0, 1.6);
	ostringstream cnvrt3;
	cnvrt3 << carspeed; // Car Speed
	sprint(-4, -2.4, "Speed: " + cnvrt3.str());
	glPopMatrix();

	glPopMatrix();
	glClearColor(sky_red, sky_green, sky_blue, 1.0);

	if (collision())
	{
		winner('a');
	}

	glutSwapBuffers();
}