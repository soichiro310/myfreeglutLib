#include "GLScenery.h"

GLScenery::GLScenery()
{
}


GLScenery::~GLScenery()
{
}

//木のオブジェクト
void GLScenery::tree(GLint x, GLint y, GLint type) {
	
	GLdefineColor color;
	glPushMatrix();
	glTranslated(0.0, 1.5, 0.0);

	switch (type){
	case TREE::NORMAL:
		color.green();
		break;
	case TREE::SAKURA:
		color.setRGBColor(0xF2D8DF);
		break;
	case TREE::MOMIJI:
		color.setRGBColor(0xFF4F19);
		break;
	default:
		break;
	}

	pyramid(x, y, 3, 3, 4);
	glPopMatrix();
	color.maroon();
	cube(x + 1, y + 1, 1, 1, 3);
}

//家のオブジェクト
void GLScenery::house(GLint x, GLint y) {
	GLdefineColor color;
	glPushMatrix();
	glTranslated(0.0, 1.5, 0.0);
	color.blue();
	pyramid(x, y, 5, 5, 3);
	glPopMatrix();
	color.setRGBColor(0xE7E8E2);
	cube(x + 1, y + 1, 4, 4, 3);

}

//道路のオブジェクト
void GLScenery::road(GLint x, GLint y, GLint type) {
	GLdefineColor color;

	switch (type){
	
	case ROAD_TYPE::STRAIGHT_X:
		glPushMatrix();
		glTranslated((x + 2)* SQ_SIZE, 0.01, (y + 3.5) * SQ_SIZE);
		color.white();
		plane(SQ_SIZE * 2.5, SQ_SIZE * 0.5);
		glPopMatrix();

		glPushMatrix();
		glTranslated((x + 6)* SQ_SIZE, 0.01, (y + 3.5) * SQ_SIZE);
		color.white();
		plane(SQ_SIZE * 2.5, SQ_SIZE * 0.5);
		glPopMatrix();
		break;

	case ROAD_TYPE::STRAIGHT_Y:
		glPushMatrix();
		glTranslated((x + 3.5)* SQ_SIZE, 0.01, (y + 2) * SQ_SIZE);
		color.white();
		plane(SQ_SIZE * 0.5, SQ_SIZE * 2.5);
		glPopMatrix();

		glPushMatrix();
		glTranslated((x + 3.5)* SQ_SIZE, 0.01, (y + 6) * SQ_SIZE);
		color.white();
		plane(SQ_SIZE * 0.5, SQ_SIZE * 2.5);
		glPopMatrix();
		break;

	case ROAD_TYPE::CURVE_LEFT:
		glPushMatrix();
		glTranslated((x + 3.5)* SQ_SIZE, 0.01, (y + 2.5) * SQ_SIZE);
		color.white();
		plane(SQ_SIZE * 0.5, SQ_SIZE * 2.5);
		glPopMatrix();

		glPushMatrix();
		glTranslated((x + 2.5)* SQ_SIZE, 0.01, (y + 3.5) * SQ_SIZE);
		color.white();
		plane(SQ_SIZE * 2.5, SQ_SIZE * 0.5);
		glPopMatrix();
		break;

	case ROAD_TYPE::CURVE_RIGHT:
		glPushMatrix();
		glTranslated((x + 3.5)* SQ_SIZE, 0.01, (y + 5.0) * SQ_SIZE);
		color.white();
		plane(SQ_SIZE * 0.5, SQ_SIZE * 2.5);
		glPopMatrix();

		glPushMatrix();
		glTranslated((x + 2.5)* SQ_SIZE, 0.01, (y + 3.5) * SQ_SIZE);
		color.white();
		plane(SQ_SIZE * 2.5, SQ_SIZE * 0.5);
		glPopMatrix();
		break;

	case ROAD_TYPE::CROSSROAD:
		glPushMatrix();
		glTranslated((x + 3.5)* SQ_SIZE, 0.01, (y + 3.5) * SQ_SIZE);
		color.white();
		plane(SQ_SIZE * 0.5, SQ_SIZE * 4.5);
		plane(SQ_SIZE * 4.5, SQ_SIZE * 0.5);
		glPopMatrix();
		break;

		default:
			break;
	}

	glPushMatrix();
	glTranslated((x + 3.5)* SQ_SIZE, 0, (y + 3.5) * SQ_SIZE);
	color.silver();
	plane(SQ_SIZE * 8, SQ_SIZE * 8);
	glPopMatrix();
}

//レゴの基礎版的な何か
void GLScenery::basefield(GLdouble size) {
	GLdefineColor color;
	glPushMatrix();
	glTranslated(size * 0.5, -0.01, size * 0.5);
	color.green();
	plane(size, size);
	glPopMatrix();
}


void GLScenery::office(GLint x, GLint y) {
	GLdefineColor color;
	
	glPushMatrix();
	glTranslated((x + 3.5) * SQ_SIZE, 1.5, (y + 7.51) * SQ_SIZE);
	glRotated(90.0, 1.0, 0, 0);
	color.setRGBColor(168, 209, 227);
	plane(SQ_SIZE * 6, SQ_SIZE * 5);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated((x + 9) * SQ_SIZE, 1.75, (y + 7.51) * SQ_SIZE);
	glRotated(90.0, 1.0, 0, 0);
	color.setRGBColor(168, 209, 227);
	plane(SQ_SIZE * 2.5, SQ_SIZE * 4);
	glPopMatrix();

	glPushMatrix();
	glTranslated((x + 13) * SQ_SIZE, 1.75, (y + 7.51) * SQ_SIZE);
	glRotated(90.0, 1.0, 0, 0);
	color.setRGBColor(168, 209, 227);
	plane(SQ_SIZE * 2.5, SQ_SIZE * 4);
	glPopMatrix();

	glPushMatrix();
	glTranslated((x + 7.5) * SQ_SIZE, 3.75, (y + 7.51) * SQ_SIZE);
	glRotated(90.0, 1.0, 0, 0);
	color.setRGBColor(0xFF5E19);
	plane(SQ_SIZE * 15, SQ_SIZE * 2);
	glPopMatrix();

	glPushMatrix();
	color.setRGBColor(0xDDDED3);
	cube(x, y, 16, 8, 10);
	glPopMatrix();
	
}

void GLScenery::post(GLint x, GLint y) {
	GLdefineColor color;
	glPushMatrix();
	glTranslated(0.0, SQ_SIZE, 0.0);
	color.red();
	cube(x, y, 2, 2, 3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(SQ_SIZE / 2, 0.0, SQ_SIZE / 2);
	color.maroon();
	cube(x, y, 1, 1, 1); 
	glPopMatrix();
}

void GLScenery::shop(GLint x, GLint y, GLint type) {
	GLdefineColor color;
	
	switch (type){
	case SHOP::CAKE:
		glPushMatrix();
		glTranslated(0.0, 1.5, 0.0);
		color.setRGBColor(0xE0C184);
		pyramid(x, y, 7, 7, 3);
		glPopMatrix();
		color.setRGBColor(0xE7E18F);
		cube(x + 1, y + 1, 6, 6, 3);
		break;

	case SHOP::SOBA:
		glPushMatrix();
		glTranslated(0.0, 1.5, 0.0);
		color.black();
		pyramid(x, y, 7, 7, 3);
		glPopMatrix();
		color.white();
		cube(x + 1, y + 1, 6, 6, 3);
		break;

	default:
		break;
	}
}