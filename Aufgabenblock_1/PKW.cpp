
#include "PKW.h"

//------------------Konstruktor ohne Parameter---------------//
PKW::PKW() {

}

//------------------Konstruktor mit 4 Parametern----------------//
PKW::PKW(std::string name, double max_geschwindigkeit, double verbrauch, double tankvolumen):
		Fahrzeug(name, max_geschwindigkeit), p_dVerbrauch(verbrauch), p_dTankvolumen(tankvolumen),p_dTankinhalt(tankvolumen/2){

}

//------------------Dekonstruktor---------------------//
PKW::~PKW() {

}

//-----------------Funktion zur Menge ,die zu tanken ist(Ueberschrieben)------------//
double PKW::dTanken(double dMenge=std::numeric_limits<double>::infinity()){ //wenn kein Parameter eingetragen wird, voll tanken

	if(dMenge < (p_dTankvolumen - p_dTankinhalt)){
		p_dTankinhalt += dMenge;
		return dMenge;
	}
	else{
		double dGetankt = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
		return dGetankt;
	}
}

//--------------------Simulationsfunktion eines PKWs(Ueberschriben)--------------------//
void PKW::vSimulieren(){
	double dZwischenZeit = dGlobaleZeit - p_dZeit;//Echtzeit - (letzte Zeitmarke)/ p_dZeit als

	double dZwischenStrecke = dZwischenZeit * dGeschwindigkeit(); // hier: dGeschwindigkeit() = Max.Geschwindigkeit
	p_dGesamtZeit += dZwischenZeit;
	p_dZeit = dGlobaleZeit;

	//-----------Zusaetzliche Eigenschaften----------//
	double dZwischenVerbrauch = p_dVerbrauch/100 * dZwischenStrecke; //p_dVerbrauch in L/100km

	if(p_dTankinhalt >= dZwischenVerbrauch){ //Solange es genug Tankinhalt gibt, kann es weiter fahren
		p_dGesamtStrecke += dZwischenStrecke;
		p_dTankinhalt -= dZwischenVerbrauch;
	}
}

//------------------Funktion zum Ausgeben der Daten eines PKWs-----------------//
void PKW::vAusgeben(std::ostream& o) const{
	o << std::fixed;
	o << std::setprecision(2);
	o << std::resetiosflags(std::ios::left);
	o << std::setiosflags(std::ios::right) << p_iID
		<<std::setw(20)<< p_sName << std::setw(20) << p_dMaxGeschwindigkeit << std::setw(30)
		<< dGeschwindigkeit() << std::setw(30) << p_dGesamtStrecke << std::setw(30)
		<< p_dGesamtStrecke * p_dVerbrauch/100 <<std::setw(30)<< p_dTankinhalt;
}

//---------------Ueberladung von '=' Operator----------------//
void PKW::operator=(const PKW& pkw1){
	this -> p_sName = pkw1.p_sName;
	this -> p_dMaxGeschwindigkeit = pkw1.p_dMaxGeschwindigkeit;
	this -> p_dVerbrauch = pkw1.p_dVerbrauch;
	this -> p_dTankvolumen = pkw1.p_dTankvolumen;
}
