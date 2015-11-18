public class ListTest {

  public static void main(String[] args){
   
    List list = new List();
    list.appendInt(1);
    list.appendInt(2);
    list.appendInt(3);
    list.appendInt(4);
    list.appendInt(5);
    list.print();
    list.removeNode(list.head);
    list.print();
    list.removeNode(list.tail);
    list.print();
  }

}
