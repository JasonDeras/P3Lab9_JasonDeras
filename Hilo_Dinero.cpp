#include<time.h>
#include<windows.h>
#include<process.h>
#include<iostream>
#include<string.h>

#ifndef HILO_CPP
#define HILO_CPP

using namespace std;

class Hilo{
	
	private:
		
		bool vive;
		int espera;
		string texto;
	
	public:
	
		Hilo(){
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
			_beginthread(&Hilo::runner,0,static_cast<void*>(this));
		}//Metodo run
		
		static void runner(void *o){
			static_cast<Hilo*>(o)->runnerEstatico();
		}//Metodo runner
		
		void runnerEstatico(){
			
			while(vive){
				
				MessageBox(0,texto.c_str(),"Advertencia",MB_OK);
				
				Sleep(espera);
				
				if(!vive){
					_endthread();
				}//Corre mientras sea verdadero
				
			}//While que hace la tarea del hilo
			
		}//Metodo de correr estatico
};
#endif
