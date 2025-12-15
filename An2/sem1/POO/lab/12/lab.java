//import java.util.List;
//import java.util.LinkedList;
//import java.util.Objects;
//import java.util.ArrayList;
import java.util.*;

interface Valoare{
    List<Valoare> contine(long x);
}

class ValoareNumerica implements Valoare{
    private long valoare;

    public ValoareNumerica(long valoare){
        this.valoare=valoare;
    }

    public List<Valoare> contine(long x){
        List<Valoare> lista=new LinkedList<>();
        if(valoare==x){
            lista.add(this);
        }
        return lista;
    }

    public String toString(){
        return String.valueOf(valoare);
    }

    public boolean equals(Object o){
        if(this==o) return true;
        if(!(o instanceof ValoareNumerica)) return false;
        ValoareNumerica that=(ValoareNumerica) o;
        return valoare==that.valoare;
    }

    public int hashCode(){
        return Objects.hash(valoare);
    }
}

class PerecheDeValori implements Valoare{
    private Valoare a,b;
    public PerecheDeValori(Valoare a, Valoare b){
        this.a=a;
        this.b=b;
    }

    public List<Valoare> contine(long x){
        List<Valoare> rezultat=new ArrayList<>();
        rezultat.addAll(a.contine(x));
        rezultat.addAll(b.contine(x));
        return rezultat;
    }

    public String toString(){
        return "("+a+", "+b+")";
    }

    public boolean equals(Object o){
        if(this==o) return true;
        if(!(o instanceof PerecheDeValori)) return false;
        PerecheDeValori that=(PerecheDeValori) o;
        return a.equals(that.a) && b.equals(that.b);
    }

    public int hashCode(){
        return Objects.hash(a,b);
    }
}

class Grup implements Valoare{
    private Set<Valoare> multime=new HashSet<>();

    public Grup(Valoare... valori){
        multime.addAll(Arrays.asList(valori));
    }

    public List<Valoare> contine(long x){
        List<Valoare> rezultat=new ArrayList<>();
        Iterator<Valoare> it=multime.iterator();

        while(it.hasNext()){
            rezultat.addAll(it.next().contine(x));
        }
        return rezultat;
    }

    public String toString(){
        StringBuilder sb=new StringBuilder("(");
        Iterator<Valoare> it=multime.iterator();

        while(it.hasNext()){
            sb.append(it.next());
            if(it.hasNext()) sb.append(", ");
        }
        sb.append(")");
        return sb.toString();
    }

    public boolean equals(Object o){
        if(this==o) return true;
        if(!(o instanceof Grup)) return false;
        Grup grup=(Grup) o;
        return multime.equals(grup.multime);
    }

    public int hashCode(){
        return multime.hashCode();
    }
}

class Main{
    public static void main(String[] args){
        Valoare v1=new ValoareNumerica(1);
        Valoare v2=new ValoareNumerica(2);
        Valoare v3=new ValoareNumerica(3);

        PerecheDeValori p1=new PerecheDeValori(v1,v2);
        PerecheDeValori p2=new PerecheDeValori(v3,v1);

        Grup grup=new Grup(p1,p2);
        System.out.println(grup);

        grup=new Grup(p1,p2,new PerecheDeValori(v1,v2));
        System.out.println(grup);

        List<Valoare> rezultat=grup.contine(3);
        for(int i=0; i<rezultat.size(); i++){
            Valoare v=rezultat.get(i);
            System.out.println(v+" | hashCode: "+v.hashCode()+" | identityHashCode: "+System.identityHashCode(v));
        }
    }
}

