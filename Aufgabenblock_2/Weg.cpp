/*
 * Weg.cpp
 *
 *  Created on: Nov 21, 2022
 *      Author: Haesu Kim
 */
#include "Weg.h"
#include "Streckenende.h"
#include "Losfahren.h"

//muss noch initialisiert werden
/*
Weg::Weg(){
	// TODO Auto-generated constructor stub
}*/

Weg::Weg(std::string name, double wegLaenge, Tempolimit tempoLimit):
		Simulationsobjekt(name), p_dLaenge(wegLaenge), p_eTempolimit(tempoLimit){
}

Weg::~Weg() {
	// TODO Auto-generated destructor stub
}

double Weg::getTempolimit() const{
	double converted = (double)(p_eTempolimit);// explizit Datentyp verwandeln
	return converted;
}

void Weg::vSimulieren(){
	//-----------Alle auf dem Weg befindlichen Fahrzeuge werden simuliert----------//
	for(auto& i: p_pFahrzeuge){
		//i -> vSimulieren();
		try{
			i -> vSimulieren(); // Verhalten:: bzw. Parken::dStrecke() in Fahrzeug::vSimulieren() enthalten / in dStrecke() wird 'throw' aufgerufen
		}

		//2 Arten von 'catch'
		/*
		catch(Streckenende& Ende){
			Ende.vBearbeiten();
		}
		catch(Losfahren& Los){
			Los.vBearbeiten();
		}*/

		//Aber die beiden Faellen nur mit einem 'catch' block fangen

		catch(Fahrausnahme& fahrausnahme){ // faengt alle Ableitungen davon und mittels Polymorphie bearbeiten
			fahrausnahme.vBearbeiten(); // Streckenende::vBearbeiten() oder Losfahren::vBearbeiten(), abhaenging von dem Parameter
		}
	}
}

void Weg::vAusgeben(std::ostream &o) const {

	Simulationsobjekt::vAusgeben(o);
	o << std::setw(30) << p_dLaenge << std::setw(20);
	o << "( ";
	for(auto& i: p_pFahrzeuge){
		o << i -> getName() << " ";

		//i -> vKopf();
		//std::cout << *i;
	}
	o << ")";
}

void Weg::vKopf(){
	std::cout << std::resetiosflags(std::ios::left);
			std::cout << std::setiosflags(std::ios::right) // right-alinged Werte
				<< "ID" << std::setw(20) <<"Name" << std::setw(30) << "Laenge(km)"<< std::setw(30) << "Fahrzeuge" << std::endl;
		std::cout << "-------------------------------------------------------------------------------------" << std::endl;
}

std::string Weg::getName() const{
	return p_sName;
}

double Weg::getLaenge() const {
	return p_dLaenge;
}

//-----------------------Fahrende Fahrzeuge annehmen--------------------------------//
void Weg::vAnnahme(std::unique_ptr<Fahrzeug> Fzg){
	Fzg -> vNeueStrecke(*this); //Das Verhalten des Fahrzeuges bestimmen -> Hier Fahren
	p_pFahrzeuge.push_back(move(Fzg));
}

//------------------------Parkende Fahrzeuge annehmen--------------------------------//
void Weg::vAnnahme(std::unique_ptr<Fahrzeug> Fzg, double dStartZeitPunkt){
	Fzg -> vNeueStrecke(*this, dStartZeitPunkt); // Hier Parken
	p_pFahrzeuge.push_front(move(Fzg)); // front?
}
