#if !defined __CMK2008SUMMER_ITEM__
#define __CMK2008SUMMER_ITEM__


typedef struct _tagITEM
{
	BOOL flag;
	int type;
	int x,y;
//	int angle;
	int picType;
	int speedX,speedY;
} ITEM;

class CItem
{
public:
	CItem();
	~CItem();
	void End(void);

	void Clear(void);

	ITEM* m_item;

	int GetItemMax(void){return m_itemMax;}
	ITEM* GetItem(int n){return &(m_item[n]);}

	BOOL CheckStageClear(void);
	void Move(void);

	void AddItem(int type,int x,int y);
private:
	int m_itemMax;

	BOOL CheckOutOfRange(int x,int y);

};

#endif

/*_*/