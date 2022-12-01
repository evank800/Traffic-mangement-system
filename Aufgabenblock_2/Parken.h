/*
 * Parken.h
 *
 *  Created on: Nov 29, 2022
 *      Author: evank
 */

#ifndef PARKEN_H_
#define PARKEN_H_
#include "Verhalten.h"

class Weg;
class Fahrzeug;

class Parken: public Verhalten {
private:
	double p_dStartZeitPunkt = 0;
public:
	Parken(const Weg& weg1, double dStartZeitPunkt);
	virtual ~Parken();
	double dStrecke(Fahrzeug& aFzg, double ZeitIntervall) override;
};

#endif /* PARKEN_H_ */
