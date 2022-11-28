#ifndef OYUNCU_H
#define OYUNCU_H

#include "nesne.h"
#include <QString>

class Oyuncu
{
public:
	Oyuncu();
	Oyuncu(int oyuncuId, QString oyuncuAdi, int skor);

	QList<Nesne*> nesneListesi;
	int skorGoster() { return skor; }
	virtual Nesne *nesneSec(int index);

	QString getOyuncuID() const;
	void setOyuncuID(QString newOyuncuID);
	const QString &getOyuncuAdi() const;
	void setOyuncuAdi(const QString &newOyuncuAdi);
	QList<int> elenenNesneler;
	QList<int> blokluNesneler;

	void setSkor(int newSkor);

private:
	QString oyuncuID;
	QString oyuncuAdi;
	int skor = 0;
};

#endif // OYUNCU_H
