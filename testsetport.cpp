#include <cstdlib>
using namespace std;

int main() {
    system("./setport");
    system("./setport -?");
    system("./setport -h");
    system("./setport --help");
    system("./setport -!");
    system("./setport --about");
    system("./setport -v");
    system("./setport --version");
    system("./setport -p -e");
    system("./setport -p -e PORT");
    system("./setport -p 4040");
    system("./setport --port 4040");
    
    system("./setport help");
    system("./setport -help");
    system("./setport --h");
    system("./setport -h --help");
    system("./setport -hs");
    system("./setport ?");
    system("./setport !");
    system("./setport -p -e 8080");
    system("./setport -e PORT");
    system("./setport -p --port 9");
    system("./setport -p 77 33");
    system("./setport -p -21");
    system("./setport -p 0");
    system("./setport --port");
    system("./setport -p 90642");
    system("./setport -x 45321");
    system("./setport -P 714");
    
    // I didn't include language tests because regex is commented out
    
    return 0;
}