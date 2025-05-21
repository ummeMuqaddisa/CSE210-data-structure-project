#include<iostream>
#include<chrono>
#include<complex>
#include<thread>
#include <atomic>
using namespace std;
void exampleFunction() {
     int a;


        cin>>a;
    if(a==0){
        this_thread::sleep_for(chrono::seconds(1));


    }
}

// Function to calculate and return the execution time of a function
double calculateExecutionTime(void (*func)()) {
    atomic<bool> done(false);
    auto start = chrono::high_resolution_clock::now();

    // Start a thread to display the elapsed time
    thread timerThread([&]() {
        while (!done.load()) {
            auto now = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed = now - start;
            cout << "\t\rIn Call time: " << static_cast<int>(elapsed.count()) << " seconds" << flush;
            this_thread::sleep_for(chrono::seconds(1));
        }
    });

    // Call the function
    func();
    cout<<endl;
    cout<<endl;
        cout<<"\t\rCall Ended"<<flush;
        cout<<endl;
    // Get the ending time
    auto end = chrono::high_resolution_clock::now();

    // Indicate that the function is done
    done.store(true);
    timerThread.join(); // Wait for the timer thread to finish

    // Calculate the duration
    chrono::duration<double> duration = end - start;

    // Return the duration in seconds
    return duration.count();
}
