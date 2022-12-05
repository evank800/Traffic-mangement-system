/*
 * Parken.cpp
 *
 *  Created on: Nov 29, 2022
 *      Author: evank
 */

#include "Parken.h"
#include <math.h>
#include "Fahrzeug.h"
#include "Losfahren.h"

Parken::Parken(Weg& weg1, double dStartZeitPunkt):
	Verhalten(weg1), p_dStartZeitPunkt(dStartZeitPunkt){
	// TODO Auto-generated constructor stub

}

Parken::~Parken() {
	// TODO Auto-generated destructor stub
}

double Parken::dStrecke(Fahrzeug& aFzg, double ZeitIntervall){
	/*if(fabs(dGlobaleZeit - p_dStartZeitPunkt) < 0.001){
		std::cout << "das Fahrzeug fahrt los" << std:: endl;
	}
	else{
		return 0.0;
	}*/
	/*
	if(dGlobaleZeit < p_dStartZeitPunkt){
		return 0.0;
	}*/
	/*
	if(fabs(dGlobaleZeit - p_dStartZeitPunkt) < 0.001){
		throw Losfahren(aFzg, p_Weg);
	}
	else{
		return 0;
		//std::cout << "das Fahrzeug faehrt los" << std::endl;
	}*/

	if(dGlobaleZeit < p_dStartZeitPunkt){
		return 0;
	}
	else{
		throw Losfahren(aFzg, p_Weg);
	}
}
