#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


// 100
// 50
// 30
int main()
{

	FragTrap fr_bot("fr4p-Tp");
	fr_bot.putStatus();
	fr_bot.attack(fr_bot.getName()); // 자기 자신 때리기!
	fr_bot.takeDamage(fr_bot.getAttackDamage());
	fr_bot.putStatus();

	ScavTrap sc_bot("sc4o-Tp");
	sc_bot.attack(fr_bot.getName());
	fr_bot.takeDamage(sc_bot.getAttackDamage());
	sc_bot.putStatus();
	fr_bot.putStatus();
	
	DiamondTrap dm_bot("dm4g-Tp");
	dm_bot.attack(sc_bot.getName());
	sc_bot.takeDamage(dm_bot.getAttackDamage());
	dm_bot.putStatus();
	sc_bot.putStatus();
	sc_bot.attack(dm_bot.getName());
	dm_bot.takeDamage(sc_bot.getAttackDamage());
	dm_bot.putStatus();
	sc_bot.putStatus();
	dm_bot.beRepaired(2);
	dm_bot.putStatus();
	dm_bot.whoAmI();

	// // DiamondTrap dm_bot_2(dm_bot);
	// DiamondTrap dm_bot_2 = dm_bot;
	// dm_bot_2.putStatus();
	// // DiamondTrap dm_bot_3(dm_bot_2);
	// DiamondTrap dm_bot_3 = dm_bot_2;
	// dm_bot_3.putStatus();
	// // DiamondTrap dm_bot_4("fr4p-Tp");
	// // dm_bot_4.putStatus();
}