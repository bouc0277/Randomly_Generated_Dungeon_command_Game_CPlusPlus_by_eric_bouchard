#include <iostream>
#include "player.h"
#include "functions.h"




PLAYER::PLAYER()
{
  p_Level = 1;
  p_Xp = 0;
  p_HpMax = 30;
  p_Hp = p_HpMax;
  p_Armour = 0;
  p_Attack = 1;
  p_EquipedWeapon = "";
  p_EquipedHeadArmour = "";
  p_EquipedChestArmour = "";
  p_EquipedLegArmour = "";
  p_EquipedRingArmour = "";
}

PLAYER::PLAYER(unsigned short Level,
	           unsigned int Xp,
		       int HpMax,
		       int Hp,
		       short Armour,
		       short Attack,
		       string EquipedWeapon,
	           string EquipedHeadArmour,
		       string EquipedChestArmour,
		       string EquipedLegArmour,
		       string EquipedRingArmour)
{
  p_Level = 1;
  p_Xp = 0;
  p_HpMax = 30;
  p_Hp = 30;
  p_Armour = 0;
  p_Attack = 1;
  p_EquipedWeapon = " ";
  p_EquipedHeadArmour = " ";
  p_EquipedChestArmour = " ";
  p_EquipedLegArmour = " ";
  p_EquipedRingArmour = " ";

  SetLevel(Level);
  SetXp(Xp);
  SetHpMax(HpMax);
  SetHp(Hp);
  SetArmour(Armour);
  SetAttack(Attack);
  SetEquipedWeapon(EquipedWeapon);
  SetEquipedHeadArmour(EquipedHeadArmour);
  SetEquipedHeadArmour(EquipedChestArmour);
  SetEquipedHeadArmour(EquipedLegArmour);
  SetEquipedHeadArmour(EquipedRingArmour);




  
}


 void PLAYER::SetLevel(unsigned short Level)
  {

	p_Level = Level;
  }

  unsigned short PLAYER::GetLevel()
  {

   return p_Level;
  }

  void PLAYER::SetXp(unsigned int Xp)
  {
   
   p_Xp = Xp;
  }

  unsigned int PLAYER::GetXp()
  {

   return p_Xp;
  }

  void PLAYER::SetHpMax(int HpMax)
  {

   p_HpMax = HpMax;
  }

  int PLAYER::GetHpMax()
  {
  
   return p_HpMax;
  }

  void PLAYER::SetHp(int Hp)
  {
   
   p_Hp = Hp;
  }

  int PLAYER::GetHp()
  {

	return p_Hp;
  }

  void PLAYER::SetArmour(short Armour)
  {
   
   p_Armour = Armour;
  }

  short PLAYER::GetArmour()
  {

	return p_Armour;
  }

  void PLAYER::SetAttack(short Attack)
  {

   p_Attack = Attack;
  }

  short PLAYER::GetAttack()
  {

   return p_Attack;
  }

  void PLAYER::SetEquipedWeapon(string EquipedWeapon)
  {

   p_EquipedWeapon = EquipedWeapon;
  }

  string PLAYER::GetEquipedWeapon()
  {

   return p_EquipedWeapon;
  }

  void PLAYER::SetEquipedHeadArmour(string EquipedHeadArmour)
  {

   p_EquipedHeadArmour = EquipedHeadArmour;
  }

  string PLAYER::GetEquipedHeadArmour()
  {

	return p_EquipedHeadArmour;
  }

  void PLAYER::SetEquipedChestArmour(string EquipedChestArmour)
  {

   p_EquipedChestArmour = EquipedChestArmour;
  }

  string PLAYER::GetEquipedChestArmour()
  {

	return p_EquipedChestArmour;
  }

    void PLAYER::SetEquipedLegArmour(string EquipedLegArmour)
  {

   p_EquipedLegArmour = EquipedLegArmour;
  }

  string PLAYER::GetEquipedLegArmour()
  {

	return p_EquipedLegArmour;
  }

    void PLAYER::SetEquipedRingArmour(string EquipedRingArmour)
  {

   p_EquipedRingArmour = EquipedRingArmour;
  }

  string PLAYER::GetEquipedRingArmour()
  {

	return p_EquipedRingArmour;
  }