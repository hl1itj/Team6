/*
 * Lope.h
 *
 *  Created on: 2010. 11. 20.
 *      Author: ������, �ڰ�ȣ, �ŵ���
 */

#ifndef LOPE_H_
#define LOPE_H_

#include "Character.h"

class Lope {
public:
	int x,y;
	int isShot;
	int isSelected;
public:
	Lope();
	virtual ~Lope();
	void change();
	void move(int ch_x, int ch_y);
};

#endif /* LOPE_H_ */
