#include <iostream>

using namespace std;

int main() {
	int size, b = 0, c, temp, temp2;
	cin >> size;
	int a = size/5;
	int m1[size];
	if (size%5 != 0) {cout << "error";}
	else
    {for(int i = 0; i < size; i++)
        {
            cin >> c;
            m1[i] = c;
	    }
    }
    int m2[size];
    for(int j = 0; j < size; j++)
    {
        m2[j] = j;
    }
     int m3[size];
    for(int j = 0; j < size; j++)
    {
        m3[j] = j;
    }
    int m4[size];
    
    for (int k = 0; k < size - 1; k++) {
        for (int l = 0; l < size - k - 1; l++) {
            if (m1[l] > m1[l + 1]) {
                temp = m1[l];
                m1[l] = m1[l + 1];
                m1[l + 1] = temp;
                temp2 = m2[l];
                m2[l] = m2[l + 1];
                m2[l + 1] = temp2;
            }
        }
    }
    
    for (int q = 0; q < size; q++) {
    }
   
    for (int q = 0; q < size; q++) {

    if (q < a) {m4[q] = 1;}
        if (q < a*2 & q >= a) {m4[q] = 2;}
        if (q < a*3 & q >= a*2) {m4[q] = 3;}
        if (q < a*4 & q >= a*3) {m4[q] = 4;}
        if (q < a*5 & q >= a*4) {m4[q] = 5;}
        
    }
    for(int o =0; o < size; o++){
        for(int p = 0; p < size; p++){
            if (m3[o] == m2[p]) {cout << m4[p];}
            
        }
        }   
    
    
	return 0;
}
