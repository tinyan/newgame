#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nnnUtilLib\nameList.h"

#include "tamaType.h"



CTamaType::CTamaType()
{
	//num,multi,pic,dx,dy,sp,angle,autoLimit, attack,laser,hitSizeX,hitSizeY,
	m_list = new CNameList();
	m_list->LoadFile("data\\tamaType.xtx");

	int kosuu = m_list->GetNameKosuu();
	m_data = new int[kosuu];

	for (int i=0;i<kosuu;i++)
	{
		m_data[i] = atoi(m_list->GetName(i));
	}
}

CTamaType::~CTamaType()
{
	End();
}

void CTamaType::End(void)
{
	DELETEARRAY(m_data);
	ENDDELETECLASS(m_list);
}

int CTamaType::GetTamaNumber(int type,int level)
{
	return m_data[16*(type*4+level)+0];
}

int CTamaType::GetTamaMulti(int type,int level)
{
	return m_data[16*(type*4+level)+1];
}

POINT CTamaType::GetTamaDelta(int type,int level,int k)
{
	int n = GetTamaNumber(type,level);
	int dx = m_data[16*(type*4+level)+3];
	int dy = m_data[16*(type*4+level)+4];
	int x = - dx / 2;
	int y = - dy / 2;
	if (n > 1)
	{
		x += (dx * k) / (n - 1);
		y += (dy * k) / (n - 1);
	}

	int laser = GetTamaLaser(type,level,k);
	if (laser > 0)
	{
		SIZE hitSize = GetHitSize(type,level,k);
		y -=  hitSize.cy / 2;
	}


	POINT p;
	p.x = x;
	p.y = y;
	return p;
}

int CTamaType::GetTamaPic(int type,int level,int k)
{
	return m_data[16*(type*4+level)+2];
}

POINT CTamaType::GetTamaSpeed(int type,int level,int k)
{
	int n = GetTamaNumber(type,level);
	double sp = (double)m_data[16*(type*4+level)+5];
	int dangle = m_data[16*(type*4+level)+6];
	int angle = 270;
	if (n > 1)
	{
		angle -= dangle / 2;
		angle += (dangle * k) / (n - 1);
	}
	double th = (double)angle;
	th *= 3.14159;
	th /= 180.0;
	int speedX = (int)(cos(th) * sp);
	int speedY = (int)(sin(th) * sp);
	POINT p;
	p.x = speedX;
	p.y = speedY;
	return p;
}

SIZE CTamaType::GetHitSize(int type,int level,int k)
{
	SIZE sz;
	sz.cx = m_data[16*(type*4+level)+10];
	sz.cy = m_data[16*(type*4+level)+11];
	return sz;
}

int CTamaType::GetTamaAttack(int type,int level,int k)
{
	return m_data[16*(type*4+level)+8];
}

int CTamaType::GetTamaLaser(int type,int level,int k)
{
	return m_data[16*(type*4+level)+9];
}

int CTamaType::GetAutoFireLimit(int type,int level)
{
	return m_data[16*(type*4+level)+7];
}

/*
int CTamaType::GetTamaAngle(int type,int level)
{
}
*/

