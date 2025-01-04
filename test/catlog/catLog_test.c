#include "../catLog.h"

int main() {
    catLog("This is catLog test.");
    
    int i = 0;
    
    while (i < 10) {
        catLog("Current value of i: ");
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "%d", i);
        catLog(buffer);
        i++;
    }
    
    return 0;
}
