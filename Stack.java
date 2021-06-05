package Data_Structures;
import java.util.*;
public class Stack
{
    int a[];
    int top;
    Stack(int n)
    {
        a=new int[n];
        top=-1;
    }
    void push(int n)
    {
        if(top==a.length-1)
            System.out.println("Overflow");
        else
        {
            top++;
            a[top]=n;
        }
    }
    int pop()
    {
        if(top==-1)
        {
            System.out.println("Underflow");
            return -999;
        }
        else
        {
            int temp=a[top];
            top--;
            return temp;
        }
    }
    void LIFO()
    {
        for(int i=top;i>=0;i--)
            System.out.println(a[i]);
    }
    public static void main(String args[])
    {
        Stack obj=new Stack(5);
        obj.push(3);
        obj.push(4);
        obj.push(5);
        obj.LIFO();
        System.out.println("*");
        obj.push(6);
        obj.LIFO();
        int n=obj.pop();
        obj.LIFO();
        obj.push(7);
    }
}
    
    
        
