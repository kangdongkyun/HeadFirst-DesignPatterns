
public abstract class Character {
	WeaponBehavior weapon;
	
	public abstract void fight();
	public void attack() {
		weapon.useWeapon();
	}
	public void setWeapon(WeaponBehavior weapon) {
		this.weapon = weapon;
	}
}
