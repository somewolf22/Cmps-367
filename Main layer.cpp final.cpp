/*

Group members: Cameron Wolf/John Bryant
Date: 12/01/2023
course: CMPS 367
Assignment: Final Project 

*/


#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Profile {
	string name;
	int lightOnHour;
	int lightOffHour;
	double minTemperature;
	double maxTemperature;
	double minHumidity;
	double maxHumidity;
};

const int MAX_SENSORS = 3;
const int MAX_PROFILES = 3;

double calculateAverage(double readings[], int count) {
	double sum = 0.0;
	for (int i = 0; i < count; ++i) {
		sum += readings[i];
	}
	return count > 0 ? sum / count : 0.0;
}

void controlEnvironment(const Profile& profile, double avgTemperature, double avgHumidity) {
	bool heatLampOn = false;
	bool humidifierOn = false;

	if (avgTemperature < profile.minTemperature) {
		heatLampOn = true;
		cout << "Heat lamp turned ON (Temperature below minimum)" << endl;
	}
	else if (avgTemperature > profile.maxTemperature) {
		cout << "Heat lamp turned OFF (Temperature above maximum)" << endl;
	}
	else {
		cout << "Heat lamp status unchanged (Temperature within range)" << endl;
	}

	if (avgHumidity < profile.minHumidity) {
		humidifierOn = true;
		cout << "Humidifier turned ON (Humidity below minimum)" << endl;
	}
	else if (avgHumidity > profile.maxHumidity) {
		cout << "Humidifier turned OFF (Humidity above maximum)" << endl;
	}
	else {
		cout << "Humidifier status unchanged (Humidity within range)" << endl;
	}
}

int main() {
	Profile reptileProfiles[MAX_PROFILES] = {
		{"Bearded Dragon", 6, 17, 80, 90, 30, 40},
		{"Ball Python", 8, 16, 78, 89, 55, 80},
		{"Leopard Gecko", 7, 17, 75, 85, 50, 60}
	};

	Profile plantProfiles[MAX_PROFILES] = {
		{"Monstera", 8, 16, 60, 80, 75, 85},
		{"Alocasia", 8, 14, 60, 85, 80, 90},
		{"Philodendron", 10, 14, 65, 80, 70, 80}
	};

	double temperatureReadings[MAX_SENSORS] = { 72, 78, 81 }; // Example readings
	double humidityReadings[MAX_SENSORS] = { 35, 40, 38 };    // Example readings

	double avgTemperature = calculateAverage(temperatureReadings, MAX_SENSORS);
	double avgHumidity = calculateAverage(humidityReadings, MAX_SENSORS);

	cout << "Average Temperature: " << avgTemperature << " Degrees F" << endl;
	cout << "Average Humidity: " << avgHumidity << "%" << endl;

	string profileType;
	cout << "Select profile type (Plant/Reptile): ";
	cin >> profileType;

	Profile selectedProfile;

	if (profileType == "Plant") {
		// For simplicity, selecting the first plant profile
		selectedProfile = plantProfiles[0];
	}
	else if (profileType == "Reptile") {
		// For simplicity, selecting the first reptile profile
		selectedProfile = reptileProfiles[0];
	}
	else {
		cout << "Invalid profile type." << endl;
		return 1;
	}

	// Control the environment based on the selected profile
	controlEnvironment(selectedProfile, avgTemperature, avgHumidity);

	return 6787;
}
