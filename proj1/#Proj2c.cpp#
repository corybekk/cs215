// AUTHOR: CORY BEKKER                                                  |
// CS215                                                                |
// PROJECT 1                                                            |
// This program parses a sentence and checks for invalid capitalization,|
// punctuation, and if it is missing a subject or predicate.            |
//-----------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

//------------------CLASS CheckArg-------------------------------------
//This class has one private member "argc" which is the amount of inputs
//for the command line argument. The two member functions "open" and "check"
//are used to check the argumets are valid and if the file can open. The 
//CheckArg object I used is called "input".
//--------------------------------------------------------------------
class CheckArg {
public:
  CheckArg();//defaulf constructor
  CheckArg(const CheckArg& other);//copy constructor
  ~CheckArg();//destructor
  bool open(char* a[]);//checks if file can open from command line
  bool check(int a);//checks command line argument input 

private:
  int argc;// the amount of argument on the command line
};

//-------------------------------------------------------------
string check_proper_noun(string Array[],int x1);
string check_subject_pronoun(string Array1[], int x2);
string check_common_noun(string Array2[], int x3);
string check_adjective(string Array3[], int x4);
string check_articles(string Array4[], int x5);
string check_verb(string Array5[], int x6);
string check_object(string Array6[], int x7);
string check_preposition(string Array7[], int x8);
string check_and(string Array8[], int x9);
bool check_argument(int argc, char* argv[]);
bool check_spaces( string stream);
bool check_PuncsCaps(string sentence);
bool check_Vocab(string SENTENCE);
bool empty_line(string Sentence);
bool print_sentence(int CurrentWord, int MaxWord, string Array9[]);
int check_for_subject(string Array8[],string NOUN[], string SUBJECT_PRO[],
                      string ARTICLE[],string COMMONNOUN[], string ADJECTIVE[], int i, int n);
int check_for_object(string Array9[],string NOUN1[], string OBJECT1[], string ARTICLE1[],
		     string COMMONNOUN1[], string ADJECTIVE1[], int I, int N);

const int num = 1000;//size of all arrays

int main(int argc, char* argv[]) {
  
  ifstream file;// used to open the command line argument file 
  string sentence;// this is the line/sentence being read
  CheckArg input;//class object to check command line arguments

  if(input.check(argc)== false)return 0;// checks if the cmd line arguments are good
  if(input.open(argv)== false)return 0;// checks if the file will open
  
  file.open(argv[1]);// opens file.
  
  while(getline(file,sentence)){// makes the first line of the file into a string
    
    if(empty_line(sentence)==false){//checks if the line being read is empty 
      
      if(check_spaces(sentence)==true){//checks spaces in sentence
	
        if(check_PuncsCaps(sentence)==true){//checks puntuation and capitalization in sentence
	  
	  if(check_Vocab(sentence)==true){//checks for predicate and subject
	  }
	}
      }
    }
  }
  file.close();  
  return 0;
}
//////////////////////CLASS FUNCTIONS///////////////////////////////////
//-----------------MEMBER FUNCTION CHECK------------------------------------
//member function "check" is used to check the command line argument/inputs.
//it passes "a" which is the amount of inputs in the command line. If the 
//argument is within correct limits then it returns true, if it is not, then 
//it returns false, which exits the program. 
bool CheckArg::check(int a){
  if(a>2){ //If the arguments given is greater than 2, it will return false.
    cout<<"Too many command-line inputs given."<<endl;
    return false;
  }
  if(a<2){// If the arguments given is less than 2 it returns false.
    cout<<"No file name entered."<<endl;
    return false;
  }
  return true;
}
//-----------------MEMBER FUNCTION OPEN--------------------------------
//Passes "a[]" which is argv[] and tries to open the index spot a[1] as a 
//file. If the file opens it returns true and it is good, if it returns 
//false the file is bad and the program exits.
//---------------------------------------------------------------------
bool CheckArg::open(char* a[]){
  
  ifstream file;//used to open up a[1] to see if it is good
  
  file.open(a[1]);// opens the file
  if(file.fail()){// checks if the file fails to open
    cout<<"Could not open file"<<endl;
    return false; // if it fails returns false
  }
  file.close();// closes the file

  return true;
}
//------------DEFAULT CONSTRUCTOR----------------------------
// has no parameters or return value.
//---------------------------------------------------------
CheckArg::CheckArg(){
  argc=0; // sets argc to 0 so that way it is not filled with garbage
}
//--------------COPY CONSTRUCTOR----------------------------
//the parmater is a object of the class. it has no return value
//------------------------------------------------------------
CheckArg::CheckArg(const CheckArg& other){
  argc=other.argc; // copies the argc input variable to the member variable
}
//--------------DESTRUCTOR----------------------------
CheckArg::~CheckArg(){
}
//-------------------------EMPTY LINE FUNCTION--------------------------------------
/*This function passes "Sentence" as a string and makes it into a stringstream. It 
  checks if the string stream can be read into a variable which determines if that 
  line is empty or not. If it is not empty it returns true. */
//----------------------------------------------------------------------------------
bool empty_line(string Sentence){
  
  stringstream s;// used to make sentence into a string stream
  char word;// used to see if there is a char on the "sentence" line
   
  s.str(Sentence);//makes sentence into a string stream
  if(s>>word){//checks if the line is empty 
    return false;//if the line ins not empty it returns false
  }
  else{
    return true;//if the line is empty it returns true
  }
}
//------------------------CHECK VOCAB FUNCTION----------------------------------------
/*The check_Vocab function checks the sentence for a correct subject and
  correct predicate. If a subject or predicate is missing, it will return false
  and give an error saying "invalid predicate" or "invalid subject." */
//------------------------------------------------------------------------------------
bool check_Vocab(string SENTENCE){
   
  stringstream s; // used to turn the getline string "sentence" into a stream 
  string words;// this is what the s stream goes into to make a function of strings
  string array4[num];// the array of strings
  string noun[num];//a. 
  string subject_pro[num];//b.
  string commonnoun[num];//c. each vocab has its own array incase a word appears more than once
  string adjective[num];//d.
  string article[num];//e.
  string verb[num];//f.
  string object[num];//g.
  string preposition[num];//h.
  string word_and[num];//k
  int current_word=0;// used to give the current position in the array 
  int MAX=0;//this is the max size of the array
  int i =0;
  int a =0;
  int b =0;
  int c =0;// each vocab array has its own index variable incase a word appears more than once
  int d =0;
  int e =0;
  int f =0;
  int g =0;
  int h =0;
  int k =0;
  int n=0;// the index position of the arrays in the object/subject calls 
  
  s.str(SENTENCE);// creates the string sentence into a stream 
  while(s>>words){// makes the stream into an array of words 
    for(int i=0;i<words.length();i++){
      words[i]=tolower(words[i]);// makes each word in the sentence lowercase
    }                            // so it wouldnt mess up the vocab with the first uppercase letter.
    array4[MAX]=words;// creates the array of lower case words
    MAX++;
  }

  // array4[MAX].erase(array4[MAX].length()-1);//<--------- got this idea from Rivoire code
                                            //This code erases the periode of the sentence.
  for(int i=0; i<MAX; i++){                 //suddenly stopped working... can't figure it out
    
    if(check_proper_noun(array4,i)!="..."){// each one of these fucntion calls assignes each word of
      noun[a]=check_proper_noun(array4,i);// the sentence to its corresponding Vocab and puts it  
      a++;                                // into an array. 
    }
    if(check_subject_pronoun(array4,i)!="..."){// it returns "..." if a vocab word does not match
      subject_pro[b]=check_subject_pronoun(array4,i);
      b++;//increments incase there is more than one subject pronoun
    }
    if(check_common_noun(array4,i)!="..."){
      commonnoun[c]=check_common_noun(array4,i);
      c++;//increments incase there is more than one common noun
    }
    if(check_adjective(array4,i)!="..."){
      adjective[d]=check_adjective(array4,i);
      d++;
    }
    if(check_articles(array4,i)!="..."){
      article[e]=check_articles(array4,i);
      e++;
    }
    if(check_verb(array4,i)!="..."){
      verb[f]=check_verb(array4,i);
      f++;
    }
    if(check_object(array4,i)!="..."){
      object[g]=check_object(array4,i);
      g++;
    }
    if(check_preposition(array4,i)!="..."){
      preposition[h]=check_preposition(array4,i);
      h++;
    }
    if(check_and(array4,i)!="..."){
      word_and[k]=check_and(array4,i);
      k++;
    }
  }
  //checks if the begining of the sentence starts with a correct subject. 
  if(check_for_subject(array4,noun,subject_pro,article,commonnoun,adjective,i,n) == -1){
    cout<<"Error: invalid subject"<<endl<<endl;//passes all the correct vocab pertaining to a subject.
    return false;
  }
  else{
    current_word = check_for_subject(array4,noun,subject_pro,// this insures the correct index spot. 
				     article,commonnoun,adjective,i,n)+1;
  }
  i=current_word;// updates the current index spot

  //--------SUBJECT AND SUBJECT---------
  while(check_and(array4,i)!="..."){//keeps looping as long as there is "and" at the end of subject

      if(i==MAX-1){// if the word "and" is the last word of the sentence, prints error 
      	cout<<"Error: invalid subject"<<endl<<endl;
	return false;
      }
      
      i++; //updates current index spot
      
      if(check_for_subject(array4,noun,subject_pro,article,commonnoun,adjective,i,n) == -1){
	cout<<"Error: invalid subject"<<endl<<endl;
	return false;
      }
      else{
	current_word = check_for_subject(array4,noun,subject_pro,
					 article,commonnoun,adjective,i,n)+1;
      }
      i=current_word;

  }
 
  //-----------VERB + SUBJECT-----------
  if(check_verb(array4,i)!="..."){ //checks if current index spot is a verb.

    if(i==MAX-1){// if the current index spot is the size of the array it exits the function.  
  
      print_sentence(current_word,MAX,array4);// fucntion call to print sentence
      return false;
    }      
    i++; // this updates the current spot in the array.
  }
  
  else{
    cout<<"Error: invalid predicate"<<endl<<endl;// if there is no verb it prints out an error. 
    return false;
  }
  
  if(check_preposition(array4,i)!="..."){//checks current index spot for preposition
    if(i==MAX-1){//if there is a preposition and its the size of the array it prints error. 
      cout<<"Error: invalid predicate"<<endl<<endl;
      return false;
    }
    i++;               //**************KEEPS REPEATING********************
  }
  
  if(check_for_object(array4,noun,object,//checks current index spot for object.
		      article,commonnoun,adjective,i,n)!= -1){
    if(i==MAX-1){
   
      print_sentence(current_word,MAX,array4);
      return false;
    } 
    
    i=check_for_object(array4,noun,object,article,commonnoun,adjective,i,n);
    i++;
  }
  
  if(check_preposition(array4,i)!="..."){
    if(i==MAX-1){
      cout<<"Error: invalid predicate"<<endl<<endl;
      return false;
    }
    i++;
  }
  if(check_for_object(array4,noun,object,
		      article,commonnoun,adjective,i,n)!= -1){
    if(i==MAX-1){ 
    
      print_sentence(current_word,MAX,array4);
      return false;
    }
    i= check_for_object(array4,noun,object,article,commonnoun,adjective,i,n);
    i++;
  }
  //--------VERB AND VERB----------------
  while(check_and(array4,i)!="..."){// keeps looping as long as there is a "and" after verb
   
      if(i==MAX-1){
	cout<<"Error: invalid predicate"<<endl<<endl;
	return false;
      }
      i++;
      if(check_verb(array4,i)!="..."){
	if(i==MAX-1){
	
	  print_sentence(current_word,MAX,array4);
	  return false;
	}
	i++;
	if(check_preposition(array4,i)!="..."){
	  if(i==MAX-1){
	    cout<<"Error: invalid predicate"<<endl<<endl;
	    return false;
	  }
	  i++;
	}
	if(check_for_object(array4,noun,object,
			    article,commonnoun,adjective,i,n)!= -1){
	  if(i==MAX-1){
	  
	    print_sentence(current_word,MAX,array4);
	    return true;
	  }
	  i= check_for_object(array4,noun,object,article,commonnoun,adjective,i,n);
	  i++;
	}
	if(check_preposition(array4,i)!="..."){
	  if(i==MAX-1){
	    cout<<"Error: invalid predicate"<<endl<<endl;
	    return false;
	  }
	  i++;
	}
	if(check_for_object(array4,noun,object,
			    article,commonnoun,adjective,i,n)!= -1){
	  
	  print_sentence(current_word,MAX,array4);
	  return true;
	  
	  cout<<"Error: invalid predicate"<<endl<<endl;
	  return false;
	}
	cout<<"Error: invalid predicate"<<endl<<endl;// if everything fails in the predicate section
	return false;                                // it returns a error.
      }
      cout<<"Error: invalid predicate"<<endl<<endl;
      return false;
  }
  cout<<"Error: invalid predicate"<<endl<<endl;
  return false;
}
//--------------------PRINTS SENTENCE-------------------------------------------
//This function passes "currentword" as a int, which is the array index spot where
//the object of the sentence ends. "MaxWord" is the size of the array and "Array9"
//is the array holding the sentence. The sentence returns false which just ends the 
//function. 
//--------------------------------------------------------------------------------
bool print_sentence(int CurrentWord, int MaxWord, string Array9[]){

  cout<<"Subject: ";
  for(int j=0;j<CurrentWord;j++){//cycles through the array and prints out the subj.
    cout<<Array9[j]<<" ";
  }
  cout<<endl;
  cout<<"Predicate: ";
  for(int j=CurrentWord;j<MaxWord;j++){//cycles through remainder of array and prints pred.
    cout<<Array9[j]<<" ";
  }
  cout<<endl<<endl;
  return false;
}
//---------------------------------CHECK FOR SUBJECT-------------------------------------
/* This function passes the current index spot of the sentence and checks if it corresponds
   with the vocab correctly that is passed through its parameters. If it does correspond then
   it returnes a number, which will then be used to update the current index spot for the 
   next vocab check. If no vocab matches it returnes -1. */
//--------------------------------------------------------------------------------------
int check_for_subject(string Array8[],string NOUN[], string SUBJECT_PRO[], string ARTICLE[],
                      string COMMONNOUN[], string ADJECTIVE[], int i, int n){
  for(n=0;n<4;n++){
    if(Array8[i] == NOUN[n])
      return i;
    if(Array8[i] == SUBJECT_PRO[n])
      return i;
    if(Array8[i] == ARTICLE[n] and Array8[i+1] == COMMONNOUN[n])
      return i+1;
    if(Array8[i] == ARTICLE[n] and Array8[i+1] == ADJECTIVE[n] and Array8[i+2]== COMMONNOUN[n])
      return i+2;
  }
  return -1;
} 
//------------------------------CHECK FOR OBJECT-----------------------------------------
//This functiond does the same thing as check_for_subject only but it passes a OBJECT as
//its paremeter. Although it is very similar I had to still make a seperate function to 
//ensure that check_for_subject would read the correct vocab.  
//--------------------------------------------------------------------------------------
int check_for_object(string Array9[],string NOUN1[], string OBJECT1[], string ARTICLE1[],
		     string COMMONNOUN1[], string ADJECTIVE1[], int I, int N){
    
  for(N = 0; N<4; N++){// just in case there is a word used more than once in a sentence 
    if(Array9[I] == NOUN1[N])
      return I;
    if(Array9[I] == OBJECT1[N])
      return I;
    if(Array9[I] == ARTICLE1[N] and Array9[I+1] == COMMONNOUN1[N])
      return I+1;
    if(Array9[I] == ARTICLE1[N] and Array9[I+1] == ADJECTIVE1[N] and Array9[I+2]== COMMONNOUN1[N])
      return I+2;
  }
  return -1;
}
//---------------------CHECK SPACES FUNCTION---------------------------
/*This function passes string stream which is turned into an array of chars.
  Each char is checked for white space. The function makes sure the white space
  in the beggining and end of the sentence is ignored. If there is more than one
  space between a set of words or char the function returns false and gives an error. */
//---------------------------------------------------------------------
bool check_spaces(string stream){
  
  string arr2[num];// the array of chars 
  int max1=0;// the max size of the array
  int front_spot = 0;// the front spot of the array until it hits text.
  int rear_spot = 0;// the rear spot of the array until it hits text. 
  
  for(int i=0;i<stream.length();i++){// gets the length of string stream and creates array.
    arr2[i]= stream[i];
    max1++;
  }
  while(arr2[front_spot]== " " or arr2[front_spot]=="\t"){// reads chars until it hits text.
    front_spot++;
    if(front_spot==max1){//if line is only populated by blank spaces then it returns false. 
      return false;
    }
  }
  for(int i= max1; i>front_spot; i--){//starts at end of array and reads backwards till it hits text.
    
    if(arr2[i]==" " or arr2[i]=="\n" or arr2[i]=="\t" or arr2[i]=="\0"){
      rear_spot =i;// updates the current index spot and puts it into rear_spot.
    }
    else{
      break;//exits loop if arr2[i] runs into a char/text/letter
    }
  }
  cout<<"Report for sentence"<<": ";
  
  for(int n=front_spot; n<=rear_spot; n++){//Prints out sentence without trailing and leading space.
    cout<<arr2[n];
  }
  cout<<endl;
  for(int n=front_spot; n<rear_spot; n++){//starts where text is read and ends where text stops.
    if(arr2[n] == " " and arr2[n-1] ==" " or arr2[n]== "\t"){ //checks for more than two spaces.
      cout<<"Error: invalid spacing"<<endl<<endl;
      return false;                                          
    }
  }
  return true;
}
//---------------------------CHECKS PUNCSCAPS--------------------------------------
/*Passes the string sentence and makes it into a string stream creating a array.
  The function checks the first index of the array for capitalization and the 
  last index spot for a period. if it is missing either one and fails, it returns false.*/ 
//-------------------------------------------------------------------------------- 
bool check_PuncsCaps(string sentence){

  char letter;//used to create a string of characters
  char arr1[num];// the array of characters
  int max=0;//the max size of the array
  stringstream s;// used to create a stream

  s.str(sentence);
  
  while(s >> letter){
    arr1[max]=letter;// makes an array of chars and also updates the size of the array 
    max++;
  }  
  if(arr1[0] >='a' && arr1[0] <='z'){// checks if the first index is a lowercase letter. 
    cout<<"Error: invalid capitalization"<<endl<<endl;
    return false;
  }
  if(arr1[max-1]== '.'){ }// checks the last spot of the array for a period.
  else {
    cout <<"Error: invalid punctuation"<<endl<<endl;
    return false;
  }
  return true;
}
//----------------CHECK FOR "AND"--------------------------------
//This function parameter passes the words of the sentence as an array and checks
//the word at the current index spot "x9" and checks if it is the 
//word "and". If it is not it returns "..." as a fail.
//-------------------------------------------------------------
string check_and(string Array8[], int x9){
  
  int i=0;// looks nicer if it is i
  i=x9;// current index spot
  if(Array8[i]== "and" or
     Array8[i]== "and.") return Array8[i];// checks if that index spot is the word "and"
  return "...";
}
//--------------------CHECK PREPOSITION--------------------------
/*This function passes a array and "int x8" which is the current 
  index spot of the array. It checks that current spot of the array and 
  checks if it is a preposition by comparing it to the library of words.
  If it matches a word, then it returns that word to be used in other 
  functions. If it does not match it returns "..." which cannot be used anywhere */
//---------------------------------------------------------------
string check_preposition(string Array7[], int x8){
  
  int i = 0;// declared "i" so I could use "i" instead because it looks nicer. 
  i = x8;// x8 is the current array spot being read
  if(Array7[i] == "to" or
     Array7[i] == "for" or
     Array7[i] == "with" or
     Array7[i] == "to." or
     Array7[i] == "for." or
     Array7[i] == "with.")return Array7[i];  
  return "...";
}
//----------------CHECKS OBJECT------------------------------------
//All these functions do the same thing as the function above
//----------------------------------------------------------------
string check_object(string Array6[], int x7){

  int i=0;
  i=x7;
  if(Array6[i] == "him" or
     Array6[i] == "her" or
     Array6[i] == "them" or
     Array6[i] == "me" or
     Array6[i] == "him." or
     Array6[i] == "her." or
     Array6[i] == "them." or
     Array6[i] == "me.")return Array6[i];
   return "...";
}
//-----------------CHECKS VERB-------------------------------------
string check_verb(string Array5[], int x6){

  int i =0;
  i=x6;
  if(Array5[i] == "gave" or
     Array5[i] == "ate" or
     Array5[i] == "married"or
     Array5[i] == "gave." or
     Array5[i] == "ate." or
     Array5[i] == "married.")return Array5[i];
  return "...";
}
//----------------------CHECKS ARTICLES-----------------------------
string check_articles(string Array4[], int x5){

  int i =0;
  i=x5;
  if(Array4[i] == "a" or
     Array4[i] == "the"or
     Array4[i] == "a." or
     Array4[i] == "the")return Array4[i];
  return "...";
}
//---------------------CHECKS ADJECTIVE----------------------------
string check_adjective(string Array3[], int x4){

  int i=0;
  i=x4;
  if(Array3[i] == "cute" or
     Array3[i] == "big" or
     Array3[i] == "purple" or
     Array3[i] == "cute." or
     Array3[i] == "big." or
     Array3[i] == "purple.")return Array3[i];
  return "...";
}
//-------------------CHECK COMMON NOUN------------------------------
string check_common_noun(string Array2[], int x3){

  int i = 0;
  i = x3;
  if(Array2[i] == "time" or
     Array2[i] == "kneecap" or
     Array2[i] == "puppy" or
     Array2[i] == "refrigerator" or
     Array2[i] == "time." or
     Array2[i] == "kneecap." or
     Array2[i] == "puppy." or
     Array2[i] == "refrigerator.") return Array2[i];
  return "...";
}
//--------------------CHECK SUBJECT PRONOUN---------------------------
string check_subject_pronoun(string Array1[], int x2){

  int i = 0;
  i = x2;
  if(Array1[i] == "i" or
     Array1[i] == "he" or
     Array1[i] == "they" or
     Array1[i] == "i." or
     Array1[i] == "he." or
     Array1[i] == "they.")return Array1[i];
  return "...";
}
//-------------------CHECK PROPER NOUN-------------------------------
string check_proper_noun(string Array[],int x1){

  int i =0;
  i = x1;
  if(Array[i] == "godzilla" or
     Array[i] == "spiderman" or
     Array[i] == "zeus" or
     Array[i] == "godzilla." or
     Array[i] == "spiderman." or
     Array[i] == "zeus.") return Array[i];
  return "...";
}

