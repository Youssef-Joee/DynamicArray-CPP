#include <iostream>
using namespace std;

// Array as Data Structure using Class (OOP)

class Array
{
private:
    int size;
    int length;
    int* ptr;     // Pointeer

public :
    // Create Paramizied Constructor
    Array(int arrsize)
    {
        size = arrsize;
        length = 0;

        ptr = new int[arrsize];
    }

    void Fill()
    {
        int NoOfItems;
        cout << "How many items you wanna fill? ";
        cin >> NoOfItems;

        if (NoOfItems <= 0 || NoOfItems > size)
        {
            cout << "You entered wrong number please try again!\n";
            return;     // Important and new for me
            // return here means I will not continue this method and I will break it.
        }


        length = NoOfItems; 
        for (int i = 0; i < NoOfItems ; i++)
        {
            cout << "Enter element No. [" << i << "] ? ";
            cin >> ptr[i];
            
        }
    }

    void Display()
    {
        cout << "\nDisplay Array Content\n";

        for (int i = 0; i < length; i++)
        {
            cout << ptr[i] << "\t";
        }
        cout << endl; 
    }

    int getSize()
    {
        return size;
    }

    int getLength()
    {
        return length;
    }

    int Search(int Value)
    {
        for (int i = 0; i < length; i++)   // Big O(n)
        {
            if (ptr[i] == Value)
            {
                return i;         // i is index;
            }
        }
        return -1;
    }

    void Append(int New_Item)   // Add Elements at the end of the array
    {
        if (length < size)
        {
            ptr[length] = New_Item;
            length++;
        }
        else
        {
            cout << "Array is Full. You Can NOT add more elements !!\n";
        }
    }

    void Insert(int index, int Value)
    {
        int i = length-1;  // Last Elements
         
        if (length < size && index >= 0 && index < size) 
        {  
            for (;i >= index ;i--)   
            { 
                ptr[i + 1] = ptr[i];   
            } 
             
            ptr[index] = Value;    
            length++;      
        }
        else
        {
            cout << "Array is Full. You can NOT Insert Elements!!\n";
        }
        // Insert and Delete in array is Big O(n) and that's bad bz of this reason
        // We need Linked List Big O(1) 
    } 

    void Delete(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < length - 1; i++)
            {
                ptr[i] = ptr[i + 1];
            }
            length--;
        }
        else
            cout << "Index out of array range \n";
    }

    void Enlarge(int NewSize)
    {
        if (NewSize <= size)
        {
            cout << "New size must be larger than current size \n";
        }
        else
        {
            int* Temp_ptr = ptr;  // Temporary Poiteer point to the array to not lose it
            ptr = new int[NewSize];
            size = NewSize;

            for (int i = 0; i < length; i++)
            {
                ptr[i] = Temp_ptr[i];
            }

            delete[]Temp_ptr;
        }
        
    }

    void Merge(Array other) 
    {
        size = size + other.getSize(); 
        int* Temp_ptr = ptr;
        ptr = new int[size];
       
        
        // Put Frist Array Elements
        int i = 0;
        for (i; i < length; i++)
        {
            ptr[i] = Temp_ptr[i];
        }
        delete []Temp_ptr; 


        // Put Second Array Elements
        // Keep going with i Do NOT inachialize it again
        int j = i; 
        for (i = 0; i < other.getLength(); i++) 
        {  
            ptr[j++] = other.ptr[i];  
        }
         
        length = length + other.getLength();    
    }

};









int main()
{
    int arrsize; 
    cout << "Enter Array Size? "; 
    cin >> arrsize; 

    Array MyArray(arrsize); 

    MyArray.Fill();

    cout << "Array Size = " << MyArray.getSize() << endl; 
    cout << "Array Length = " << MyArray.getLength() << endl;  


    MyArray.Display();

   
   /* 
    
    int Value;
    cout << "Enter the value to search for? ";
    cin >> Value;

    int index;
    index = MyArray.Search(Value);

    if (index == -1)
        cout << "The Elements is not found\n";
    else
        cout << "The Elements is found at index = " << index << endl;
  */

    /*int New_Item;
    cout << "Enter new item to add to the array? ";
    cin >> New_Item;

    MyArray.Append(New_Item);
    MyArray.Display();*/

    /*int New_Item, Index; 
    cout << "Enter the index of the Item? ";
    cin >> Index;  

    MyArray.Delete(Index);
    MyArray.Display();
    cout << "Array Size = " << MyArray.getSize() << endl;
    cout << "Array Length = " << MyArray.getLength() << endl;*/

    /*cout << "Array Size = " << MyArray.getSize() << endl;
    cout << "Array Length = " << MyArray.getLength() << endl;

    int NewSize;
    cout << "Enter New Size ";
    cin >> NewSize;

    MyArray.Enlarge(NewSize);*/

    

    Array other(3);
    other.Fill();

    MyArray.Merge(other);
    cout << "Array Size = " << MyArray.getSize() << endl;
    cout << "Array Length = " << MyArray.getLength() << endl;
    MyArray.Display();

    return 0;
}
