#ifndef STADIUM_H
#define STADIUM_H
#include "souvenirs.h"
#include <qlist.h>
#include <qstring.h>
#include <sstream>
#include <vector>
#include <QDebug>

class Stadium {
    public:
        Stadium();
        Stadium(int nID, QString nTeamName, QString nStadiumName, double nCapacity, QString nLocation, 
                QString nConference, QString nSurfaceType, QString nRoofType, QString nStarName, double nRevenue);
       ~Stadium();
        //Accessors
        int GetID();
        QString GetTeamName();
        QString GetStadiumName();
        double GetCapacity();
        QString GetLocation();
        QString GetConference();
        QString GetSurfaceType();
        QString GetRoofType();
        QString GetStarPlayer();
        double GetTotalRevenue();
        void GetSouvenirs(QList<Souvenirs> &mySouvenirs) const;
        QString GetSouvenirName(int nID) const;
        double GetSouvenirPrice(int nID) const;
        int GetSouvTotal() const;
        void DisplaySouvenirs() const;
        //Mutators
        void SetID(int nID);
        void SetTeamName(QString nName);
        void SetStadiumName(QString nName);
        void SetCapacity(double nCapacity);
        void SetLocation(QString nLocation);
        void SetConference(QString nConference);
        void SetSurfaceType(QString nSurfaceType);
        void SetRoofType(QString nRoofType);
        void SetStarPlayer(QString nStar);
        void SetInitRevenue(double nRevenue);
        void SetTotalRevenue(double nRevenue);
        void SetSouvenirPrice(int i, double souvPrice);
        void AddSouvenir(Souvenirs nSouvenir);
        void RemoveSouvenir(int i);
        void ClearSouvenirs();
    private:
        int ID;
        QString teamName;
        QString stadiumName;
        double capacity;
        QString location;
        QString conference;
        QString surfaceType;
        QString roofType;
        QString starPlayer;
        double totalRevenue;
        int souvTotal;
        QList<Souvenirs> souvenirList;
};

#endif // STADIUM_H
