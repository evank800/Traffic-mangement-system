/*
 * Simulationsobjekt.cpp
 *
 *  Created on: 21 Nov 2022
 *      Author: Haesu Kim
 */

#include "Simulationsobjekt.h"


Simulationsobjekt::Simulationsobjekt(std::string name):
	p_sName(name), p_iID(p_iMaxID++){
	//std::cout << "Das Objekt: " << p_sName << " mit ID: " << p_iID << " wurde erstellt" << std::endl;
	std::cout << "Das Objekt: " << p_sName << " mit ID: " << getID() << " wurde erstellt" << std::endl;
}

Simulationsobjekt::~Simulationsobjekt() {
	// TODO Auto-generated destructor stub
	//std::cout << "Das Objekt: " << p_sName << " mit ID: " << p_iID << " wurde geloescht" << std::endl;
	std::cout << "Das Objekt: " << p_sName << " mit ID: " << getID() << " wurde geloescht" << std::endl;
}

bool Simulationsobjekt::operator ==(const Simulationsobjekt &simObj) const {
	//if((this -> p_iID) == simObj.p_iID)
	if((this -> getID()) == simObj.getID()){
		return true;
	}
	else{
		return false;
	}
}

void Simulationsobjekt::vAusgeben(std::ostream& o) const{
	o << std::fixed;
	o << std::setprecision(2);
	o << std::resetiosflags(std::ios::left);
	o << std::setiosflags(std::ios::right) << getID() //p_iID
		<<std::setw(20)<< p_sName;
}

std::ostream& operator<<(std::ostream& o, const Simulationsobjekt &simObj2){
	simObj2.vAusgeben(o);
	std::cout << "" << std::endl;
	return o;
}

int Simulationsobjekt::getID() const{
	return p_iID;
}
