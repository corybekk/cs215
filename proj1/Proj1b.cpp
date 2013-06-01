//AUTHOR: CORY BEKKER
//CS215
//PROJECT 1
////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

string check_proper_noun(string Array[],int x1);
string check_subject_pronoun(string Array1[], int x2);
string check_common_noun(string Array2[], int x3);
string check_adjective(string Array3[], int x4);
string check_articles(string Array4[], int x5);
string check_verb(string Array5[], int x6);
string check_object(string Array6[], int x7);
string check_preposition(string Array7[], int x8);
bool check_argument(int argc, char* argv[]);
bool check_spaces(char* argv[]);
int check_for_subject(string Array8[],string NOUN, string SUBJECT_PRO,
		      string ARTICLE,string COMMONNOUN, string ADJECTIVE);
bool check_PuncsCaps(char* argv[]);

const int num = 1000;//size of all arrays 

int main(int argc, char* argv[]) {

  ifstream file;
  char sentence;
  string sentence1;
  char arr1[num];
  int i =0;
  int max=0;
  
  ////////////checks for argument/////////////////////////////////////////
  if(check_argument(argc,argv)== true){}
  else{
    return 0;
  }
  ///////////checks for spaces///////////////////////////////////////////
  if(check_spaces(argv)==true){}
  else{
    return 0;
  }
  //////////////////////checks for capitalization and punctuation/////////
  if(check_PuncsCaps(argv)==true){}
  else{
    return 0;
  }
  /////////////////checks for subject///////////////////////////////////
  
  file.open(argv[1]);
  
  stringstream s;
  string words;//// I can make this as a string, and can compare to words like godzilla.
  string array4[num];
  int w=0;
  string noun;
  string subject_pro;
  string commonnoun;
  string adjective;
  string article;
  string verb;
  string object;
  string preposition;
  int current_word;
  
  while(getline(file,sentence1)){
    s.str(sentence1);
    while(s>>words){
      array4[w]=words;
      w++;
    }
    s.clear();
  }
  noun =  check_proper_noun(array4,w);
  subject_pro = check_subject_pronoun(array4,w);
  commonnoun = check_common_noun(array4,w);
  adjective = check_adjective(array4,w);
  article = check_articles(array4,w);
  verb= check_verb(array4,w);
  object= check_object(array4,w);
  preposition = check_preposition(array4,w);
 
  if(check_for_subject(array4,noun,subject_pro,article,commonnoun,adjective) == -1){
    cout<<"missing subject, No0o0o0 :(!!!"<<endl;
  }
  else{
    current_word = check_for_subject(array4,noun,subject_pro,
				     article,commonnoun,adjective)+1;
  }


  /////////////////////////////////////////////////////////////////////////
  int LessThanOne = w-1;

  for(int i=current_word; i<w; i++){

    if(check_verb(array4,i)!="..."){//reads the same verb twice
    }
    else{ 
      cout<<"missing predicate"<<endl;
    }
  }



  ////////////////////////////////////////////////////////////////////////

  return 0;
  
}

////////////////////////FUNCTIONS///////////////////////////////////////////
int check_for_subject(string Array8[],string NOUN, string SUBJECT_PRO, string ARTICLE,
                      string COMMONNOUN, string ADJECTIVE){
  int i=0;
  if(Array8[i] == NOUN)
    return i;
  if(Array8[i] == SUBJECT_PRO)
    return i;
  if(Array8[i] == ARTICLE and Array8[i+1] == COMMONNOUN)
    return i+1;
  if(Array8[i] == ARTICLE and Array8[i+1] == ADJECTIVE and Array8[i+2]== COMMONNOUN)
    return i+2;
  else
    return -1;
}
///////////////////////////////CHECK ARGUMENT////////////////////////////////////////
bool check_argument(int argc, char* argv[]){

  ifstream file;

  if(argc > 2){
    cout<< "Too many command-line inputs given."<<endl;
    return false;
  }
  if(argc < 2){
    cout<<"No file name entered."<<endl;
    return false;
  }

  file.open(argv[1]);

  if(file.fail()){
    cout<<"Could not open file."<<endl;
    file.close();
    return false;
  }
  else{
    file.close();
    return true;
  }
}
///////////////////////////CHECK SPACES FUNCTION////////////////////////////////
bool check_spaces(char* argv[]){
  
  ifstream file;
  char arr1[num];
  string arr2[num];
  char next;
  int max1=0;
  int front_spot = 0;
  int rear_spot = 0;
  
  file.open(argv[1]);
  
 while((next = file.get()) != '\n'){
   arr2[max1]=next;//creates array
   max1++;//size of array
 }
 while(arr2[front_spot]== " "or arr2[front_spot]=="\n"or arr2[front_spot]=="\t"){
   front_spot++;// reads all white space before first char
   if(front_spot==max1){//if file is empty, closes program
     return false;
   }
 }
 for(int i= max1; i>front_spot; i--){
   
   if(arr2[i]==" " or arr2[i]=="\n" or arr2[i]=="\t" or arr2[i]=="\0"){
     rear_spot =i;// always looking at a empty spot i -1.
   }
   else{
     break;//exits loop if arr2[i] runs into a char
   }
 }
 cout<<"Report for sentence: ";
 for(int n=front_spot; n<=rear_spot; n++){//Prints out sentence
   cout<<arr2[n];
 }
 cout<<endl;
 for(int n=front_spot; n<rear_spot; n++){// starts where the first char is in the txt.
   if(arr2[n] == " " and arr2[n-1] ==" " or arr2[n]== "\t"){ // checks for...
     cout<<"ERROR: invalid spacing"<<endl;
     return false;                                          // extra spaces and tabs.
   }
 }
 file.close();
 return true;
}
 ///////////////////////////////////////////////////////////////////////////////////////
bool check_PuncsCaps(char* argv[]){
  
  ifstream file;
  char sentence;
  char arr1[num];
  int max=0;
  int i=0;

  file.open(argv[1]);
 
 while(file >> sentence){
  arr1[i]=sentence;
  max = i++;
 }
 if(arr1[0] >='a' && arr1[0] <='z'){
  cout<<"ERROR: invalid capitalization"<<endl;
  //return false;
 }
 if(arr1[max]== '.'){ }
 else {
   cout <<"ERROR: invalid punctuation"<<endl;
   // return false;
 }
 file.close();
 return true;
}
//////////////////////////////////////////////////////////////////////////////////////

string check_preposition(string Array7[], int h){

  for(int i=0; i<=h; i++){
    if(Array7[i] == "to" or
       Array7[i] == "for" or
       Array7[i] == "with")return Array7[i];
  }
  return "...";
}
///////////////////////////////////////////////////
string check_object(string Array6[], int g){

  for(int i=0; i<=g; i++){
    if(Array6[i] == "him" or
       Array6[i] == "her" or
       Array6[i] == "them" or
       Array6[i] == "me" or
       Array6[i] == "him." or
       Array6[i] == "her." or
       Array6[i] == "them." or
       Array6[i] == "me.")return Array6[i];
  }
  return "...";
}
///////////////////////////////////////////////////
string check_verb(string Array5[], int f){

  for(int i=0; i<=f; i++){
    if(Array5[i] == "gave" or
       Array5[i] == "ate" or
       Array5[i] == "married" or
       Array5[i] == "gave." or
       Array5[i] == "ate." or
       Array5[i] == "married.")return Array5[i];
  }
  return "...";
}
/////////////////////////////////////////////////////
string check_articles(string Array4[], int e){

  for(int i=0; i<=e; i++){
    if(Array4[i] == "a" or
       Array4[i] == "the" or
       Array4[i] == "a." or
       Array4[i] == "the.")return Array4[i];
  }
  return "...";
}
//////////////////////////////////////////////////////
string check_adjective(string Array3[], int d){

  for(int i=0; i<=d; i++){
    if(Array3[i] == "cute" or
       Array3[i] == "big" or
       Array3[i] == "purple" or
       Array3[i] == "cute." or
       Array3[i] == "big." or
       Array3[i] == "purple.")return Array3[i];
  }
  return "...";
}
////////////////////////////////////////////////////////
string check_common_noun(string Array2[], int c){

  for( int i=0; i<=c; i++){
    if(Array2[i] == "time" or
       Array2[i] == "kneecap" or
       Array2[i] == "puppy" or
       Array2[i] == "refrigerator" or
       Array2[i] == "time." or
       Array2[i] == "kneecap." or
       Array2[i] == "puppy." or
       Array2[i] == "refrigerator.") return Array2[i];
  }
  return "...";
}
////////////////////////////////////////////////////////
string check_subject_pronoun(string Array1[], int b){

  for(int i=0; i<=b; i++){
    if(Array1[i] == "I" or
       Array1[i] == "he" or
       Array1[i] == "her" or
       Array1[i] == "they"or
       Array1[i] == "I." or
       Array1[i] == "he." or
       Array1[i] == "her." or
       Array1[i] == "they.")return Array1[i];
  }
  return "...";
}
//////////////////////////////////////////////////////
string check_proper_noun(string Array[],int a){

  for(int i =0; i<=a; i++){
    if(Array[i] == "godzilla" or
       Array[i] == "spiderman" or
       Array[i] == "zeus" or
       Array[i] == "godzilla." or
       Array[i] == "spiderman." or
       Array[i] == "zeus.") return Array[i];
  }
  return "...";
}


















