#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 1 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Devuelve true si al menos dos apuntadores dados apuntan a la misma direccion de memoria
bool espaciosCompartidos(int* a, int* b, int* c)
{
    if(a == b || a == c || b == c){
    return true;
    }
    return false;
}

//Devuelve la cantidad de veces que valor_buscado (dado) existe en arreglo (dado) dado su tamano
//Nota: la template debe de poder aceptar cualquier tipo primitivo
template <typename T>
int contar(T*arreglo, T valor_buscado,int tamano)
{
    int rep=0;
    for(int i =0; i<tamano; i++){
        if(arreglo[i]==valor_buscado){
            rep++;
        }
    }

    return rep;
}

//Devuelve la probabilidad de seleccionar aleatoriamente el valor dado en el vector elementos dado
//Nota la probabilidad debe ser un numero entre 0 y 1, siendo 0 una probabilidad de 0% y 1 de 100%
double probabilidad(vector<string>elementos, string valor)
{
    double acu=0;
    for(int i=0; i< elementos.size();i++){
        if(valor==elementos[i]){
            acu++;
        }
    }
    double prop = acu/elementos.size();
    return prop;
}

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 2 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Realizar las clases MedioDeTransporte, Carro y Moto descritas en el diagrama UML adjunto

//**MedioDeTransporte**
//Constructor vacio: no hace nada
//operator+=(): suma el parametro al atributo de clase gasolina
//pagaPeaje(): devuelve true

//**Carro**
//Constructor: inicializa los atributos de clase dados los parametros
//getCantidadLLantas(): devuelve 4
//esPaila(): devuelve el atributo de la clase es_paila

//**Moto**
//Constructor: inicializa la variable gasolina dado el parametro
//getCantidadLLantas(): devuelve 2
//paga

class MedioDeTransporte{
public:
int gasolina;
MedioDeTransporte(){
}
void operator+=(int g){
    gasolina +=g;
}
virtual bool pagaPeaje(){
    return true;
}
virtual int getCantidadLLantas()=0;
};

class Carro : public MedioDeTransporte
{
public:
bool es_paila;
    Carro(int g, bool ep){
        this->gasolina=g;
        es_paila=ep;
    }
    int getCantidadLLantas(){
        return 4;
    }

    bool esPaila(){
        return es_paila;
    }
};

class Moto : public MedioDeTransporte
{
public:
    Moto(int g){
    this->gasolina =g;
    }

    bool pagaPeaje(){
     return false;
    }

    int getCantidadLLantas(){
        return 2;
    }
};
///////////////////////////////////////////////////////////////////
////////////////////////////// Main ///////////////////////////////
///////////////////////////////////////////////////////////////////

void evaluar();
void evaluar2();

int main ()
{
    //Funcion evaluadora parte 1
    cout<<"Evaluador parte 1"<<endl<<"================="<<endl;
    evaluar();


    //Evaluacion parte 2
    //Descomentar para evaluar
    cout<<"Evaluador parte 2"<<endl<<"================="<<endl;
    evaluar2();

    return 0;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////// Evaluador 2 /////////////////////////////
///////////////////////////////////////////////////////////////////////

void evaluar()
{
    double nota = 0;

    int a1=4,b1=5,*c1=new int(0);
    int a2=10,b2=15,*c2=new int(0);
    int a3=7,b3=3,*c3=new int(0);

    int* num1 = new int(1);
    int* num2 = new int(2);
    int* num3 = new int(3);

    cout<<"espaciosCompartidos():\t";
    if(!espaciosCompartidos(new int(10),new int(20),new int(30))
        && !espaciosCompartidos(new int(10),new int(10),new int(10))
        && espaciosCompartidos(num1,num2,num1)
        && espaciosCompartidos(num1,num2,num1)
        && espaciosCompartidos(num1,num2,num2)
        && !espaciosCompartidos(num1,num2,num3)
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    int *arr = new int[3];
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;

    float *arr2 = new float[5];
    arr2[0]=1;
    arr2[1]=0;
    arr2[2]=2;
    arr2[3]=7;
    arr2[4]=0;

    string *arr3 = new string[2];
    arr3[0]="hola";
    arr3[1]="mundo";
    string ejemplo="ejemplo";

    cout<<"contar():\t\t";
    if(contar(arr,3,3)==1
        && contar(arr2,0.0f,5)==2
       && contar(arr3,ejemplo,2)==0
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    vector<string>v1,v2,v3,v4;

    v1.push_back("a");
    v1.push_back("b");
    v1.push_back("c");
    v1.push_back("d");

    v2.push_back("a");
    v2.push_back("c");
    v2.push_back("c");
    v2.push_back("c");

    v3.push_back("a");
    v3.push_back("a");
    v3.push_back("b");
    v3.push_back("c");
    v3.push_back("c");
    v3.push_back("c");

    v4.push_back("c");
    v4.push_back("c");

    cout<<"probabilidad():\t\t";
    if(probabilidad(v1,"a")==0.25
        && probabilidad(v1,"f")==0
       && probabilidad(v2,"c")==0.75
       && probabilidad(v3,"a")==1.0/3.0
       && probabilidad(v3,"c")==0.5
       && probabilidad(v4,"c")==1
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/6"<<endl<<endl;
}

void evaluar2()
{
    double nota = 0;

    cout<<"**Clase Carro**"<<endl;
    cout<<"Test constructor:\t\t";
    Carro carro1(120,false);
    Carro carro2(200,true);

    if(carro1.gasolina == 120
        && !carro1.es_paila
        && carro2.gasolina == 200
        && carro2.es_paila
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test getCantidadLLantas():\t";

    if(carro1.getCantidadLLantas() == 4
        && carro2.getCantidadLLantas() == 4
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test esPaila():\t\t\t";

    if(!carro1.esPaila()
        && carro2.esPaila()
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test pagaPeaje():\t\t";

    if(carro1.pagaPeaje()
        && carro2.pagaPeaje()
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    carro1+=10;
    carro2+=20;

    cout<<"Test operator+=():\t\t";

    if(carro1.gasolina == 130
        && carro2.gasolina == 220
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }




    cout<<"**Clase Moto**"<<endl;

    Moto moto1(50);
    Moto moto2(60);

    cout<<"Test constructor:\t\t";

    if(moto1.gasolina == 50
        && moto2.gasolina == 60
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test pagaPeaje():\t\t";

    if(!moto1.pagaPeaje()
        && !moto2.pagaPeaje()
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test getCantidadLLantas():\t";

    if(moto1.getCantidadLLantas()==2
        && moto2.getCantidadLLantas()==2
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    cout<<"Test operator+=():\t\t";
    moto1+=20;
    moto2+=30;

    if(moto1.gasolina == 70
        && moto2.gasolina == 90
        )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/9"<<endl;
}
