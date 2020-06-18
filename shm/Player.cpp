#include "Player.hpp"

#include <numeric>

size_t countAvailableSpace() {
    auto occupiedSpace = std::accumulate(begin(ship_->getAllCargos()), end(ship_->getAllCargos()), 0, [](const auto& cargo) {
        cargo.getAmount();
    });
    if (ship_->getCapacity() <= occupiedSpace) {
        return 0;
    }
    return ship_->getCapacity() - occupiedSpace;
}
