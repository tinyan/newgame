#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nyanlib\include\areaControl.h"
#include "..\..\systemNNN\nyanlib\include\picture.h"

#include "printStage.h"

CPrintStage::CPrintStage()
{
	m_pic = new CPicture("sys\\ta_stage");
}

CPrintStage::~CPrintStage()
{
	End();
}

void CPrintStage::End(void)
{
	ENDDELETECLASS(m_pic);
}


void CPrintStage::Print(int stage,int x,int y)
{
	stage %= 100;
	stage += 1;

	int data50 = stage / 50;
	stage -= data50 * 50;
	int data10 = stage / 10;
	stage -= data10 * 10;
	int data5 = stage / 5;
	stage -= data5 * 5;
	int data1 = stage;

	int putX = x;
	int putY = y;


	for (int i=0;i<data50;i++)
	{
		int srcX = 0;
		int srcY = 0;
		int sizeX = 64;
		int sizeY = 64;

		m_pic->Blt(putX,putY,srcX,srcY,sizeX,sizeY,TRUE);

		putX += sizeX;
	}

	for (int i=0;i<data10;i++)
	{
		int srcX = 64;
		int srcY = 0;
		int sizeX = 48;
		int sizeY = 64;

		m_pic->Blt(putX,putY,srcX,srcY,sizeX,sizeY,TRUE);

		putX += sizeX;
	}

	for (int i=0;i<data5;i++)
	{
		int srcX = 0;
		int srcY = 64;
		int sizeX = 32;
		int sizeY = 64;

		m_pic->Blt(putX,putY,srcX,srcY,sizeX,sizeY,TRUE);

		putX += sizeX;
	}

	for (int i=0;i<data1;i++)
	{
		int srcX = 64;
		int srcY = 64;
		int sizeX = 16;
		int sizeY = 64;

		m_pic->Blt(putX,putY,srcX,srcY,sizeX,sizeY,TRUE);

		putX += sizeX;
	}
}

