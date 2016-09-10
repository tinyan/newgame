#if !defined __TINYAN_NEWGAME_PRINTZANKI__
#define __TINYAN_NEWGAME_PRINTZANKI__

class CPicture;

class CPrintZanki
{
public:
	CPrintZanki();
	~CPrintZanki();
	void End(void);

	void Print(int zanki);
private:
	CPicture* m_pic;

};

#endif
/*_*/
