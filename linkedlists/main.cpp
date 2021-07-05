//
//  main.cpp
//  linkedlists
//
//  Created by 조다빈 on 2021/07/05.
//

#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string name;
    double score;
    node *link;
    void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
    name = s;
    score = n;
}


class my_list {
    node *head, *tail;
public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    double score_sum();
    double get_score(string t_name);
    int remove_a_node(string t_name);
};

my_list::my_list() {
    head = NULL;
    tail = NULL;
}

void my_list::add_to_head(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
    if(tail == NULL)
        tail = p;
}

void my_list::add_to_tail(node t)
{
    node *p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if(tail != NULL)
        tail->link = p;
    else
        head = p;
    tail = p;
}

node my_list::delete_from_head()
{
    node temp;
    node *t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    
    if(head == NULL)
        tail = NULL;
    return temp;
}

int my_list::num_nodes()
{
    node *t;
    int count = 0;
    
    for(t = head; t != NULL; t = t->link)
        count++;
    return count;
}

bool my_list::list_empty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

double my_list::score_sum()
{
    node *t;
    double sum = 0;
    
    for(t = head; t != NULL; t = t->link)
        sum += t->score;
    
    return sum;
}

double my_list::get_score(string t_name)
{
    node *t;
    
    for(t = head; t != NULL; t = t->link){
        if(t->name == t_name){
            return t->score;
            break;
        }
    }
    return 0;
}

int my_list::remove_a_node(string t_name)
{
    node *t, *k;
    int count = 0, i = 0;
   
    for(t = head; t != NULL; t = t->link){
        if(t->name == t_name){
            if(t == head){
                for(k = head; head != NULL; k = k->link){
                    if(i == count){
                        node *h;
                        h = k;
                        head = head->link;
                        delete h;
                        
                        if(head == NULL)
                            tail = NULL;
                        return 1;
                        break;
                }
                    i++;
                }break;
            }else{
                for(k = head; head != NULL; k = k->link){
                    if(i == count-1){
                        node *h;
                        h = k;
                        k->link = t->link;
                        delete t;
                        
                        return 1;
                        break;
                    }
                    i++;
                } break;
        }
        }
        count++;
    }
    return 0;
}




int main()
{
    my_list a;
    node tmp;
    
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("LEE", 78.2);
    a.add_to_head(tmp);
    cout << a.num_nodes() << ":" << a.score_sum() << "\n";
    tmp.set_data("Park", 91.3);
    a.add_to_tail(tmp);
    cout << a.num_nodes() << ":" << a.score_sum() << "\n";
    tmp = a.delete_from_head();
    cout << tmp.name << " is deleted.\n";
    tmp.set_data("Choi", 85.1);
    a.add_to_tail(tmp);
    tmp.set_data("Ryu", 94.3);
    a.add_to_head(tmp);
    cout << a.num_nodes() << ":" << a.score_sum() << "\n";
    cout << "Park's score : " << a.get_score("Park") << "\n";
    if ( a.remove_a_node("Kim") == 1)
        cout << "Kim is deleted from the list. \n";
    cout << a.num_nodes()<< " : " << a.score_sum() << "\n";
    
    return  0;
    
}


