/*
 * Streckenende.cpp
 *
 *  Created on: Nov 29, 2022
 *      Author: Haesu Kim
 */

#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
/*
Streckenende::Streckenende() {
	// TODO Auto-generated constructor stub
}*/

Streckenende::Streckenende(const Fahrzeug& fahrzeug, const Weg& weg):
	Fahrausnahme(fahrzeug, weg){

}

Streckenende::~Streckenende() {
	// TODO Auto-generated destructor stub
}

void Streckenende::vBearbeiten(){
	std::cout << "Streckenende: das Fahrzeug: " << Fzg.getName() << " ist zum Ende des Weges: " << weg.getName() << " gekommen" << std::endl;
}
