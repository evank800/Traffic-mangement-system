/*
 * Simulationsobjekt.h
 *
 *  Created on: 21 Nov 2022
 *      Author: Haesu Kim
 */

//#ifndef SIMULATIONSOBJEKT_H_
//#define SIMULATIONSOBJEKT_H_
#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Simulationsobjekt {

protected:
	std::string p_sName = "";
	//const int p_iID; // sollte es initialisiert werden?
	double p_dZeit = 0;
private:
	static inline int p_iMaxID = 0;
	const int p_iID = 0; // sollte es initialisiert werden?
public:
	Simulationsobjekt();
	Simulationsobjekt(std::string name);
	virtual ~Simulationsobjekt();

	// Copy-Konstruktor
	Simulationsobjekt(Simulationsobjekt &Simulationsobjekt) = delete;

	//rein virtuell?
	virtual void vKopf() = 0;
	virtual void vSimulieren() = 0;
	//virtuell, aber nicht rein
	virtual void vAusgeben(std::ostream& o) const;

	//p_iID Vergleichen
	bool operator==(const Simulationsobjekt &simObj1) const;

	//getID()
	int getID() const;
};

//-------"<<" Operator Ueberladung---------------//
std::ostream& operator<<(std::ostream& o, const Simulationsobjekt &simObj2);

//#endif /* SIMULATIONSOBJEKT_H_ */
