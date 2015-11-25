#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.compare("-") == 0)
            break;
        double meal_cal = 0, meal_fat_cal = 0;
        do {
            if (line.compare("-") == 0)
                break;
            double fat_cal = 0;
            double fat_percent = 0;
            double total_percent = 100;
            double total_cal = 0;

            stringstream ss(line);
            int x;
            char c;
            // Fat
            ss >> x >> c;
            if (c == '%') {
                fat_percent += x;
                total_percent -= x;
            } else if (c == 'g') {
                fat_cal += 9 * x;
                total_cal += 9 * x;
            } else if (c == 'C') {
                fat_cal += x;
                total_cal += x;
            }
            // Protein
            ss >> x >> c;
            if (c == '%') {
                total_percent -= x;
            } else if (c == 'g') {
                total_cal += 4 * x;
            } else if (c == 'C') {
                total_cal += x;
            }
            // Sugar
            ss >> x >> c;
            if (c == '%') {
                total_percent -= x;
            } else if (c == 'g') {
                total_cal += 4 * x;
            } else if (c == 'C') {
                total_cal += x;
            }
            // Starch
            ss >> x >> c;
            if (c == '%') {
                total_percent -= x;
            } else if (c == 'g') {
                total_cal += 4 * x;
            } else if (c == 'C') {
                total_cal += x;
            }
            // Alcohol
            ss >> x >> c;
            if (c == '%') {
                total_percent -= x;
            } else if (c == 'g') {
                total_cal += 7 * x;
            } else if (c == 'C') {
                total_cal += x;
            }

            total_cal = 100.0 * total_cal / total_percent;
            fat_cal = fat_cal + fat_percent * total_cal / 100.0;
            meal_cal += total_cal;
            meal_fat_cal += fat_cal;
        } while (getline(cin, line));
        cout << (int)round(100.0 * meal_fat_cal / meal_cal) << "%\n";
    }
}
