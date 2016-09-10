#include <windows.h>
#include <stdio.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nnnUtilLib\nameList.h"

#include "stageData.h"

CStageData::CStageData(int n)
{
	char fullname[256];
	sprintf_s(fullname,256,"stage\\%d.xtx",n);
	m_list = new CNameList();
	m_list->LoadFile(fullname);

	int kosuu = m_list->GetNameKosuu();
	m_average = 40;
	if (kosuu > 0) m_average = atoi(m_list->GetName(0));
	m_enemyNumber = (kosuu - 8) / 16;



}


CStageData::~CStageData()
{
	End();
}

void CStageData::End(void)
{
	ENDDELETECLASS(m_list);
}
//type wait x,y,angle,speed,0,0
//think...

int CStageData::GetType(int n)
{
	if ((n < 0) || (n >= m_enemyNumber)) return 0;
	return atoi(m_list->GetName(8+n*16+0));
}

int CStageData::GetWait(int n)
{
	if ((n < 0) || (n >= m_enemyNumber)) return 0;
	return atoi(m_list->GetName(8+n*16+1));
}

POINT CStageData::GetStart(int n)
{
	POINT pt;
	pt.x = 0;
	pt.y = 0;

	if ((n < 0) || (n >= m_enemyNumber)) return pt;

	pt.x = atoi(m_list->GetName(8+n*16+2));
	pt.y = atoi(m_list->GetName(8+n*16+3));
	return pt;
}

int CStageData::GetAngle(int n)
{
	if ((n < 0) || (n >= m_enemyNumber)) return 0;
	return atoi(m_list->GetName(8+n*16+4));
}

int CStageData::GetSpeed(int n)
{
	if ((n < 0) || (n >= m_enemyNumber)) return 0;
	return atoi(m_list->GetName(8+n*16+5));
}

int CStageData::GetThink(int n,int k)
{
	if ((n < 0) || (n >= m_enemyNumber)) return 0;
	if ((k<0) || (k>=8)) return 0;
	return atoi(m_list->GetName(8+n*16+8 + k));
}






/*_*/


