#include "stadium.h"

Stadium::Stadium() {
    souvTotal = 0;
}

/**
 * @brief Stadium::Stadium
 * @param nStadiumName - stadium name
 * @param nLocation - city name
 * @param nConference - conference type
 * @param nCapacity - capacity number
 * @param nSurfaceType - field surface type
 * @param nRoofType - type of roof
 * @param nTotalRevenue - total revenue
 * @param nStarPlayer - star player of the stadium
 */
Stadium::Stadium(int nID, QString nTeamName, QString nStadiumName, double nCapacity, QString nLocation,
                 QString nConference, QString nSurfaceType, QString nRoofType, QString nStarName, double nTotalRevenue) {
    ID = nID;
    teamName = nTeamName;
    stadiumName = nStadiumName;
    capacity = nCapacity;
    location = nLocation;
    conference = nConference;
    surfaceType = nSurfaceType;
    roofType = nRoofType;
    starPlayer = nStarName;
    totalRevenue = nTotalRevenue;
    souvTotal = 0;
}

/**
 * @brief Stadium::~Stadium
 * @return  none
 */
Stadium::~Stadium() {}

/**
 * @brief Stadium::GetId
 * @return  id
 */
int Stadium::GetID() {
  return ID;
}

/**
 * @brief Stadium::GetTeamName
 * @return  teamName
 */
QString Stadium::GetTeamName() {
  return teamName;
}

/**
 * @brief Stadium::GetStadiumName
 * @return  stadiumName
 */
QString Stadium::GetStadiumName() { 
  return stadiumName;
}

/**
 * @brief Stadium::GetCapacity
 * @return  capacity
 */
double Stadium::GetCapacity() {
  return capacity;
}

/**
 * @brief Stadium::GetLocation
 * @return  location
 */
QString Stadium::GetLocation() { 
  return location;
}

/**
 * @brief Stadium::GetConference
 * @return  conference
 */
QString Stadium::GetConference() { 
  return conference;
}

/**
 * @brief Stadium::GetSurfaceType
 * @return  surfaceType
 */
QString Stadium::GetSurfaceType() { 
  return surfaceType;
}

/**
 * @brief Stadium::GetRoofType
 * @return  roofType
 */
QString Stadium::GetRoofType() { 
  return roofType;
}

/**
 * @brief Stadium::GetStarPlayer
 * @return  starPlayer
 */
QString Stadium::GetStarPlayer() {
  return starPlayer;
}

/**
 * @brief Stadium::GetTotalRevenue
 * @return  totalRevenue
 */
double Stadium::GetTotalRevenue() { 
  return totalRevenue;
}

/**
 * @brief Stadium::GetSouvenirs
 * @get all souviners 
 */
void Stadium::GetSouvenirs(QList<Souvenirs> &mySouvenirs) const {
    mySouvenirs = souvenirList;
}

/**
 * @brief Stadium::GetSouvenirName
 * @get named souviner
 */
QString Stadium::GetSouvenirName(int nID) const {
    return souvenirList.at(nID).GetName();
}

/**
 * @brief Stadium::GetSouvenirPrice
 * @get souvenir price
 */
double Stadium::GetSouvenirPrice(int nID) const {
    return souvenirList.at(nID).GetPrice();
}

/**
 * @brief Stadium::GetSouvTotal
 * @get souvenir total
 */
int Stadium::GetSouvTotal() const {
    return souvTotal;
}

/**
 * @brief Stadium::DisplaySouvenirs
 * @display all souvenirs
 */
void Stadium::DisplaySouvenirs() const {
    for (int i = 0; i < souvenirList.size(); i++) {
        qDebug() << souvenirList.at(i).GetName() << " - " << souvenirList.at(i).GetPrice();
    }
}


/**
 * @brief Stadium::SetId
 * @set id
 */
void Stadium::SetID(int nID) {
  ID = nID;
}

/**
 * @brief Stadium::SetTeamName
 * @set  stadiumName
 */
void Stadium::SetTeamName(QString nName) {
  teamName = nName;
}

/**
 * @brief Stadium::SetStadiumName
 * @set  stadiumName
 */
void Stadium::SetStadiumName(QString nName) {
  stadiumName = nName;
}

/**
 * @brief Stadium::SetCapacity
 * @set  capacity
 */
void Stadium::SetCapacity(double nCapacity) {
  capacity = nCapacity;
}

/**
 * @brief Stadium::SetLocation
 * @set  location
 */
void Stadium::SetLocation(QString nLocation) {
  location = nLocation;
}

/**
 * @brief Stadium::SetConference
 * @set  conference
 */
void Stadium::SetConference(QString nConference) {
  conference = nConference;
}

/**
 * @brief Stadium::SetSurfaceType
 * @set  surfaceType
 */
void Stadium::SetSurfaceType(QString nSurfaceType) {
  surfaceType = nSurfaceType;
}

/**
 * @brief Stadium::SetRoofType
 * @set  roofType
 */
void Stadium::SetRoofType(QString nRoofType) {
  roofType = nRoofType;
}

/**
 * @brief Stadium::SetStarPlayer
 * @set  starPlayer
 */
void Stadium::SetStarPlayer(QString nStar) {
  starPlayer = nStar;
}

/**
 * @brief Stadium::TotalRevenue
 * @set  totalRevenue
 */
void Stadium::SetInitRevenue(double nRevenue) {
  totalRevenue = nRevenue;
}

/**
 * @brief Stadium::TotalRevenue
 * @set  totalRevenue
 */
void Stadium::SetTotalRevenue(double nRevenue) {
  totalRevenue += nRevenue;
}

/**
 * @brief Stadium::SetSouvenirPrice
 * @set  souvenirPrice
 */
void Stadium::SetSouvenirPrice(int i, double souvPrice) {
    i -= 2;
    souvenirList[i].SetPrice(souvPrice);
//    qDebug() << souvenirList[i].GetName() << " - " << souvenirList[i].GetPrice() << ": " << i << endl;
}

/**
 * @brief Stadium::AddSouvenir
 * @set  souvenirList
 */
void Stadium::AddSouvenir(Souvenirs nSouvenir) {
    souvenirList.push_back(nSouvenir);
    souvTotal++;
}

/**
 * @brief Stadium::RemoveSouvenir
 * @set removes identified souvenir
 */
void Stadium::RemoveSouvenir(int i) {
    souvenirList.removeAt(i);
    souvTotal--;
}

/**
 * @brief Stadium::ClearSouvenirs()
 * @set removes all from souvenir list
 */
void Stadium::ClearSouvenirs() {
    souvenirList.clear();
}
