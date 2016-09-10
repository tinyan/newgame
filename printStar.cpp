#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nyanlib\include\areaControl.h"
#include "..\..\systemNNN\nyanlib\include\picture.h"
#include "..\..\systemNNN\nyanlib\include\allGeo.h"
#include "..\..\systemNNN\nyanlib\include\mygraphics.h"

#include "printStar.h"

int CPrintStar::m_colorData[] = 
{
	255,255,255,
	255,255,255,
	255,255,255,
	255,255,255,
	255,64,64,
	255,64,64,
	255,64,64,
	255,64,64,
	32,64,255,
	32,64,255,
	32,64,255,
	32,64,255,
	255,255,64,
	255,255,64,
	255,255,64,
	255,255,64,

};
	

CPrintStar::	CPrintStar()
{
	m_max = 400;
	m_zahyo = new int[m_max * 2];

	m_mod = 0;

	Create();
}

CPrintStar::~CPrintStar()
{
	End();
}

void CPrintStar::End(void)
{
	DELETEARRAY(m_zahyo);
}

void CPrintStar::Create(void)
{
	for (int i=0;i<m_max;i++)
	{
		int x = rand() % 796;
		int y = rand() % 596;
		m_zahyo[i*2+0] = x;
		m_zahyo[i*2+1] = y;
	}

	for (int i=0;i<16;i++)
	{
		int r = m_colorData[i*3+0];
		int g = m_colorData[i*3+1];
		int b = m_colorData[i*3+2];
		int col = (r << 16) | (g << 8) | b;
		m_color[i] = col;
	}
}

void CPrintStar::Move(void)
{
	for (int i=0;i<m_max;i++)
	{
		int x = m_zahyo[i*2+0];
		int y = m_zahyo[i*2+1];
		y += 1;
		if (y >= 596)
		{
			y = rand() % 16;
			x = rand() % 796;
		}
		m_zahyo[i*2+0] = x;
		m_zahyo[i*2+1] = y;
	}
}

void CPrintStar::ReverseMove(void)
{
	for (int i=0;i<m_max;i++)
	{
		int x = m_zahyo[i*2+0];
		int y = m_zahyo[i*2+1];
		y -= 6;
		if (y <= 0)
		{
			y = 596;
			x = rand() % 796;
		}
		m_zahyo[i*2+0] = x;
		m_zahyo[i*2+1] = y;
	}
}

void CPrintStar::Print(void)
{
	m_mod++;
	m_mod %= 64;


	int* buf = CMyGraphics::GetScreenBuffer();
	int pitch = CMyGraphics::GetScreenSizeX();


	for (int i=0;i<m_max;i++)
	{
		int r = i + m_mod;
		r %= 64;
		if (r < 48)
		{
			int x = m_zahyo[i*2];
			int y = m_zahyo[i*2+1];

			int* add = buf + x + y * pitch;
			int col = m_color[i % 16];

//			*add = col;
			*(add+1) = col;
			*(add+pitch) = col;
			*(add+pitch+1) = col;
			*(add+pitch+2) = col;
			*(add+pitch*2+1) = col;

		}
	}

}
