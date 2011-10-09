#include <vector>

using namespace std;

class Node {
	std::vector<Node> * children;

public:
	Node();
	~Node();
};
