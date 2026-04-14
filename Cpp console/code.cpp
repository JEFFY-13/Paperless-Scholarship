#include <iostream> 
#include <string> 
using namespace std; 
class PaperlessScholarship { 
private: 
  struct data { 
    string name; 
    string gender; 
    int hsc_mark; 
    float parent_income; 
    long int aadhar_no; 
    long int account_no; 
    struct data *nxt, *prev; 
  } *head, *p, *temp, *tail; 
public: 
  PaperlessScholarship() { 
    head = NULL; 
    p = NULL; 
    temp = NULL; 
    tail = NULL; 
    }  
  void insert(string, string, int, float, long int, long int); 
  void displayf(); 
  void displayr(); 
  void deletedata(string); 
  void modify(string, string); 
  void search(string); 
  void insertatbeg(string, string, int, float, long int, long int); 
  void deletebeg(); 
}; 
int main() { 
  PaperlessScholarship ps; 
  ps.insert("Rani", "F", 566, 720000, 908667576, 6745459); 
  ps.insert("Fabina", "F", 543, 767658, 876764435, 9877685); 
  ps.insert("Teddy", "F", 543, 767658, 876764435, 9877685); 
  ps.insert("Priya", "F", 543, 767658, 876764435, 9877685); 
  ps.insert("Dharshini", "F", 543, 767658, 876764435, 9877685); 
  ps.displayf(); 
  cout << "\nDisplaying in reverse order:\n"; 
  ps.displayr(); 
  ps.deletedata("Teddy"); 
  cout << "\nContents after deletion:\n"; 
  ps.displayf(); 
  ps.modify("Fabina", "Celesta"); 
  cout << "\nContents of list after modification:\n"; 
  ps.displayf(); 
  cout << "\nSearching:\n"; 
  ps.search("Celesta"); 
  ps.insertatbeg("Rakshi", "F", 543, 767658, 876764435, 9877685); 
  cout << "\nContents of list after insertion @ first:\n"; 
  ps.displayf(); 
  ps.deletebeg(); 
  cout << "\nContents of list after deletion @ first:\n"; 
  ps.displayf(); 
  return 0; 
} 

void PaperlessScholarship::insert(string name, string gender, int hsc_mark, float parent_income, long int aadhar_no, long int account_no) { 
  temp = new struct data; 
  temp->name = name; 
  temp->gender = gender; 
  temp->hsc_mark = hsc_mark; 
  temp->parent_income = parent_income; 
  temp->aadhar_no = aadhar_no; 
  temp->account_no = account_no; 
  temp->nxt = NULL; 
  temp->prev = NULL; 
  if (head == NULL) { 
    head = temp; 
    return; 
  } 
  p = head; 
  while (p->nxt != NULL) 
    p = p->nxt; 
  p->nxt = temp; 
  temp->prev = p; 
  tail = temp; 
} 
void PaperlessScholarship::displayf() { 
  if (head == NULL) { 
    cout << "Sorry. The list is empty."; 
    return; 
  } 
  p = head;    
  while (p != NULL) { 
    cout << "NAME: " << p->name << "\t --> GENDER: " << p->gender << "\t --> HSC Mark: " << p->hsc_mark << "\t --> Parent Income: "<< p->parent_income << "\t --> Account Number: " << p->account_no<< "\t --> Aadhar Number: " << p->aadhar_no << endl; 
    p = p->nxt; 
  } 
} 
void PaperlessScholarship::displayr() { 
  if (head == NULL) { 
    cout << "Sorry. The list is empty."; 
    return; 
  } 
  p = tail; 
  while (p != NULL) { 
    cout << "NAME: " << p->name << "\t --> GENDER: " << p->gender << "\t --> HSC Mark: " << p->hsc_mark << "\t --> Parent Income: "<< p->parent_income << "\t --> Account Number: " << p->account_no<< "\t --> Aadhar Number: " << p->aadhar_no << endl; 
    p = p->prev; 
  } 
} 
void PaperlessScholarship::deletedata(string d) { 
  if (head == NULL) { 
    cout << "\nSorry the list is empty"; 
    return; 
  } 
  p = head; 
  while (p->name != d) { 
    temp = p; 
    p = p->nxt; 
  } 
  temp->nxt = p->nxt; 
  if (p->nxt != NULL) { 
    p->nxt->prev = temp; 
  } 
  delete p;  
} 
void PaperlessScholarship::modify(string a, string b) { 
  if (head == NULL) {  
    cout << "\nSorry the list is empty"; 
    return; 
  } 
  p = head;  
  while (p != NULL) { 
    if (p->name == a) { 
      p->name = b;              
      return;  
    }          
    p = p->nxt; 
  } 
} 
void PaperlessScholarship::search(string c) { 
  if (head == NULL) { 
    cout << "\nSorry the list is empty"; 
    return; 
  } 
  p = head;  
  while (p != NULL) { 
    if (p->name == c) { 
      cout << "NAME: " << p->name << "\t --> GENDER: " << p->gender  << "\t --> HSC Mark: " << p->hsc_mark << "\t --> Parent Income: " << p->parent_income << "\t --> Account Number: " << p->account_no << "\t --> Aadhar Number: " << p->aadhar_no << endl; 
      return; 
    } 
    p = p->nxt;  
  } 
  cout << "Record not found!" << endl; 
} 
void PaperlessScholarship::insertatbeg(string n, string g, int h, float pc, long int adh, long int acc) { 
  temp = new struct data;  
  temp->name = n; 
  temp->gender = g; 
  temp->hsc_mark = h; 
  temp->parent_income = pc; 
  temp->aadhar_no = adh; 
  temp->account_no = acc; 
  temp->nxt = NULL; 
  if (head == NULL) { 
    head = temp; 
    return; 
  } 
  temp->nxt = head; 
  head->prev = temp; 
  head = temp;  
} 
void PaperlessScholarship::deletebeg() { 
  if (head == NULL) { 
    cout << "\nSorry the list is empty";  
    return; 
  }      
  p = head;  
  head = p->nxt;  
  if (head != NULL) { 
    head->prev = NULL; 
  } 
  delete p;  
} 
