#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"

#include "powerup.h"

CPowerup::CPowerup()
{
	Clear();
}

CPowerup::~CPowerup()
{
	End();
}

void CPowerup::End(void)
{
}

void CPowerup::Clear(void)
{
	m_select = 0;
	for (int i=0;i<4;i++)
	{
		m_level[i] = 0;
	}
//	m_level[0] = 1;
}

void CPowerup::GetItem(int type)
{
	if (type == m_select)
	{
		if (m_level[m_select] < 3)
		{
			m_level[m_select]++;
		}
	}
	m_select = type;
}

/*_*/

