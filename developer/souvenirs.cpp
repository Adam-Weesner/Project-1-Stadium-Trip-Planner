#include "souvenirs.h"

/*****************************************************************************
 * Souvenirs
 *____________________________________________________________________________
 * This method will initialize the class.
 *****************************************************************************/
Souvenirs::Souvenirs() {
    name = "";
    price = 0.00;
}

/*****************************************************************************
 * Souvenirs
 *____________________________________________________________________________
 * This method will initialize the class.
 *****************************************************************************/
Souvenirs::Souvenirs(QString nName, double nPrice) {
	name = nName;
	price = nPrice;
}

/*****************************************************************************
 * ~Souvenirs
 *____________________________________________________________________________
 * This method will deconstruct the class.
 *****************************************************************************/
Souvenirs::~Souvenirs() { }

/*****************************************************************************
 * GetName
 *____________________________________________________________________________
 * This method will return the name.
 *****************************************************************************/
QString Souvenirs::GetName() const {
    return name;
}

/*****************************************************************************
 * GetPrice
 *____________________________________________________________________________
 * This method will return the price.
 *****************************************************************************/
double Souvenirs::GetPrice() const {
    return price;
}

/*****************************************************************************
 * SetAll
 *____________________________________________________________________________
 * This method will set all values
 *****************************************************************************/
void Souvenirs::SetAll(QString nName, double nPrice) {
    name = nName;
    price = nPrice;
}

/*****************************************************************************
 * SetItem
 *____________________________________________________________________________
 * This method will set the item name;
 *****************************************************************************/
void Souvenirs::SetItem(QString nName) {
	name = nName;
}

/*****************************************************************************
 * SetPrice
 *____________________________________________________________________________
 * This method will set the price.
 *****************************************************************************/
void Souvenirs::SetPrice(double nPrice) {
    	price = nPrice;
}