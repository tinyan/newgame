

#if !defined __CMK2008SUMMER_GAMETITLE__
#define __CMK2008SUMMER_GAMETITLE__


class CCommonGeneral;
class CGame;
class CPicture;

class CMyMessage;

class CNameList;

class CPrintEnemy;
class CPrintTama;
class CPrintPowerup;

class CTama;
class CEnemy;
class CPowerup;

class CPrintMyFont;

class CGameTitle : public CCommonGeneral
{
public:
	CGameTitle(CGame* lpGame);
	~CGameTitle();
	void End(void);

	int Init(void);
	int Calcu(void);
	int Print(void);


	void FinalExitRoutine(void);

private:
	CGame* m_game2;
	CMyMessage* m_message;


};

#endif
/*_*/



