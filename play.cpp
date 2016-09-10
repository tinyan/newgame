

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

#include "..\..\systemNNN\nyanlib\include\myFile.h"
#include "..\..\systemNNN\nnnUtilLib\mySaveFolder.h"

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
#include "item.h"
#include "effect.h"

#include "printEnemy.h"
#include "printTama.h"
#include "printItem.h"
#include "printPowerup.h"
#include "printEffect.h"
#include "printStar.h"
#include "printZanki.h"
#include "printStage.h"

#include "stageData.h"

#include "printMyFont.h"

#include "play.h"
#include "game.h"


#define STAGESTART_MODE 0
#define GAMEPLAY_MODE 1
#define GAMEOVER_MODE 2
#define STAGECLEAR_MODE 3



CPlay::CPlay(CGame* lpGame) : CCommonGeneral(lpGame)
{
	SetClassNumber(PLAY_MODE);
	LoadSetupFile("play",256);

	m_game2 = lpGame;
	m_message = m_game->GetMyMessage();

	m_stageMax = 15;

	m_jiki = CSystemPicture::GetSystemPicture("ta_jiki");
//	m_font = CSystemPicture::GetSystemPicture("ta_font");
//	m_font32 = CSystemPicture::GetSystemPicture("ta_font32");

	m_printFont32 = new CPrintMyFont("ta_font32",32,32);
	m_printFont64 = new CPrintMyFont("ta_font",64,64);

	m_tama = new CTama();
	m_enemy = new CEnemy(m_stageMax);
	m_item = new CItem();
	m_effect = new CMyEffect();
	m_powerup = new CPowerup();

	m_printTama = new CPrintTama();
	m_printEnemy = new CPrintEnemy();
	m_printItem = new CPrintItem();
	m_printPowerup = new CPrintPowerup();
	m_printEffect = new CPrintEffect();
	m_printStar = new CPrintStar();
	m_printZanki = new CPrintZanki();
	m_printStage = new CPrintStage();


//	m_soundControl = new CSoundControl();
	
//	CreateBackButton();
//	m_back->SetCancelButtonFlag(FALSE);

//	m_useButton = new CCommonButton(m_setup,"use");
//	m_dropButton = new CCommonButton(m_setup,"drop");
//	m_cancelButton = new CCommonButton(m_setup,"cancel");

//	m_useButton->SetPicture(CSuperButtonPicture::GetPicture(3));
//	m_dropButton->SetPicture(CSuperButtonPicture::GetPicture(4));
//	m_cancelButton->SetPicture(CSuperButtonPicture::GetPicture(5));

	m_score = 0;
	m_highScore = 10000;
	LoadHighScore();

	m_fireSoundBuffer = 0;
	m_hitSoundBuffer = 0;

	GetFadeInOutSetup();

}


CPlay::~CPlay()
{
	End();
}

void CPlay::End(void)
{


	ENDDELETECLASS(m_printStage);
	ENDDELETECLASS(m_printZanki);
	ENDDELETECLASS(m_printStar);
	ENDDELETECLASS(m_printEffect);
	ENDDELETECLASS(m_printPowerup);
	ENDDELETECLASS(m_printEnemy);
	ENDDELETECLASS(m_printTama);
	ENDDELETECLASS(m_printItem);

	ENDDELETECLASS(m_effect);
	ENDDELETECLASS(m_powerup);
	ENDDELETECLASS(m_item);
	ENDDELETECLASS(m_enemy);
	ENDDELETECLASS(m_tama);

	ENDDELETECLASS(m_printFont64);
	ENDDELETECLASS(m_printFont32);

//	ENDDELETECLASS(m_cancelButton);
//	ENDDELETECLASS(m_dropButton);
//	ENDDELETECLASS(m_useButton);

//	ENDDELETECLASS(m_soundControl);
}


int CPlay::Init(void)
{
	m_oneup = 20000;
	m_stageLoop = 0;
	m_stage = 0;
	if (m_game2->GetStartStageFlag())
	{
		m_stage = m_stageMax - 1;
	}

	m_highScoreUpdateFlag = FALSE;

	m_score = 0;
	m_zanki = 3;

//	m_useButton->LoadFile();
//	m_dropButton->LoadFile();
//	m_cancelButton->LoadFile();

//	ClearButton();

	m_jikiX = 400;
	m_jikiY = 560;

	m_powerup->Clear();
	m_item->Clear();
	m_enemy->Clear();
	m_tama->Clear();
	m_effect->Clear();


	StartStartStage();

//	NewStage();

//	m_tama->AddTama(0,300,300,0);
	
//	LoadBackButtonPic();
//	m_back->Init();

//	m_soundControl->Clear();

//	m_game->PlaySystemSound(17-1);

	return -1;
}



int CPlay::Calcu(void)
{
	m_tama->Move();

	MoveJiki();
	CheckFire();

	if (m_playMode == STAGESTART_MODE)
	{
		return CalcuStageStart();
	}
	else if (m_playMode == GAMEPLAY_MODE)
	{
		return CalcuGamePlay();
	}
	else if (m_playMode == STAGECLEAR_MODE)
	{
		return CalcuStageClear();
	}
	else if (m_playMode == GAMEOVER_MODE)
	{
		return CalcuGameover();
	}


	return -1;
}


int CPlay::Print(void)
{
	
	CAreaControl::SetNextAllPrint();

	CAllGraphics::FillScreen();


	m_printStar->Print();
	m_printZanki->Print(m_zanki);
	m_printStage->Print(m_stage + m_stageLoop * m_stageMax);


	if (m_playMode == STAGESTART_MODE)
	{
		PrintStageStart();
	}
	else if (m_playMode == GAMEPLAY_MODE)
	{
		PrintGamePlay();
	}
	else if (m_playMode == STAGECLEAR_MODE)
	{
		PrintStageClear();
	}
	else if (m_playMode == GAMEOVER_MODE)
	{
		PrintGameover();
	}


	m_jiki->Blt(m_jikiX-32,m_jikiY-32,0,0,64,64,TRUE);

	m_printEnemy->AllPrint(m_enemy);
	m_printTama->PrintAll(m_tama);

	m_printEffect->PrintAll(m_effect);
	m_effect->Calcu();

	m_printItem->PrintAll(m_item);

	m_printPowerup->PrintAll(m_powerup);


	m_printFont32->PrintSuuji(800-32*8-8,8,m_score);
//	m_message->PrintMessage(100,100,"‚o‚k‚`‚x");

	return -1;
}



void CPlay::FinalExitRoutine(void)
{
}



void CPlay::NewStage(void)
{
	m_tama->Clear();
	m_effect->Clear();

	m_enemy->SetAllEnemy(m_stage);

	CStageData* stageData = m_enemy->GetStageData(m_stage);

	m_average = stageData->GetAverage();
	m_perfectNumber = stageData->GetEnemyNumber();

	if (m_stageLoop == 1)
	{
		m_average = (m_average + m_perfectNumber) / 2;
	}
	else if (m_stageLoop > 1)
	{
		m_average = m_perfectNumber;
	}




	m_numberOfHit = 0;
	m_bonus = 0;

	m_autoFireCount = 0;
	GetAutoFireLimit();
}




void CPlay::StartStartStage(void)
{
	NewStage();
	m_count = 0;
	m_playMode = STAGESTART_MODE;
}

void CPlay::StartPlay(void)
{
	m_playMode = GAMEPLAY_MODE;
}

void CPlay::StartStageClear(void)
{
	//bonus
	m_bonus = 0;
	if (m_numberOfHit == m_perfectNumber)
	{
		m_bonus = 10000;
	}
	else if (m_numberOfHit >= m_average)
	{
		m_bonus = 100 * m_numberOfHit;
	}

	m_count = 0;
	m_playMode = STAGECLEAR_MODE;
}

void CPlay::StartGameover(void)
{
	m_count = 0;

	if (m_highScoreUpdateFlag)
	{
		SaveHighScore();
	}

	m_playMode = GAMEOVER_MODE;
}


int CPlay::CalcuStageStart(void)
{
	m_count++;
	if (m_count >= 200)
	{
		StartPlay();
	}

	return -1;
}

int CPlay::CalcuGamePlay(void)
{
	m_printStar->Move();

	m_enemy->Move();
	m_item->Move();


	CheckGetPowerup();

	//hit check
	CheckHit();


	


	if (CheckStageEnd())
	{
		if (m_numberOfHit >= m_average)
		{
		}
		else
		{
			m_zanki--;
		}
		StartStageClear();
	}



	return -1;
}

int CPlay::CalcuStageClear(void)
{
	if (m_numberOfHit >= m_perfectNumber)
	{
		m_printStar->ReverseMove();
	}
	else if (m_numberOfHit >= m_average)
	{
		m_printStar->Move();
	}
	
	m_count++;
	if (m_count == 30)
	{
		if (m_numberOfHit >= m_perfectNumber)
		{
			m_game->PlaySystemSound(13);
		}
		else if (m_numberOfHit >= m_average)
		{
			m_game->PlaySystemSound(12);
		}
	}

	if (m_count >= 200)
	{
		AddScore(m_bonus);

		if (m_zanki <= 0)
		{
			StartGameover();
		}
		else
		{
			if (NextStage())
			{
				StartStartStage();
			}
			else
			{
				StartGameover();
			}
		}
	}
	return -1;
}

int CPlay::CalcuGameover(void)
{
	m_count++;
	if (m_count >= 30)
	{
		if ((m_mouseStatus->CheckClick()) || (m_count >= 200))
		{
			return ReturnFadeOut(GAMETITLE_MODE);
		}
	}

	return -1;
}

void CPlay::PrintStageStart(void)
{
	int x = 140;
	int y = 200;
	int y2 = 350;

	if (m_count >= 30)
	{
		char mes[256];
		sprintf_s(mes,256,"STAGE %d",m_stage+m_stageLoop*m_stageMax+1);
		m_printFont64->PrintMessage(x,y,mes);
	}

	if (m_count >= 60)
	{
		char mes[256];
		sprintf_s(mes,256,"NEED  %d",m_average);
		m_printFont64->PrintMessage(x,y2,mes);
		//avarage dd
	}
}

void CPlay::PrintGamePlay(void)
{
}

void CPlay::PrintStageClear(void)
{
	int x = 160;
	int y = 200;
	int y0 = 250;
	int y1 = 300;
	int y2 = 350;

	if (m_count >= 30)
	{
		char mes[256];
		sprintf_s(mes,256,"HIT     %d",m_numberOfHit);
		m_printFont32->PrintMessage(x,y,mes);

		if (m_numberOfHit >= m_average)
		{
			m_printFont32->PrintMessage(x,y0,"SUCCESS!");
		}
		else
		{
			m_printFont32->PrintMessage(x,y0,"FAIL...");
		}
	}
	
	if (m_count >= 45)
	{
		if (m_numberOfHit == m_perfectNumber)
		{
			if ((m_count % 8) < 4)
			{
				m_printFont32->PrintMessage(x,y1,"PERFECT!");
			}
		}
	}
	
	if (m_count >= 60)
	{
		char mes[256];
		if (m_numberOfHit >= m_average)
		{
			sprintf_s(mes,256,"BONUS   %d",m_bonus);
		}
		else
		{
			sprintf_s(mes,256,"NO BONUS");
		}
		m_printFont32->PrintMessage(x,y2,mes);
	}
}

void CPlay::PrintGameover(void)
{
	int x = 160;
	int y = 300;
	int y2 = 400;

	m_printFont64->PrintMessage(128,200,"GAME OVER");

	if (m_count >= 30)
	{
		char mes[256];
		sprintf_s(mes,256,"SCORE   %d",m_score);
		m_printFont32->PrintMessage(x,y,mes);
	}
	
	if (m_count >= 60)
	{
		char mes[256];
		sprintf_s(mes,256,"HIGH-   %d",m_highScore);
		m_printFont32->PrintMessage(x,y2,mes);
		//avarage dd
	}
}


BOOL CPlay::NextStage(void)
{
	m_stage++;
	if (m_stage >= m_stageMax)
	{
		m_stage = 0;
		m_stageLoop++;
		if (m_stageLoop >= 3) return FALSE;
	}



	return TRUE;
}

void CPlay::AddScore(int point)
{
	m_score += point;
	if (m_score > m_highScore)
	{
		m_highScoreUpdateFlag = TRUE;
		m_highScore = m_score;
	}

	//one up?
	if (m_score >= m_oneup)
	{
		if (m_oneup == 20000)
		{
			m_oneup = 60000;
		}
		else
		{
			m_oneup += 60000;
		}
		m_zanki++;
		m_game->PlaySystemSound(14);
	}
}


void CPlay::CheckGetPowerup(void)
{
	int loop = m_item->GetItemMax();
	for (int i=0;i<loop;i++)
	{
		ITEM* item = m_item->GetItem(i);
		if (item->flag)
		{
			int itemX = item->x;
			int itemY = item->y;
			int dx = m_jikiX - itemX;
			int dy = m_jikiY - itemY;
			if ((dx >= -32) && (dx < 32) && (dy>= -32) && (dy < 32))
			{
				AddScore(1000);
				int type = item->type;
				GetItemRoutine(type);
				item->flag = FALSE;
			}
		}
	}
}


void CPlay::GetAutoFireLimit(void)
{
	int type = m_powerup->GetType();
	int level = m_powerup->GetLevel(type);
	m_autoFireLimit = m_tama->GetAutoFireLimit(type,level);
}

BOOL CPlay::CheckStageEnd(void)
{
	if (!m_enemy->CheckStageEnd()) return FALSE;
	if (!m_item->CheckStageClear()) return FALSE;

	return TRUE;
}

void CPlay::GetItemRoutine(int type)
{
	m_game->PlaySystemSound(9);

	m_powerup->GetItem(type);
	GetAutoFireLimit();
}



void CPlay::FireRoutine(void)
{
	int type = m_powerup->GetType();
	int level = m_powerup->GetLevel(type);
	if (m_tama->CheckCanNewTama(type,level))
	{
		PlayFireSound(type);
		m_tama->AddTama(type,level,m_jikiX,m_jikiY);
		m_autoFireCount = 0;
	}
}


void CPlay::MoveJiki(void)
{
	POINT pt = m_mouseStatus->GetZahyo();
	int targetX = pt.x;
	int targetY = pt.y;
	if (targetX < 50) targetX = 50;
	if (targetX > 750) targetX = 750;
	if (targetY < 350) targetY = 350;
	if (targetY > 550) targetY = 550;

	int speedX = 10;
	int speedY = 10;

	if (m_jikiX < targetX)
	{
		m_jikiX += speedX;
		if (m_jikiX > targetX)
		{
			m_jikiX = targetX;
		}
	}
	else if (m_jikiX > targetX)
	{
		m_jikiX -= speedX;
		if (m_jikiX < targetX)
		{
			m_jikiX = targetX;
		}
	}

	if (m_jikiY < targetY)
	{
		m_jikiY += speedY;
		if (m_jikiY > targetY)
		{
			m_jikiY = targetY;
		}
	}
	else if (m_jikiY > targetY)
	{
		m_jikiY -= speedY;
		if (m_jikiY < targetY)
		{
			m_jikiY = targetY;
		}
	}
}

void CPlay::CheckHit(void)
{
	int loop = m_tama->GetTamaMax();
	for (int i=0;i<loop;i++)
	{
		TAMA* tama = m_tama->GetTama(i);
		if (tama->flag)
		{
			SIZE hitCheck = tama->hitSize;
			int x = tama->x;
			int y = tama->y;
			int attack = tama->attack;

			int start = 0;
			int laser = tama->laser;
			int hit = -1;
			while ((hit = m_enemy->CheckHit(start,x,y,hitCheck,attack,laser)) != -1)
//			int hit = m_enemy->CheckHit(x,y,hitCheck,attack);
//			if (hit != -1)
			{
				if (hit == -2)
				{
					PlayKinSound();
					break;
				}

				ENEMY* enemy = m_enemy->GetEnemy(hit);

				int score = enemy->score;
				AddScore(score);

				int item = enemy->item;

				int henshin = enemy->henshin;
				if (henshin < 0)
				{
					enemy->flag = FALSE;
					m_numberOfHit++;
					AddEffect((int)enemy->x,(int)enemy->y);

					PlayHitSound();

				//	char mes[256];
				//	sprintf_s(mes,256,"”j‰ó %d",hit);
				//	OutputDebugString(mes);
				}
				else
				{
					m_enemy->SetEnemyStatus(hit,henshin);
				}


				if (item != -1)
				{
					m_item->AddItem(item,(int)enemy->x,(int)enemy->y);
				}


				if ((laser & 1) == 0)
				{
					tama->flag = FALSE;
					break;
				}
				else
				{
					start = hit + 1;
				}
			}
		}
	}

}


void CPlay::AddEffect(int x,int y)
{
	m_effect->AddEffect(x,y);
}

void CPlay::CheckFire(void)
{
//fire?
	BOOL fire = FALSE;
	if (m_mouseStatus->CheckClick(0)) fire = TRUE;
	if (m_mouseStatus->GetTrig(0))
	{
		m_autoFireCount++;
		if (m_autoFireCount >= m_autoFireLimit) fire = TRUE;
	}

	if (fire)
	{
		FireRoutine();
	}

}

void CPlay::PlayHitSound(void)
{
	m_game->PlaySystemSound(10+m_hitSoundBuffer);
	m_hitSoundBuffer++;
	m_hitSoundBuffer %= 2;

}

void CPlay::PlayFireSound(int n)
{
	m_game->PlaySystemSound(n*2+1+m_fireSoundBuffer);
	m_fireSoundBuffer++;
	m_fireSoundBuffer %= 2;
}

void CPlay::PlayKinSound(void)
{
	m_game->PlaySystemSound(15);
}

void CPlay::LoadHighScore(void)
{
	LPSTR folderName = CMySaveFolder::GetFullFolder();
	char filename[1024];
	sprintf_s(filename,1024,"%s\\high.dat",folderName);
	FILE* file = CMyFile::OpenFullPath(filename,"rb");
	if (file != NULL)
	{
		fread(&m_highScore,sizeof(int),1,file);
		fclose(file);
	}
}

void CPlay::SaveHighScore(void)
{
	m_highScoreUpdateFlag = FALSE;

	LPSTR folderName = CMySaveFolder::GetFullFolder();
	char filename[1024];
	sprintf_s(filename,1024,"%s\\high.dat",folderName);
	FILE* file = CMyFile::OpenFullPath(filename,"wb");
	if (file != NULL)
	{
		fwrite(&m_highScore,sizeof(int),1,file);
		fclose(file);
	}


}



/*_*/


