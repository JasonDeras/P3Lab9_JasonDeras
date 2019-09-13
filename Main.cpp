#include <iostream>
#include <string.h>
#include <conio.h>
#include "Hilo_Vida.cpp"
#include "Hilo_Batalla.cpp"
#include "Hilo_Dinero.cpp"

using namespace std;
void Batalla();

int main(){
	//Variable del nombre
	string nombre;
	cout<<"Ingrese su nombre: ";
	cin>>nombre;
	
	cout<<"\n\n\n";
	//Instancia del jugador
	Jugador*jugador=new Jugador();
	
	//Creacion del hilo de dinero
	Hilo_Dinero h_dinero;
	h_dinero.setVive(true);
	h_dinero.setEspera(7000);
	h_dinero.setJugador(jugador);
	h_dinero.run();
	
	//Creacion del hilo de la vida
	Hilo_Vida h_vida;
	h_vida.setVive(true);
	h_vida.setEspera(6000);
	h_vida.setJugador(jugador);
	h_vida.run();
	
	//Creacion del hilo de la batalla
	Hilo_Batalla h_batalla;
	h_batalla.setVive(true);
	h_batalla.setEspera(10000);
	h_batalla.setJugador(jugador);
	h_batalla.run();
	
	while(true){
		
		system("cls");
		cout<<"Menu\n\n\n";
		cout<<"1. Datos del jugador\n\n";
		cout<<"2. Curar vida\n\n";
		cout<<"3. Salir\n\n";
		
		//Variable para controlar el menu
		int op;
		
		cout<<"Ingrese una opcion: ";
		if(jugador->getPelear()==false){
			cin>>op;
		}else{
			op=4;
		}//If que valida si le toca pelear o no
		cout<<"\n\n\n";
		
		switch(op){
			
			case 1:
				cout<<"Nivel: "<<jugador->getNivel()<<endl;
				cout<<"Dinero: "<<jugador->getDinero()<<endl;
				cout<<"Vida: "<<jugador->getVida()<<"/"<<jugador->getVida_Maxima()<<endl;
				system("pause");
			break;
			
			case 2:
				jugador->comprarVida();
				system("pause");
			break;
			
			case 3:
				cout<<"Sesion cerrada"<<endl;
				jugador=NULL;
				exit(0);
			break;
			
			case 4:
			break;
			
			default:
				cout<<"Opcion no valida\n\n\n";
			break;	
		}//Fin de las opciones
		
	}//Fin del while repetitivo
	
	return 0;
	
}//Fin del main

void Batalla(){
	
}//Metodo para la batalla

