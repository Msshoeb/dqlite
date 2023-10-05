#include <iostream>
#include <csignal>

// Global flag to indicate if the interrupt signal was received
volatile bool interruptFlag = false;

// Signal handler function
void interruptHandler(int signum) {
    std::cout << "Interrupt signal (" << signum << ") received." << std::endl;
    interruptFlag = true;
}

int main() {
    // Register the signal handler for SIGINT
    signal(SIGINT, interruptHandler);

    std::cout << "Press Ctrl+C to send a SIGINT signal..." << std::endl;

    while (!interruptFlag) {
        // Your main program logic here
    }

    std::cout << "Exiting the program." << std::endl;

    return 0;
}
