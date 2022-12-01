/*
 * Verhalten.h
 *
 *  Created on: Nov 22, 2022
 *      Author: Haesu Kim
 */

//#ifndef VERHALTEN_H_
//#define VERHALTEN_H_
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <list>
//#include "Fahrzeug.h"
//#include "Weg.h"

class Fahrausnahme;
class Fahrzeug;
class Weg;

class Verhalten {

protected:
	const Weg& p_Weg;
public:
	Verhalten();
	Verhalten(const Weg &weg1);//Verhalten haengt vom Weg an
	virtual ~Verhalten();

	//double dStrecke(Fahrzeug& aFzg, double ZeitIntervall);//ermittelt wie weit ein Fahrzeug innerhalb
	//des ueberigebene Zeitintervalls fahren kann, ohne das Wegende zu ueberschreiten
	virtual double dStrecke(Fahrzeug& aFzg, double Zeitintervall);

	double getWegTempolimit() const;
};

//#endif /* VERHALTEN_H_ */
