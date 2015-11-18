public class Queue{
  
  List queue;

  public Queue(){
    this.queue = new List();
  }

  public void enqueue(int n){
    this.queue.appendInt(n);
  }

  public int dequeue(){
    int value;
    value = this.queue.head.value;
    this.queue.removeNode(this.queue.head);
    return value;
  }

  public boolean isEmpty(){
    return this.queue.isEmpty();
  }

  public void print(){
    this.queue.print();
  }

  public int getSize(){
    return this.queue.size;
  }

}
