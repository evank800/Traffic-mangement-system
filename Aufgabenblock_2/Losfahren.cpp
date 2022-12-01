/*
 * Losfahren.cpp
 *
 *  Created on: Nov 29, 2022
 *      Author: Haesu Kim
 */

#include "Losfahren.h"
/*
Losfahren::Losfahren() {
	// TODO Auto-generated constructor stub

}*/
Losfahren::Losfahren(const Fahrzeug& fahrzeug, const Weg& weg):
	Fahrausnahme(fahrzeug, weg){

}

Losfahren::~Losfahren() {
	// TODO Auto-generated destructor stub
}

void Losfahren::vBearbeiten(){
	std::cout << "Losfahren: das Fahrzeug: " << Fzg.getName() << " faehrt jetzt auf dem Weg: " << weg.getName() << " los" << std::endl;
}
