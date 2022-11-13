#include "oyuncu.h"

Oyuncu::Oyuncu()
{

}

Oyuncu::Oyuncu(int oyuncuId, QString oyuncuAdi, int skor)
{

}

Nesne* Oyuncu::nesneSec(int index)
{
	return nesneListesi[index];
}

QString Oyuncu::getOyuncuID() const
{
	return oyuncuID;
}

void Oyuncu::setOyuncuID(QString newOyuncuID)
{
	oyuncuID = newOyuncuID;
}

const QString &Oyuncu::getOyuncuAdi() const
{
	return oyuncuAdi;
}

void Oyuncu::setOyuncuAdi(const QString &newOyuncuAdi)
{
	oyuncuAdi = newOyuncuAdi;
}

void Oyuncu::setSkor(int newSkor)
{
	skor = newSkor;
}
