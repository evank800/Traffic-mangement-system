/*
 * Streckenende.h
 *
 *  Created on: Nov 29, 2022
 *      Author: evank
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_
#include "Fahrausnahme.h"
class Fahrzeug;
class Weg;

class Streckenende: public Fahrausnahme {
public:
	//Streckenende();
	Streckenende(const Fahrzeug& fahrzeug, const Weg& weg);
	virtual ~Streckenende();
	void vBearbeiten() override;
};

#endif /* STRECKENENDE_H_ */
