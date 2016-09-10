#include <windows.h>
#include <stdio.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nnnUtilLib\nameList.h"

#include "movepattern.h"

CMovePattern::CMovePattern(int n)
{
	char fullname[256];
	sprintf_s(fullname,256,"move\\%d.xtx",n);
	m_list = new CNameList();
	m_list->LoadFile(fullname);

	//count,command,angle,kasoku

	int kosuu = m_list->GetNameKosuu();
	m_patternMax = kosuu / 8;

	m_count = new int[m_patternMax];
	m_totalCount = 0;
	for (int i=0;i<m_patternMax;i++)
	{
		m_totalCount += atoi(m_list->GetName(i*8+0));
		m_count[i] = m_totalCount;
	}
}


CMovePattern::~CMovePattern()
{
	End();
}

void CMovePattern::End(void)
{
	DELETEARRAY(m_count);
	ENDDELETECLASS(m_list);
}

BOOL CMovePattern::CheckLast(int count)
{
	if (count >= m_totalCount) return TRUE;
	return FALSE;
}

int CMovePattern::GetCommand(int count)
{
	int block = GetBlock(count);
	return atoi(m_list->GetName(block*8+1));
}

int CMovePattern::GetAngle(int count)
{
	int block = GetBlock(count);
	return atoi(m_list->GetName(block*8+2));
}

int CMovePattern::GetKasoku(int count)
{
	int block = GetBlock(count);
	return atoi(m_list->GetName(block*8+3));

}

int CMovePattern::GetBlock(int count)
{
	for (int i=0;i<m_patternMax;i++)
	{
		if (count < m_count[i]) return i;
	}

	return 0;
}

/*
int CMovePattern::GetAmari(int block,int count)
{
	if (block == 0) return count;
	return count - m_count[block-1];

}
*/

/*_*/


