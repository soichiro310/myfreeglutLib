#include "GLobject.h"
#include "GLdefineColor.h"

class DrawDotChara : private GLobject, private GLsetColor
{

public:
	enum SlimeType {SLIME, BETH, METAL, KNIGHT};

public:
	DrawDotChara();
	~DrawDotChara();

	void DQSlime(GLint x, GLint y);
	void DQSlime(GLint x, GLint y, GLint type);
	void MarioJumping(GLint x, GLint y);
	void MarioFieldBlock(GLint x, GLint y);
};
