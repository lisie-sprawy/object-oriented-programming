#include "Cargo.hpp"
#include "Observer.hpp"
#include "Player.hpp"

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store : public Observer {
private:
    std::shared_ptr<Time> time_{nullptr};

public:
    //Override from Observer
    void nextDay() override;

    Store(std::shared_ptr<Time>& time);
    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, Player* player);
};
