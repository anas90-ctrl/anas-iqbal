#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

enum LightState { RED, GREEN, YELLOW };  // Enum for traffic light states

class TrafficLight {
public:
    LightState state;  // Current state of the light

    TrafficLight() : state(RED) {}  // Initially set to RED

    void changeState() {
        // Simple logic to cycle through states: RED -> GREEN -> YELLOW -> RED
        if (state == RED)
            state = GREEN;
        else if (state == GREEN)
            state = YELLOW;
        else
            state = RED;
    }

    void display() {
        switch (state) {
            case RED:    cout << "Red Light" << endl; break;
            case GREEN:  cout << "Green Light" << endl; break;
            case YELLOW: cout << "Yellow Light" << endl; break;
        }
    }
};

int main() {
    TrafficLight light;  // Create a traffic light

    while (true) {
        light.display();  // Show the current light state

        // Wait for a few seconds before changing the state
        if (light.state == RED) {
            this_thread::sleep_for(chrono::seconds(5));  // Red for 5 seconds
        } else if (light.state == GREEN) {
            this_thread::sleep_for(chrono::seconds(7));  // Green for 7 seconds
        } else {
            this_thread::sleep_for(chrono::seconds(3));  // Yellow for 3 seconds
        }

        light.changeState();  // Change the state of the light
    }

    return 0;
}
