/*
 * Fahrzeug.h
 *
 *  Created on: Oct 19, 2022
 *      Author: Haesu Kim
 */

//#ifndef FAHRZEUG_H_
//#define FAHRZEUG_H_
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <memory>
#include "Verhalten.h"
#include "Simulationsobjekt.h"
#include "Fahren.h"
#include "Parken.h"
//#include "Weg.h"



extern double dGlobaleZeit;

class Verhalten;
class Weg;
class Fahren;
class Parken;

class Fahrzeug: public Simulationsobjekt{
private:
	//static inline int p_iMaxID = 0;//p_iMaxID muessen die Abgeleitete Klassen nicht zugreifen koennen


protected:
	std::unique_ptr<Verhalten> p_pVerhalten;// objekt einer Verhalten Klasse
	//std::string p_sName = "";
	//const int p_iID;
	double p_dMaxGeschwindigkeit = 0; // in km/h
	double p_dGesamtStrecke = 0;// in km
	double p_dGesamtZeit = 0; // in h
	//double p_dZeit = 0; // Zeitmarke der letzten Simulationsschritt/ in h
	double p_dAbschnittStrecke = 0; // auf dem aktuellen Weg zurueckgelegte Strecke(nicht Gesamtstrecke!!!)

public:
	Fahrzeug();
	Fahrzeug(std::string name);// Konstruktor, der den Namen initialisiert
	Fahrzeug(std::string name, double max_geschwindigkeit);//mit Namen/Max.Geschwindigkeit
	virtual ~Fahrzeug();

	// Copy-Konstruktor
	Fahrzeug(Fahrzeug &fahrzeug) = delete;

	//Virtualfunktionen werden bei Abgeleitete Klasse(z.B PKW) ueberschrieben
	virtual void vAusgeben(std::ostream& o) const override;//override?
	virtual void vKopf() override;
	virtual void vSimulieren() override;

	virtual double dTanken(double dMenge);
	virtual double dGeschwindigkeit() const;

	bool operator<(const Fahrzeug& Fahrzeug2);
	void operator=(const Fahrzeug& Fahrzeug3);

	virtual std::string getName() const; // 'const' hinzugefuegt. es sagt, dass sich 'const Fahrzeug& Fzg' innerhalb dieser funktion nicht aendern wird

	double getAbschnittStrecke();

	void vNeueStrecke(Weg& weg2);
	void vNeueStrecke(Weg& weg2, double dStartZeitPunkt);

	virtual void vZeichnen(const Weg& weg3) const = 0;
};

//std::ostream& operator<<(std::ostream& o, const Fahrzeug& Fahrzeug1);

//#endif /* FAHRZEUG_H_ */

