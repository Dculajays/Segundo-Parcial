#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

class CINE{
public:

    void Alta(){
            std::fstream bitacora;
            bitacora.open("bitacora.dat",ios::app|ios::in|ios::out|ios::binary);
            bitacora<<std::left<<std::setw(15)<<"menu ALTA";
            bitacora.close();
        system("cls");
        fstream baseDatos;
        cout << "\n\t\t\tEntrando al menu --REGISTRAR CLIENTES--\n" << endl;
        cout << "\n\t¿Quires salir al --MENU CATALOGOS--? [ si / no ] : "; cin >> desicion;
        if (desicion=="si"){
            return menuCatalogos();
        }
        else {
            cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
            cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
            cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
            cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
            cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
            cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
            cout << "\t\tIngrese eL NIT de la persona a ingresar "; cin >> NIT;
            cout << "\t\tIngrese la pelicula a ver "; cin>>Pelicula;
            cout << "\t\tIngrese el costo del ticket "; cin>>costo;
            cout << "\n\t--Registro completado--\n" << endl;
            baseDatos.open("clientes.dat", ios::app | ios::out | ios::binary);
            baseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< NIT << std::left<<std::setw(15)<< Pelicula << std::left<<std::setw(15)<< costo <<"\n";
            baseDatos.close();
            cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU CATALOGOS--";
                    return menuCatalogos();
                }
        }
    }
    void modificaciones(){
            std::fstream bitacora;
            bitacora.open("bitacora.dat",ios::app|ios::in|ios::out|ios::binary);
            bitacora<<std::left<<std::setw(15)<<"menu modificar";
            bitacora.close();
        system("cls");
        fstream baseDatos, modBaseDatos;
        cout << "\n\t\t\tEntrando al menu --MODIFICAR--" << endl;
            baseDatos.open("clientes.dat",ios::in|ios::binary);
            if(!baseDatos){
                cout << "\n\t\tNo se encontro el archivo" << endl;
                baseDatos.close();
                cout << "\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\t\nRegresando al --MENU CATALOGOS--";
                    return menuCatalogos();
                }
            }
            else {
                cout << "\n\t\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
                modBaseDatos.open("temporal.dat",ios::app|ios::out|ios::binary);
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>NIT>>Pelicula>>costo;
                while (!baseDatos.eof()){
                    if (busquedaDatos!=documentoIdentificacion){
                        modBaseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< NIT << std::left<<std::setw(15)<< Pelicula << std::left<<std::setw(15)<< costo <<"\n";
                    }
                    else {
                        cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
                        cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
                        cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
                        cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
                        cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
                        cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
                        cout << "\t\tIngrese el NIT a ingresar "; cin >> NIT;
                        cout << "\t\tIngrese la Nombre de la Pelicula "; cin>>Pelicula;
                        cout << "\t\tIngrese el costo del Ticket "; cin>>costo;
                        modBaseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< NIT << std::left<<std::setw(15)<< Pelicula << std::left<<std::setw(15)<< costo <<"\n";
                    }
                    baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>NIT>>Pelicula>>costo;
                }
                modBaseDatos.close();
                baseDatos.close();
                remove("clientes.dat");
                rename("temporal.dat","empleados.dat");
                cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU CATALOGOS--";
                    return menuCatalogos();
                }
            }
    }
    void BAJA(){
            std::fstream bitacora;
            bitacora.open("bitacora.dat",ios::app|ios::in|ios::out|ios::binary);
            bitacora<<std::left<<std::setw(15)<<"menu eliminar";
            bitacora.close();
        system("cls");
        int datos=0;
        fstream baseDatos, modBaseDatos;
        cout << "\n\t\t\tEntrando al menu --ELIMINAR--" << endl;
            baseDatos.open("clientes.dat",ios::in|ios::binary);
            if(!baseDatos){
                cout << "\n\t\tNo se encontro el archivo" << endl;
                baseDatos.close();
                cout << "\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU CATALOGOS--";
                    return menuCatalogos();
                }
            }
            else {
                cout << "\n\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
                modBaseDatos.open("temporal.dat",ios::app|ios::out|ios::binary);
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>NIT>>Pelicula>>costo;
                while (!baseDatos.eof()){
                    if (busquedaDatos!=documentoIdentificacion){

                        modBaseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono << std::left<<std::setw(15)<< direccion << std::left<<std::setw(15)<< NIT << std::left<<std::setw(15)<< Pelicula << std::left<<std::setw(15)<< costo <<"\n";
                    }
                    else {
                        datos++;
                        cout << "\n\t\tLa informacion se a borrado con exito...";
                    }
                    baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>NIT>>Pelicula>>costo;
                }
                if (datos==0){
                    cout << "\n\t\t\tNo se encontraron coincidencias, Revise el numero del Documento de Identificacion e intentelo de nuevo...";
                    cout << "\n\n\t\tPresione s para intentarlo de nuevo "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\t\nRegresando al --MENU CATALOGOS--";
                    return menuCatalogos();
                    }
                }
                modBaseDatos.close();
                baseDatos.close();
                remove("clientes.dat");
                rename("temporal.dat","empleados.dat");
                cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU CATALOGOS--";
                    return menuCatalogos();
                }
            }
    }
    void Lectura(){
            std::fstream bitacora;
            bitacora.open("bitacora.dat",ios::app|ios::in|ios::out|ios::binary);
            bitacora<<std::left<<std::setw(15)<<"menu Lectura";
            bitacora.close();
        system("cls");
        fstream baseDatos;
        cout << "\n\t\t\tEntrando al menu --MOSTRAR Lectura--";
        cout << "\n\n\t\t¿Quiere buscar a una persona en especifico? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            int datos=0;
            baseDatos.open("clientes.dat",ios::in|ios::binary);
            if(!baseDatos)
            {
                cout<<"\n\t\tError";
                cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            }
            else
            {
                cout << "\n\t\t\tEntrando en el menu --BUSCAR--"<<endl;
                cout << "\n\t\tIngrese el numero del Documento de Identificacion de la persona a buscar: "; cin >> busquedaDatos;
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>NIT>>Pelicula>>costo;
                while(!baseDatos.eof()){
                    if(busquedaDatos==documentoIdentificacion){
                        cout<<"\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                        cout<<"\n\t\tNombre: " << nombre;
                        cout<<"\n\t\tEdad: "<< edad;
                        cout<<"\n\t\tCorreo Electronico: "<< correo;
                        cout<<"\n\t\tTelefono: "<< telefono;
                        cout<<"\n\t\tDireccion: "<< direccion;
                        cout<<"\n\t\tNIT: "<< NIT;
                        cout<<"\n\t\tPelicula "<< Pelicula;
                        cout<<"\n\t\tCosto del boleto "<< costo;
                        datos++;
                    }
                    baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>NIT>>Pelicula>>costo;
                }
                if(datos==0)
                {
                    cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                }
                cout << "\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\t\nRegresando al --MENU LECTURA--";
                    return Lectura();
                }
                baseDatos.close();
            }
        }
        else {
            fstream baseDatos;
            int total=0;
            cout<<"\n\t\t\tEntrando al --MENU LECTURA "<<endl;
            baseDatos.open("clientes.dat",ios::in|ios::binary);
            if(!baseDatos){
                cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
                baseDatos.close();
                cout << "\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\t\nRegresando al --MENU CATALOGOS--";
                    return menuCatalogos();
                }
            }
            else
            {
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>NIT>>Pelicula>>costo;
                while(!baseDatos.eof())
                {
                    total++;
                    cout<<"\n\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                    cout<<"\n\t\tNombre: " << nombre;
                    cout<<"\n\t\tEdad: "<< edad;
                    cout<<"\n\t\tCorreo Electronico: "<< correo;
                    cout<<"\n\t\tTelefono: "<< telefono;
                    cout<<"\n\t\tDireccion: "<< direccion;
                    cout<<"\n\t\tNIT"<< NIT;
                    cout<<"\n\t\tPelicula "<< Pelicula;
                    cout<<"\n\t\tCosto de la pelicula "<< costo;
                    baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>NIT>>Pelicula>>costo;
                }
                if(total==0){
                    cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                }
                cout << "\n\n\t\tPresione s para salir "; cin >>desicion;
                if (desicion=="s"){
                    cout <<"\t\t\nRegresando al --MENU CATALOGOS--";
                    return menuCatalogos();
                }
            }
            baseDatos.close();
        }
    }
    void menuPrincipal(){
        system ("cls");
        int menu;
        fstream bienvenida;
        string line;
        bienvenida.open("bienvenidos.txt");
        if(bienvenida.is_open()){
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(bienvenida, line))
        {
            cout << line << endl;
        }
        bienvenida.close();
        }
        cout << "\n\t\tPresione i para ingresar al --PROGRAMA-- : ";cin>>desicion;
        if (desicion=="i"){
            cout << "\n\t\t\tBienvenido al programa de ==CORPORACION CINE=";
               cout << "\n\t\t\tNUESTRA CARTELERA-----------------...........";
            cout << "\n\t\t\t------------------BATMAN----------------";
            cout << "\n\t\t\t-----------SPIDER MAN NO WAY HOME----";
            cout << "\n\t\t\t---ANIMALES FANTASTICO.SECRETO DE DUMBLEDORE----";
            cout << "\n\t\t\t-----------LA CIUDAD PERDIDA--------";
            cout << "\n\t\t\t-----------------MORBIUS----------------";
            cout << "\n\t\t\t----------------SONIC 2-----------------";
             cout << "\n\t\t\t--------------------------------------------------------------------------------";
            cout << "\n\n\t\tElija el numero del menu al que quiera ingresar\n"<< endl << "\t\t[1] CATALOGOS\n" << "\t\t[2] PROCESOS" << "\t\t[3] INFORMES\n" << "\t\t[4] SALIR DEL SISTEMA\n" ;cout<<"\n\t\t";cin >> menu;

            switch(menu){
            case 1:
                menuCatalogos();

                break;
            case 2:
                menuProceso();
                break;
            case 3:
                menuInformes();
                break;
            case 4:
                cout << "\n\t\t¿Quiere salir del programa? [ si / no ] : "; cin>>desicion;
                if (desicion=="si"){
                    return exit (0);
                }
                else {
                    return menuPrincipal();
                break;
                }
            }
        }
    }
    void menuCatalogos(){
        system("cls");
        int menu;
        cout << "\n\t\tBienvenido al --MENU CATALOGOS--" << endl;
        cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] ALTA\n" << "\t\t[2] BAJA\n" << "\t\t[3] MODIFICACIONES\n" << "\t\t[4] lECTURA\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
        switch (menu){
        case 1:
            Alta();
            break;
        case 2:
            BAJA();
            break;
        case 3:
            modificaciones();
            break;
        case 4:
            Lectura();
            break;
        case 5:
            cout << "\tSaliendo al --MENU PRINCIPAL--" << endl;
            return menuPrincipal();
            break;
            }
    }
    void menuProceso(){
                system("cls");
        int menu;
        cout << "\n\t\tBienvenido al --MENU CATALOGOS--" << endl;
        cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] ALTA\n" << "\t\t[2] BAJA\n" << "\t\t[3] MODIFICACIONES\n" << "\t\t[4] lECTURA\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
        switch (menu){
        case 1:
            Alta();
            break;
        case 2:
            BAJA();
            break;
        case 3:
            modificaciones();
            break;
        case 4:
            Lectura();
            break;
        case 5:
            cout << "\tSaliendo al --MENU PRINCIPAL--" << endl;
            return menuPrincipal();
            break;
            }
    }

    void menuInformes(){
              system("cls");
        int menu;
        cout << "\n\t\tBienvenido al --MENU CATALOGOS--" << endl;
        cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] ALTA\n" << "\t\t[2] BAJA\n" << "\t\t[3] MODIFICACIONES\n" << "\t\t[4] lECTURA\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
        switch (menu){
        case 1:
            Alta();
            break;
        case 2:
            BAJA();
            break;
        case 3:
            modificaciones();
            break;
        case 4:
            Lectura();
            break;
        case 5:
            cout << "\tSaliendo al --MENU PRINCIPAL--" << endl;
            return menuPrincipal();
            break;
            }
    }

private:
    string documentoIdentificacion, nombre, direccion, edad, correo, telefono, NIT, Pelicula, costo, desicion, busquedaDatos;;
};

class empleado : public CINE{
private:
    string documentoIdentificacion, nombre, direccion, edad, correo, telefono, NIT, Pelicula, costo, desicion, busquedaDatos;;
};

class Proceso: public CINE{
   string documentoIdentificacion, nombre, direccion, edad, correo, telefono, NIT, Pelicula, costo, desicion, busquedaDatos;;
};

class informes : public CINE{
   string documentoIdentificacion, nombre, direccion, edad, correo, telefono, NIT, Pelicula, costo, desicion, busquedaDatos;;
};


class bitacora{
public:
    void ingreso();
};

 int main(){
    system ("cls");
    string usuario, contrasena, config1, config2;
    fstream usuariosContrasenas, bitacora;
    usuariosContrasenas.open("seguridad.dat",ios::app|ios::in|ios::binary);
    if(!usuariosContrasenas){
        cout<<"\n\t\tError";
        cout<<"\n\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
    }
    else{
        cout << "\n\t\t\tPROGRAMA DE DIEGO CULAJAY 9959-20-9491" << endl;
        cout << "\n\t\tIngrese su usuario: "; cin >> usuario;
        cout << "\n\t\tIngrese su contrasena: "; cin >> contrasena;
        usuariosContrasenas>>config1>>config2;
        //while (!usuariosContrasenas.eof()){
            if (usuario=="admin" && contrasena =="123"){
                bitacora.open("bitacora.dat",ios::app|ios::in|ios::out|ios::binary);
                bitacora<<std::left<<std::setw(15)<<usuario;
                bitacora.close();
                empleado prueba;
                prueba.menuPrincipal();
            }
            else{
                cout << "\n\t\t\tPermiso denegado\a";
                exit(0);
            }
        //}
    }
};
