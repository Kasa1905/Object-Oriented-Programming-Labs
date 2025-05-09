#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, long> statePopulation;

    statePopulation["Maharashtra"] = 39538223;
    statePopulation["Uttar Pradesh"] = 29145505;
    statePopulation["Karnataka"] = 21538187;
    statePopulation["Madhya Pradesh"] = 20201249;
    statePopulation["Goa"] = 12812508;

    // Prompt the user to enter the name of a state
    std::string state;
    std::cout << "Enter the name of a state: ";
    std::getline(std::cin, state);

    // Look up the state in the map and return the population if found
    if (statePopulation.count(state) > 0) {
        std::cout << "The population of " << state << " is " << statePopulation[state] << "." << std::endl;
    } else {
        std::cout << "State not found." << std::endl;
    }

    return 0;
}
