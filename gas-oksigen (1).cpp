%%writefile oksigen.cpp

using namespace std;

    int main (){
    for(int i = 0; i > 4; i++){
    for(int j = 0; j < 4; j++){
    for(int k = 0; k < 4; k++){
        cout << i << endl;
    }
        
    // deklarasi variabel
    float pi = 3.14;
    int counter = 0;

    // deklarasi molekul oksigen
    float O1x[125], O1y[125], O1z[125];
    float O2x[125], O2y[125], O2z[125];
    float Ptx[125], Pty[125], Ptz[125];
    float Fex[125], Fey[125], Fez[125];

    /*
       ________
       |  O-O |
       |______|
        Pt-Fe
      molekul oksigen itu bentuk rigid
    */

    float rB_O1x = cos((1.460/2.0)*pi/180.0) * 1.4;
    float rB_O1y = 0.0;
    float rB_O1z = sin((1.460/2.0)*pi/180.0) * 1.4;

    float rB_Ox = rB_Ox;
    float rB_Oy = rB_Oy;
    float rB_Oz = - rB_Oz;

    float rB_ptx = 0.0;
    float rB_pty = 0.0;
    float rB_ptz = 0.0;

    float rB_Fex = 0.0;
    float rB_Fey = 0.0;
    float rB_Fez = 0.0;


    //iterasi untuk setiap molekul oksigen
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                
              O1x[counter] = Ox[counter] + rB_O1x;
              O1y[counter] = Oy[counter] + rB_O1y;
              O1z[counter] = Oz[counter] + rB_O1z;

              O2x[counter] = Ox[counter] + rB_O2x;
              O2y[counter] = Oy[counter] + rB_O2y;
              O2z[counter] = Oz[counter] + rB_O2z;

              Ptx[counter] = rB_Ptx + (i*3.663);
              Pty[counter] = rB_Pty + (j*3.663);
              Ptz[counter] = rB_Ptz + (k*3.663);

              Fex[counter] = rB_Ptx + (i*3.663);
              Fey[counter] = rB_Pty + (j*3.663);
              Fez[counter] = rB_Ptz + (k*3.633);

              counter += 1;  
            }
        }
    }

    // hasil ietrasi dimasukkan ke dalam file xyz
    ofstream file;
    file.open("oksigen.xyz");
    int N = 125 * 2;
    file << N << "\n" << endl;

    // iterasi dalam output array
    for(int m = 0; m < 125; m++){
        
        file << setw(5) << "O" << setw(5) << " "\
             << fixed << setprecision(5) << O1x[m] << setw(5) << " " \
             << fixed << setprecision(5) << O1y[m] << setw(5) << " " \
             << fixed << setprecision(5) << O1z[m] << "\n";

        file << setw(5) << "O" << setw(5) << " "\
             << fixed << setprecision(5) << O2x[m] << setw(5) << " " \
             << fixed << setprecision(5) << O2y[m] << setw(5) << " " \
             << fixed << setprecision(5) << O2z[m] << "\n"; 

         file << setw(5) << "Pt" << setw(5) << " " \
             << fixed << setprecision(5) << Ptx[m] << setw(5) << " " \
             << fixed << setprecision(5) << Pty[m] << setw(5) << " " \
             << fixed << setprecision(5) << Ptz[m] << "\n";    

          file << setw(5) << "Fe" << setw(5) << " " \
             << fixed << setprecision(5) << Fex[m] << setw(5) << " " \
             << fixed << setprecision(5) << Fey[m] << setw(5) << " " \
             << fixed << setprecision(5) << Fez[m] << "\n";      
    } 

    cout << "Program telah selesai";

    return 0;
}
