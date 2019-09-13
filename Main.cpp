#include<iostream>
#include <string.h>
#include<CONIO.H>
#include "Jugador.cpp"
#include "Hilo_Dinero.cpp"
#include "Hilo_Vida.cpp"
#include "Hilo_Batalla.cpp"

using namespace std;

int main(){
	
	//Variable de control del nombre del jugador
	string nombre;
	
	cout<<"Ingrese su nombre: ";
	cin>>nombre;
	
	//Creacion del jugador
	Jugador jugador;
	
	//Creacion del Hilo del dinero
	Hilo_Dinero dinero;
	dinero.setVive(true);
	dinero.setTexto("Gano +1 de dinero");
	dinero.setEspera(7000);
	//dinero.run();
	
	//Creacion del hilo de la vida
	Hilo_Vida vida;
	vida.setVive(true);
	vida.setTexto("Gano +1 de vida");
	vida.setEspera(6000);
	//vida.run();
	
	//Creacion del hilo de la batalla
	Hilo_Batalla batalla;
	batalla.setVive(true);
	batalla.setTexto("Se encontro una batalla");
	batalla.setEspera(10000);
	batalla.run();

	while(true){
				
		//Variable de control del menu
		int op;
		
		cout<<"Menu\n\n\n";
		cout<<"1. Ver datos\n\n";
		cout<<"2. Curar un punto de vida<$1>\n\n";
		cout<<"3. Salir\n\n\n";
		cout<<"Ingrese una opcion: ";
		cin>>op;
		cout<<"\n\n\n";
		
		if(dinero.getDinero()==1){
			jugador.setDinero(jugador.getDinero()+1);
			dinero.setDinero(0);
		}//If auxilar de los datos del jugador
		
		if(vida.getVida()==1){
			jugador.setVida(jugador.getVida()+1);
			vida.setVida(0);
		}//If auxilar de los datos del jugador
		
		switch(op){
			
			case 1:
				jugador.print();
			break;
			
			case 2:
				if(jugador.getDinero()>0){
					jugador.setVida(jugador.getVida()+1);
					jugador.setDinero(jugador.getDinero()-1);	
				}else{
					cout<<"No tiene el dinero necesario para curar mas vida\n\n\n";
				}//Fin del if para curar la vida del jugador	
			break;
			
			case 3:
				exit(0);
				dinero.stop();
				vida.stop();
			break;
			
			default:
				cout<<"Opcion no valida\n\n";
			break;
			
		}//Fin de las opciones del jugador
		
	}//Fin repetitivo
	
	return 0;
	
}//Fin del main

