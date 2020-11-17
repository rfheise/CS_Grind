
class Hash<T>{
    private Node<T>[] nodes;
    private int size;

    public static void main(String[] args) {
        Hash<Integer> epicness = new Hash<Integer>(10000);
        int x = 1000000;
        for (int i = 0; i < x; i++) {
            epicness.add(i);
        }
        // cout << "not noice" << endl;
        for (int i = 0; i < x; i++) {
            epicness.check(i);
            // cout << "fin" << endl;
        }
        for (int i = 0,l = x/2; i < l; i++) {
            epicness.remove(i);
        }
        System.out.println("Done");
    }

    public Hash(int len){
        nodes = new Node[len];
        size = 0;
    }

    public void add(T o){
        int hash = o.hashCode();
        if (hash < 0) {
            hash *= -1;
        }
        hash %= nodes.length;
        nodes[hash] = new Node(o, nodes[hash]);
        size++;

    }
    public boolean check(T o) {
        int hash = o.hashCode();
        if (hash < 0) {
            hash *= -1;
        }
        hash %= nodes.length;
        Node<T> temp = nodes[hash];
        while(temp != null) {
            if (temp.equals(o)) {
                return true;
            }
            temp = temp.getNext();
        }
        return false;
    }
    public int getSize(){
        return size;
    }
    public void remove(T o) {
        int hash = o.hashCode();
        if (hash < 0) {
            hash *= -1;
        }
        hash %= nodes.length;
        if (nodes[hash] == null) {
            return;
        }
        if (nodes[hash].equals(o)) {
            nodes[hash] = nodes[hash].getNext();
            size --;
            return;
        }
        Node<T> temp = nodes[hash];
        while (temp.getNext() != null) {
            if (temp.getNext().equals(o)) {
                temp.setNext(temp.getNext().getNext());
                size --;
                return;
            }
            temp = temp.getNext();
        }
    }


    public Hash() {
        this(1000000);
    }


}
