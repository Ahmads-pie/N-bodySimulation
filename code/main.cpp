#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Particle.cpp"
#include "physics.cpp"

const int WIDTH = 1280;
const int HEIGHT = 720;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "N-Body Simulation");

    std::vector<std::pair<Particle, sf::CircleShape>> particles;
    for (int i = WIDTH/2-200; i < WIDTH/2+201; i += 50){
        for(int j = HEIGHT/2-200; j < HEIGHT/2 +201; j += 50){
            Particle particle(i, j, 0, 0.0000001);
            sf::CircleShape circle(5.f);
            circle.setFillColor(sf::Color::White);
            circle.setPosition(particle.x, particle.y);
            particles.push_back(std::make_pair(particle, circle));
        }
    }
    std::pair<double, double> force;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (int i=0; i < particles.size()-1; i++){
            for(int j=i+1; j < particles.size(); j++){
                if(i != j){
                    force = gravitationalForce(particles[j].first.x - particles[i].first.x,
                                                    particles[j].first.y - particles[i].first.y);
                    particles[i].first.addForce(force.first, force.second);
                    particles[j].first.addForce(force.first, force.second, true);
                }

            }
        }
        for (int i=0; i<particles.size(); i++){
            particles[i].first.updateColor();
            particles[i].second.setPosition(particles[i].first.x, particles[i].first.y);
            particles[i].second.setFillColor(sf::Color(255, 255, particles[i].first.b));
            
            window.draw(particles[i].second);
        }
        window.display();
        window.clear();
    }

    return 0;
}