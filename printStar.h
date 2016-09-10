#if !defined __TINYAN_NEWGAME_PRINTSTAR__
#define __TINYAN_NEWGAME_PRINTSTAR__


class CPrintStar
{
public:
	CPrintStar();
	~CPrintStar();
	void End(void);

	void Create(void);
	void Move(void);
	void ReverseMove(void);
	void Print(void);

	int m_mod;

	int* m_zahyo;
	int m_max;
	static int m_colorData[];
	int m_color[16];

private:
};

#endif
/*_*/
