#include <iostream>
#include <string>
#include <unistd.h>
#include <iomanip>
#include "Input_Validation_Extended.h"

using namespace std;

class Team
{
  private:
    int score, timeouts;
    bool homeStat;
    string name;
    string cName;
  public:
      Team()
      {
        score = 0, timeouts = 0;
        homeStat = false;
        name = "TeamName";
        cName = "Coach's Name";
      }
      void setScore(int s) { score = s; }
      void setTimeouts(int t) { timeouts = t; }
      void setHomeStat(bool hs) { homeStat = hs; }
      void setName(string n) { name = n; }
      void setCName(string cn) { cName = cn; }
      int getScore() const { return score; }
      int getTimeouts() const { return timeouts; }
      bool getHomeStat() const { return homeStat; }
      string getName() const { return name; }
      string getCName() const { return cName; }
};

class Scoreboard
{
  private:
    int quarter, downs, toGo;
    Team home;
    Team visitor;
    bool possession;
  public:
    Scoreboard()
    {
      quarter = 1, downs = 0, toGo = 0;
      possession = true;
    }
    void setQuarter(int q) { quarter = q; }
    void setDowns(int d) { downs = d; }
    void setToGo(int tg) { toGo = tg; }
    void setHome(Team h) { home = h; }
    void setVisitor(Team v) { visitor = v; }
    void setPos(bool p) { possession = p; }
    int getQuarter() const { return quarter; }
    int getDowns() const { return downs; }
    int getToGo() const { return toGo; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    bool getPos() const { return possession; }

    void showScoreboard()
    {
      
      cout << "\t  Isaiah's Football Scoreboard" << endl;
      for(int i = 0; i < 38; i++) { cout << "*"; }
      cout << "\nHome\t\t\t\t\t\tVisitor" << endl;
      cout << setw(7) << home.getName() << "\t\t\t\t" << setw(12) << visitor.getName() << endl;
      cout << setw(7) << home.getCName() << "\t\t\t\t" << setw(7) << visitor.getCName() << endl;
      cout << setw(5) << home.getScore() << "\t\t\t\t\t\t" << setw(7) << visitor.getScore() << endl;
      cout << "\t\tPoss: ";
      if(possession == true) { cout << "H"; }
      else { cout << "V"; }
      cout << "\t\tQTR: " << getQuarter() << endl;
      cout << "\tDown: #" << getDowns() << "\t\tTo Go: " << getToGo() << endl;
      
    }
};

void scoreboardLengend()
{
  Scoreboard s;
  Team one;
  Team two;
  string userInput = "", newName = "", newCName = "";
  int newScore = 0, newPos = 0, newDown = 0, newTG = 0, newQ = 0;

  one.setHomeStat(true);
  s.setHome(one);
  s.setVisitor(two);
  

  do
  {
    system("clear");
    s.showScoreboard();
    for(int i = 0; i < 38; i++) { cout << "*"; }
    cout << "\nScoreboard Legend!" << endl;
    cout << "A = Change Home Team's Name." << endl;
    cout << "B = Change Visiting Team's Name." << endl;
    cout << "C = Change Home's Score" << endl;
    cout << "D = Change Visitor's Score" << endl;
    cout << "E = Update Possesion" << endl;
    cout << "F = Update Downs" << endl;
    cout << "G = Update Yards To Go" << endl;
    cout << "H = Update Quarter" << endl;
    cout << "I = Edit Home Team's Coach" << endl;
    cout << "J = Edit Visiting Team's Coach" << endl;
    cout << "X = Exit Menu" << endl;
    cout << endl;
    userInput = validateString(userInput);

    if(userInput == "A" || userInput == "a")
    {
      cout << "Please Enter The Home Team's Name: ";
      newName = validateString(newName);
      one.setName(newName);
      cout << "Updating Name to " << one.getName() << endl;
      sleep(2);
    }
    else if(userInput == "B" || userInput == "b")
    {
      cout << "Please Enter The Visiting Team's Name: ";
      newName = validateString(newName);
      two.setName(newName);
      cout << "Updating Name to " << two.getName() << endl;
      sleep(2);
    }
    else if(userInput == "C" || userInput == "c")
    {
      cout << "\nPlease Enter The New Score For The Home Team: ";
      newScore = validateInt(newScore);
      one.setScore(newScore);
      cout << "Updating Score to " << one.getScore() << endl;
      sleep(2);
    }
    else if(userInput == "D" || userInput == "d")
    {
      cout << "\nPlease Enter The New Score For The Visiting Team: ";
      newScore = validateInt(newScore);
      two.setScore(newScore);
      cout << "Updating Score to " << two.getScore() << endl;
      sleep(2);
    }
    else if(userInput == "E" || userInput == "e")
    {
      cout << "Who Has The Ball? (1 = Home & 2 = Visitor)" << endl;
      newPos = validateInt(newPos);
      if(newPos == 1)
      {
        s.setPos(true);
        cout << "Home now has the ball." << endl;
        sleep(2);
      }
      else
      {
        s.setPos(false);
        cout << "Visitors now have the ball." << endl;
        sleep(2);
      }
    }
    else if(userInput == "F" || userInput == "f")
    {
      cout << "Please Enter The Current Down" << endl;
      newDown = validateInt(newDown);
      s.setDowns(newDown);
      cout << "Updating Down to " << s. getDowns() << endl;
      sleep(2);
    }
    else if(userInput == "G" || userInput == "g")
    {
      cout << "Please Enter How Many Yards To Go For A First Down. ";
      newTG = validateInt(newTG);
      s.setToGo(newTG);
      cout << "Updating Yards to " << s.getToGo() << endl;
      sleep(2);
    }
    else if(userInput == "H" || userInput == "h")
    {
      cout << "Please Enter The Current Quarter. ";
      newQ = validateInt(newQ);
      s.setQuarter(newQ);
      cout << "Updating Quarter to " << s.getQuarter() << endl;
      sleep(2);
    }
    else if(userInput == "I" || userInput == "i")
    {
      cout << "Please Enter The Coach's Name: ";
      newCName = validateString(newCName);
      one.setCName(newCName);
      cout << "Updating Name to " << one.getCName() << endl;
      sleep(2);
    }
    else if(userInput == "J" || userInput == "j")
    {
      cout << "Please Enter The Coach's Name: ";
      newCName = validateString(newCName);
      two.setCName(newCName);
      cout << "Updating Name to " << two.getCName() << endl;
      sleep(2);
    }
    else if(userInput == "X" || userInput == "x")
    {
      system("clear");
      cout << "End Game!" << endl;
    }
    else
    {
      cout << "\nInvalid Input" << endl;
      sleep(3);
    }


   s.setHome(one);
  s.setVisitor(two);
  }while(userInput != "X" && userInput != "x");
}