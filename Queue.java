package Data_Structures;
import java.util.*;
public class Queue
{
    int a[];
    int front,rear;
    Queue(int n)
    {
        a=new int[n];
        front=0;
        rear=-1;
    }
    void enqueue(int n)
    {
        if(rear==a.length-1)
            System.out.println("Overflow");
        else
        {
            rear++;
            a[rear]=n;
        }
    }
    int dequeue()
    {
        int temp=0;
        if(front==rear)
        {
            temp=a[front++];
            reset();
            return temp;
        }
        else if(front>rear)
        {
            System.out.println("Underflow");
            return -999;
        }
        else
        {
            temp=a[front++];
            return temp;
        }
    }
    void reset()
    {
        front=0;
        rear=-1;
    }
    void FIFO()
    {
        for(int i=front;i<=rear;i++)
            System.out.println(a[i]);
    }
    public static void main(String args[])
    {
        Queue obj=new Queue(5);
        obj.enqueue(3);
        obj.enqueue(4);
        obj.enqueue(5);
        obj.enqueue(6);
        obj.FIFO();
        System.out.println(obj.dequeue());
        obj.enqueue(7);
        obj.FIFO();
        obj.enqueue(8);
    }
}
    
    
        
