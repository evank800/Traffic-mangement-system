/*
 * Fahrzeug.cpp
 *
 *  Created on: Oct 19, 2022
 *      Author: Haesu Kim
 */
#include <iostream>
#include "Fahrzeug.h"


/*

//--------------------Konstruktor ohne Parametern---------------------//
Fahrzeug::Fahrzeug() :
		p_sName(""), p_iID(p_iMaxID++){

	std::cout << "Das Fahrzeug: " << p_sName << " mit ID: " << p_iID << " wurde erstellt"<< std::endl;

}

//-----------------Konstruktor mit einem Parameter(name)-----------------//
Fahrzeug::Fahrzeug(std::string name):
		p_sName(name), p_iID(p_iMaxID++){

	std::cout << "Das Fahrzeug: " << p_sName << " mit ID: " << p_iID << " wurde erstellt" << std::endl;
}

//--------------------Konstruktor mit zwei Parametern(name, max.geschw.)------------------//
Fahrzeug::Fahrzeug(std::string name, double max_geschwindigkeit):
		p_sName(name),  p_iID(p_iMaxID++), p_dMaxGeschwindigkeit((max_geschwindigkeit > 0) ? max_geschwindigkeit : (max_geschwindigkeit *= -1)){//Vorzeichen der Geschw. wird geprueft und ergibt positive Werte

}
*/
Fahrzeug::Fahrzeug(std::string name):
		Simulationsobjekt(name){

	//std::cout << "Das Fahrzeug: " << p_sName << " mit ID: " << p_iID << " wurde erstellt" << std::endl;
}

Fahrzeug::Fahrzeug(std::string name, double max_geschwindigkeit):
		Simulationsobjekt(name), p_dMaxGeschwindigkeit((max_geschwindigkeit > 0) ? max_geschwindigkeit : (max_geschwindigkeit *= -1)){

}

/*
//--------------------Dekonstruktor-------------------//
Fahrzeug::~Fahrzeug() {

	std::cout << "Das Fahrzeug: " << p_sName << " mit ID: " << p_iID << " wurde geloescht" << std::endl;
}
*/
Fahrzeug::~Fahrzeug() {

}
/*
//------------------Funktion zum Ausgeben der Daten eines Fahrzeuges-----------------//
void Fahrzeug::vAusgeben(std::ostream& o) const{

	o << std::fixed;
	o << std::setprecision(2);
    o << std::resetiosflags(std::ios::left);
	o << std::setiosflags(std::ios::right) << p_iID
		<<std::setw(20)<< p_sName << std::setw(20) << p_dMaxGeschwindigkeit << std::setw(30)
		<< dGeschwindigkeit() << std::setw(30)<< p_dGesamtStrecke;
}
*/

void Fahrzeug::vAusgeben(std::ostream& o) const{


	Simulationsobjekt::vAusgeben(o);
		o << std::setw(20) << p_dMaxGeschwindigkeit << std::setw(30)
		<< dGeschwindigkeit() << std::setw(30)<< p_dGesamtStrecke;
}
//---------------Funktion zur Ueberschrift der Ausgaben------------------//
void Fahrzeug::vKopf(){

	std::cout << std::resetiosflags(std::ios::left);
		std::cout << std::setiosflags(std::ios::right) // right-alinged Werte
			<< "ID" << std::setw(20) <<"Name" << std::setw(30) << "MaxGeschwindigkeit(km/h)"
			<< std::setw(30) << "Akt.Geschwindigkeit(km)" << std::setw(30) << "Gesamtstrecke(km)" << std::setw(30) << "GesamtVerbrauch(L)"
			<< std::setw(30) << "Tankinhalt(L)"<< std::endl;
	std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
}

/*
//------------------Simulationsfunktion eines Fahrzeuges---------------------//
void Fahrzeug::vSimulieren(){

	double dZwischenZeit = dGlobaleZeit - p_dZeit;//Akt.Zeit - letzte Zeitmarke
	double dZwischenStrecke = dZwischenZeit * dGeschwindigkeit();
	p_dGesamtStrecke += dZwischenStrecke;
	p_dGesamtZeit += dZwischenZeit;
	p_dZeit = dGlobaleZeit;
}
*/

//------------------Simulationsfunktion eines Fahrzeuges---------------------//
void Fahrzeug::vSimulieren(){
	double dZwischenZeit = dGlobaleZeit - p_dZeit;

	if(p_pVerhalten != nullptr){
		double dGefahren = p_pVerhalten -> dStrecke(*this, dZwischenZeit);//'this' muss dereferenziert werden
		p_dAbschnittStrecke += dGefahren;
		p_dGesamtStrecke += dGefahren;
	}

	p_dGesamtZeit += dZwischenZeit;
	p_dZeit = dGlobaleZeit;
}

//---------------Funktion zur Menge ,die zu tanken ist------------------------//
double Fahrzeug::dTanken(double dMenge){

	return 0;
}

//------------Funktion zur Rueckgabe der aktuellen Geschwindigkeit------------//
double Fahrzeug::dGeschwindigkeit() const{
	return p_dMaxGeschwindigkeit; //default
}



/*
//-------------Ueberladung von '<<' operator fuer vAusgeben()----------//
std::ostream& operator<<(std::ostream& o, const Fahrzeug& Fahrzeug1){

	Fahrzeug1.vAusgeben(o);
	std::cout << "" << std::endl;
	return o;
}
*/


//--------------Ueberladungvon '<' Operator---------------//
bool Fahrzeug::operator<(const Fahrzeug& Fahrzeug2){

	if(this -> p_dGesamtStrecke < Fahrzeug2.p_dGesamtStrecke){
		return true;
	}
	else{
		return false;
	}
}

//---------------Ueberladung von '=' Operator----------------//
void Fahrzeug::operator=(const Fahrzeug& Fahrzeug3){
	this -> p_sName = Fahrzeug3.p_sName;
	this -> p_dMaxGeschwindigkeit = Fahrzeug3.p_dMaxGeschwindigkeit;
}


std::string Fahrzeug::getName() const{
	return p_sName;
}

double Fahrzeug::getAbschnittStrecke(){
	return p_dAbschnittStrecke;
}

//----------------zum Fahren------------------//
void Fahrzeug::vNeueStrecke(Weg& weg2){
	//Verhalten verhalten1(weg2);// should be a pointer
	//p_pVerhalten = std::make_unique<Verhalten>(weg2); //Konstruktor nimmt Weg Objekt als parameter auf
	p_pVerhalten = std::make_unique<Fahren>(weg2);
	p_dAbschnittStrecke = 0;
	p_dZeit = dGlobaleZeit;
}


void Fahrzeug::vNeueStrecke(Weg& weg2, double dStartZeitPunkt){
	p_pVerhalten = std::make_unique<Parken>(weg2, dStartZeitPunkt);
	p_dAbschnittStrecke = 0;
	p_dZeit = dGlobaleZeit;
}

