#include<iostream>

class Trango{
	private:
		int trangoLong;
		int trangoHeight;
		int square;
		int length;
	public:
		Trango(int trangoLong = 0,int trangoHeight=0){
			this->trangoLong=trangoLong;
			this->trangoHeight=trangoHeight;
			length=(trangoLong+trangoHeight)*2;
			square=trangoLong*trangoHeight;
		}

		int GetLong(){
			return trangoLong;
		}

		int GetHeight(){
			return trangoHeight;
		}

		int GetSquare(){
			return square;
		}

		int GetLength(){
			return length;
		}
};

int main(){
	Trango T(5,4);
	std::cout<<T.GetLong()<<" "<<T.GetHeight()<<std::endl;
	return 0;
}
