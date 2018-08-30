
public class GameSumulator {

	public static void main(String[] args) {
		Character kang = new King();
		kang.attack();
		kang.setWeapon(new AxeBehavior());
		kang.attack();
		kang.setWeapon(new BowAndArrowBehavior());
		kang.attack();
		kang.setWeapon(new KnifeBehavior());
		kang.attack();
		
	}

}
