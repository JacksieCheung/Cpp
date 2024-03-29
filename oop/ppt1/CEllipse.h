#include<iostream>
#include<cstring>

// 圆文本框类
class CEllipse{
	private:
		int AddX; // 原点Ｘ
		int AddY; // 原点Ｙ
		int Radium;
		char* Message;
		friend class CPPage;
	public:
		CEllipse(int AddX=0,int AddY=0,int Radium=0,const char* Message=NULL){
			this->AddX = AddX;
			this->AddY = AddY;
			this->Radium = Radium;
			this->Message = NULL;
			if (Message != NULL){
				this->Message = new char[10];
				std::strcpy(this->Message,Message);
			}
		}
		CEllipse(const CEllipse& c){
			this->AddX = c.AddX;
			this->AddY = c.AddY;
			this->Radium = c.Radium;
			this->Message = NULL;
			if (c.Message != NULL){
				this->Message = new char[10];
				std::strcpy(this->Message,c.Message);
			}
		}
		~CEllipse(){
			delete Message;
		}

		// 修改属性
		void ChangeSize(int AddX,int AddY,int Radium){
			this->AddX = AddX;
			this->AddY = AddY;
			this->Radium = Radium;
		}
	
		// 修改信息
		void ChangeMsg(const char* Message){
			if (strlen(this->Message)<strlen(Message)){
				delete this->Message;
				this->Message = new char[strlen(Message)];
			}
			std::strcpy(this->Message,Message);
		}

		// 查看信息
		void ShowInfo(){
			std::cout<<"Here is a CEllipse object:"<<std::endl;
			std::cout<<"AddX:"<<AddX<<" , "<<"AddY:"<<AddY<<std::endl;
			std::cout<<"Radium:"<<Radium<<std::endl;
		}

		void ShowMsg(){
			std::cout<<"Here is a CEllipse object:"<<std::endl;
			std::cout<<"AddX:"<<AddX<<" , "<<"AddY:"<<AddY<<std::endl;
			std::cout<<"Radium:"<<Radium<<std::endl;
			std::cout<<"Message:"<<Message<<std::endl;
			std::cout<<std::endl;
		}

		// 等号重载
		CEllipse& operator=(CEllipse& obj){
			this->AddX = obj.AddX;
			this->AddY = obj.AddY;
			this->Radium = obj.Radium;
			
			if (this->Message != NULL) {
				delete Message;
				Message = NULL;
			}

			if (obj.Message != NULL){
				this->Message = new char[strlen(obj.Message)];
				std::strcpy(this->Message,obj.Message);
			}
			return *this;
		}
};

