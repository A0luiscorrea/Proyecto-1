//
//  main.cpp
//  Proyecto1
//
//  Created by Luis Alejandro Correa Vargas on 06/09/20.
//  Copyright © 2020 Luis Alejandro Correa Vargas. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string linea,linea1,linea2,linea3,linea4,linea5,linea6,linea7,linea8,linea9,linea10,linea11,linea12,linea13;
    string cliente, saldo, fecha, cuenta, direccion, empresa, salida;
    cout << "Digite el nombre de su archivo de salida: ";
    getline(cin,salida);
    ifstream archEnt,archDatos;
    ofstream archSalida;
    
    archEnt.open("plantilla.txt");
    archDatos.open("datos.txt");
    while (getline(archDatos,linea)) //Asignar variables de archivo de datos a otras variables
        if(linea.find("<cliente>")!=-1) //Cliente
        {
            linea.erase(0,10);
            cliente = linea;
        }
    else
    {
        if(linea.find("<saldo>")!=-1) //Saldo
        {
            linea.erase(0,8);
            saldo = linea;
        }
        else
        {
            if(linea.find("<fecha>")!=-1) //Fecha
            {
                linea.erase(0,8);
                fecha = linea;
            }
            else
            {
                if(linea.find("<cuenta>")!=-1) //Cuenta
                {
                    linea.erase(0,9);
                    cuenta = linea;
                }
                else
                {
                    if(linea.find("<direccion>")!=-1) //Dirección
                    {
                        linea.erase(0,12);
                        direccion = linea;
                    }
                    else
                    {
                        
                        if(linea.find("<empresa>")!=-1) //Empresa
                        {
                            linea.erase(0,10);
                            empresa = linea;
                        }
                    }
                }
            }
        }
    }
    archDatos.close();//Cerrar archivo de Datos
    
    getline(archEnt,linea); //Estimado <cliente>:
    if(linea.find("<cliente>")!=-1)
    {
        linea.replace(9,13,cliente);
        //cout << linea;
    }
    getline(archEnt,linea1); //Espacio en blanco
    //cout << linea1;
    getline(archEnt,linea2);
   //Este mensaje es para informarle que tiene un saldo pendiente de <saldo> y tiene que cubrirlo antes de <fecha>.
    if (linea2.find("<saldo>")!=-1)
    {
        linea2.replace(64,8,saldo);
    }
    if (linea2.find("<fecha>")!=-1)
    {
        linea2.replace(105,8,fecha);
    }
    //cout << linea2;
    getline(archEnt,linea3); //Espacio en blancho
    //cout << linea3;
    //Para hacerlo puede depositar <saldo> pesos en la cuenta <cuenta>; o bien, asistir a <direccion> con la cantidad de <saldo> completa.
    getline(archEnt,linea4);
    if (linea4.find("<saldo>")!=-1)
       {
           linea4.replace(29,7,saldo);
           linea4.replace(119,7,saldo);
       }
    if (linea4.find("<cuenta")!=-1)
    {
        linea4.replace(60,8,cuenta);
    }
    if(linea4.find("direccion")!=-1)
    {
        linea4.replace(93,11,direccion);
    }
    //cout << linea4;
    //Espacio en blanco
    getline(archEnt,linea5);
    //cout << linea5;
    //También puede enviar un cheque a nombre de <empresa> por la cantidad de <saldo> y con la fecha <fecha>.
    getline(archEnt,linea6);
    if(linea6.find("<empresa>")!=-1)
    {
        linea6.replace(44,9,empresa);
        if(linea6.find("<saldo>")!=-1)
        {
            linea6.replace(75,9,saldo);
            if(linea6.find("<fecha>")!=-1)
            {
                linea6.replace(100,11,fecha);
            }
        }
        //cout << linea6;
    }
    //Espacio en blanco
    getline(archEnt,linea7);
    //cout << linea7;
    //No olvide colocar su nombre como lo tenemos registrado que es <cliente>.
    getline(archEnt,linea8);
    if(linea8.find("<cliente>")!=-1)
    {
        linea8.replace(62,11,cliente);
        //cout << linea8;
    }
    //Espacio en blanco
    getline(archEnt,linea9);
    //cout << linea9;
    //Esperamos tener noticias suyas pronto y estamos para servirle
    getline(archEnt,linea10);
      // cout << linea10;
    //Espacio en blanco
    getline(archEnt,linea11);
       //cout << linea11;
    //Atentamente
    getline(archEnt,linea12);
       //cout << linea12;
    // <empresa>
    getline(archEnt,linea13);
       if(linea13.find("<empresa>")!=-1)
       {
           linea13.replace(0,11,empresa);
           //cout << linea13;
       }
   archEnt.close();
    
    archSalida.open(salida.c_str());
    archSalida << linea;
    archSalida << linea1;
    archSalida << linea2;
    archSalida << linea3;
    archSalida << linea4;
    archSalida << linea5;
    archSalida << linea6;
    archSalida << linea7;
    archSalida << linea8;
    archSalida << linea9;
    archSalida << linea10;
    archSalida << linea11;
    archSalida << linea12;
    archSalida << linea13;
    archSalida.close();//Cerrar archivo de plantilla
    return 0;
}
   
