/*
 * Weg.h
 *
 *  Created on: Nov 21, 2022
 *      Author: Haesu Kim
 */

//#ifndef WEG_H_
//#define WEG_H_
#pragma once
#include <iostream>
#include <list>
#include <memory>
#include "Simulationsobjekt.h"
#include "Tempolimit.h"
#include "Fahrzeug.h"
#include <iterator>
#include "vertagt_aktion.h"
#include "vertagt_liste.h"

class Fahrzeug;
class Verhalten;

class Weg: public Simulationsobjekt {

protected:
	double p_dLaenge = 0; // in km
	Tempolimit p_eTempolimit = Tempolimit::Autobahn; //setTempolimit erstellen?
	//std::list<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
	vertagt::VListe<std::unique_ptr<Fahrzeug>> p_pFahrzeuge;
public:
	//Weg();
	Weg(std::string name, double wegLaenge, Tempolimit tempoLimit=Tempolimit::Autobahn);//tempo limit default: unbegrenzt(Autobahn)
	virtual ~Weg();

	double getTempolimit() const;

	void vSimulieren() override; //muss es virtuell sein?

	void vAusgeben(std::ostream &o) const override;

	void vKopf() override;

	std::string getName() const;
	double getLaenge() const; // const muss geschrieben werden(should be declared
	//that the method should not make changes to the object)
	//because p_pWeg(in Verhalten) is declared as const

	void vAnnahme(std::unique_ptr<Fahrzeug> Fzg); // Beim Fahren
	void vAnnahme(std::unique_ptr<Fahrzeug> Fzg, double dStartZeitPunkt);//Beim Parken

	std::unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug& aFzg); // returns unique_ptr<Fahrzeug>

};

//#endif /* WEG_H_ */
