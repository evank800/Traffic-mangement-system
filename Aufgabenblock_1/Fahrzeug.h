/*
 * Fahrzeug.h
 *
 *  Created on: Oct 19, 2022
 *      Author: Haesu Kim
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <iostream>
#include <string>
#include <iomanip>

extern double dGlobaleZeit;

class Fahrzeug {
private:
	static inline int p_iMaxID = 0;//p_iMaxID muessen die Abgeleitete Klassen nicht zugreifen koennen


protected:

	std::string p_sName = "";
	const int p_iID;
	double p_dMaxGeschwindigkeit = 0; // in km/h
	double p_dGesamtStrecke = 0;// in km
	double p_dGesamtZeit = 0; // in h
	double p_dZeit = 0; // Zeitmarke der letzten Simulationsschritt/ in h

public:
	Fahrzeug();
	Fahrzeug(std::string name);// Konstruktor, der den Namen initialisiert
	Fahrzeug(std::string name, double max_geschwindigkeit);//mit Namen/Max.Geschwindigkeit
	virtual ~Fahrzeug();

	// Copy-Konstruktor
	Fahrzeug(Fahrzeug &fahrzeug) = delete;

	//Virtualfunktionen werden bei Abgeleitete Klasse(z.B PKW) ueberschrieben
	virtual void vAusgeben(std::ostream& o) const;
	virtual void vKopf();
	virtual void vSimulieren();

	virtual double dTanken(double dMenge);
	virtual double dGeschwindigkeit() const;

	bool operator<(const Fahrzeug& Fahrzeug2);
	void operator=(const Fahrzeug& Fahrzeug3);
};

std::ostream& operator<<(std::ostream& o, const Fahrzeug& Fahrzeug1);

#endif /* FAHRZEUG_H_ */

