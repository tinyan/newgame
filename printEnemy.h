#if !defined __CMK2008SUMMER_PRINTENEMY__
#define __CMK2008SUMMER_PRINTENEMY__


class CCommonGeneral;
class CPicture;
class CEnemy;

class CPrintEnemy
{
public:
	CPrintEnemy();
	~CPrintEnemy();
	void End(void);

	void AllPrint(CEnemy* enemy);

	void PutEnemy(int x,int y,int type,int angle);

	void Debug(void);

private:

	CPicture* m_pic;

};

#endif

/*_*/
