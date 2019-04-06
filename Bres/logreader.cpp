#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include "global.h"

using namespace std;

int main()
{
    filereader();
}

void filereader()
{
    ifstream input("E://oops.txt");                                                //reading log file
    if (!input)
    {
        cout << "Error opening file" << endl;                                      
    }

    while(input.getline(buffer,512))
    {
        handler();
    }
}

void handler()
{
    if((strstr(buffer, ":")) && (strstr(buffer, "Length")) && ((strstr(buffer, "IRP_MJ_WRITE")) || (strstr(buffer, "SUCCESS")) || (strstr(buffer, "TIMEOUT"))))
    {
        string buf1(buffer);
        string buf2(buffer);                                                    //char to string transformation

        pos = buf1.rfind("Length");                                             //rfind "Length" in buf1 string
        bites = buf1.substr(pos + 6);                                            

        pos1 = buf2.rfind(":");
        reqout = buf2.substr(pos1 + 2, pos1 + 15);
        reqstart = buf2.substr(0, pos1 + 1);

        pos = bites.find(" ") + 1;
        pos2 = bites.find(":");
        string vae(bites.substr(pos, pos2 - pos));                              //length value found and
        istringstream val(vae);                                                 //string to int transformation
        val >> length;

        if ((length == 1) || (length == 0))                                     //if length = 1 or length = 0
        {
            ///then this string - response
            response();
        }

        else
        {
            request();
        }
    }
}

void response()
{
    spawn = bites.rfind(":");
    respbite = bites.substr(spawn + 1, spawn + 2);
    //cout << respbite;
    if (respiter == reqiter)
    {
        k++;
        res[k] = respbite;
    }
    else
    {
        //cout << endl << reqiter << "+++" << respiter << endl;
        res[0] = respbite;
        int sbval;                                                              //spawn bite value (lenth)
        istringstream spawnbite(res[0]);
        spawnbite >> sbval;
        if (sbval == 68)
        {
            cout << "long";
            /*ofstream out("D:\\out.txt" , ios_base::app);
            out << "long";
            out.close();*/
        }
        if (sbval == 10)
        {
            cout << "short";
            /*ofstream out("D:\\out.txt" , ios_base::app);
            out << "short";
            out.close();*/
        }
        sbval =0;
        respiter++;
    }
    cout << res[k];
    /*ofstream out("D:\\out.txt" , ios_base::app);
    out << res[k];
    out.close();*/
}

void request()
{
    cout << endl << endl << endl << "Request" << "  :  " << reqstart << " ";
    if (length < 20)
    {
    while (x != length)
    {
        string reqreq(reqout.substr(a, 2));
        req[x] = reqreq;
        a = a + 3;
        cout << req[x] << " ";
        x++;
    }
    x = 0;
    a = 0;
    }
    else
    {
       while (x != 21)
    {
        string reqreq(reqout.substr(a, 2));
        reqreq = sixteen + reqreq;
        req[x] = reqreq;
        a = a + 3;
        cout << req[x] << " ";
        x++;
    }
    x = 0;
    a = 0;
    }
     cout << endl << endl << endl << "Response : ";                                   //output if this string - request

    for (int point = 0; point < k; point++)                                           //res[k] cleaning (rewriting)
    {
        res[point] = " ";
    }
    k = 0;
    reqiter++;
}
