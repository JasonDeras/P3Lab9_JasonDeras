#include<time.h>
#include<windows.h>
#include<process.h>
#include<iostream>
#include<string.h>

#ifndef HILO_BATALLA_CPP
#define HILO_BATALLA_CPP

using namespace std;

class Hilo_Batalla{
	
	private:
		
		bool vive;
		int espera;
		string texto;
	
	public:
	
		Hilo_Batalla(){
		}//Constructor simple

		void setVive(bool vive){
			this->vive=vive;
		}//Set del vive
		
		void setTexto(string texto){
			this->texto=texto;
		}//Set del texto
		
		void setEspera(int espera){
			this->espera=espera;
		}
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
				
				if(!vive){
					_endthread();
				}//Corre mientras sea verdadero
				
			}//While que hace la tarea del hilo
			
		}//Metodo de correr estatico
};
#endif
