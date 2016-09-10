#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nyanlib\include\areaControl.h"
#include "..\..\systemNNN\nyanlib\include\picture.h"

#include "item.h"
#include "printItem.h"


CPrintItem::CPrintItem()
{
	m_pic = new CPicture("sys\\ta_item");
}

CPrintItem::~CPrintItem()
{
	End();
}

void CPrintItem::End(void)
{
	ENDDELETECLASS(m_pic);
}


void CPrintItem::PutItem(int x,int y,int type)
{
	int sizeX = 64;
	int sizeY = 32;

	int srcX = 0;
	int srcY = 32 * type;

	int putX = x - sizeX / 2;
	int putY = y - sizeY / 2;

	m_pic->Blt(putX,putY,srcX,srcY,sizeX,sizeY,TRUE);

}

void CPrintItem::PrintAll(CItem* item)
{
	int loop = item->GetItemMax();
	for (int i=0;i<loop;i++)
	{
		ITEM* work = item->GetItem(i);
		if (work->flag)
		{
			int picType = work->picType;
			int x = work->x;
			int y = work->y;
//			int angle = work->angle;
			PutItem(x,y,picType);
		}
	}
}


/*_*/

