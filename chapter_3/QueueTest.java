public class QueueTest{

  public static void main(String[] args){

    Queue queue = new Queue();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.print();
    System.out.println("Dequeued: " + queue.dequeue());
    queue.print();
    System.out.println("Dequeued: " + queue.dequeue());
    queue.print();
    queue.enqueue(6);
    queue.print();
    System.out.println("Dequeued: " + queue.dequeue());
    queue.print();

  }

}
