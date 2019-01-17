#include "Admin.h"
#include "ChangeDirectory.h"
#include "MakeOrganization.h"
#include "Create.h"
#include "Delete.h"
#include "Print.h"
#include "Listserv.h"
#include "BuildList.h"
#include "Subscribe.h"
#include "unsubscribe.h"
#include "notify.h"
#include "display.h"
#include "Quit.h"
#include "showordered.h"

#include "ShowMessage.h"
#include <iostream>
#include <string>
#include <sstream>


Admin::Admin() : orgs(new organization("Fresno State"))
{
	status = new bool(true);
	current = orgs;  // set to root
	parent = orgs;  // set to root
	Mapping();  //  setup map which contains commands
	constructOrg();  // construct default organization
	constructListserv(); //  construct default LISTSERV
}


Admin::~Admin()
{
	if (orgs)
	{
		orgs->del();
	}
}

void Admin::Mapping()
{
	//initialize hash table that contains all the commands
	commands.emplace("cd",new ChangeDirectory(&parent,orgs, &current));  // pointer to pointer because pointer is chnaging
	commands.emplace("mkorg", new MakeOrganization(&current)); 
	commands.emplace("create", new Create(&current)); 
	commands.emplace("del", new Delete(&current)); 
	commands.emplace("ls", new Print(&current));
	commands.emplace("buildlist", new BuildList(&lists, &archive));
	commands.emplace("subscribe", new Subscribe(&lists, orgs));
	commands.emplace("unsubscribe", new unsubscribe(&lists,orgs));
	commands.emplace("notify", new notify(&lists, &archive));
	commands.emplace("display", new display(orgs) );
	commands.emplace("QUIT", new Quit(status));
	commands.emplace("showordered", new showordered(&archive)); // bonus part1
	commands.emplace("swmsg", new ShowMessage(&archive)); // bounus part 2
}
void Admin::constructOrg() // create default organization specified on Blackboard
{
	organization* CSM = new organization("CSM");
	organization* Lyles = new organization("Lyles");
	organization* CSCI = new organization("CSCI");
	organization* Math = new organization("Math");
	organization* ECE = new organization("ECE");

	Student *Alex = new Student("Alex");
	Student *Elizabeth = new Student("Elizabeth");
	Student *Kishan = new Student("Kishan");
	Student *Kushad = new Student("Khushad");
	Student *Sean = new Student("Sean");
	Student *Conner = new Student("Conner");

	CSCI->addComponent(Alex);
	CSCI->addComponent(Elizabeth);
	CSCI->addComponent(Kishan);
	CSCI->addComponent(Kushad);
	Math->addComponent(Sean);
	ECE->addComponent(Conner);

	CSM->addComponent(Math);
	CSM->addComponent(CSCI);
	Lyles->addComponent(ECE);
	orgs->addComponent(CSM);
	orgs->addComponent(Lyles);
}

void Admin::constructListserv()
{
	lists.emplace("CSMls", new Listserv("CSMls"));
	archive.emplace("CSMls", new std::list<ArchiveObject*>);
	ArchiveObject* temp1 = new ArchiveObject("Happy 4 20, Time to Light up!",20,4);
	ArchiveObject* temp2 = new ArchiveObject("Happy PI Day!",14,3);
	ArchiveObject* temp3 = new ArchiveObject("Happy Cinco de Mayo!", 5,5);
	ArchiveObject* temp4 = new ArchiveObject("Happy Valentines Days!",14,2);
	ArchiveObject* temp5 = new ArchiveObject("Merry Christmas Students!",25,12);

	auto archivelist = archive["CSMls"];
	archivelist->push_back(temp1);
	archivelist->push_back(temp2);
	archivelist->push_back(temp3);
	archivelist->push_back(temp4);
	archivelist->push_back(temp5);
}


void Admin::processCommand()  //  process command
{
	while (*status)
	{
		std::string commandwparam = "";
		std::cout << current->getName() << "> ";  // console output (current directory)
		getline(std::cin, commandwparam); //take command with parameters from console

		std::stringstream ss(commandwparam);
		std::string command;
		std::string params;

		getline(ss, command, ' '); //  extract command from string
		getline(ss, params); // extract params from string 

		if (commands.count(command)) // will return 1 if key exists
		{
			ICommand *c = commands[command];
			c->execute(params);
		}
		else
		{
			std::cerr << "Command " << command << " Unknown" << std::endl; // error message
		}
	}
}