#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"

#include "item.h"

CItem::CItem()
{
	m_itemMax = 20;
	m_item = new ITEM[m_itemMax];

}

CItem::~CItem()
{
	End();
}

void CItem::End(void)
{
	DELETEARRAY(m_item);
}

void CItem::Clear(void)
{
	for (int i=0;i<m_itemMax;i++)
	{
		m_item[i].flag = FALSE;
	}
}

BOOL CItem::CheckStageClear(void)
{
	for (int i=0;i<m_itemMax;i++)
	{
		if (m_item[i].flag) return FALSE;
	}

	return TRUE;
}

void CItem::Move(void)
{
	for (int i=0;i<m_itemMax;i++)
	{
		if (m_item[i].flag)
		{
			m_item[i].x += m_item[i].speedX;
			m_item[i].y += m_item[i].speedY;
			if (CheckOutOfRange(m_item[i].x,m_item[i].y))
			{
				m_item[i].flag = FALSE;
			}
		}
	}
}

BOOL CItem::CheckOutOfRange(int x,int y)
{
	if (x < -40) return TRUE;
	if (x > 840) return TRUE;
	if (y < -40) return TRUE;
	if (y > 640) return TRUE;

	return FALSE;
}

void CItem::AddItem(int type,int x,int y)
{
	for (int i=0;i<m_itemMax;i++)
	{
		if (!m_item[i].flag)
		{
			m_item[i].flag = TRUE;
			m_item[i].type = type;
			int picType = type;
			m_item[i].picType = picType;
			m_item[i].x = x;
			m_item[i].y = y;
			m_item[i].speedX = 0;
			m_item[i].speedY = 5;

			return;
		}
	}
}

/*_*/

