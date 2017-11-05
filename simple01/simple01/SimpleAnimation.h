#pragma once
#include <string>
#include <glut.h>
#include <iostream>
#include "IBaseStarter.h"

class SimpleAnimation : public IBaseStarter
{
public:
	SimpleAnimation();
	~SimpleAnimation();
	void run()override;

	
protected:
	static void ChangeSizeStatic(GLsizei w, GLsizei h);
	static void RenderSceneStatic();
	static void TimerFunctionStatic(int value);
	static SimpleAnimation* mInstance;

protected:
	void TimerFunction(int value);
	void ChangeSize(GLsizei w, GLsizei h);
	void RenderScene();
	
	void SetupRC();

protected:
	float mX = 0.0f;
	float mY = 0.0f;
	GLfloat mSize = 25.0f;

	GLfloat mXStep = 1.0f; GLfloat mYStep = 1.0f;

	GLfloat mWindowWidth; GLfloat mWindowHeight;
};

