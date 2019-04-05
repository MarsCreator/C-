//Simple christmas tree

#include <iostream>

using namespace std;

int h;
int k = 0;
int t = 2;
void fir(int h);

int main()
{
    cout<<"Enter h:" << endl; //tree height
    cin >> h;
    fil(h);
    return 0;
}

void fir(int h){
    while(k<h-1){
        cout << " ";
        k++;
    }
    cout << "*" << endl;
    for(int i = 1; i < h; i++){
        k = 0;
        while(k<h-i-1){
            cout << " ";
            k++; 
        }
        for(int j = 1; j <= i+t; j++){
            cout << "*";
        }
        t++;
        cout << endl;
    }
}
