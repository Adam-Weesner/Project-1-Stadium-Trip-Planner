#ifndef SOUVENIRS_H
#define SOUVENIRS_H
#include <qstring.h>

class Souvenirs {
    public:
        Souvenirs();
        Souvenirs(QString nName, double nPrice);
        ~Souvenirs();
        QString GetName() const;
        double GetPrice() const;
        void SetAll(QString nName, double nPrice);
        void SetItem(QString name);
        void SetPrice(double price);
    private:
        QString name;
        double price;
};

#endif // SOUVENIRS_H
