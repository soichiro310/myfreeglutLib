#include "GLsetColor.h"


GLsetColor::GLsetColor()
{
}

GLsetColor::GLsetColor(GLint colorHex) {
	GLint _R = (colorHex & 0xff0000) >> 16;
	GLint _G = (colorHex & 0x00ff00) >> 8;
	GLint _B = (colorHex & 0x0000ff);
	glColor3d((GLdouble)_R / 255.0, (GLdouble)_G / 255.0, (GLdouble)_B / 255.0);

}

GLsetColor::GLsetColor(GLint _R, GLint _G, GLint _B) {
	glColor3d((GLdouble)_R / 255.0, (GLdouble)_G / 255.0, (GLdouble)_B / 255.0);
}


GLsetColor::~GLsetColor()
{
}

//16進数の値から色を設定する関数
void GLsetColor::setRGBColor(GLint colorHex) {
	GLint _R = (colorHex & 0xff0000) >> 16;
	GLint _G = (colorHex & 0x00ff00) >> 8;
	GLint _B = (colorHex & 0x0000ff);
	glColor3d((GLdouble)_R / 255.0, (GLdouble)_G / 255.0, (GLdouble)_B / 255.0);
}

//10進数のR,G,Bの値から色を設定する関数
void GLsetColor::setRGBColor(GLint _R, GLint _G, GLint _B) {
	glColor3d((GLdouble)_R / 255.0, (GLdouble)_G / 255.0, (GLdouble)_B / 255.0);
}

//HSV色空間から色を設定する関数
void GLsetColor::setHSVColor(GLint _H, GLint _S, GLint _V) {
	GLint hsvmax = _V;
	GLint hsvmin = (GLint)((GLdouble)hsvmax * (1.0 - ((GLdouble)_S / 255.0)));
	GLint hsvrange = hsvmax - hsvmin;

	if (_H >= 0 && _H < 60)
		setRGBColor(hsvmax, (GLint)((GLdouble)_H / 60.0 * (GLdouble)hsvrange + (GLdouble)hsvmin), hsvmin);
	else if (_H < 120)
		setRGBColor((GLint)((120.0 - (GLdouble)_H) / 60.0 * (GLdouble)hsvrange + (GLdouble)hsvmin), hsvmax, hsvmin);
	else if (_H < 180)
		setRGBColor(hsvmin, hsvmax, (GLint)(((GLdouble)_H - 120.0) / 60.0 * (GLdouble)hsvrange + (GLdouble)hsvmin));
	else if (_H < 240)
		setRGBColor(hsvmin, (GLint)((240.0 - (GLdouble)_H) / 60.0 * (GLdouble)hsvrange + (GLdouble)hsvmin), hsvmax);
	else if (_H < 300)
		setRGBColor((GLint)(((GLdouble)_H - 240.0) / 60.0 * (GLdouble)hsvrange + (GLdouble)hsvmin), hsvmin, hsvmax);
	else if (_H < 360)
		setRGBColor(hsvmax, hsvmin, (GLint)((360.0 - (GLdouble)_H) / 60.0 * (GLdouble)hsvrange + (GLdouble)hsvmin));

}



