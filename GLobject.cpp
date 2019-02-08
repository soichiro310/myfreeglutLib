#include "GLobject.h"
#include <GL/glut.h>
#include <math.h>


GLobject::GLobject()
{
}

GLobject::~GLobject()
{
}


//X-Z平面上に幅w, 高さdの平面を書く関数
void GLobject::plane(GLdouble w, GLdouble d)
{
	GLdouble norm[3];
	glPushMatrix();//全体の世界に影響を与えないために行列をよけておく
	glBegin(GL_POLYGON);//多角形を描画するための頂点リストを並べますよ
	norm[0] = 1; norm[1] = 0; norm[2] = 0;//面の向きベクトル（法線）の決定
	glNormal3dv(norm);//法線ベクトルを指定
	glVertex3d(w / 2.0, 0, d / 2.0);//右回りに頂点を決めていく：1点目
	glVertex3d(w / 2.0, 0, -d / 2.0);//右回りに頂点を決めていく：2点目
	glVertex3d(-w / 2.0, 0, -d / 2.0);//右回りに頂点を決めていく：3点目
	glVertex3d(-w / 2.0, 0, d / 2.0);//右回りに頂点を決めていく：4点目
	glEnd();//ここで頂点リストは終わりですよ
	glPopMatrix();//行列を元に戻す
}

//x-Z平面上に幅w, 高さdのチェッカーボードを書く関数
void GLobject::checkerboard(GLint w, GLint d) {

	GLfloat color[][4] = {
		{ 0.4, 0.4, 0.4, 1.0 },
		{ 1, 1, 1, 1.0 },
	};

	int bWB = 0;
	double i, j;
	for (i = 0; i < w; i++) {
		for (j = 0; j < d; j++) {
			glPushMatrix();
			if (bWB) {
				glColor3fv(color[0]);
			}
			else {
				glColor3fv(color[1]);
			}
			glTranslated(i * SQ_SIZE, 0, j * SQ_SIZE);
			plane(SQ_SIZE, SQ_SIZE);
			glPopMatrix();
			bWB = !bWB;

		}
		if((w * d) % 2 == 0)
		bWB = (int)(fabs(bWB - 1));
	}
}

//(x,y)の位置に大きさを指定してキューブを配置する関数
void GLobject::cube(GLint x, GLint y, GLint cubeWidth, GLint cubeDepth, GLint cubeHeight) {

	GLdouble vertex[][3] = {
		{ -SQ_SIZE                      ,                  0.0, -SQ_SIZE                       },
		{  SQ_SIZE * (cubeWidth * 2 - 1),                  0.0, -SQ_SIZE                       },
		{  SQ_SIZE * (cubeWidth * 2 - 1), SQ_SIZE * cubeHeight, -SQ_SIZE                       },
		{ -SQ_SIZE                      , SQ_SIZE * cubeHeight, -SQ_SIZE                       },
		{ -SQ_SIZE                      ,                  0.0,  SQ_SIZE * (cubeDepth * 2 - 1) },
		{  SQ_SIZE * (cubeWidth * 2 - 1),                  0.0,  SQ_SIZE * (cubeDepth * 2 - 1) },
		{  SQ_SIZE * (cubeWidth * 2 - 1), SQ_SIZE * cubeHeight,  SQ_SIZE * (cubeDepth * 2 - 1) },
		{ -SQ_SIZE                      , SQ_SIZE * cubeHeight,  SQ_SIZE * (cubeDepth * 2 - 1) }
	};

	int face[][4] = {
		{ 0, 1, 2, 3 },
		{ 1, 5, 6, 2 },
		{ 5, 4, 7, 6 },
		{ 4, 0, 3, 7 },
		{ 4, 5, 1, 0 },
		{ 3, 2, 6, 7 }
	};
	GLdouble normal[][3] = {
		{      0.0,      0.0, -SQ_SIZE * cubeDepth },
		{  SQ_SIZE * cubeWidth,      0.0,      0.0 },
		{      0.0,      0.0,  SQ_SIZE * cubeDepth},
		{ -SQ_SIZE * cubeWidth,      0.0,      0.0 },
		{      0.0, -SQ_SIZE * cubeHeight,      0.0 },
		{      0.0,  SQ_SIZE * cubeHeight,      0.0 }
	};

	glBegin(GL_QUADS);
	for (int j = 0; j < 6; j++) {
		glNormal3dv(normal[j]);
		for (int i = 0; i < 4; i++) {
			glVertex3d((vertex[face[j][i]][0] + x) * SQ_SIZE,
				vertex[face[j][i]][1],
				(vertex[face[j][i]][2] + y) * SQ_SIZE);
		}
	}
	glEnd();
}

//(x,y)の位置に大きさを指定してキューブを配置する関数
void GLobject::pyramid(GLint x, GLint y, GLint width, GLint depth, GLint height) {
	
	GLdouble vertex[][3] = {
		{      0.0,      SQ_SIZE * height, 0.0 },
		{ -SQ_SIZE,                   0.0, -SQ_SIZE },
		{  SQ_SIZE * (width * 2 - 1), 0.0, -SQ_SIZE },
		{  SQ_SIZE * (width * 2 - 1), 0.0, SQ_SIZE * (depth * 2 - 1) },
		{ -SQ_SIZE,                   0.0, SQ_SIZE * (depth * 2 - 1) },
	};
	int face[][4] = {
		{ 0, 1, 2, 0 },
		{ 0, 2, 3, 0 },
		{ 0, 3, 4, 0 },
		{ 0, 4, 1, 0 },
		{ 1, 4, 3, 2 },
	};

	GLdouble normal[][3] = {
		{              0.0, SQ_SIZE * height, -SQ_SIZE * depth },
		{  SQ_SIZE * width, SQ_SIZE * height,              0.0 },
		{              0.0, SQ_SIZE * height,  SQ_SIZE * depth },
		{ -SQ_SIZE * width, SQ_SIZE * height,              0.0 },
	};

	int i, j;

	glBegin(GL_TRIANGLES);
	for (j = 0; j < 4; j++) {
		glNormal3dv(normal[j]);
		for (i = 0; i < 3; i++) {
			glVertex3d((vertex[face[j][i]][0] + x) * SQ_SIZE,
				vertex[face[j][i]][1],
				(vertex[face[j][i]][2] + y) * SQ_SIZE);
		}
	}
	glEnd();
	glBegin(GL_QUADS);
	glNormal3d(0.0, -SQ_SIZE * height, 0.0);
	for (i = 0; i < 4; i++) {
		glVertex3d((vertex[face[j][i]][0] + x) * SQ_SIZE,
			vertex[face[j][i]][1],
			(vertex[face[j][i]][0] + y) * SQ_SIZE);
	}
	glEnd();
	
}