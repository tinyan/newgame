#if !defined __TINYAN_NEWGAME_ENEMYTYPELIST__
#define __TINYAN_NEWGAME_ENEMYTYPELIST__

class CNameList;
class CEnemyTypeList
{
public:
	CEnemyTypeList();
	~CEnemyTypeList();
	void End(void);

	int GetPic(int type);
	int GetHP(int type);
	int GetDeffense(int type);
	int GetItem(int type);
	int GetHenshin(int type);
	int GetScore(int type);
private:
	CNameList* m_list;
	int m_typeMax;
};

#endif
/*_*/