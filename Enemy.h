class Enemy{
  protected:
   int health=100;
   int attack_power=100;
   int defence_power=10;
   string name;
   string super_power_name;
   int power_use=1;// super power can be used for one time

  public:
    bool attackAction(Lovers &opponent);//Enemy attacks Lover :(
    void setHealth(int health){this->health=health;}
    void setAttackPow(int attack_power){this->attack_power=attack_power;}
    void setDefencePow(int defence_power){this->defence_power=defence_power;}
    string getName(){return name;}
    int getHealth(){return health;}
    int getAttackPow(){return attack_power;}
    int getDefencePow(){return defence_power;}
    void superPower();// eksik can degerinin %20si kadar iyilesir.
};

class Place: public Enemy{
  private:
    int distance=0;// distance to ankara in km.
    int phone_access=5;//rate of time you can talk to phone out of 10.
  public:
    Place(string name,string pow_name="not found",int atak=50,int def=10){
    this->name=name;
    this->super_power_name=pow_name;
    this->attack_power=atak;
    this->defence_power=def;
    }
    void setDistance(int distance){this->distance=distance;}
    void setPhoneAccess(int access){this->phone_access=access;}
    void superPhone(Lovers Lover);//decreases happiness of the lover.
};

class Objects:public Enemy{

}ilosun_tirnaklari,fiskiyeler;
