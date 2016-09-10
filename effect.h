#if !defined __CMK2008SUMMER_EFFECT__
#define __CMK2008SUMMER_EFFECT__


typedef struct _tagMYEFFECT
{
	BOOL flag;
	int type;
	int count;
	int x,y;
}MYEFFECT;

class CMyEffect
{
public:
	CMyEffect();
	~CMyEffect();
	void End(void);

	void Clear(void);

	void AddEffect(int x,int y);
	void Calcu(void);

	int GetEffectMax(void){return m_effectMax;}
	MYEFFECT* GetEffect(int n){return &(m_effect[n]);}
private:
	int m_effectMax;
	MYEFFECT* m_effect;

};

#endif

/*_*/