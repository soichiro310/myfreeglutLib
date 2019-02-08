#pragma once
#include <GL/glut.h>

class GLsetColor
{
public:
	GLsetColor();
	GLsetColor(GLint colorHex);
	GLsetColor(GLint _R, GLint _G, GLint _B);
	~GLsetColor();

	//glutの色の設定の仕方がややこしいので任意のパラメータを与えれば色を設定してくれる関数を作成した。
	void setRGBColor(GLint colorHex);
	void setRGBColor(GLint _R, GLint _G, GLint _B);
	void setHSVColor(GLint _H, GLint _S, GLint _V);
};

