#include <vector>
#include <memory>

class Store {
public:
friend std::ostream& operator<<(std::ostream& oper, const Store& store);


private:
std::vector<std::shared_ptr<Cargo>>cargo_;

};