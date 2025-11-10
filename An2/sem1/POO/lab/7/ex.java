// class Caine extends Animal - Caine devine o subclasa a lui Animal si are acces la totul din Animal, daca variabilele sunt de tip protected

// super () - apeleaza constructor din clasa superioara

// variabilele le putem apela this.nume, nume sau super.nume daca numele este un String din clasa superioara

// private Animal[] animal;
// Animal[0] = new Caine();
// Animal[1] = new Pisica();
// ^ daca fac asa pot apela doar functiile din superclasa, nu si pe cele din subclasa
// dar pot face ((Caine)c).latra(); iar atunci merge sa rulez si functiile din subclasa


class Avion
{
    public Avion(String planeID, int totalEnginePower)
    {
        this.planeID = planeID;
        this.totalEnginePower = totalEnginePower;
    }
    protected String planeID;
    public String getPlaneID()
    {
        return planeID;
    }

    protected int totalEnginePower;
    public int getTotalEnginePower()
    {
        return totalEnginePower;
    }

    public void takeOff()
    {
        System.out.println("Plane" + planeID + "- Initiating takeoff procedure - Starting engines - Accelerating down the runway - Taking off - Retracting gear - Takeoff complete");
    }

    public void fly()
    {
        System.out.println("Plane" + planeID + " - Flying");
    }

    public void land()
    {
        System.out.println("Plane" + planeID + "- Initiating landing procedure - Enabling airbrakes - Lowering gear - Contacting runway - Decelerating - Stopping engines - Landing complete");
    }
}

class Avion_Calatori extends Avion
{
    public Avion_Calatori(String planeID, int maxEnginePower, int maxPassengers)
    {
        super(planeID, maxEnginePower);
        this.maxPassengers = maxPassengers;
    }
    protected int maxPassengers;
    public int getMaxPassengers()
    {
        return maxPassengers;
    }
}

class Avion_Lupta extends Avion
{
    public void launchMissile()
    {
        System.out.println("Plane" + planeID + "- Initiating missile launch procedure - Acquiring target - Launching missile - Breaking away - Missile launch complete");
    }
    public Avion_Lupta(String planeID, int maxEnginePower)
    {
        super(planeID, maxEnginePower);
    }
}

class Boeing extends Avion_Calatori
{
    public Boeing(String planeID, int totalEnginePower, int maxPassengers)
    {
        super(planeID, totalEnginePower, maxPassengers);
    }
}

class Concorde extends Avion_Calatori
{
    public Concorde(String planeID, int totalEnginePower, int maxPassengers)
    {
        super(planeID, totalEnginePower, maxPassengers);
    }
    public void goSuperSonic()
    {
        System.out.println("Plane" + planeID + " - Supersonic mode activated");
    }

    public void goSubSonic()
    {
        System.out.println("Plane" + planeID + " - Supersonic mode deactivated");
    }
}

class Mig extends Avion_Lupta
{
    public Mig(String planeID, int totalEnginePower)
    {
        super(planeID, totalEnginePower);
    }
    public void highSpeedGeometry()
    {
        System.out.println("Plane" + planeID + "- High speed geometry selected");
    }

    public void normalSpeedGeometry()
    {
        System.out.println("Plane" + planeID + "- Normal speed geometry selected");
    }
}

class TomCat extends Avion_Lupta
{
    public TomCat(String planeID, int totalEnginePower)
    {
        super(planeID, totalEnginePower);
    }
    public void refuel()
    {
        System.out.println("Plane" + planeID + "  Initiating refueling procedure - Locating refueller - Catching up - Refueling - Refueling complete");
    }
}

class Main
{
    public static void main(String[] argv)
    {
        Avion a1 = new Boeing("Boeing1", 1200, 300);
        a1.takeOff();
        System.out.println();
        a1.land();
        System.out.println();

        Avion a2 = new Mig("Mig1", 1600);
        ((Mig)a2).launchMissile();
        System.out.println();
        ((Mig)a2).normalSpeedGeometry();
        System.out.println();

        System.out.println(((Boeing)a1).getMaxPassengers());
        System.out.println();

        Avion a3 = new Concorde("Concorde1", 2500, 450);
        ((Concorde)a3).goSuperSonic();


    }
}
