#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>

using namespace std;

class PLAYER
{
 private:
  //private data members
  unsigned short p_Level;
  unsigned int p_Xp;
  int p_HpMax;
  int p_Hp;
  short p_Armour;
  short p_Attack;
  string p_EquipedWeapon;
  string p_EquipedHeadArmour;
  string p_EquipedChestArmour;
  string p_EquipedLegArmour;
  string p_EquipedRingArmour;

 public:
  //public methods.
  PLAYER();

  PLAYER(unsigned short Level,
	     unsigned int Xp,
		 int HpMax,
		 int Hp,
		 short Armour,
		 short Attack,
		 string EquipedWeapon,
		 string EquipedHeadArmour,
		 string EquipedChestArmour,
		 string EquipedLegArmour,
		 string EquipedRingArmour);

  void SetLevel(unsigned short Level);
  unsigned short GetLevel();

  void SetXp(unsigned int Xp);
  unsigned int GetXp();

  void SetHpMax(int HpMax);
  int GetHpMax();

  void SetHp(int Hp);
  int GetHp();

  void SetArmour(short Armour);
  short GetArmour();

  void SetAttack(short Attack);
  short GetAttack();

  void SetEquipedWeapon(string EquipedWeapon);
  string GetEquipedWeapon();

  void SetEquipedHeadArmour(string EquipedHeadArmour);
  string GetEquipedHeadArmour();

  void SetEquipedChestArmour(string EquipedChestArmour);
  string GetEquipedChestArmour();

  void SetEquipedLegArmour(string EquipedLegArmour);
  string GetEquipedLegArmour();

  void SetEquipedRingArmour(string EquipedRingArmour);
  string GetEquipedRingArmour();
};








#endif 