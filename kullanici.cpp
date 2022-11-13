#include "kullanici.h"

Kullanici::Kullanici()
{

}

Kullanici::Kullanici(int oyuncuId, QString oyuncuAdi, int skor)
{
	oyuncuIdk = oyuncuId;
	oyuncuAdiK = oyuncuAdi;
	skorK = skor;
	super();
}

void Kullanici::super()
{
	setOyuncuID(oyuncuIdk);
	setOyuncuAdi(oyuncuAdiK);
}
