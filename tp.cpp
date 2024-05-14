#include <iostream>
#include <thread>

// Function to be executed by the thread
void printMessage() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    // Create a thread that runs the printMessage function
    std::thread myThread(printMessage);

    // Wait for the thread to finish
    myThread.detach();

    std::cout << "Hello from main!" << std::endl;
    return 0;
}
