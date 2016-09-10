#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nyanlib\include\areaControl.h"
#include "..\..\systemNNN\nyanlib\include\picture.h"

#include "printZanki.h"


CPrintZanki::CPrintZanki()
{
	m_pic = new CPicture("sys\\ta_zanki");
}

CPrintZanki::~CPrintZanki()
{
	End();
}

void CPrintZanki::End(void)
{
	ENDDELETECLASS(m_pic);
}

void CPrintZanki::Print(int zanki)
{
	if (zanki <= 1) return;

	for (int i=0;i<zanki-1;i++)
	{
		int sizeX = 32;
		int sizeY = 32;

		int putX = 800-sizeX-i*sizeX - 8;
		int putY = 600-sizeY - 8;

		m_pic->Put(putX,putY,TRUE);
	}
}

/*_*/

