const double GRAVITATIONAL_CONSTANT = 6.6743;

//pixels are intended to be 1 micro meter so distance cancels with mass of particles

std::pair<double, double> gravitationalForce(double dx, double dy){
    double gForce;
    if (!(dx < 10 && dx > -10 && dy < 10 && dy > -10))
        gForce = GRAVITATIONAL_CONSTANT / ((pow(dx, 2) + pow(dy, 2)) * pow(10, 5));
    else{
        gForce = GRAVITATIONAL_CONSTANT / ((pow(10, 2) + pow(10, 2)) * pow(10, 5));
    }
    double theta = atan2(dy, dx);
    std::pair<double, double> force;
    force.first = cos(theta) * gForce;
    force.second = sin(theta) * gForce;
    return force;
}