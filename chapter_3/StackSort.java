public class StackSort {

  public static Stack sort(Stack s){
    
    Stack stack = s;
    Stack sortedStack = new Stack();

    while(!stack.isEmpty()){
      int n = stack.pop();
      if(sortedStack.isEmpty() || sortedStack.peek() <= n){
        sortedStack.push(n);
      }else{
        while(!sortedStack.isEmpty() && sortedStack.peek() > n){
          stack.push(sortedStack.pop());
        }
        sortedStack.push(n);
      }
    }
    return sortedStack;
  }

  public static void main(String[] args){

    Stack s = new Stack();
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(1);
    s.push(4);
    s.print();
    s = StackSort.sort(s);
    s.print();

  }
}
