#if !defined __CMK2008SUMMER_MOVEPATTERN__
#define __CMK2008SUMMER_MOVEPATTERN__


class CNameList;

class CMovePattern
{
public:
	CMovePattern(int n);
	~CMovePattern();
	void End(void);

	int m_patternMax;
	
	BOOL CheckLast(int count);

	int GetAngle(int count);
	int GetKasoku(int count);
	int GetCommand(int count);

private:
	CNameList* m_list;
	int m_totalCount;
	int* m_count;

	int GetBlock(int count);
//	int GetAmari(int block,int count);

};

#endif
/*_*/

