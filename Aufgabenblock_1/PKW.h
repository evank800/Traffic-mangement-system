/*
 * PKW.h
 *
 *  Created on: Oct 24, 2022
 *      Author: Haesu Kim
 */

#ifndef PKW_H_
#define PKW_H_
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "Fahrzeug.h"

class PKW: public Fahrzeug{

private:
	double p_dVerbrauch = 0; // L/100km
	double p_dTankvolumen = 0; //L
	double p_dTankinhalt = 0; //L
public:
	PKW();
	PKW(std::string name, double max_geschwindigkeit, double verbrauch, double tankvolumen);
	virtual ~PKW();
	double dTanken(double dMenge) override;
	void vSimulieren() override;
	void vAusgeben(std::ostream& o) const override;
	PKW(PKW &pkw) = delete;
	void operator=(const PKW& pkw1);
};

#endif /* PKW_H_ */
