
#include "PKW.h"
#include "Weg.h"
#include "Verhalten.h"
#include "SimuClient.h"
/*
//------------------Konstruktor ohne Parameter---------------//
PKW::PKW() {

}
*/
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

/*
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
*/

void PKW::vSimulieren(){
	double dZwischenZeit = dGlobaleZeit - p_dZeit;
		if(p_pVerhalten != nullptr){
			double dGefahren = p_pVerhalten -> dStrecke(*this, dZwischenZeit);//'this' muss dereferenziert werden / Verhalten::dStrecke(Fahrzeug& aFzg, double ZeitIntervall)
			p_dAbschnittStrecke += dGefahren;
			p_dGesamtStrecke += dGefahren;
			double dZwischenVerbrauch = p_dVerbrauch/100 * dGefahren;
			if(p_dTankinhalt >= dZwischenVerbrauch){ //Solange es genug Tankinhalt gibt, kann es weiter fahren
					//p_dGesamtStrecke += dZwischenStrecke;
					p_dTankinhalt -= dZwischenVerbrauch;
		}

		p_dGesamtZeit += dZwischenZeit;
		p_dZeit = dGlobaleZeit;
	}
}
/*
//------------------Funktion zum Ausgeben der Daten eines PKWs-----------------//
void PKW::vAusgeben(std::ostream& o) const{
	o << std::fixed;
	o << std::setprecision(2);
	o << std::resetiosflags(std::ios::left);
	o << std::setiosflags(std::ios::right) << getID()//p_iID
		<<std::setw(20)<< p_sName << std::setw(20) << p_dMaxGeschwindigkeit << std::setw(30)
		<< dGeschwindigkeit() << std::setw(30) << p_dGesamtStrecke << std::setw(30)
		<< p_dGesamtStrecke * p_dVerbrauch/100 <<std::setw(30)<< p_dTankinhalt;
}
*/
void PKW::vAusgeben(std::ostream& o) const{
	Fahrzeug::vAusgeben(o);
		o << std::setw(30)
		<< p_dGesamtStrecke * p_dVerbrauch/100 <<std::setw(30)<< p_dTankinhalt;
}
//---------------Ueberladung von '=' Operator----------------//
void PKW::operator=(const PKW& pkw1){
	this -> p_sName = pkw1.p_sName;
	this -> p_dMaxGeschwindigkeit = pkw1.p_dMaxGeschwindigkeit;
	this -> p_dVerbrauch = pkw1.p_dVerbrauch;
	this -> p_dTankvolumen = pkw1.p_dTankvolumen;
}

double PKW::dGeschwindigkeit() const{
	if ((this -> Fahrzeug::dGeschwindigkeit()) > (p_pVerhalten -> getWegTempolimit())){
		return p_pVerhalten -> getWegTempolimit();
	}
	else{
		return Fahrzeug::dGeschwindigkeit(); // gibt die p_dMaxGeschwindigkeit() zurueck
	}
}


void PKW::vZeichnen(const Weg& weg3) const{
	double dRelPosition = p_dAbschnittStrecke / weg3.getLaenge();
	/*
	if (dRelPosition < 0){
		dRelPosition = 0;
	}
	if(dRelPosition > 1){
		dRelPosition = 1;
	}*/

	bZeichnePKW(p_sName, weg3.getName(), dRelPosition,dGeschwindigkeit(), p_dTankinhalt);
}









