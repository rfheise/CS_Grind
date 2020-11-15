
class Node<T>{
    private Node next;
    private T obj;

    public Node(T obj, Node next){
        this.obj = obj;
        this.next = next;
    }
    public Node(T obj) {
        this(obj, null);
    }
    public Node getNext() {
        return next;
    }
    public void setNext(Node next) {
        this.next = next;
    }
    @Override
    public boolean equals(Object o) {
        if(this == o) {
            return true;
        }
        if (o instanceof Node){
            Node other = (Node)o;
            return other.obj.equals(obj);
        }
        return obj.equals(o);
    }



}
