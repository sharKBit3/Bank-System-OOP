#include "clsLoginScreen.h"





int main() {

        while (true)
        {
            if (!clsLoginScreen::Login())
            {
                break;
            }
        }



	system("pause>0");
	return 0;
}