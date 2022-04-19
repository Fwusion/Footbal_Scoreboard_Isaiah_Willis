#include <iostream>
#include <string>
#include <unistd.h>

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
        cName = "Coach'sName";
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
  public:
    Scoreboard()
    {
      quarter = 0, downs = 0, toGo = 0;
    }
    void setQuarter(int q) { quarter = q; }
    void setDowns(int d) { downs = d; }
    void setToGo(int tg) { toGo = tg; }
    void setHome(Team h) { home = h; }
    void setVisitor(Team v) { visitor = v; }
    int getQuarter() const { return quarter; }
    int getDowns() const { return downs; }
    int getToGo() const { return toGo; }
    Team getHome() const { return home; }
    Team getVisitor() const {return visitor; }

    void showScoreboard()
    {
      cout << "yo" << endl;
      cout << home.getName() << "\t\t" << visitor.getName() << endl;
      cout << "\t" << home.getScore() << "\t\t\t\t" << visitor.getScore() << endl;
    }
};

void scoreboardLengend()
{
  Scoreboard s;
  Team one;
  Team two;
  string userInput = "", newName = "";
  int newScore = 0;

  one.setHomeStat(true);
  s.setHome(one);
  s.setVisitor(two);
  

  do
  {
    system("clear");
    s.showScoreboard();
    cout << "*************************" << endl;
    cout << "Scoreboard Legend!" << endl;
    cout << "A = Change Home Team's Name." << endl;
    cout << "B = Change Visitor Team's Name." << endl;
    cout << "C = Change Home's Score" << endl;
    cout << "D = Change Visitor's Score" << endl;
    cout << "E = Update Possesion" << endl;
    cout << "F = Update Downs" << endl;
    cout << "G = Update Yards To Go" << endl;
    cout << "H = Update Quarter" << endl;
    cout << "X = Exit Menu" << endl;
    cin >> userInput;

    if(userInput == "A" || userInput == "a")
    {
      cout << "Please Enter The Home Team's Name: ";
      cin >> newName;
      one.setName(newName);
    }
    else if(userInput == "B" || userInput == "b")
    {
      cout << "Please Enter The Visitor Team's Name" << endl;
      cin >> newName;
      two.setName(newName);
    }
    else if(userInput == "c" || userInput == "c")
    {
      cout << "Please Enter The New Score For The Home Team" << endl;
      cin >> newScore;
      one.setScore(newScore);
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