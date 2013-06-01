//AUTHOR: CORY BEKKER
//CS215
//PROJECT 1

////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

string check_proper_noun(string Array[],int a);
string check_subject_pronoun(string Array1[], int b);
string check_common_noun(string Array2[], int c);
string check_adjective(string Array3[], int d);
string check_articles(string Array4[], int e);
string check_verb(string Array5[], int f);
string check_object(string Array6[], int g);
string check_preposition(string Array7[], int h);

int check_for_subject(string Array8[],string NOUN, string SUBJECT_PRO, 
			 string ARTICLE,string COMMONNOUN, string ADJECTIVE);

bool check_for_predicate(string Array9[],int C,string VERB,string PREPOSITION,
                         string OBJECT,string NOUN1,string SUBJECT_PRO1,
                         string ARTICLE1,string COMMONNOUN1,string ADJECTIVE1);
                      
/*string check_for_object(string Array10[],int C1, string NOUN1, string OBJECT1,
			string ARTICLE1,string COMMONNOUN1, string ADJECTIVE1);*/
bool check_argument(int argc, char* argv[]);


const int num = 1000;

int main(int argc, char* argv[]) {

  ifstream file;
  char sentence;
  string sentence1;
  char arr1[num];
  string arr2[num];
  char next;
  int i =0;
  int max =0;
  int max1=0;
  int front_spot = 0;
  int rear_spot = 0;
  stringstream f;

  if(check_argument(argc,argv)== true){}
  else{
    return 0;
  }

  /////////////CHECKS SPACES/////////////////////////////////////////////////
  /*  while((next = file.get()) != EOF){
    arr2[max1]=next;//creates array
    max1++;//size of array
    }*/

  getline(file,sentence1);
  f.str(sentence1);
  while(f>>next){
    cout<<next;
  }

  while(arr2[front_spot]== " "or arr2[front_spot]=="\n"or arr2[front_spot]=="\t"){
    front_spot++;// reads all white space before first char
    if(front_spot==max1){//if file is empty, closes program
      return 0;
    }
  }
  for(int i= max1; i>front_spot; i--){
    rear_spot=i;
    if(arr2[i]==" " or arr2[i]=="\n" or arr2[i]=="\t" or arr2[i]=="\0"){
    }
    else{
      break;//exits loop if arr2[i] runs into a char
    }
  }
  cout<<"Report for sentence: ";
  for(int n=front_spot; n<rear_spot; n++){//Prints out sentence
    cout<<arr2[n];
  }
  cout<<endl;
  for(int n=front_spot; n<rear_spot; n++){// starts where the first char is in the txt.
    if(arr2[n] == " " and arr2[n-1] ==" " or arr2[n]== "\t"){ // checks for...
      cout<<"ERROR: invalid spacing"<<endl;                   // extra spaces and tabs.
    }
  }
  ////////close and open file//////////////////////////////////////////////////
  file.close();
  file.open(argv[1]);
  ///////////////creates array of chars////////////////////////////////////////
  while(file >> sentence){
    arr1[i]=sentence;
    max = i++;
  }
  if(arr1[0] >='a' && arr1[0] <='z'){
    cout<<"ERROR: invalid capitalization"<<endl;
  }
  ////////////checks for period/////////////////////////////////////////////
  if(arr1[max]== '.'){ }
  else {
    cout <<"ERROR: invalid punctuation"<<endl;
  }
  file.close();

  
  
  file.close();
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
  int current_word=0;
  char letters;
  char wordz[num];

  while(getline(file,sentence1)){
    s.str(sentence1);
    while(s>>words){
      ///////      
      /*   char wordz;
      wordz=words;// cant change string to char
      for(int i=0;i<wordz.length(); i++){
	wordz[i]=tolower(wordz[i]);      
	}*/
      ///////
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

  cout<<"the noun:           "<<noun<<endl;
  cout<<"the subject pronoun:"<<subject_pro<<endl;
  cout<<"the commonnoun:     "<<commonnoun<<endl;
  cout<<"the adjective:      "<<adjective<<endl;
  cout<<"the article:        "<<article<<endl;
  cout<<"the verb:           "<<verb<<endl;
  cout<<"The object:         "<<object<<endl;
  cout<<"The Preposition:    "<<preposition<<endl;

  if(check_for_subject(array4,noun,subject_pro,article,commonnoun,adjective) == -1){
    cout<<"missing subject, DAMMIT ALL!!!"<<endl;
  }
  else{
    current_word = check_for_subject(array4,noun,subject_pro,
				     article,commonnoun,adjective);
 }
  /*
  if(check_for_predicate(array4,current_word,verb,preposition,
			 object,noun,subject_pro,article,commonnoun,adjective)==true){
    cout<<"Correct predicate"<<endl;
  }

   else{
   cout<<"missing predicate, DAMMIT ALL!!!"<<endl;
   }
  */ 
     return 0;
}























//////////////////CHECK ARUGMENTS//////////////////////////////
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
///////////////////////////////////////////////////////////////////
string check_proper_noun(string Array[],int a){
 
  for(int i =0; i<a; i++){
    if(Array[i] == "godzilla" or  
       Array[i] == "spiderman" or
       Array[i] == "zeus" or
       Array[i] == "godzilla." or
       Array[i] == "spiderman." or
       Array[i] == "zeus.") return Array[i];
  }
   return "...";
}
////////////////////////////////////////////////////////
string check_subject_pronoun(string Array1[], int b){

  for(int i=0; i<b; i++){
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
////////////////////////////////////////////////////////
string check_common_noun(string Array2[], int c){

  for( int i=0; i<c; i++){
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
//////////////////////////////////////////////////////
string check_adjective(string Array3[], int d){

  for(int i=0; i<d; i++){
    if(Array3[i] == "cute" or
       Array3[i] == "big" or
       Array3[i] == "purple" or
       Array3[i] == "cute." or
       Array3[i] == "big." or
       Array3[i] == "purple.")return Array3[i];
  }
  return "...";
}
/////////////////////////////////////////////////////
string check_articles(string Array4[], int e){

  for(int i=0; i<e; i++){
    if(Array4[i] == "a" or
       Array4[i] == "the" or
       Array4[i] == "a." or
       Array4[i] == "the.")return Array4[i];
  }
  return "...";
}
///////////////////////////////////////////////////
string check_verb(string Array5[], int f){

  for(int i=0; i<f; i++){
    if(Array5[i] == "gave" or
       Array5[i] == "ate" or
       Array5[i] == "married")return Array5[i];
  }
  return "...";
}
///////////////////////////////////////////////////
string check_object(string Array6[], int g){

  for(int i=0; i<g; i++){
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
/////////////////////////////////////////////////////
string check_preposition(string Array7[], int h){
  
  for(int i=0; i<h; i++){
    if(Array7[i] == "to" or
       Array7[i] == "for" or
       Array7[i] == "with")return Array7[i];
  }
  return "...";
}
/////////////////////////////////////////////////////
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


///////////////////////////////////////////////////////
bool check_for_predicate(string Array9[],int C,string VERB,string PREPOSITION,
			 string OBJECT,string NOUN1,string SUBJECT_PRO1,
			 string ARTICLE1,string COMMONNOUN1,string ADJECTIVE1){
  
  /* Array9[C+1]==VERB and Array9[C+2]==OBJECT  
     and Array9[C+3]==PREPOSITION and Array9[C+4]==OBJECT);*/
  
  //chcks for verb+Preposition+Object
  if(Array9[C+1]==VERB and Array9[C+2]==PREPOSITION and Array9[C+3]==ARTICLE1 and
     Array9[C+4]==ADJECTIVE1 and Array9[C+5]==COMMONNOUN1){
    return true;
  }
    else{ 
      cout<<Array9[C+1]<<endl;
      cout<<Array9[C+2]<<endl;
      cout<<Array9[C+3]<<endl;
      cout<<Array9[C+4]<<endl; 
      cout<<Array9[C+5]<<endl;    
      cout<<VERB<<endl;
      cout<<PREPOSITION<<endl;
      cout<<ARTICLE1<<endl;
      cout<<ADJECTIVE1<<endl;
      cout<<COMMONNOUN1<<endl;      
      
      return false;
    }
  // }
  /*  if(Array9[C+1]==VERB and Array9[C+2]==PREPOSITION and Array9[C+3]==ARTICLE1){
    if(Array9[C+4]==COMMONNOUN1)return true;
    else return false;
  }

    if(Array9[C+1]==VERB and Array9[C+2]==PREPOSITION and Array9[C+3]==SUBJECT_PRO1)
      return true;
    if(Array9[C+1]==VERB and Array9[C+2]==PREPOSITION and Array9[C+3]==NOUN1)
      return true;

    //checks for verb+Object
    if(Array9[C+1]==VERB and Array9[C+2]==ARTICLE1 and Array9[C+3]==ADJECTIVE1 and 
       Array9[C+4]==COMMONNOUN1)return true;
    if(Array9[C+1]==VERB and Array9[C+2]==ARTICLE1 and Array9[C+3]==COMMONNOUN1)return true;
    if(Array9[C+1]==VERB and Array9[C+2]==SUBJECT_PRO1)return true;
    if(Array9[C+1]==VERB and Array9[C+2]==NOUN1)return true;

    //Checks for verb
	 if(Array9[C+1]==VERB) return true;
  
  else
    return false;

  */
}
////////////////////////////////////////////////////
/*string check_for_object(string Array10[],int C1, string NOUN1, string OBJECT1,
			 string ARTICLE1,string COMMONNOUN1, string ADJECTIVE1){
  
  if(Array10[C+2]==NOUN1)
   
  if(Array10[C+2]==OBJECT1)
   
  if(Array10[C+2]==ARTICLE1 and Array10[C+3]==COMMONNOUN1)
   
  if(Array10[C+2]==ARTICLE1 and Array10[C+3]==ADJECTIVE1 and Array10[C+4]==COMMONNOUN1)
   
  else
  return "no";
}
*/
/////////////////////////////////////////////////////////
/* while((next = file.get()) != EOF){
    arr2[n]=next;///// creates array
    n++;
    max1++;//Max size of the array
    }*/
