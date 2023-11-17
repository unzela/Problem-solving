#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  // creation
  unordered_map<string, int> m;

  // insertion
  pair<string, int> p = make_pair("Scorpio", 10);
  m.insert(p);

  pair<string, int> p2("Fortuner", 20);
  m.insert(p2);

  m["Nexon"] = 30;

  // access
  cout << m["Fortuner"] << endl;
  cout << m.at("Scorpio") << endl;

  // search
  cout << m.count("Scorpio") << endl; // If it exisits ans is 1 else 0
  cout << m.count("Innova") << endl;

  if (m.find("Nexon") != m.end()) { // Find return iterator
    cout << "Nexon Found" << endl;
    ;
  } else
    cout << "Not found";

  cout << m.size();

  cout << m["Harrier"] << endl; // If this key is not found while accessing it
                                // cerates a new key with value as 0
  cout << m.size() << endl;

  for (auto i : m) {
    cout << i.first << " = " << i.second << endl;
  }
}
