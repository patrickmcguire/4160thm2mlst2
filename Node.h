#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

using namespace std;

class Node {

	std::vector<Node> * children;

public:
	Node();
	virtual void draw();
	virtual ~Node();
};
