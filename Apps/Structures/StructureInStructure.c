#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    typedef struct 
    {
        int id;
        char brand[30];
        char engineType[30];
    } Car;

    typedef struct 
    {
        Car car;
        int engineWattage;
    } ElectricCar;

    typedef struct 
    {
        Car car;
        int engineCC;
    } GasolineCar;

    ElectricCar electricCar  = { 1, "TESLA", "Electric", 7000};
    GasolineCar gasCar = {2, "BMW", "Gas", 2000};

    printf("id = %d\n", electricCar.car.id);
    printf("id = %d, brand = %s, Engine Type = %s, EngineCC = %d\n", gasCar.car.id, gasCar.car.brand, gasCar.car.engineType, gasCar.engineCC);
    
    
    
    return 0;
}
