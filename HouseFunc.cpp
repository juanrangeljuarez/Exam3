// File: HouseFunc
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include <iostream>
#include <vector>
#include <pthread.h>
#include <map>
#include "HouseFunc.h"
#include "HousePrice.h"
#include "csv.h" // library to read csv files
#include <algorithm>
#include <fstream>

using namespace std;


/*!
 * Read CSV Mock Data. Parses each record in the file to
 * an object of HousePrice house. Then, populate a vector
 * of HousePrice objects with all the records.
 * It uses special library to parse CSV file "csv.h"
 * @param fileIn File name <string>
 * @param hp Reference to Vector of HousePrice Objects
 */
void readCSV(const string fileIn,vector<HousePrice>& hp)
{
    ifstream in(fileIn);
    double price;
    in.is_open();
    string state;
    string city;
    string street;
    string id2;
    string postal2;
    string number2;
    string price2;
    int postalCode;
    int number;
    int id;
    int i = 0;

    // get data from the file
    while(in.good())
    {
        getline(in, id2, ',');
        getline(in, number2, ',');
        getline(in, street, ',');
        getline(in, city, ',');
        getline(in, state, ',');
        getline(in, postal2, ',');
        getline(in, price2, '\n');
        id = atoi(id2.c_str());
        number = atoi(number2.c_str());
        postalCode = atoi(postal2.c_str());
        price = atof(price2.c_str());
        if (i > 0 && i < 1001) {
            HousePrice house(id, number, street, city, state, postalCode, price);
            hp.push_back(house);
        }
        i++;
    }
    cout<< endl;
    for(auto item:hp)
    {
        cout << item << endl;
    }
    cout<< endl;
}


/*!
 * Sort the Vector of HousePrice Objects by price. Display the most affordable
 * and the most expensive house from the vector.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketValues(vector<HousePrice> &hp)
{
    sort(hp.begin(), hp.end(), [](HousePrice & house1, HousePrice & house2){return house1.getPrice() < house2.getPrice();});
    auto min = min_element(hp.begin(), hp.end(),
                           []( const HousePrice &house1, const HousePrice &house2 )
                           {
                               return house1.getPrice() < house2.getPrice();
                           } );

    cout << "The most affordable: "<< *min << endl;
    auto max = max_element(hp.begin(), hp.end(),
                           []( const HousePrice &house1, const HousePrice &house2)
                           {
                               return house1.getPrice() < house2.getPrice();
                           } );

    cout << "The most expensive: "<< *max << endl;
}


/*!
 * Sort the Vector of HousePrice Objects by state. Display the
 * number of houses per state.
 * It uses a map to count instances per state.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketPerState(vector<HousePrice> &hp)
{
    string states[47]; // array string of states
    int NumOfHouses[47]; // array number of houses
    bool flagFirstTime = false;
    string oldName;
    string name;
    int index = 0, numberHouses=0;

    // Sort by State
    sort(hp.begin(), hp.end(), [](HousePrice & house1, HousePrice & house2){return house1.getState() < house2.getState();});

    // get states and count houses
    for(auto item:hp)
    {
        oldName = name;
        name = item.getState();
        if(name != oldName && flagFirstTime)
        {
            NumOfHouses[index-1] = numberHouses;
            states[index] = name;
            index++;
            numberHouses = 0;
        }// end if
        else
        {
            if(!flagFirstTime)
            {
                states[index] = name;
                index++;
            }
            flagFirstTime = true;
        }
        numberHouses++;
    }// end if
    NumOfHouses[index-1] = numberHouses;

    // display states and number of houses
    cout<< endl;
    for(int i = 0; i < 47; i++)
    {
        cout << states[i]<< ": "<<NumOfHouses[i]<< "\t";
        if(((i+1)%10) == 0)
        {
            cout<<endl;
        }
    }
}// end housePerState

