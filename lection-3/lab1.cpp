#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <clocale>


using namespace std;

int main() {
    const int NEWS_COUNT = 4;
    const double RADIUS = 10.0;
    double a[NEWS_COUNT];
    char* news[] = {
     "Fire",
     "Flood",
     "Asteroid",
     "City Day"    
    };
    
    double lats[] = {
     45.5,
     48.6,
     58.6,
     60.6
    };
    
    double lons[] = {
     40.5,
     47.6,
     56.6,
     43.6
    };

	char* b[NEWS_COUNT];
	char* c[1];
    setlocale(LC_ALL,"RUS");
    cout << "������� � ����� �������:" << endl << endl;
    
    double myLat, myLon,tmp,distance;
    
    cout << "������� ���� ����������" << endl;
    
    cin >> myLat >> myLon;
    
    bool hasNews = false;
    
    
    for(int i = 0; i < NEWS_COUNT; ++i) 
	 {  
	   distance =sqrt(pow((myLat - lats[i]), 2) + pow((myLon - lons[i]), 2));
       if(distance < RADIUS) 
	    {
		 a[i] = distance;
		 b[i] = news[i];           
        }   
     }
  
	//����� ���������� ��������
	for(int i = 0; i < NEWS_COUNT- 1; ++i) // i - ����� �������
    {            
        for(int j = 0; j < NEWS_COUNT- 1; ++j) // ���������� ���� �������
        {     
            if (a[j + 1] < a[j]) 
            {
                tmp = a[j + 1]; 
                a[j + 1] = a[j]; 
                a[j] = tmp;

				c[1] = b[j + 1]; 
                b[j + 1] = b[j]; 
                b[j] = c[1];
            }
        }
    }


	for(int i = 0; i < NEWS_COUNT- 1; ++i)
	{
		cout <<b[i]<<" - "<<a[i]<<endl;
	}

}