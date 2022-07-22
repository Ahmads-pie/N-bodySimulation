class Particle{
    public:
    double x, y;
    int b;
    std::pair<double, double> force = std::make_pair(0, 0);

    void addForce(double i_comp, double j_comp, bool negative = false);
    Particle(double _x = 0, double _y = 0, double i_comp = 0, double j_comp = 0){
        x = _x;
        y = _y;
        force.first = i_comp;
        force.second = j_comp;
    }
    void updateColor();
};

void Particle::addForce(double i_comp, double j_comp, bool negative){
    if (negative){
        force.first -= i_comp;
        force.second -= j_comp;
    }
    else{
        force.first += i_comp;
        force.second += j_comp;
    }
    x += force.first;
    y += force.second;
}

void Particle::updateColor(){
    b = 255-(abs(force.first*100000)+abs(force.second*100000));
    if (b < 54)
        b = 54;
}