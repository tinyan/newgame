#include <windows.h>
#include <math.h>


#include "..\..\systemNNN\nyanlib\include\commonMacro.h"
#include "..\..\systemNNN\nyanlib\include\areaControl.h"
#include "..\..\systemNNN\nyanlib\include\picture.h"

#include "enemy.h"
#include "printEnemy.h"


CPrintEnemy::CPrintEnemy()
{
	m_pic = new CPicture("sys\\ta_pantu");


	int* buf = (int*)(m_pic->GetBuffer());
	char* mask = (char*)(m_pic->GetMaskPic());
	int pitch = (m_pic->GetPicSize()).cx;

	for (int y=0;y<8;y++)
	{
		for (int x=1;x<16;x++)
		{
			double th = (double)x;
			th /= 16.0;
			th *= 3.14159 * 2.0;
			th *= -1.0;

			double c = cos(th);
			double s = sin(th);

			int fromX = 0;
			int fromY = 64 * y;


			for (int j=0;j<64;j++)
			{
				for (int i=0;i<64;i++)
				{
					int toX = x * 64 + i;
					int toY = y * 64 + j;

					int dx = i - 32;
					int dy = j - 32;

					int fromDX = (int)(c * dx - s * dy + 32);
					int fromDY = (int)(s * dx + c * dy + 32);
					int col = 0;
					char a = 0;
					if ((fromDX >= 0) && (fromDX < 64) && (fromDY >=0) && (fromDY<64))
					{
						col = *(buf + fromX + fromDX + (fromY + fromDY) * pitch);
						a = *(mask + fromX + fromDX + (fromY + fromDY) * pitch);
					}

			//		col = 0x123456;
			//		a = 0xff;

					*(buf + toX + toY * pitch) = col;
					*(mask + toX + toY * pitch) = a;
				}
			}
		}
	}


}

CPrintEnemy::~CPrintEnemy()
{
	End();
}

void CPrintEnemy::End(void)
{
	ENDDELETECLASS(m_pic);
}


void CPrintEnemy::PutEnemy(int x,int y,int type,int angle)
{
	int sizeX = 64;
	int sizeY = 64;

	int srcX = (angle * 16 + 11) / 360;
	srcX += 12;
	srcX += 16;
	srcX %= 16;
	srcX *= sizeX;
	int srcY = type;
	srcY *= sizeY;
	int putX = x - sizeX / 2;
	int putY = y - sizeY / 2;

	m_pic->Blt(putX,putY,srcX,srcY,sizeX,sizeY,TRUE);

}


void CPrintEnemy::Debug(void)
{
	m_pic->Put(0,0,TRUE);
}

void CPrintEnemy::AllPrint(CEnemy* enemy)
{
	int loop = enemy->GetEnemyNumber();

	for (int i=0;i<loop;i++)
	{
		ENEMY* enemyWork = enemy->GetEnemy(i);

		if (enemyWork->flag)
		{
			if (enemyWork->wait <= 0)
			{
				int pic = enemyWork->pic;
				int x = (int)enemyWork->x;
				int y = (int)enemyWork->y;
				int angle = (int)enemyWork->angle;

				PutEnemy(x,y,pic,angle);
			}
		}

	}
}

/*_*/

