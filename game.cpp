//
// game.cpp
//






#include <windows.h>
#include <stdio.h>

#include "..\..\systemNNN\nyanLib\include\commonMacro.h"
#include "..\..\systemNNN\nnnUtilLib\scriptcommand.h"
#include "..\..\systemNNN\nnnUtilLib\commonGameVersion.h"
#include "..\..\systemNNN\nnnUtilLib\nameList.h"

#include "..\..\systemNNN\nyanLib\include\myFile.h"
#include "..\..\systemNNN\nnnUtilLib\mySaveFolder.h"



//#include "..\nnnUtilLib\varNumber.h"
//#include "..\nnnUtilLib\myKeyStatus.h"
//#include "..\nnnUtilLib\inputStatus.h"
//#include "..\nnnUtilLib\gameMouse.h"
//#include "..\nnnUtilLib\messageCursor.h"
//#include "..\nnnUtilLib\sceneOptionButton.h"
//#include "..\nnnUtilLib\waveMusic.h"
#include "..\..\systemNNN\nnnUtilLib\commonSystemFile.h"


#include "..\..\systemNNN\nnnLib\commonMode.h"
//#include "..\nnnLib\execScript.h"
#include "..\..\systemNNN\nnnLib\commonGeneral.h"
//#include "..\nnnLib\commonSelectPlace.h"
//#include "..\nnnLib\commonSelectHeroin.h"
//#include "..\nnnLib\commonPrintCalendar.h"
//#include "..\nnnLib\commonPrintMovie.h"
#include "..\..\systemNNN\nnnLib\gameCallBack.h"



#include "mode.h"


#include "gameTitle.h"
#include "play.h"
//#include "editmap.h"
//#include "gameTitle.h"


//#include "nekopic.h"

#include "game.h"

/*
int CGame::m_daysOfMonth[13]=
{
	0,	31,29,31,30,31,30,31,31,30,31,30,31,
};
*/




CGame::CGame(HWND hwnd, HINSTANCE hinstance, CCommonSystemFile* lpSystemFile, int windowSizeX, int windowSizeY, int bpp) : CGameCallBack(hwnd, hinstance, lpSystemFile, windowSizeX, windowSizeY, bpp)
{
}

void CGame::Create(void)
{
	if (CheckDebugOk()) SetDebugFlag();

	LPSTR saveFolder = CMySaveFolder::GetFullFolder();

	m_startStageFlag = 0;
	CreateAllClass();

	SetOption(FALSE);
	StartInitialMessage();
}


CGame::~CGame()
{
	End();
}

void CGame::End(void)
{
}







///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CGame::CreateAllClass(void)
{
	CreateCommonClass(NOTHING_MODE);
	CreateCommonClass(LOGO_MODE);
//	CreateCommonClass(TITLE_MODE);
//	CreateCommonClass(OPENING_MODE);
//	CreateCommonClass(CONFIG_MODE);
//	CreateCommonClass(PRINTMESSAGE_MODE);
//	CreateCommonClass(SELECTPLACE_MODE);
//	CreateCommonClass(BACKLOG_MODE);
//	CreateCommonClass(PRINTOVERRAP_MODE);
//	CreateCommonClass(SELECTMESSAGE_MODE);
//	CreateCommonClass(SYSTEMMENU_MODE);
//
//	CreateCommonClass(CODECERROR_MODE);
//	CreateCommonClass(PRINTMOVIE_MODE);

//	CreateCommonClass(SELECTHEROIN_MODE);
//	CreateCommonClass(PRINTCALENDAR_MODE);

//	CreateCommonClass(PRINTMOVIE_MODE);
//	CreateCommonClass(NAMEINPUT_MODE);
//	CreateCommonClass(MYPRINTRESULT_MODE);
//	CreateCommonClass(SELECTCHART_MODE);

	if (CCommonGameVersion::CheckTaikenOrNetVersion() == FALSE)
	{
//		CreateCommonClass(OMAKE_MODE);
//		CreateCommonClass(SELECTCGCHARA_MODE);
//		CreateCommonClass(SELECTCG_MODE);
//		CreateCommonClass(SELECTSCENECHARA_MODE);
//		CreateCommonClass(SELECTSCENE_MODE);
//		CreateCommonClass(LISTENBGM_MODE);
//		CreateCommonClass(PRINTCG_MODE);
//		CreateCommonClass(LOAD_MODE);
//		CreateCommonClass(SAVE_MODE);
	}


	m_general[GAMETITLE_MODE] = new CGameTitle(this);
	m_general[PLAY_MODE] = new CPlay(this);
//	m_general[EDITMAP_MODE] = new CEditMap(this);

//	m_general[GAMETITLE_MODE] = new CGameTitle(this);
//	m_general[EDITDECK_MODE] = new CEditDeck(this);
//	m_general[LOADDECK_MODE] = new CLoadDeck(this);
//	m_general[SAVEDECK_MODE] = new CSaveDeck(this);
//	m_general[GACHA_MODE] = new CGacha(this);
//	m_general[SELECTSTAGE_MODE] = new CSelectStage(this);



//	m_general[NEKOPIC_MODE] = new CNekoPic(this);




//	CreateCommonClass(LOAD_MODE);
//	CreateCommonClass(SAVE_MODE);

//	CreateCommonClass(MINIGAME_MODE);


}




void CGame::ReceiveUserCommand(int cmd, int paraKosuu, int* paraPtr)
{
	m_skipNextCommandFlag = FALSE;
	m_userCommand = cmd;
	GetUserPara(paraKosuu, paraPtr);

//	if (m_userCommand == m_selectHeroinCommandNumber)
//	{
//		CSelectHeroin* selectHeroin = (CSelectHeroin*)m_general[SELECTHEROIN_MODE];
//		selectHeroin->StartSelectHeroin();
//		SetReturnCode(SELECTHEROIN_MODE);
//	}


}



void CGame::ReceiveUserFunction(int cmd, int paraKosuu, int* paraPtr)
{
	m_userFunction = cmd;
	GetUserPara(paraKosuu, paraPtr);

	if (m_userFunction == m_adjustDateFunction)
	{
		if (m_dayMonthVar != -1)
		{
			int d = GetVarData(m_dayMonthVar);
////			d = AdjustDate(d);
			SetVarData(m_dayMonthVar,d);
		}
	}



}






/*
int CGame::AdjustDate(int daymonth)
{
	int month = daymonth / 100;
	int day = daymonth % 100;

	if (day > m_daysOfMonth[month])
	{
		day -= m_daysOfMonth[month];
		month++;
	}

	return month * 100 + day;
}
*/







void CGame::UserCommandCallBack(void)
{
//	if (m_userCommand == m_selectPlaceCommandNumber)
//	{
//		CCommonSelectPlace* selectPlace = (CCommonSelectPlace*)(m_general[SELECTPLACE_MODE]);
//
//		SetReturnCode(SELECTPLACE_MODE);
//	}

}






BOOL CGame::CheckDebugOk(void)
{
	FILE* file00 = NULL;

	fopen_s(&file00,"debug666.txt","rb");
	if (file00 != NULL)
	{
		fclose(file00);
		return TRUE;
	}
	return FALSE;
}


void CGame::GetExtDataForSave(LPVOID ptr,int extNumber)
{
}

void CGame::SetExtDataByLoad(LPVOID ptr,int extNumber)
{
}


/*_*/



