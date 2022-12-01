/*
 * Fahrrad.h
 *
 *  Created on: Oct 24, 2022
 *      Author: Haesu Kim
 */

//#ifndef FAHRRAD_H_
//#define FAHRRAD_H_
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Fahrzeug.h"


class Fahrrad: public Fahrzeug{

public:
	double dGeschwindigkeit() const;
	Fahrrad(std::string name, double maxGeschwindigkeit);
	virtual ~Fahrrad();

	Fahrrad(Fahrrad &fahrrad) = delete;
	void operator=(const Fahrrad &fahrrad1);

	void vZeichnen(const Weg& weg3) const override;
};

//#endif /* FAHRRAD_H_ */
