/*
 * Losfahren.h
 *
 *  Created on: Nov 29, 2022
 *      Author: evank
 */

#ifndef LOSFAHREN_H_
#define LOSFAHREN_H_
#include "Fahrausnahme.h"
class Fahrzeug;
class Weg;

class Losfahren: public Fahrausnahme {
public:
	//Losfahren();
	Losfahren(const Fahrzeug& fahrzeug, const Weg& weg);
	virtual ~Losfahren();
	void vBearbeiten() override;
};

#endif /* LOSFAHREN_H_ */
