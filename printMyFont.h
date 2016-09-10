#if !defined __CMK2008SUMMER_PRINTMYFONT__
#define __CMK2008SUMMER_PRINTMYFONT__


class CCommonGeneral;
class CPicture;

class CPrintMyFont
{
public:
	CPrintMyFont(LPSTR fontName,int sizeX,int sizeY);
	~CPrintMyFont();
	void End(void);

	void PrintSuuji(int x,int y,int data,int keta = 8);
	void PrintMessage(int x,int y,LPSTR mes);

private:
	CPicture* m_pic;
	int m_sizeX;
	int m_sizeY;
};

#endif

/*_*/

