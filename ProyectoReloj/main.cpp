#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;


void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void reloj(int hora, int minutos, int segundos){

    for(hora;hora<24;hora++){
        for(minutos;minutos<60;minutos++){
            for(segundos;segundos<60;segundos++){
                system("cls");
                gotoxy(40,5);
                cout << hora << ":" << minutos << ":" << segundos<< endl;
                Sleep(1000);
                    if(segundos==59){
                    segundos=-1;
                    minutos++;
                    }
                    if(minutos==60){
                        minutos=0;
                        hora++;
                    }
                    if(hora==24){
                        hora=0;
                    }
            }
        }
    }
}

int main()
{
    bool datosIncorrectos;
    int hora,minutos,segundos;
    do{
    cout << "\t\t\tRELOJ MANUAL\n\n ------- Inserte la hora en formato de 24 horas -------\n\n";
    cout << "Hora: ";    cin  >> hora;
    cout<< "Minutos: ";    cin  >> minutos;
    cout << "Segundos: ";    cin >> segundos;

    if((hora<-1||hora>23||minutos<-1||minutos>59||segundos<-1||segundos>59)){
        cout << "\n\tDATOS INCORRECTOS!! \nINGRESE LOS VALORES NUEVAMENTE\n\n";
        datosIncorrectos=true;
    }else{
        datosIncorrectos=false;
    }
    }while(datosIncorrectos);

    reloj(hora,minutos,segundos);

    return 0;
}


