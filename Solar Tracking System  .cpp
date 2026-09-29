#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

class SolarTracker {
private:
    int leftLDR;
    int rightLDR;
    int panelAngle;

public:
    SolarTracker() {
        leftLDR = 0;
        rightLDR = 0;
        panelAngle = 90;   // Initial position
    }

    // Set LDR sensor values
    void setLDRValues(int left, int right) {
        leftLDR = left;
        rightLDR = right;
    }

    // Move the solar panel
    void trackSun() {

        int difference = leftLDR - rightLDR;

        cout << "\nLeft LDR  : " << leftLDR;
        cout << "\nRight LDR : " << rightLDR;
        cout << "\n";

        // Dead zone prevents unnecessary movement
        if (abs(difference) <= 20) {
            cout << "Sun Position : CENTERED\n";
            cout << "Panel Status : No movement required.\n";
        }

        else if (difference > 20) {

            panelAngle += 5;

            if (panelAngle > 180)
                panelAngle = 180;

            cout << "Sun Position : LEFT\n";
            cout << "Panel Action : Moving LEFT\n";
        }

        else {

            panelAngle -= 5;

            if (panelAngle < 0)
                panelAngle = 0;

            cout << "Sun Position : RIGHT\n";
            cout << "Panel Action : Moving RIGHT\n";
        }

        cout << "Panel Angle  : "
             << panelAngle << " degrees\n";
    }

    void displayStatus() {

        cout << "\n====================================\n";
        cout << "       SOLAR TRACKING SYSTEM\n";
        cout << "====================================\n";

        cout << "Panel Angle : "
             << panelAngle << " degrees\n";

        cout << "Left LDR    : "
             << leftLDR << "\n";

        cout << "Right LDR   : "
             << rightLDR << "\n";

        cout << "====================================\n";
    }
};

int main() {

    SolarTracker tracker;

    int left, right;
    char choice;

    cout << "====================================\n";
    cout << "       SOLAR TRACKING SYSTEM\n";
    cout << "====================================\n";

    do {

        cout << "\nEnter Left LDR value (0-1000): ";
        cin >> left;

        cout << "Enter Right LDR value (0-1000): ";
        cin >> right;

        if (left < 0 || left > 1000 ||
            right < 0 || right > 1000) {

            cout << "Invalid LDR value!\n";
            continue;
        }

        tracker.setLDRValues(left, right);

        tracker.trackSun();

        cout << "\nDo you want another reading? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    tracker.displayStatus();

    cout << "\nSolar tracking simulation completed.\n";

    return 0;
}
