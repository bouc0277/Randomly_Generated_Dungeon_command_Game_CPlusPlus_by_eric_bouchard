#ifndef _BATTLE_H
#define _BATTLE_H


class BATTLE
{
private:

	//data members
     unsigned short m_mLevel;
     unsigned short m_mHealth;
     unsigned short m_mAttack;
	 unsigned short m_mArmour;

public:

	//default constructor
	BATTLE();
    //overloaded constructor
	BATTLE(unsigned short Level,unsigned short Health,unsigned short Attack,unsigned short Armour);


	// functions/ methods

	unsigned short GetLevel();
	void SetLevel(unsigned short Level);

	unsigned short GetHealth();
	void SetHealth(unsigned short Health);

    unsigned short GetAttack();
	void SetAttack(unsigned short Attack);

	unsigned short GetArmour();
	void SetArmour(unsigned short Armour);

	void Fight(short Attack);

	void Fight2(short Attack,short Armour,short x,short y);

	bool ifDead();

};










#endif 