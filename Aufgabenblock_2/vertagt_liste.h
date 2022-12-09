#pragma once

#include "vertagt_aktion.h"
#include <list>
#include <memory>

namespace vertagt
{
	template <class T>
	class VListe
	{
	private:
		std::list<T> p_objekte;
		std::list<std::unique_ptr<VAktion<T>>> p_aktionen;

	public:
		// Typdefinitionen
		using iterator = typename std::list<T>::iterator;
		using const_iterator = typename std::list<T>::const_iterator;

		// Konstruktoren
		VListe(){}; // Benötigt man einen Standardkonstruktor?
		//VListe(std::list<T>& Liste, std::list<std::unique_ptr<VAktion<T>>>& Aktionen):p_objekte(Liste), p_aktionen(Aktionen){};
		// Destruktor
		~VListe()
		{
			vAktualisieren();
			p_objekte.clear();
		}

		void clear()
		{
			p_objekte.clear(); // Alternative?
		}

		// Lesefunktionen
		const_iterator begin() const
		{
			return p_objekte.begin();
		}
		const_iterator end() const
		{
			return p_objekte.end();
		}
		iterator begin()
		{
			return p_objekte.begin();
		}
		iterator end()
		{
			return p_objekte.end();
		}
		//----ueberprueft ob die Liste leer ist----//
		bool empty() const
		{
			return p_objekte.empty();
		}


		// Schreibfunktionen
		void push_back(T obj)
		{
			// Aktionselement für PushBack auf Liste erzeugen
			//std::make_unique<VPushBack<T>>(std::list<T>& p_pListe, T obj)
			p_aktionen.push_back(std::make_unique<VPushBack<T>>(p_objekte, std::move(obj)));//move(obj) here as well
		}
		void push_front(T obj)
		{
			// Aktionselement für PushBack auf Liste erzeugen
			p_aktionen.push_back(std::make_unique<VPushFront<T>>(p_objekte, std::move(obj)));
		}

		void erase(iterator it)
		{
			// Aktionselement für PushBack auf Liste erzeugen (hier Iterator statt Objekt !)
			p_aktionen.push_back(std::make_unique<VErase<T>>(p_objekte, it));
		}

		// Änderungen auf Objektliste übertragen
		void vAktualisieren()
		{
			// Änderungen auf Objektliste übertragen
			for (auto& pAktion : p_aktionen)
			{
				// Aktion ausführen
				pAktion -> vAusfuehren();
			}

			// Aktionsliste löschen
			p_aktionen.clear();
		}
	};
} // namespace vertagt
