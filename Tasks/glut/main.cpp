#include "freeglut_std.h"

void draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void Initialize() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char** argv) {
	// Инициализация
	glutInit(&argc, argv);
	glutinitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutinitWindowPosition(100, 200);
	glutCreateWindow("Lesson 01");
	// регистрация
	glutDisplayFunc(Draw);
	Initialize();
	glutMainLoop();
	return 0;
}
