public class MultiStackTest {
  public static void main(String[] args){
    
    MultiStack mStack = new MultiStack();

    mStack.push(1);
    mStack.push(2);
    mStack.push(3);
    mStack.push(4);
    mStack.push(5);
    mStack.push(6);
    mStack.push(7);
    mStack.push(8);
    mStack.print();
    mStack.pop();
    mStack.pop();
    mStack.print();
    mStack.pop();
    mStack.print();
    mStack.pop();
    mStack.print();

  }
}
