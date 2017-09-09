#include <iostream>
using namespace std;
#include "Lovers.h"
#include "Enemy.h"
#include "Present.h"
void InfoPrinter(int value){
  for(int i=0;i<value/4;i++){
    cout << "\xe2\x99\xa5" << " ";//heart unicode.
  }
  for(int i=value/4;i<25;i++){
    cout <<"."<< " ";
  }
  cout << endl;
}
void InfoPrinterMoney(int value){
  for(int i=0;i<value/8;i++){
    cout << "$" << " ";//heart unicode.
  }
  for(int i=value/8;i<25;i++){
    cout <<"."<< " ";
  }
  cout << endl;
}
void InfoPrinterTime(int value){
  for(int i=0;i<value/4;i++){
    cout << "\xe2\x99\xa5" << " ";//heart unicode.
  }
  for(int i=value/4;i<15;i++){
    cout <<"."<< " ";
  }
  cout << endl;
}

int main(){
  Lovers onur("Onur","Ilosunu mutlu etmek <3");
  Place USA("USA","not found");
  onur.setHappiness(50);
  USA.attackAction(onur);
  onur.showInfo();

  return 0;
}

void Lovers::showInfo(){
  cout << endl << "               INFORMATION" << endl << endl;
  cout << "Name: " << this->name << endl;
  cout << "Super power is " << this->super_power_name << endl;
  cout <<"Attack Power: " << this->attack_power << endl;
  InfoPrinter(this->attack_power);
  cout << endl<< "Defence Power: " << this->defence_power << endl;
  InfoPrinter(this->defence_power);
  cout << endl<<"Happiness: " << this->happiness << endl;
  InfoPrinter(this->happiness);
  cout << endl<<"Time : " << this->timeleft << endl;
  InfoPrinterTime(this->timeleft);
  cout << endl<<"Money: " << this->money << endl;
  InfoPrinterMoney(this->money);
}
bool Lovers::attackAction(Enemy &opponent){//Returns the damage dealt by Lover.
  int health=opponent.getHealth();
  int damage_dealt=(this->attack_power)-(2*opponent.getDefencePow());
  if(damage_dealt<=0){
    cout <<this->name <<" cannot be hurt.!"<< endl;
    return true;
  }
  if(damage_dealt>health){
    opponent.setHealth(0);
    cout << opponent.getName() <<" is dead." << endl;
    return false;
  }
  opponent.setHealth(health-damage_dealt);
  return true;
}
bool Enemy::attackAction(Lovers &opponent){
  int happiness=opponent.getHappiness();
  int damage_dealt=(this->attack_power)-(2*opponent.getDefencePow());
  if(damage_dealt<=0){
    cout <<this->name <<" cannot be hurt!"<< endl;
    return true;
  }
  if(damage_dealt>health){
    opponent.setHappiness(0);
    cout << opponent.getName() <<" is dead." << endl;
    return false;
  }
  opponent.setHappiness(happiness-damage_dealt);
  return true;
}
void Lovers::getPresent(Present present,Lovers owner){
  //owner is the one who buys the present.
  int meaning_=(present.getMeaning())*3;// 4 or 5 could be better.
  int price_=present.getPrice();
  if(price_>owner.getMoney()){
    cout << this->name << "can't afford it." << endl;
    return;
  }
  if((meaning_+this->happiness)>=100){
    this->happiness=100;
    owner.setMoney((owner.getMoney()-price_));// Money is spent.
  }
  else{
    this->happiness+=meaning_;
    owner.setMoney((owner.getMoney()-price_));
  }
}
void Enemy::superPower(){
  if(this->power_use && health!=100){
    this->health+=(100-this->health)/5;
    this->power_use--;
    cout << this->name << " healed itself!" << endl;
    cout << "Current Health: " << this->health<< endl;
    InfoPrinter(this->health);
  }
  else{
    cout << this->name << " has already used its super power!"<<endl;
  }
}
void Place::superPhone(Lovers Lover){
  cout << Lover.getName() << " becomes upset as he/she can't talk to phone" << endl;
  int new_happiness=Lover.getHappiness()-(10-this->phone_access)*6;
  if(new_happiness<=0){
    Lover.setHappiness(0);
    cout << "Current happiness: " << Lover.getHappiness() << endl;
    InfoPrinter(Lover.getHappiness());
    cout << Lover.getName()<< " says:'I suppose I won't be able to make it walk.':("<< endl;
    cout << "The game." << Lover.getName()<<" couldn't make the game walk." << endl;
    exit(0);//the game is over due to lack of happiness:dd.
  }
  else{
  Lover.setHappiness(new_happiness);
  cout << "Current happiness: " << Lover.getHappiness() << endl;
  InfoPrinter(Lover.getHappiness());
  }
}
