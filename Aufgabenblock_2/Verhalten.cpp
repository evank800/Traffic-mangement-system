/*
 * Verhalten.cpp
 *
 *  Created on: Nov 22, 2022
 *      Author: Haesu Kim
 */

#include "Verhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Fahrausnahme.h"
#include "Streckenende.h"

/*
Verhalten::Verhalten() {
	// TODO Auto-generated constructor stub

}
*/
Verhalten::Verhalten(const Weg& weg1):
	p_Weg(weg1){

}
Verhalten::~Verhalten() {
	// TODO Auto-generated destructor stub
}


//--------wie kann weit ein Fahrzeug innerhalb des uebergebenen Zeitintervalls fahren, ohne das Wegende zu ueberschreiten(Fahren)------//
double Verhalten::dStrecke(Fahrzeug& aFzg, double ZeitIntervall){


	if(aFzg.getAbschnittStrecke() <= p_Weg.getLaenge()){//Wenn Weglaenge groesser als der zurueckgelegten Weg des Fahrzeugs...

		if((aFzg.dGeschwindigkeit() * ZeitIntervall) <= (p_Weg.getLaenge() - aFzg.getAbschnittStrecke()))
			return aFzg.dGeschwindigkeit() * ZeitIntervall;
		else{
			return (p_Weg.getLaenge() - aFzg.getAbschnittStrecke());
		}
	}

	else{
		//no return
		throw Streckenende(aFzg, p_Weg);
		return 0;
		//std::cout << "Wegende" << std::endl; //sinvoll hier throw() zu benutzen?

	}
}


double Verhalten::getWegTempolimit() const{
	return p_Weg.getTempolimit();
}
