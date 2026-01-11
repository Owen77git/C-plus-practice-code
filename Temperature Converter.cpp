// File: temperature_converter.cpp (55 lines)
#include <iostream>
#include <iomanip>

class TemperatureConverter {
private:
    double temperature;
    char scale;
    
    double toCelsius() const {
        switch (scale) {
            case 'C': return temperature;
            case 'F': return (temperature - 32) * 5/9;
            case 'K': return temperature - 273.15;
            default: return 0;
        }
    }
    
    double toFahrenheit() const {
        return toCelsius() * 9/5 + 32;
    }
    
    double toKelvin() const {
        return toCelsius() + 273.15;
    }
    
public:
    TemperatureConverter(double temp, char sc) : temperature(temp), scale(toupper(sc)) {}
    
    void displayAll() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\n=== Temperature Conversions ===\n";
        std::cout << "Celsius: " << toCelsius() << " °C\n";
        std::cout << "Fahrenheit: " << toFahrenheit() << " °F\n";
        std::cout << "Kelvin: " << toKelvin() << " K\n";
    }
    
    bool isValid() const {
        switch (scale) {
            case 'C': return temperature >= -273.15; // Absolute zero
            case 'F': return temperature >= -459.67; // Absolute zero in Fahrenheit
            case 'K': return temperature >= 0;       // Absolute zero in Kelvin
            default: return false;
        }
    }
};

int main() {
    std::cout << "Temperature Converter\n";
    std::cout << "====================\n";
    
    // Test cases
    TemperatureConverter temps[] = {
        TemperatureConverter(100, 'C'),
        TemperatureConverter(32, 'F'),
        TemperatureConverter(300, 'K'),
        TemperatureConverter(-10, 'C')
    };
    
    for (int i = 0; i < 4; i++) {
        std::cout << "\nTest Case " << i + 1 << ": ";
        if (temps[i].isValid()) {
            temps[i].displayAll();
        } else {
            std::cout << "Invalid temperature (below absolute zero)!\n";
        }
    }
    
    // Interactive conversion
    double temp;
    char scale;
    std::cout << "\nEnter temperature and scale (e.g., 100 C): ";
    std::cin >> temp >> scale;
    
    TemperatureConverter userTemp(temp, scale);
    if (userTemp.isValid()) {
        userTemp.displayAll();
    } else {
        std::cout << "Invalid temperature input!\n";
    }
    
    return 0;
}
