

#if !defined __CMK2008SUMMER_PLAY__
#define __CMK2008SUMMER_PLAY__


class CCommonGeneral;
class CGame;
class CPicture;

class CMyMessage;

class CNameList;

class CPrintEnemy;
class CPrintTama;
class CPrintItem;
class CPrintPowerup;
class CPrintEffect;
class CPrintStar;
class CPrintZanki;
class CPrintStage;


class CTama;
class CEnemy;
class CPowerup;
class CItem;
class CMyEffect;

class CPrintMyFont;

class CPlay : public CCommonGeneral
{
public:
	CPlay(CGame* lpGame);
	~CPlay();
	void End(void);

	int Init(void);
	int Calcu(void);
	int Print(void);


	void FinalExitRoutine(void);

	int m_zanki;

	int m_jikiX;
	int m_jikiY;

	int m_score;
	int m_highScore;
	int m_stage;
	int m_stageMax;

	int m_average;
	int m_numberOfHit;
	int m_bonus;

	int m_autoFireLimit;
	int m_autoFireCount;
private:
	CGame* m_game2;
	CMyMessage* m_message;

	CPrintMyFont* m_printFont32;
	CPrintMyFont* m_printFont64;

	CPicture* m_jiki;
	//CPicture* m_font;
	//CPicture* m_font32;

	CPrintEnemy* m_printEnemy;
	CPrintTama* m_printTama;
	CPrintItem* m_printItem;
	CPrintPowerup* m_printPowerup;
	CPrintEffect* m_printEffect;

	CPrintStar* m_printStar;
	CPrintZanki* m_printZanki;
	CPrintStage* m_printStage;

	CTama* m_tama;
	CEnemy* m_enemy;
	CPowerup* m_powerup;
	CItem* m_item;
	CMyEffect* m_effect;

	int m_stageLoop;


	int m_perfectNumber;

	void NewStage(void);
	BOOL NextStage(void);

	int m_playMode;

	int CalcuStageStart(void);
	int CalcuGamePlay(void);
	int CalcuStageClear(void);
	int CalcuGameover(void);

	void PrintStageStart(void);
	void PrintGamePlay(void);
	void PrintStageClear(void);
	void PrintGameover(void);


	void StartStartStage(void);
	void StartPlay(void);
	void StartStageClear(void);
	void StartGameover(void);

	int m_count;
	int m_oneup;

	void AddScore(int point);

	void CheckGetPowerup(void);

	BOOL CheckStageEnd(void);

	void GetAutoFireLimit(void);

	void FireRoutine(void);

	void GetItemRoutine(int type);
//	void PrintScore(int x,int y,int score);
//	void PrintMessage32(int x,int y,LPSTR mes);

	void MoveJiki(void);
	void CheckHit(void);
	void AddEffect(int x,int y);
	void CheckFire(void);

	int m_hitSoundBuffer;
	void PlayHitSound(void);
	int m_fireSoundBuffer;
	void PlayFireSound(int n);
	void PlayKinSound(void);

	BOOL m_highScoreUpdateFlag;
	void LoadHighScore(void);
	void SaveHighScore(void);


};






#endif
/*_*/

