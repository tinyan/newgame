#if !defined __CMK2008SUMMER_TAMA__
#define __CMK2008SUMMER_TAMA__


class CCommonGeneral;
class CTamaType;

typedef struct _tagTAMA
{
	BOOL flag;
	int type;
	int x,y;
	int angle;
	int picType;
	int speedX,speedY;
	int attack;
	int laser;
	SIZE hitSize;
} TAMA;

class CTama
{
public:
	CTama();
	~CTama();
	void End(void);

	void Clear(void);

	TAMA* m_tama;

	void AddTama(int type,int level,int x,int y);

	int GetTamaMax(void){return m_tamaMax;}
	TAMA* GetTama(int n){return &(m_tama[n]);}

	int GetTypeCount(int type);
	void Move(void);

	int GetAutoFireLimit(int type,int level);
	BOOL CheckCanNewTama(int type,int level);

private:
	int m_tamaMax;
	BOOL CheckAki(int count);
	int SearchAki(void);
	BOOL CheckOutOfRange(int x,int y);

	CTamaType* m_tamaType;

};

#endif

/*_*/


