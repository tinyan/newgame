#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nyanlib\include\areaControl.h"
#include "..\..\systemNNN\nyanlib\include\picture.h"

#include "powerup.h"
#include "printPowerup.h"


CPrintPowerup::CPrintPowerup()
{
	m_pic = new CPicture("sys\\ta_powerup");
}

CPrintPowerup::~CPrintPowerup()
{
	End();
}

void CPrintPowerup::End(void)
{
	ENDDELETECLASS(m_pic);
}



void CPrintPowerup::PrintAll(CPowerup* powerup)
{
	int select = powerup->GetType();
	int putX = 8;
	int putY = 8;
	int nextX = 70;
	int nextY = 36;
	int sizeX = 64;
	int sizeY = 32;

	for (int i=0;i<4;i++)
	{
		int level = powerup->GetLevel(i);
		for (int j=0;j<=level;j++)
		{
			int x = putX + i * nextX;
			int y = putY + j * nextY;
			int srcX = 0;
			if (i == select) srcX += sizeX;
			int srcY = i * sizeY;
			m_pic->Blt(x,y,srcX,srcY,sizeX,sizeY,TRUE);
		}
	}

	/*
	int loop = tama->GetTamaMax();
	for (int i=0;i<loop;i++)
	{
		TAMA* work = tama->GetTama(i);
		if (work->flag)
		{
			int picType = work->picType;
			int x = work->x;
			int y = work->y;
			int angle = work->angle;
			PutTama(x,y,picType,angle);
		}
	}
	*/
}


/*_*/

