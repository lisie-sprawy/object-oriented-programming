#include "Store.hpp"
#include <algorithm>
#include <iostream>

Response Store::buy(std::shared_ptr<Cargo> cargo, size_t amount, Player* player) {
    const size_t price = amount * cargo->getBasePrice();
    if (cargo -> getAmount() < amount){
        return Response::lack_of_cargo;
    }
    else if (player -> getMoney() < price){
        return Response::lack_of_money;
    }
    else if (player -> getAvailableSpace() < amount){
        return Response::lack_of_space;
    }
    *cargo += amount;
    player->buyCargo(cargo, amount, price);
    return Response::done;
}

Response Store::sell(std::shared_ptr<Cargo> cargo, size_t amount, Player* player) {
    const size_t price = amount * cargo->getPrice();
    *cargo -= amount; 
    player->sellCargo(cargo, amount, price);
    return Response::done;
}

void Store::nextDay() {
    //Doing nothing for now. Interface purposes
}

Store::Store(std::shared_ptr<Time> &time)
    : time_(time)
{
    time_->addObserver(this);
}
