#pragma once
#include <GL/glut.h>

class GLsetColor
{
public:
	GLsetColor();
	GLsetColor(GLint colorHex);
	GLsetColor(GLint _R, GLint _G, GLint _B);
	~GLsetColor();

	//glut�̐F�̐ݒ�̎d������₱�����̂ŔC�ӂ̃p�����[�^��^����ΐF��ݒ肵�Ă����֐����쐬�����B
	void setRGBColor(GLint colorHex);
	void setRGBColor(GLint _R, GLint _G, GLint _B);
	void setHSVColor(GLint _H, GLint _S, GLint _V);
};

