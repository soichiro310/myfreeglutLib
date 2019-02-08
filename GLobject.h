#pragma once
#include <GL/glut.h>

class GLobject
{
private:
	#define SQ_SIZE 0.5
public:
	GLobject();
	~GLobject();

	void plane(GLdouble w, GLdouble d);
	void checkerboard(GLint w, GLint d);
	void cube(GLint x, GLint y, GLint cubeWidth, GLint cubeDepth, GLint cubeHeight);
	void pyramid(GLint x, GLint y, GLint cubeWidth, GLint cubeDepth, GLint cubeHeight);
};

