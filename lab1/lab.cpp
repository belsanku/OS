#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

struct student {
	string name;
	double mark;
};

struct list {
	student data;
	struct list *next;
	struct list *prev;
};

struct list * init (string name, double mark) {
	struct list *lst;
	lst = (struct list*)malloc(sizeof(struct list));
	lst->data.name = name;
	lst->data.mark = mark;
	lst->next = NULL;
	lst->prev = NULL;
	return(lst);	
}

void add(list *lst, string temp_name, double mark, int n)
{
 	int j = 1;
    int i; list *pnew, *p = lst;
    pnew = new list; pnew->data.mark = mark;
    pnew->data.name = temp_name;
    if (n <= 1 || lst == NULL)
    {
        pnew->next = lst; lst = pnew;
    }
    else
    {
        for (i = 1; i<n - 1; i++)
        if (p->next != NULL)
        {
            p = p->next;
            j++;
        }
        if (n <= j + 1)
        {
            pnew->next = p->next; p->next = pnew;
        }
    }
}

struct list * addelem(list *lst, string temp_name, double number) {
	struct list *temp, *p;
  	temp = (struct list*)malloc(sizeof(list));
  	p = lst->next; // сохранение указателя на следующий узел
  	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->data.name = temp_name;
  	temp->data.mark = number;
  	temp->next = p; // созданный узел указывает на следующий узел
  	temp->prev = lst; // созданный узел указывает на предыдущий узел
  	if (p != NULL)
    	p->prev = temp;
  	return(temp);
}

struct list * deletelem(list *lst) {
  	struct list *prev, *next;
  	prev = lst->prev; // узел, предшествующий lst
  	next = lst->next; // узел, следующий за lst
  	if (prev != NULL)
    	prev->next = lst->next; // переставляем указатель
  	if (next != NULL)
    	next->prev = lst->prev; // переставляем указатель
  	free(lst); // освобождаем память удаляемого элемента
  	return(prev);
}

struct list *  deleteEl(list *lst, int cnt)
{
	struct list *p;
	p = lst;
	int i = 0;
	while (i < cnt) {
		if (i == cnt - 1) 
			return p;
		p=p->next;
		i++;
	}
	return NULL;
}

void listprint(list *lst) {
	cout << "Source list: " << endl;
	ofstream file("binarydata.bin", ios::binary);
  	struct list *p;
  	p = lst;
  	int num = 1;
  	do {
		file.write((char*)&p->data.name, p->data.name.size());
		file.write((char*)&p->data.mark, sizeof(double));
    	cout << num << ". " << p->data.name << " " << p->data.mark << endl; // вывод значения элемента p
    	num++;
    	p = p->next; // переход к следующему узлу
  	} while (p != NULL); // условие окончания обхода
	file.close();
}

struct list * listNav(list *lst, int cnt) {
	struct list *p;
	p = lst;
	int i = 0;
	while (i < cnt) {
		if (i == cnt - 1) {
			cout << p->data.name << "\t" << p->data.mark << endl;
			return p;
		}

		p = p->next;
		i++;
	}	
	return NULL;
}

int main() {
	string a = "Saske";
	struct list* journal = init(a, 4.36);
	addelem(journal, "Sasha", 5.5);
	for (int i = 0; i < 3; i++) {
		string tempName;
		double tempMark;
		cin >> tempName >> tempMark;
		addelem(journal, tempName, tempMark);
	}
	listprint(journal);
	cout << endl;
	int n;
	cout << "Enter the number of cucumber: "; 
	cin>>n;
	listNav(journal, n);
	cout<<"Enter the number of kogo hotite ubit': ";
	cin>>n;
	struct list* temp_t = deleteEl(journal,n);
	deletelem(temp_t);
	listprint(journal);
	cout<<"Enter the newbie: "<<endl;
	string name_t = "";
	double mark_t = 0.0;
	cin>>name_t>>mark_t;
	cin >> n;
	add(journal, name_t, mark_t, n);
	listprint(journal);
	//struct list*temp_p = listNav(journal, n);
	//addelem(temp_p, name_t, mark_t);
	return 0;
}