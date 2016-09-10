#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nyanlib\include\areaControl.h"
#include "..\..\systemNNN\nyanlib\include\picture.h"

#include "printMyFont.h"


CPrintMyFont::CPrintMyFont(LPSTR fontName,int sizeX,int sizeY)
{
	char filename[256];
	sprintf_s(filename,256,"sys\\%s",fontName);

	m_sizeX = sizeX;
	m_sizeY = sizeY;

	m_pic = new CPicture(filename);
}


CPrintMyFont::~CPrintMyFont()
{
	End();
}

void CPrintMyFont::End(void)
{
	ENDDELETECLASS(m_pic);
}

void CPrintMyFont::PrintSuuji(int x,int y,int data,int keta)
{

	char mes[256];
	sprintf_s(mes,256,"0000000%d",data);

	int ln = strlen(mes);

	int putX = x;
	int putY = y;
	PrintMessage(putX,putY,mes+ln-keta);

}

void CPrintMyFont::PrintMessage(int x,int y,LPSTR mes)
{
	int ln = strlen(mes);
	for (int i=0;i<ln;i++)
	{
		char c = *(mes+i);
		int d = (int)c & 0xff;
		d -= 32;
		d &= 0x3f;
		int srcX = d % 8;
		int srcY = d / 8;
		int sizeX = m_sizeX;
		int sizeY = m_sizeY;

		srcX *= sizeX;
		srcY *= sizeY;

		int putX = x + sizeX * i;
		int putY = y;

		m_pic->Blt(putX,putY,srcX,srcY,sizeX,sizeY,TRUE);
	}

}



/*_*/

