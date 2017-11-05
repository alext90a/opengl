#include "stdafx.h"
#include "SimpleAnimation.h"

SimpleAnimation* SimpleAnimation::mInstance(nullptr);

SimpleAnimation::SimpleAnimation()
{
	mInstance = this;
}


SimpleAnimation::~SimpleAnimation()
{
}

void SimpleAnimation::run()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Simple");
	glutDisplayFunc(this->RenderSceneStatic);
	glutReshapeFunc(this->ChangeSizeStatic);
	glutTimerFunc(33, this->TimerFunctionStatic, 1);
	SetupRC();
	glutMainLoop();
}

void SimpleAnimation::ChangeSizeStatic(GLsizei w, GLsizei h)
{
	mInstance->ChangeSize(w, h);
}

void SimpleAnimation::RenderSceneStatic()
{
	mInstance->RenderScene();
}

void SimpleAnimation::TimerFunctionStatic(int value)
{
	mInstance->TimerFunction(value);
}

void SimpleAnimation::ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio;
	if (h == 0)
	{
		h = 1;
	}
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)
	{
		mWindowWidth = 100;
		mWindowHeight = 100 / aspectRatio;
		glOrtho(-100.0, 100.0, -mWindowHeight, mWindowHeight, 1.0, -1.0);
	}
	else
	{
		mWindowWidth = 100 * aspectRatio;
		mWindowHeight = 100;
		glOrtho(-mWindowWidth, mWindowWidth, -100.0, 100.0, 1.0, -1.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SimpleAnimation::RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(mX, mY, mX + mSize, mY - mSize);
	glutSwapBuffers();
}

void SimpleAnimation::TimerFunction(int value)
{
	if (mX > mWindowWidth - mSize || mX < -mWindowWidth)
		mXStep = -mXStep;

	if (mY > mWindowHeight || mY < -mWindowHeight + mSize)
		mYStep = -mYStep;

	mX += mXStep;
	mY += mYStep;

	if (mX >(mWindowWidth - mSize + mXStep))
		mX = mWindowWidth - mSize - 1;
	else if (mX < -(mWindowWidth + mXStep))
		mX = -mWindowWidth - 1;

	if (mY >(mWindowHeight + mYStep))
		mY = mWindowHeight - 1;
	else if (mY < -(mWindowHeight - mSize + mYStep))
		mY = -mWindowHeight + mSize - 1;

	glutPostRedisplay();
	glutTimerFunc(33, this->TimerFunctionStatic, 33);

}

void SimpleAnimation::SetupRC()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}


