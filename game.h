//
//
//

#if !defined __NNNEXE_GAME__
#define __NNNEXE_GAME__


//#include "..\nnnLib\gameCallBack.h"

class CCommonSystemFile;
class CNameList;


class CGameCallBack;

class CGame : public CGameCallBack
{
public:
	CGame(HWND hwnd, HINSTANCE hinstance, CCommonSystemFile* lpSystemFile, int windowSizeX, int windowSizeY, int bpp);
	virtual ~CGame();
	void End(void);


//
	void ReceiveUserCommand(int cmd, int paraKosuu, int* paraPtr);
	void ReceiveUserFunction(int cmd, int paraKosuu, int* paraPtr);
	void UserCommandCallBack(void);

	/////////////////////////////////////////////Ç±ÇÃÇ÷ÇÒÇ…ïKóvÇ»ä÷êîÇí«â¡

	//åpè≥
	void GetExtDataForSave(LPVOID ptr,int extNumber = 0);
	void SetExtDataByLoad(LPVOID ptr,int extNumber = 0);

	void Create(void);

	void SetStartStageFlag(int startStage = 0){m_startStageFlag = startStage;}
	int GetStartStageFlag(void) {return m_startStageFlag;}
private:
	void CreateAllClass(void);
//	void AfterInitNewGame(int uraMode = 0, BOOL demoFlag = FALSE);

	BOOL CheckDebugOk(void);

	int m_startStageFlag;
};





#endif
/*_*/

