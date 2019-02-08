#pragma once
#include "GLobject.h"
#include "GLdefineColor.h"
class GLScenery : protected GLobject, protected GLdefineColor
{
public:
	enum ROAD_TYPE : GLint 
		{ STRAIGHT_X, STRAIGHT_Y, CURVE_LEFT, CURVE_RIGHT, CROSSROAD };
	enum SHOP : GLint
		{ CAKE, SOBA};
	enum TREE : GLint 
		{ NORMAL, SAKURA, MOMIJI};

public:
	GLScenery();
	~GLScenery();

	void tree(GLint x, GLint y, GLint type); 
	void house(GLint x, GLint y);
	void road(GLint x, GLint y, GLint type);
	void basefield(GLdouble size);
	void office(GLint x, GLint y);
	void post(GLint x, GLint y);
	void shop(GLint x, GLint y, GLint type);
};

