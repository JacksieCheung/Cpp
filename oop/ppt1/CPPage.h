#include "CRect.h"
#include "CEllipse.h"
#define Status int

// 建立文本框后返回信息，用于定位
typedef struct code{
	int Code;  // 类型序号，1->矩形 2->圆
	int Index; // 数组中的索引
} Code;

// 派生链表节点的类 CRect
class CRnode:public CRect{
	public:
		CRnode* Next;
		int Index;

		CRnode(int AddX=0,int AddY=0,int Length=0,int Height=0,const char *Message=NULL):CRect(AddX,AddY,Length,Height,Message){
			Next = NULL;
		}
		CRnode(const CRect& c):CRect(c){
			Next = NULL;
		}
};

// 派生链表节点的类 CEllipse
class CEnode:public CEllipse{
	public:
		CEnode* Next;
		int Index;

		CEnode(int AddX=0,int AddY=0,int Radium=0,const char*Message=NULL):CEllipse(AddX,AddY,Radium,Message){
			Next = NULL;
			Index = 0;
		}

		CEnode(const CEllipse& c):CEllipse(c){
			Next = NULL;
			Index = 0;
		}
};

class CPPage{
	private:
		CRnode* CRptr;
		CEnode* CEptr;
		int CRnums; // 矩形的数量
		int CEnums; // 圆形的数量
		int Number; // 用于给同一个页面的这两个文本框计数
	public:
		static int count; // 计数 CPPage

		CPPage(){
			CRptr = NULL;
			CEptr = NULL;
			CRnums = 0;
			CEnums = 0;
			Number = 0;
		}
		~CPPage(){
			while(CRptr!=NULL) {
				CRnode* tmp = CRptr;
				CRptr = CRptr->Next;
				delete tmp;
			}
			while(CEptr!=NULL){
				CEllipse* tmp = CEptr;
				CEptr = CEptr->Next;
				delete tmp;
			}
		}

		// 在页面中新建一个矩形对象
		// 输入参数，返回类型基本信息
		Code InsertCRByObj(CRect c){
			CRnode* node = new CRnode(c);
			node->Next = CRptr;
			CRptr = node;
			CRptr->Index = Number;
			CRnums++;
			Number++;
			return Code{Code:1,Index:Number-1};
		}

		Status ModifyCRMsgById(int index,const char* Message){
			CRnode* tmp = CRptr;
			while(tmp!=NULL) {
				if (tmp->Index==index) break;
			}

			if (tmp==NULL) return 0; // cr 走完了，说明没找到，返回错误代码 0

			tmp->ChangeMsg(Message);
			return 1;
		}

		Status ModifyCRSizeById(int index,int AddX,int AddY,int Length,int Height){
			CRnode* tmp = CRptr;
			while(tmp!=NULL) {
				if (tmp->Index==index) break;
			}

			if (tmp==NULL) return 0; // cr 走完了，说明没找到，返回错误代码 0

			tmp->ChangeSize(AddX,AddY,Length,Height);
			return 1;
		}

		// 删除一个矩形对象
		Status DeleteCRByID(int index){
			CRnode* tmpHead = CRptr;
			CRnode* tmpTail = NULL;
			while(tmpHead->Next!=NULL){
				if (tmpHead->Next->Index==index) {
					tmpTail = tmpHead;
					tmpHead = tmpHead->Next;
					break;
				}
			}

			if (tmpTail==NULL) return 0;
			
			tmpTail->Next = tmpHead->Next;
			delete tmpHead;
			return 1;
		}

		// 在页面中新建一个椭圆对象
		// 输入参数，返回类型基本信息
		Code InsertCEByObj(CEllipse c){
			CEnode* node = new CEnode(c);
			node->Next = CEptr;
			CEptr = node;
			CEptr->Index = Number;
			CEnums++;
			Number++;
			return Code{Code:2,Index:Number-1};
		}

		Status ModifyCEMsgById(int index,const char* Message){
			CEnode* tmp = CEptr;
			while(tmp!=NULL) {
				if (tmp->Index==index) break;
			}

			if (tmp==NULL) return 0; // cr 走完了，说明没找到，返回错误代码 0

			tmp->ChangeMsg(Message);
			return 1;
		}

		Status ModifyCESizeById(int index,int AddX,int AddY,int Radium){
			CEnode* tmp = CEptr;
			while(tmp!=NULL) {
				if (tmp->Index==index) break;
			}

			if (tmp==NULL) return 0; // cr 走完了，说明没找到，返回错误代码 0
		
			tmp->ChangeSize(AddX,AddY,Radium);
			return 1;
		}

		// 删除一个圆形文本框
		Status DeleteCEByID(int index){
			CEnode* tmpHead = CEptr;
			CEnode* tmpTail = NULL;
			while(tmpHead->Next!=NULL){
				if (tmpHead->Next->Index==index) {
					tmpTail = tmpHead;
					tmpHead = tmpHead->Next;
					break;
				}
			}

			if (tmpTail==NULL) return 0;
			
			tmpTail->Next = tmpHead->Next;
			delete tmpHead;
			return 1;
		}
 
		// 显示全部的文本框信息
		void Show(){
			std::cout<<"Here is a page:"<<std::endl;
			std::cout<<"CRnums:"<<CRnums<<" , "<<"CEnums:"<<CEnums<<std::endl<<std::endl;;
			
			CRnode* tmp1 = CRptr;
			while(tmp1!=NULL){
				tmp1->ShowInfo();
				std::cout<<tmp1->Message<<std::endl<<std::endl;
				tmp1 = tmp1->Next;
			}

			CEnode* tmp2 = CEptr;
			while(tmp2!=NULL){
				tmp2->ShowInfo();
				std::cout<<tmp2->Message<<std::endl<<std::endl;
				tmp2 = tmp2->Next;
			}

			std::cout<<std::endl;
		}
};

