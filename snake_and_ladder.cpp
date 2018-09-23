#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Board{
	
	 int positionsnake[4] = {62,17,87,98};
     int positionsnakefinal[4] = {18,7,36,79};
	 int positionladder[4] = {1,28,51,72};
     int positionladderfinal[4] = {38,84,67,91};
    
	unordered_map<int,int> snake;
	unordered_map<int,int> ladder;
	
	int position;
	
	public: 
	
  	Board(){
  	
		position = 0;
		
		for (int i =0; i<4; i++)
		{
			snake[positionsnake[i]]=positionsnakefinal[i];
	
	    }
        
		for (int j =0; j<4; j++)
		{
			ladder[positionladder[j]]=positionladderfinal[j];
	
	    }
    }
	
	
	int checkSnake_and_Ladder(int pos){
		
		if(snake.find(pos)!=snake.end())
		return snake.find(pos)->second;
		if(ladder.find(pos)!=ladder.end())
		return ladder.find(pos)->second;
		
		return 0;
	}

	int updatePosition(int number){
		
		if((position + number) > 100 )
		return position;
		
		position = position + number;
		
		// Check Snake and ladder 
		
		 int temp = checkSnake_and_Ladder(position);
		 if(temp!=0)
		  {
		  	position = temp;
		  }
		  
		return position;
	}
	
	
};

int main(){
	Board newBoard;
	int getinput, trackposition = 0;
	while(trackposition != 100 ){
		
		cout<<"Roll a dice!"<<"\n";
		cin>>getinput;
		if(getinput > 6)
		cout<<"Invalid Input"<<"\n";
		
		else{
		
		trackposition = newBoard.updatePosition(getinput);
		cout<<"New postion:"<<trackposition<<"\n";
	    }
		   
		}
	cout<<"You Won!";
	
	return 0;
}
