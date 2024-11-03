#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double convertCelsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Celsius to Kelvin
double convertCelsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

// Function to convert Fahrenheit to Celsius
double convertFahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert Fahrenheit to Kelvin
double convertFahrenheitToKelvin(double fahrenheit) {
    return convertCelsiusToKelvin(convertFahrenheitToCelsius(fahrenheit));
}

// Function to convert Kelvin to Celsius
double convertKelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

// Function to convert Kelvin to Fahrenheit
double convertKelvinToFahrenheit(double kelvin) {
    return convertCelsiusToFahrenheit(convertKelvinToCelsius(kelvin));
}

// Function to perform the conversion based on input scales
double convertTemperature(double value, char fromScale, char toScale) {
    if (fromScale == toScale) {
        return value; // No conversion needed if scales are the same
    }

    switch (fromScale) {
        case 'C':
            if (toScale == 'F') return convertCelsiusToFahrenheit(value);
            if (toScale == 'K') return convertCelsiusToKelvin(value);
            break;
        case 'F':
            if (toScale == 'C') return convertFahrenheitToCelsius(value);
            if (toScale == 'K') return convertFahrenheitToKelvin(value);
            break;
        case 'K':
            if (toScale == 'C') return convertKelvinToCelsius(value);
            if (toScale == 'F') return convertKelvinToFahrenheit(value);
            break;
        default:
            return value; // Return original value for unsupported scales
    }
    return value; // Fallback return (shouldn't be reached)
}

int main() {
    double temperatureValue;
    char currentScale, targetScale;

    // Introduction message
    printf("Welcome to the Temperature Converter!\n");

    // Input temperature value
    printf("Please enter the temperature value you want to convert: ");
    scanf("%lf", &temperatureValue);

    // Input current scale
    printf("Is this temperature in Celsius (C), Fahrenheit (F), or Kelvin (K)? ");
    scanf(" %c", &currentScale);

    // Input target scale
    printf("What scale would you like to convert this temperature to? (C, F, K): ");
    scanf(" %c", &targetScale);

    // Validate input scales
    if ((currentScale != 'C' && currentScale != 'F' && currentScale != 'K') ||
        (targetScale != 'C' && targetScale != 'F' && targetScale != 'K')) {
        printf("Error: Please enter valid scales (C, F, K).\n");
        return 1; // Exit with error
    }

    // Perform the conversion
    double convertedTemperature = convertTemperature(temperatureValue, currentScale, targetScale);

    // Output the result
    printf("%.2f %c is equivalent to %.2f %c.\n", temperatureValue, currentScale, convertedTemperature, targetScale);

    return 0; // Program completed successfully
}
