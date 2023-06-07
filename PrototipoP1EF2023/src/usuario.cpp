#include "usuario.h"
#include "bitacora.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;
string codigo;
bitacora bit;
void usuario::menuAdministrador()
{
    int Opciones;
	char x;
	do
    {
	system("cls");
	cout << "\t\t\t*==============================*" << endl;
	cout << "\t\t\t|   INGRESO DE ADMINISTRADOR   |" << endl;
	cout << "\t\t\t*==============================*" << endl;
	cout << "\t\t\t 0. Datos del estudiante" << endl;
	cout << "\t\t\t 1. Ingresar Administrador" << endl;
	cout << "\t\t\t 2. Salir del sistema" << endl;
	cout << "\t\t\t*==============================*" << endl;
	cout << "\t\t\t    Opciones a escoger:[0/1/2]  " << endl;
	cout << "\t\t\t*==============================*" << endl;
	cout << "\t\t\t    Ingresa una Opcion: ";
    cin >> Opciones;
    switch(Opciones)
    {
    case 0:
        system("cls");
        cout << "*============================================*" << endl;
        cout << "|| EXAMEN FINAL DEL CURSO DE PROGRAMACION I ||" << endl;
        cout << "*============================================*" << endl;
        cout << std::endl;
        cout << "    UUUU   UUUU   MMMM     MMM   GGGGGG   " << endl;
        cout << "    UUUU   UUUU   MMMMM   MMMM  GGGGGGGG  " << endl;
        cout << "    UUUU   UUUU   MMMMMM MMMMM GGG        " << endl;
        cout << "    UUUU   UUUU   MMM MMMM MMM GGG   GGGGG " << endl;
        cout << "    UUUU   UUUU   MMM  MM  MMM GGG    GGGG  " << endl;
        cout << "    UUUU   UUUU   MMM      MMM  GGGGGGGGG   " << endl;
        cout << "    UUUUUUUUUUU   MMM      MMM   GGGGGGG  " << endl;
        cout << "     UUUUUUUUU    MMM      MMM    GGGGG   " << endl;
        cout << endl;
        cout << "=============================================" << endl;
        cout << "||             DATOS DEL ALUMNO            ||" << endl;
        cout << "=============================================" << endl;
        cout << "||                9959-22-5755             ||" << endl;
        cout << "||        Erick Alexander Solares Rosales  ||" << endl;
        cout << "||               Sede: Portales            ||" << endl;
        cout << "=============================================" << endl;
        cout << std::endl;
        break;
    case 1:
        insertarAdministrador();
		break;
	case 2:
	    system("cls");
	    cout << "          __^__                                     __^__"<< endl;
        cout << "         ( ___ )===================================( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
        cout << "          |___|            vuelva pronto            |___|"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)===================================(_____)"<< endl;
		exit(0);
	default:
	    std::cout << "=====================================================" << std::endl;
        std::cout << "||  Opcion invalida...Por favor prueba otra vez..  ||" << std::endl;
        std::cout << "=====================================================" << std::endl;
	}
	getch();
    }while(Opciones!= 4);
}
void usuario::insertarAdministrador()
{

    vector<string> usuarios;
    vector<string> claves;

    usuarios.push_back("Erick");

    claves.push_back("ERI");

    int contador = 0;
    bool ingresa = false;
    do
    {
        system("cls");
        fstream file;
        cout << "               __^__                                     __^__"<< endl;
        cout << "             ( ___ )===================================( ___ )"<< endl;
        cout << "               | / |                                     | / |"<< endl;
        cout << "               | / | INGRESA LOS DATOS DE ADMINISTRACION | / |"<< endl;
        cout << "               |___|                                     |___|"<< endl;
        cout << "             (_____)===================================(_____)"<< endl;
        cout << "             ================================================="<< endl;
        cout << "===============================================================================" << endl;
        cout << "||                           AYUDA PARA INGRESAR                             ||" << endl;
        cout << "==============================================================================" << endl;
        cout << "||  USUARIO: Nombre del usuario                                              ||" << endl;
        cout << "||  PASSWORD: ***********                                                    ||" << endl;
        cout << "===============================================================================" << endl;
        cout << "\t\t\tIngresa Usuario \n";

        cout << "\t\t\tUsuario: ";
        cin >> nameAdministrador;

        char caracter;
        cout << "\t\t\tPassword: ";
        caracter = getch();
        getline(cin, passwordAdministrador);

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                passwordAdministrador.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (passwordAdministrador.length() > 0)
                {
                    cout << "\b \b";
                    passwordAdministrador = passwordAdministrador.substr(0, passwordAdministrador.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == nameAdministrador && claves[i] == passwordAdministrador)
            {
                ingresa = true;
                break;
            }
        }
        if (!ingresa)
        {
            system("cls");
            std::cout << "=====================================================" << std::endl;
            std::cout << "||     El usuario y/o password son incorrectos     ||" << std::endl;
            std::cout << "=====================================================" << std::endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        system("cls");
        std::cout << "================================================================" << std::endl;
        std::cout << "||  Haz fallado 3 veces, no puedes acceder al sistema. ADIOS  ||" << std::endl;
        std::cout << "================================================================" << std::endl;
        codigo="7000";
        bitacora bit;
        bit.ingreso(nameAdministrador,codigo);
    }

    else
    {
    codigo="7001";
    bitacora bit2;
    bit2.ingreso(nameAdministrador,codigo);
    int Opciones;
	char x;
	do
    {
	system("cls");
	std::cout << "**=========================================================================================================**" << std::endl;
	std::cout << "||       BBBBBB   IIII   EEEEEEE  NN     NN   VV     VV   EEEEEEE   NN    NN   IIII   DDDDDD   OOOOOOO     ||" << std::endl;
    std::cout << "||       BB   BB   II    EE       NNNN   NN   VV     VV   EE        NNNN  NN    II    DD   DD  OO   OO     ||" << std::endl;
    std::cout << "||       BBBBBB    II    EEEEE    NN NN  NN    VV   VV    EEEEE     NN NN NN    II    DD   DD  OO   OO     ||" << std::endl;
    std::cout << "||       BB   BB   II    EE       NN   NNNN     VV VV     EE        NN  NNNN    II    DD   DD  OO   OO     ||" << std::endl;
    std::cout << "||       BBBBBB   IIII   EEEEEEE  NN    NNN       V       EEEEEEE   NN   NNN   IIII   DDDDDD   OOOOOOO     ||" << std::endl;
    std::cout << "**=========================================================================================================**" << std::endl;
    std::cout << "||                       Bienvenido, " << nameAdministrador << " al programa de recetas medicas                          ||" << std::endl;
    std::cout << "**=========================================================================================================**" << std::endl;
    std::cout << std::endl;
    system("pause");
    system("cls");
    cout << "" << endl;
    cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
    cout << "          __^__                                     __^__"<< endl;
    cout << "         ( ___ )===================================( ___ )"<< endl;
    cout << "          | / |                                     | / |"<< endl;
    cout << "          | / |            MENU General             | / |"<< endl;
    cout << "          |___|                                     |___|"<< endl;
    cout << "         (_____)===================================(_____)"<< endl;
    cout << "\        ================================================="<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                 |   Porfavor, elije una opcion  |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 | 1. Procesos                   |"<< endl;
    cout << "                 | 2. Informes                   |"<< endl;
    cout << "                 | 3. Cerrar Sesion              |"<< endl;
    cout << "                 | 4. Salir del sistema          |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                      Ingresa una Opcion: ";
    cin >> Opciones;

    switch(Opciones)
    {
    case 1:
        menuTrabajador();
		break;
    case 2:
    system("cls");
    do
    {
        system("cls");
    cout << "" << endl;
    cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
    cout << "          __^__                                     __^__"<< endl;
    cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "          | / |                                     | / |"<< endl;
    cout << "          | / |            MENU DE INFORME          | / |"<< endl;
    cout << "          |___|                                     |___|"<< endl;
    cout << "         (_____)-----------------------------------(_____)"<< endl;
    cout << "\        -------------------------------------------------"<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                 |   Porfavor, elije una opcion  |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 | 1. Clientes                   |"<< endl;
    cout << "                 | 2. Bitacora                   |"<< endl;
    cout << "                 | 3. Aplicaciones               |"<< endl;
    cout << "                 | 4. Peliculas                  |"<< endl;
    cout << "                 | 5. Salir al menu inicial      |"<< endl;
    cout << "                 | 6. Salir del sistema          |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                   Ingresa una Opcion: ";
    cin >> Opciones;

        switch(Opciones)
        {
        case 1:
            desplegarTrabajador();
        break;
        case 2:
            bit.desplegarBitacora(nameAdministrador,"7500");
            break;
        case 3:
            system("cls");
            cout << "          __^__                                     __^__"<< endl;
            cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
            cout << "          | / |                                     | / |"<< endl;
            cout << "          | / |           CODIGOS DE CAMBIOS        | / |"<< endl;
            cout << "          |___|                                     |___|"<< endl;
            cout << "         (_____)-----------------------------------(_____)"<< endl;
            cout << "         -------------------------------------------------"<< endl;
            cout << "                   7000		INGRESOFALLIDO             "<< endl;
            cout << "                   7001		INGRESO                    "<< endl;
            cout << "                   7300		MENUCLIENTES               "<< endl;
            cout << "                   7301		+.CLIENTES                 "<< endl;
            cout << "                   7302		REP.CLIENTES               "<< endl;
            cout << "                   7303		MOD.CLIENTES               "<< endl;
            cout << "                   7304		BUSCAR.CLIENTES            "<< endl;
            cout << "                   7305		-.CLIENTES                 "<< endl;
            cout << "                   7400		REPAPLICACIONES            "<< endl;
            cout << "                   7500        MENUDEPARTAMENTOS          "<< endl;
            cout << "                   7501        REPADMINISTRACION          "<< endl;
            cout << "                   7502        REPVENTAS                  "<< endl;
            cout << "                   7999		LOG OUT                    "<< endl;
            cout << "         ------------------------ -------------------------"<< endl;
            bit.ingreso(nameAdministrador,"7400");
            system("pause");
            break;
        case 4:
            menuDepartamentos();
            bit.ingreso(nameAdministrador,"7500");
            break;
        case 5:
            system("cls");
            cout << "          __^__                                     __^__"<< endl;
            cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
            cout << "          | / |                                     | / |"<< endl;
            cout << "          |___|    Redireccionando al inicio....    |___|"<< endl;
            cout << "          |___|                                     |___|"<< endl;
            cout << "         (_____)-----------------------------------(_____)"<< endl;
                return;
        case 6:
        system("cls");
	    bitacora bit;
        codigo="7999";
        bit.ingreso(nameAdministrador,codigo);
        cout << "" << endl;
        cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
        cout << "" << endl;
	    cout << "          __^__                                     __^__"<< endl;
        cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
        cout << "          |___|            vuelva pronto            |___|"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)-----------------------------------(_____)"<< endl;
		exit(0);
	default:
		cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(Opciones!= 4);
    break;
	case 3:
	    system("cls");
	    cout << "          __^__                                     __^__"<< endl;
        cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
        cout << "          |___|    Redireccionando al inicio....    |___|"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)-----------------------------------(_____)"<< endl;
		return;
		bitacora bit;
        codigo="7999";
        bit.ingreso(nameAdministrador,codigo);
    case 4:
        system("cls");
	    cout << "          __^__                                     __^__"<< endl;
        cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
        cout << "          |___|            vuelva pronto            |___|"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)-----------------------------------(_____)"<< endl;
		exit(0);
        codigo="7999";
        bit.ingreso(nameAdministrador,codigo);
	default:
		cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(Opciones!= 3);
}
}

void usuario::menuTrabajador()
{
    int Opciones;
	char x;
	do
    {
    system("cls");
	bitacora bit;
	codigo="7300";
	bit.ingreso(nameAdministrador,codigo);
    cout << "" << endl;
    cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
    cout << "          __^__                                     __^__"<< endl;
    cout << "         ( ___ )===================================( ___ )"<< endl;
    cout << "          | / |                                     | / |"<< endl;
    cout << "          | / |             CINE UMG                | / |"<< endl;
    cout << "          |___|                                     |___|"<< endl;
    cout << "         (_____)===================================(_____)"<< endl;
    cout << "\        ================================================="<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                 |   Porfavor, elije una opcion  |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 | 1. Ingresar datos cliente     |"<< endl;
    cout << "                 | 2. Desplegar cliente          |"<< endl;
    cout << "                 | 3. Modificar cliente          |"<< endl;
    cout << "                 | 4. Buscar cliente             |"<< endl;
    cout << "                 | 5. Borrar cliente             |"<< endl;
    cout << "                 | 6. Regresar al inicio         |"<< endl;
    cout << "                 | 7. Salir del sistema          |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                    Ingresa una Opcion: ";
    cin >> Opciones;
    switch(Opciones)
    {
    case 1:
    	do
    	{
    		insertarTrabajador();
    		cout << "          __^__                                     __^__"<< endl;
            cout << "         ( ___ )===================================( ___ )"<< endl;
            cout << "          | / |                                     | / |"<< endl;
            cout << "          | / |  Desea gregar un nuevo cliente   ?  | / |"<< endl;
            cout << "          |___|                                     |___|"<< endl;
            cout << "         (_____)===================================(_____)"<< endl;
            cout << "         =================================================" <<endl;
            cout << "                Pulsa Y para si ||| Pulsa N para No     " <<endl;
            cout << "         =================================================" <<endl;
            cout << "                Selecciona una respuesta: ";
    		cin >> x;
		}while(x == 'y'||x == 'Y');
		break;
	case 2:
		desplegarTrabajador();
		break;
	case 3:
		modificarTrabajador();
		break;
	case 4:
		buscarTrabajador();
		break;
	case 5:
		borrarTrabajador();
		break;
    case 6:
        system("cls");
        cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
        cout << "" << endl;
        cout << "          __^__                                     __^__"<< endl;
	    cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
        cout << "          |___|    Redireccionando al inicio....    |___|"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)-----------------------------------(_____)"<< endl;
                break;
	case 7:
	    system("cls");
	    bitacora bit;
        codigo="7999";
        bit.ingreso(nameAdministrador,codigo);
        cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
        cout << "" << endl;
	    cout << "          __^__                                     __^__"<< endl;
        cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
        cout << "          | / |                                     | / |"<< endl;
        cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
        cout << "          |___|            vuelva pronto            |___|"<< endl;
        cout << "          |___|                                     |___|"<< endl;
        cout << "         (_____)-----------------------------------(_____)"<< endl;
        exit(0);
	default:
		cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(Opciones!= 6);
}
void usuario::insertarTrabajador()
{
	system("cls");
	fstream file;
    cout << "" << endl;
    cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
    cout << "          __^__                                     __^__"<< endl;
    cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "          | / |                                     | / |"<< endl;
    cout << "          | / |    Agregar informacion cliente      | / |"<< endl;
    cout << "          |___|                                     |___|"<< endl;
    cout << "         (_____)-----------------------------------(_____)"<< endl;
	cout << "\t\t  Ingresa ID del cliente : ";
	cin >> ID;
	cout << "\t\t  Ingresa Nombre del cliente : ";
	cin >> name;
	cout << "\t\t  Ingresa Apellido del cliente : ";
	cin >> apellido;
	cout << "\t\t  Ingresa DPI del cliente : ";
	cin >> dpi;
	cout << "\t\t  Ingresa el numero de telefono del cliente : ";
	cin >> telefono;
	cout << "\t\t  Ingrese Pelicula M/S/G/R(Mario Bros, SpiderMan, Guardianes de la galaxia, Rapidos y furiosos ): ";
	cin >> Pelicula;
    system("cls");
    cout << "=============================================" <<endl;
    cout << "||      Listo! nuevo cliente agregado     ||" <<endl;
    cout << "=============================================" <<endl;
	if (Pelicula=="M")
    {
        Pelicula="Mario";
        file.open("Mario.txt", ios::app | ios::out);
        file << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << apellido << std::left << std::setw(15) << dpi << std::left << std::left << std::setw(15)<< telefono << std::setw(15)<< Pelicula << "\n";
        bitacora bit;
        codigo="7301";
        bit.ingreso(nameAdministrador,codigo);
        file.close();
    }
    if (Pelicula=="S")
    {
        Pelicula="SpiderMan";
        file.open("SpiderMan.txt", ios::app | ios::out);
        file << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << apellido << std::left << std::setw(15) << dpi << std::left << std::left << std::setw(15)<< telefono << std::setw(15)<< Pelicula << "\n";
        codigo="7301";
        bit.ingreso(nameAdministrador,codigo);
        file.close();
    }
    if (Pelicula=="G")
    {
        Pelicula="Guardianes";
        file.open("Guardianes.txt", ios::app | ios::out);
        file << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << apellido << std::left << std::setw(15) << dpi << std::left << std::left << std::setw(15)<< telefono << std::setw(15)<< Pelicula << "\n";
        bitacora bit;
        codigo="7301";
        bit.ingreso(nameAdministrador,codigo);
        file.close();
    }
    if (Pelicula=="R")
    {
        Pelicula="Rapidos";
        file.open("Rapidos.txt", ios::app | ios::out);
        file << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << apellido << std::left << std::setw(15) << dpi << std::left << std::left << std::setw(15)<< telefono << std::setw(15)<< Pelicula << "\n";
        bitacora bit;
        codigo="7301";
        bit.ingreso(nameAdministrador,codigo);
        file.close();
    }
    file.open("Usuarios.txt", ios::app | ios::out);
    file << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << dpi << std::left << std::left << std::setw(15)<< telefono << std::setw(15)<< Pelicula << "\n";
	bitacora bit;
	codigo="7301";
	bit.ingreso(nameAdministrador,codigo);
	file.close();
}
void usuario::desplegarTrabajador()
{
	system("cls");
	fstream file;
	string ver;
	int total = 0;
    cout << "" << endl;
    cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
	cout << "                     __^__                                     __^__"<< endl;
    cout << "                    ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "                     | / |                                     | / |"<< endl;
    cout << "                     | / |    Tabla de Detalles de Paciente    | / |"<< endl;
    cout << "                     |___|                                     |___|"<< endl;
    cout << "                    (_____)-----------------------------------(_____)"<< endl;
    cout << "===============================================================================================" << endl;
    cout << "ID             NOMBRE          APELLIDO          DPI         TELEFONO         ENFERMEDAD       " << endl;
    cout << "===============================================================================================" << endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		while(!file.eof())
		{
			total++;
			getline(file,ver);
            cout << ver << endl;
		}
		if(total == 0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
    bitacora bit;
	codigo="7302";
	bit.ingreso(nameAdministrador,codigo);
}
void usuario::modificarTrabajador()
{
	system("cls");
	fstream file,file1;
	string user_ID;
	int found = 0;
	cout << "\n-------------------------Modificacion Detalles Usuario-------------------------"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{   cout << "" << endl;
	    cout << "\n\tUsuario: " << nameAdministrador << endl << endl;
		cout << "\n Ingrese ID del usuario que quiere modificar: ";
		cin >> user_ID;
		file1.open("Record.txt",ios::app | ios::out);
		        file >> ID >> name >> apellido >> dpi >> telefono >> Pelicula ;
		while(!file.eof())
		{
			if(user_ID!=ID)
			{
                file1 << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << apellido << std::left << std::setw(15) << dpi << std::left << std::left << std::setw(15)<< telefono << std::setw(15)<< Pelicula << "\n";
			}
			else
			{
				cout << "\t\t\tIngrese ID Persona: ";
				cin >> ID;
				cout << "\t\t\tIngrese Nombre Persona: ";
				cin >> name;
				cout << "\t\t\tIngrese Contrasena Persona: ";
				cin >> dpi;
				cout << "\t\t\tIngrese Telefono Persona: ";
				cin >> telefono;
				cout << "\t\t\tIngrese Departamento Persona: ";
				cin >> Pelicula;
                file1 << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << dpi << std::left << std::left << std::setw(15)<< telefono << std::setw(15)<< Pelicula << "\n";
				found++;
			}
			        file >> ID >> name >> apellido >> dpi >> telefono >> Pelicula ;

		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
        bitacora bit;
        codigo="7303";
        bit.ingreso(nameAdministrador,codigo);
	}
}
void usuario::buscarTrabajador()
{
	system("cls");
	fstream file;
	int found = 0;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{

		cout << "\n-------------------------Datos del Trabajador buscada------------------------" << endl;
		cout << "\n\t\t\tNo hay informacion...";
	}
	else
	{
		string user_ID;
        cout << "" << endl;
        cout << "\t\t    Nombre Administrador: " << nameAdministrador << endl;
		cout << "          __^__                                      __^__"<< endl;
        cout << "         ( ___ )------------------------------------( ___ )"<< endl;
        cout << "          | / |                                      | / |"<< endl;
        cout << "          | / |     Datos del Paciente buscado     | / |"<< endl;
        cout << "          |___|                                      |___|"<< endl;
        cout << "         (_____)------------------------------------(_____)"<< endl;
		cout << "\nIngrese ID de la Persona que quiere buscar: ";
		cin >> user_ID;
		file >> ID >> name >> dpi >> telefono >> Pelicula ;
		while(!file.eof())
		{
			if(user_ID == ID)
			{
				cout << "                 *============================* "<< endl;
                cout << "                                              "<< endl;
                cout << "                   ID Trabajador: "<< ID << endl;
                cout << "                   Nombre Trabajador : "<< name << endl;
                cout << "                   DPI de Paciente : "<< dpi << endl;
                cout << "                   Enfermedad del paciente"<< Pelicula << endl;
                cout << "                   Telefono: "<< telefono << endl;
                cout << "                                              "<< endl;
                cout << "                 *============================* "<< endl;
				found++;
			}
			file >> ID >> name >> dpi >> telefono >> Pelicula ;
		}
		if(found == 0)
		{
			cout<<"\n\t\t\t Paciente no encontrado...";
		}
		file.close();
		bitacora bit;
        codigo="7304";
        bit.ingreso(nameAdministrador,codigo);
	}
}
void usuario::borrarTrabajador()
{
	system("cls");
	fstream file,file1;
	string user_ID;
	int found = 0;
	cout << "\n-------------------------Detalles Paciente a Borrar-------------------------" << endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{   cout << "" << endl;
	    cout << "\n\tUsuario: " << nameAdministrador << endl << endl;
		cout << "\n Ingrese el ID del Paciente que quiere borrar: ";
		cin >> user_ID;
		file1.open("Record.txt",ios::app | ios::out);
        file >> ID >> name >> dpi >> telefono >> Pelicula ;
		while(!file.eof())
		{
			if(user_ID!=ID)
			{
                file1 << std::left << std::setw(15) << ID << std::left << std::setw(15) << name << std::left << std::setw(15) << dpi << std::left << std::left << std::setw(15)<< telefono << std::setw(15)<< Pelicula << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
        file >> ID >> name >> dpi >> telefono >> Pelicula ;
		}
		if(found == 0)
		{
			cout<<"\n\t\t\t ID Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
        bitacora bit;
        codigo="7304";
        bit.ingreso(nameAdministrador,codigo);
	}
}
void usuario::desplegarAdministracion()
{
	system("cls");
	fstream file;
	string ver;
	int total = 0;
    cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
	cout << "     __^__                                     __^__"<< endl;
    cout << "    ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "     | / |                                     | / |"<< endl;
    cout << "     | / |    Tabla de Peliculas               | / |"<< endl;
    cout << "     |___|            Pelicula de Mario        |___|"<< endl;
    cout << "     |___|                                     |___|"<< endl;
    cout << "    (_____)-----------------------------------(_____)"<< endl;
    cout << "====================================================" << endl;
    cout << "ID             NOMBRE       DPI         TELEFONO    " << endl;
    cout << "====================================================" << endl;
	file.open("Mario.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		while(!file.eof())
		{
			total++;
			getline(file,ver);
            cout << ver << endl;
		}
		if(total == 0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
    bitacora bit;
	codigo="7501";
	bit.ingreso(nameAdministrador,codigo);
}
void usuario::desplegarVentas()
{
	system("cls");
	fstream file;
	string ver;
	int total = 0;
    cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
    cout << "     __^__                                     __^__"<< endl;
    cout << "    ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "     | / |                                     | / |"<< endl;
    cout << "     | / |    Tabla de Peliculas               | / |"<< endl;
    cout << "     |___|            Pelicula de Guardianes   |___|"<< endl;
    cout << "     |___|                                     |___|"<< endl;
    cout << "    (_____)-----------------------------------(_____)"<< endl;
    cout << "====================================================" << endl;
    cout << "ID             NOMBRE       DPI         TELEFONO    " << endl;
    cout << "====================================================" << endl;
	file.open("Guardianes.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		while(!file.eof())
		{
			total++;
			getline(file,ver);
            cout << ver << endl;
		}
		if(total == 0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
    bitacora bit;
	codigo="7502";
	bit.ingreso(nameAdministrador,codigo);
}
void usuario::desplegarContabilidad()
{
	system("cls");
	fstream file;
	string ver;
	int total = 0;
    cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
    cout << "     __^__                                     __^__"<< endl;
    cout << "    ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "     | / |                                     | / |"<< endl;
   cout << "     | / |    Tabla de Peliculas                | / |"<< endl;
    cout << "     |___|            Pelicula de SpiderMan    |___|"<< endl;
    cout << "     |___|                                     |___|"<< endl;
    cout << "    (_____)-----------------------------------(_____)"<< endl;
    cout << "====================================================" << endl;
    cout << "ID             NOMBRE       DPI         TELEFONO    " << endl;
    cout << "====================================================" << endl;
	file.open("SpiderMan.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		while(!file.eof())
		{
			total++;
			getline(file,ver);
            cout << ver << endl;
		}
		if(total == 0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
    bitacora bit;
	codigo="7501";
	bit.ingreso(nameAdministrador,codigo);
}
void usuario::desplegarRecepcion()
{
	system("cls");
	fstream file;
	string ver;
	int total = 0;
    cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
    cout << "" << endl;
    cout << "     __^__                                     __^__"<< endl;
    cout << "    ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "     | / |                                     | / |"<< endl;
    cout << "     | / |    Tabla de Peliculas               | / |"<< endl;
    cout << "     |___|            Pelicula de Rapidos      |___|"<< endl;
    cout << "     |___|                                     |___|"<< endl;
    cout << "    (_____)-----------------------------------(_____)"<< endl;
    cout << "====================================================" << endl;
    cout << "ID             NOMBRE       DPI         TELEFONO    " << endl;
    cout << "====================================================" << endl;
	file.open("Rapidos.txt",ios::in);
	if(!file)
	{
		cout << "\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		while(!file.eof())
		{
			total++;
			getline(file,ver);
            cout << ver << endl;
		}
		if(total == 0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
    bitacora bit;
	codigo="7501";
	bit.ingreso(nameAdministrador,codigo);
}
void usuario::menuDepartamentos()
{
    int Opciones;
    do
    {
    system("cls");
    cout << "" << endl;
    cout << "\t\t   Nombre Administrador: " << nameAdministrador << endl;
    cout << "          __^__                                     __^__"<< endl;
    cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
    cout << "          | / |                                     | / |"<< endl;
    cout << "          | / |         MENU DE ENFERMEDADES        | / |"<< endl;
    cout << "          |___|                                     |___|"<< endl;
    cout << "         (_____)-----------------------------------(_____)"<< endl;
    cout << "\        -------------------------------------------------"<< endl;
    cout << "                 *===============================*"<< endl;
    cout << "                 |   Porfavor, elije una opcion  |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 | 1. Mario 3:30 pm              |"<< endl;
    cout << "                 | 2. Guardianes 12:15 pm        |"<< endl;
    cout << "                 | 3. SpiderMan 16:45 pm         |"<< endl;
    cout << "                 | 4. Rapidos 8:00 am            |"<< endl;
    cout << "                 | 5. Salir del sistema          |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 |      Ingresa una Opcion       |"<< endl;
    cout << "                 |                               |"<< endl;
    cout << "                 *===============================*"<< endl;
    cin >> Opciones;

        switch(Opciones)
        {
        case 1:
            desplegarAdministracion();
            break;
        case 2:
            desplegarVentas();
            break;
        case 3:
            desplegarContabilidad();
            break;
        case 4:
            desplegarRecepcion();
            break;
        case 5:
            system("cls");
            bitacora bit;
            codigo="7999";
            bit.ingreso(nameAdministrador,codigo);
            cout << "\t\t\tNombre Administrador: " << nameAdministrador << endl;
            cout << "" << endl;
            cout << "          __^__                                     __^__"<< endl;
            cout << "         ( ___ )-----------------------------------( ___ )"<< endl;
            cout << "          | / |                                     | / |"<< endl;
            cout << "          | / |     Muchas gracias por ingresar     | / |"<< endl;
            cout << "          |___|            vuelva pronto            |___|"<< endl;
            cout << "          |___|                                     |___|"<< endl;
            cout << "         (_____)-----------------------------------(_____)"<< endl;
            exit(0);
	default:
		cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(Opciones!= 5);
}
