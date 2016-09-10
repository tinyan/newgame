#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nyanlib\include\areaControl.h"
#include "..\..\systemNNN\nyanlib\include\picture.h"

#include "effect.h"
#include "printEffect.h"


CPrintEffect::CPrintEffect()
{
	m_pic = new CPicture("sys\\ta_effect");
}


CPrintEffect::~CPrintEffect()
{
	End();
}

void CPrintEffect::End(void)
{
	ENDDELETECLASS(m_pic);
}

void CPrintEffect::PrintAll(CMyEffect* effect)
{
	int loop = effect->GetEffectMax();
	for (int i=0;i<loop;i++)
	{
		MYEFFECT* work = effect->GetEffect(i);
		if (work->flag)
		{
			int type = work->type;
			int x = work->x;
			int y = work->y;
			int anime = work->count / 2;
			if ((anime >= 0) && (anime < 8))
			{
				PutEffect(x,y,type,anime);
			}
		}
	}
}

void CPrintEffect::PutEffect(int x,int y,int type,int anime)
{
	int sizeX = 64;
	int sizeY = 64;

	int srcX = anime % 4;
	int srcY = anime / 4;
	srcX *= sizeX;
	srcY *= sizeY;
	int putX = x - sizeX / 2;
	int putY = y - sizeY / 2;

	m_pic->Blt(putX,putY,srcX,srcY,sizeX,sizeY,TRUE);
}



/*_*/

