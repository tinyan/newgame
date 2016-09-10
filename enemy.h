#if !defined __CMK2008SUMMER_ENEMY__
#define __CMK2008SUMMER_ENEMY__


class CCommonGeneral;
class CMovePattern;
class CStageData;
class CEnemyTypeList;

typedef struct _tagENEMY
{
	BOOL flag;
	int wait;
	int pic;
	double x,y;
	double angle;
	double speed;
	int hp;
	int deffense;
	int item;
	int henshin;
	int thinkCount;
	int thinkData[8];
	int movePattern;
	int moveCount;
	int score;
} ENEMY;

class CEnemy
{
public:
	CEnemy(int stageMax);
	~CEnemy();
	void End(void);

	void Clear(void);
	void SetAllEnemy(int stage);

	void Move(void);

	CStageData* GetStageData(int stage);
	int GetEnemyNumber(void);
	ENEMY* GetEnemy(int n);

	BOOL CheckStageEnd(void);

	void SetEnemyStatus(int n,int type);

	int CheckHit(int start,int x,int y,SIZE hitSize,int attack,int laser);

private:
	int m_movePatternMax;
	int m_stageDataMax;
	CMovePattern** m_movePattern;
	CStageData** m_stageData;
	CEnemyTypeList* m_enemyTypeList;

	ENEMY* m_enemy;

	int m_average;
	int m_enemyNumber;

	BOOL CheckOutOfRange(double x,double y);
};

#endif

/*_*/