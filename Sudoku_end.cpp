#include<bits/stdc++.h>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

void playSudoku();
void hideCursor(bool condition);
void gamePart(string part);
void gotoMenu(char choice);
void exitMenu();
void colorSet(int tint);
void helpSudoku(string located);
void print(int arr[9][9]);
void setNumberKey(string value){}
void upKey();
void downKey();
void leftKey();
void rightKey();
void pauseGame();
char gameLevel();
void finalAnswer();
void resume();


bool canPlace(int arr[9][9], int row, int col, int n)
{
	if (arr[row][col] != 0) return false;
	bool status = true;
	int gridx = (col / 3) * 3;
	int gridy = (row / 3) * 3;
	for (int i = 0; i < 9; i++) {
		if (arr[row][i] == n) { status = false; break; }
		if (arr[i][col] == n) { status = false; break; }
		if (arr[gridy + i / 3][gridx + i % 3] == n) { status = false; break; }
	}
	return status;
}

void nextEmpty(int arr[9][9], int row, int col, int& rowNext, int& colNext)
{

	int indexNext = 9 * 9 + 1;
	for (int i = row * 9 + col + 1; i < 9 * 9; i++) {
		if (arr[i / 9][i % 9] == 0) {

			indexNext = i;
			break;
		}
	}
	rowNext = indexNext / 9;
	colNext = indexNext % 9;
	//cout << row << "," << col << "|" << rowNext << "," << colNext << endl;
}

void copyArray(int arr[9][9], int arrCpy[9][9]) {
	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++)
			arrCpy[y][x] = arr[y][x];
}
std::vector<int> findPlaceables(int arr[9][9], int row, int col) {
	vector<int> placebles = {};
	for (int n = 1; n <= 9; n++)
		if (canPlace(arr, row, col, n)) placebles.push_back(n);
	return placebles;
}


bool solveSudoku(int arr[9][9], int row, int col)
{
	system("cls");
	print(arr);

	if (row > 8) return true;
	if (arr[row][col] != 0) {
		int rowNext, colNext;
		nextEmpty(arr, row, col, rowNext, colNext);
		return solveSudoku(arr, rowNext, colNext);
	}

	std::vector<int> placebles = findPlaceables(arr, row, col);

	if (placebles.size() == 0) {
		
		return false; 
	
	};

	bool status = false;
	for (int i = 0; i < placebles.size(); i++) {
		int n = placebles[i];
		int arrCpy[9][9];
		copyArray(arr, arrCpy);
		//cout << "(" << row << "," << col << ") =>" << n << endl;
		arrCpy[row][col] = n;
		int rowNext = row;
		int colNext = col;
		nextEmpty(arrCpy, row, col, rowNext, colNext);
		if (solveSudoku(arrCpy, rowNext, colNext)) {
			copyArray(arrCpy, arr);
			status = true;
			break;
		}
	}
	return status;
}



int sudokuPointer=0;
string sudokuStatus;
char setLevel;


int sudoku1[9][9] ={
	    {7,8,0,4,0,0,1,2,0},
	    {6,0,0,0,7,5,0,0,9},
		{0,0,0,6,0,1,0,7,8},
		{0,0,7,0,4,0,2,6,0},
		{0,0,1,0,5,0,9,3,0},
		{9,0,4,0,6,0,0,0,5},
		{0,7,0,3,0,0,0,1,2},
		{1,2,0,0,0,7,4,0,0},
		{0,4,9,2,0,6,0,0,7}
	};

int sudoku2[9][9] ={
	    {0,8,4,2,0,0,0,0,9},
	    {1,0,2,8,0,0,5,0,0},
		{9,0,0,0,6,0,0,0,3},
		{0,9,0,0,0,0,2,7,0},
		{5,0,0,0,0,0,0,0,8},
		{0,4,8,0,0,0,0,3,0},
		{7,0,0,0,2,0,0,0,1},
		{0,0,3,0,0,6,7,0,4},
		{4,0,0,0,0,5,3,9,0}
	};
	
int sudoku3[9][9] ={
	    {0,8,0,5,2,0,6,4,0},
	    {7,0,6,0,0,0,0,0,2},
		{4,2,0,0,0,0,0,3,0},
		{0,5,0,0,0,1,0,0,0},
		{6,0,0,7,8,3,0,0,9},
		{0,0,0,9,0,0,0,6,0},
		{0,3,0,0,0,0,0,2,6},
		{1,0,0,0,0,0,3,0,5},
		{0,9,2,0,3,5,0,0,0}
	};

int main()
{   //hide cursor
    hideCursor(true);
    //set title
    SetConsoleTitle(("Sudoku"));
    //varaible
    int choice;
    // display
    while(true)
    {
    	system("cls");
    	colorSet(4);  //Dark red
    	    gamePart("line_small_left");
    	colorSet(15);  //white
            cout<<"SUDOKU";
        colorSet(4);  //Dark red
    	    gamePart("line_small_right");
    	 cout<<endl;
		colorSet(15);
		   cout<<"[1] ";
		colorSet(11);  //light cyan
		  cout<<"START"<<endl;
		colorSet(15); //white
		  cout<<"[2] ";
		colorSet(14);  //yellow
		  cout<<"INSTRUCTIONS"<<endl;
		colorSet(15); //white
		  cout<<"[3] ";
		colorSet(12);  //light red
		  cout<<"EXIT"<<endl;
		colorSet(4);  //red
		  gamePart("seperator");
		colorSet(7);  //light gray
		 cout<<"(Press the number of your choice!) ";
		 colorSet(15); //white     	
		 
		 
		 //get your choice
		 char select= getch();
		 if(!(select<'1'|| select>'3')){
		 	choice= select;
		 	break;
		 }
	}
	
	//go to menu of user choice
	gotoMenu(choice);
}

//menu central

void gotoMenu(char choice)
{
	if(choice=='1'){
		  playSudoku();  //go to play menu
	}
	else if(choice=='2')
	{
		helpSudoku("main");  //go to instruction menu
    }
    else if(choice=='3')
    {
    	 exitMenu(); //go to exit menu
	}
}

void playSudoku(){
	 
    setLevel=  gameLevel();  	
   	system("cls");
	
	colorSet(4); //dark red
	  gamePart("line_small_left");
	colorSet(15);
	 cout<<"SUDOKU";
	colorSet(4);
	  gamePart("line_small_right");
	  //level and collect parts

	  	if( setLevel=='1')
	  	{
	  		colorSet(10);
			  cout<<setw(24)<<right<<"EASY LEVEL"<<endl;
			colorSet(4);
	           gamePart("seperator");
	        cout<<endl;
	         //Printing the board
	     	print(sudoku1);
		
		}
		else if(setLevel=='2')
		{	colorSet(14);
	    	 cout<<setw(25)<<right<<"MEDIUM LEVEL"<<endl;
	    	colorSet(4);
	          gamePart("seperator");
	          cout<<endl;
	
	    	print(sudoku2);
		}
		else if(setLevel=='3')
		{
			 colorSet(12);
	    	   cout<<setw(24)<<right<<"HARD LEVEL"<<endl;
	    	 colorSet(4);
 	          gamePart("seperator");
             cout<<endl;
	
	    	print(sudoku3);
		}
		else {
			main();
		}
	

	
	do{
	cout<<endl;
			  colorSet(14);
			   cout<<" Press";
			  colorSet(12);
			   cout<<" [1] ";
			  colorSet(14);
			   cout<<" to Pause the Game."<<endl;
			  colorSet(15);
			   cout<<" and ";
			  colorSet(14);
			   cout<<" Press";
			  colorSet(12);
			   cout<<"[2] ";
			  colorSet(14);
			   cout<<"to find solution of the SUDOKU"<<endl;
            char select = getch();
             if(!(select<'1' || select>'2')){
	    	   cout<<endl;
	    	 if(select =='1'){
                    pauseGame();		
					break;	 }
			 else{
                finalAnswer();
                break;
			 }
		  }
		  system("cls");
		  
		}while(true);  

    
    //----keyboard functions-----//
		while(true)
		{
			int keyPress;  //key code
			colorSet(15);
			  keyPress=0; //reset
			  keyPress=getch(); //get number
			  
			  if(keyPress==0 ||keyPress==224){// if arrow keys and delete key pressed
			     keyPress= 256 + getch(); //convert key code
			     if(keyPress== 328){ //up
			      upKey();
			      break;
				 }
				 else if(keyPress== 336){// down
				    downKey();
				    break;
				 }
				 else if(keyPress== 331){ //left
				 	leftKey();
				 	break;
				 }
				 else if(keyPress==333){// right
				   rightKey();
				   break;
				 }
				 else if(keyPress== 339){ //delete
				    setNumberKey("clear");
				    break;
				 }
			  }
			  else{ //if other key pressed
			  
			      //movemeent keys
			     if(keyPress== 119|| keyPress==87){ //up(W)
			        upKey();
			        break;
				 }
				 else if(keyPress== 115 || keyPress== 83){// down(S)
				    downKey();
				    break;
				 }
				 else if(keyPress== 97 || keyPress==65){ //left(A)
				 	leftKey();
				 	break;
				 }
				 else if(keyPress==100 || keyPress ==68){// right(D)
				   rightKey();
				   break;
				 }
				 //number key
				 if(keyPress== 49){// one (1)
				      setNumberKey("1");
				      break;
				 }
				  else  if(keyPress== 50){// two (2)
				      setNumberKey("2");
				      break;
				 }
				  else  if(keyPress== 51){// three (3)
				      setNumberKey("3");
				      break;
				 }
				  else  if(keyPress== 52){// four (4)
				      setNumberKey("4");
				      break;
				 }
				  else  if(keyPress== 53){// five (5)
				      setNumberKey("5");
				      break;
				 }
				  else  if(keyPress== 54){// six(6)
				      setNumberKey("6");
				      break;
				 }
				  else  if(keyPress== 55){// seven (7)
				      setNumberKey("7");
				      break;
				 }
				  else  if(keyPress== 56){// eight (8)
				      setNumberKey("8");
				      break;
				 }
				  else  if(keyPress== 57){// nine (9)
				      setNumberKey("9");
				      break;
				 }
				 //delete key
				 else if(keyPress==8){  //backspace
				      setNumberKey("clear");
				      break;
				 }
				 //pause key
				 else if(keyPress==27 || keyPress== 112|| keyPress==80){// escape(esc)
				    pauseGame();
				    break;
				 }
				 else{
				 	continue;
				 }
			  }
		}		 
		//-- key functions---//
	
	//pause
	    getch();
	    //go to main menu
	    main();
}

char gameLevel(){
	
	char choice;
		//display
	do{
		system("cls");
    	colorSet(4);  //Dark red
    	    gamePart("line_small_left");
    	colorSet(15);  //white
            cout<<"SUDOKU";
		colorSet(4); //dark red
    	    gamePart("line_small_right");
		colorSet(13);  //light cyan
		  cout<<setw(29)<<right<<"SELECT A DIFFICULTY"<<endl;
		colorSet(4); //white
		  cout<<"[1] ";
		colorSet(14);  //yellow
		  cout<<"EASY"<<endl;
		colorSet(15); //white
		  cout<<"[2] ";
		colorSet(14);  //yellow
		  cout<<"MEDIUM"<<endl;
		colorSet(15);  //white
		  cout<<"[3] ";
		colorSet(12);  //light red
		  cout<<"HARD"<<endl;
		colorSet(4); //dark red
		     gamePart("seperator");
		colorSet(15);  //white
		  cout<<"[4] ";
		colorSet(11); //light cyan
		  cout<<"BACK"<<endl;
		colorSet(4);  //dark red
		  gamePart("seperator");
		colorSet(7);//light gray
		  cout<<"(Press the number of your choice!) ";
		colorSet(15);  //white  
		
		  //get user choice
		  char select= getch();
		  if(!(select<'1'|| select>'4')){
		  	choice= select;
		  	break;
		  }
	}while(true);
	
	return choice;
}


void print(int arr[9][9]) {
   colorSet(13); 
     cout<<setw(53)<<right<<"________________________"<<endl;
   colorSet(15);	
	   
	for(int i = 0; i < 9; i++) {
	   	colorSet(13); 
          cout<<setw(29)<<right<<"|";
        colorSet(15); 
         if(i%3==0 && i!=0)
         { 	colorSet(13); 
      	      cout<<"_______|________|_______|"<<endl;;
      		colorSet(13); 
              cout<<setw(29)<<right<<"|";
          	colorSet(15); 
	    }
		   for (int j = 0; j < 9; j++)
	       {  if(j%3==0 && j!=0)
              { colorSet(13); 
      	              cout<<" | ";
      		    colorSet(13); 
	         }
	    
      	     if(arr[i][j]!=0)
      	     { colorSet(14); // dark red
   	            cout<<arr[i][j]<<' ';
		     }
		     else
		     { colorSet(4); //yellow
   	            cout<<arr[i][j]<<' ';
		     }
		    }
      	colorSet(13); 
          cout<<"|"<<endl;
      	colorSet(15);
	}
      colorSet(13); 
        cout<<setw(54)<<right<<"|_______|________|_______|"<<endl;
      colorSet(15);
}


void upKey(){
	sudokuPointer = sudokuPointer - 9;
	// top barrier
	if(sudokuPointer==-9)
	{ 
		sudokuPointer==72;
	}
	else if(sudokuPointer==-8)
	{
		sudokuPointer==73;
	}
	else if(sudokuPointer==-7)
	{
		sudokuPointer==74;
	}
	else if(sudokuPointer==-6)
	{
		sudokuPointer==75;
	}
	else if(sudokuPointer==-5)
	{
		sudokuPointer==76;
	}
	else if(sudokuPointer==-4)
	{
		sudokuPointer==77;
	}
	else if(sudokuPointer==-3)
	{
		sudokuPointer==78;
	}
	else if(sudokuPointer==-2)
	{
		sudokuPointer==79;
	}
	else if(sudokuPointer==-1)
	{
		sudokuPointer==80;
	}
}
void downKey(){
	sudokuPointer =sudokuPointer + 9;
	//bottom barrier
	if(sudokuPointer==81)
	{
		sudokuPointer==0;
	}
	else if(sudokuPointer==82)
	{
		sudokuPointer==1;
    } 
	else if(sudokuPointer==83)
	{
		sudokuPointer==2;
	}
	else if(sudokuPointer==84)
	{
		sudokuPointer==3;
	}
	else if(sudokuPointer==85)
	{
		sudokuPointer==4;
	}
	else if(sudokuPointer==86)
	{
		sudokuPointer==5;
	}
	else if(sudokuPointer==87)
	{
		sudokuPointer==6;
	}
	else if(sudokuPointer==88)
	{
		sudokuPointer==7;
	}
	else if(sudokuPointer==89)
	{
		sudokuPointer==8;
	}	
}
void leftKey(){
		sudokuPointer =sudokuPointer - 1;
	//left barrier
	if(sudokuPointer==62)
	{
		sudokuPointer==71;
	}
	else if(sudokuPointer==71)
	{
		sudokuPointer==80;
    } 
	else if(sudokuPointer==53)
	{
		sudokuPointer=62;
	}
	else if(sudokuPointer==44)
	{
		sudokuPointer==53;
	}
	else if(sudokuPointer==35)
	{
		sudokuPointer==44;
	}
	else if(sudokuPointer==26)
	{
		sudokuPointer==35;
	}
	else if(sudokuPointer==17)
	{
		sudokuPointer==26;
	}
	else if(sudokuPointer==8)
	{
		sudokuPointer==17;
	}
	else if(sudokuPointer==-1)
	{
		sudokuPointer==8;
	}	
}
void rightKey(){
		sudokuPointer =sudokuPointer + 1;
	//right barrier
	if(sudokuPointer==81)
	{
		sudokuPointer==72;
	}
	else if(sudokuPointer==72)
	{
		sudokuPointer==63;
    } 
    else if(sudokuPointer==63)
	{
		sudokuPointer==54;
    } 
	else if(sudokuPointer==54)
	{
		sudokuPointer=45;
	}
	else if(sudokuPointer==45)
	{
		sudokuPointer==36;
	}
	else if(sudokuPointer==36)
	{
		sudokuPointer==27;
	}
	else if(sudokuPointer==27)
	{
		sudokuPointer==18;
	}
	else if(sudokuPointer==18)
	{
		sudokuPointer==9;
	}
	else if(sudokuPointer==9)
	{
		sudokuPointer==0;
	}
}


void finalAnswer()
{
	// clear the screen
	system("cls");
	
	colorSet(4); //dark red
	  gamePart("line_small_left");
	colorSet(15);
	 cout<<"SUDOKU ";
	colorSet(4);
	  gamePart("line_small_right");
	colorSet(4);
	  gamePart("seperator");
	   cout<<endl;
	   
	 if(setLevel=='1'){
	 		   print(sudoku1);

	 }
	 else if(setLevel=='2')
	 {
	 		   print(sudoku2);

	 }
	 else if(setLevel=='3')
	 {
	 		   print(sudoku3);
	 }
	 else {
	 	main();
	 }

	   colorSet(4);  //dark red
		  gamePart("seperator");
	    colorSet(4);  //Dark red
    	    gamePart("line_small_left");
    	colorSet(15);  //white
            cout<<"SOLUTION";
		colorSet(4); //dark red
    	    gamePart("line_small_right");
	    colorSet(15); //white
	     
	 if(setLevel=='1'){
	 	   if(solveSudoku(sudoku1,0,0))
	 	       cout<<"successfully solved the board!"<<endl;
	 }
	 else if(setLevel=='2')
	 { if(solveSudoku(sudoku2,0,0))
	 	       cout<<"successfully solved the board!"<<endl;
	 }
	 else if(setLevel=='3')
	 { if(solveSudoku(sudoku3,0,0))
	 	       cout<<"successfully solved the board!"<<endl;
	 }
	 else {
	 	main();
	 }

    	 
		colorSet(13); 
  	      cout<<endl<<"Here , the solution."<<endl<<endl;
			  
		colorSet(4); //dark red
		  gamePart("seperator");
		colorSet(7); //light gray
		  cout<<"(Press any key to go back!) ";
		colorSet(15); //white
		
		//pause
		getch();
		//go to main menu
		
			main();	
}

//pause game
void pauseGame(){
	//display
	do{
		system("cls");
		colorSet(4); //dark red
		  gamePart("line_small_left");
		colorSet(15);
		 cout<<"SUDOKU";
		colorSet(4); //dark red
		  gamePart("line_small_right");
		colorSet(13);
		 cout<<setw(24)<<right<<"GAME PAUSED"<<endl;
		colorSet(4); //dark red
		 gamePart("seperator");
		colorSet(15);//white
		 cout<<"[1] ";
		colorSet(14); // yellow
		 cout<<"RESUME"<<endl;
		colorSet(15);
		 cout<<"[2] ";
	    colorSet(10); //light green
	     cout<<"INSTRUCTIONS"<<endl;
	    colorSet(15); //white
	     cout<<"[3] ";
	    colorSet(12);  //light red
	     cout<<"QUIT"<<endl;
	    colorSet(4); 
	      gamePart("seperator");
	    colorSet(7); //light gray
	      cout<<"(Press the number of your choice!) ";
	    colorSet(15); //white
	    
	    //get user choice
	    char select = getch();
	    if(!(select<'1' || select>'3')){
	    	 cout<<endl;
	    	 if(select =='2'){
	    	 	  helpSudoku("in-game");
			 }
			 else if(select=='3'){
			   finalAnswer();
			   break;
			 }
			 else if(select=='1'){
			 	resume();
			 }
			 else{
			 	break;
			 }
			}
		}while(true);
}


void resume(){
				
	system("cls");
	
	colorSet(4); //dark red
	  gamePart("line_small_left");
	colorSet(15);
	 cout<<"SUDOKU";
	colorSet(4);
	  gamePart("line_small_right");
	  //level and collect parts

	  	if( setLevel=='1')
	  	{
	  		colorSet(10);
			  cout<<setw(24)<<right<<"EASY LEVEL"<<endl;
			colorSet(4);
	          gamePart("seperator");
	          cout<<endl;
	
	
	print(sudoku1);
		}
		else if(setLevel=='2')
		{	colorSet(14);
	    	 cout<<setw(25)<<right<<"MEDIUM LEVEL"<<endl;
	    	colorSet(4);
	          gamePart("seperator");
	        cout<<endl;
	
	    	print(sudoku2);
		}
		else if(setLevel=='3')
		{
			 colorSet(12);
	    	   cout<<setw(24)<<right<<"HARD LEVEL"<<endl;
	    	 colorSet(4);
	          gamePart("seperator");
	        cout<<endl;
	
	    	print(sudoku3);
		}
		else {
			main();
		}
	

	
	do{
	cout<<endl;
			  colorSet(14);
			    cout<<" Press";
			  colorSet(12);
			    cout<<" [1] ";
			  colorSet(14);
			    cout<<" to Pause the Game."<<endl;
			  colorSet(15);
			    cout<<" and ";
			  colorSet(14);
			    cout<<" Press";
			  colorSet(12);
			    cout<<"[2] ";
			  colorSet(14);
			    cout<<"for solution of the SUDOKU"<<endl;
            char select = getch();
             if(!(select<'1' || select>'2')){
	    	   cout<<endl;
	    	 if(select =='1'){
                 pauseGame();		
				 break;	 }
			 else{
                finalAnswer();
                break;
			 }
		  }
		  system("cls");
		}while(true);  

    		
	    
	}
void helpSudoku(string located){
	 
	system("cls");
		colorSet (4); //DARK RED
			gamePart("line_small_left");
		colorSet(15); //15
			cout<<"SUDOKU";
		colorSet(4); //DARK RED
			gamePart("line_small_right"); 
		colorSet(13); //13
         cout<<setw(25)<<right<<"INSTRUCTIONS"<<endl; 
		colorSet (4); //DARK RED
          gamePart("seperator");
        colorSet(10); //LIGHT GREEN
         cout<<" How to play: "<<endl; 
		colorSet(15); //WITTE
         cout<<" * The sudoku puzzle is consist of"<<endl
             <<"   a 9x9 grid, you have to fill"<<endl
			 <<"   the empty squares using the" <<endl
			 <<"   numbers 1 to 9."<<endl
             <<" * Use the 1-9 keys in your"<<endl
			 <<"   keybord to fill the sudoku"<<endl
             <<"   puzzle."<<endl
 			 <<" * To move arround the sudoku"<<endl
 			 <<"   puzzle, use the WASD letter"<<endl
 			 <<"   keys or the arrow keys."<<endl
			 <<" * Use backspace or delete key to "<<endl
			 <<"   clear the number selected in"<<endl
			 <<"   the sudoku puzzle."<<endl
			 <<" * Once you finish the sudoku"<<endl
			 <<"   puzzle, it will prompt you that"<<endl
			 <<"   you finished it if not you can"<<endl 
 			 <<"   press P then you can choose"<<endl 
			 <<"   \"Quit\" in the pause menu "<<endl
			 <<"   if your having a hard time."<<endl;
		colorSet(4); //dark red
		  gamePart("seperator");
		colorSet(7); //light gray
		  cout<<"(Press any key to go back!) ";
		colorSet(15); //white
		
		//pause
		getch();
		//go to main menu
		if(located=="main"){
			main();
		}
}

void exitMenu(){
	//display
	  do{
		system("cls");
		colorSet(4); //dark red
		  gamePart("line_small_left");
		colorSet(15);
		  cout<<"SUDOKU";
		colorSet(4); //dark red
		  gamePart("line_small_right");
		colorSet(13);
		 cout<<setw(24)<<right<<"DO YOU WANT TO EXIT"<<endl;
		colorSet(4); //dark red
		 gamePart("seperator");
		colorSet(15);//white
		 cout<<"[1] ";
		colorSet(14); // yellow
		 cout<<"YES"<<endl;
		colorSet(15);
		 cout<<"[2] ";
	    colorSet(10); //light green
	     cout<<"NO"<<endl;
	    colorSet(4); 
	      gamePart("seperator");
	    colorSet(7); //light gray
	      cout<<"(Press the number of your choice!) ";
	    colorSet(15); //white
	    
	    //get user choice
	    char select = getch();
	    if(!(select<'1' || select>'2')){
	    	 cout<<endl;
	    	 if(select =='1'){
	    	 	  exit(0);
			 }
			 else{
			 	main(); 
			 }
		  }
		}while(true);  
}

void gamePart(string part){
	
	if(part == "line_small_left"){
		cout<<"=============== ";
	}
	else if(part == "line_small_right"){
		cout<<" ================"<<endl;
	}
	else if(part == "seperator"){
		cout<<"======================================="<<endl;
	}
	else if(part == "sudoku_outer_border"){
		cout<<" $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	}
	else if(part == "sudoku_outer_vertical_border_small"){
		cout<<" $ ";
	}
	else if(part == "sudoku_outer_vertical_border_next_line"){
		cout<<" $"<<endl;
	}
	else if(part == "sudoku_inner_vertical_border_small"){
		cout<<" | ";
	}
	else if(part == "sudoku_inner_border"){
		cout<<" $---*---*---$---*---*---$---*---*---$"<<endl;
	}
	else{
		cout<<"";
	}	
}

void colorSet(int tint){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tint);
}

void hideCursor(bool condition)
{
	HANDLE out= GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible=(!(condition));  //set the cursor visibility
	SetConsoleCursorInfo(out,&cursorInfo);
}

