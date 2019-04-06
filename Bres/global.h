#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;

int reqiter = 0, respiter = 0, k = 0;                                      
string res[128];                                            
string req[128];                                               
void filereader();
void handler();
string respbite, bites, reqout, reqstart;
void response();                                                 
void request();                                               
int length;                                                     
size_t pos, pos1, pos2, spawn;                               
char buffer[512];
int x = 0;
int a = 0, o = 0;
string sixteen = "0x";
