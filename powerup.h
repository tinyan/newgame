#if !defined __CMK2008SUMMER_POWERUP__
#define __CMK2008SUMMER_POWERUP__




class CPowerup
{
public:
	CPowerup();
	~CPowerup();
	void End(void);

	void Clear(void);

	void GetItem(int type);
	int GetType(void){return m_select;}
	int GetLevel(int type){return m_level[type];}
private:
	int m_select;
	int m_level[4];

};

#endif

/*_*/


