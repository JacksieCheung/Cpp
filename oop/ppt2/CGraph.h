#include<iostream>
#include<cstring>

using namespace std;

class CGraph
{
private:    
    int AddX;
    int AddY;
    char* Message;
    char* Colour;
public:
    CGraph(int AddX=0,int AddY=0,
    const char* Message=NULL,char* Colour=NULL){
        this->AddX = AddX,this->AddY = AddY;
   		this->Colour = NULL;
        if (Colour !=NULL){
            this->Colour = new char[10];
            std::strcpy(this->Colour,Colour);
        }
        this->Message = NULL;
        if (Message != NULL){
		    this->Message = new char[strlen(Message)];
		    std::strcpy(this->Message,Message);
	    }
	}
    virtual ~CGraph(){
        delete Colour;
        delete Message;
    };

    virtual void Show(){
        cout<<AddX<<","<<AddY<<endl;
    }

    virtual void ChangeMeesage(const char* Message)=0;
    virtual void ChangeSize()=0;
    virtual void ShowInfo()=0;
    virtual void ShowMsg()=0;

};
