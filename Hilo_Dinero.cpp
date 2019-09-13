#include <time.h>
#include <windows.h>
#include <process.h>
#include <iostream>
#include "Jugador.cpp"

using namespace std;

#ifndef Hilo_Dinero_Cpp
#define Hilo_Dinero_Cpp

class Hilo_Dinero{
	
	private:
		
		bool vive;
		int espera;
		Jugador* jugador;
		
	public:
		
		Hilo_Dinero(){
		}//Constructor vacio
		
		void setVive(bool v){
			vive=v;
		}//Set del vive
		
		void setEspera(int e){
			espera=e;
		}//Set del espera
		
		bool getVive(){
			return vive;
		}//Get del vive
		
		void setJugador(Jugador* jugador){
			this->jugador=jugador;
		}//Set del jugador
		
		void stop(){
			vive=false;
		}//Cierra el hilo
		
		void run(){
			_beginthread(&Hilo_Dinero::runner,0,static_cast<void*>(this));
		}//Empieza el hilo
		
		static void runner(void* o){
			static_cast<Hilo_Dinero*>(o)->runnerEstatico();
		}//Instancia del hilo
		
		void runnerEstatico(){
			
			while(vive){
				
				Sleep(espera);
				
				if(jugador->getPelear()==false){
					jugador->addDinero();
				}
				if(!vive){
					_endthread();
				}
			}//While del hilo
			
		}//Metodo runner estatico
};
#endif
