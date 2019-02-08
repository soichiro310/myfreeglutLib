#include "GLobject.h"
#include <GL/glut.h>
#include <math.h>


GLobject::GLobject()
{
}

GLobject::~GLobject()
{
}


//X-Z���ʏ�ɕ�w, ����d�̕��ʂ������֐�
void GLobject::plane(GLdouble w, GLdouble d)
{
	GLdouble norm[3];
	glPushMatrix();//�S�̂̐��E�ɉe����^���Ȃ����߂ɍs����悯�Ă���
	glBegin(GL_POLYGON);//���p�`��`�悷�邽�߂̒��_���X�g����ׂ܂���
	norm[0] = 1; norm[1] = 0; norm[2] = 0;//�ʂ̌����x�N�g���i�@���j�̌���
	glNormal3dv(norm);//�@���x�N�g�����w��
	glVertex3d(w / 2.0, 0, d / 2.0);//�E���ɒ��_�����߂Ă����F1�_��
	glVertex3d(w / 2.0, 0, -d / 2.0);//�E���ɒ��_�����߂Ă����F2�_��
	glVertex3d(-w / 2.0, 0, -d / 2.0);//�E���ɒ��_�����߂Ă����F3�_��
	glVertex3d(-w / 2.0, 0, d / 2.0);//�E���ɒ��_�����߂Ă����F4�_��
	glEnd();//�����Œ��_���X�g�͏I���ł���
	glPopMatrix();//�s������ɖ߂�
}

//x-Z���ʏ�ɕ�w, ����d�̃`�F�b�J�[�{�[�h�������֐�
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

//(x,y)�̈ʒu�ɑ傫�����w�肵�ăL���[�u��z�u����֐�
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

//(x,y)�̈ʒu�ɑ傫�����w�肵�ăL���[�u��z�u����֐�
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