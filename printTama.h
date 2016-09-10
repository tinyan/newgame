#if !defined __CMK2008SUMMER_PRINTTAMA__
#define __CMK2008SUMMER_PRINTTAMA__


class CCommonGeneral;
class CPicture;

class CTama;

class CPrintTama
{
public:
	CPrintTama();
	~CPrintTama();
	void End(void);

	void PutTama(int x,int y,int type,int angle);

	void PrintAll(CTama* tama);
private:

	CPicture* m_pic;

};

#endif

/*_*/