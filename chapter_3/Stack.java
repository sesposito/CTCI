public class Stack {

  private List stack;
  
  public Stack(){
    this.stack = new List();
  }

  public int getSize(){
    return stack.size;
  }

  public void push(int value){
    this.stack.appendInt(value);
  }

  public int pop(){
    int value;
    value = this.stack.tail.value;
    this.stack.removeNode(this.stack.tail);
    return value;
  }

  public void print(){
    this.stack.print();
  }

  public int peek(){
    return this.stack.tail.value;
  }

  public boolean isEmpty(){
    return this.stack.isEmpty();
  }

  public List getList(){
    return this.stack;
  }

}
