/*
 * Floor.h
 *
 *  Created on: Oct 10, 2011
 *      Author: pjm2119
 */

#ifndef FLOOR_H_
#define FLOOR_H_

#include <vector>
#include "Node.h"

class Floor : public Node {

public:
	Floor();
	virtual void draw();
	virtual ~Floor();
};

#endif /* FLOOR_H_ */
