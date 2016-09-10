#if !defined __CMK2008SUMMER_STAGEDATA__
#define __CMK2008SUMMER_STAGEDATA__


class CNameList;

class CStageData
{
public:
	CStageData(int n);
	~CStageData();
	void End(void);


	int GetAverage(void){return m_average;}
	int GetEnemyNumber(void){return m_enemyNumber;}

	int GetType(int n);
	int GetWait(int n);
	POINT GetStart(int n);
	int GetAngle(int n);
	int GetSpeed(int n);
	int GetThink(int n,int k);



private:
	CNameList* m_list;
	int m_average;
	int m_enemyNumber;

};

#endif
/*_*/