/* -------------------------------------------------------------
 * CS 215 Project 1
 * Suzanne Rivoire
 * 
 * Parses a file of sentences and looks for errors in punctuation,
 * spacing, capitalization, grammar, and spelling.
 * ------------------------------------------------------------- */
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cassert>
using namespace std;

// ------------- DATA TYPES --------------

// Specialized data type -- could do the same thing by definining
// integer constants
enum PhraseType{ NONE, PREP_PHRASE, OBJECT, BAD };

// For storing ongoing information about a subject, object, etc.
struct Phrase {
	string phrase;	// the phrase itself
	bool phrase_complete; // whether it's complete as is
	bool valid_so_far; // whether this could be the beginning of a valid subject, object, etc.
};

// ------------- PROTOTYPES --------------
void ProcessCmdArgs(ifstream& infile, int argc, char* argv[]);

// Grabs next non-whitespace sentence
bool GetNextSentence(ifstream& infile, string& sentence);

// Helper functions for stripping leading and trailing whitespace
int GetFirstPos(string sentence);
int GetLastPos(string sentence);

// Check for spacing, capitalization, punctuation errors
bool CheckAndRemovePunctuation(string& sentence);
bool CheckSpacing(string sentence);
bool CheckCapitalization(string sentence);

// Main function for parsing subject and predicate
void ParseSentence(string sentence);

// Helper functions for extracting words from streams
string GetWord(stringstream& str);

Phrase GetSubject(stringstream& str);
Phrase GetPredicate(stringstream& str);

Phrase ParseNounPhrase1(string word, bool isSubject);
void ParseNounPhrase2(stringstream& str, Phrase& phr);
Phrase GetVerb(string word);

PhraseType AddPrepOrObject(stringstream& str, Phrase& phr, bool prep_ok, bool obj_ok);

// Identify the different parts of speech
bool IsProperNoun(string word);
bool IsSubjPronoun(string word);
bool IsObjPronoun(string word); 
bool IsArticle(string word, bool isSubject); 
bool IsCommonNoun(string word); 
bool IsAdjective(string word); 
bool IsVerb(string word); 
bool IsPreposition(string word); 

// ------------- MAIN --------------
int main(int argc, char* argv[] ) {
	ifstream infile;	// For reading the file of sentences
	string sentence;	// Most recent sentence read from file
	
	ProcessCmdArgs(infile, argc, argv);
	
	// Read in each non-whitespace sentence from the file
	while(GetNextSentence(infile, sentence)) {
		
		// Print the report header
		cout << "\nReport for sentence: " << sentence << endl;
		
		// Check for errors
		if (CheckAndRemovePunctuation(sentence) == false) {
			cout << "Error: invalid punctuation\n";
		}
		else if(CheckSpacing(sentence) == false) {
			cout << "Error: invalid spacing\n";
		}
		else if(CheckCapitalization(sentence) == false) {
			cout << "Error: invalid capitalization\n";
		}
		else ParseSentence(sentence);
	}
	
	infile.close();
	return 0;
}

/* -------------------------------------------------------------
 * ProcessCmdArgs: handle the command-line arguments passed to main
 *
 * Input parameters: ifstream variable for input file,
 *    the argc and argv that were passed to main
 * Checks that:
 *    1. There is exactly one command-line argument
 *    2. That argument is the name of a file that can be opened for reading
 * Exits with error if these 2 conditions are not true.
 *
 * Finally, it opens the file for reading using the ifstream parameter
 * that was passed in.
 * ------------------------------------------------------------- */
void ProcessCmdArgs(ifstream& infile, int argc, char* argv[]) {
	
	// Check command-line args first to avoid accessing nonexistent memory
	if (argc != 2) {
		cerr << "Error: this program takes one command-line argument.\n";
		exit(1);
	}
	
	// Try to open the file using the provided filename
	infile.open(argv[1]);
	
	// Exit with error if it doesn't open
	if (infile.fail()) {
		cerr << "Error: could not open " << argv[1] << ".\n";
		exit(1);
	}
	
}

/* -------------------------------------------------------------
 * GetNextSentence: grab the next non-whitespace sentence from file
 *
 * Input parameters: 
 *   1. The file to read from
 *   2. The string variable to read into
 *
 * Returns TRUE if it was able to read a non-whitespace line from the file
 * and copies that line (minus leading and trailing whitespace) into sentence.
 * ------------------------------------------------------------- */
bool GetNextSentence(ifstream& infile, string& sentence) {
	string line;     // temp variable for reading lines from the file
 	int firstPos;    // position of first non-whitespace character
	int lastPos;     // position of last non-whitespace character
	
	do {
		// see if there are any lines left in the file at all
		getline(infile, line);
		if (infile.fail()) {
			return false;
		}
		
		firstPos = GetFirstPos(line);
		
	} while (firstPos == -1);	// if this line was whitespace, look for another
	
	lastPos = GetLastPos(line);
	
	// Exit with error if LastPos is -1.  Since we already found
	// text above, we have a bug if we can't find it here too.
	assert (lastPos != -1);
	
	// Copy the line (omitting leading and trailing whitespace) into sentence
	sentence = line.substr(firstPos, lastPos-firstPos+1);
	
	return true;
}

/* -------------------------------------------------------------
 * GetFirstPos: return the position of the first non-whitespace
 * character in a sentence (or -1 if it's all whitespace)
 *
 * Input parameter: the sentence
 * ------------------------------------------------------------- */
int GetFirstPos(string sentence) {
	int position = 0;	// current position in sentence
	
	// Loop through the line looking for the first non-whitespace character
	
	// Keep looping until (a) we hit the end of the line or (b) we find text and return
	while (position < sentence.length()) {
		if (isspace(sentence[position])) {
			position++; // if it's a space, keep looking
		}
		else {
			return position;
		}
	}
	
	// If we get here, the sentence contained only whitespace
	return -1;
}

/* -------------------------------------------------------------
 * GetLastPos: return the position of the last non-whitespace
 * character in a sentence (or -1 if it's all whitespace)
 *
 * Input parameter: the sentence
 * ------------------------------------------------------------- */
int GetLastPos(string sentence) {
	int position = sentence.length()-1; // current position in sentence
	
	// Loop through the line looking for the first non-whitespace character
	
	// Keep looping until (a) we hit the beginning of the line or (b) we find text and return
	while (position >= 0) {
		if (isspace(sentence[position])) {
			position--; // if it's a space, keep looking
		}
		else {
			return position;
		}
	}
	
	// If we get here, the sentence contained only whitespace
	return -1;
}

/* -------------------------------------------------------------
 * CheckAndRemovePunctuation
 *
 * Input parameter: a sentence with leading and trailing
 * whitespace removed
 *
 * Checks to be sure there's punctuation at the end
 * Returns true if there's punctuation, otherwise false
 *
 * Modifies the original sentence to remove the punctuation
 *
 * ------------------------------------------------------------- */
bool CheckAndRemovePunctuation(string& sentence) {
	assert(!isspace(sentence[0]) && !isspace(sentence[sentence.length()-1]));
	
	int length = sentence.length();
	
	if (sentence[length-1] != '.') {
		return false;
	}
	
	// Strip out the last character
	sentence.erase(length-1, 1);
	
	return true;
}

/* -------------------------------------------------------------
 * CheckSpacing
 *
 * Input parameter: a sentence with leading and trailing
 * whitespace removed
 *
 * Checks to be sure that the words are separated by a single
 * space
 *
 * ------------------------------------------------------------- */
bool CheckSpacing(string sentence) {
	
	// Be sure leading and trailing whitespace have been removed
	assert(!isspace(sentence[0]) && !isspace(sentence[sentence.length()-1]));
	
	for (int i=0; i < sentence.length(); i++) {
		if (sentence[i] == '\t') {
			return false;	// tabs are not OK
		}
		
		// Since leading and trailing whitespace have been removed,
		// it's not possible for sentence[i] to be the last character,
		// so we're not going off the end of the sentence
		
		// Instead we check for 2 consecutive spaces
		if (sentence[i] == ' ' && sentence[i+1] == ' ') {
			return false;
		}
	}
	return true;
}

/* -------------------------------------------------------------
 * CheckCapitalization
 *
 * Input parameter: a sentence with leading and trailing
 * whitespace removed
 *
 * Checks to be sure that the first letter is capitalized
 * Returns true if so, otherwise false
 *
 * ------------------------------------------------------------- */
bool CheckCapitalization(string sentence) {
	assert(!isspace(sentence[0]) && !isspace(sentence[sentence.length()-1]));
	
	return(isupper(sentence[0]));
}

/* -------------------------------------------------------------
 * ParseSentence
 *
 * Input parameter: a sentence with leading and trailing
 * whitespace removed and punctuation stripped
 *
 * Either prints subject and predicate or prints an error
 * ------------------------------------------------------------- */
void ParseSentence(string sentence) {
	
	Phrase subject, predicate; // the subject and predicate of the sentence
	stringstream sentstr;	   // stream to read words of sentence
	sentstr.str(sentence);
	
	subject = GetSubject(sentstr);
	predicate = GetPredicate(sentstr);
	
	if (subject.phrase_complete == false) {
		cout << "Error: invalid subject\n";
	}
	else if (predicate.phrase_complete == false) {
		cout << "Error: invalid predicate\n";
	}
	else {
		cout << "Subject: " << subject.phrase << endl;
		cout << "Predicate: " << predicate.phrase << endl;
	}
}

/* -------------------------------------------------------------
 * GetSubject
 * 
 *
 * Look through a stringstream for a subject
 *
 * Parameters:
 *  The stringstream to look through
 *
 * Returns info about the phrase as a whole:
 * - phrase: the phrase itself
 * - phrase_complete: whether it is a complete subject/object
 * if phrase_complete == false, disregard the phrase itself
 * ------------------------------------------------------------- */
Phrase GetSubject(stringstream& str) {
	Phrase phr;	// phrase with info about subject

	phr = ParseNounPhrase1(GetWord(str), true);
	if (!phr.valid_so_far or phr.phrase_complete) {
		return phr;
	}
	
	ParseNounPhrase2(str, phr);
	return phr;
}

/* -------------------------------------------------------------
 * GetWord
 *
 * Helper function to read a word from a stream
 * Input parameter: the stream
 *
 * Returns the word that was read, or "" if no word could be read
 * ------------------------------------------------------------- */
string GetWord(stringstream& str) {
	string word = "";
	str >> word;
	//cout << word << endl;
	return word;
}


/* -------------------------------------------------------------
 * ParseNounPhrase1
 *
 * Handles the first word of a noun phrase
 *
 * Parameters:
 *  The word
 *  A bool that should be true if we're looking for a subject
 *
 * Returns a phrase with information about the first word
 * and subject as a whole
 * ------------------------------------------------------------- */
Phrase ParseNounPhrase1(string word, bool isSubject) {
	Phrase phr;		// For keeping track of the phrase
	string lc_word; // tmpword converted to lowercase
	
	phr.valid_so_far = true;
	phr.phrase_complete = false;
	
	// A proper noun or pronoun is valid in itself
	if (IsProperNoun(word) or isSubject && IsSubjPronoun(word) or !isSubject && IsObjPronoun(word)) {
		phr.phrase_complete = true;
	}

	// If it's not an article, then there's a subject error
	else if (!IsArticle(word, isSubject)) {
		phr.valid_so_far = false;
	}
	
	phr.phrase = word;
	return phr;
}

/* -------------------------------------------------------------
 * ParseNounPhrase2
 *
 * Look through a stringstream for the second (and third)
 * words of a noun phrase
 *
 * Parameters:
 *  The stringstream to look through
 *  A phrase to update
 *
 * Updates the phrase that was passed to it
 * ------------------------------------------------------------- */
void ParseNounPhrase2(stringstream& str, Phrase& phr) {
	string tmpword;	// read next word into this variable
	
	if (str >> tmpword) {
		if (IsAdjective(tmpword)) {
			phr.phrase += " " + tmpword;
			
			// still valid so far but not complete: read another word
			str >> tmpword;
		}
		
		// a common noun will complete the subject, with 
		// or without an adjective
		if (!str.fail() && IsCommonNoun(tmpword)) {
			phr.phrase += " " + tmpword;
			phr.phrase_complete = true;
		}
	}
}

/* -------------------------------------------------------------
 * GetPredicate
 *
 * Look through a stringstream for a predicate
 *
 * Parameter: the stringstream to look through
 *
 * Returns the noun phrase found or the empty string
 * if it couldn't parse a noun phrase
 * ------------------------------------------------------------- */
Phrase GetPredicate(stringstream& str) {
	Phrase pred;	// The predicate as a whole
	string tmpword; // Temporary variable for reading a word
	PhraseType result; // The type of object parsed
	
	// First, look for verb
	pred = GetVerb(GetWord(str));

	// Then, look for any object
	result = AddPrepOrObject(str, pred, true, true);

	// Keep reading until we get to the end of the sentence
	// or to a bad object
	while (result != NONE && result != BAD) {

		// If it was a prepositional phrase,
		// call again to make sure there's nothing
		// left over
		if (result == PREP_PHRASE) {
			result = AddPrepOrObject(str, pred, false, false);
		}
		// If it was a regular object, call again to see if there's
		// a prep phrase
		else if (result == OBJECT) {
			result = AddPrepOrObject(str, pred, true, false);
		}
	}

	return pred;
}

/* -------------------------------------------------------------
 * GetVerb
 * 
 * Input parameter: a word
 *
 * Returns a Phrase object with valid/complete flags set
 * if the word is a verb
 * ------------------------------------------------------------- */
Phrase GetVerb(string word) {
	Phrase phr;		// For keeping track of the predicate
	
	phr.valid_so_far = phr.phrase_complete = false;
	
	// It had better be a verb, which is a complete predicate in itself
	if (IsVerb(word)) {
		phr.phrase_complete = true;
		phr.valid_so_far = true;
		phr.phrase = word;
		
	}
	
	return phr;
}

/* -------------------------------------------------------------
 * AddPrepOrObject
 * 
 * Input parameter: 
 * - a stringstream to read from
 * - a phrase to add the object to
 * - a flag that is TRUE if a prepositional phrase is OK here
 * - a flag that is TRUE if a direct object is OK here
 *
 * Modifies the Phrase object that was passed to it
 * 
 * Returns a code for the type of phrase it read
 * ------------------------------------------------------------- */
PhraseType AddPrepOrObject(stringstream& str, Phrase& phr, bool prep_ok, bool obj_ok) {
        string word="";	   // the word read from the stream
	string curr_phrase = phr.phrase; // the phrase so far -- will overwrite
	bool prep = false; // true if the first word is a preposition

        str >> word;

	// No object
        if (word == "") {
		return NONE;
	}

	// Does it start with a preposition?
	if (IsPreposition(word) && prep_ok) {
		curr_phrase += " " + word;
		str >> word;
		if (str.fail()) {
			phr.valid_so_far = phr.phrase_complete = false;
		}
		else {
			prep = true;
		}
	}

	// Is it OK to have an object here?
	if (prep or obj_ok) {
		phr = ParseNounPhrase1(word, false);
        	if (phr.valid_so_far and !phr.phrase_complete) {
        		ParseNounPhrase2(str, phr);
		}
		phr.phrase = curr_phrase + " " + phr.phrase;
		if (phr.phrase_complete && prep) {
			return PREP_PHRASE;
		}
		if (phr.phrase_complete && !prep) {
			return OBJECT;
		}

	}
	phr.valid_so_far = phr.phrase_complete = false;
	return BAD;
}

/* -------------------------------------------------------------
 * VOCABULARY
 *
 * Functions that check to see if a word is in the vocabulary
 * ------------------------------------------------------------- */

/* IsProperNoun: returns true if the input string is a proper noun */
bool IsProperNoun(string word) {
	return (word == "Godzilla" || word == "Spiderman" || word == "Zeus");
}

/* IsSubjPronoun: returns true if the input string is a subject pronoun */
bool IsSubjPronoun(string word) {
	// subject pronouns will be capitalized
	return (word == "I" || word == "He" || word == "She" || word == "They");
}

/* IsObjPronoun: returns true if the input string is an object pronoun */
bool IsObjPronoun(string word) {
	return (word == "me" || word == "him" || word == "her" || word == "them");
}

/* IsArticle: returns true if the input string is an article 
 If it's the subject, compares w/ lowercase first letter
 */
bool IsArticle(string word, bool isSubject) {
	if (isSubject) {
		word[0] = tolower(word[0]);
	}
	return (word == "a" || word == "the");
}

/* IsCommonNoun: returns true if the input string is a common noun */
bool IsCommonNoun(string word) {
	return (word == "time" || word == "kneecap" || word == "puppy" || word == "refrigerator");
}

/* IsAdjective: returns true if the input string is an adjective */
bool IsAdjective(string word) {
	return (word == "cute" || word == "big" || word == "purple");
}

/* IsVerb: returns true if the input string is a verb */
bool IsVerb(string word) {
	return (word == "gave" || word == "ate" || word == "married");
}

/* IsPreposition: returns true if the input string is a preposition */
bool IsPreposition(string word) {
	return (word == "to" || word == "for" || word == "with");
}

