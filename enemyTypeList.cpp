#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nnnUtilLib\namelist.h"

#include "enemyTypeList.h"

CEnemyTypeList::CEnemyTypeList()
{
	//pic,HP,def,item,henshin,score,0,0
	m_list = new CNameList();
	m_list->LoadFile("data\\enemytypelist.xtx");
	m_typeMax = m_list->GetNameKosuu() / 8;
}

CEnemyTypeList::~CEnemyTypeList()
{
	End();
}

void CEnemyTypeList::End(void)
{
}

int CEnemyTypeList::GetPic(int type)
{
	if ((type < 0) || (type >= m_typeMax)) return 0;
	return atoi(m_list->GetName(type*8+0));
}

int CEnemyTypeList::GetHP(int type)
{
	if ((type < 0) || (type >= m_typeMax)) return 1;
	return atoi(m_list->GetName(type*8+1));
}

int CEnemyTypeList::GetDeffense(int type)
{
	if ((type < 0) || (type >= m_typeMax)) return 0;
	return atoi(m_list->GetName(type*8+2));
}

int CEnemyTypeList::GetItem(int type)
{
	if ((type < 0) || (type >= m_typeMax)) return -1;
	return atoi(m_list->GetName(type*8+3));
}

int CEnemyTypeList::GetHenshin(int type)
{
	if ((type < 0) || (type >= m_typeMax)) return -1;
	return atoi(m_list->GetName(type*8+4));
}


int CEnemyTypeList::GetScore(int type)
{
	if ((type < 0) || (type >= m_typeMax)) return 0;
	return atoi(m_list->GetName(type*8+5));
}
/*_*/



