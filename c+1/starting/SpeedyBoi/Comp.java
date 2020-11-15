import java.util.HashSet;

class Comp{

    public static void main(String[] args) {
        HashSet<Integer> hash = new HashSet<Integer>();
        for (int i = 0; i < 1000000; i ++) {
            hash.add(i);
        }
        for (int i = 0; i < 1000000; i++) {
            hash.contains((Integer)i);
        }
        for (int i = 0; i< 1000000; i++) {
            hash.remove((Integer) i);
        }
        System.out.println("Done");
    }


}
