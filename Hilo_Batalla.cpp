#include<time.h>
#include<windows.h>
#include<process.h>
#include<iostream>
#include<string.h>
#include "Jugador.cpp"
#ifndef HILO_BATALLA_CPP
#define HILO_BATALLA_CPP

using namespace std;

class Hilo_Batalla{
	
	private:
		
		bool vive;
		int espera;
		Jugador* jugador;
		
	public:
	
		Hilo_Batalla(){
		}//Constructor simple

		void setVive(bool vive){
			this->vive=vive;
		}//Set del vive
		
		void setEspera(int espera){
			this->espera=espera;
		}//Set del espera
		
		void setJugador(Jugador* jugador){
			this->jugador=jugador;
		}//Set del jugador
		
		void stop(){
			vive=false;
		}//Detiene el hilo
		
		void run(){
			_beginthread(&Hilo_Batalla::runner,0,static_cast<void*>(this));
		}//Metodo run
		
		static void runner(void *o){
			static_cast<Hilo_Batalla*>(o)->runnerEstatico();
		}//Metodo runner
		
		void runnerEstatico(){
			
			while(vive){
				
				Sleep(espera);
				
				srand(time(0));
				
				int r = (rand() % 5) + 1;
				
				if(jugador->getPelear()==false){
					
					if(r>=4){
						jugador->setPelear(true);
					}
				}
				
				if(!vive){
					_endthread();
				}
				
			}//While de ejecucion del hilo
			
		}//Fin del metodo runner estatico
		
		
};
#endif
