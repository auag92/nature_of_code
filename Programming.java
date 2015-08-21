//Constructor example
class Programming {

  //Constructor method
  Programming(){
    int a,b;
    a = 1;
    b = 10;
    System.out.println("Thsi is a constructor method");
  }

  public static void main(String args[]){
    //Creating object
    Programming object = new Programming();
    System.out.println(object.a);
  }
}
