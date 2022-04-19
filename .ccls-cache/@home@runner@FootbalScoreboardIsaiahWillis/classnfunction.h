#include <iostream>
#include <string>
#include <unistd.h>
#include <iomanip>

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
    bool possession;
  public:
    Scoreboard()
    {
      quarter = 0, downs = 0, toGo = 0;
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
      cout << "\t\tIsaiah's Football Scoreboard" << endl;
      for(int i = 0; i < 45; i++) { cout << "*"; }
      cout << "\n" << setw(10) << home.getName() << "\t\t" << setw(10) << visitor.getName() << endl;
      cout << setw(5) << home.getScore() << "\t\t\t" << setw(5) << visitor.getScore() << endl;
      
    }
};

void scoreboardLengend()
{
  Scoreboard s;
  Team one;
  Team two;
  string userInput = "", newName = "";
  int newScore = 0, newPos = 0, newDown = 0, newTG = 0, newQ = 0;

  one.setHomeStat(true);
  s.setHome(one);
  s.setVisitor(two);
  

  do
  {
    system("clear");
    s.showScoreboard();
    for(int i = 0; i < 45; i++) { cout << "*"; }
    cout << "\nScoreboard Legend!" << endl;
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
      cout << "Please Enter The Visitor Team's Name: ";
      cin >> newName;
      two.setName(newName);
    }
    else if(userInput == "C" || userInput == "c")
    {
      cout << "Please Enter The New Score For The Home Team: ";
      cin >> newScore;
      one.setScore(newScore);
    }
    else if(userInput == "D" || userInput == "d")
    {
      cout << "Please Enter The New Score For The Visitor Team: ";
      cin >> newScore;
      two.setScore(newScore);
    }
    else if(userInput == "E" || userInput == "e")
    {
      cout << "Who Has The Ball?" << endl;
      cin >> newPos;
      if(newPos == 1)
      {
        s.setPos(true);
        cout << "Home has the ball." << endl;
        
      }
      else
      {
        s.setPos(false);
        cout << "Visitors have the ball." << endl;
      }
    }
    else if(userInput == "F" || userInput == "f")
    {
      cout << "Please Enter The Current Down" << endl;
      cin >> newDown;
      s.setDowns(newDown);
    }
    else if(userInput == "G" || userInput == "g")
    {
      cout << "Please Enter How Many Yards To Go For A First Down. ";
      cin >> newTG;
      s.setToGo(newTG);
    }
    else if(userInput == "H" || userInput == "h")
    {
      cout << "Please Enter The Current Quarter. ";
      cin >> newQ;
      s.setQuarter(newQ);
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