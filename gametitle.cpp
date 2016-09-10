

#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nyanlib\include\areaControl.h"
#include "..\..\systemNNN\nyanlib\include\picture.h"
#include "..\..\systemNNN\nyanlib\include\myGraphics.h"
#include "..\..\systemNNN\nyanlib\include\allGeo.h"
#include "..\..\systemNNN\nyanlib\include\allGraphics.h"

#include "..\..\systemNNN\nnnLib\commonGeneral.h"
#include "..\..\systemNNN\nnnLib\gameCallBack.h"

#include "..\..\systemNNN\nnnLib\commonSystemParamName.h"
#include "..\..\systemNNN\nnnUtilLib\nnnButtonStatus.h"

#include "..\..\systemNNN\nnnUtilLib\myMouseStatus.h"
#include "..\..\systemNNN\nnnUtilLib\mymessage.h"
#include "..\..\systemNNN\nnnUtilLib\nameList.h"

#include "..\..\systemNNN\nnnUtilLib\superButtonPicture.h"
#include "..\..\systemNNN\nnnUtilLib\commonButton.h"
#include "..\..\systemNNN\nnnUtilLib\commonButtonGroup.h"

#include "..\..\systemNNN\nnnUtilLib\commonBackButton.h"

#include "..\..\systemNNN\nnnUtilLib\systempicture.h"
#include "..\..\systemNNN\nnnUtilLib\suuji.h"


#include "mode.h"

//#include "clearStage.h"
//#include "mapData.h"
//#include "demoPlay.h"

//#include "hajike.h"

//#include "printCountDown.h"
//#include "printHaikei.h"
//#include "printPlate.h"
//#include "printScore.h"

//#include "printGameStatus.h"

//#include "resultControl.h"

//#include "highScoreData.h"

//#include "playStageCommon.h"
//#include "playStageType1.h"
//#include "playStageType1B.h"
//#include "playStageType2.h"
//#include "playStageType3.h"


#include "tama.h"
#include "enemy.h"
#include "powerup.h"

#include "printEnemy.h"
#include "printTama.h"
#include "printPowerup.h"

#include "printMyFont.h"

#include "gametitle.h"
#include "game.h"





CGameTitle::CGameTitle(CGame* lpGame) : CCommonGeneral(lpGame)
{
	SetClassNumber(GAMETITLE_MODE);
	LoadSetupFile("gametitle",256);

	m_game2 = lpGame;
	m_message = m_game->GetMyMessage();



	GetFadeInOutSetup();

}


CGameTitle::~CGameTitle()
{
	End();
}

void CGameTitle::End(void)
{



//	ENDDELETECLASS(m_cancelButton);
//	ENDDELETECLASS(m_dropButton);
//	ENDDELETECLASS(m_useButton);

//	ENDDELETECLASS(m_soundControl);
}


int CGameTitle::Init(void)
{
	m_commonBG->LoadDWQ("sys\\title");

	return -1;
}



int CGameTitle::Calcu(void)
{
//	m_soundControl->Clear();


	if (m_mouseStatus->CheckClick())
	{
		m_game2->SetStartStageFlag();
		return ReturnFadeOut(PLAY_MODE);
	}

	if (m_mouseStatus->CheckClick(1))
	{
		m_game2->SetStartStageFlag(1);
		return ReturnFadeOut(PLAY_MODE);
	}



	return -1;
}


int CGameTitle::Print(void)
{
	
	CAreaControl::SetNextAllPrint();

	m_commonBG->Put(0,0,FALSE);

	return -1;
}



void CGameTitle::FinalExitRoutine(void)
{
}




/*_*/


