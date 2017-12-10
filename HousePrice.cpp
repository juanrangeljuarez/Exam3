// File: HousePrice
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include "HousePrice.h"


HousePrice::HousePrice(int id2, int number2, const string &street2, const string &city2, const string &state2,
                       int postalCode2, double price2)
{
    id = id2;
    number = number2;
    street = street2;
    city = city2;
    state = state2;
    postalCode = postalCode2;
    price = price2;
}

ostream &operator<<(ostream &os, const HousePrice &price)
{
    os<<"id: " << price.id;
    os<<" number: " << price.number;
    os<<" postalCode: "<<price.postalCode;
    os<<" street: " << price.street;
    os<<" city: "<<price.city;
    os<<" state: "<< price.state;
    os<<" price: "<<price.price;
    return os;
}


HousePrice::HousePrice() {

}

double HousePrice::getPrice() const
{
    return price;
}

const string &HousePrice::getState() const
{
    return state;
}
