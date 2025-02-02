/*
 * Fahrausnahme.h
 *
 *  Created on: Nov 29, 2022
 *      Author: Haesu Kim
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_
#include <exception> // Vorteile?
#include "Fahrzeug.h"
#include "Weg.h"

class Fahrzeug;
class Weg;

class Fahrausnahme: std::exception { // or from std::runtime_error?
protected:
	Fahrzeug& Fzg;
	Weg& weg;
public:
	//Fahrausnahme();
	Fahrausnahme(Fahrzeug& fahrzeug, Weg& weg);
	virtual ~Fahrausnahme();
	virtual void vBearbeiten() = 0;//rein virtuell
};

#endif /* FAHRAUSNAHME_H_ */
