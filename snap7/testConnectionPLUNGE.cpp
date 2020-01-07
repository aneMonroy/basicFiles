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
	int result2;
	if(result==0)
	{
		cout<<"CONNECTED"<<endl;
	}
	else
	{
		cout<<"NO CONNECTED"<<endl;
	}
	cout<<"READ DB 318 FIRST"<<endl;
	byte db1Buffer[30];
	int read = PLC->DBRead(318,0,30,&db1Buffer);
	if(read!=0)
	{
		cout<<"Error"<<endl;
	}
	bool requestFlag = S7_GetBitAt(db1Buffer,0,0);
	cout<<"DB318.DBX0.0: "<<requestFlag<<endl;
	bool TRG1 = S7_GetBitAt(db1Buffer,1,0);
	cout<<"DB318.DBX1.0: "<<TRG1<<endl;
	int commandNumber = S7_GetIntAt(db1Buffer,16);
	cout<<"DB318.DBW16: "<<commandNumber<<endl;
	int commandPart = S7_GetIntAt(db1Buffer,20);
	cout<<"DB318.DBW20: "<<commandPart<<endl;
	int command2 = S7_GetIntAt(db1Buffer,24);
	cout<<"DB318.DBW24: "<<command2<<endl;
	
	
	//void S7_SetBitAt ( byte Buffer[], int Pos, int Bit, bool Value)
	
	//byte dbBuffer[2];
	//const int START_INDEX = 6;
	//S7_SetIntAt(dbBuffer,6-START_INDEX,1);
	//int a = encoder->ReadArea(S7AreaDB,1,0,2,4,&result);
	//int res = PLC->DBWrite(500,START_INDEX,2,dbBuffer);//&
	//int res = PLC->DBWrite(500,START_INDEX,1,&dbBuffer);
	//int DBRead(int DBNumber, int Start, int Size, void *pUsrData);
    //int DBWrite(int DBNumber, int Start, int Size, void *pUsrData);
	
	bool v1 = false, v2=true,v3=true,v4=true,v5=true,v6=true;
	int value;
	cout<<"Loop initiated..."<<endl;
	while(true)
	{
		
		byte db1Buffer[30];
		int read = PLC->DBRead(318,0,30,&db1Buffer);
		bool requestFlag = S7_GetBitAt(db1Buffer,0,0);
		cout<<"DB318.DBX0.0: "<<requestFlag<<endl;
		bool TRG1 = S7_GetBitAt(db1Buffer,1,0);
		cout<<"DB318.DBX1.0: "<<TRG1<<endl;
		int commandNumber = S7_GetIntAt(db1Buffer,16);
		cout<<"DB318.DBW16: "<<commandNumber<<endl;
		int commandParam = S7_GetIntAt(db1Buffer,20);
		cout<<"DB318.DBW20: "<<commandParam<<endl;
		usleep(50000);
		cout<<"\n"<<endl;
		/*
		
		byte dbOUT[4];
		string mystr;
		int q=0;
		getline (cin,mystr);
		stringstream(mystr) >> q;
		int read = PLC->DBRead(319,0,4,&dbOUT);
		cout<<"READ->"<<endl;
		bool errorFlag = S7_GetBitAt(dbOUT,0,1);
		cout<<"DB319.DBX0.1(errFlag): "<<errorFlag<<endl;
		bool readyFlag = S7_GetBitAt(dbOUT,0,2);
		cout<<"DB319.DBX0.2(rdyFlag): "<<readyFlag<<endl;
		bool partFlag = S7_GetBitAt(dbOUT,4,0);
		cout<<"DB319.DBX4.0(partFlag): "<<partFlag<<endl;
		bool ballsFlag = S7_GetBitAt(dbOUT,4,1);
		cout<<"DB319.DBX4.1(ballsFlag): "<<ballsFlag<<endl;
		bool cageFlag = S7_GetBitAt(dbOUT,4,2);
		cout<<"DB319.DBX4.2(ballsFlag): "<<cageFlag<<endl;
		bool trackFlag = S7_GetBitAt(dbOUT,4,3);
		cout<<"DB319.DBX4.3(ballsFlag): "<<trackFlag<<endl;
		//cout<<"ALL READ:\n"<<dbOUT<<endl;
		
		switch(q)
		{
			case 0:
				v1=v1;
				v2=v2;
				v3=v3;
				v4=v4;
				v5=v5;
				v6=v6;
				break;				
			case 1:
				v1=(v1);
				v2=(v2);
				v3=not(v3);
				v4=not(v4);
				v5=not(v5);
				v6=not(v6);
				break;
			case 2:
				value=10;
				break;
			default:
				value=10;
				break;
		}
		if(value==10)
		{
			
			break;
		}
		else
		{
			
			byte db0[1];
			byte db1[1];
			const int strtIDX = 0;
			const int strtIDX2 = 4;
			S7_SetBitAt(db0,strtIDX,1,v1);
			S7_SetBitAt(db0,strtIDX,2,v2);
			S7_SetBitAt(db1,strtIDX2,0,v3);
			S7_SetBitAt(db1,strtIDX2,1,v4);
			S7_SetBitAt(db1,strtIDX2,2,v5);
			S7_SetBitAt(db1,strtIDX2,3,v6);
	
			result = PLC->DBWrite(319,strtIDX,1,db0);
			result2 = PLC->DBWrite(319,strtIDX2,1,db1);
			if(result!=0)
			{
				cout<<"ERROR AT WRITING!!"<<endl;
			}
			if(result2!=0)
			{
				cout<<"ERROR AT WRITING 2!!"<<endl;
			}
			cout<<"WROTE->\n"<<endl;
		}*/
	}
	PLC->Disconnect();
	delete PLC;
	return 0;
}
