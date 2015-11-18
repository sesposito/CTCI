public class List {

    public Node head;
    public Node tail;
    public int size;

    public List(){

      this.size = 0;
      this.tail = null;
      this.head = null;

    }

    public void appendInt(int val){
        
      if(size == 0){
        Node n = new Node();
        n.next = null;
        n.prev = null;
        n.value = val;
        this.head = n;
        this.tail = n;
        this.size++;
        return;
      }

      if(size >= 1){
        Node n = new Node();
        n.value = val;
        n.next = null;
        n.prev = this.tail;
        this.tail.next = n;
        this.tail = n;
        this.size++;
        return;
      }
  
    }

    public void print(){
      
      Node current = this.head;
      String listString = "";

      while(current != null){
        if(current.next == null){
          listString += "["+current.value+"]";
        }else{
          listString += "["+current.value+"]->";
        }
        current = current.next;
      }
      System.out.println(listString);
    }

    public void removeNode(Node n){

      if(this.isEmpty()){
        System.out.println("List is empty.");
        return;
      }

      if(this.head == n && this.size == 1){
        this.head = null;
        this.tail = null;
        this.size--;
        return;
      }

      if(this.head == n){
        this.head = this.head.next;
        this.head.prev = null;
        this.size--;
        return;
      }

      if(this.tail == n){
        this.tail = this.tail.prev;
        this.tail.next = null;
        this.size--;
        return;
      }

      Node current = this.head;
      while(current != null){
        if(current == n){
          current.prev.next = current.next;
          current.next.prev = current.prev;
          this.size--;
          return;
        }
        current = current.next;
      }

      System.out.println("Element not found in list");

    }

    public boolean isEmpty(){

      if(size == 0){
        return true;
      }

      return false;
    }

}
