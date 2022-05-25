#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>

using namespace std;



void nrandom(vector<int>&n){
  int num=0;
  int b=1;
  
  num=1+rand()%(101-1);
  n.push_back(num);

  while(n.size()!=0){
    
    for(int i=0;i<n.size();i++){
      if(n[i]==num){
        b*=0;
      }
    }
    if(b==1){
      n.push_back(num);
    }
    return;
    }
}

class strategy{
  public:
    vector<int>nram;
    virtual ~strategy()=0;
    virtual void execute()=0;
};

class cinco_pares:public strategy{
  int cp=0;

  void execute()override{
   
    for(int i=0;i<nram.size();i++){
      if(nram[i]%2==0){
        cp++;
      }
    }
    if(cp==5){
      cout<<"Yo gane(cinco pares)"<<endl;
    }
    return;
  }
};

class cinco_impares:public strategy{
  int ci=0;

  void execute()override{
    for(int i=0;i<nram.size();i++){
      if(nram[i]%2!=0){
        ci++;
      }
    }
    if(ci==5){
      cout<<"Yo gane(cinco impares)"<<endl;
    }
    return;
  }
};

class primo:public strategy{
  int p=0;
//falta
  void execute()override{
    for(int i=0;i<nram.size();i++){
      if(nram[i]%2==0){
        cout<<"Yo gane (primo)"<<endl;
      }
    }
    
    return;
  }
};

class m10:public strategy{
  int m1=0;

   void execute()override{
    for(int i=0;i<nram.size();i++){
      if(nram[i]%10==0){
        m1++;
      }
    }
    if(m1==3){
      cout<<"Yo gane (m10)"<<endl;
    }
    return;
  }
};

class m25:public strategy{
  int m2=0;

   void execute()override{
    for(int i=0;i<nram.size();i++){
      if(nram[i]%25==0){
        m2++;
      }
    }
    if(m2==2){
      cout<<"Yo gane (m25)"<<endl;
    }
    return;
  }
};

class jugador{
  private:
    string name;
    strategy* st;
  public:
    jugador(string n,strategy* s){
      st = s;
      name = n;
    }
  
};

class juego{
  private:
    vector<jugador*> j;
    static juego* azar;
    juego()=default;
  public:
    static juego* getinstance(){
      if(azar == nullptr) {
        azar= new juego;
      }
      return azar;
    }
    void add_jugador(string name,strategy* st){
      jugador* temp= new jugador(name,st);
      j.push_back(temp);
      cout<<"jugador "<<name<<" añadido"<<endl;
    }
    bool start(){
      if(j.size()==5){
        cout<<"Que comienze el juego"<<endl;
        return true;
      }
      return false;
    }
    bool finish(){
      return false;
    }
    
    
};

juego * juego::azar=nullptr;

int main() {
  srand(time(NULL));
  auto azar= juego::getinstance();
  cinco_pares* a;
  cinco_impares* b;
  primo* c;
  m10* d;
  m25* e;

  
  azar->add_jugador("paulo",a);
  azar->add_jugador("eric",b);
  azar->add_jugador("alexander",c);
  azar->add_jugador("rodrigo",d);
  azar->add_jugador("francisco",e);
cout<<"------------------"<<endl;
  azar->start();
  
  return 0;
}
