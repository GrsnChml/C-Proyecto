#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <ctime>
#include <time.h>
#include <vector>
using namespace std;

/************************
* registros de Clientes *
************************/
struct DatosCliente3
{
	char Nombre[20];
	int Nit;
	char Direccion[25];
};

DatosCliente3 DatosCliente[500];
int Clientes=0;

/*************************
* Registros de Productos *
*************************/
struct DatosProductos4
{
	char Nombre[15];
	char Codigo[5];
	int Cantidad;
	double Precio;
	double Total;
};

DatosProductos4 DatosProductos[500];
int Productos=0;

/*************************
*
************************/
struct DatosFactura1 
{
	char Fecha[25];
	char FacturaSerie[10];
};

DatosFactura1 DatosFactura[500];
int NoFactura=0;

void gotoxy(int x, int y);
void Menuprincipal();
void Carga();
void Carga1();
//void FechaHora();
int MostrarProducto();
int MostrarClientes();
int GuardarReportes();
int CargarReportes();
int Facturar();

char SerieFactura[5];
void Permutaciones(char *, int l=0); 
int main()
{
	char palabra[] = "0123456";   
	Permutaciones(palabra);
	
	cin.get();
	return 0;
	Menuprincipal();
}

void Menuprincipal()
{
	int Opcion;
	system("cls");
	
	for(int i=0; i < 55; i++)
	{
		gotoxy(20+i,6);
		cout<<(char)176;
		
		gotoxy(20+i,28);
		cout<<(char)176;
		Sleep(10);
	}
	for(int i=0; i < 22; i++)
	{
		gotoxy(20,6+i);
		cout<<(char)176;
		
		gotoxy(74,6+i);
		cout<<(char)176;
		Sleep(10);
	}
	
//	FechaHora();
	gotoxy(41,8);
	cout<<"BIENVENIDOS";
	gotoxy(21,14);
	cout<<"1) Facturar."<<endl;
	gotoxy(21,15);
	cout<<"2) Mostrar Productos."<<endl;
	gotoxy(21,16);
	cout<<"3) Mostrar Clientes."<<endl;
	gotoxy(21,17);
	cout<<"4) Guardar Reportes."<<endl;
	gotoxy(21,18);
	cout<<"5) Cargar Reportes."<<endl;
	gotoxy(21,19);
	cout<<"6) Mostrar Proveedores."<<endl;
	gotoxy(21,20);
	cout<<"0) Salir."<<endl;
	gotoxy(47,27);
	cin>>Opcion;
	
	switch(Opcion)
	{		
		case 1:
			Facturar();
		break;
		
		case 2:
			MostrarProducto();
		break;
		
		case 3:
			MostrarClientes();
		break;
		
		case 4:
			GuardarReportes();
		break;
		
		case 5:
			CargarReportes();
		break;
			
		case 6:
			CargarProveedores();
		break;
		
		case 0:
			system("cls");
			Carga();
			gotoxy(43,18);
			cout<<"Saliendo...";
			exit(1);
		break;
				
		default:
		{
			cout<<"\n\nDATO INGRESADO NO VALIDO!!";
			main();
		}
	}
}

/*************************
*    Creacion Factura    *
*************************/
int Facturar()
{
	char intentar;
	char regresar;
	char Serie;
	
	do
	{
		char nombre[20];
		int nit=0;
		char direccion[25];
		char fecha[25];
		
		system("cls");
		for(int i=0; i < 55; i++)
		{
			gotoxy(20+i,6);
			cout<<(char)176;
			
			gotoxy(20+i,28);
			cout<<(char)176;
			Sleep(10);
		}
		
		for(int i=0; i < 22; i++)
		{
			gotoxy(20,6+i);
			cout<<(char)176;
			
			gotoxy(74,6+i);
			cout<<(char)176;
			Sleep(10);
		}
		gotoxy(38,7);	
		cout<<"CREACION FACTURA";
		gotoxy(21,10);
		cout<<"No. Factura: "<<NoFactura+1<<endl;
		gotoxy(21,11);
		cout<<"Fecha: ";
		cin>>fecha;
		cin.ignore(25,'\n');
		gotoxy(21,12);
		cout<<"Nombre: ";
		cin.getline(nombre, 20);
		gotoxy(21,13);
		cout<<"Direccion: ";
		cin.getline(direccion,25);
		gotoxy(21,14);
		cout<<"Nit: ";
		cin>>nit;
		gotoxy(21,16);
		cout<<"Guardar (Si/s)(No/n)";
		cin>>intentar;
		
		if(intentar== 'S' || intentar=='s')
		{
			for(int i=0; i < 20; i++)
			{
				DatosCliente[Clientes].Nombre[i]=nombre[i];
			}
			
			for(int i=0; i < 25; i++)
			{
				DatosCliente[Clientes].Direccion[i]=direccion[i];
			}
		
			for(int i=0; i < 25; i++)
			{
				DatosFactura[NoFactura].Fecha[i]=fecha[i];
			}
			
			DatosCliente[Clientes].Nit=nit;
			Clientes++;
			NoFactura++;
			gotoxy(41,19);
			cout<<"Guardado!!";
			Sleep(2000);
		}
		else
		{
			cout<<"Informacion no almacenada";
		}
		
		system("cls");
	}while(intentar !='N' && intentar != 'n' && intentar !='S' && intentar != 's');

		gotoxy(30,2);
		cout<<"FACTURACION";
		gotoxy(5,6);
		cout<<"Fecha: "<<DatosFactura[NoFactura-1].Fecha;
		gotoxy(5,7);
		cout<<"Cliente: "<<DatosCliente[Clientes-1].Nombre;	
		gotoxy(5,8);
		cout<<"Nit: "<<DatosCliente[Clientes-1].Nit;
		gotoxy(5,9);
		cout<<"Direccion: "<<DatosCliente[Clientes-1].Direccion;
		gotoxy(5,10);
		cout<<"No. Factura: "<<NoFactura;
		if(NoFactura < 100)
		{
			gotoxy(5,11);
			cout<<"Serie: "<<DatosFactura[NoFactura-1].FacturaSerie[0];
		}
		else if(NoFactura >= 100 && NoFactura <= 199)
		{
			gotoxy(5,11);
			cout<<"Serie: "<<DatosFactura[NoFactura-1].FacturaSerie[1];
		}
		gotoxy(5,13);
		cout<<"Ingrese los Productos."<<endl;
		
		cout<<"| No. |";
		cout<<" Nombre d. Producto |";
		cout<<" Cantidad |";
		cout<<"  Precio  |";
		cout<<"  Codigo  |";
		cout<<"   Total   |"<<endl;
		
		
	int producto=0;
	int guardarOpcion=0;

	while(intentar !='N' && intentar != 'n')
	{

		char nombreProducto[15];
		double precio=0;
		int cantidad=0;
		char codigo[6];
		double total=0;
		
		gotoxy(1,13+producto);
		cout<<"  "<<producto+1;
		gotoxy(8,13+producto);
		cin>>nombreProducto;
		cin.ignore(15,'\n');
		
		gotoxy(31,13+producto);
		cin>>cantidad;
		
		gotoxy(41,13+producto);
		cin>>precio;
		cin.ignore(5,'\n');
		
		gotoxy(53,13+producto);
		cin>>codigo;
		cin.ignore(5,'\n');
		
		total=precio*cantidad;
		gotoxy(63,13+producto);
		cout<<total;
		
		gotoxy(1,35);
		cout<<"(1)Guardar (2)Borrar Anterior (3)Terminar. ";
		cin>>guardarOpcion;
		
		if(guardarOpcion==1)
		{
			for(int i=0; i < 15;i++)
			{
				DatosProductos[Productos].Nombre[i]=nombreProducto[i];
			}
			
			for(int i=0; i < 6; i++)
			{
				DatosProductos[Productos].Codigo[i]=codigo[i];
			}
			DatosProductos[Productos].Cantidad=cantidad;
			DatosProductos[Productos].Precio=precio;
			DatosProductos[Productos].Total=cantidad*precio;
			producto++;
		}
		
		else if(guardarOpcion==2)
		{
			Productos-=1;
		}
		
		else if(guardarOpcion==3)
		{
			for(int i=0; i < 15;i++)
			{
				DatosProductos[Productos].Nombre[i]=nombreProducto[i];
			}
			
			for(int i=0; i < 6; i++)
			{
				DatosProductos[Productos].Codigo[i]=codigo[i];
			}
			
			DatosProductos[Productos].Cantidad=cantidad;
			DatosProductos[Productos].Precio=precio;
			DatosProductos[Productos].Total=cantidad*precio;
			producto++;
			
			intentar='n';
		}
		
		Productos++;
	}
	main();
}

/*************************
*    Mostrar Producto    *
*************************/
int MostrarProducto()
{
	system("cls");
	Carga1();
	system("cls");
	
	for(int i=0; i < 70; i++)
	{
		gotoxy(10+i,6);
		cout<<(char)176;
		
		gotoxy(10+i,16+Productos);
		cout<<(char)176;
		Sleep(10);
	}
	for(int i=0; i < 10+Productos; i++)
	{
		gotoxy(10,6+i);
		cout<<(char)176;
		
		gotoxy(79,6+i);
		cout<<(char)176;
		Sleep(10);
	}
	gotoxy(35,7);
	cout<<"PRODUCTOS INVENTARIADOS";
	gotoxy(11,9);
	cout<<"|  No. |";
	cout<<"    NOMBRE    |";
	cout<<"  CODIGO  |";
	cout<<"  CANTIDAD  |";
	cout<<"  PRECIO  |";
	cout<<"  TOTAL  |";
	
	for(int i=0; i < Productos; i++)
	{
		gotoxy(15,10+i);
		cout<<i+1;
		gotoxy(20,10+i);
		cout<<DatosProductos[i].Nombre;
		gotoxy(37,10+i);
		cout<<DatosProductos[i].Codigo;
		gotoxy(48,10+i);
		cout<<DatosProductos[i].Cantidad;
		gotoxy(59,10+i);
		cout<<DatosProductos[i].Precio;
		gotoxy(70,10+i);
		cout<<DatosProductos[i].Precio*DatosProductos[i].Cantidad;	
	}
	getch();
	main();
}

/*************************
*    Mostrar Cliente     *
*************************/
int MostrarClientes()
{
	system("cls");
	Carga1();
	system("cls");
	cout<<"\n\n\t\t\t CLIENTES\n\n";
	for(int i=0; i < Clientes; i++)
	{
		cout<<"Cliente No. "<<i+1<<endl;
		cout<<"Nombre: "<<DatosCliente[i].Nombre<<endl;
		cout<<"Direccion: "<<DatosCliente[i].Direccion<<endl;
		cout<<"Nit: "<<DatosCliente[i].Nit<<endl<<endl;
	}
	getch();
	main();
}

/****************************
* GUARDA TODOS LOS REPORTES *
****************************/
int GuardarReportes()
{
	char datosProductos[20]={"DatosProductos.txt"};
	char datosClientes[20]={"DatosClientes.txt"};
	
	system("cls");

	/******************
	//Guarda Productos//
	*******************/
	ofstream ArchivoProductos(datosProductos);
	ArchivoProductos.is_open();
	if(ArchivoProductos.fail()) 
	cout<<"EL ARCHIVO NO SE ABRIO";
	
	for(int i=0; i < Productos; i++)
	{
		ArchivoProductos << fixed  << DatosProductos[i].Nombre <<",";
		ArchivoProductos << fixed  << DatosProductos[i].Codigo <<",";
		ArchivoProductos << fixed  << DatosProductos[i].Cantidad <<",";
		ArchivoProductos << fixed  << DatosProductos[i].Precio <<",";
		ArchivoProductos << fixed  << DatosProductos[i].Total <<endl;
	}
	ArchivoProductos.close();
	
	/*****************
	//Guarda Clientes//
	******************/
	ofstream ArchivoClientes(datosClientes);
	
	if(ArchivoClientes.is_open())
	{
		for(int i=0; i < Clientes; i++)
		{
			ArchivoClientes << fixed  << DatosCliente[i].Nombre <<",";
			ArchivoClientes << fixed  << DatosCliente[i].Direccion <<",";
			ArchivoClientes << fixed  << DatosCliente[i].Nit <<endl;
		}
	}
	if(ArchivoClientes.fail()) 
	cout<<"EL ARCHIVO NO SE ABRIO";
	
	ArchivoClientes.close();
	Carga();
	main();
}

/***************************
* CARGA TODOS LOS REPORTES *
***************************/
int CargarReportes()
{
	char linea[100];
	char direccion[25];
	char nombre[25];
	int nit=0;
	
	system("cls");
	
	/*********************
	* CARGA LOS CLIENTES *
	*********************/
	ifstream ArchivoClientes;
	
	ArchivoClientes.open("DatosClientes.txt");
	
	if(ArchivoClientes.fail())
		cout<<"Archivo no se pudo abrir";
	
	ArchivoClientes.getline(linea,sizeof(linea));
	
	while(!ArchivoClientes.eof())
	{
		for(int i=0; i < 3; i++)
		{
			char *puntero;
			if(i==0)
			{
				puntero=strtok(linea,",");
				strcpy(nombre,puntero);
			}
			else if(i==1)
			{
				puntero=strtok(NULL,",");
				strcpy(direccion,puntero);
			}
			else if(i==2)
			{
				puntero=strtok(NULL,",");
				nit=atoi(puntero);
			}
		}
		
		ArchivoClientes.getline(linea,sizeof(linea));
		
		for(int i=0; i < 20;i++)
		{
			DatosCliente[Clientes].Nombre[i]=nombre[i];
		}	
		
		for(int i=0; i < 25;i++)
		{
			DatosCliente[Clientes].Direccion[i]=direccion[i];
		}
		
		DatosCliente[Clientes].Nit=nit;
		Clientes++;
	}

	ArchivoClientes.close();
	
	/**********************
	* CARGA LOS PRODUCTOS *
	**********************/
	char NombreP[15];
	char Codigo[5];
	int Cantidad;
	double Precio;
	double Total;
	char line[100];
	
	ifstream ArchivoProductos;
	
	ArchivoProductos.open("DatosProductos.txt");
	
	if(ArchivoProductos.fail())
		cout<<"Archivo no se pudo abrir";
	
	ArchivoProductos.getline(line,sizeof(line));
	
	while(!ArchivoProductos.eof())
	{
		for(int i=0; i < 4; i++)
		{
			char *punteros;
			if(i==0)
			{
				punteros=strtok(line,",");
				strcpy(NombreP,punteros);
			}
			else if(i==1)
			{
				punteros=strtok(NULL,",");
				strcpy(Codigo,punteros);
			}
			else if(i==2)
			{
				punteros=strtok(NULL,",");
				Cantidad=atoi(punteros);
			}
			else if(i==3)
			{
				punteros=strtok(NULL,",");
				Precio=atoi(punteros);
			}
		}
		
		ArchivoProductos.getline(line,sizeof(line));
		
		for(int i=0; i < 15;i++)
		{
			DatosProductos[Productos].Nombre[i]=NombreP[i];
		}	
		
		for(int i=0; i < 5;i++)
		{
			DatosProductos[Productos].Codigo[i]=Codigo[i];
		}
		
		DatosProductos[Productos].Cantidad=Cantidad;
		DatosProductos[Productos].Precio=Precio;
		Productos++;
	}

	ArchivoProductos.close();
	
	Carga();
	main();
}

int CargarProveedores() {
	system("cls");
	cout<<"\n\n\t\t\t PROVEEDORES\n\n";
	getch();
	Carga();
	main();
}

/*****************************************************
* FUNCION PARA EL POSICIONEMIENTO EN X, Y COORDENADA *
******************************************************/
void gotoxy(int x, int y)
{
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void Carga()
{
	gotoxy(43,18);
	cout<<"Cargando...";
	for(int i=0; i < 35; i++) 
	{
		gotoxy(30+i,17);
		cout<<(char)176;
		Sleep(150);
		if(i==5)Sleep(400);
		if(i==10)Sleep(500);
		if(i==16)Sleep(900);
		if(i==21)Sleep(500);
		if(i==28)Sleep(400);
		if(i==30)Sleep(800);
	}
}


void Carga1()
{
	gotoxy(43,18);
	cout<<"Cargando...";
	for(int i=0; i < 35; i++) 
	{
		gotoxy(30+i,17);
		cout<<(char)176;
		Sleep(40);
		if(i==5)Sleep(100);
		if(i==10)Sleep(50);
		if(i==16)Sleep(100);
		if(i==21)Sleep(50);
		if(i==28)Sleep(40);
		if(i==30)Sleep(80);
	}
}
 
/* Prototipo de función */
void Permutaciones(char * cad, int l) {
   char c;    /* variable auxiliar para intercambio */
   int i, j;  /* variables para bucles */
   int n = strlen(cad);
   int t;
   int h;
   int f;
   int k;
   char caracter;
   char m[59][7];
   char v[n];   
   for(i = 0; i < n-l; i++) {
      if(n-l > 2){
	 Permutaciones(cad, l+1);
      }else{
		std::string st;
		std::getline(std::cin,st);
		ifstream fe("resultat.txt");
		for(j=0;j<59;j++){
			for(h=0;h<7;h++){
				fe.get(caracter);
				m[j][h]=caracter;
			
			
			}
		}
		std::ofstream fh(st.c_str());
		
		for(t=0;t<n;t++){
			v[t]=cad[t];
			
		}
		for(h=0;h<59;h++){
			
			for(f=0;f<n;f++){
				k=v[f]-48;
				fh<<m[h][k];
			}
		}
		
      /* Intercambio de posiciones */
      }
      c = cad[l];
      cad[l] = cad[l+i+1];
      cad[l+i+1] = c;
      if(l+i == n-1) {
         for(j = l; j < n; j++) cad[j] = cad[j+1];
         cad[n] = 0;
      }
   }
}

//void FechaHora()
//{
//	vector<string> DiaSemana;
//	DiaSemana.push_back("Domingo");
//	DiaSemana.push_back("Lunes");
//	DiaSemana.push_back("Martes");
//	DiaSemana.push_back("Miercoles");
//	DiaSemana.push_back("Jueves");
//	DiaSemana.push_back("Viernes");
//	DiaSemana.push_back("Sabado");
//	
//	vector<string> mes;
//	mes.push_back("Enero");
//	mes.push_back("Febrero");
//	mes.push_back("Marzo");
//	mes.push_back("Abril");
//	mes.push_back("Mayo");
//	mes.push_back("Junio");
//	mes.push_back("Julio");
//	mes.push_back("Agosto");
//	mes.push_back("Septiembre");
//	mes.push_back("Octubre");
//	mes.push_back("Noviembre");
//	mes.push_back("Diciembre");
//	
//	
//	/*	struct tm 
//		{
//		  int tm_sec;   // seconds of minutes from 0 to 61
//		  int tm_min;   // minutes of hour from 0 to 59
//		  int tm_hour;  // hours of day from 0 to 24
//		  int tm_mday;  // day of month from 1 to 31
//		  int tm_mon;   // month of year from 0 to 11
//		  int tm_year;  // year since 1900
//		  int tm_wday;  // days since sunday
//		  int tm_yday;  // days since January 1st
//		  int tm_isdst; // hours of daylight savings time
//		};*/
//	
//	int year=1900+time->tm_year;
//	
//	
//	time_t now = time(0);
//	
//	tm * time = localtime(&now);
//	gotoxy(2,1);
//	cout<<"Dia: "<<DiaSemana[time->tm_wday]<<", ";
//	cout<<time->tm_mday <<" De "<<mes[time->tm_mon];
//	cout<<"Del "<<year;
//}
