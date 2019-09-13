#include<iostream>
#include<string.h>
#include<vector>
#include<bits/stdc++.h>

#ifndef JUGADOR_CPP
#define JUGADOR_CPP

using namespace std;

class Jugador{
	
      private:
      	
	  	int dinero;
		int vida;
 		int vida_maxima;
		int nivel;
	    
      public:
      	
        Jugador(){
        	dinero=0;
        	vida=1;
        	vida_maxima=3;
        	nivel=1;
		}//Constructor vacio
			             
        Jugador(int dinero,int vida,int vida_maxima,int nivel){
        	this->dinero=dinero;
			this->vida=vida;
			this->vida_maxima=vida_maxima;
			this->nivel=nivel;	              
        }//Constructor sobrecargado
             
        void setDinero(int dinero){
        	this->dinero=dinero;
        }//Set del dinero
             
        int getDinero(){
            return dinero;
        }//Get del dinero
             
        void setVida(int vida){
            this->vida=vida;
        }//Set de la vida
             
        int Vida(){
            return vida;
        }//Get de la vida
        
		void setVida_Maxima(int vida_maxima){
        	this->vida_maxima=vida_maxima;
        }//Set de la vida maxima
             
        int getVida_Maxima(){
            return vida_maxima;
        }//Get de la vida maxima
		
		void setNivel(int nivel){
            this->nivel=nivel;
        }//Set del nivel
             
        int getNivel(){
            return nivel;
        }//Get del nivel	 
		              
        void print(){
        	cout<<"Dinero: "<<dinero<<endl;
        	cout<<"Vida: "<<vida<<endl;
        	cout<<"Vida Maxima: "<<vida_maxima<<endl;
        	cout<<"Nivel: "<<nivel<<endl;
			cout<<"\n\n\n\n";
        }//Metodo print 
        
        ~Jugador(){
		}//Destructor   
};
#endif
