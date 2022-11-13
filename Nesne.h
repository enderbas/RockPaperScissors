#ifndef Nesne_H
#define Nesne_H

#include <QWidget>

class Nesne : public QWidget
{
	Q_OBJECT
public:
	Nesne();
	Nesne(int dayaniklilikP, int seviyePuani);

	enum TURLER {
		TAS,
		KAGIT,
		MAKAS,
		AGIRTAS,
		USTAMAKAS,
		OZELKAGIT,
		NONE
	};

	virtual void super(int dayaniklilik, int seviyePuani);
	virtual QPair<int, int> nesnePuaniGoster();
	virtual double etkiHesapla(Nesne *rakip);
	virtual void durumGuncelle(int etkiDegeri, Nesne *rakip);

	TURLER type = NONE;
	const double aDegeri = 0.2;

	virtual int getKeskinlik() const;
	virtual void setKeskinlik(int newKeskinlik);
	virtual int getKatilik() const;
	virtual void setKatilik(int newKatilik);
	virtual int getNufuz() const;
	virtual void setNufuz(int newNufuz);
	virtual int getDayaniklilik() const;
	virtual void setDayaniklilik(int newDayaniklilik);
	virtual int getSeviye() const;
	virtual void setSeviye(int newSeviye);
	virtual int getDirenc() const;
	virtual void setDirenc(int newDirenc);
	virtual int getKalinlik() const;
	virtual void setKalinlik(int newKalinlik);
	virtual int getSicaklik() const;
	virtual void setSicaklik(int newSicaklik);
	virtual bool getElendiMi() const;
	virtual bool getTerfiEttiMi() const;

private:
	int dayaniklilik = 20;
	int seviye = 0;

	int keskinlik = 0;
	int katilik = 0;
	int nufuz = 0;

	int direnc = 1;
	int kalinlik = 1;
	int sicaklik = 1;

	bool terfiEttiMi = false;
	bool terfiDurdur = false;
};

#endif // Nesne_H
