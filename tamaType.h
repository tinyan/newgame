#if !defined __TINYAN_NEWGAME_TAMATYPE__
#define __TINYAN_NEWGAME_TAMATYPE__

class CNameList;


class CTamaType
{
public:
	CTamaType();
	~CTamaType();
	void End(void);

	int GetTamaNumber(int type,int level);
	int GetTamaMulti(int type,int level);
	POINT GetTamaDelta(int type,int level,int k);
	int GetTamaPic(int type,int level,int k);
	POINT GetTamaSpeed(int type,int level,int k);
//	int GetTamaAngle(int type,int level);
	SIZE GetHitSize(int type,int level,int k);
	int GetTamaAttack(int type,int level,int k);
	int GetTamaLaser(int type,int level,int k);

	int GetAutoFireLimit(int type,int level);

private:
	CNameList* m_list;
	int* m_data;
};

#endif
/*_*/

