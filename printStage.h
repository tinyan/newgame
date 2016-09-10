#if !defined __TINYAN_NEWGAME_PRINTSTAGE__
#define __TINYAN_NEWGAME_PRINTSTAGE__


class CPicture;
class CPrintStage
{
public:
	CPrintStage();
	~CPrintStage();
	void End(void);

	void Print(int stage,int x=8,int y=532);
private:
	CPicture* m_pic;
};

#endif
/*_*/

