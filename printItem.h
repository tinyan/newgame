#if !defined __CMK2008SUMMER_PRINTITEM__
#define __CMK2008SUMMER_PRINTITEM__


class CCommonGeneral;
class CPicture;

class CItem;

class CPrintItem
{
public:
	CPrintItem();
	~CPrintItem();
	void End(void);

	void PutItem(int x,int y,int type);

	void PrintAll(CItem* item);
private:

	CPicture* m_pic;

};

#endif

/*_*/