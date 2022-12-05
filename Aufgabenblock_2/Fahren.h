/*
 * Fahren.h
 *
 *  Created on: Nov 29, 2022
 *      Author: evank
 */

#ifndef FAHREN_H_
#define FAHREN_H_

#include "Verhalten.h"

class Weg;
class Fahrzeug;

class Fahren: public Verhalten { // speichert auch Wege(Da unterklasse ist)
public:
	Fahren(Weg& weg1);
	virtual ~Fahren();

};

#endif /* FAHREN_H_ */
