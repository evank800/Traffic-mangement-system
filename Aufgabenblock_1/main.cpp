#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"


double dGlobaleZeit = 0.0;


void vAufgabe_1(){

		//--------Objekte erzeugen ueber Deklaration----------//
		Fahrzeug Zug("Zug_1");
		Fahrzeug Motorrad("Motorrad_1");

		//------------Objekte dynamisch erzeugen-------------//
		Fahrzeug *p1 = new Fahrzeug("Fahrrad_1");
		Fahrzeug *p2 = new Fahrzeug("Auto_1");
		delete p1;
		delete p2;

		//--------------Unique-Pointers--------------//
		std::unique_ptr<Fahrzeug> uniqueP(new Fahrzeug("Zug_2"));
		std::unique_ptr<Fahrzeug> uniqueP_2(new Fahrzeug("Motorrad_2"));

        //std::unique ptr<Fahrzeug> uniqueP_3 = uniqueP_2  => ergibt Error(unique_ptr kann nicht kopiert werden)
	    //std::unique_ptr<Fahrzeug> uniqueP_3 = move(uniqueP_2) => funktioniert


		//---------------Shared-Pointers--------------//
		std::shared_ptr<Fahrzeug> sharedP(new Fahrzeug("Auto_2"));
		std::shared_ptr<Fahrzeug> sharedP_2(new Fahrzeug("Fahrrad_2"));
		std::cout << "Anzahl der Referenzen: "<< sharedP_2.use_count() << std::endl; // ergibt 1, da Objekt nur ein Pointer besitzt
		std::shared_ptr<Fahrzeug> sharedP_3 = sharedP_2;
		std::cout << "Anzahl der Referenzen: "<< sharedP_2.use_count() << std::endl; // ergibt 2, da Objekt jetzt 2 Pointers besitzt

		//--------------Fahrzeuge in Vector hinzufuegen-----------------//
		std::vector<std::unique_ptr<Fahrzeug>> fahrzeuge_u; //Vector(type: unique_ptr) erstellen
		fahrzeuge_u.push_back(move(uniqueP));
		fahrzeuge_u.push_back(move(uniqueP_2));

		std::vector<std::shared_ptr<Fahrzeug>> fahrzeuge_s; //Vector<type: shared_ptr> erstellen
		fahrzeuge_s.push_back(sharedP);
		fahrzeuge_s.push_back(sharedP_2); //sharedP_2 noch mal kopiert => An. Ref. = 3
		std::cout << "Anzahl der Referenzen: "<< sharedP_2.use_count() << std::endl;
		fahrzeuge_s.push_back(move(sharedP_2)); // keine Kopie => An. Ref. = 0
		std::cout << "Anzahl der Referenzen: "<< sharedP_2.use_count() << std::endl;
		fahrzeuge_s.push_back(sharedP_3);

		//-------Elemente entfernen-------//
		fahrzeuge_u.clear();
		fahrzeuge_s.clear();
}




void vTest(){

	//----------Fahrzeuge erstellen mittels smart pointers---------------//

	//std::unique_ptr<Fahrzeug> schnellerZug(new Fahrzeug("Schneller Zug", 360));

	//std::unique_ptr<Fahrzeug> sportsCar(new Fahrzeug("sportsCar", 210));
	//schnellerZug -> vKopf(); // Klassenfunktionen mit '->' aufrufen bei smart pointers
	//schnellerZug -> vAusgeben();
	//sportsCar -> vAusgeben();

	//Simulation
	//schnellerZug -> vSimulieren();

	std::unique_ptr<PKW> pkw1(new PKW("PKW1", 150 , 0.7, 300)); // (name, max_geschw., verbrauch, tankvolumen)
	pkw1 -> vKopf(); // vKopf() wurde nur in 'Fahrzeug' Klasse definiert

//	std::unique_ptr<Fahrrad> fahrrad1(new Fahrrad("Fahrrad1", 20));
//	fahrrad1 ->vKopf();

	const double dTakt = 0.2;
	while(dGlobaleZeit <= 1){

		pkw1 -> vSimulieren();
//		fahrrad1 -> vSimulieren();
		dGlobaleZeit += dTakt;
	}


}





void vAufgabe_1a(){

	//------------Smart pointers erzeugen------------//
	auto BMW = std::make_unique<Fahrzeug>("BMW", 260);
	//std::unique_ptr<Fahrzeug> BMW(new Fahrzeug("BMW", 260));
	//std::unique_ptr<Fahrzeug> VW(new Fahrzeug("VW", 210));
	auto VW = std::make_unique<Fahrzeug>("VW", 210);
	//std::unique_ptr<Fahrzeug> Opel(new Fahrzeug("Opel", 180));
	auto Opel = std::make_unique<Fahrzeug>("Opel", 180);


	//----------Vector erzeugen/Eemente hinzufuegen---------//
	std::vector<std::unique_ptr<Fahrzeug>> Autos;
	Autos.push_back(move(BMW));
	Autos.push_back(move(VW));
	Autos.push_back(move(Opel));


	//--------------Sumulieren---------------//
	const double dTakt = 0.2; //Simulationsintervall
	Autos[0] -> vKopf();

	//jedes Auto simulieren, bis zu zwei Stunde
	while(dGlobaleZeit <= 2){

		dGlobaleZeit += dTakt;
		Autos[0] -> vSimulieren();
		Autos[1] -> vSimulieren();
		Autos[2] -> vSimulieren();
		std::cout << *Autos[0];
		std::cout << *Autos[1];
		std::cout << *Autos[2];
	}
}




void vAufgabe_2(){
	//---------Anzahl der PKWs und Fahrraeder deklarieren/initialisieren--------//
	int iPKW;
	int iFahrrad;

	std::cout << "Geben Sie die Anzahl der zu erzeugenden PKWs an: " << std::endl;
	std::cin >> iPKW;
	std::cout << "Geben Sie die Anzahl der zu erzeugenden Fahrraeder an: " << std::endl;
	std::cin >> iFahrrad;

	std::vector<std::unique_ptr<Fahrzeug>> Fahrzeuge2;

	//-----------PKWs hinzufuegen----------//
	for(int i = 0; i < iPKW; i++){
		std::string sName;
		double dGeschw;
		double dVerbrauch;
		double dTankvolumen;
		std::cout << "Name: ";
		std::cin >> sName;
		std::cout << "Max.Geschwindigkeit(km): ";
		std::cin >> dGeschw;
		std::cout << "Verbrauch(L/100km): ";
		std::cin >> dVerbrauch;
		std::cout << "dTankvolumen(L): ";
		std::cin >> dTankvolumen;

		Fahrzeuge2.push_back(move(std::unique_ptr<PKW> (new PKW(sName, dGeschw, dVerbrauch, dTankvolumen))));
	}

	//----------Fahrraeder hinzufuegen---------//
	for(int i = 0; i < iFahrrad; i++){
		std::string sName;
		double dGeschw;
		std::cout << "Name: ";
		std::cin >> sName;
		std::cout << "Max.Geschwindigkeit(km): ";
		std::cin >> dGeschw;

		Fahrzeuge2.push_back(move(std::unique_ptr<Fahrrad> (new Fahrrad(sName, dGeschw))));
	}


	//------------Simulieren-------------//

	double dTakt = 0.2;
	bool bGetankt = false;

	if(Fahrzeuge2.size() != 0){
		Fahrzeuge2[0] -> vKopf();
	}

	while(dGlobaleZeit <= 5){

		//---------voll tanken(in 3 Stunden)---------//
		if(dGlobaleZeit >= 3 && bGetankt == false){ // bGetankt == true => nicht mehr tanken
			for(int i = 0; i < int(Fahrzeuge2.size()); i++){
				Fahrzeuge2[i] -> dTanken(std::numeric_limits<double>::infinity());
				bGetankt = true;
			}
		}


		for(int i = 0; i < int(Fahrzeuge2.size()); i++){
			Fahrzeuge2[i]->vSimulieren();
			//Fahrzeuge2[i]->vAusgeben();
			std::cout << *Fahrzeuge2[i];// mit ueberladenem Operator

		}
		dGlobaleZeit += dTakt;

	}

}





//-------------------Testen der Ueberladungen---------------//
void vAufgabe_3(){

	//------------------Ueberladung von '<<'(Ausgabe) Operator testen---------------//
	std::vector<std::unique_ptr<Fahrzeug>> Fahrzeuge;

	auto pkw1 = std::make_unique<PKW>("PKW1", 256, 9.3, 61);
	auto pkw2 = std::make_unique<PKW>("PKW2", 313, 8.9, 55);
	auto fahrrad1 = std::make_unique<Fahrrad>("Fahrrad1", 64);
	auto fahrrad2 = std::make_unique<Fahrrad>("Fahrrad2", 43);

//	Fahrzeuge.push_back(move(pkw1));
//	Fahrzeuge.push_back(move(pkw2));
//	Fahrzeuge.push_back(move(fahrrad1));
//	Fahrzeuge.push_back(move(fahrrad2));


//	double dTakt = 0.2;
//
//	Fahrzeuge[0] -> vKopf();
//
//	while (dGlobaleZeit <= 3){
//		for(int i = 0; i < int(Fahrzeuge.size()); i++){
//			Fahrzeuge[i] -> vSimulieren();
//			std::cout << *Fahrzeuge[i]; //Dereferenzieren
//
//		}
//
//
//		dGlobaleZeit += dTakt;
//	}


	//----------=Ueberladung von '<'(Vergleich von Strecken) Operator testen---------------//

		double dTakt = 0.2;

		pkw1 -> vKopf();

		while (dGlobaleZeit <= 3){
			pkw1 -> vSimulieren();
			pkw2 -> vSimulieren();
			std::cout << *pkw1;
			std::cout << *pkw2;

			bool isTrue = *pkw1 < *pkw2; //Dereferenzieren
			std::cout << isTrue << std::endl;


			dGlobaleZeit += dTakt;
		}
}



int main(){

	//vAufgabe_1();

	//vTest();

	//vAufgabe_1a();

	//vAufgabe_2();

	vAufgabe_3();
}
