/*
 * Character.h
 *
 *  Created on: 2010. 11. 20.
 *      Author: ������, �ڰ�ȣ, �ŵ���
 */


#ifndef CHARACTER_H_
#define CHARACTER_H_


class Character {
public:
	int x, y;	// �ɸ����� ��ġ ��ǥ.
	int isShild;  // ���尡 �ֳ�?

public:
	Character();
	virtual ~Character();
	void move();
};

#endif /* CHARACTER_H_ */
