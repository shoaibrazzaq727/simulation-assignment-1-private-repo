#include <iostream>
using namespace std;

int main() {
    // Input and parameter specification
    const double I_yy = 3800; // moment of intertie in y axis (kgm^2)
    const double T_y = 0.3; // torque applied to helicopter (kgm/s^2)
    
    // Initial state specification
    double theta = 0; // initial yaw (rad)
    double theta_dot = 0; // initial yaw rate (rad/s)
    
    // Simulation parameters
    const double step_size = 0.01; // 10ms step size
    const int num_steps = 1000; // simulate for 10 seconds
    const int log_interval = 100; // log every 1 second
    
    // Simulation loop
    for (int i = 0; i < num_steps; i++) {
        // Compute torque at current time
        double T_y_t = T_y * (i * step_size);
        
        // Compute acceleration and update state using Euler integration
        double theta_ddot = T_y_t / I_yy;
        theta_dot += theta_ddot * step_size;
        theta += theta_dot * step_size;
        
        // Log output at specified interval
        if (i % log_interval == 0) {
            cout << "Time: " << i * step_size << " s, Yaw: " << theta << " rad" << endl;
        }
    }
    
    return 0;
}

