#include <iostream>
#include <string>

using namespace std;

class Transport {
protected:
    string type; // Тип транспорта
    double distance; // Расстояние между Одессой и Киевом (в км)

public:
    Transport(string type, double distance) {
        SetType(type);
        SetDistance(distance);
    }

    virtual ~Transport() {}

    virtual double CalculateTime() const = 0;
    virtual double CalculateCost() const = 0;

    void SetType(string type) {
        this->type = type;
    }

    void SetDistance(double distance) {
        this->distance = distance;
    }

    string GetType() const {
        return type;
    }

    double GetDistance() const {
        return distance;
    }
};

class Car : public Transport {
public:
    Car(double distance) : Transport("Car", distance) {}

    double CalculateTime() const {
        return GetDistance() / 110.0; // Средняя скорость автомобиля 110 км/ч
    }

    double CalculateCost() const {
        double fuelPricePerLiter = 50.0;
        double fuelConsumptionPer100Km = 10.0;
        double costPerKm = (fuelPricePerLiter * fuelConsumptionPer100Km) / 100.0;
        return GetDistance() * costPerKm;
    }
};

class Taxi : public Transport {
public:
    Taxi(double distance) : Transport("Taxi", distance) {}

    double CalculateTime() const {
        return GetDistance() / 100.0; // Средняя скорость такси 100 км/ч
    }

    double CalculateCost() const {
        return GetDistance() * 15.0; // Стоимость поездки на такси 15 грн за километр
    }
};

class Tram : public Transport {
public:
    Tram(double distance) : Transport("Tram", distance) {}

    double CalculateTime() const {
        cout << "Tram cannot travel from Odessa to Kiev." << "\n";
        return 0;
    }

    double CalculateCost() const {
        cout << "Tram cannot travel from Odessa to Kiev." << "\n";
        return 0;
    }
};

class Trolleybus : public Transport {
public:
    Trolleybus(double distance) : Transport("Trolleybus", distance) {}

    double CalculateTime() const {
        cout << "Trolleybus cannot travel from Odessa to Kiev." << "\n";
        return 0;
    }

    double CalculateCost() const {
        cout << "Trolleybus cannot travel from Odessa to Kiev." << "\n";
        return 0;
    }
};

class Marshrutka : public Transport {
public:
    Marshrutka(double distance) : Transport("Marshrutka", distance) {}

    double CalculateTime() const {
        cout << "Marshrutka 242 cannot travel from Odessa to Kiev." << "\n";
        return 0;
    }

    double CalculateCost() const {
        cout << "Marshrutka 242 cannot travel from Odessa to Kiev." << "\n";
        return 0;
    }
};

class Scooter : public Transport {
public:
    Scooter(double distance) : Transport("Scooter", distance) {}

    double CalculateTime() const {
        return GetDistance() / 10.0; // Средняя скорость самоката 10 км/ч
    }

    double CalculateCost() const {
        return 0;  // Поездка на самокате бесплатная
    }
};

class Train : public Transport {
public:
    Train(double distance) : Transport("Train", distance) {}

    double CalculateTime() const {
        return GetDistance() / 80.0; // Средняя скорость поезда 80 км/ч
    }

    double CalculateCost() const {
        return 800.0; // Условная стоимость проезда на поезде
    }
};

class Airplane : public Transport {
public:
    Airplane(double distance) : Transport("Airplane", distance) {}

    double CalculateTime() const {
        return GetDistance() / 900.0; // Средняя скорость самолета 900 км/ч
    }

    double CalculateCost() const {
        return 1200; // Условная стоимость проезда на самолете
    }
};

class Bicycle : public Transport {
public:
    Bicycle(double distance) : Transport("Bicycle", distance) {}

    double CalculateTime() const {
        return GetDistance() / 15.0; // Средняя скорость велосипеда 15 км/ч
    }

    double CalculateCost() const {
        return 0; // Поездка на велосипеде бесплатная
    }
};

int main() {
    double distanceOdessaToKiev = 500.0; // Примерное расстояние между Одессой и Киевом (в км)

    Car car(distanceOdessaToKiev);
    cout << "Using " << car.GetType() << ":" << "\n";
    cout << "Time: " << car.CalculateTime() << " hours" << "\n";
    cout << "Cost: " << car.CalculateCost() << " UAH" << "\n\n";

    Taxi taxi(distanceOdessaToKiev);
    cout << "Using " << taxi.GetType() << ":" << "\n";
    cout << "Time: " << taxi.CalculateTime() << " hours" << "\n";
    cout << "Cost: " << taxi.CalculateCost() << " UAH" << "\n\n";

    Tram tram(distanceOdessaToKiev);
    cout << "Using " << tram.GetType() << ":" << "\n";
    tram.CalculateTime();
    tram.CalculateCost();

    Trolleybus trolleybus(distanceOdessaToKiev);
    cout << "\nUsing " << trolleybus.GetType() << ":" << "\n";
    trolleybus.CalculateTime();
    trolleybus.CalculateCost();

    Marshrutka marshrutka(distanceOdessaToKiev);
    cout << "\nUsing " << marshrutka.GetType() << ":" << "\n";
    marshrutka.CalculateTime();
    marshrutka.CalculateCost();

    Scooter scooter(distanceOdessaToKiev);
    cout << "\nUsing " << scooter.GetType() << ":" << "\n";
    cout << "Time: " << scooter.CalculateTime() << " hours" << "\n";
    cout << "Cost: " << scooter.CalculateCost() << " UAH" << "\n\n";

    Train train(distanceOdessaToKiev);
    cout << "Using " << train.GetType() << ":" << "\n";
    cout << "Time: " << train.CalculateTime() << " hours" << "\n";
    cout << "Cost: " << train.CalculateCost() << " UAH" << "\n\n";

    Airplane airplane(distanceOdessaToKiev);
    cout << "Using " << airplane.GetType() << ":" << "\n";
    cout << "Time: " << airplane.CalculateTime() << " hours" << "\n";
    cout << "Cost: " << airplane.CalculateCost() << " UAH" << "\n\n";

    Bicycle bicycle(distanceOdessaToKiev);
    cout << "Using " << bicycle.GetType() << ":" << "\n";
    cout << "Time: " << bicycle.CalculateTime() << " hours" << "\n";
    cout << "Cost: " << bicycle.CalculateCost() << " UAH" << "\n\n";

}