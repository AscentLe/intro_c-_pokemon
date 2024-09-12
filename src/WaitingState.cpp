#include "WaitingState.hpp"
#include "StateExplorationSansDanger.hpp"
#include "Context.hpp"
void WaitingState::handle(){
    std::string userInput;
    while (true) {
        std::cout << "You are in the Waiting State. Type 'play' or 'go' to continue: ";
        std::cin >> userInput;
        for (auto &c : userInput) c = tolower(c);
        if (userInput == "play" || userInput == "go") {
            std::cout << "Transitioning to Exploration State." << std::endl;
            this->context_->TransitionTo(new StateExplorationSansDanger());
            break;
        } else {
            std::cout << "Invalid input. Please type 'play' or 'go'." << std::endl;
        }
    }
}

std::string WaitingState::getName() const{
    return "WaitingState";
}
