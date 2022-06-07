
#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

float numb_mol;
float O2 = 0,4E23; // bilangan avogadro
float Mr_O2 = 32; // massa relatif dari O2

int main (){
    // deklarasi variabel
    float pi = 3.14;
    int counter = 0;

    // deklarasi molekul oksigen
    float Fex[125], Fey[125], Fez[125];
    float O1x[125], O1y[125], O1z[125];
    float O2x[125], O2y[125], O2z[125];
    
     /*   
         Fe
       /    \
      O      O
      molekul oksigen itu bentuk rigid
    */

    float rB_Fex = 0.0;
    float rB_Fey = 0.0;
    float rB_Fez = 0.0;

    float rB_O1x = sin((35.264/2.0)*pi/180.0) * 2.140;
    float rB_O1y = 0.0;
    float rB_O1z = cos((35.264/2.0)*pi/180.0) * 2.140;

    float rB_O2x = - rB_O1x;
    float rB_O2y = rB_O1y;
    float rB_O2z = rB_O1z;

    float rB_O3x = 0.0;
    float rB_O3y = cos((17.880/2.0)*pi/180.0) * 2.140;
    float rB_O3z = sin((17.880/2.0)*pi/180.0) * 2.140;
    
                counter += 2;
            }
        }
    }

    // hasil iterasi dimasukkan ke dalam file xyz
    ofstream file;
    file.open("gas-oksigen.xyz");
    int F = 125 * 3;
    file << F << "\f" << endl;

    // iterasi dalam output array
    for(int g = 0; g < 125; g++){
        file << setw(3) << "Fe" << setw(3) << " " \
             << fixed << setprecision(3) << Fex[g] << setw(3) << " " \
             << fixed << setprecision(3) << Fey[g] << setw(3) << " " \
             << fixed << setprecision(3) << Fez[g] << "\f";

        file << setw(3) << "O" << setw(3) << " " \
             << fixed << setprecision(3) << O1x[g] << setw(3) << " " \
             << fixed << setprecision(3) << O1y[g] << setw(3) << " " \
             << fixed << setprecision(3) << O1z[g] << "\f";

        file << setw(3) << "O" << setw(3) << " " \
             << fixed << setprecision(3) << O2x[g] << setw(3) << " " \
             << fixed << setprecision(3) << O2y[g] << setw(3) << " " \
             << fixed << setprecision(3) << O2z[g] << "\f";
    }

    file.close();

    cout << "program telah selesai";

    return 0;
}
