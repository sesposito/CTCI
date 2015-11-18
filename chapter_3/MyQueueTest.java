public class MyQueueTest {

  public static void main(String[] args){

    MyQueue queue = new MyQueue();

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    System.out.println(queue.dequeue());
    System.out.println(queue.dequeue());
    queue.enqueue(7);
    queue.enqueue(8);
    System.out.println(queue.dequeue());
    System.out.println(queue.dequeue());
    System.out.println(queue.dequeue());
    System.out.println(queue.dequeue());
    System.out.println(queue.dequeue());
    System.out.println(queue.dequeue());
    queue.enqueue(9);
    System.out.println(queue.dequeue());

  }

}
