/*
        Name            Cameron Wolf
        Date            12/11/23
        Course          CMPS 367
        Assignment      Final  
*/

#include <iostream>
#include <string>
#include "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\include\stdc.h">

using namespace std;

void recursiveBubbleSort(int arr[], int n) {
    if (n == 1) {
        return;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    recursiveBubbleSort(arr, n - 1);
}

double calculateAverage(int arr[], int n, int pointsPossible) {
    double totalScore = accumulate(arr, arr + n, 0);
    return (totalScore / (n * pointsPossible)) * 100.0;
}

int findMinimum(int arr[], int n) {
    return *min_element(arr, arr + n);
}

int findMaximum(int arr[], int n) {
    return *max_element(arr, arr + n);
}

int main() {
    cout << "*************Welcome to Grade Calculator!***********" << endl << endl;

    string courseDept, courseNum, courseName;
    int numStudents, pointsPossible;

    cout << "Enter the course dept: ";
    getline(cin, courseDept);
    cout << "Enter the course number: ";
    cin >> courseNum;
    cout << "Enter the course name: ";
    cin.ignore();
    getline(cin, courseName);
    cout << "Enter the number of students that will be scored: ";
    cin >> numStudents;
    cout << "Enter points possible: ";
    cin >> pointsPossible;

    int* arr = new int[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        cout << "\n\nEnter student " << i + 1 << "'s score: ";
        cin >> arr[i];
    }

    recursiveBubbleSort(arr, numStudents);

    double average = calculateAverage(arr, numStudents, pointsPossible);
    int lowestScore = findMinimum(arr, numStudents);
    int highestScore = findMaximum(arr, numStudents);

    cout << "\nCourse: " << courseDept << " " << courseNum << ": " << courseName << endl;
    cout << "Scores: ";
    for (int i = 0; i < numStudents; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\n\nAverage: " << fixed << setprecision(2) << average << "%"
        << "\nLowest Score: " << lowestScore
        << "\nHighest Score: " << highestScore << endl;

    cout << "\nThank you for using the grade calculator!" << endl;

    // Reminder to free the allocated memory
    delete[] arr;

    system("pause");
    return 6787;
}