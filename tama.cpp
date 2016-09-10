#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"

#include "tamaType.h"
#include "tama.h"


CTama::CTama()
{
	m_tamaMax = 40;
	m_tama = new TAMA[m_tamaMax];
	m_tamaType = new CTamaType();
}

CTama::~CTama()
{
	End();
}

void CTama::End(void)
{
	ENDDELETECLASS(m_tamaType);
	DELETEARRAY(m_tama);
}

void CTama::Clear(void)
{
	for (int i=0;i<m_tamaMax;i++)
	{
		m_tama[i].flag = FALSE;
	}
}

void CTama::AddTama(int type,int level,int x,int y)
{
	int loop = m_tamaType->GetTamaNumber(type,level);
	for (int k=0;k<loop;k++)
	{
		int n = SearchAki();
		if (n != -1)
		{
			POINT speed = m_tamaType->GetTamaSpeed(type,level,k);
			POINT p = m_tamaType->GetTamaDelta(type,level,k);
			int pic = m_tamaType->GetTamaPic(type,level,k);
			int attack = m_tamaType->GetTamaAttack(type,level,k);
			int laser = m_tamaType->GetTamaLaser(type,level,k);
			int angle = 0;//dummy?
			SIZE hitSize = m_tamaType->GetHitSize(type,level,k);

			m_tama[n].flag = TRUE;
			m_tama[n].x = x + p.x;
			m_tama[n].y = y + p.y;
			m_tama[n].angle = angle;
			m_tama[n].picType = pic;
			m_tama[n].type = type;
			m_tama[n].speedX = speed.x;
			m_tama[n].speedY = speed.y;
			m_tama[n].attack = attack;
			m_tama[n].hitSize = hitSize;
			m_tama[n].laser = laser;
		}
	}

}

int CTama::SearchAki(void)
{
	for (int i=0;i<m_tamaMax;i++)
	{
		if (!m_tama[i].flag)
		{
			return i;
		}
	}

	return -1;
}

BOOL CTama::CheckAki(int count)
{
	int sum = 0;
	for (int i=0;i<m_tamaMax;i++)
	{
		if (!m_tama[i].flag)
		{
			sum += 1;
			if (sum >= count)
			{
				return TRUE;
			}
		}
	}

	return FALSE;
}

int CTama::GetTypeCount(int type)
{
	int sum = 0;
	for (int i=0;i<m_tamaMax;i++)
	{
		if (m_tama[i].flag)
		{
			if (m_tama[i].type == type)
			{
				sum += 1;
			}
		}
	}

	return sum;
}

void CTama::Move(void)
{
	int loop = GetTamaMax();
	for (int i=0;i<loop;i++)
	{
		if (m_tama[i].flag)
		{
			int x = m_tama[i].x + m_tama[i].speedX;
			int y = m_tama[i].y + m_tama[i].speedY;
			if (CheckOutOfRange(x,y))
			{
				m_tama[i].flag = FALSE;
			}
			else
			{
				m_tama[i].x = x;
				m_tama[i].y = y;
			}
		}
	}
}


BOOL CTama::CheckOutOfRange(int x,int y)
{
	if (x < -40) return TRUE;
	if (x > 840) return TRUE;
	if (y < -40) return TRUE;
	if (y > 640) return TRUE;

	return FALSE;

}

BOOL CTama::CheckCanNewTama(int type,int level)
{
	int base = m_tamaType->GetTamaNumber(type,level);
	int multi = m_tamaType->GetTamaMulti(type,level);
	int use = GetTypeCount(type);
	if ((use + base) > base * multi) return FALSE;

	if (CheckAki(base))
	{
		return TRUE;
	}


	return FALSE;
}

int CTama::GetAutoFireLimit(int type,int level)
{
	return m_tamaType->GetAutoFireLimit(type,level);
}

/*_*/

