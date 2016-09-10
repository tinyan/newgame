#include <windows.h>
#include <stdio.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"

#include "movePattern.h"
#include "stageData.h"
#include "enemyTypeList.h"
#include "enemy.h"

CEnemy::CEnemy(int stageMax)
{
	m_enemyTypeList = new CEnemyTypeList();

	m_movePatternMax = 40;
	m_movePattern = new CMovePattern*[m_movePatternMax+1];
	m_movePattern[0] = NULL;
	for (int i=1;i<=m_movePatternMax;i++)
	{
		m_movePattern[i] = new CMovePattern(i);
	}

	m_stageDataMax = stageMax;
	m_stageData = new CStageData*[m_stageDataMax];
	for (int i=0;i<m_stageDataMax;i++)
	{
		m_stageData[i] = new CStageData(i);
	}

	m_enemyNumber = 40;
	m_enemy = new ENEMY[40];
}

CEnemy::~CEnemy()
{
	End();
}

void CEnemy::End(void)
{
	if (m_stageData != NULL)
	{
		for (int i=0;i<m_stageDataMax;i++)
		{
			ENDDELETECLASS(m_stageData[i]);
		}
		DELETEARRAY(m_stageData);
	}

	if (m_movePattern != NULL)
	{
		for (int i=0;i<=m_movePatternMax;i++)
		{
			ENDDELETECLASS(m_movePattern[i]);
		}
		DELETEARRAY(m_movePattern);
	}

	DELETEARRAY(m_enemy);

	ENDDELETECLASS(m_enemyTypeList);
}

void CEnemy::SetAllEnemy(int stage)
{
	if ((stage < 0) || (stage >= m_stageDataMax)) stage = 0;
	CStageData* stageData = GetStageData(stage);

	m_enemyNumber = stageData->GetEnemyNumber();
	m_average = stageData->GetAverage();

	for (int i=0;i<m_enemyNumber;i++)
	{
		m_enemy[i].flag = TRUE;

		int type = stageData->GetType(i);
		SetEnemyStatus(i,type);

		m_enemy[i].thinkCount = 0;
		for (int k=0;k<8;k++)
		{
			m_enemy[i].thinkData[k] = stageData->GetThink(i,k);
		}
		m_enemy[i].movePattern = 0;
		m_enemy[i].moveCount = 0;

		POINT pt = stageData->GetStart(i);
		m_enemy[i].x = (double)pt.x;
		m_enemy[i].y = (double)pt.y;
		m_enemy[i].speed = (double)stageData->GetSpeed(i);
		m_enemy[i].angle = (double)stageData->GetAngle(i);
		m_enemy[i].wait = stageData->GetWait(i);

	}


}

void CEnemy::SetEnemyStatus(int n,int type)
{
	m_enemy[n].pic = m_enemyTypeList->GetPic(type);
	m_enemy[n].hp = m_enemyTypeList->GetHP(type);
	m_enemy[n].deffense = m_enemyTypeList->GetDeffense(type);
	m_enemy[n].item = m_enemyTypeList->GetItem(type);
	m_enemy[n].henshin = m_enemyTypeList->GetHenshin(type);
	m_enemy[n].score = m_enemyTypeList->GetScore(type);
}

void CEnemy::Clear(void)
{
	for (int i=0;i<m_enemyNumber;i++)
	{
		m_enemy[i].flag = FALSE;
	}
}

void CEnemy::Move(void)
{
	for (int i=0;i<m_enemyNumber;i++)
	{
		if (m_enemy[i].flag)
		{
			if (m_enemy[i].wait > 0)
			{
				m_enemy[i].wait--;
			}
			else
			{
				double th = m_enemy[i].angle;
				th *= 3.14159;
				th /= 180.0;
				double speed = m_enemy[i].speed;
				double dx = speed * cos(th);
				double dy = speed * sin(th);
				m_enemy[i].x += dx;
				m_enemy[i].y += dy;

				//check out of range
				if (CheckOutOfRange(m_enemy[i].x,m_enemy[i].y))
				{
					m_enemy[i].flag = FALSE;
					continue;
				}


				//think
//				if (m_enemy[i].thinkCount < 8)
				if (m_enemy[i].movePattern < 8)
				{
					int movePattern = m_enemy[i].movePattern;
					int moveCount = m_enemy[i].moveCount;

					int think = m_enemy[i].thinkData[movePattern];

					if (think == 0)
					{
						continue;
					}

					CMovePattern* pattern = m_movePattern[think];

					double angle = (double)pattern->GetAngle(moveCount);
					double kasoku = (double)pattern->GetKasoku(moveCount);
					m_enemy[i].speed += kasoku;
					if (m_enemy[i].speed < 0) m_enemy[i].speed = 0;

					m_enemy[i].angle += angle;
					if (m_enemy[i].angle < 0) m_enemy[i].angle += 360;
					if (m_enemy[i].angle >= 360) m_enemy[i].angle -= 360;

					/*
					if (i == 32)
					{
						if (think == 8)
						{
							int a = 0;
							a++;
						}
						char mes[256];
						sprintf_s(mes,256,"think=%d %d ",think,(int)angle);
						OutputDebugString(mes);

					}
					*/

					int cmd = pattern->GetCommand(moveCount);
					if (cmd > 0)
					{
						if (cmd <= 3)
						{
							if (cmd & 1)
							{
								m_enemy[i].angle = angle;
							}
							
							if (cmd & 2)
							{
								m_enemy[i].speed = kasoku;
							}
						}
					}

					moveCount++;
					m_enemy[i].moveCount = moveCount;


					//move pattern last?
					if (pattern->CheckLast(moveCount))
					{
						m_enemy[i].movePattern++;
						m_enemy[i].moveCount = 0;
					}
				}

			}

		}
	}
}

BOOL CEnemy::CheckOutOfRange(double x,double y)
{
	if (x < -100) return TRUE;
	if (x > 900) return TRUE;
	if (y < -200) return TRUE;
	if (y > 800) return TRUE;

	return FALSE;

}

CStageData* CEnemy::GetStageData(int stage)
{
	return m_stageData[stage];
}

int CEnemy::GetEnemyNumber(void)
{
	return m_enemyNumber;
}

ENEMY* CEnemy::GetEnemy(int n)
{
	return &(m_enemy[n]);
}

BOOL CEnemy::CheckStageEnd(void)
{
	int loop = GetEnemyNumber();
	for (int i=0;i<loop;i++)
	{
		if (m_enemy[i].flag) return FALSE;
	}

	return TRUE;
}

int CEnemy::CheckHit(int start,int x,int y,SIZE hitSize,int attack,int laser)
{
	int limitX1 = -hitSize.cx / 2;
	int limitX2 = hitSize.cx / 2;
	int limitY1 = -hitSize.cy / 2;
	int limitY2 = hitSize.cy / 2;

	int addHitSize = 16;
	limitX1 -= addHitSize;
	limitX2 += addHitSize;
	limitY1 -= addHitSize;
	limitY2 += addHitSize;

	int nodef = laser & 2;


	for (int i=start;i<m_enemyNumber;i++)
	{
		if (m_enemy[i].flag)
		{
			if (m_enemy[i].wait <= 0)
			{
				int dx = (int)m_enemy[i].x - x;
				int dy = (int)m_enemy[i].y - y;


				if ((dx > limitX1) && (dx < limitX2) && (dy > limitY1) && (dy < limitY2))
				{
					//
					int damage = attack;
					if (nodef == 0)
					{
						damage -= m_enemy[i].deffense;
					}
					if (damage < 1) damage = 1;
					m_enemy[i].hp -= damage;
					if (m_enemy[i].hp <= 0)
					{
						return i;
					}

					if ((laser & 1)== 0)
					{
						return -2;
					}
				}
			}
		}
	}

	return -1;
}

/*_*/

