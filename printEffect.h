#if !defined __CMK2008SUMMER_PRINTEFFECT__
#define __CMK2008SUMMER_PRINTEFFECT__


class CCommonGeneral;
class CPicture;

class CMyEffect;

class CPrintEffect
{
public:
	CPrintEffect();
	~CPrintEffect();
	void End(void);

	void PrintAll(CMyEffect* effect);
	void PutEffect(int x,int y,int type,int anime);


private:

	CPicture* m_pic;

};

#endif

/*_*/
