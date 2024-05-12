#define STB_IMAGE_IMPLEMENTATION
#define glGenerateMipmaps ;
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/stb_image.h>

#include "Reshape.h"
#include "Controls.h"
#include "Variables.h"
#include "Drawing.h"
#include "Display.h"

using namespace std;

void load(int num) {
	if (num == 1) {
		imgData = stbi_load("C:\\Users\\bodyk\\Downloads\\clear_sky_2d_bmp_graphics__pattern_texture_material__graphics_23446.jpg", &width, &height, &nrChannels, 0);
		checkImg(imgData);
	}
	if (num == 2) {
		imgData = stbi_load("C:\\Users\\bodyk\\Downloads\\green-grass-field-background.jpg", &width, &height, &nrChannels, 0);
		checkImg(imgData);
	}
}

void checkImg(unsigned char* imageData) {
	if (imageData) {
		
		glGenTextures(1, &texture);//the first Argument is the number of texture namees to generate ,second will hold the generated texture name 
		glBindTexture(GL_TEXTURE_2D, texture);//mapping the photo to 0 1 
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);//x-axis repeat the print of the photo
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);//y-axis
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//امتداد 
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);// تصغيره او تكبيره على الشاشة 
	}
	else {
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(imageData);
}

void update(int value) {
	crmove -= 0.1f;

	// Check if total meter reaches 4000
	if (totalMeter >= 4000) {
		win('a'); // End the game
		return;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(crspeed, update, 0);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(100, 100);
	
	glutCreateWindow("Car Game");
	initRendering();

	//Set handler functions

	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardspecial);
	glutMouseFunc(mouseClick);
	glutFullScreen();
	glutMainLoop();
	return 0;
}