#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
using namespace std;

class Carmodel
{
public:
    string brand;
    string model;
    string color;
    int year;
    double price;
    double mileage;

    void display()
    {
        cout << "Brand Car: " << brand << endl;
        cout << "Car Model: " << model << endl;
        cout << "Color of Car: " << color << endl;
        cout << "Production Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Mileage: " << mileage << endl;
    }

    void saveToExcel(const string &filename)
    {
        bool fileExists = false;
        struct stat buffer;
        if (stat(filename.c_str(), &buffer) == 0)
            fileExists = true;

        ofstream file(filename, ios::app);
        if (file.is_open())
        {
            if (!fileExists)
            {
                // More descriptive column titles
                file << "Brand Car,Car Model,Color of Car,Production Year,Price,Mileage\n";
            }

            file << brand << "," << model << "," << color << ","
                 << year << "," << price << "," << mileage << "\n";
            file.close();
        }
        else
        {
            cerr << "Failed to open file: " << filename << endl;
        }
    }
};

int main()
{
    Carmodel car1;
    cout << "Enter brand: ";
    cin >> car1.brand;
    cout << "Enter model: ";
    cin >> car1.model;
    cout << "Enter color: ";
    cin >> car1.color;
    cout << "Enter year: ";
    cin >> car1.year;
    cout << "Enter price: ";
    cin >> car1.price;
    cout << "Enter mileage: ";
    cin >> car1.mileage;

    car1.display();
    car1.saveToExcel("car_details.csv");

    cout << "Data saved to 'car_details.csv'. Open it in Excel to see descriptive column titles." << endl;
    return 0;
}