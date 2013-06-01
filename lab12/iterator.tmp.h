/* Iterator function definitions - not a standalone file */

template <class T>
LList<T>::Iterator::Iterator() { current = NULL; }

template <class T>
LList<T>::Iterator::Iterator(LNode* NP) { current = NP; }

template <class T>
const T LList<T>::Iterator::operator * () const { return current->data; }

template <class T>
class LList<T>::Iterator LList<T>::Iterator::operator++() {
	current = current->next;
	return *this;
}

template <class T>
class LList<T>::Iterator LList<T>::Iterator::operator++(int) {
	Iterator tmp = *this;
	current = current->next;
	return tmp;
}

template <class T>
bool LList<T>::Iterator::operator== (const Iterator& other) const {
	return current == other.current;
}

template <class T>
bool LList<T>::Iterator::operator!= (const Iterator& other) const {
	return current != other.current;
}

template <class T>
class LList<T>::Iterator LList<T>::begin() const {
	Iterator tmp(first);
	return tmp;
}

template <class T>
class LList<T>::Iterator LList<T>::end() const {
	Iterator tmp;	// it's NULL
	return tmp;
}

