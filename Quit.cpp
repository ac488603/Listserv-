#include "Quit.h"

Quit::Quit(bool * s):status(s)
{
}
Quit::~Quit()
{
}
void Quit::execute(std::string x) { *status = false;}