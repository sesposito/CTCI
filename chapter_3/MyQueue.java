public class MyQueue {

  private Stack arrivals;
  private Stack departures;

  public MyQueue() {

    this.arrivals = new Stack();
    this.departures = new Stack();

  }

  public void enqueue(int n){

    arrivals.push(n);

  }

  public int dequeue() {
  
    if(!departures.isEmpty()){
      
      return departures.pop();

    }else{
  
      while(!arrivals.isEmpty()){

        departures.push(arrivals.pop());

      }
      return departures.pop();
    }
  }
}
