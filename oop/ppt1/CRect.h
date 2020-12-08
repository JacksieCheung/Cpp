#include<iostream>
#include<cstring>

// 矩形文本框类
class CRect{
	private:
		int AddX; // 左上角的x坐标
		int AddY; // 右上角的y坐标
		int Length;
		int Height;
		char* Message;
		friend class CPPage; // 友元
	public:
		CRect(int AddX=0,int AddY=0,int Length=0,int Height=0,const char* Message=NULL){
			this->AddX = AddX;
			this->AddY = AddY;
			this->Length = Length;
			this->Height = Height;
			this->Message = NULL;
			if (Message!=NULL){
				this->Message = new char[10];
				std::strcpy(this->Message,Message);
			}
		}
		CRect(const CRect& c){
			this->AddX = c.AddX;
			this->AddY = c.AddY;
			this->Length = c.Length;
			this->Height = c.Height;
			this->Message = NULL;
			if (c.Message!=NULL){
				this->Message = new char[10];
				std::strcpy(this->Message,c.Message);
			}
		}
		~CRect(){
			delete Message;
		}

		// 修改属性
		void ChangeSize(int AddX,int AddY,int Length,int Height){
			this->AddX = AddX;
			this->AddY = AddY;
			this->Length = Length;
			this->Height = Height;
		}

		// 修改信息
		void ChangeMsg(const char* Message){
			if (strlen(this->Message)<strlen(Message)){
				delete this->Message;
				this->Message = new char[strlen(Message)];
			}
			std::strcpy(this->Message,Message);
		}

		// 打印信息
		void ShowInfo(){
			std::cout<<"Here is a CRect object:"<<std::endl;
			std::cout<<"AddX:"<<AddX<<" , "<<"AddY:"<<AddY<<std::endl;
			std::cout<<"Length:"<<Length<<" , "<<"Height:"<<Height<<std::endl;
		}

		void ShowMsg(){
			std::cout<<"Here is a CRect object:"<<std::endl;
			std::cout<<"AddX:"<<AddX<<" , "<<"AddY:"<<AddY<<std::endl;
			std::cout<<"Length:"<<Length<<" , "<<"Height:"<<Height<<std::endl;
			std::cout<<"Message:"<<Message<<std::endl;
			std::cout<<std::endl;
		}

		// 等号重载
		CRect& operator=(CRect& obj){
			this->AddX = obj.AddX;
			this->AddY = obj.AddY;
			this->Length = obj.Length;
			this->Height = obj.Height;

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
