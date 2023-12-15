/*

        Name            Cameron Wolf
        Assignment      Assignment 3
        Date            12/11/23
        Course          CMPS 367

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

class Course
{
public:
    string course_code, course_title;
    int max_cap, current_cap;
};

void add_class(vector<Course>& classes);
void edit_class(Course& class_to_edit);
void display_classes(const vector<Course>& classes);
void register_class(vector<Course>& classes);
void drop_class(vector<Course>& classes);

void add_class(vector<Course>& classes)
{
    Course new_class;

    cout << "Enter CRN Number: ";
    cin >> new_class.course_code;

    cout << "Enter course title: ";
    cin.ignore();
    getline(cin, new_class.course_title);

    cout << "Enter max capacity: ";
    cin >> new_class.max_cap;

    // Initialize current capacity to 0
    new_class.current_cap = 0;

    // Add the new class to the vector
    classes.push_back(new_class);

    cout << "Class added successfully.\n";
}

void edit_class(Course& class_to_edit)
{
    cout << "Editing Class - " << class_to_edit.course_code << "\n";

    cout << "Enter new course title: ";
    cin.ignore();
    getline(cin, class_to_edit.course_title);

    cout << "Enter new max capacity: ";
    cin >> class_to_edit.max_cap;

    // Add any other fields you want to edit

    cout << "Class edited successfully.\n";
}

void display_classes(const vector<Course>& classes)
{
    cout << "Available Classes:\n";
    cout << setw(15) << "Course Code" << setw(20) << "Course Title" << setw(15) << "Capacity" << setw(20) << "Remaining Capacity" << "\n";

    for (const auto& cls : classes)
    {
        cout << setw(15) << cls.course_code << setw(20) << cls.course_title << setw(15) << cls.max_cap << setw(20) << (cls.max_cap - cls.current_cap) << "\n";
    }
}

void register_class(vector<Course>& classes)
{
    display_classes(classes);

    string code;
    cout << "Enter the course code you want to register for: ";
    cin >> code;

    // Find the class with the entered course code
    auto it = find_if(classes.begin(), classes.end(), [code](const Course& cls) { return cls.course_code == code; });

    if (it != classes.end() && it->current_cap < it->max_cap)
    {
        cout << "Enter student details:\n"; // Add more fields as needed
        it->current_cap++;
        cout << "Registration successful!\n";
    }
    else
    {
        cout << "Invalid course code or no available capacity for the selected class.\n";
    }
}

void drop_class(vector<Course>& classes)
{
    string code;
    cout << "Enter the course code you want to drop: ";
    cin >> code;

    // Find the class with the entered course code
    auto it = find_if(classes.begin(), classes.end(), [code](const Course& cls) { return cls.course_code == code; });

    if (it != classes.end() && it->current_cap > 0)
    {
        // Drop the class
        it->current_cap--;
        cout << "Class dropped successfully!\n";
    }
    else
    {
        cout << "Invalid course code or you are not currently registered for the selected class.\n";
    }
}

int main()
{
    vector<Course> classes;

    while (true)
    {
        cout << "***************************Welcome to ULV**************************\n"
            << "Choose one of the following options:\n"
            << "(1) Add a Class\n"
            << "(2) Edit a Class\n"
            << "(3) Register a Class\n"
            << "(4) Drop a Class\n"
            << "Enter the option: ";

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            add_class(classes);
            break;

        case 2:
            if (!classes.empty())
            {
                string code;
                cout << "Enter the course code you want to edit: ";
                cin >> code;

                auto it = find_if(classes.begin(), classes.end(), [code](const Course& cls) { return cls.course_code == code; });

                if (it != classes.end())
                {
                    edit_class(*it);
                }
                else
                {
                    cout << "Invalid course code.\n";
                }
            }
            else
            {
                cout << "No classes available to edit.\n";
            }
            break;

        case 3:
            register_class(classes);
            break;

        case 4:
            drop_class(classes);
            break;

        default:
            cout << "Invalid option. Exiting.\n";
            return 6787;
        }
    }
}
