#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

class instituto
{

public:
instituto ();
~instituto ();
void leer ();
void promedio ();
void imprimir ();
void guardar ();
void cargar ();
int alumno;

private:

struct datos
{
char nombre[50];
char grupo[10];
long int boleta;
float cal1,cal2,cal3,prom;
};
datos dat[30];


};
instituto::instituto ()
{
cout<<"Datos Alumno"<<endl;
cout<<"Ingrese la cantidad de alunmos que desea ingresar y guardar: ";
cin>>alumno;


}
instituto::~instituto ()
{}
void instituto::leer ()
{
for(int i=0; i<alumno; i++)
{



cout<<"\n\tNombre y Apellidos: \n"<<endl;
cin.ignore(100,'\n');
cin.getline(dat[i].nombre,32);
cout<<"\n\tcodigo: \n"<<endl;
cin>>dat[i].grupo;
cout<<"\n\tnumero : \n"<<endl;
cin>>dat[i].boleta;
cout<<"\n\tPrimer Calificacion: \n"<<endl;
cin>>dat[i].cal1;
cout<<"\n\tSegunda Calificacion: \n"<<endl;
cin>>dat[i].cal2;
cout<<"\n\tTercera Calificacion: \n"<<endl;
cin>>dat[i].cal3;
}
return;

}

void instituto::promedio ()
{
for(int i=0; i<alumno; i++)
{

dat[i].prom=(dat[i].cal1+dat[i].cal2+dat[i].cal3)/3;
}
return;

}

void instituto::imprimir()
{
for(int i=0; i<alumno; i++)
{

cout<<"Los datos del Alumno son los siguentes:"<<endl
<<"\t\tNombre: "<<dat[i].nombre<<endl
<<"\t\tCodigo: "<<dat[i].boleta<<endl
<<"\t\tNumero: "<<dat[i].grupo<<endl
<<"\t\tPrimera calificacion: "<<dat[i].cal1<<endl
<<"\t\tSegunda calificacion: "<<dat[i].cal2<<endl
<<"\t\tTercera calificacion: "<<dat[i].cal3<<endl
<<"\t\tPromedio final: "<<dat[i].prom<<endl;

if(dat[i].prom>=6)
{
cout<<"\t\nNOTA: El Alumno tiene un promedio aprobado"<<endl;
}
else
{
cout<<"\t\nNOTA: El Alumno tiene un promedio reprobado"<<endl;
}
}
return;

}

void instituto::guardar()
{
const int MAXCARACTERES=15;
char nombrearchivo[MAXCARACTERES]="registro.dat";
ofstream archivo_sale;
archivo_sale.open(nombrearchivo);
if(archivo_sale.fail())
{

cout<<"El archivo no se abrio exitosamente"<<endl;
exit(1);
}
for (int i=0; i<alumno; i++)
{
archivo_sale<<dat[i].nombre<<"\n"
<<dat[i].boleta<<"\n"
<<dat[i].grupo<<"\n"
<<dat[i].cal1<<"\n"
<<dat[i].cal2<<"\n"
<<dat[i].cal3<<"\n"
<<dat[i].prom<<"\n";
}
archivo_sale.close();
cout<<"Los datos fueron guardados correctamente en"<<nombrearchivo<<endl;
system("PAUSE");
return;
}
void instituto::cargar()
{

const int MAXCARACTERES=15;
char nombrearchivo[MAXCARACTERES]="registro.dat";
ifstream archivo_entra;
archivo_entra.open(nombrearchivo);
if (!archivo_entra)
{

cout<<"El archivo"<<nombrearchivo<<"no se abrio exitosamente \n verifique si existe"<<endl;
system("PAUSE");
exit(1);
}
cout<<"Los datos del registro de alumno son:";
for (int i=0; i<alumno; i++)
{

archivo_entra>>dat[i].nombre;
cout<<"Nombres y Apellidos: "<<dat[i].nombre<<endl;
archivo_entra>>dat[i].boleta;
cout<<"Codigo: "<<dat[i].boleta<<endl;
archivo_entra>>dat[i].grupo;
cout<<"Numero: "<<dat[i].grupo<<endl;
archivo_entra>>dat[i].cal1;
cout<<"Calificacion 1: "<<dat[i].cal1<<endl;
archivo_entra>>dat[i].cal2;
cout<<"Calificacion 2: "<<dat[i].cal2<<endl;
archivo_entra>>dat[i].cal3;
cout<<"Calificacion 3: "<<dat[i].cal3<<endl;
archivo_entra>>dat[i].prom;
cout<<"Promedio: "<<dat[i].prom<<endl;

}
system("PAUSE");
return;
}
int main ()
{

instituto datos;


system ("CLS");

if(datos.alumno>30)
{
cout<<"ERROR SOBRE CUPO DE ALUMNOS \n Maximo pueden ser 30 alumnos asi que introduce un num maximo a 30"<<endl;
}
else
{


datos.leer();

datos.promedio();
datos.guardar();

system("CLS");

datos.imprimir();


cout<<"Los datos cargados desde el archivo:"<<endl;

datos.cargar();


}


system ("PAUSE");
return 0;
}
