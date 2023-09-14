/**
 * Lineked_List_Operations
 */


public class Lineked_List_Operations {
    
    Node head ;

    class Node {
        Integer data ;
        Node next ;
    
        Node (Integer data) {
            this.data = data ;
            next = null ;
        }
    }

    class ll {
        public void addFirst (Integer data) {
            Node newNode = new Node(data) ;
            if (head == null) head = newNode ; 
        }
    }
  

    public static void main(String[] args) {
        
    }
}