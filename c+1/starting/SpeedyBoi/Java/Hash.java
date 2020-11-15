
class Hash<T>{
    private Node<T>[] nodes;
    private int size;

    public static void main(String[] args) {
        Hash<Integer> x = new Hash<Integer>(1000000);
        for(int i = 0; i < 1000000; i++) {
            x.add(i);
        }
        for (int i = 0; i < 1000000; i ++) {
            x.check((Integer)i);
        }
        for(int i = 0; i < 1000000; i++){
            x.remove((Integer)i);
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
