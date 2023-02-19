#include <iostream>
#include<string>
#include<regex>

// the node structure for linked lists

struct Node
{
    std::string data;
    Node* next;
};

// Class stack

class stack
{
private:
    // head is the top
    Node* head;
public:
    // constructor
    stack()
    {
        head=NULL;
    }
    void push(std::string data)
    {
         // Create a new node
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;  
    }
    std::string pop()
    {
            
        if(isEmpty()){
            std::cout << "No URL in memory" <<std::endl;

    }
    else {
    
    // get top element

        Node* top = head;
        std::string data = top->data;

        // Update head to point to the next element

        head = head->next;

        // free memory
        delete top;
        return data;
    }
    }
    bool isEmpty()
    {
        if(head==NULL){
            return true;
        }
        else
        return false;

    }
    void DisplayHead()
    {
        //Node *run=head
        
        if(head!=NULL){

        std::cout<<"You are currently at: "<<head->data<<std::endl;
    }
    }
    void Display()
    {
        Node *temp=head;
        while(temp != NULL)
        {
            std::cout << temp->data <<std::endl;
            temp = temp->next;
        }
        //Node *temp=head;
    }
};

// push element to top of stack

//url validation format function
bool isValidUrl(const std::string url){
    const std::regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
    
    if(url.empty()){
        return false;
    }
    
    if(std::regex_match(url,pattern)){
        return true;
    }else{
        return false;
    }
}


int main()
{
    stack first;
    stack second;
    stack History;
    std::string temp;
    int option;
    std::string URL;
      do {
        
        std::cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << std::endl;
        first.DisplayHead();
        std::cout << "1. Search " <<std::endl;
        std::cout << "2. Move Backward" <<std::endl;
        std::cout << "3. Move Forward" <<std::endl;
        std::cout<< "4. Display history" <<std::endl;

        std::cin >> option;
        switch(option)
        {
        case 0:
            break;
        case 1:

            std::cout << "Enter URL: " << std::endl;
            std::cin>>URL;
            
            if(isValidUrl(URL)){
            first.push(URL);
            History.push(URL);
            }else{
                std::cout<<"Incorrect URL format!"<<std::endl;
                std::cout<<"Please try again!"<<std::endl;
                std::cout<<" example Url:https://www.example.com"<<std::endl;
            }
            break;
                    
        case 2:
            if(first.isEmpty()){
                std::cout<<"There is no Url"<<std::endl;
            }else if(!first.isEmpty()){
            
            temp = first.pop();
            second.push(temp);
        }else{
            std::cout<<"There is no Url"<<std::endl;
        }
            break;
        
        case 3:
            if(second.isEmpty()){
                std::cout<<"There is no url"<<std::endl;
            }else if(!second.isEmpty()){
            temp = second.pop(); 
            first.push(temp);
        }else{
            std::cout<<"There is no url"<<std::endl;
        }
            break;      
        case 4:
            if(History.isEmpty()){
                std::cout<<"No history"<<std::endl;
            }else{
            History.Display();
        }
            break;
        default:
            std::cout<<"Invalid selection!"<<std::endl;
        }
      } while(option != 0);

        return 0;

}

