#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <fstream>

using namespace std;

const int MAX_SENSORS = 3;
const int MAX_PROFILES = 3;

// Function to calculate the average of an array of values
double calculateAverage(int values[], int count) {
	int sum = 0;
	for (int i = 0; i < count; ++i) {
		sum += values[i];
	}
	return sum / count;
}

// Get the current time point
auto currentTimePoint = std::chrono::system_clock::now();

// Convert the time point to a time_t object
std::time_t currentTime = std::chrono::system_clock::to_time_t(currentTimePoint);

// Convert the time_t object to a string representation
std::string currentTimeStr = std::ctime(&currentTime);


int main()
{
	const int numSensors = 3;
	int temperatures[numSensors];
	int humidities[numSensors];
	//welcome message.

	cout << "Welcome to the enviroment controller program.\n";
	cout << "This program will allow you to enter the temperature and humidity of 3 sensors.\n";
	cout << "The program will then calculate the average temperature and humidity of the sensors.\n" << endl;

	cout << "Please enter the data for each sensor.\n";


	// Simulate measuring temperature and humidity for each sensor
	for (int i = 0; i < numSensors; ++i) {
		cout << "Sensor " << i + 1 << " - Enter temperature (in Farenheit): ";
		cin >> temperatures[i];

		cout << "Sensor " << i + 1 << " - Enter humidity (in percentage): ";
		cin >> humidities[i];
	}

	// Calculate the average temperature and humidity
	int avgTemperature = calculateAverage(temperatures, numSensors);
	int avgHumidity = calculateAverage(humidities, numSensors);

	// Display the collected data and the averages
	cout << "\nCollected Sensor Data:\n";
	for (int i = 0; i < numSensors; ++i) {
		cout << "Sensor " << i + 1 << " - Temperature: " << temperatures[i] << " °C, Humidity: " << humidities[i] << " %\n";
	}

	cout << "\nAverage Data - Temperature: " << avgTemperature << " °C, Humidity: " << avgHumidity << " %\n" << endl;


	cout << "The program will now determine wether or not your hardware will be on or off based on the average temp, humidity, and hour of day it is for light." << endl;

	int temperatureReadings[MAX_SENSORS] = { 72, 78, 81 }; // Example readings
	int humidityReadings[MAX_SENSORS] = { 35, 40, 38 };    // Example readings

	int avgTemperature1 = calculateAverage(temperatureReadings, MAX_SENSORS);
	int avgHumidity1 = calculateAverage(humidityReadings, MAX_SENSORS);

	cout << "Average Temperature: " << avgTemperature << " Degrees F" << endl;
	cout << "Average Humidity: " << avgHumidity << "%" << endl;

	string choice;
	char sub_type, yn;
	bool heatLampOn = false;
	bool humidifierOn = false;
	do
	{
		cout << "Select profile type (Plant/Reptile): ";
		cin >> choice;

		// Get the current time point
		auto currentTimePoint = std::chrono::system_clock::now();

		// Convert the time point to a time_t object
		std::time_t currentTime = std::chrono::system_clock::to_time_t(currentTimePoint);

		// Convert the time_t object to a string representation
		std::string currentTimeStr = std::ctime(&currentTime);

		if (choice == "Plant" || choice == "plant")
		{
			cout << "Please select your plant type(1/2/3):\n 1. Monstera\n 2. Alocasia\n 3. Philodendron\n";
			cin >> sub_type;

			switch (sub_type)
			{
			case '1':
				if (avgTemperature < 60)
				{
					heatLampOn = true;
					cout << "Heat lamp turned ON (Temperature below minimum)" << endl;
				}
				else if (avgTemperature > 80)
				{
					cout << "Heat lamp turned OFF (Temperature above maximum)" << endl;
				}
				else
				{
					cout << "Heat lamp status unchanged (Temperature within range)" << endl;
				}

				if (avgHumidity < 75)
				{
					humidifierOn = true;
					cout << "Humidifier turned ON (Humidity below minimum)" << endl;
				}
				else if (avgHumidity > 85)
				{
					cout << "Humidifier turned OFF (Humidity above maximum)" << endl;
				}
				else
				{
					cout << "Humidifier status unchanged (Humidity within range)" << endl;
				}

				if (currentTimeStr == "kjvvkjn" && currentTimeStr == "jhfbkj")
				{
					cout << "The current time is " << currentTimeStr << " therefore the light will be turned on.\n";
				}
				else
				{
					cout << "The current time is " << currentTimeStr << " therefore the light will be turned off.\n";
				}
				break;
			case '2':
				if (avgTemperature < 60)
				{
					heatLampOn = true;
					cout << "Heat lamp turned ON (Temperature below minimum)" << endl;
				}
				else if (avgTemperature > 85)
				{
					cout << "Heat lamp turned OFF (Temperature above maximum)" << endl;
				}
				else
				{
					cout << "Heat lamp status unchanged (Temperature within range)" << endl;
				}
				if (avgHumidity < 80)
				{
					humidifierOn = true;
					cout << "Humidifier turned ON (Humidity below minimum)" << endl;
				}
				else if (avgHumidity > 90)
				{
					cout << "Humidifier turned OFF (Humidity above maximum)" << endl;
				}
				else
				{
					cout << "Humidifier status unchanged (Humidity within range)" << endl;
				}

				if (currentTimeStr == "kjvvkjn" && currentTimeStr == "jhfbkj")
				{
					cout << "The current time is " << currentTimeStr << " therefore the light will be turned on.\n";
				}
				else
				{
					cout << "The current time is " << currentTimeStr << " therefore the light will be turned off.\n";
				}
				break;
			case '3':
				if (avgTemperature < 65)
				{
					heatLampOn = true;
					cout << "Heat lamp turned ON (Temperature below minimum)" << endl;
				}
				else if (avgTemperature > 80)
				{
					cout << "Heat lamp turned OFF (Temperature above maximum)" << endl;
				}
				else
				{
					cout << "Heat lamp status unchanged (Temperature within range)" << endl;
				}

				if (avgHumidity < 70)
				{
					humidifierOn = true;
					cout << "Humidifier turned ON (Humidity below minimum)" << endl;
				}
				else if (avgHumidity > 80)
				{
					cout << "Humidifier turned OFF (Humidity above maximum)" << endl;
				}
				else
				{
					cout << "Humidifier status unchanged (Humidity within range)" << endl;
				}

				if (currentTimeStr == "kjvvkjn" && currentTimeStr == "jhfbkj")
				{
					cout << "The current time is " << currentTimeStr << " therefore the light will be turned on.\n";
				}
				else
				{
					cout << "The current time is " << currentTimeStr << " therefore the light will be turned off.\n";
				}
				break;
			}
		}
		else if (choice == "Reptile" || choice == "reptile")
		{
			cout << "Please select your Reptile type(1/2/3):\n 1. Ball Python\n 2. Bearded  Dragon\n 3. Leopard Gecko\n";
			cin >> sub_type;
			switch (sub_type)
			{
			case '1':
				if (avgTemperature < 78)
				{
					heatLampOn = true;
					cout << "Heat lamp turned ON (Temperature below minimum)" << endl;
				}
				else if (avgTemperature > 89)
				{
					cout << "Heat lamp turned OFF (Temperature above maximum)" << endl;
				}
				else
				{
					cout << "Heat lamp status unchanged (Temperature within range)" << endl;
				}

				if (avgHumidity < 55)
				{
					humidifierOn = true;
					cout << "Humidifier turned ON (Humidity below minimum)" << endl;
				}
				else if (avgHumidity > 80)
				{
					cout << "Humidifier turned OFF (Humidity above maximum)" << endl;
				}
				else
				{
					cout << "Humidifier status unchanged (Humidity within range)" << endl;
				}

				if (currentTimeStr == "kjvvkjn" && currentTimeStr == "jhfbkj")
				{
					cout << "The current time is " << currentTimeStr << " therefore the light will be turned on.\n";
				}
				else
				{
					cout << "The current time is " << currentTimeStr << " therefore the light will be turned off.\n";
				}
				break;
			case '2':
				if (avgTemperature < 80)
				{
					heatLampOn = true;
					cout << "Heat lamp turned ON (Temperature below minimum)" << endl;
				}
				else if (avgTemperature > 90)
				{
					cout << "Heat lamp turned OFF (Temperature above maximum)" << endl;
				}
				else
				{
					cout << "Heat lamp status unchanged (Temperature within range)" << endl;
				}

				if (avgHumidity < 30)
				{
					humidifierOn = true;
					cout << "Humidifier turned ON (Humidity below minimum)" << endl;
				}
				else if (avgHumidity > 40)
				{
					cout << "Humidifier turned OFF (Humidity above maximum)" << endl;
				}
				else
				{
					cout << "Humidifier status unchanged (Humidity within range)" << endl;
				}

				if (currentTimeStr == "kjvvkjn" && currentTimeStr == "jhfbkj")
				{
					cout << "The current time is " << currentTimeStr << " therefore the light will be turned on.\n";
				}
				else
				{
					cout << "The current time is " << currentTimeStr << " therefore the light will be turned off.\n";
				}
				break;
			case '3':
				if (avgTemperature < 75)
				{
					heatLampOn = true;
					cout << "Heat lamp turned ON (Temperature below minimum)" << endl;
				}
				else if (avgTemperature > 85)
				{
					cout << "Heat lamp turned OFF (Temperature above maximum)" << endl;
				}
				else
				{
					cout << "Heat lamp status unchanged (Temperature within range)" << endl;
				}

				if (avgHumidity < 50)
				{
					humidifierOn = true;
					cout << "Humidifier turned ON (Humidity below minimum)" << endl;
				}
				else if (avgHumidity > 60)
				{
					cout << "Humidifier turned OFF (Humidity above maximum)" << endl;
				}
				else
				{
					cout << "Humidifier status unchanged (Humidity within range)" << endl;
				}

				if (currentTimeStr == "kjvvkjn" && currentTimeStr == "jhfbkj")
				{
					cout << "The current time is " << currentTimeStr << " therefore the light will be turned on.\n";
				}
				else
				{
					cout << "The current time is " << currentTimeStr << " therefore the light will be turned off.\n";
				}
				break;
			}
		}
		else
		{
			cout << "Invalid profile type." << endl;
		}
		cout << endl;
		cout << "Would you like to run another analysis(y/n)? "; cin >> yn;
	} while (yn == 'Y' || yn == 'y');

	cout << "Thank you for using our program, see you next time!\n";

	//terminate program
	system("pause");
	return 0;
}