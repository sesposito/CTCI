import java.util.ArrayList;


public class MultiStack {

  private static final int MAX_SIZE = 3;
  private ArrayList<Stack> stacks;
  private int nStacks;
  private Stack currentStack;

  public MultiStack() {

    this.nStacks = 0;
    stacks = new ArrayList<Stack>();
    stacks.add(new Stack());
    currentStack = stacks.get(nStacks);

  }

  public void push(int n){

    if(currentStack.getSize() == MultiStack.MAX_SIZE){

      nStacks++;
      stacks.add(new Stack());
      currentStack = stacks.get(nStacks);
      currentStack.push(n);
      return;
    
    }

    currentStack.push(n);

  }

  public int pop(){

    if(currentStack.getSize() == 0){
  
      nStacks--;
      currentStack = stacks.get(nStacks);
      return currentStack.pop();

    }

    return currentStack.pop();

  }

  public void print(){
    System.out.println("nStacks: " + (nStacks+1)); 
    for(Stack s : stacks){
      s.print();
    }
    
  }


}
