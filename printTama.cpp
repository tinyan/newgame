#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nyanlib\include\areaControl.h"
#include "..\..\systemNNN\nyanlib\include\picture.h"
#include "..\..\systemNNN\nyanlib\include\allGeo.h"

#include "tama.h"
#include "printTama.h"


CPrintTama::CPrintTama()
{
	m_pic = new CPicture("sys\\ta_tama");
}

CPrintTama::~CPrintTama()
{
	End();
}

void CPrintTama::End(void)
{
	ENDDELETECLASS(m_pic);
}


void CPrintTama::PutTama(int x,int y,int type,int angle)
{
	int sizeX = 64;
	int sizeY = 64;

	int srcX = (angle + 16) / 32;
	srcX += 8;
	srcX %= 8;
	srcX *= sizeX;
	int srcY = type;
	srcY *= sizeY;
	int putX = x - sizeX / 2;
	int putY = y - sizeY / 2;

	m_pic->Blt(putX,putY,srcX,srcY,sizeX,sizeY,TRUE);

}

void CPrintTama::PrintAll(CTama* tama)
{
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
			int laser = work->laser;

			if ((laser & 1)== 0)
			{
				PutTama(x,y,picType,angle);
			}
			else
			{
				SIZE sz = work->hitSize;
				int sizeX = sz.cx;
				int sizeY = sz.cy;
				int r = 255;
				int g = 255;
				int b = 64;
				CAllGeo::BoxFill(x-sizeX/2,y-sizeY/2,sizeX,sizeY,r,g,b);
			}
		}
	}
}


/*_*/

