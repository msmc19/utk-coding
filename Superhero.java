public class Superhero {
    private String name;
    private Power superPower;

    public Superhero(String heroName, Power heroPower) {
        name = heroName;
        //superPower = heroPower; //can't do this!
        
        superPower = new Power(heroPower.getName(), heroPower.getStrength());
    }

    public int getStrength() {
        return superPower.getStrength();
    }

    public void setStrength(int newStrength) {
        superPower.setStrength(newStrength);
    }


}