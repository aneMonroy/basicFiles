#include <stdio.h>
#include <iostream>
#include "snap7.h"
#include "s7.h"
#include <string>
#include <sstream>

using namespace std;

TS7Client *PLC;

int main(int argc, char **argv)
{
	PLC = new TS7Client();
	int result = PLC->ConnectTo("192.168.2.40",0,0);
	if(result==0)
		cout << "[INFO] >> PLC CONNECTED" << endl;
	else
		cerr << "[ERR] >> PLC NOT CONNECTED" << endl;
	
	cout << "[INFO] >> READ DB xx" <<endl;
	byte db1Buffer[30];
	int read = PLC -> DBRead(318,0,30,&db1Buffer);
	if(read!=0)
		cerr << "[ERR] >> ERROR AT READING DB" << endl;
	bool requestFlag = S7_GetBitAt(db1Buffer,0,0);
	bool TRG1 = S7_GetBitAt(db1Buffer,1,0);
	int commandNumber = S7_GetIntAt(db1Buffer,16);
	
	cout << "DB318.DBX0.0: " << requestFlag << endl;
	cout << "DB318.DBX1.0: " << TRG1 << endl;
	cout << "DB318.DBW16: " << commandNumber << endl;
	
	cout << "[INFO] >> WRITE DB xx" << endl;
	byte dbOUT[4];
	read = PLC->DBRead(319,0,4,&dbOUT);
	bool errorFlag = S7_GetBitAt(dbOUT,0,1);
	bool readyFlag = S7_GetBitAt(dbOUT,0,2);
	
	cout << "DB319.DBX0.1: " << errorFlag << endl;
	cout << "DB319.DBX0.2: " << readyFlag << endl;
	
	byte db0[1];
	const int strtIDX = 0;
	S7_SetBitAt(db0,strtIDX,1,0);
	S7_SetBitAt(db0,strtIDX,2,0);
	
	result = PLC->DBWrite(319,strtIDX,1,db0);
	if(result !=0)
		cerr << "[ERR] >> COULDNT WRITE" << endl;
	
	PLC->Disconnect();
	delete PLC;
	cout << "[INFO] >> PROGRAM STOPPED" << endl;
	return 0;
}
	
