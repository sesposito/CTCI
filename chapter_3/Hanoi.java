public class Hanoi {

  private static final int TOWER_1 = 0;
  private static final int TOWER_2 = 1;
  private static final int TOWER_3 = 2;

  private Stack[] towers; 
  private int nDisks;

  public Hanoi(int disks){

    this.nDisks = disks;
    Stack s1 = new Stack();
    Stack s2 = new Stack();
    Stack s3 = new Stack();
    towers = new Stack[nDisks];
    towers[TOWER_1] = s1;
    towers[TOWER_2] = s2; 
    towers[TOWER_3] = s3;

    for(int i = 0; i < nDisks; i++){
      towers[TOWER_1].push(nDisks - i);
    }

  }

  public void moveDisk(int t1, int t2){

    if(towers[t1].getSize() == 0){
      System.out.println("Invalid Move");
      return;
    }

    if(towers[t2].getSize() == 0 || towers[t2].peek() > towers[t1].peek()){
  
      int val = towers[t1].pop();
      towers[t2].push(val);

    }else{
      System.out.println("Invalid Move");      
    }
  }

  public boolean canMove(int t1, int t2){

    if(towers[t1].getSize() == 0){
      return false;
    }
    if(towers[t2].getSize() == 0 || towers[t2].peek() > towers[t1].peek()){
      return true;
    }else{
      return false;
    }

  }

  private boolean isSolved(){
  
    List stackList = this.towers[TOWER_3].getList();
    if(stackList.isEmpty()){
      return false;
    }
    Node current = stackList.tail;
    int i = 1;
    while(current != null){
      if(current.value == 3 && current.prev == null){
        return true;
      }
      if(current.value != i){
        return false;
      }
      i++;
      current = current.prev;
    }
    if(i == 3){
      return true;
    }else{
      return false;
    }
  }


  public void print(){

    towers[TOWER_1].print();
    towers[TOWER_2].print();
    towers[TOWER_3].print();

  }


  public static void main(String[] args){

    Hanoi hanoi = new Hanoi(3);
    hanoi.print();
    hanoi.solve();
    hanoi.print();    

  }

}
