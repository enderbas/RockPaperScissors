#include "bilgisayar.h"

Bilgisayar::Bilgisayar()
{

}

Bilgisayar::Bilgisayar(QString oyuncuId, QString oyuncuAdi, int skor)
{
	oyuncuIdpc = oyuncuId;
	oyuncuAdipc = oyuncuAdi;
	skorPc = skor;
	super();
}

void Bilgisayar::super()
{
	setOyuncuID(oyuncuIdpc);
	setOyuncuAdi(oyuncuAdipc);
}
