#include<time.h>
#include<windows.h>
#include<process.h>
#include<iostream>
#include<string.h>
#include "Jugador.cpp"
#ifndef HILO_VIDA_CPP
#define HILO_VIDA_CPP

using namespace std;

class Hilo_Vida{
	
	private:
		
		bool vive;
		int espera;
		Jugador* jugador;
		
	public:
	
		Hilo_Vida(){
		}//Constructor simple

		void setVive(bool vive){
			this->vive=vive;
		}//Set del vive
		
		void setEspera(int espera){
			this->espera=espera;
		}
		void stop(){
			vive=false;
		}//Detiene el hilo
		
		void setJugador(Jugador* jugador){
			this->jugador=jugador;
		}//Set del usuario
		
		void run(){
			_beginthread(&Hilo_Vida::runner,0,static_cast<void*>(this));
		}//Metodo run
		
		static void runner(void *o){
			static_cast<Hilo_Vida*>(o)->runnerEstatico();
		}//Metodo runner
		
		void runnerEstatico(){
			
			while(vive){
				Sleep(espera);
				if(jugador->getPelear()==false){
					jugador->addVida();
				}
				if(!vive){
					_endthread();
				}
			}//Se ejecuta el hilo
			
		}//Fin del correr estatico	
		
};
#endif
