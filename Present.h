class Present {
  private:
    string name;
    int price;//TL
    int meaning=10;//Out of 10.
    int time_consume;
  public:
    Present(string name="trash",int meaning=10,int price=0,int time_consume=0):
    name(name),price(price),meaning(meaning),time_consume(time_consume){
      if(meaning>10){
        cout << "Nothing can be valued this much unless it is IL";
        cout << "\xe2\x99\xa5"<< " S" << endl;
        cout << "Well, 'sort' can be. No no nevermind. "<< endl;
        cout << "the meaning of " << this->name << " will be initialized to 10"<< endl;
        this->meaning=10;
      }
    }

  string getName(){return name;}
  int getPrice(){return price;}
  int getMeaning(){return meaning;}
}sort("sort",100,40),map("map",0,8),love_letter("letter",0,8);
//since sort is a unique item its meaning is out of range.
//but don't worry it will be handled :).
