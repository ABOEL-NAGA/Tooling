#include<iostream>
#include<algorithm>
#include<string>
#include<vector>



struct person
{
  std::string name;
  std::string address;

};

int main()
{
    std::vector<person> v;
    person mohamed {"mohamed","cairo" };
    person ahmed  {"ahmed","giza"}; 
    person nagib  {"nagib","menofia"};
    person samer  {"samer","nasr"};

    v.push_back(mohamed);
    v.push_back(ahmed);
    v.push_back(nagib);
    v.push_back(samer);

   auto compare_name=[](person const& first,person const& second){return first.name>second.name;};
   auto compare_address=[](person const& first,person const& second){return first.address>second.address;};
    std::sort(v.begin(),v.end(),compare_name);
    std::cout<<"sorting by name"<<std::endl;
    for(person c: v)
    {
        std::cout<<c.name<<">>";
        std::cout<<c.address<<std::endl;
    }
        std::cout<<"sorting by address"<<std::endl;

     std::sort(v.begin(),v.end(),compare_address);
    for(auto c: v)
    {
        std::cout<<c.name<<">>";
        std::cout<<c.address<<std::endl;
    }




}