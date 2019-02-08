#include "DrawDotChara.h"

DrawDotChara::DrawDotChara()
{
}
DrawDotChara::~DrawDotChara()
{
}

void DrawDotChara::DQSlime(GLint x, GLint y) {

	//輪郭
	setRGBColor(0, 0, 0);
	cube(7 + x, 0 + y);
	cube(6 + x, 1 + y, DIR_Y, 3);
	cube(8 + x, 1 + y, DIR_Y, 3);
	cube(5 + x, 4 + y);
	cube(9 + x, 4 + y);
	cube(3 + x, 5 + y, DIR_X, 2);
	cube(10 + x, 5 + y, DIR_X, 2);
	cube(2 + x, 6 + y);
	cube(12 + x, 6 + y);
	cube(1 + x, 7 + y);
	cube(13 + x, 7 + y);
	cube(0 + x, 8 + y, DIR_Y, 4);
	cube(14 + x, 8 + y, DIR_Y, 4);
	cube(1 + x, 12 + y);
	cube(13 + x, 12 + y);
	cube(2 + x, 13 + y);
	cube(12 + x, 13 + y);
	cube(3 + x, 14 + y, DIR_X, 9);
	cube(5 + x, 9 + y);
	cube(9 + x, 9 + y);

	setRGBColor(114, 152, 255);
	cube(7 + x, 1 + y, DIR_Y, 3);
	cube(6 + x, 4 + y, DIR_X, 3);
	cube(9 + x, 5 + y);
	cube(5 + x, 6 + y);
	cube(3 + x, 7 + y, DIR_X, 2);
	cube(2 + x, 8 + y, DIR_Y, 2);
	cube(1 + x, 8 + y, DIR_Y, 4);

	//口
	setRGBColor(255, 0, 0);
	cube(4 + x, 11 + y);
	cube(10 + x, 11 + y);
	cube(5 + x, 12 + y, DIR_X, 5);

	//目と光っている部分
	setRGBColor(255, 255, 255);
	cube(8 + x, 9 + y);
	cube(9 + x, 8 + y);
	cube(9 + x, 10 + y);
	cube(10 + x, 9 + y);
	cube(5 + x, 8 + y);
	cube(6 + x, 9 + y);
	cube(4 + x, 9 + y);
	cube(5 + x, 10 + y);
	cube(2 + x, 7 + y);
	cube(3 + x, 6 + y, DIR_X, 2);
	cube(5 + x, 5 + y);

	//体の色(メイン)
	setRGBColor(35, 94, 255);
	cube(6 + x, 5 + y, DIR_X, 3);
	cube(6 + x, 6 + y, DIR_X, 6);
	cube(5 + x, 7 + y, DIR_X, 8);
	cube(2 + x, 8 + y, DIR_X | DIR_Y, 12, 5);
	cube(3 + x, 13 + y, DIR_X, 9);
}

void DrawDotChara::DQSlime(GLint x, GLint y, GLint type) {

	GLint slimeColor[4][3] = {
		{0x235EFF, 0x7298FF, 0xFF0000},
		{0xFF8119, 0xFFB74C, 0xFF0000},
		{0x9B9B9B, 0xB2B2B2, 0x000000},
		{0x47EA7E, 0x6DF79C, 0xFF0000 }
	};

	//輪郭
	setRGBColor(0, 0, 0);
	cube(7 + x, 0 + y);
	cube(6 + x, 1 + y, DIR_Y, 3);
	cube(8 + x, 1 + y, DIR_Y, 3);
	cube(5 + x, 4 + y);
	cube(9 + x, 4 + y);
	cube(3 + x, 5 + y, DIR_X, 2);
	cube(10 + x, 5 + y, DIR_X, 2);
	cube(2 + x, 6 + y);
	cube(12 + x, 6 + y);
	cube(1 + x, 7 + y);
	cube(13 + x, 7 + y);
	cube(0 + x, 8 + y, DIR_Y, 4);
	cube(14 + x, 8 + y, DIR_Y, 4);
	cube(1 + x, 12 + y);
	cube(13 + x, 12 + y);
	cube(2 + x, 13 + y);
	cube(12 + x, 13 + y);
	cube(3 + x, 14 + y, DIR_X, 9);
	cube(5 + x, 9 + y);
	cube(9 + x, 9 + y);

	//目と光っている部分
	setRGBColor(255, 255, 255);
	cube(8 + x, 9 + y);
	cube(9 + x, 8 + y);
	cube(9 + x, 10 + y);
	cube(10 + x, 9 + y);
	cube(5 + x, 8 + y);
	cube(6 + x, 9 + y);
	cube(4 + x, 9 + y);
	cube(5 + x, 10 + y);
	cube(2 + x, 7 + y);
	cube(3 + x, 6 + y, DIR_X, 2);
	cube(5 + x, 5 + y);

	//若干明るい部分
	setRGBColor(slimeColor[type][1]);
	cube(7 + x, 1 + y, DIR_Y, 3);
	cube(6 + x, 4 + y, DIR_X, 3);
	cube(9 + x, 5 + y);
	cube(5 + x, 6 + y);
	cube(3 + x, 7 + y, DIR_X, 2);
	cube(2 + x, 8 + y, DIR_Y, 2);
	cube(1 + x, 8 + y, DIR_Y, 4);

	//口
	setRGBColor(slimeColor[type][2]);
	cube(4 + x, 11 + y);
	cube(10 + x, 11 + y);
	cube(5 + x, 12 + y, DIR_X, 5);
	
	//体の色(メイン)
	setRGBColor(slimeColor[type][0]);
	cube(6 + x, 5 + y, DIR_X, 3);
	cube(6 + x, 6 + y, DIR_X, 6);
	cube(5 + x, 7 + y, DIR_X, 8);
	cube(2 + x, 8 + y, DIR_X | DIR_Y, 12, 5);
	cube(3 + x, 13 + y, DIR_X, 9);
}

void DrawDotChara::MarioJumping(GLint x, GLint y) {

	setRGBColor(0xFF0000);
	cube(5 + x, 2 + y, DIR_X, 9);
	cube(6 + x, 1 + y, DIR_X, 5);

	cube(4 + x, 15 + y, DIR_X, 4);
	cube(4 + x, 14 + y, DIR_X, 8);
	cube(5 + x, 13 + y, DIR_X, 9);
	cube(4 + x, 12 + y, DIR_X, 10);
	cube(4 + x, 11 + y, DIR_X, 2);
	cube(7 + x, 11 + y, DIR_X, 2);
	cube(10 + x, 11 + y, DIR_X, 2);
	cube(13 + x, 11 + y);
	cube(8 + x, 10 + y, DIR_X, 5);
	cube(8 + x, 9 + y);
	cube(12 + x, 9 + y);
	cube(7 + x, 8 + y);
	cube(11 + x, 8 + y);
	

	setRGBColor(0xF3D51A);
	cube(9 + x, 11 + y);
	cube(12 + x, 11 + y);

	setRGBColor(0xFFB74C);
	cube(0 + x, 10 + y, DIR_X, 2);
	cube(0 + x, 11 + y, DIR_X, 3);
	cube(1 + x, 12 + y);
	cube(5 + x, 4 + y, DIR_Y, 2);
	cube(6 + x, 7 + y, DIR_X, 7);
	cube(6 + x, 6 + y, DIR_X, 4);
	cube(8 + x, 5 + y, DIR_X, 3);
	cube(12 + x, 5 + y, DIR_X, 3);
	cube(7 + x, 4 + y, DIR_X, 3);
	cube(11 + x, 4 + y, DIR_X, 2);
	cube(8 + x, 3 + y, DIR_X, 2);
	cube(11 + x, 3 + y);
	cube(13 + x, 0 + y, DIR_X | DIR_Y, 3, 2);
	cube(14 + x, 2 + y, DIR_X, 2);

	setRGBColor(0xA09444);
	cube(1 + x, 14 + y, DIR_Y, 2);
	cube(2 + x, 13 + y, DIR_Y, 2);
	cube(3 + x, 12 + y, DIR_Y, 3);
	cube(4 + x, 13 + y);
	cube(14 + x, 11 + y, DIR_Y, 3);
	cube(15 + x, 9 + y, DIR_Y, 5);
	cube(1 + x, 9 + y);
	cube(2 + x, 8 + y, DIR_X | DIR_Y, 11, 3);
	cube(6 + x, 11 + y);
	cube(4 + x, 4 + y, DIR_X | DIR_Y, 12, 2);
	cube(4 + x, 6 + y, DIR_X, 11);
	cube(5 + x, 3 + y, DIR_X, 6);
	cube(13 + x, 3 + y, DIR_X, 3);
	cube(13 + x, 7 + y);

}

void DrawDotChara::MarioFieldBlock(GLint x, GLint y) {
	
	setRGBColor(0xFFFFFF);
	cube(0 + x, 0 + y, DIR_Y, 16);
	cube(1 + x, 0 + y, DIR_X, 9);
	cube(11 + x, 0 + y, DIR_X, 5);

	setRGBColor(0x000000);
	cube(15 + x, 1 + y, DIR_Y, 15);
	cube(10 + x, 1 + y, DIR_Y, 8);
	cube(11 + x, 6 + y, DIR_X, 5);
	cube(9 + x, 8 + y, DIR_Y, 2);
	cube(8 + x, 9 + y, DIR_Y, 2);
	cube(7 + x, 11 + y, DIR_Y, 5);
	cube(1 + x, 9 + y, DIR_X, 3);
	cube(4 + x, 10 + y, DIR_X, 4);

	setRGBColor(0xD17047);
	cube(1 + x, 1 + y, DIR_X | DIR_Y, 15);
} 

