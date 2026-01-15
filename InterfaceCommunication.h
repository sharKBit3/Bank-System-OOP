#pragma once

#include <iostream>

class InterfaceCommunication {


public:

	virtual void SendEmail(string Text, string Body) = 0;
	virtual void SendFax(string Text, string Body) = 0;



	


};