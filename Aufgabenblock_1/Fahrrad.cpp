/*
 * Fahrrad.cpp
 *
 *  Created on: Oct 24, 2022
 *      Author: Haesu Kim
 */

#include "Fahrrad.h"
#include <math.h>

//-----------Konstruktor mit 2 Parameter----------//
Fahrrad::Fahrrad(std::string name, double maxGeschwindigkeit):
	Fahrzeug(name, maxGeschwindigkeit){

}

//-----------Dekonstruktor------------//
Fahrrad::~Fahrrad() {

}

//------------Funktion zur Rueckgabe der aktuellen Geschwindigkeit(ueberschrieben)-------------//
double Fahrrad::dGeschwindigkeit()const{
	int counter = std::floor(p_dGesamtStrecke/20);
	double dGeschwindigkeit = p_dMaxGeschwindigkeit;

	//Jede 20km, Geschwindigkeit um 10% abnehmen
	for(int i = 0; i < counter; i++){
		if((dGeschwindigkeit * 0.9) > 12){ //Abgenommene Geschwindigkeit kleiner als 12km/h => nicht mehr abnehmen
			dGeschwindigkeit *=0.9;
		}
	}
	return dGeschwindigkeit;
}

//---------------Ueberladung von '=' Operator----------------//
void Fahrrad::operator=(const Fahrrad& fahrrad1){
	this -> p_sName = fahrrad1.p_sName;
	this -> p_dMaxGeschwindigkeit = fahrrad1.p_dMaxGeschwindigkeit;
}


