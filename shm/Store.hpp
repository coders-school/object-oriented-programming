#pragma onec

class Store {
public:
    enum class Response {
        done,
        lack_of_money,
        lack_of_cargo,
        lack_of_space
    };

    Response Buy(Cargo* cargo, size_t amount, Player* player);

private:
};
