

#include <iostream>
using namespace std;
struct deporte {
    char deporte[20];
    char posicion[20];
    int dorsal=0;

};

struct atleta {
    char nombre[30];
    int edad=0;
    double salario=0;
    deporte deporteAtleta ;


};
bool validaIndice(int indice, int numAtletas) {
    if (indice >= 0 and indice < numAtletas) {
        return true;
    }
    else {
        return false;
    }

    
}
bool validaSiHayDato(int indice, atleta deportista[]) {
    if (deportista[indice].edad ==0 && deportista[indice].salario==0) {
        return false;
    }
    else {
        return true;
    }
}

void altas(int indice, int numAtletas, atleta deportista[]) {
    if (validaIndice(indice,numAtletas)== true && validaSiHayDato(indice, deportista)==false) {
        cout << "Ingrese los datos del atleta: "<<endl;
        cout << "Nombre: ";
        cin.ignore();
        cin.getline(deportista[indice].nombre, 30);
        cout << "Edad: ";
        cin >> deportista[indice].edad;
        if (deportista[indice].edad > 0) {
            cout << "Salario: ";
            cin >> deportista[indice].salario;
            cin.ignore();
            if (deportista[indice].salario) {
                
                cout << "Deporte: ";
                cin.getline(deportista[indice].deporteAtleta.deporte, 20);
                cout << "Posicion: ";
                cin.getline(deportista[indice].deporteAtleta.posicion, 20);
                cout << "Dorsal: ";
                cin >> deportista[indice].deporteAtleta.dorsal;
                cin.ignore();
            }
            else {
                cout << "Ingresa un salario valido" << endl;
            }
           
        }
        else {
            cout << "Ingresa una edad valida" << endl;
        }
        
    }
    else if (validaIndice(indice, numAtletas) == false) {
        cin.ignore();
        cout << "Ingrese un indice valido" << endl;
       
    }
    else {
        cout << "Ya hay un registro en el indice " << indice << endl;
    }


}

void bajas(int indice, int numAtletas, atleta deportista[]) {
    if (validaIndice(indice, numAtletas) == true && validaSiHayDato(indice, deportista) == true) {
        *deportista[indice].nombre = {};
        deportista[indice].edad = 0;
        deportista[indice].salario = 0;
        *deportista[indice].deporteAtleta.deporte = {};
        *deportista[indice].deporteAtleta.posicion = {};
        deportista[indice].deporteAtleta.dorsal = 0;
        cout << "*** Atleta dado de baja exitosamente ***" << endl;
    }
    else if(validaSiHayDato(indice, deportista) == false) {
        cout << "El indice ingresado no contiene datos registrados" << endl;
    }
    else {
        cout << "El indice ingresado no es valido" << endl;
    }

}
void consulta(int indice, int numAtletas, atleta deportista[]) {
    if (validaIndice(indice, numAtletas) == true && validaSiHayDato(indice, deportista) == true) {
        
        cout << "Nombre: " << deportista[indice].nombre << endl;
        cout << "Edad: " << deportista[indice].edad << endl;
        cout << "Salario: " << deportista[indice].salario << endl;
        cout << "Deporte: " << deportista[indice].deporteAtleta.deporte << endl;
        cout << "Posicion: " << deportista[indice].deporteAtleta.posicion << endl;
        cout << "Dorsal: " << deportista[indice].deporteAtleta.dorsal << endl;
          

    }
    else if (validaSiHayDato(indice, deportista) == false) {
        cout << "El indice ingresado no contiene datos registrados" << endl;
    }
    else {
        cout << "El indice ingresado no es valido" << endl;
    }
}

void mostrarTodo(int numAtletas, atleta deportista[]) {
    bool arregloVacio = true;
    cout << "Mostrando indices registrados: " << endl << endl;
    for (int i = 0; i < numAtletas; i++) {
     
        if (deportista[i].edad != 0 && deportista[i].salario != 0) {
            cout << "************************" << endl;
            cout << "Datos del deportista "<<deportista[i].nombre<<": " << endl;
            cout << "Nombre: " << deportista[i].nombre << endl;
            cout << "Edad: " << deportista[i].edad << endl;
            cout << "Salario: " << deportista[i].salario << endl;
            cout << "Deporte: " << deportista[i].deporteAtleta.deporte << endl;
            cout << "Posicion: " << deportista[i].deporteAtleta.posicion << endl;
            cout << "Dorsal: " << deportista[i].deporteAtleta.dorsal << endl << endl;
            
            arregloVacio = false;
        }
        
    }
    if (arregloVacio == true) {
        cout << "No hay datos para mostrar"<<endl;
    }

}

int main()
{
    
    char resp;
    int numAtletas, opcion, indice;
    cout << "Hola mundo" << endl;
    cout << "Cuantos atletas quiere registrar? ";
    cin >> numAtletas;

    atleta* deportista = new atleta[numAtletas];

    do {
        cout << "Eliga una opcion: " << endl << "1: Altas" << endl << "2: Bajas" <<endl<< "3: Consultas" <<endl<< "4: Mostrar todo" <<endl<< "5: Salir" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
            {
                cout << "*** ALTAS ***" << endl;
                cout << "Ingrese el indice del atleta: ";
                cin >> indice;
                altas(indice, numAtletas, deportista);
                break;
            }
            case 2:
            {
                cout << "*** BAJAS ***" << endl;
                cout << "Ingrese el indice del atleta: ";
                cin >> indice;
                bajas(indice, numAtletas, deportista);
                break;
            }
            case 3:
            {
                cout << "*** CONSULTAS ***" << endl;
                cout << "Ingrese el indice del atleta: ";
                cin >> indice;
                consulta(indice, numAtletas, deportista);
                break;

            }
            case 4:
            {
                mostrarTodo( numAtletas, deportista);
                break;
            }
            case 5:
            {
                return 0;
            }
            default:
            {
                cout << "Elige una opcion valida!" << endl;
            }
        }
        
        cout << "Desea continuar? y/n "<<endl;
       
        cin >> resp;
        
    } while (resp=='y'||resp=='Y');
    delete deportista;
}

