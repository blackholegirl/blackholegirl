
#include "iostream"
#include "cmath"
#include "iomanip"
#include "fstream"

using namespace std;

int main (){
    // deklarasi variabel
    float pi = 3.14;
    int counter = 0;

    // deklarasi molekul air
    float Ox[125], Oy[125], Oz[125];
    float H1x[125], H1y[125], H1z[125];
    float H2x[125], H2y[125], H2z[125];

    /* H     H
        \   /
          O 
      molekul air itu bentuk rigid
    */

    float rB_Ox = 0.0;
    float rB_Oy = 0.0;
    float rB_Oz = 0.0;

    float rB_H1x = sin((104.52/2.0)*pi/180.0) * 1.0;
    float rB_H1y = 0.0;
    float rB_H1z = cos((104.52/2.0)*pi/180.0) * 1.0;

    float rB_H2x = - rB_H1x;
    float rB_H2y = rB_H1y;
    float rB_H2z = rB_H1z;

    //iterasi untuk setiap molekul air
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){

              Ox[counter] = rB_Ox + (i*3.01);
              Oy[counter] = rB_Oy + (j*3.01);
              Oz[counter] = rB_Oz + (k*3.01);

              H1x[counter] = Ox[counter] + rB_H1x;
              H1y[counter] = Oy[counter] + rB_H1y;
              H1z[counter] = Oz[counter] + rB_H1z;

              H2x[counter] = Ox[counter] + rB_H2x;
              H2y[counter] = Oy[counter] + rB_H2y;
              H2z[counter] = Oz[counter] + rB_H2z;

              counter += 1;  
            }
        }
    }

    // hasil ietrasi dimasukkan ke dalam file xyz
    ofstream file;
    file.open("air-ruah.xyz");
    int N = 125 * 3;
    file << N << "\n" << endl;

    // iterasi dalam output array
    for(int m = 0; m < 125; m++){
        file << setw(3) << "O" << setw(3) << " " \
             << fixed << setprecision(3) << Ox[m] << setw(3) << " " \
             << fixed << setprecision(3) << Oy[m] << setw(3) << " " \
             << fixed << setprecision(3) << Oz[m] << "\n";

        file << setw(3) << "H" << setw(3) << " "\
             << fixed << setprecision(3) << H1x[m] << setw(3) << " " \
             << fixed << setprecision(3) << H1y[m] << setw(3) << " " \
             << fixed << setprecision(3) << H1z[m] << "\n";

        file << setw(3) << "H" << setw(3) << " "\
             << fixed << setprecision(3) << H2x[m] << setw(3) << " " \
             << fixed << setprecision(3) << H2y[m] << setw(3) << " " \
             << fixed << setprecision(3) << H2z[m] << "\n";      
    } 

    file.close();

    cout << "Program telah selesai";

    return 0;
}