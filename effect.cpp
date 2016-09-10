#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"

#include "effect.h"

CMyEffect::CMyEffect()
{
	m_effectMax = 20;
	m_effect = new MYEFFECT[m_effectMax];
	Clear();
}

CMyEffect::~CMyEffect()
{
	End();
}

void CMyEffect::End(void)
{
	DELETEARRAY(m_effect);
}

void CMyEffect::Clear(void)
{
	for (int i=0;i<m_effectMax;i++)
	{
		m_effect[i].flag = FALSE;
	}
}

void CMyEffect::AddEffect(int x,int y)
{
	for (int i=0;i<m_effectMax;i++)
	{
		if (!m_effect[i].flag)
		{
			m_effect[i].flag = TRUE;
			m_effect[i].count = 0;
			m_effect[i].type = 0;
			m_effect[i].x = x;
			m_effect[i].y = y;
			return;
		}
	}
}

void CMyEffect::Calcu(void)
{
	for (int i=0;i<m_effectMax;i++)
	{
		if (m_effect[i].flag)
		{
			m_effect[i].count++;
			if (m_effect[i].count >= 16)
			{
				m_effect[i].flag = FALSE;
			}
		}
	}
}


/*_*/

