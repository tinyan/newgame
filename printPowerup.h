#if !defined __CMK2008SUMMER_PRINTPOWERUP__
#define __CMK2008SUMMER_PRINTPOWERUP__


class CPicture;

class CPowerup;

class CPrintPowerup
{
public:
	CPrintPowerup();
	~CPrintPowerup();
	void End(void);

	void PrintAll(CPowerup* powerup);
private:

	CPicture* m_pic;

};

#endif

/*_*/