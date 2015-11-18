public class StackTest {

  public static void main(String[] args){

    Stack stack = new Stack();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.print();
    stack.pop();
    stack.print();
    stack.push(5);
    stack.print();
    stack.pop();
    System.out.println(stack.peek());
     
  }

}
